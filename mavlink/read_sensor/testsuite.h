/** @file
 *    @brief MAVLink comm protocol testsuite generated from read_sensor.xml
 *    @see http://qgroundcontrol.org/mavlink/
 */
#pragma once
#ifndef READ_SENSOR_TESTSUITE_H
#define READ_SENSOR_TESTSUITE_H

#ifdef __cplusplus
extern "C" {
#endif

#ifndef MAVLINK_TEST_ALL
#define MAVLINK_TEST_ALL

static void mavlink_test_read_sensor(uint8_t, uint8_t, mavlink_message_t *last_msg);

static void mavlink_test_all(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{

    mavlink_test_read_sensor(system_id, component_id, last_msg);
}
#endif




static void mavlink_test_read_uart_sensor(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
    mavlink_status_t *status = mavlink_get_channel_status(MAVLINK_COMM_0);
        if ((status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) && MAVLINK_MSG_ID_READ_UART_SENSOR >= 256) {
            return;
        }
#endif
    mavlink_message_t msg;
        uint8_t buffer[MAVLINK_MAX_PACKET_LEN];
        uint16_t i;
    mavlink_read_uart_sensor_t packet_in = {
        17.0,45.0,73.0,101.0,129.0,"UVWXYZABCDEFGHIJKLM","OPQRSTUVWXYZABCDEFG","IJKLMNOPQRSTUVWXYZA","CDEFGHIJKLMNOPQRSTU","WXYZABCDEFGHIJKLMNO"
    };
    mavlink_read_uart_sensor_t packet1, packet2;
        memset(&packet1, 0, sizeof(packet1));
        packet1.voltage_sensor = packet_in.voltage_sensor;
        packet1.current_sensor = packet_in.current_sensor;
        packet1.temperature_sensor = packet_in.temperature_sensor;
        packet1.quantity_sensor = packet_in.quantity_sensor;
        packet1.remaining_sensor = packet_in.remaining_sensor;
        
        mav_array_memcpy(packet1.voltage_str, packet_in.voltage_str, sizeof(char)*20);
        mav_array_memcpy(packet1.current_str, packet_in.current_str, sizeof(char)*20);
        mav_array_memcpy(packet1.temperature_str, packet_in.temperature_str, sizeof(char)*20);
        mav_array_memcpy(packet1.quantity_str, packet_in.quantity_str, sizeof(char)*20);
        mav_array_memcpy(packet1.remaining_str, packet_in.remaining_str, sizeof(char)*20);
        
#ifdef MAVLINK_STATUS_FLAG_OUT_MAVLINK1
        if (status->flags & MAVLINK_STATUS_FLAG_OUT_MAVLINK1) {
           // cope with extensions
           memset(MAVLINK_MSG_ID_READ_UART_SENSOR_MIN_LEN + (char *)&packet1, 0, sizeof(packet1)-MAVLINK_MSG_ID_READ_UART_SENSOR_MIN_LEN);
        }
#endif
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_read_uart_sensor_encode(system_id, component_id, &msg, &packet1);
    mavlink_msg_read_uart_sensor_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_read_uart_sensor_pack(system_id, component_id, &msg , packet1.voltage_str , packet1.current_str , packet1.temperature_str , packet1.quantity_str , packet1.remaining_str , packet1.voltage_sensor , packet1.current_sensor , packet1.temperature_sensor , packet1.quantity_sensor , packet1.remaining_sensor );
    mavlink_msg_read_uart_sensor_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_read_uart_sensor_pack_chan(system_id, component_id, MAVLINK_COMM_0, &msg , packet1.voltage_str , packet1.current_str , packet1.temperature_str , packet1.quantity_str , packet1.remaining_str , packet1.voltage_sensor , packet1.current_sensor , packet1.temperature_sensor , packet1.quantity_sensor , packet1.remaining_sensor );
    mavlink_msg_read_uart_sensor_decode(&msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);

        memset(&packet2, 0, sizeof(packet2));
        mavlink_msg_to_send_buffer(buffer, &msg);
        for (i=0; i<mavlink_msg_get_send_buffer_length(&msg); i++) {
            comm_send_ch(MAVLINK_COMM_0, buffer[i]);
        }
    mavlink_msg_read_uart_sensor_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
        
        memset(&packet2, 0, sizeof(packet2));
    mavlink_msg_read_uart_sensor_send(MAVLINK_COMM_1 , packet1.voltage_str , packet1.current_str , packet1.temperature_str , packet1.quantity_str , packet1.remaining_str , packet1.voltage_sensor , packet1.current_sensor , packet1.temperature_sensor , packet1.quantity_sensor , packet1.remaining_sensor );
    mavlink_msg_read_uart_sensor_decode(last_msg, &packet2);
        MAVLINK_ASSERT(memcmp(&packet1, &packet2, sizeof(packet1)) == 0);
}

static void mavlink_test_read_sensor(uint8_t system_id, uint8_t component_id, mavlink_message_t *last_msg)
{
    mavlink_test_read_uart_sensor(system_id, component_id, last_msg);
}

#ifdef __cplusplus
}
#endif // __cplusplus
#endif // READ_SENSOR_TESTSUITE_H
