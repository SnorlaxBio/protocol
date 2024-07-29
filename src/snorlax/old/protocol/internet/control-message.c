#include <arpa/inet.h>

#include "control-message.h"

#ifndef   RELEASE
extern void internet_control_message_protocol_debug(FILE * stream, const internet_protocol_t * internet, const uint8_t * segment) {
    internet_control_message_protocol_t * message = (internet_control_message_protocol_t *) segment;
    fprintf(stream, "| internet control message ");
    fprintf(stream, "| % 3d ", message->type);
    fprintf(stream, "| % 3d ", message->code);
    fprintf(stream, "| % 6d ", ntohs(message->checksum));

    switch(message->type) {
        case internet_control_message_protocol_type_echo_req:                   internet_control_message_protocol_echo_debug(stream, internet, segment);                            break;
        case internet_control_message_protocol_type_echo_res:                   internet_control_message_protocol_echo_debug(stream, internet, segment);                            break;
        case internet_control_message_protocol_type_destination_unreachable:    internet_control_message_protocol_destination_unreachable_debug(stream, internet, segment);         break;
        case internet_control_message_protocol_type_source_quench:              internet_control_message_protocol_source_quench_debug(stream, internet, segment);                   break;
        case internet_control_message_protocol_type_redirect:                   internet_control_message_protocol_redirect_debug(stream, internet, segment);                        break;
        case internet_control_message_protocol_type_time_exceeded:              internet_control_message_protocol_time_exceeded_debug(stream, internet, segment);                   break;
        case internet_control_message_protocol_type_parameter_problem:          internet_control_message_protocol_parameter_problem_debug(stream, internet, segment);               break;
        case internet_control_message_protocol_type_timestamp_req:              internet_control_message_protocol_timestamp_debug(stream, internet, segment);                       break;
        case internet_control_message_protocol_type_timestamp_res:              internet_control_message_protocol_timestamp_debug(stream, internet, segment);                       break;
        case internet_control_message_protocol_type_information_req:            internet_control_message_protocol_information_debug(stream, internet, segment);                     break;
        case internet_control_message_protocol_type_information_res:            internet_control_message_protocol_information_debug(stream, internet, segment);                     break;
        default:                                                                snorlaxdbg(true, false, "critical", "unknown internet control message type => %d", message->type);  break;
    }
}

extern void internet_control_message_protocol_destination_unreachable_debug(FILE * stream, const internet_protocol_t * internet, const uint8_t * segment) {
    // TODO:
    fprintf(stream, "|\n");
}

extern void internet_control_message_protocol_time_exceeded_debug(FILE * stream, const internet_protocol_t * internet, const uint8_t * segment) {
    // TODO:
    fprintf(stream, "|\n");
}

extern void internet_control_message_protocol_parameter_problem_debug(FILE * stream, const internet_protocol_t * internet, const uint8_t * segment) {
    internet_control_message_protocol_parameter_problem_t * message = (internet_control_message_protocol_parameter_problem_t *) segment;

    fprintf(stream, "| % 3d ", message->pointer);
    // TODO: 
    fprintf(stream, "|\n");
}

extern void internet_control_message_protocol_source_quench_debug(FILE * stream, const internet_protocol_t * internet, const uint8_t * segment) {
    // TODO:
    fprintf(stream, "|\n");
}

extern void internet_control_message_protocol_redirect_debug(FILE * stream, const internet_protocol_t * internet, const uint8_t * segment) {
    internet_control_message_protocol_redirect_t * message = (internet_control_message_protocol_redirect_t *) segment;

    fprintf(stream, "| %15s ", inet_ntoa((struct in_addr) { .s_addr = message->address }));

    // TODO:

    fprintf(stream, "\n");
}

extern void internet_control_message_protocol_echo_debug(FILE * stream, const internet_protocol_t * internet, const uint8_t * segment) {
    internet_control_message_protocol_echo_t * message = (internet_control_message_protocol_echo_t *) segment;

    fprintf(stream, "| % 6d ", ntohs(message->identifier));
    fprintf(stream, "| % 6d ", ntohs(message->sequence));

    // TODO:

    fprintf(stream, "|\n");
}

extern void internet_control_message_protocol_timestamp_debug(FILE * stream, const internet_protocol_t * internet, const uint8_t * segment) {
    internet_control_message_protocol_timestamp_t * message = (internet_control_message_protocol_timestamp_t *) segment;

    fprintf(stream, "| % 6d ", ntohs(message->identifier));
    fprintf(stream, "| % 6d ", ntohs(message->sequence));

    // TODO: 

    fprintf(stream, "|\n");
}

extern void internet_control_message_protocol_information_debug(FILE * stream, const internet_protocol_t * internet, const uint8_t * segment) {
    internet_control_message_protocol_information_t * message = (internet_control_message_protocol_information_t *) segment;

    fprintf(stream, "| % 6d ", ntohs(message->identifier));
    fprintf(stream, "| % 6d ", ntohs(message->sequence));

    // TODO: 

    fprintf(stream, "|\n");
}
#endif // RELEASE
