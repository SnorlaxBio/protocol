/**
 * @file        snorlax/protocol/internet/version6.h
 * @brief
 * @details
 * 
 * @author      snorlax <ceo@snorlax.bio>
 * @since       July 5, 2024
 */

#ifndef   __SNORLAX__PROTOCOL_INTERNET_VERSION6__H__
#define   __SNORLAX__PROTOCOL_INTERNET_VERSION6__H__

#include <snorlax.h>

struct internet_protocol_version6;

typedef struct internet_protocol_version6 internet_protocol_version6_t;

struct internet_protocol_version6 {
    uint32_t  prefix;
    uint16_t length;
    uint8_t  next;
    uint8_t  limit;
    uint16_t source[8];
    uint16_t destination[8];
};

#define internet_protocol_version6_traffic_class_get(prefix)        (((prefix) & 0x0FF00000u) >> 20u)
#define internet_protocol_version6_flow_label_get(prefix)           ((prefix) & 0x000FFFFFu)
#define internet_protocol_version6_length_get(datagram)             ntohs((internet_protocol_version6_t *)(datagram)->length)

#ifndef   RELEASE
extern void internet_protocol_version6_debug(FILE * stream, const uint8_t * datagram);
#endif // RELEASE

#endif // __SNORLAX__PROTOCOL_INTERNET_VERSION6__H__
