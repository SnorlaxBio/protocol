/**
 * @file        snorlax/protocol/address-resolution.h
 * @brief
 * @details
 * 
 * @author      snorlax <ceo@snorlax.bio>
 * @since       July 4, 2024
 * 
 * @see         [Ethernet Address Resolution Protocol](https://datatracker.ietf.org/doc/html/rfc826)
 * @see         [Address Resolution Protocol (ARP) Parameters](https://www.iana.org/assignments/arp-parameters/arp-parameters.xhtml)
 */

#ifndef   __SNORLAX__PROTOCOL_ADDRESS_RESOLUTION__H__
#define   __SNORLAX__PROTOCOL_ADDRESS_RESOLUTION__H__

#include <snorlax.h>

#define protocol_address_resolution_hardware_type           1

struct address_resolution_protocol;

typedef struct address_resolution_protocol address_resolution_protocol_t;

struct address_resolution_protocol {
    uint16_t hardware;
    uint16_t protocol;
    struct {
        uint8_t hardware;
        uint8_t protocol;
    } length;
    uint16_t op;
};

#ifndef   RELEASE
extern void address_resolution_protocol_debug(FILE * stream, const uint8_t * datagram);
#endif // RELEASE

#endif // __SNORLAX__PROTOCOL_ADDRESS_RESOLUTION__H__
