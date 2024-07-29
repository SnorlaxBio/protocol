#include <arpa/inet.h>

#include "version4.h"

#include "../module/map.h"

static internet_protocol_version4_module_t * internet_protocol_version4_module_func_rem(internet_protocol_version4_module_t * module);
static int32_t internet_protocol_version4_module_func_validate(internet_protocol_version4_module_t * module, const uint8_t * datagram, uint32_t datagramlen);
static void internet_protocl_version4_module_func_debug(internet_protocol_version4_module_t * module, FILE * stream, const internet_protocol_version4_t * datagram);
static int32_t internet_protocol_version4_module_func_on(internet_protocol_version4_module_t * module, internet_protocol_version4_t * packet, int32_t packetlen);

static internet_protocol_version4_module_func_t func = {
    internet_protocol_version4_module_func_rem,
    internet_protocol_version4_module_func_validate,
    internet_protocl_version4_module_func_debug,
    internet_protocol_version4_module_func_on
};

extern internet_protocol_version4_module_t * internet_protocol_version4_module_gen(void) {
    internet_protocol_version4_module_t * module = (internet_protocol_version4_module_t *) calloc(1, sizeof(internet_protocol_version4_module_t));

    module->func = address_of(func);

    return module;
}

static internet_protocol_version4_module_t * internet_protocol_version4_module_func_rem(internet_protocol_version4_module_t * module) {
#ifndef   RELEASE
    snorlaxdbg(module == nil, false, "critical", "");
#endif // RELEASE

    free(module);

    return nil;
}

static int32_t internet_protocol_version4_module_func_validate(internet_protocol_version4_module_t * module, const uint8_t * datagram, uint32_t datagramlen) {
#ifndef   RELEASE
    snorlaxdbg(module == nil, false, "critical", "");
    snorlaxdbg(datagram == nil, false, "critical", "");
    snorlaxdbg(datagramlen == 0, false, "critical", "");
#endif // RELEASE

    internet_protocol_version4_t * packet = (internet_protocol_version4_t *) datagram;

    // if(datagramlen < internet_protocol_version4_length_cal(datagram)) {
    //     return false;
    // }

    // if(datagram->version != 4) {
    //     return false;
    // }

    return true;

    // LENGTH CHECK
}

extern uint16_t internet_protocol_version4_header_checksum_cal(internet_protocol_version4_t * packet) {
    uint16_t checksum = packet->checksum;

    packet->checksum = 0;

    uint16_t * data = (uint16_t *) packet;

    int n = (packet->length * 2);

    uint16_t v = data[0];

    for(int i = 1; i < n; i++) {
        v = v + data[i];
    }

    packet->checksum = htons(checksum);

    return ~v;
}

static int32_t internet_protocol_version4_module_func_on(internet_protocol_version4_module_t * module, internet_protocol_version4_t * packet, int32_t packetlen) {
#ifndef   RELEASE
    snorlaxdbg(module == nil, false, "critical", "");
    snorlaxdbg(packet == nil, false, "critical", "");
    snorlaxdbg(packetlen == 0, false, "critical", "");
#endif // RELEASE

    internet_protocol_version4_module_debug(module, stdout, packet);

    if(internet_protocol_version4_module_validate(module, packet, packetlen)) {
        for(internet_protocol_version4_option_t * option = internet_protocol_version4_module_option_begin(packet); internet_protocol_version4_module_option_end(option, packet); option = internet_protocol_version4_module_option_next(option)) {
            switch(internet_protocol_version4_module_option_type_get(option)) {
                case internet_protocol_version4_module_option_type_end:                     internet_protocol_version4_module_option_on_end(option);                    break;
                case internet_protocol_version4_module_option_type_no_operation:            internet_protocol_version4_module_option_on_no_operation(option);           break;
                case internet_protocol_version4_module_option_type_security:                internet_protocol_version4_module_option_on_security(option);               break;
                case internet_protocol_version4_module_option_type_loose_source_route:      internet_protocol_version4_module_option_on_loose_source_route(option);     break;
                case internet_protocol_version4_module_option_type_strict_source_route:     internet_protocol_version4_module_option_on_strict_source_route(option);    break;
                case internet_protocol_version4_module_option_type_record_route:            internet_protocol_version4_module_option_on_record_route(option);           break;
                case internet_protocol_version4_module_option_type_stream_identifier:       internet_protocol_version4_module_option_on_stream_identifier(option);      break;
                case internet_protocol_version4_module_option_type_internet_timestamp:      internet_protocol_version4_module_option_on_internet_timestamp(option);     break;
                default:                                                                    snorlaxdbg(true, false, "critial", "");                                     break;
            }
        }

        protocol_module_t * submodule = protocol_module_map_get(module->map, packet->protocol);

        if(submodule) {
            // protocol_module_on
        }

        // module->map
    }

    return false;
}

static void internet_protocl_version4_module_func_debug(internet_protocol_version4_module_t * module, FILE * stream, const internet_protocol_version4_t * datagram) {
#ifndef   RELEASE
    snorlaxdbg(module == nil, false, "critical", "");
    snorlaxdbg(stream == nil, false, "critical", "");
    snorlaxdbg(datagram == nil, false, "critical", "");
#endif // RELEASE

    fprintf(stream, "| internet protocol version 4 ");
    fprintf(stream, "| %d ", datagram->version);
    fprintf(stream, "| % 2d ", datagram->length);
    fprintf(stream, "| % 3d ", datagram->service);
    fprintf(stream, "| % 6d ", ntohs(datagram->total));
    fprintf(stream, "| % 6d ", ntohs(datagram->identification));
    fprintf(stream, "| %04x ", datagram->fragment);
    fprintf(stream, "| % 3d ", datagram->ttl);
    fprintf(stream, "| % 3d ", datagram->protocol);
    fprintf(stream, "| % 6d ", ntohs(datagram->checksum));
    fprintf(stream, "| % 15s ", inet_ntoa((struct in_addr) { .s_addr = ntohl(datagram->source) }));
    fprintf(stream, "| % 15s ", inet_ntoa((struct in_addr) { .s_addr = ntohl(datagram->destination) }));
    fprintf(stream, "|\n");
}
