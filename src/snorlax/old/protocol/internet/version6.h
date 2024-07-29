/**
 * @file        snorlax/protocol/internet/version6.h
 * @brief
 * @details
 * 
 * @author      snorlax <ceo@snorlax.bio>
 * @since       July 5, 2024
 */

#ifndef   __SNORLAX__PROTOCOL_INTERNET_VERSION6__H__
#define   __SNORLAX__PROTOCOL_INTERNET_VERSION6__H__

#include <snorlax.h>

struct internet_protocol_version6_module;
struct internet_protocol_version6_module_func;

typedef struct internet_protocol_version6_module internet_protocol_version6_module_t;
typedef struct internet_protocol_version6_module_func internet_protocol_version6_module_func_t;

struct internet_protocol_version6;
struct internet_protocol_version6_option;

typedef struct internet_protocol_version6 internet_protocol_version6_t;
typedef struct internet_protocol_version6_option internet_protocol_version6_option_t;

struct internet_protocol_version6_module {
    internet_protocol_version6_module_func_t * func;
};

struct internet_protocol_version6_module_func {
    internet_protocol_version6_module_t * (*rem)(internet_protocol_version6_module_t *);
};

struct internet_protocol_version6 {
    uint32_t  prefix;
    uint16_t length;
    uint8_t  next;
    uint8_t  limit;
    uint16_t source[8];
    uint16_t destination[8];
};

struct internet_protocol_version6_option {
    uint8_t type;
    uint8_t len;
};

#define internet_protocol_version6_address_type_unspecified             0
#define internet_protocol_version6_address_type_loopback                1
#define internet_protocol_version6_address_type_multicast               2
#define internet_protocol_version6_address_type_link_local_unicast      3
#define internet_protocol_version6_address_type_global_unicast          4

#define internet_protocol_version6_address_unspecified                  ((uint16_t *) {    0,    0, 0, 0, 0, 0, 0, 0 })
#define internet_protocol_version6_address_loopback                     ((uint16_t *) {    0,    0, 0, 0, 0, 0, 0, 1 })
#define internet_protocol_version6_address_multicast                    ((uint16_t *) { 0xFF,    0, 0, 0, 0, 0, 0, 0 })
#define internet_protocol_version6_address_link_local_unicast           ((uint16_t *) { 0xFE, 0x80, 0, 0, 0, 0, 0, 0 })

#define internet_protocol_version6_address_prefix_unspecified           128
#define internet_protocol_version6_address_prefix_loopback              128
#define internet_protocol_version6_address_prefix_multicast             8
#define internet_protocol_version6_address_prefix_link_local            10

#define internet_protocol_version6_traffic_class_get(prefix)            (((prefix) & 0x0FF00000u) >> 20u)
#define internet_protocol_version6_flow_label_get(prefix)               ((prefix) & 0x000FFFFFu)
#define internet_protocol_version6_length_get(datagram)                 (ntohs(((internet_protocol_version6_t *)(datagram))->length) + sizeof(internet_protocol_version6_t))

// #define internet_protocol_version6_source_address_determine()

extern int32_t internet_protocol_version6_source_address_determine(const uint16_t * source, uint64_t * result);

#ifndef   RELEASE
extern void internet_protocol_version6_debug(FILE * stream, const uint8_t * datagram);
#endif // RELEASE

#endif // __SNORLAX__PROTOCOL_INTERNET_VERSION6__H__
