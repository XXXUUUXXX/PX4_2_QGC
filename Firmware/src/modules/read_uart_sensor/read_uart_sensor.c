#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <stdbool.h>
#include <errno.h>
#include <drivers/drv_hrt.h>
#include <string.h>
#include <systemlib/err.h>
#include <nuttx/config.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <poll.h>
#include <uORB/uORB.h>
#include <uORB/topics/sensor_combined.h>
#include <uORB/topics/vehicle_attitude.h>
#include <uORB/topics/read_uart_sensor.h>
#include <px4_platform_common/tasks.h>

static int daemon_task;
static bool thread_should_exit = true;
static bool thread_running = false;

__EXPORT int read_uart_sensor_main(int argc, char *argv[]);
int read_uart_thread_main(int argc, char *argv[]);

static void usage(const char *reason);
static int uart_init(char * uart_name);
static int set_uart_baudrate(const int fd, unsigned int baud);

int set_uart_baudrate(const int fd, unsigned int baud)
{
    int speed;

    switch (baud) {
    case 9600:   speed = 9600;   break;
    case 19200:  speed = 19200;  break;
    case 38400:  speed = 38400;  break;
    case 57600:  speed = 57600;  break;
    case 115200: speed = 115200; break;
    default:
        warnx("ERR: baudrate: %d\n", baud);
        return -EINVAL;
    }

    struct termios uart_config;
    /*
    termios 函数族提供了一个常规的终端接口，用于控制非同步通信端口。 这个结构包含了至少下列成员：
    tcflag_t c_iflag;      输入模式
    tcflag_t c_oflag;      输出模式
    tcflag_t c_cflag;      控制模式
    tcflag_t c_lflag;      本地模式
    cc_t c_cc[NCCS];       控制字符
    */

    int termios_state;

    /* 以新的配置填充结构体 */
    /* 设置某个选项，那么就使用"|="运算，
     * 如果关闭某个选项就使用"&="和"~"运算
     * */
    tcgetattr(fd, &uart_config); // 获取终端参数

    /* clear ONLCR flag (which appends a CR for every LF) */
    uart_config.c_oflag &= ~ONLCR;// 将NL转换成CR(回车)-NL后输出。

    /* 无偶校验，一个停止位 */
    uart_config.c_cflag &= ~(CSTOPB | PARENB);// CSTOPB 使用两个停止位，PARENB 表示偶校验

    /* 设置波特率 */
    if ((termios_state = cfsetispeed(&uart_config, speed)) < 0) {
        warnx("ERR: %d (cfsetispeed)\n", termios_state);
        return false;
    }

    if ((termios_state = cfsetospeed(&uart_config, speed)) < 0) {
        warnx("ERR: %d (cfsetospeed)\n", termios_state);
        return false;
    }
    // 设置与终端相关的参数，TCSANOW 立即改变参数
    if ((termios_state = tcsetattr(fd, TCSANOW, &uart_config)) < 0) {
        warnx("ERR: %d (tcsetattr)\n", termios_state);
        return false;
    }
    return true;
}

int uart_init(char * uart_name)
{
    int serial_fd = open(uart_name, O_RDWR | O_NOCTTY);
    // printf("serial_fd = %d", serial_fd);
    if (serial_fd < 0)
    {
        err(1, "failed to open port: %s", uart_name);
        return false;
    }
    return serial_fd;
}

static void usage(const char *reason)
{
    if (reason) {
        fprintf(stderr, "%s\n", reason);
    }

    fprintf(stderr, "usage: read_uart_sensor {start|stop|status} [param]\n\n");
    exit(1);
}

int read_uart_sensor_main(int argc, char *argv[])
{
    // printf("argv_0 = %s,argv_1 = %s, argv_2 = %s",argv[0],argv[1], argv[2]);
    if (argc < 2)
    {
        usage("missing command");
    }

    if (!strcmp(argv[1], "start")){
        if (thread_running){
            warnx("already running\n");
            // exit(0);
            return 0;
        }

        thread_should_exit = false;
        daemon_task = px4_task_spawn_cmd("read_uart_sensor",//任务接口句柄
                                         SCHED_DEFAULT,
                                        //  SCHED_PRIORITY_DEFAULT,
                                         SCHED_PRIORITY_MAX - 5,
                                         2000,
                                         read_uart_thread_main,
                                         (argv) ? (char * const *)&argv[2] : (char * const *)NULL);
        // exit(0);
        return 0;
    }

    if (!strcmp(argv[1], "stop")){
        thread_should_exit = true;
        // exit(0);
        return 0;
    }

    if (!strcmp(argv[1], "status")){
        if (thread_running)
        {
            warnx("running");
            // return 0;//

        } else
        {
            warnx("stopped");
            // return 1;//
        }
        return 0;
    }
    usage("unrecognized command");
    PX4_INFO("exiting");
    return 1;
}

int read_uart_thread_main(int argc,char *argv[])
{
    char data = '0';
    char buffer[30] = "";
    const char douhao[2] = ","; //逗号
    char *result = NULL;
    int index = 0;

    /* 读取start_charge和stop_charge */
    int read_uart_sensor_sub_fd = orb_subscribe(ORB_ID(read_uart_sensor));
    printf("read_uart_sensor_sub_fd = %d\n", read_uart_sensor_sub_fd);
#if 0
    struct read_uart_sensor_s read_uart_sensor_sub;
    memset(&read_uart_sensor_sub, 0, sizeof(read_uart_sensor_sub));
    // char start_charge_sub[5];
    // char stop_charge_sub[5];
    int start_charge_sub;
    int stop_charge_sub;
#endif

    /*
     * TELEM1 : /dev/ttyS1
     * TELEM2 : /dev/ttyS2
     * GPS
     * : /dev/ttyS3
     * NSH    : /dev/ttyS5
     * SERIAL4: /dev/ttyS6
     * N/A    : /dev/ttyS4
     * IO DEBUG (RX only):/dev/ttyS0
     */
    // int uart_read = uart_init(uart_name);
    int uart_read = uart_init("/dev/ttyS3");

    if(false == uart_read){
        printf("read uart failed\n");
        return -1;
    }
    // 此处设置波特率
    if(false == set_uart_baudrate(uart_read,115200))
    {
        printf("set_uart_baudrate is failed\n");
        return -1;
    }
    printf("uart init is successful\n");

    thread_running = true;

    /*初始化数据结构体 */
    struct read_uart_sensor_s orbtest;
    memset(&orbtest,0,sizeof(orbtest));

    //公告，公告必须在发布之前，否则即使订阅也得不到任何数据
    orb_advert_t pub_fd = orb_advertise(ORB_ID(read_uart_sensor),&orbtest);

    while (!thread_should_exit){
#if 0
        bool updated;
        orb_check(read_uart_sensor_sub_fd, &updated);
        if (updated) { //更新
            orb_copy(ORB_ID(read_uart_sensor), read_uart_sensor_sub_fd, & read_uart_sensor_sub);
            start_charge_sub = read_uart_sensor_sub.start_charge;
            stop_charge_sub = read_uart_sensor_sub.stop_charge;
            // strcpy(start_charge_sub, read_uart_sensor_sub.start_charge);
            // strcpy(stop_charge_sub, read_uart_sensor_sub.stop_charge);
            // memcpy(start_charge_sub, read_uart_sensor_sub.start_charge,
            //         sizeof(read_uart_sensor_sub.start_charge));
            // memcpy(stop_charge_sub, read_uart_sensor_sub.stop_charge,
            //         sizeof(read_uart_sensor_sub.stop_charge));
            // start_charge_sub = read_uart_sensor_sub.start_charge;
            // stop_charge_sub = read_uart_sensor_sub.stop_charge;
            printf("start_charge = %d, stop_charge = %d\n", start_charge_sub, stop_charge_sub);
            printf("read_uart_sensor_sub.start_charge = %d, read_uart_sensor_sub.stop_charge = %d\n",
                    read_uart_sensor_sub.start_charge, read_uart_sensor_sub.stop_charge);

        }
#endif



        read(uart_read,&data,1);
        /* 举例 UART发送消息 */
        // R15.42,18.13,-1.5,18,40
        // R53.42,57.13,+5.5,58,33
        if(data == 'R'){
            for(int i = 0;i <22; ++i){   // i 为字符个数
                read(uart_read, &data, 1);
                buffer[i] = data;
                data = '0';
            }
            //逗号分割,返回下一个分割后的字符串指针，如果没有可检索的字符串，则返回一个空指针。
            result = strtok(buffer, douhao);
            // printf("buffer = %s\n", buffer);
            // printf("result = %s\n", result);
            // printf("\r\nstart read\r\n");
            if(result){
                printf("split ok\r\n");
            }else{
                printf("failed\r\n");
            }
            while(result != NULL) {
                index++;
                switch(index){
                    case 1:
                        //定义的数组不够大越界操作NULL被覆盖掉，每个数组起码加大1容纳NULL结尾
                        // strncpy(orbtest.voltage_str, result, 5);//5+1=6
                        strncpy(orbtest.voltage_str, result, 6);
                        // printf("orbtest.voltage_str = ", orbtest.voltage_str);
                        break;
                    case 2:
                        strncpy(orbtest.current_str, result, 7);
                        // printf("orbtest.voltage_str = ", orbtest.current_str);
                        break;
                    case 3:
                        strncpy(orbtest.temperature_str, result, 6);
                        // printf("orbtest.voltage_str = ", orbtest.temperature_str);
                        break;
                    case 4:
                        strncpy(orbtest.quantity_str, result, 3);
                        // printf("orbtest.voltage_str = ", orbtest.quantity_str);
                        break;
                    case 5:
                        strncpy(orbtest.remaining_str, result, 3);
                        // printf("orbtest.voltage_str = ", orbtest.remaining_str);
                        break;
                }
                result = strtok(NULL, douhao);
            }
            printf("stop read\r\n");
            index = 0;
            //指定长度的字符串复制到字符数组中
            // strncpy(orbtest.datastr, buffer, 19);

            //atoi()把字符串转换成整型数
            // atof()把字符串转换成浮点数,默认为6位小数
            orbtest.voltage_sensor = atof(orbtest.voltage_str);
            orbtest.current_sensor = atof(orbtest.current_str);
            orbtest.temperature_sensor = atof(orbtest.temperature_str);
            orbtest.quantity_sensor = atoi(orbtest.quantity_str);
            orbtest.remaining_sensor = atoi(orbtest.remaining_str);
            //发布
            orb_publish(ORB_ID(read_uart_sensor), pub_fd, &orbtest);

            printf("orbtest.voltage_sensor = %.2f\r\n", (double)orbtest.voltage_sensor);
            printf("orbtest.current_sensor = %.2f\r\n", (double)orbtest.current_sensor);
            printf("orbtest.temperature_sensor = %.1f\r\n", (double)orbtest.temperature_sensor);
            printf("orbtest.quantity_sensor = %d\r\n", (int)orbtest.quantity_sensor);
            printf("orbtest.remaining_sensor = %d\r\n", (int)orbtest.remaining_sensor);
        }
    }

    warnx("exiting");
    thread_running = false;
    close(uart_read);
    fflush(stdout);
    return 0;
}
