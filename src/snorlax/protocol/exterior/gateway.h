/**
 * @file        snorlax/protocol/exterior/gateway.h
 * @brief
 * @details
 * 
 * @author      snorlax <ceo@snorlax.bio>
 * @since       July 24, 2024
 * @see         [EXTERIOR GATEWAY PROTOCOL](https://www.rfc-editor.org/rfc/rfc888.html)
 */

#ifndef   __SNORLAX__PROTOCOL_EXTERIOR_GATEWAY__H__
#define   __SNORLAX__PROTOCOL_EXTERIOR_GATEWAY__H__

#include <snorlax.h>

#define exterior_gateway_protocol_version       2

extern int32_t exterior_gateway_protocol_request(void);
extern int32_t exterior_gateway_protocol_confirm(void);
extern int32_t exterior_gateway_protocol_refuse(void);
extern int32_t exterior_gateway_protocol_cease(void);
extern int32_t exterior_gateway_protocol_cease_ack(void);
extern int32_t exterior_gateway_protocol_hello(void);
extern int32_t exterior_gateway_protocol_i_heard_you(void);
extern int32_t exterior_gateway_protocol_poll(void);
extern int32_t exterior_gateway_protocol_update(void);
extern int32_t exterior_gateway_protocol_error(void);

struct exterior_gateway_protocol_message;
struct exterior_gateway_protocol_message_neighbor_acquisition;
struct exterior_gateway_protocol_message_neighbor_reachability;
struct exterior_gateway_protocol_message_poll_command;
struct exterior_gateway_protocol_message_update;
struct exterior_gateway_protocol_message_error;

typedef struct exterior_gateway_protocol_message exterior_gateway_protocol_message_t;
typedef struct exterior_gateway_protocol_message_neighbor_acquisition exterior_gateway_protocol_message_neighbor_acquisition_t;
typedef struct exterior_gateway_protocol_message_neighbor_reachability exterior_gateway_protocol_message_neighbor_reachability_t;
typedef struct exterior_gateway_protocol_message_poll_command exterior_gateway_protocol_message_poll_command_t;
typedef struct exterior_gateway_protocol_message_update exterior_gateway_protocol_message_update_t;
typedef struct exterior_gateway_protocol_message_error exterior_gateway_protocol_message_error_t;

struct exterior_gateway_protocol_message {
    uint8_t version;
    uint8_t type;
    uint8_t code;
    uint8_t status;
    uint16_t checksum;
    uint16_t autonomous;
    uint16_t sequence;
};

extern uint16_t exterior_gateway_protocol_message_checksum_cal(uint16_t * array, int arraylen);
#ifndef   RELEASE
extern void exterior_gateway_protocol_message_debug(FILE * file, const uint8_t * message);
#endif // RELEASE

struct exterior_gateway_protocol_message_neighbor_acquisition {
    uint8_t version;
    uint8_t type;
    uint8_t code;
    uint8_t status;
    uint16_t checksum;
    uint16_t autonomous;
    uint16_t sequence;
    uint16_t hello;
    uint32_t poll;
};

#define exterior_gateway_protocol_message_type_neighbor_acquisition                     3

#define exterior_gateway_protocol_message_code_neighbor_acquisition_request_command     0
#define exterior_gateway_protocol_message_code_neighbor_acquisition_confirm_response    1
#define exterior_gateway_protocol_message_code_neighbor_acquisition_refuse_response     2
#define exterior_gateway_protocol_message_code_neighbor_acquisition_cease_command       3
#define exterior_gateway_protocol_message_code_neighbor_acquisition_cease_ack_response  4

#define exterior_gateway_protocol_message_status_unspecified                            0
#define exterior_gateway_protocol_message_status_active_mode                            1
#define exterior_gateway_protocol_message_status_passive_mode                           2
#define exterior_gateway_protocol_message_status_insufficient_resources                 3
#define exterior_gateway_protocol_message_status_administratively_prohibited            4
#define exterior_gateway_protocol_message_status_going_down                             5
#define exterior_gateway_protocol_message_status_parameter_problem                      6
#define exterior_gateway_protocol_message_status_protocol_violation                     7

extern exterior_gateway_protocol_message_neighbor_acquisition_t * exterior_gateway_protocol_message_neighbor_acquisition_gen(exterior_gateway_protocol_message_neighbor_acquisition_t * message, uint8_t code, uint8_t status, uint16_t autonomous, uint16_t sequence, uint16_t hello, uint16_t poll);
#ifndef   RELEASE
extern void exterior_gateway_protocol_message_neighbor_acquisition_debug(FILE * stream, const exterior_gateway_protocol_message_t * message);
#endif // RELEASE

struct exterior_gateway_protocol_message_neighbor_reachability {
    uint8_t version;
    uint8_t type;
    uint8_t code;
    uint8_t status;
    uint16_t checksum;
    uint16_t autonomous;
    uint16_t sequence;
};

#define exterior_gateway_protocol_message_type_neighbor_reachability                    5

#define exterior_gateway_protocol_message_code_neighbor_reachability_hello_command      0
#define exterior_gateway_protocol_message_code_neighbor_reachability_i_heard_u_command  1

#define exterior_gateway_protocol_message_status_neighbor_reachability_indeterminate    0
#define exterior_gateway_protocol_message_status_neighbor_reachability_up_state         1
#define exterior_gateway_protocol_message_status_neighbor_reachability_down_state       2

extern exterior_gateway_protocol_message_neighbor_reachability_t * exterior_gateway_protocol_message_neighbor_reachability_gen(exterior_gateway_protocol_message_neighbor_reachability_t * message, uint8_t code, uint8_t status, uint16_t autonomous, uint16_t sequence);
#ifndef   RELEASE
extern void exterior_gateway_protocol_message_neighbor_reachability_debug(FILE * stream, const exterior_gateway_protocol_message_t * message);
#endif // RELEASE

struct exterior_gateway_protocol_message_poll_command {
    uint8_t version;
    uint8_t type;
    uint8_t code;
    uint8_t status;
    uint16_t checksum;
    uint16_t autonomous;
    uint16_t sequence;
    uint16_t reserved;
    uint32_t source;
};

#define exterior_gateway_protocol_message_type_poll_command                     2

#define exterior_gateway_protocol_message_code_poll_command                     0

#define exterior_gateway_protocol_message_status_poll_command_indeterminate     0
#define exterior_gateway_protocol_message_status_poll_command_up_state          1
#define exterior_gateway_protocol_message_status_poll_command_down_state        2

extern exterior_gateway_protocol_message_poll_command_t * exterior_gateway_protocol_message_poll_command_gen(exterior_gateway_protocol_message_poll_command_t * message, uint8_t status, uint16_t autonomous, uint16_t sequence, uint32_t source);
#ifndef   RELEASE
extern void exterior_gateway_protocol_message_poll_command_debug(FILE * stream, const exterior_gateway_protocol_message_t * message);
#endif // RELEASE

struct exterior_gateway_protocol_message_update {
    uint8_t version;
    uint8_t type;
    uint8_t code;
    uint8_t status;
    uint16_t checksum;
    uint16_t autonomous;
    uint16_t sequence;
    struct {
        uint8_t interior;
        uint8_t exterior;
    } gateway;
    uint32_t source;
};

#define exterior_gateway_protocol_message_type_update                               1

#define exterior_gateway_protocol_message_code_update                               0

#define exterior_gateway_protocol_message_status_update_indeterminate               0
#define exterior_gateway_protocol_message_status_update_up_state                    1
#define exterior_gateway_protocol_message_status_update_down_state                  2
#define exterior_gateway_protocol_message_status_update__unsolicited_message_bit    128

extern exterior_gateway_protocol_message_update_t * exterior_gateway_protocol_message_update_gen(exterior_gateway_protocol_message_update_t * message, uint8_t status, uint16_t autonomous, uint16_t sequence, uint8_t interior, uint8_t exterior, uint32_t source);
#ifndef   RELEASE
extern void exterior_gateway_protocol_message_update_debug(FILE * stream, const exterior_gateway_protocol_message_t * message);
#endif // RELEASE

struct exterior_gateway_protocol_message_error {
    uint8_t version;
    uint8_t type;
    uint8_t code;
    uint8_t status;
    uint16_t checksum;
    uint16_t autonomous;
    uint16_t sequence;
    uint16_t reason;
    struct {
        uint8_t version;
        uint8_t type;
        uint8_t code;
        uint8_t status;
        uint16_t checksum;
        uint16_t autonomous;
        uint16_t sequence;
        uint16_t reason;
    } origin;
};

#define exterior_gateway_protocol_message_type_error                                    8

#define exterior_gateway_protocol_message_code_error                                    0

#define exterior_gateway_protocol_message_status_error_indeterminate                    0
#define exterior_gateway_protocol_message_status_error_up_state                         1
#define exterior_gateway_protocol_message_status_error_down_state                       2
#define exterior_gateway_protocol_message_status_error_unsolicited_message_bit          128

#define exterior_gateway_protocol_message_reason_error_unspecified                      0
#define exterior_gateway_protocol_message_reason_error_bad_egp_header_format            1
#define exterior_gateway_protocol_message_reason_error_bad_egp_data_field_format        2
#define exterior_gateway_protocol_message_reason_error_reachability_info_unavailable    3
#define exterior_gateway_protocol_message_reason_error_excessive_polling_rate           4
#define exterior_gateway_protocol_message_reason_error_no_response                      5

extern exterior_gateway_protocol_message_error_t * exterior_gateway_protocol_message_error_gen(exterior_gateway_protocol_message_error_t * message, uint8_t status, uint16_t autonomous, uint16_t sequence, uint16_t reason, exterior_gateway_protocol_message_t * origin, uint32_t originlen);
#ifndef   RELEASE
extern void exterior_gateway_protocol_message_error_debug(FILE * stream, const exterior_gateway_protocol_message_t * message);
#endif // RELEASE

#endif // __SNORLAX__PROTOCOL_EXTERIOR_GATEWAY__H__
