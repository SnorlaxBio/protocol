/**
 * @file        snorlax/protocol/internet/control-message-version6.h
 * @brief
 * @details
 * 
 * @author      snorlax <ceo@snorlax.bio>
 * @since       July 26, 2024
 */

#ifndef   __SNORLAX__PROTOCOL_INTERNET_CONTROL_MESSAGE_VERSION6__H__
#define   __SNORLAX__PROTOCOL_INTERNET_CONTROL_MESSAGE_VERSION6__H__

#include <snorlax.h>

#define internet_control_message_version6_type_error_destination_unreachable                1
#define internet_control_message_version6_type_error_packet_too_big                         2
#define internet_control_message_version6_type_error_time_exceeded                          3
#define internet_control_message_version6_type_error_parameter_problem                      4
#define internet_control_message_version6_type_error_private_experimentation_100            100
#define internet_control_message_version6_type_error_private_experimentation_101            101
#define internet_control_message_version6_type_error_reserved                               127
#define internet_control_message_version6_type_information_echo_request                     128
#define internet_control_message_version6_type_information_echo_reply                       129
#define internet_control_message_version6_type_information_private_experimentation_200      200
#define internet_control_message_version6_type_information_private_experimentation_201      201
#define internet_control_message_version6_type_information_reserved                         255

struct internet_control_message_version6;

typedef struct internet_control_message_version6 internet_control_message_version6_t;

struct internet_control_message_version6 {
    uint8_t type;
    uint8_t code;
    uint16_t checksum;
};

#define internet_control_message_version6_class_error           0
#define internet_control_message_version6_class_information     1

#define internet_control_message_version6_class_check(type)     ((type & 0x80) >> 7)

#ifndef   RELEASE
extern void internet_control_message_version6_debug(FILE * stream, const uint8_t * datagram);
#endif // RELEASE

#endif // __SNORLAX__PROTOCOL_INTERNET_CONTROL_MESSAGE_VERSION6__H__