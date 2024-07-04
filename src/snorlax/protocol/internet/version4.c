#include <arpa/inet.h>

#include "version4.h"
#include "control-message.h"

#include "../internet.h"
#include "../transmission-control.h"
#include "../user-datagram.h"

#ifndef   RELEASE
extern void internet_protocol_version4_debug(FILE * stream, const uint8_t * datagram) {
    internet_protocol_version4_t * header = (internet_protocol_version4_t *) datagram;
    fprintf(stream, "| internet ");
    fprintf(stream, "| %d ", header->version);
    fprintf(stream, "| %d ", header->length);
    fprintf(stream, "| %02x ", header->service);
    fprintf(stream, "| % 6d ", ntohs(header->total));
    fprintf(stream, "| %04x ", ntohs(header->identification));
    fprintf(stream, "| %04x ", ntohs(header->fragment));
    fprintf(stream, "| % 4d ", header->ttl);
    fprintf(stream, "| % 4d ", header->protocol);
    fprintf(stream, "| % 6d ", ntohs(header->checksum));
    fprintf(stream, "| %15s ", inet_ntoa((struct in_addr) { .s_addr = header->source }));
    fprintf(stream, "| %15s ", inet_ntoa((struct in_addr) { .s_addr = header->destination }));
    fprintf(stream, "|\n");

    const uint8_t * segment = internet_protocol_version4_segment_get(datagram);

    switch(header->protocol) {
        case internet_protocol_type_icmp:   internet_control_message_protocol_debug(stream, (internet_protocol_t *) datagram, segment);     break;
        case internet_protocol_type_tcp:    transmission_control_protocol_debug(stream, (internet_protocol_t *) datagram, segment);         break;
        case internet_protocol_type_udp:    user_datagram_protocol_debug(stream, (internet_protocol_t *) datagram, segment);                break;
        default:                            snorlaxdbg(true, false, "critical", "not implemented => %d", header->protocol);                 break;
    }
}
#endif // RELEASE
