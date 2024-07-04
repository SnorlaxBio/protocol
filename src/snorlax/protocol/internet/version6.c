#include <arpa/inet.h>

#include "version6.h"
#include "../internet.h"

#ifndef   RELEASE
extern void internet_protocol_version6_debug(FILE * stream, const uint8_t * datagram) {
    const internet_protocol_version6_t * internet = (internet_protocol_version6_t *) datagram;

    uint32_t prefix = ntohl(internet->prefix);

    fprintf(stream, "| internet version 6 ");
    fprintf(stream, "| %d ", internet_protocol_version_get(datagram));
    fprintf(stream, "| %02x ", internet_protocol_version6_traffic_class_get(prefix));
    fprintf(stream, "| %05x ", internet_protocol_version6_flow_label_get(prefix));
    fprintf(stream, "| % 6d ", ntohs(internet->length));
    fprintf(stream, "| % 3d ", internet->next);
    fprintf(stream, "| % 3d ", internet->limit);
    fprintf(stream, "| %04x:%04x:%04x:%04x:%04x:%04x:%04x:%04x ", ntohs(internet->source[0]),
                                                                  ntohs(internet->source[1]),
                                                                  ntohs(internet->source[2]),
                                                                  ntohs(internet->source[3]),
                                                                  ntohs(internet->source[4]),
                                                                  ntohs(internet->source[5]),
                                                                  ntohs(internet->source[6]),
                                                                  ntohs(internet->source[7]));
    fprintf(stream, "| %04x:%04x:%04x:%04x:%04x:%04x:%04x:%04x ", ntohs(internet->destination[0]),
                                                                  ntohs(internet->destination[1]),
                                                                  ntohs(internet->destination[2]),
                                                                  ntohs(internet->destination[3]),
                                                                  ntohs(internet->destination[4]),
                                                                  ntohs(internet->destination[5]),
                                                                  ntohs(internet->destination[6]),
                                                                  ntohs(internet->destination[7]));
    fprintf(stream, "|\n");

    snorlaxdbg(true, false, "check", "");
}
#endif // RELEASE