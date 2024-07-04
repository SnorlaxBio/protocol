#include <arpa/inet.h>

#include "transmission-control.h"

#ifndef   RELEASE
extern void snorlax_protocol_transmission_control_debug(FILE * stream, const internet_protocol_t * internet, const uint8_t * segment) {
    
    transmission_control_protocol_t * header = (transmission_control_protocol_t *) segment;
    fprintf(stream, "| transmission control ");
    fprintf(stream, "| % 6d ", ntohs(header->source));
    fprintf(stream, "| % 6d ", ntohs(header->destination));
    fprintf(stream, "| % 12d ", ntohl(header->sequence));
    fprintf(stream, "| % 12d ", ntohl(header->destination));
    fprintf(stream, "| % 3d ", header->offset);
    fprintf(stream, "| %02x ", header->controls);
    fprintf(stream, "| % 6d ", ntohs(header->window));
    fprintf(stream, "| % 6d ", ntohs(header->checksum));
    fprintf(stream, "| % 6d ", ntohs(header->urgent));

    snorlaxdbg(false, true, "check", "implement tcp option & well known application protocol");

    fprintf(stream, "|\n");
}
#endif // RELEASE
