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
