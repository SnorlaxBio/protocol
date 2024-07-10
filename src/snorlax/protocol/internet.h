/**
 * @file        snorlax/protocol/internet.h
 * @brief
 * @details
 * 
 * @author      snorlax <ceo@snorlax.bio>
 * @since       July 4, 2024
 */

#ifndef   __SNORLAX__PROTOCOL_INTERNET__H__
#define   __SNORLAX__PROTOCOL_INTERNET__H__

#include <snorlax.h>

#define internet_protocol_type_icmp         1

#define internet_protocol_type_tcp          6

#define internet_protocol_type_udp          17

typedef uint8_t                 internet_protocol_t;

#if       __BYTE_ORDER == __LITTLE_ENDIAN
#define internet_protocol_version_get(datagram)         (datagram[0] >> 4)
#else
#define internet_protocol_version_get(datagram)         (datagram[0] & (0x0Fu))
#endif // __BYTE_ORDER == __LITTLE_ENDIAN

extern uint32_t internet_protocol_length_get(internet_protocol_t * datagram);

// #define internet_protocol_length_get(datagram)          

#ifndef   RELEASE
extern void internet_protocol_debug(FILE * stream, const uint8_t * datagram);
#endif // RELEASE

#endif // __SNORLAX__PROTOCOL_INTERNET__H__
