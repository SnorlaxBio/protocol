/**
 * @file        snorlax/protocol/internet/version4.h
 * @brief
 * @details
 * 
 * @author      snorlax <ceo@snorlax.bio>
 * @since       July 5, 2024
 */

#ifndef   __SNORLAX__PROTOCOL_INTERNET_VERSION4__H__
#define   __SNORLAX__PROTOCOL_INTERNET_VERSION4__H__

#include <snorlax.h>

struct internet_protocol_version4;
struct internet_protocol_version4_pseudo;

typedef struct internet_protocol_version4           internet_protocol_version4_t;
typedef struct internet_protocol_version4_pseudo    internet_protocol_version4_pseudo_t;
typedef uint8_t *                                   internet_protocol_version4_option_t;

struct internet_protocol_version4 {
#if       __BYTE_ORDER == __LITTLE_ENDIAN
    uint8_t length:4;
    uint8_t version:4;
#else  // __BYTE_ORDER == __LITTLE_ENDIAN
    uint8_t version:4;
    uint8_t length:4;
#endif // __BYTE_ORDER == __LITTLE_ENDIAN
    uint8_t  service;
    uint16_t total;
    uint16_t identification;
    uint16_t fragment;
    uint8_t  ttl;
    uint8_t  protocol;
    uint16_t checksum;
    uint32_t source;
    uint32_t destination;
};

struct internet_protocol_version4_pseudo {
    uint32_t source;
    uint32_t destination;
    uint8_t  zero;
    uint8_t  protocol;
    uint16_t length;
};

#define internet_protocol_version4_header_length_get(datagram)      (((internet_protocol_version4_t *) datagram)->length * 4)
#define internet_protocol_version4_segment_get(datagram)            (&((uint8_t *) datagram)[internet_protocol_version4_header_length_get(datagram)])

#define internet_protocol_version4_length_get(datagram)             (0)

#ifndef   RELEASE
extern void internet_protocol_version4_debug(FILE * stream, const uint8_t * datagram);
#endif // RELEASE

#endif // __SNORLAX__PROTOCOL_INTERNET_VERSION4__H__
