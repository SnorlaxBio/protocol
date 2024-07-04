/**
 * @file        snorlax/protocol/user-datagram.h
 * @brief
 * @details
 * 
 * @author      snorlax <ceo@snorlax.bio>
 * @since       July 5, 2024
 */

#ifndef   __SNORLAX__PROTOCOL_USER_DATAGRAM__H__
#define   __SNORLAX__PROTOCOL_USER_DATAGRAM__H__

#include <snorlax.h>
#include <snorlax/protocol/internet.h>

struct user_datagram_protocol;

typedef struct user_datagram_protocol user_datagram_protocol_t;

struct user_datagram_protocol {
    uint16_t source;
    uint16_t destination;
    uint16_t length;
    uint16_t checksum;
};

#define user_datagram_protocol_message_get(segment)         (&((uint8_t *) segment)[sizeof(user_datagram_protocol_t)])

#ifndef   RELEASE
extern void user_datagram_protocol_debug(FILE * stream, const internet_protocol_t * internet, const uint8_t * segment);
#endif // RELEASE

#endif // __SNORLAX__PROTOCOL_USER_DATAGRAM__H__
