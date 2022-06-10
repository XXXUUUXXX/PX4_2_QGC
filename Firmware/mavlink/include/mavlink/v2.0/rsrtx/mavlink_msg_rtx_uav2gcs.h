#pragma once
// MESSAGE RTX_UAV2GCS PACKING

#define MAVLINK_MSG_ID_RTX_UAV2GCS 213


typedef struct __mavlink_rtx_uav2gcs_t {
 uint8_t dev; /*<  which port send this pkg,see RSRTX_OPT_DEV_ENUM*/
 uint8_t len; /*<  pkg lenght , 250 max*/
 uint8_t data[250]; /*<  data payload*/
} mavlink_rtx_uav2gcs_t;

#define MAVLINK_MSG_ID_RTX_UAV2GCS_LEN 252
#define MAVLINK_MSG_ID_RTX_UAV2GCS_MIN_LEN 252
#define MAVLINK_MSG_ID_213_LEN 252
#define MAVLINK_MSG_ID_213_MIN_LEN 252

#define MAVLINK_MSG_ID_RTX_UAV2GCS_CRC 62
#define MAVLINK_MSG_ID_213_CRC 62

#define MAVLINK_MSG_RTX_UAV2GCS_FIELD_DATA_LEN 250

#if MAVLINK_COMMAND_24BIT
#define MAVLINK_MESSAGE_INFO_RTX_UAV2GCS { \
    213, \
    "RTX_UAV2GCS", \
    3, \
    {  { "dev", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_rtx_uav2gcs_t, dev) }, \
         { "len", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_rtx_uav2gcs_t, len) }, \
         { "data", NULL, MAVLINK_TYPE_UINT8_T, 250, 2, offsetof(mavlink_rtx_uav2gcs_t, data) }, \
         } \
}
#else
#define MAVLINK_MESSAGE_INFO_RTX_UAV2GCS { \
    "RTX_UAV2GCS", \
    3, \
    {  { "dev", NULL, MAVLINK_TYPE_UINT8_T, 0, 0, offsetof(mavlink_rtx_uav2gcs_t, dev) }, \
         { "len", NULL, MAVLINK_TYPE_UINT8_T, 0, 1, offsetof(mavlink_rtx_uav2gcs_t, len) }, \
         { "data", NULL, MAVLINK_TYPE_UINT8_T, 250, 2, offsetof(mavlink_rtx_uav2gcs_t, data) }, \
         } \
}
#endif

/**
 * @brief Pack a rtx_uav2gcs message
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 *
 * @param dev  which port send this pkg,see RSRTX_OPT_DEV_ENUM
 * @param len  pkg lenght , 250 max
 * @param data  data payload
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_rtx_uav2gcs_pack(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg,
                               uint8_t dev, uint8_t len, const uint8_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RTX_UAV2GCS_LEN];
    _mav_put_uint8_t(buf, 0, dev);
    _mav_put_uint8_t(buf, 1, len);
    _mav_put_uint8_t_array(buf, 2, data, 250);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RTX_UAV2GCS_LEN);
#else
    mavlink_rtx_uav2gcs_t packet;
    packet.dev = dev;
    packet.len = len;
    mav_array_memcpy(packet.data, data, sizeof(uint8_t)*250);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RTX_UAV2GCS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_RTX_UAV2GCS;
    return mavlink_finalize_message(msg, system_id, component_id, MAVLINK_MSG_ID_RTX_UAV2GCS_MIN_LEN, MAVLINK_MSG_ID_RTX_UAV2GCS_LEN, MAVLINK_MSG_ID_RTX_UAV2GCS_CRC);
}

/**
 * @brief Pack a rtx_uav2gcs message on a channel
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param dev  which port send this pkg,see RSRTX_OPT_DEV_ENUM
 * @param len  pkg lenght , 250 max
 * @param data  data payload
 * @return length of the message in bytes (excluding serial stream start sign)
 */
static inline uint16_t mavlink_msg_rtx_uav2gcs_pack_chan(uint8_t system_id, uint8_t component_id, uint8_t chan,
                               mavlink_message_t* msg,
                                   uint8_t dev,uint8_t len,const uint8_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RTX_UAV2GCS_LEN];
    _mav_put_uint8_t(buf, 0, dev);
    _mav_put_uint8_t(buf, 1, len);
    _mav_put_uint8_t_array(buf, 2, data, 250);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), buf, MAVLINK_MSG_ID_RTX_UAV2GCS_LEN);
#else
    mavlink_rtx_uav2gcs_t packet;
    packet.dev = dev;
    packet.len = len;
    mav_array_memcpy(packet.data, data, sizeof(uint8_t)*250);
        memcpy(_MAV_PAYLOAD_NON_CONST(msg), &packet, MAVLINK_MSG_ID_RTX_UAV2GCS_LEN);
#endif

    msg->msgid = MAVLINK_MSG_ID_RTX_UAV2GCS;
    return mavlink_finalize_message_chan(msg, system_id, component_id, chan, MAVLINK_MSG_ID_RTX_UAV2GCS_MIN_LEN, MAVLINK_MSG_ID_RTX_UAV2GCS_LEN, MAVLINK_MSG_ID_RTX_UAV2GCS_CRC);
}

/**
 * @brief Encode a rtx_uav2gcs struct
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param msg The MAVLink message to compress the data into
 * @param rtx_uav2gcs C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_rtx_uav2gcs_encode(uint8_t system_id, uint8_t component_id, mavlink_message_t* msg, const mavlink_rtx_uav2gcs_t* rtx_uav2gcs)
{
    return mavlink_msg_rtx_uav2gcs_pack(system_id, component_id, msg, rtx_uav2gcs->dev, rtx_uav2gcs->len, rtx_uav2gcs->data);
}

/**
 * @brief Encode a rtx_uav2gcs struct on a channel
 *
 * @param system_id ID of this system
 * @param component_id ID of this component (e.g. 200 for IMU)
 * @param chan The MAVLink channel this message will be sent over
 * @param msg The MAVLink message to compress the data into
 * @param rtx_uav2gcs C-struct to read the message contents from
 */
static inline uint16_t mavlink_msg_rtx_uav2gcs_encode_chan(uint8_t system_id, uint8_t component_id, uint8_t chan, mavlink_message_t* msg, const mavlink_rtx_uav2gcs_t* rtx_uav2gcs)
{
    return mavlink_msg_rtx_uav2gcs_pack_chan(system_id, component_id, chan, msg, rtx_uav2gcs->dev, rtx_uav2gcs->len, rtx_uav2gcs->data);
}

/**
 * @brief Send a rtx_uav2gcs message
 * @param chan MAVLink channel to send the message
 *
 * @param dev  which port send this pkg,see RSRTX_OPT_DEV_ENUM
 * @param len  pkg lenght , 250 max
 * @param data  data payload
 */
#ifdef MAVLINK_USE_CONVENIENCE_FUNCTIONS

static inline void mavlink_msg_rtx_uav2gcs_send(mavlink_channel_t chan, uint8_t dev, uint8_t len, const uint8_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char buf[MAVLINK_MSG_ID_RTX_UAV2GCS_LEN];
    _mav_put_uint8_t(buf, 0, dev);
    _mav_put_uint8_t(buf, 1, len);
    _mav_put_uint8_t_array(buf, 2, data, 250);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RTX_UAV2GCS, buf, MAVLINK_MSG_ID_RTX_UAV2GCS_MIN_LEN, MAVLINK_MSG_ID_RTX_UAV2GCS_LEN, MAVLINK_MSG_ID_RTX_UAV2GCS_CRC);
#else
    mavlink_rtx_uav2gcs_t packet;
    packet.dev = dev;
    packet.len = len;
    mav_array_memcpy(packet.data, data, sizeof(uint8_t)*250);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RTX_UAV2GCS, (const char *)&packet, MAVLINK_MSG_ID_RTX_UAV2GCS_MIN_LEN, MAVLINK_MSG_ID_RTX_UAV2GCS_LEN, MAVLINK_MSG_ID_RTX_UAV2GCS_CRC);
#endif
}

/**
 * @brief Send a rtx_uav2gcs message
 * @param chan MAVLink channel to send the message
 * @param struct The MAVLink struct to serialize
 */
static inline void mavlink_msg_rtx_uav2gcs_send_struct(mavlink_channel_t chan, const mavlink_rtx_uav2gcs_t* rtx_uav2gcs)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    mavlink_msg_rtx_uav2gcs_send(chan, rtx_uav2gcs->dev, rtx_uav2gcs->len, rtx_uav2gcs->data);
#else
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RTX_UAV2GCS, (const char *)rtx_uav2gcs, MAVLINK_MSG_ID_RTX_UAV2GCS_MIN_LEN, MAVLINK_MSG_ID_RTX_UAV2GCS_LEN, MAVLINK_MSG_ID_RTX_UAV2GCS_CRC);
#endif
}

#if MAVLINK_MSG_ID_RTX_UAV2GCS_LEN <= MAVLINK_MAX_PAYLOAD_LEN
/*
  This varient of _send() can be used to save stack space by re-using
  memory from the receive buffer.  The caller provides a
  mavlink_message_t which is the size of a full mavlink message. This
  is usually the receive buffer for the channel, and allows a reply to an
  incoming message with minimum stack space usage.
 */
static inline void mavlink_msg_rtx_uav2gcs_send_buf(mavlink_message_t *msgbuf, mavlink_channel_t chan,  uint8_t dev, uint8_t len, const uint8_t *data)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    char *buf = (char *)msgbuf;
    _mav_put_uint8_t(buf, 0, dev);
    _mav_put_uint8_t(buf, 1, len);
    _mav_put_uint8_t_array(buf, 2, data, 250);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RTX_UAV2GCS, buf, MAVLINK_MSG_ID_RTX_UAV2GCS_MIN_LEN, MAVLINK_MSG_ID_RTX_UAV2GCS_LEN, MAVLINK_MSG_ID_RTX_UAV2GCS_CRC);
#else
    mavlink_rtx_uav2gcs_t *packet = (mavlink_rtx_uav2gcs_t *)msgbuf;
    packet->dev = dev;
    packet->len = len;
    mav_array_memcpy(packet->data, data, sizeof(uint8_t)*250);
    _mav_finalize_message_chan_send(chan, MAVLINK_MSG_ID_RTX_UAV2GCS, (const char *)packet, MAVLINK_MSG_ID_RTX_UAV2GCS_MIN_LEN, MAVLINK_MSG_ID_RTX_UAV2GCS_LEN, MAVLINK_MSG_ID_RTX_UAV2GCS_CRC);
#endif
}
#endif

#endif

// MESSAGE RTX_UAV2GCS UNPACKING


/**
 * @brief Get field dev from rtx_uav2gcs message
 *
 * @return  which port send this pkg,see RSRTX_OPT_DEV_ENUM
 */
static inline uint8_t mavlink_msg_rtx_uav2gcs_get_dev(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  0);
}

/**
 * @brief Get field len from rtx_uav2gcs message
 *
 * @return  pkg lenght , 250 max
 */
static inline uint8_t mavlink_msg_rtx_uav2gcs_get_len(const mavlink_message_t* msg)
{
    return _MAV_RETURN_uint8_t(msg,  1);
}

/**
 * @brief Get field data from rtx_uav2gcs message
 *
 * @return  data payload
 */
static inline uint16_t mavlink_msg_rtx_uav2gcs_get_data(const mavlink_message_t* msg, uint8_t *data)
{
    return _MAV_RETURN_uint8_t_array(msg, data, 250,  2);
}

/**
 * @brief Decode a rtx_uav2gcs message into a struct
 *
 * @param msg The message to decode
 * @param rtx_uav2gcs C-struct to decode the message contents into
 */
static inline void mavlink_msg_rtx_uav2gcs_decode(const mavlink_message_t* msg, mavlink_rtx_uav2gcs_t* rtx_uav2gcs)
{
#if MAVLINK_NEED_BYTE_SWAP || !MAVLINK_ALIGNED_FIELDS
    rtx_uav2gcs->dev = mavlink_msg_rtx_uav2gcs_get_dev(msg);
    rtx_uav2gcs->len = mavlink_msg_rtx_uav2gcs_get_len(msg);
    mavlink_msg_rtx_uav2gcs_get_data(msg, rtx_uav2gcs->data);
#else
        uint8_t len = msg->len < MAVLINK_MSG_ID_RTX_UAV2GCS_LEN? msg->len : MAVLINK_MSG_ID_RTX_UAV2GCS_LEN;
        memset(rtx_uav2gcs, 0, MAVLINK_MSG_ID_RTX_UAV2GCS_LEN);
    memcpy(rtx_uav2gcs, _MAV_PAYLOAD(msg), len);
#endif
}
