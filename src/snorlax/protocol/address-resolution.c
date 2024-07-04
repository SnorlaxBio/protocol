#include <arpa/inet.h>

#include "address-resolution.h"

#include "ethernet.h"

#ifndef   RELEASE
extern void address_resolution_protocol_debug(FILE * stream, const uint8_t * datagram) {
    address_resolution_protocol_t * protocol = (address_resolution_protocol_t *) datagram;

    uint16_t hardware = ntohs(protocol->hardware);
    uint16_t type = ntohs(protocol->protocol);

    fprintf(stream, "| Address Resolution ");
    fprintf(stream, "| % 6d ", hardware);
    fprintf(stream, "| %04d ", type);
    fprintf(stream, "| % 3d ", protocol->length.hardware);
    fprintf(stream, "| % 3d ", protocol->length.protocol);
    fprintf(stream, "| % 6d ", protocol->op);

    uint32_t offset = sizeof(address_resolution_protocol_t);

    if(hardware == protocol_address_resolution_hardware_type) {
        fprintf(stream, "| ");
        for(int i = 0; i < protocol->length.hardware; i++, offset++) {
            fprintf(stream, "%02x%c", datagram[offset], i + 1 == protocol->length.hardware ? ' ' : ':');
        }
    } else {
        snorlaxdbg(true, false, "critical", "not implemented => %d", hardware);
    }

    if(type == protocol_ethernet_type_internet_protocol_version4) {
        fprintf(stream, "| %15s ", inet_ntoa((struct in_addr) { .s_addr = uint32of(datagram, offset) }));
        offset = offset + protocol->length.protocol;
    } else {
        snorlaxdbg(true, false, "critical", "not implemented => %d", type);
    }

    if(hardware == protocol_address_resolution_hardware_type) {
        fprintf(stream, "| ");
        for(int i = 0; i < protocol->length.hardware; i++, offset++) {
            fprintf(stream, "%02x%c", datagram[offset], i + 1 == protocol->length.hardware ? ' ' : ':');
        }
    } else {
        snorlaxdbg(true, false, "critical", "not implemented => %d", hardware);
    }

    if(type == protocol_ethernet_type_internet_protocol_version4) {
        fprintf(stream, "| %15s ", inet_ntoa((struct in_addr) { .s_addr = uint32of(datagram, offset) }));
        offset = offset + protocol->length.protocol;
    } else {
        snorlaxdbg(true, false, "critical", "not implemented => %d", type);
    }

    fprintf(stream, "|\n");
}

#endif // RELEASE