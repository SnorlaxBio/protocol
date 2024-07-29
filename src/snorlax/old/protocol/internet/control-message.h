/**
 * @file        snorlax/protocol/internet/control-message.h
 * @brief
 * @details
 * 
 * @author      snorlax <ceo@snorlax.bio>
 * @since       July 5, 2024
 */

#ifndef   __SNORLAX__PROTOCOL_INTERNET_CONTROL_MESSAGE__H__
#define   __SNORLAX__PROTOCOL_INTERNET_CONTROL_MESSAGE__H__

#include <snorlax.h>

#include <snorlax/protocol/internet.h>

struct internet_control_message_protocol;

struct internet_control_message_protocol_destination_unreachable;
struct internet_control_message_protocol_time_exceeded;
struct internet_control_message_protocol_parameter_problem;
struct internet_control_message_protocol_source_quench;
struct internet_control_message_protocol_redirect;
struct internet_control_message_protocol_echo;
struct internet_control_message_protocol_timestamp;
struct internet_control_message_protocol_information;

typedef struct internet_control_message_protocol                            internet_control_message_protocol_t;

typedef struct internet_control_message_protocol_destination_unreachable    internet_control_message_protocol_destination_unreachable_t;
typedef struct internet_control_message_protocol_time_exceeded              internet_control_message_protocol_time_exceeded_t;
typedef struct internet_control_message_protocol_parameter_problem          internet_control_message_protocol_parameter_problem_t;
typedef struct internet_control_message_protocol_source_quench              internet_control_message_protocol_source_quench_t;
typedef struct internet_control_message_protocol_redirect                   internet_control_message_protocol_redirect_t;
typedef struct internet_control_message_protocol_echo                       internet_control_message_protocol_echo_t;
typedef struct internet_control_message_protocol_timestamp                  internet_control_message_protocol_timestamp_t;
typedef struct internet_control_message_protocol_information                internet_control_message_protocol_information_t;

#define internet_control_message_protocol_type_echo_req                     8
#define internet_control_message_protocol_type_echo_res                     0
#define internet_control_message_protocol_type_destination_unreachable      3
#define internet_control_message_protocol_type_source_quench                4
#define internet_control_message_protocol_type_redirect                     5
#define internet_control_message_protocol_type_time_exceeded                11
#define internet_control_message_protocol_type_parameter_problem            12
#define internet_control_message_protocol_type_timestamp_req                13
#define internet_control_message_protocol_type_timestamp_res                14
#define internet_control_message_protocol_type_information_req              15
#define internet_control_message_protocol_type_information_res              16


struct internet_control_message_protocol {
    uint8_t  type;
    uint8_t  code;
    uint16_t checksum;
};

struct internet_control_message_protocol_destination_unreachable {
    uint8_t  type;
    uint8_t  code;
    uint16_t checksum;
    uint32_t unused;
};

struct internet_control_message_protocol_time_exceeded {
    uint8_t  type;
    uint8_t  code;
    uint16_t checksum;
    uint32_t unused;
};

struct internet_control_message_protocol_parameter_problem {
    uint8_t  type;
    uint8_t  code;
    uint16_t checksum;
    uint8_t  pointer;
    uint8_t  unused[3];
};

struct internet_control_message_protocol_source_quench {
    uint8_t  type;
    uint8_t  code;
    uint16_t checksum;
    uint32_t unused;
};

struct internet_control_message_protocol_redirect {
    uint8_t  type;
    uint8_t  code;
    uint16_t checksum;
    uint32_t address;
};

struct internet_control_message_protocol_echo {
    uint8_t  type;
    uint8_t  code;
    uint16_t checksum;
    uint16_t identifier;
    uint16_t sequence;
};

struct internet_control_message_protocol_timestamp {
    uint8_t  type;
    uint8_t  code;
    uint16_t checksum;
    uint16_t identifier;
    uint16_t sequence;
    struct {
        uint32_t originate;
        uint32_t receive;
        uint32_t transmit;
    } timestamp;
};

struct internet_control_message_protocol_information {
    uint8_t  type;
    uint8_t  code;
    uint16_t checksum;
    uint16_t identifier;
    uint16_t sequence;
};

#ifndef   RELEASE
extern void internet_control_message_protocol_debug(FILE * stream, const internet_protocol_t * internet, const uint8_t * segment);
extern void internet_control_message_protocol_destination_unreachable_debug(FILE * stream, const internet_protocol_t * internet, const uint8_t * segment);
extern void internet_control_message_protocol_time_exceeded_debug(FILE * stream, const internet_protocol_t * internet, const uint8_t * segment);
extern void internet_control_message_protocol_parameter_problem_debug(FILE * stream, const internet_protocol_t * internet, const uint8_t * segment);
extern void internet_control_message_protocol_source_quench_debug(FILE * stream, const internet_protocol_t * internet, const uint8_t * segment);
extern void internet_control_message_protocol_redirect_debug(FILE * stream, const internet_protocol_t * internet, const uint8_t * segment);
extern void internet_control_message_protocol_echo_debug(FILE * stream, const internet_protocol_t * internet, const uint8_t * segment);
extern void internet_control_message_protocol_timestamp_debug(FILE * stream, const internet_protocol_t * internet, const uint8_t * segment);
extern void internet_control_message_protocol_information_debug(FILE * stream, const internet_protocol_t * internet, const uint8_t * segment);

#endif // RELEASE

#endif // __SNORLAX__PROTOCOL_INTERNET_CONTROL_MESSAGE__H__
