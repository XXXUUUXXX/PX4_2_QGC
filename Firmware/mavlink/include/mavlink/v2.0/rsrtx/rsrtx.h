/** @file
 *  @brief MAVLink comm protocol generated from rsrtx.xml
 *  @see http://mavlink.org
 */
#pragma once
#ifndef MAVLINK_RSRTX_H
#define MAVLINK_RSRTX_H

#ifndef MAVLINK_H
    #error Wrong include order: MAVLINK_RSRTX.H MUST NOT BE DIRECTLY USED. Include mavlink.h from the same directory instead or set ALL AND EVERY defines from MAVLINK.H manually accordingly, including the #define MAVLINK_H call.
#endif

#undef MAVLINK_THIS_XML_IDX
#define MAVLINK_THIS_XML_IDX 0

#ifdef __cplusplus
extern "C" {
#endif

// MESSAGE LENGTHS AND CRCS

#ifndef MAVLINK_MESSAGE_LENGTHS
#define MAVLINK_MESSAGE_LENGTHS {}
#endif

#ifndef MAVLINK_MESSAGE_CRCS
#define MAVLINK_MESSAGE_CRCS {{211, 35, 252, 252, 0, 0, 0}, {213, 62, 252, 252, 0, 0, 0}}
#endif

#include "../protocol.h"

#define MAVLINK_ENABLED_RSRTX

// ENUM DEFINITIONS


/** @brief which port send to or receive */
#ifndef HAVE_ENUM_RSRTX_OPT_DEV_ENUM
#define HAVE_ENUM_RSRTX_OPT_DEV_ENUM
typedef enum RSRTX_OPT_DEV_ENUM
{
   DEV_TTYS0=0, /* /dev/ttyS0 | */
   DEV_TTYS1=1, /* /dev/ttyS1 | */
   DEV_TTYS2=2, /* /dev/ttyS2 | */
   DEV_TTYS3=3, /* /dev/ttyS3 | */
   DEV_TTYS4=4, /* /dev/ttyS4 | */
   DEV_TTYS5=5, /* /dev/ttyS5 | */
   DEV_TTYS6=6, /* /dev/ttyS6 | */
   RSRTX_OPT_DEV_ENUM_ENUM_END=7, /*  | */
} RSRTX_OPT_DEV_ENUM;
#endif

// MAVLINK VERSION

#ifndef MAVLINK_VERSION
#define MAVLINK_VERSION 2
#endif

#if (MAVLINK_VERSION == 0)
#undef MAVLINK_VERSION
#define MAVLINK_VERSION 2
#endif

// MESSAGE DEFINITIONS
#include "./mavlink_msg_rtx_gcs2uav.h"
#include "./mavlink_msg_rtx_uav2gcs.h"

// base include


#undef MAVLINK_THIS_XML_IDX
#define MAVLINK_THIS_XML_IDX 0
/*
#if MAVLINK_THIS_XML_IDX == MAVLINK_PRIMARY_XML_IDX
# define MAVLINK_MESSAGE_INFO {MAVLINK_MESSAGE_INFO_RTX_GCS2UAV, MAVLINK_MESSAGE_INFO_RTX_UAV2GCS}
# define MAVLINK_MESSAGE_NAMES {{ "RTX_GCS2UAV", 211 }, { "RTX_UAV2GCS", 213 }}
# if MAVLINK_COMMAND_24BIT
#  include "../mavlink_get_info.h"
# endif
#endif
*/
#ifdef __cplusplus
}
#endif // __cplusplus
#endif // MAVLINK_RSRTX_H
