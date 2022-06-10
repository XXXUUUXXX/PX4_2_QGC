#pragma once
// MESSAGE RTX_GCS2UAV PACKING

#define MAVLINK_MSG_ID_RTX_GCS2UAV 211


typedef struct __mavlink_rtx_gcs2uav_t {
 uint8_t dev; /*<  which port send to ,see RSRTX_OPT_DEV_ENUM*/
 uint8_t len; /*<  pkg lenght , 250 max*/
 uint8_t data[250]; /*<  data payload*/
} mavlink_rtx_gcs2uav_t;

#define MAVLINK_MSG_ID_RTX_GCS2UAV_LEN 252
#define MAVLINK_MSG_ID_RTX_GCS2UAV_MIN_LEN 252
#define MAVLINK_MSG_ID_211_LEN 252
#define MAVLINK_MSG_ID_211_MIN_LEN 252

#define MAVLINK_MSG_ID_RTX_GCS2UAV_CRC 35
#define MAVLINK_MSG_ID_211_CRC 35

#define MAVLINK_MSG_RTX_GCS2UAV_FIELD_DATA_LEN 250

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_RTX_GCS2UAV { \
    211, \
    "RTX_GCS2UAV", \
    3, \
    {  { "dev", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_rtx_gcs2uav_t, dev) }, \
         { "len", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_rtx_gcs2uav_t, len) }, \
         { "data", NULL, MAVLINK_TYPE_UINT8_T, 250, 2, offsetof(mavlink_rtx_gcs2uav_t, data) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_RTX_GCS2UAV { \
    "RTX_GCS2UAV", \
    3, \
    {  { "dev", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_rtx_gcs2uav_t, dev) }, \
         { "len", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_rtx_gcs2uav_t, len) }, \
         { "data", NULL, MAVLINK_TYPE_UINT8_T, 250, 2, offsetof(mavlink_rtx_gcs2uav_t, data) }, \
         } \
}
#endif

/**
 * @brief Pack a rtx_gcs2uav message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param dev  which port send to ,see RSRTX_OPT_DEV_ENUM
 * @param len  pkg lenght , 250 max
 * @param data  data payload
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_rtx_gcs2uav_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t dev, uint8_t len, const uint8_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RTX_GCS2UAV_LEN];
    _mav_put_uint8_t(buf, 0, dev);
    _mav_put_uint8_t(buf, 1, len);
    _mav_put_uint8_t_array(buf, 2, data, 250);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RTX_GCS2UAV_LEN);
#else
    mavlink_rtx_gcs2uav_t packet;
    packet.dev = dev;
    packet.len = len;
    mav_array_memcpy(packet.data, data, sizeof(uint8_t)*250);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RTX_GCS2UAV_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_RTX_GCS2UAV;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_RTX_GCS2UAV_MIN_LEN, MAVLINK_MSG_ID_RTX_GCS2UAV_LEN, MAVLINK_MSG_ID_RTX_GCS2UAV_CRC);
}

/**
 * @brief Pack a rtx_gcs2uav message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param dev  which port send to ,see RSRTX_OPT_DEV_ENUM
 * @param len  pkg lenght , 250 max
 * @param data  data payload
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_rtx_gcs2uav_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t dev,uint8_t len,const uint8_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RTX_GCS2UAV_LEN];
    _mav_put_uint8_t(buf, 0, dev);
    _mav_put_uint8_t(buf, 1, len);
    _mav_put_uint8_t_array(buf, 2, data, 250);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RTX_GCS2UAV_LEN);
#else
    mavlink_rtx_gcs2uav_t packet;
    packet.dev = dev;
    packet.len = len;
    mav_array_memcpy(packet.data, data, sizeof(uint8_t)*250);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RTX_GCS2UAV_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_RTX_GCS2UAV;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_RTX_GCS2UAV_MIN_LEN, MAVLINK_MSG_ID_RTX_GCS2UAV_LEN, MAVLINK_MSG_ID_RTX_GCS2UAV_CRC);
}

/**
 * @brief Encode a rtx_gcs2uav struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param rtx_gcs2uav C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_rtx_gcs2uav_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_rtx_gcs2uav_t* rtx_gcs2uav)
{
    return mavlink_msg_rtx_gcs2uav_pack(system_id, component_id, msg, rtx_gcs2uav->dev, rtx_gcs2uav->len, rtx_gcs2uav->data);
}

/**
 * @brief Encode a rtx_gcs2uav struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param rtx_gcs2uav C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_rtx_gcs2uav_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_rtx_gcs2uav_t* rtx_gcs2uav)
{
    return mavlink_msg_rtx_gcs2uav_pack_chan(system_id, component_id, chan, msg, rtx_gcs2uav->dev, rtx_gcs2uav->len, rtx_gcs2uav->data);
}

/**
 * @brief Send a rtx_gcs2uav message
 * @param chan MAVLink channel to send the message
 *
 * @param dev  which port send to ,see RSRTX_OPT_DEV_ENUM
 * @param len  pkg lenght , 250 max
 * @param data  data payload
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_rtx_gcs2uav_send(mavlink_channel_t chan, uint8_t dev, uint8_t len, const uint8_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RTX_GCS2UAV_LEN];
    _mav_put_uint8_t(buf, 0, dev);
    _mav_put_uint8_t(buf, 1, len);
    _mav_put_uint8_t_array(buf, 2, data, 250);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RTX_GCS2UAV, buf, MAVLINK_MSG_ID_RTX_GCS2UAV_MIN_LEN, MAVLINK_MSG_ID_RTX_GCS2UAV_LEN, MAVLINK_MSG_ID_RTX_GCS2UAV_CRC);
#else
    mavlink_rtx_gcs2uav_t packet;
    packet.dev = dev;
    packet.len = len;
    mav_array_memcpy(packet.data, data, sizeof(uint8_t)*250);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RTX_GCS2UAV, (const char *)&packet, MAVLINK_MSG_ID_RTX_GCS2UAV_MIN_LEN, MAVLINK_MSG_ID_RTX_GCS2UAV_LEN, MAVLINK_MSG_ID_RTX_GCS2UAV_CRC);
#endif
}

/**
 * @brief Send a rtx_gcs2uav message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_rtx_gcs2uav_send_struct(mavlink_channel_t chan, const mavlink_rtx_gcs2uav_t* rtx_gcs2uav)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_rtx_gcs2uav_send(chan, rtx_gcs2uav->dev, rtx_gcs2uav->len, rtx_gcs2uav->data);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RTX_GCS2UAV, (const char *)rtx_gcs2uav, MAVLINK_MSG_ID_RTX_GCS2UAV_MIN_LEN, MAVLINK_MSG_ID_RTX_GCS2UAV_LEN, MAVLINK_MSG_ID_RTX_GCS2UAV_CRC);
#endif
}

#if MAVLINK_MSG_ID_RTX_GCS2UAV_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_rtx_gcs2uav_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t dev, uint8_t len, const uint8_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, dev);
    _mav_put_uint8_t(buf, 1, len);
    _mav_put_uint8_t_array(buf, 2, data, 250);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RTX_GCS2UAV, buf, MAVLINK_MSG_ID_RTX_GCS2UAV_MIN_LEN, MAVLINK_MSG_ID_RTX_GCS2UAV_LEN, MAVLINK_MSG_ID_RTX_GCS2UAV_CRC);
#else
    mavlink_rtx_gcs2uav_t *packet = (mavlink_rtx_gcs2uav_t *)msgbuf;
    packet->dev = dev;
    packet->len = len;
    mav_array_memcpy(packet->data, data, sizeof(uint8_t)*250);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RTX_GCS2UAV, (const char *)packet, MAVLINK_MSG_ID_RTX_GCS2UAV_MIN_LEN, MAVLINK_MSG_ID_RTX_GCS2UAV_LEN, MAVLINK_MSG_ID_RTX_GCS2UAV_CRC);
#endif
}
#endif

#endif

// MESSAGE RTX_GCS2UAV UNPACKING


/**
 * @brief Get field dev from rtx_gcs2uav message
 *
 * @return  which port send to ,see RSRTX_OPT_DEV_ENUM
 */
static inline uint8_t mavlink_msg_rtx_gcs2uav_get_dev(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field len from rtx_gcs2uav message
 *
 * @return  pkg lenght , 250 max
 */
static inline uint8_t mavlink_msg_rtx_gcs2uav_get_len(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field data from rtx_gcs2uav message
 *
 * @return  data payload
 */
static inline uint16_t mavlink_msg_rtx_gcs2uav_get_data(const mavlink_message_t* msg, uint8_t *data)
{
    return _MAV_RETURN_uint8_t_array(msg, data, 250,  2);
}

/**
 * @brief Decode a rtx_gcs2uav message into a struct
 *
 * @param msg The message to decode
 * @param rtx_gcs2uav C-struct to decode the message contents into
 */
static inline void mavlink_msg_rtx_gcs2uav_decode(const mavlink_message_t* msg, mavlink_rtx_gcs2uav_t* rtx_gcs2uav)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    rtx_gcs2uav->dev = mavlink_msg_rtx_gcs2uav_get_dev(msg);
    rtx_gcs2uav->len = mavlink_msg_rtx_gcs2uav_get_len(msg);
    mavlink_msg_rtx_gcs2uav_get_data(msg, rtx_gcs2uav->data);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_RTX_GCS2UAV_LEN? msg->len : MAVLINK_MSG_ID_RTX_GCS2UAV_LEN;
        memset(rtx_gcs2uav, 0, MAVLINK_MSG_ID_RTX_GCS2UAV_LEN);
    memcpy(rtx_gcs2uav, _MAV_PAYLOAD(msg), len);
#endif
}
