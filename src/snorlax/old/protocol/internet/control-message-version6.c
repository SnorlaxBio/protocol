#include "control-message-version6.h"

#ifndef   RELEASE
extern void internet_control_message_version6_debug(FILE * stream, const uint8_t * datagram) {
    snorlaxdbg(datagram == nil, false, "critical", "");

    const internet_control_message_version6_t * message = (internet_control_message_version6_t *) datagram;

    fprintf(stream, "| internet control message protocol version 6 ");
    fprintf(stream, "| % 3d ", message->type);
    fprintf(stream, "| % 3d ", message->code);
    fprintf(stream, "| % 6d ", message->checksum);

}
#endif // RELEASE