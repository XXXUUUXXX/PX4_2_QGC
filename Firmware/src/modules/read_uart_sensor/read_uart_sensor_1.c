#include <px4_platform_common/px4_config.h>
#include <px4_platform_common/tasks.h>
#include <px4_platform_common/posix.h>
#include <unistd.h>
#include <stdio.h>
#include <poll.h>
#include <string.h>
#include <uORB/uORB.h>
#include <stdio.h>
#include <termios.h>
#include <unistd.h>
#include <stdbool.h>
#include <errno.h>
#include <drivers/drv_hrt.h>
#include <string.h>
#include <systemlib/err.h>
#include <systemlib/systemlib.h>
#include <fcntl.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <uORB/topics/read_uart_sensor.h>

static int daemon_task;
static bool thread_should_exit = false;
static bool thread_running = false;

 
 
__EXPORT int read_uart_sensor_main(int argc, char *argv[]);
int read_uart_sensor_thread_main(int argc, char *argv[]);

static void usage(const char *reason);
static int uart_init(const char * uart_name);
static int set_uart_baudrate(const int fd, unsigned int baud);

int set_uart_baudrate(const int fd, unsigned int baud)//自动选取波特率
{
    int speed;
 
    switch (baud) {
        case 9600:   speed = B9600;   break;
        case 19200:  speed = B19200;  break;
        case 38400:  speed = B38400;  break;
        case 57600:  speed = B57600;  break;
        case 115200: speed = B115200; break;
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
    tcgetattr(fd, &uart_config);// 获取终端参数
    /* clear ONLCR flag (which appends a CR for every LF) */
    uart_config.c_oflag &= ~ONLCR;
    /* no parity, one stop bit */
    uart_config.c_cflag &= ~(CSTOPB | PARENB);
    
    /* set baud rate */
    if ((termios_state = cfsetispeed(&uart_config, speed)) < 0) {
        warnx("ERR: %d (cfsetispeed)\n", termios_state);
        return false;
    }
 
    if ((termios_state = cfsetospeed(&uart_config, speed)) < 0) {
        warnx("ERR: %d (cfsetospeed)\n", termios_state);
        return false;
    }
 
    if ((termios_state = tcsetattr(fd, TCSANOW, &uart_config)) < 0) {
        warnx("ERR: %d (tcsetattr)\n", termios_state);
        return false;
    }
 
    return true;
}
 
 
int uart_init(const char * uart_name)
{
    int serial_fd = open(uart_name, O_RDWR | O_NOCTTY);
 
    if (serial_fd < 0) {
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
 
    fprintf(stderr, "usage: position_estimator_inav {start|stop|status} [param]\n\n");
    exit(1);
}
 
int read_uart_sensor_main(int argc, char *argv[])
{
    if (argc < 2) {
        usage("[FC]missing command");
    }
 
    if (!strcmp(argv[1], "start")) {
        if (thread_running) {
            warnx("[FC]already running\n");
            exit(0);
        }
 
        thread_should_exit = false;
        daemon_task = px4_task_spawn_cmd("read_uart_sensor",//任务接口句柄
                         SCHED_DEFAULT,
                         SCHED_PRIORITY_MAX - 5,
                         2000,
                         read_uart_sensor_thread_main,
                         (argv) ? (char * const *)&argv[2] : (char * const *)NULL);
        exit(0);
    }
 
    if (!strcmp(argv[1], "stop")) {
        thread_should_exit = true;
        exit(0);
    }
 
    if (!strcmp(argv[1], "status")) {
        if (thread_running) {
            warnx("[FC]running");
 
        } else {
            warnx("[FC]stopped");
        }
 
        exit(0);
    }
 
    usage("unrecognized command");
    exit(1);
}
 
int read_uart_sensor_thread_main(int argc, char *argv[])
{
 
    if (argc < 2) {
        errx(1, "[FC]need a serial port name as argument");
        usage("eg:");
    }
 
    const char *uart_name = argv[1];
 
    warnx("[FC]opening port %s", uart_name);
    char data = '0';
    char buffer[5] = "";
    /*
     * TELEM1 : /dev/ttyS1
     * TELEM2 : /dev/ttyS2
     * GPS    : /dev/ttyS3
     * NSH    : /dev/ttyS5
     * SERIAL4: /dev/ttyS6
     * N/A    : /dev/ttyS4
     * IO DEBUG (RX only):/dev/ttyS0
     */
    int uart_read = uart_init(uart_name);
    if(false == uart_read)return -1;
    if(false == set_uart_baudrate(uart_read,9600)){
        printf("[FC]set_uart_baudrate is failed\n");
        return -1;
    }
    printf("[FC]uart init is successful\n");
 
    thread_running = true;
 
    /*初始化数据结构体 */
    struct read_uart_sensor_s sonardata;
    memset(&sonardata, 0, sizeof(sonardata));
    /* 公告主题 */
    orb_advert_t read_uart_sensor_pub = orb_advertise(ORB_ID(read_uart_sensor), &sonardata);
 
 
    while(!thread_should_exit){
        read(uart_read,&data,1);
        if(data == 'R'){//这个地方是模拟树莓派发送的R1100数据，在超声波处注释掉这个if条件语句，直接读取
            for(int i = 0;i <4;++i){
 
                read(uart_read,&data,1);
 
                buffer[i] = data;
 
                //data = '0';
            }
           // printf("%s\n",buffer);
            strncpy(sonardata.datastr,buffer,4);
            sonardata.data = atoi(sonardata.datastr);
           // printf("[YCM]sonar.data=%s\n",sonardata.datastr);
            orb_publish(ORB_ID(read_uart_sensor), read_uart_sensor_pub, &sonardata);
        }
    }
 
    warnx("[FC]exiting");
    thread_running = false;
    close(uart_read);
    fflush(stdout);
    return 0;
}
