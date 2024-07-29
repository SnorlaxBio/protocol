/**
 * @file        snorlax/protocol.h
 * @brief
 * @details
 * 
 * @author      snorlax <ceo@snorlax.bio>
 * @since       July 4, 2024
 */

#ifndef   __SNORLAX__PROTOCOL__H__
#define   __SNORLAX__PROTOCOL__H__

#include <snorlax.h>

typedef uint8_t * protocol_t;

extern void protocol_debug(FILE * stream, const protocol_t * packet);

// struct protocol;
// typedef struct protocol protocol_t;
// struct protocol {
// };

#include <snorlax/protocol/user-datagram.h>
#include <snorlax/protocol/transmission-control.h>
#include <snorlax/protocol/internet.h>
#include <snorlax/protocol/ethernet.h>
#include <snorlax/protocol/address-resolution.h>
#include <snorlax/protocol/internet/version4.h>
#include <snorlax/protocol/internet/version6.h>
#include <snorlax/protocol/internet/control-message.h>

#endif // __SNORLAX__PROTOCOL__H__
