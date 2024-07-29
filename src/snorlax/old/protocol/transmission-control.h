/**
 * @file        snorlax/protocol/transmission-control.h
 * @brief
 * @details
 * 
 * @author      snorlax <ceo@snorlax.bio>
 * @since       July 5, 2024
 */

#ifndef   __SNORLAX__PROTOCOL_TRANSMISSION_CONTROL__H__
#define   __SNORLAX__PROTOCOL_TRANSMISSION_CONTROL__H__

#include <snorlax.h>
#include <snorlax/protocol/internet.h>

struct transmission_control_protocol;

typedef struct transmission_control_protocol transmission_control_protocol_t;

struct transmission_control_protocol {
    uint16_t source;
    uint16_t destination;
    uint32_t sequence;
    uint32_t acknowledgment;
#if       __BYTE_ORDER == __LITTLE_ENDIAN
    uint8_t reserved:4;
    uint8_t  offset:4;
#else  // __BYTE_ORDER == __LITTLE_ENDIAN
    uint8_t  offset:4;
    uint8_t reserved:4;
#endif // __BYTE_ORDER == __LITTLE_ENDIAN
    uint8_t controls;
    uint16_t window;
    uint16_t checksum;
    uint16_t urgent;
};

#ifndef   RELEASE
extern void transmission_control_protocol_debug(FILE * stream, const internet_protocol_t * internet, const uint8_t * segment);
#endif // RELEASE

#endif // __SNORLAX__PROTOCOL_TRANSMISSION_CONTROL__H__
