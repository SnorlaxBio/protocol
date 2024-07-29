/**
 * @file        snorlax/protocol/ethernet.h
 * @brief
 * @details
 * 
 * @author      snorlax <ceo@snorlax.bio>
 * @since       July 4, 2024
 */

#ifndef   __SNORLAX__PROTOCOL_ETHERNET__H__
#define   __SNORLAX__PROTOCOL_ETHERNET__H__

#include <snorlax.h>

struct protocol_ethernet;

typedef struct protocol_ethernet protocol_ethernet_t;

#define protocol_ethernet_addrlen                               6

#define protocol_ethernet_type_internet_protocol_version4       0x0800u
#define protocol_ethernet_type_address_resolution_protocol      0x0806u
#define protocol_ethernet_type_internet_protocol_version6       0x86DDu
#define protocol_ethernet_type_vlan                             0x8100u
#define protocol_ethernet_type_link_layer_discovery_protocol    0x88CCu

struct protocol_ethernet {
    uint8_t  destination[protocol_ethernet_addrlen];
    uint8_t  source[protocol_ethernet_addrlen];
    uint16_t type;
};

#define protocol_ethernet_header_get(frame)         ((protocol_ethernet_t *) frame)
#define protocol_ethernet_datagram_get(frame)       (&((uint8_t *) frame)[sizeof(protocol_ethernet_t)])

#ifndef   RELEASE
extern void ethernet_protocol_debug(FILE * stream, const uint8_t * frame);
#endif // RELEASE

#endif // __SNORLAX__PROTOCOL_ETHERNET__H__
