set(MODULE_CFLAGS)
px4_add_module(
        MODULE modules_read_uart_sensor
        MAIN read_uart_sensor
    COMPILE_FLAGS
        -Os
    SRCS
        read_uart_sensor.c
    DEPENDS
    )



