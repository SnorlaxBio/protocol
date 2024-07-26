#include <string.h>
#include <stdlib.h>

#include "gateway.h"

extern void exterior_gateway_protocol_message_debug(FILE * stream, const uint8_t * datagram) {
    const exterior_gateway_protocol_message_t * message = (exterior_gateway_protocol_message_t *) datagram;

    switch(message->type) {
        case exterior_gateway_protocol_message_type_neighbor_acquisition:   exterior_gateway_protocol_message_neighbor_acquisition_debug(stream, message);      break;
        case exterior_gateway_protocol_message_type_neighbor_reachability:  exterior_gateway_protocol_message_neighbor_reachability_debug(stream, message);     break;
        case exterior_gateway_protocol_message_type_poll_command:           exterior_gateway_protocol_message_poll_command_debug(stream, message);              break;
        case exterior_gateway_protocol_message_type_update:                 exterior_gateway_protocol_message_update_debug(stream, message);                    break;
        case exterior_gateway_protocol_message_type_error:                  exterior_gateway_protocol_message_error_debug(stream, message);                     break;
        default:                                                            snorlaxdbg(true, false, "critical", "invalid protocol");                            break;
    }
}

extern uint16_t exterior_gateway_protocol_message_checksum_cal(uint16_t * array, int arraylen) {
    uint16_t checksum = array[0];

    for(int i = 1; i < arraylen; i++) {
        checksum = checksum + array[1];
    }
    checksum = (checksum ^ 0xFFFF);

    return checksum;
}

extern exterior_gateway_protocol_message_neighbor_acquisition_t * exterior_gateway_protocol_message_neighbor_acquisition_gen(exterior_gateway_protocol_message_neighbor_acquisition_t * message, uint8_t code, uint8_t status, uint16_t autonomous, uint16_t sequence, uint16_t hello, uint16_t poll) {
    message = message ? message : (exterior_gateway_protocol_message_neighbor_acquisition_t *) calloc(1, sizeof(exterior_gateway_protocol_message_neighbor_acquisition_t));

    message->version = exterior_gateway_protocol_version;
    message->type = exterior_gateway_protocol_message_type_neighbor_acquisition;
    message->code = code;
    message->status = status;
    message->autonomous = autonomous;
    message->sequence = sequence;
    message->hello = hello;
    message->poll = poll;
    message->checksum = 0;

    message->checksum = exterior_gateway_protocol_message_checksum_cal((uint16_t *) message, sizeof(exterior_gateway_protocol_message_neighbor_acquisition_t) / 2);

    return message;
}

#ifndef   RELEASE
extern void exterior_gateway_protocol_message_neighbor_acquisition_debug(FILE * stream, const exterior_gateway_protocol_message_t * datagram) {
    snorlaxdbg(datagram == nil, false, "critical", "");

    const exterior_gateway_protocol_message_neighbor_acquisition_t * message = (exterior_gateway_protocol_message_neighbor_acquisition_t *) datagram;

    fprintf(stream, "| exterior gateway protocol ");
    fprintf(stream, "| neighbor acquisition ");
    fprintf(stream, "| % 3d ", message->version);
    fprintf(stream, "| % 3d ", message->type);
    fprintf(stream, "| % 3d ", message->code);
    fprintf(stream, "| % 3d ", message->status);
    fprintf(stream, "| % 6d ", message->checksum);
    fprintf(stream, "| % 6d ", message->autonomous);
    fprintf(stream, "| % 6d ", message->sequence);
    fprintf(stream, "| % 6d ", message->hello);
    fprintf(stream, "| % 6d ", message->poll);
    fprintf(stream, "|\n");
}
#endif // RELEASE

extern exterior_gateway_protocol_message_neighbor_reachability_t * exterior_gateway_protocol_message_neighbor_reachability_gen(exterior_gateway_protocol_message_neighbor_reachability_t * message, uint8_t code, uint8_t status, uint16_t autonomous, uint16_t sequence) {
    message = message ? message : (exterior_gateway_protocol_message_neighbor_reachability_t *) calloc(1, sizeof(exterior_gateway_protocol_message_neighbor_reachability_t));

    message->version = exterior_gateway_protocol_version;
    message->type = exterior_gateway_protocol_message_type_neighbor_reachability;
    message->code = code;
    message->status = status;
    message->autonomous = autonomous;
    message->sequence = sequence;
    message->checksum = 0;

    message->checksum = exterior_gateway_protocol_message_checksum_cal((uint16_t *) message, sizeof(exterior_gateway_protocol_message_neighbor_reachability_t) / 2);

    return message;
}

#ifndef   RELEASE
extern void exterior_gateway_protocol_message_neighbor_reachability_debug(FILE * stream, const exterior_gateway_protocol_message_t * datagram) {
    snorlaxdbg(datagram == nil, false, "critical", "");

    const exterior_gateway_protocol_message_neighbor_reachability_t * message = (exterior_gateway_protocol_message_neighbor_reachability_t *) datagram;

    fprintf(stream, "| exterior gateway protocol ");
    fprintf(stream, "| neighbor reachability ");
    fprintf(stream, "| % 3d ", message->version);
    fprintf(stream, "| % 3d ", message->type);
    fprintf(stream, "| % 3d ", message->code);
    fprintf(stream, "| % 3d ", message->status);
    fprintf(stream, "| % 6d ", message->checksum);
    fprintf(stream, "| % 6d ", message->autonomous);
    fprintf(stream, "| % 6d ", message->sequence);
    fprintf(stream, "|\n");
}
#endif // RELEASE

extern exterior_gateway_protocol_message_poll_command_t * exterior_gateway_protocol_message_poll_command_gen(exterior_gateway_protocol_message_poll_command_t * message, uint8_t status, uint16_t autonomous, uint16_t sequence, uint32_t source) {
    message = message ? message : (exterior_gateway_protocol_message_poll_command_t *) calloc(1, sizeof(exterior_gateway_protocol_message_poll_command_t));

    message->version = exterior_gateway_protocol_version;
    message->type = exterior_gateway_protocol_message_type_poll_command;
    message->code = exterior_gateway_protocol_message_code_poll_command;
    message->status = status;
    message->autonomous = autonomous;
    message->sequence = sequence;
    message->reserved = 0;
    message->source = source;
    message->checksum = 0;

    message->checksum = exterior_gateway_protocol_message_checksum_cal((uint16_t *) message, sizeof(exterior_gateway_protocol_message_poll_command_t) / 2);

    return message;
}

#ifndef   RELEASE
extern void exterior_gateway_protocol_message_poll_command_debug(FILE * stream, const exterior_gateway_protocol_message_t * datagram) {
    snorlaxdbg(datagram == nil, false, "critical", "");

    const exterior_gateway_protocol_message_poll_command_t * message = (exterior_gateway_protocol_message_poll_command_t *) datagram;

    fprintf(stream, "| exterior gateway protocol ");
    fprintf(stream, "| poll command ");
    fprintf(stream, "| % 3d ", message->version);
    fprintf(stream, "| % 3d ", message->type);
    fprintf(stream, "| % 3d ", message->code);
    fprintf(stream, "| % 3d ", message->status);
    fprintf(stream, "| % 6d ", message->checksum);
    fprintf(stream, "| % 6d ", message->autonomous);
    fprintf(stream, "| % 6d ", message->sequence);
    fprintf(stream, "| %08x ", message->source);
    fprintf(stream, "|\n");
}
#endif // RELEASE

extern exterior_gateway_protocol_message_update_t * exterior_gateway_protocol_message_update_gen(exterior_gateway_protocol_message_update_t * message, uint8_t status, uint16_t autonomous, uint16_t sequence, uint8_t interior, uint8_t exterior, uint32_t source) {
    message = message ? message : (exterior_gateway_protocol_message_update_t *) calloc(1, sizeof(exterior_gateway_protocol_message_update_t));

    message->version = exterior_gateway_protocol_version;
    message->type = exterior_gateway_protocol_message_type_update;
    message->code = exterior_gateway_protocol_message_code_update;
    message->status = status;
    // uint16_t checksum;
    message->autonomous = autonomous;
    message->sequence = sequence;
    message->gateway.interior = interior;
    message->gateway.exterior = exterior;
    message->source = source;

    snorlaxdbg(true, false, "implement", "");

    message->checksum = 0;

    return message;
}

#ifndef   RELEASE
extern void exterior_gateway_protocol_message_update_debug(FILE * stream, const exterior_gateway_protocol_message_t * datagram) {
    snorlaxdbg(datagram == nil, false, "critical", "");

    const exterior_gateway_protocol_message_update_t * message = (exterior_gateway_protocol_message_update_t *) datagram;

    fprintf(stream, "| exterior gateway protocol ");
    fprintf(stream, "| update ");
    fprintf(stream, "| % 3d ", message->version);
    fprintf(stream, "| % 3d ", message->type);
    fprintf(stream, "| % 3d ", message->code);
    fprintf(stream, "| % 3d ", message->status);
    fprintf(stream, "| % 6d ", message->checksum);
    fprintf(stream, "| % 6d ", message->autonomous);
    fprintf(stream, "| % 6d ", message->sequence);
    fprintf(stream, "| % 3d ", message->gateway.interior);
    fprintf(stream, "| % 3d ", message->gateway.exterior);
    fprintf(stream, "| %08x ", message->source);
    fprintf(stream, "|\n");

    snorlaxdbg(true, false, "implement", "");
}
#endif // RELEASE

extern exterior_gateway_protocol_message_error_t * exterior_gateway_protocol_message_error_gen(exterior_gateway_protocol_message_error_t * message, uint8_t status, uint16_t autonomous, uint16_t sequence, uint16_t reason, exterior_gateway_protocol_message_t * origin, uint32_t originlen) {
    message = message ? message : (exterior_gateway_protocol_message_error_t *) calloc(1, sizeof(exterior_gateway_protocol_message_error_t));

    message->version = exterior_gateway_protocol_version;
    message->type = exterior_gateway_protocol_message_type_error;
    message->code = exterior_gateway_protocol_message_code_error;
    message->status = status;
    message->checksum = 0;
    message->autonomous = autonomous;
    message->sequence = sequence;
    message->reason = reason;

    memcpy(&message->origin, origin, originlen);

    message->checksum = exterior_gateway_protocol_message_checksum_cal((uint16_t *) message, sizeof(exterior_gateway_protocol_message_error_t) / 2);

    return message;
}

#ifndef   RELEASE
extern void exterior_gateway_protocol_message_error_debug(FILE * stream, const exterior_gateway_protocol_message_t * datagram) {
    snorlaxdbg(datagram == nil, false, "critical", "");

    const exterior_gateway_protocol_message_error_t * message = (exterior_gateway_protocol_message_error_t *) datagram;

    fprintf(stream, "| exterior gateway protocol ");
    fprintf(stream, "| error ");
    fprintf(stream, "| % 3d ", message->version);
    fprintf(stream, "| % 3d ", message->type);
    fprintf(stream, "| % 3d ", message->code);
    fprintf(stream, "| % 3d ", message->status);
    fprintf(stream, "| % 6d ", message->checksum);
    fprintf(stream, "| % 6d ", message->autonomous);
    fprintf(stream, "| % 6d ", message->sequence);
    fprintf(stream, "| % 6d ", message->reason);

    fprintf(stream, "| % 3d ", message->origin.version);
    fprintf(stream, "| % 3d ", message->origin.type);
    fprintf(stream, "| % 3d ", message->origin.code);
    fprintf(stream, "| % 3d ", message->origin.status);
    fprintf(stream, "| % 6d ", message->origin.checksum);
    fprintf(stream, "| % 6d ", message->origin.autonomous);
    fprintf(stream, "| % 6d ", message->origin.sequence);

    fprintf(stream, "|\n");
}
#endif // RELEASE
