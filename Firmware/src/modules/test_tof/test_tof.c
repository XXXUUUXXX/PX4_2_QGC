/**
 * @file px4_simple_app.c
 * Minimal application example for PX4 autopilot
 *
 * @author Example User <mail@example.com>
 */


#include <px4_platform_common/px4_config.h>
#include <px4_platform_common/tasks.h>
#include <px4_platform_common/posix.h>
#include <unistd.h>
#include <stdio.h>
#include <poll.h>
#include <string.h>

/* 添加要是用的topics , test_tof*/
#include <uORB/uORB.h>
#include <../build/px4_fmu-v5_default/uORB/topics/test_tof.h>

__EXPORT int test_tof_main(int argc, char *argv[]);

int test_tof_main(int argc, char *argv[])
{
	PX4_INFO("Init Tof !!!");

	/* 定义两个test_tof_s 数据结构体，tof用于发布数据，tof_copy用于订阅后复制数据 */
	struct test_tof_s tof;
    struct test_tof_s tof_copy;
	memset(&tof, 0, sizeof(tof));
   /* 公告一个消息，目的是发布这个消息 */
	orb_advert_t tof_pub = orb_advertise(ORB_ID(test_tof), &tof);
    /* 对数据进行虚假赋值*/
    tof.tof_amp = 100;
    tof.tof_distance = 200;
    tof.tof_phase = 300;

   /*发送数据*/
    orb_publish(ORB_ID(test_tof),tof_pub,&tof);

   	/* subscribe to sensor_combined topic(订阅一个消息ID) */
	int sensor_tof_fd = orb_subscribe(ORB_ID(test_tof));
	/* limit the update rate to 5 Hz */
   //设置sensor_combined消息的订阅时间间隔200毫秒一次
	orb_set_interval(sensor_tof_fd, 200);
   /* 将数据copy到新的结构体中进行验证*/
    orb_copy(ORB_ID(test_tof),sensor_tof_fd,&tof_copy);
  /* 打印数据进行验证*/
    PX4_INFO("[px4_tof] amp %d, distance %d ,phase %d\r\n", tof_copy.tof_amp,tof_copy.tof_distance,tof_copy.tof_phase);

	PX4_INFO("exiting");

	return 0;
}
