#include <arpa/inet.h>

#include "user-datagram.h"

#ifndef   RELEASE
extern void user_datagram_protocol_debug(FILE * stream, const internet_protocol_t * internet, const uint8_t * segment) {
    user_datagram_protocol_t * udp = (user_datagram_protocol_t *)(segment);

    fprintf(stream, "| user datagram ");
    fprintf(stream, "| % 6d ", ntohs(udp->source));
    fprintf(stream, "| % 6d ", ntohs(udp->destination));
    fprintf(stream, "| % 6d ", ntohs(udp->length));
    fprintf(stream, "| % 6d ", ntohs(udp->checksum));
    fprintf(stream, "|\n");

    snorlaxdbg(false, true, "check", "");
}
#endif // RELEASE
