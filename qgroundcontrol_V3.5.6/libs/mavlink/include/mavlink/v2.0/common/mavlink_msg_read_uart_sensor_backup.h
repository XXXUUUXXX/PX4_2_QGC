#pragma once
// MESSAGE READ_UART_SENSOR PACKING

#define MAVLINK_MSG_ID_READ_UART_SENSOR 223


typedef struct __mavlink_read_uart_sensor_t {
 float voltage_sensor; /*<  float*/
 float current_sensor; /*<  float*/
 float temperature_sensor; /*<  float*/
 char voltage_str[20]; /*<  string*/
 char current_str[20]; /*<  string*/
 char temperature_str[20]; /*<  string*/
 char quantity_str[20]; /*<  string*/
 char remaining_str[20]; /*<  string*/
 uint8_t quantity_sensor; /*<  uint8_t*/
 uint8_t remaining_sensor; /*<  uint8_t*/
} mavlink_read_uart_sensor_t;

#define MAVLINK_MSG_ID_READ_UART_SENSOR_LEN 114
#define MAVLINK_MSG_ID_READ_UART_SENSOR_MIN_LEN 114
#define MAVLINK_MSG_ID_223_LEN 114
#define MAVLINK_MSG_ID_223_MIN_LEN 114

#define MAVLINK_MSG_ID_READ_UART_SENSOR_CRC 196
#define MAVLINK_MSG_ID_223_CRC 196

#define MAVLINK_MSG_READ_UART_SENSOR_FIELD_VOLTAGE_STR_LEN 20
#define MAVLINK_MSG_READ_UART_SENSOR_FIELD_CURRENT_STR_LEN 20
#define MAVLINK_MSG_READ_UART_SENSOR_FIELD_TEMPERATURE_STR_LEN 20
#define MAVLINK_MSG_READ_UART_SENSOR_FIELD_QUANTITY_STR_LEN 20
#define MAVLINK_MSG_READ_UART_SENSOR_FIELD_REMAINING_STR_LEN 20

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_READ_UART_SENSOR { \
    223, \
    "READ_UART_SENSOR", \
    10, \
    {  { "voltage_str", NULL, MAVLINK_TYPE_CHAR, 20, 12, offsetof(mavlink_read_uart_sensor_t, voltage_str) }, \
         { "current_str", NULL, MAVLINK_TYPE_CHAR, 20, 32, offsetof(mavlink_read_uart_sensor_t, current_str) }, \
         { "temperature_str", NULL, MAVLINK_TYPE_CHAR, 20, 52, offsetof(mavlink_read_uart_sensor_t, temperature_str) }, \
         { "quantity_str", NULL, MAVLINK_TYPE_CHAR, 20, 72, offsetof(mavlink_read_uart_sensor_t, quantity_str) }, \
         { "remaining_str", NULL, MAVLINK_TYPE_CHAR, 20, 92, offsetof(mavlink_read_uart_sensor_t, remaining_str) }, \
         { "voltage_sensor", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_read_uart_sensor_t, voltage_sensor) }, \
         { "current_sensor", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_read_uart_sensor_t, current_sensor) }, \
         { "temperature_sensor", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_read_uart_sensor_t, temperature_sensor) }, \
         { "quantity_sensor", NULL, MAVLINK_TYPE_UINT8_T, 0, 112, offsetof(mavlink_read_uart_sensor_t, quantity_sensor) }, \
         { "remaining_sensor", NULL, MAVLINK_TYPE_UINT8_T, 0, 113, offsetof(mavlink_read_uart_sensor_t, remaining_sensor) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_READ_UART_SENSOR { \
    "READ_UART_SENSOR", \
    10, \
    {  { "voltage_str", NULL, MAVLINK_TYPE_CHAR, 20, 12, offsetof(mavlink_read_uart_sensor_t, voltage_str) }, \
         { "current_str", NULL, MAVLINK_TYPE_CHAR, 20, 32, offsetof(mavlink_read_uart_sensor_t, current_str) }, \
         { "temperature_str", NULL, MAVLINK_TYPE_CHAR, 20, 52, offsetof(mavlink_read_uart_sensor_t, temperature_str) }, \
         { "quantity_str", NULL, MAVLINK_TYPE_CHAR, 20, 72, offsetof(mavlink_read_uart_sensor_t, quantity_str) }, \
         { "remaining_str", NULL, MAVLINK_TYPE_CHAR, 20, 92, offsetof(mavlink_read_uart_sensor_t, remaining_str) }, \
         { "voltage_sensor", NULL, MAVLINK_TYPE_FLOAT, 0, 0, offsetof(mavlink_read_uart_sensor_t, voltage_sensor) }, \
         { "current_sensor", NULL, MAVLINK_TYPE_FLOAT, 0, 4, offsetof(mavlink_read_uart_sensor_t, current_sensor) }, \
         { "temperature_sensor", NULL, MAVLINK_TYPE_FLOAT, 0, 8, offsetof(mavlink_read_uart_sensor_t, temperature_sensor) }, \
         { "quantity_sensor", NULL, MAVLINK_TYPE_UINT8_T, 0, 112, offsetof(mavlink_read_uart_sensor_t, quantity_sensor) }, \
         { "remaining_sensor", NULL, MAVLINK_TYPE_UINT8_T, 0, 113, offsetof(mavlink_read_uart_sensor_t, remaining_sensor) }, \
         } \
}
#endif

/**
 * @brief Pack a read_uart_sensor message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param voltage_str  string
 * @param current_str  string
 * @param temperature_str  string
 * @param quantity_str  string
 * @param remaining_str  string
 * @param voltage_sensor  float
 * @param current_sensor  float
 * @param temperature_sensor  float
 * @param quantity_sensor  uint8_t
 * @param remaining_sensor  uint8_t
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_read_uart_sensor_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               const char *voltage_str, const char *current_str, const char *temperature_str, const char *quantity_str, const char *remaining_str, float voltage_sensor, float current_sensor, float temperature_sensor, uint8_t quantity_sensor, uint8_t remaining_sensor)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_READ_UART_SENSOR_LEN];
    _mav_put_float(buf, 0, voltage_sensor);
    _mav_put_float(buf, 4, current_sensor);
    _mav_put_float(buf, 8, temperature_sensor);
    _mav_put_uint8_t(buf, 112, quantity_sensor);
    _mav_put_uint8_t(buf, 113, remaining_sensor);
    _mav_put_char_array(buf, 12, voltage_str, 20);
    _mav_put_char_array(buf, 32, current_str, 20);
    _mav_put_char_array(buf, 52, temperature_str, 20);
    _mav_put_char_array(buf, 72, quantity_str, 20);
    _mav_put_char_array(buf, 92, remaining_str, 20);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_READ_UART_SENSOR_LEN);
#else
    mavlink_read_uart_sensor_t packet;
    packet.voltage_sensor = voltage_sensor;
    packet.current_sensor = current_sensor;
    packet.temperature_sensor = temperature_sensor;
    packet.quantity_sensor = quantity_sensor;
    packet.remaining_sensor = remaining_sensor;
    mav_array_memcpy(packet.voltage_str, voltage_str, sizeof(char)*20);
    mav_array_memcpy(packet.current_str, current_str, sizeof(char)*20);
    mav_array_memcpy(packet.temperature_str, temperature_str, sizeof(char)*20);
    mav_array_memcpy(packet.quantity_str, quantity_str, sizeof(char)*20);
    mav_array_memcpy(packet.remaining_str, remaining_str, sizeof(char)*20);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_READ_UART_SENSOR_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_READ_UART_SENSOR;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_READ_UART_SENSOR_MIN_LEN, MAVLINK_MSG_ID_READ_UART_SENSOR_LEN, MAVLINK_MSG_ID_READ_UART_SENSOR_CRC);
}

/**
 * @brief Pack a read_uart_sensor message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param voltage_str  string
 * @param current_str  string
 * @param temperature_str  string
 * @param quantity_str  string
 * @param remaining_str  string
 * @param voltage_sensor  float
 * @param current_sensor  float
 * @param temperature_sensor  float
 * @param quantity_sensor  uint8_t
 * @param remaining_sensor  uint8_t
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_read_uart_sensor_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   const char *voltage_str,const char *current_str,const char *temperature_str,const char *quantity_str,const char *remaining_str,float voltage_sensor,float current_sensor,float temperature_sensor,uint8_t quantity_sensor,uint8_t remaining_sensor)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_READ_UART_SENSOR_LEN];
    _mav_put_float(buf, 0, voltage_sensor);
    _mav_put_float(buf, 4, current_sensor);
    _mav_put_float(buf, 8, temperature_sensor);
    _mav_put_uint8_t(buf, 112, quantity_sensor);
    _mav_put_uint8_t(buf, 113, remaining_sensor);
    _mav_put_char_array(buf, 12, voltage_str, 20);
    _mav_put_char_array(buf, 32, current_str, 20);
    _mav_put_char_array(buf, 52, temperature_str, 20);
    _mav_put_char_array(buf, 72, quantity_str, 20);
    _mav_put_char_array(buf, 92, remaining_str, 20);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_READ_UART_SENSOR_LEN);
#else
    mavlink_read_uart_sensor_t packet;
    packet.voltage_sensor = voltage_sensor;
    packet.current_sensor = current_sensor;
    packet.temperature_sensor = temperature_sensor;
    packet.quantity_sensor = quantity_sensor;
    packet.remaining_sensor = remaining_sensor;
    mav_array_memcpy(packet.voltage_str, voltage_str, sizeof(char)*20);
    mav_array_memcpy(packet.current_str, current_str, sizeof(char)*20);
    mav_array_memcpy(packet.temperature_str, temperature_str, sizeof(char)*20);
    mav_array_memcpy(packet.quantity_str, quantity_str, sizeof(char)*20);
    mav_array_memcpy(packet.remaining_str, remaining_str, sizeof(char)*20);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_READ_UART_SENSOR_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_READ_UART_SENSOR;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_READ_UART_SENSOR_MIN_LEN, MAVLINK_MSG_ID_READ_UART_SENSOR_LEN, MAVLINK_MSG_ID_READ_UART_SENSOR_CRC);
}

/**
 * @brief Encode a read_uart_sensor struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param read_uart_sensor C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_read_uart_sensor_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_read_uart_sensor_t* read_uart_sensor)
{
    return mavlink_msg_read_uart_sensor_pack(system_id, component_id, msg, read_uart_sensor->voltage_str, read_uart_sensor->current_str, read_uart_sensor->temperature_str, read_uart_sensor->quantity_str, read_uart_sensor->remaining_str, read_uart_sensor->voltage_sensor, read_uart_sensor->current_sensor, read_uart_sensor->temperature_sensor, read_uart_sensor->quantity_sensor, read_uart_sensor->remaining_sensor);
}

/**
 * @brief Encode a read_uart_sensor struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param read_uart_sensor C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_read_uart_sensor_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_read_uart_sensor_t* read_uart_sensor)
{
    return mavlink_msg_read_uart_sensor_pack_chan(system_id, component_id, chan, msg, read_uart_sensor->voltage_str, read_uart_sensor->current_str, read_uart_sensor->temperature_str, read_uart_sensor->quantity_str, read_uart_sensor->remaining_str, read_uart_sensor->voltage_sensor, read_uart_sensor->current_sensor, read_uart_sensor->temperature_sensor, read_uart_sensor->quantity_sensor, read_uart_sensor->remaining_sensor);
}

/**
 * @brief Send a read_uart_sensor message
 * @param chan MAVLink channel to send the message
 *
 * @param voltage_str  string
 * @param current_str  string
 * @param temperature_str  string
 * @param quantity_str  string
 * @param remaining_str  string
 * @param voltage_sensor  float
 * @param current_sensor  float
 * @param temperature_sensor  float
 * @param quantity_sensor  uint8_t
 * @param remaining_sensor  uint8_t
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_read_uart_sensor_send(mavlink_channel_t chan, const char *voltage_str, const char *current_str, const char *temperature_str, const char *quantity_str, const char *remaining_str, float voltage_sensor, float current_sensor, float temperature_sensor, uint8_t quantity_sensor, uint8_t remaining_sensor)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_READ_UART_SENSOR_LEN];
    _mav_put_float(buf, 0, voltage_sensor);
    _mav_put_float(buf, 4, current_sensor);
    _mav_put_float(buf, 8, temperature_sensor);
    _mav_put_uint8_t(buf, 112, quantity_sensor);
    _mav_put_uint8_t(buf, 113, remaining_sensor);
    _mav_put_char_array(buf, 12, voltage_str, 20);
    _mav_put_char_array(buf, 32, current_str, 20);
    _mav_put_char_array(buf, 52, temperature_str, 20);
    _mav_put_char_array(buf, 72, quantity_str, 20);
    _mav_put_char_array(buf, 92, remaining_str, 20);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_READ_UART_SENSOR, buf, MAVLINK_MSG_ID_READ_UART_SENSOR_MIN_LEN, MAVLINK_MSG_ID_READ_UART_SENSOR_LEN, MAVLINK_MSG_ID_READ_UART_SENSOR_CRC);
#else
    mavlink_read_uart_sensor_t packet;
    packet.voltage_sensor = voltage_sensor;
    packet.current_sensor = current_sensor;
    packet.temperature_sensor = temperature_sensor;
    packet.quantity_sensor = quantity_sensor;
    packet.remaining_sensor = remaining_sensor;
    mav_array_memcpy(packet.voltage_str, voltage_str, sizeof(char)*20);
    mav_array_memcpy(packet.current_str, current_str, sizeof(char)*20);
    mav_array_memcpy(packet.temperature_str, temperature_str, sizeof(char)*20);
    mav_array_memcpy(packet.quantity_str, quantity_str, sizeof(char)*20);
    mav_array_memcpy(packet.remaining_str, remaining_str, sizeof(char)*20);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_READ_UART_SENSOR, (const char *)&packet, MAVLINK_MSG_ID_READ_UART_SENSOR_MIN_LEN, MAVLINK_MSG_ID_READ_UART_SENSOR_LEN, MAVLINK_MSG_ID_READ_UART_SENSOR_CRC);
#endif
}

/**
 * @brief Send a read_uart_sensor message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_read_uart_sensor_send_struct(mavlink_channel_t chan, const mavlink_read_uart_sensor_t* read_uart_sensor)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_read_uart_sensor_send(chan, read_uart_sensor->voltage_str, read_uart_sensor->current_str, read_uart_sensor->temperature_str, read_uart_sensor->quantity_str, read_uart_sensor->remaining_str, read_uart_sensor->voltage_sensor, read_uart_sensor->current_sensor, read_uart_sensor->temperature_sensor, read_uart_sensor->quantity_sensor, read_uart_sensor->remaining_sensor);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_READ_UART_SENSOR, (const char *)read_uart_sensor, MAVLINK_MSG_ID_READ_UART_SENSOR_MIN_LEN, MAVLINK_MSG_ID_READ_UART_SENSOR_LEN, MAVLINK_MSG_ID_READ_UART_SENSOR_CRC);
#endif
}

#if MAVLINK_MSG_ID_READ_UART_SENSOR_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_read_uart_sensor_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  const char *voltage_str, const char *current_str, const char *temperature_str, const char *quantity_str, const char *remaining_str, float voltage_sensor, float current_sensor, float temperature_sensor, uint8_t quantity_sensor, uint8_t remaining_sensor)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_float(buf, 0, voltage_sensor);
    _mav_put_float(buf, 4, current_sensor);
    _mav_put_float(buf, 8, temperature_sensor);
    _mav_put_uint8_t(buf, 112, quantity_sensor);
    _mav_put_uint8_t(buf, 113, remaining_sensor);
    _mav_put_char_array(buf, 12, voltage_str, 20);
    _mav_put_char_array(buf, 32, current_str, 20);
    _mav_put_char_array(buf, 52, temperature_str, 20);
    _mav_put_char_array(buf, 72, quantity_str, 20);
    _mav_put_char_array(buf, 92, remaining_str, 20);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_READ_UART_SENSOR, buf, MAVLINK_MSG_ID_READ_UART_SENSOR_MIN_LEN, MAVLINK_MSG_ID_READ_UART_SENSOR_LEN, MAVLINK_MSG_ID_READ_UART_SENSOR_CRC);
#else
    mavlink_read_uart_sensor_t *packet = (mavlink_read_uart_sensor_t *)msgbuf;
    packet->voltage_sensor = voltage_sensor;
    packet->current_sensor = current_sensor;
    packet->temperature_sensor = temperature_sensor;
    packet->quantity_sensor = quantity_sensor;
    packet->remaining_sensor = remaining_sensor;
    mav_array_memcpy(packet->voltage_str, voltage_str, sizeof(char)*20);
    mav_array_memcpy(packet->current_str, current_str, sizeof(char)*20);
    mav_array_memcpy(packet->temperature_str, temperature_str, sizeof(char)*20);
    mav_array_memcpy(packet->quantity_str, quantity_str, sizeof(char)*20);
    mav_array_memcpy(packet->remaining_str, remaining_str, sizeof(char)*20);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_READ_UART_SENSOR, (const char *)packet, MAVLINK_MSG_ID_READ_UART_SENSOR_MIN_LEN, MAVLINK_MSG_ID_READ_UART_SENSOR_LEN, MAVLINK_MSG_ID_READ_UART_SENSOR_CRC);
#endif
}
#endif

#endif

// MESSAGE READ_UART_SENSOR UNPACKING


/**
 * @brief Get field voltage_str from read_uart_sensor message
 *
 * @return  string
 */
static inline uint16_t mavlink_msg_read_uart_sensor_get_voltage_str(const mavlink_message_t* msg, char *voltage_str)
{
    return _MAV_RETURN_char_array(msg, voltage_str, 20,  12);
}

/**
 * @brief Get field current_str from read_uart_sensor message
 *
 * @return  string
 */
static inline uint16_t mavlink_msg_read_uart_sensor_get_current_str(const mavlink_message_t* msg, char *current_str)
{
    return _MAV_RETURN_char_array(msg, current_str, 20,  32);
}

/**
 * @brief Get field temperature_str from read_uart_sensor message
 *
 * @return  string
 */
static inline uint16_t mavlink_msg_read_uart_sensor_get_temperature_str(const mavlink_message_t* msg, char *temperature_str)
{
    return _MAV_RETURN_char_array(msg, temperature_str, 20,  52);
}

/**
 * @brief Get field quantity_str from read_uart_sensor message
 *
 * @return  string
 */
static inline uint16_t mavlink_msg_read_uart_sensor_get_quantity_str(const mavlink_message_t* msg, char *quantity_str)
{
    return _MAV_RETURN_char_array(msg, quantity_str, 20,  72);
}

/**
 * @brief Get field remaining_str from read_uart_sensor message
 *
 * @return  string
 */
static inline uint16_t mavlink_msg_read_uart_sensor_get_remaining_str(const mavlink_message_t* msg, char *remaining_str)
{
    return _MAV_RETURN_char_array(msg, remaining_str, 20,  92);
}

/**
 * @brief Get field voltage_sensor from read_uart_sensor message
 *
 * @return  float
 */
static inline float mavlink_msg_read_uart_sensor_get_voltage_sensor(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  0);
}

/**
 * @brief Get field current_sensor from read_uart_sensor message
 *
 * @return  float
 */
static inline float mavlink_msg_read_uart_sensor_get_current_sensor(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  4);
}

/**
 * @brief Get field temperature_sensor from read_uart_sensor message
 *
 * @return  float
 */
static inline float mavlink_msg_read_uart_sensor_get_temperature_sensor(const mavlink_message_t* msg)
{
    return _MAV_RETURN_float(msg,  8);
}

/**
 * @brief Get field quantity_sensor from read_uart_sensor message
 *
 * @return  uint8_t
 */
static inline uint8_t mavlink_msg_read_uart_sensor_get_quantity_sensor(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  112);
}

/**
 * @brief Get field remaining_sensor from read_uart_sensor message
 *
 * @return  uint8_t
 */
static inline uint8_t mavlink_msg_read_uart_sensor_get_remaining_sensor(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  113);
}

/**
 * @brief Decode a read_uart_sensor message into a struct
 *
 * @param msg The message to decode
 * @param read_uart_sensor C-struct to decode the message contents into
 */
static inline void mavlink_msg_read_uart_sensor_decode(const mavlink_message_t* msg, mavlink_read_uart_sensor_t* read_uart_sensor)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    read_uart_sensor->voltage_sensor = mavlink_msg_read_uart_sensor_get_voltage_sensor(msg);
    read_uart_sensor->current_sensor = mavlink_msg_read_uart_sensor_get_current_sensor(msg);
    read_uart_sensor->temperature_sensor = mavlink_msg_read_uart_sensor_get_temperature_sensor(msg);
    mavlink_msg_read_uart_sensor_get_voltage_str(msg, read_uart_sensor->voltage_str);
    mavlink_msg_read_uart_sensor_get_current_str(msg, read_uart_sensor->current_str);
    mavlink_msg_read_uart_sensor_get_temperature_str(msg, read_uart_sensor->temperature_str);
    mavlink_msg_read_uart_sensor_get_quantity_str(msg, read_uart_sensor->quantity_str);
    mavlink_msg_read_uart_sensor_get_remaining_str(msg, read_uart_sensor->remaining_str);
    read_uart_sensor->quantity_sensor = mavlink_msg_read_uart_sensor_get_quantity_sensor(msg);
    read_uart_sensor->remaining_sensor = mavlink_msg_read_uart_sensor_get_remaining_sensor(msg);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_READ_UART_SENSOR_LEN? msg->len : MAVLINK_MSG_ID_READ_UART_SENSOR_LEN;
        memset(read_uart_sensor, 0, MAVLINK_MSG_ID_READ_UART_SENSOR_LEN);
    memcpy(read_uart_sensor, _MAV_PAYLOAD(msg), len);
#endif
}
