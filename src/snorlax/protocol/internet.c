#include "internet.h"

#include "internet/version4.h"
#include "internet/version6.h"

#ifndef   RELEASE
extern void internet_protocol_debug(FILE * stream, const uint8_t * datagram) {
    uint8_t version = internet_protocol_version_get(datagram);

    if(version == 4) {
        internet_protocol_version4_debug(stream, datagram);
    } else if(version == 6) {
        internet_protocol_version6_debug(stream, datagram);
    } else {
#ifndef   RELEASE
        snorlaxdbg(true, false, "critical", "not supported protocol version => %d", version);
#endif // RELEASE
    }
}
#endif // RELEASE

extern uint32_t internet_protocol_length_get(internet_protocol_t * datagram) {
    uint8_t version = internet_protocol_version_get(datagram);

    if(version == 4) {
#ifndef   RELEASE
        snorlaxdbg(true, false, "implement", "");
#endif // RELEASE
        return internet_protocol_version4_length_get(datagram);
        // internet_protocol_version4_debug(stream, datagram);
    } else if(version == 6) {
        return internet_protocol_version6_length_get(datagram);
        // internet_protocol_version6_debug(stream, datagram);
    } else {
#ifndef   RELEASE
        snorlaxdbg(true, false, "critical", "not supported protocol version => %d", version);
#endif // RELEASE
    }

    return 0;
}
