#include <arpa/inet.h>

#include "ethernet.h"

#include "internet.h"
#include "address-resolution.h"

#ifndef   RELEASE
extern void ethernet_protocol_debug(FILE * stream, const uint8_t * frame) {
    protocol_ethernet_t * header = protocol_ethernet_header_get(frame);

    fprintf(stream, "| Ethernet Protocol ");
    fprintf(stream, "| %02x:%02x:%02x:%02x:%02x:%02x ", header->source[0],
                                                        header->source[1],
                                                        header->source[2],
                                                        header->source[3],
                                                        header->source[4],
                                                        header->source[5]);
    fprintf(stream, "| %02x:%02x:%02x:%02x:%02x:%02x ", header->destination[0],
                                                        header->destination[1],
                                                        header->destination[2],
                                                        header->destination[3],
                                                        header->destination[4],
                                                        header->destination[5]);

    uint16_t type = ntohs(header->type);

    fprintf(stream, "| %04x ", type);
    fprintf(stream, "|\n");

    const uint8_t * datagram = protocol_ethernet_datagram_get(frame);

    switch(type) {
        case protocol_ethernet_type_internet_protocol_version4:         internet_protocol_debug(stream, datagram);                                                                      break;
        case protocol_ethernet_type_address_resolution_protocol:        address_resolution_protocol_debug(stream, datagram);                                                            break;
        case protocol_ethernet_type_internet_protocol_version6:         internet_protocol_debug(stream, datagram);                                                                      break;
        case protocol_ethernet_type_vlan:                               snorlaxdbg(true, false, "critical", "not implement => protocol_ethernet_type_vlan");                            break;
        case protocol_ethernet_type_link_layer_discovery_protocol:      snorlaxdbg(true, false, "critical", "not implement => protocol_ethernet_type_link_layer_discovery_protocol");   break;
        default:                                                        snorlaxdbg(true, false, "critical", "not implement => %d", type);                                               break;
    }
}
#endif // RELEASE
