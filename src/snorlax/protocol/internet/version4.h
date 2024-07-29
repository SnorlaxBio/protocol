/**
 * @file        snorlax/protocol/internet/version4.h
 * @brief
 * @details
 * 
 * @author      snorlax <ceo@snorlax.bio>
 * @since       July 27, 2024
 */

#ifndef   __SNORLAX__PROTOCOL_INTERNET_VERSION4__H__
#define   __SNORLAX__PROTOCOL_INTERNET_VERSION4__H__

#include <snorlax.h>
#include <snorlax/protocol/module.h>

struct internet_protocol_version4;
typedef struct internet_protocol_version4 internet_protocol_version4_t;

typedef uint8_t internet_protocol_version4_option_t;

struct internet_protocol_version4_module;
struct internet_protocol_version4_module_func;

typedef struct internet_protocol_version4_module internet_protocol_version4_module_t;
typedef struct internet_protocol_version4_module_func internet_protocol_version4_module_func_t;

struct internet_protocol_version4 {
#if       __BYTE_ORDER == __LITTLE_ENDIAN
    uint8_t length:4;
    uint8_t version:4;
#else  // __BYTE_ORDER == __LITTLE_ENDIAN
    uint8_t version:4;
    uint8_t length:4;
#endif // __BYTE_ORDER == __LITTLE_ENDIAN
    uint8_t  service;
    uint16_t total;
    uint16_t identification;
    uint16_t fragment;
    uint8_t  ttl;
    uint8_t  protocol;
    uint16_t checksum;
    uint32_t source;
    uint32_t destination;
};

struct internet_protocol_version4_module {
    internet_protocol_version4_module_func_t * func;
    sync_t * sync;
    protocol_module_t * parent;
    protocol_module_map_t * map;
};

struct internet_protocol_version4_module_func {
    internet_protocol_version4_module_t * (*rem)(internet_protocol_version4_module_t *);
    int32_t (*validate)(internet_protocol_version4_module_t *, const uint8_t *, uint32_t);
    void (*debug)(internet_protocol_version4_module_t *, FILE *, const internet_protocol_version4_t *);
    int32_t (*on)(internet_protocol_version4_module_t *, internet_protocol_version4_t *, int32_t, protocol_t *);
};

#define internet_protocol_version4_module_type_of_service_precedence_network_control            (0xE0u)
#define internet_protocol_version4_module_type_of_service_precedence_internetwork_control       (0xA0u)
#define internet_protocol_version4_module_type_of_service_precedence_critic_ecp                 (0x80u)
#define internet_protocol_version4_module_type_of_service_precedence_flash_override             (0x60u)
#define internet_protocol_version4_module_type_of_service_precedence_flash                      (0x60u)
#define internet_protocol_version4_module_type_of_service_precedence_immediate                  (0x40u)
#define internet_protocol_version4_module_type_of_service_precedence_priority                   (0x20u)
#define internet_protocol_version4_module_type_of_service_precedence_routine                    (0x00u)
#define internet_protocol_version4_module_flag_fragment_may                                     (0x00u)
#define internet_protocol_version4_module_flag_fragment_do_not                                  (0x40u)
#define internet_protocol_version4_module_flag_fragment_last                                    (0x00u)
#define internet_protocol_version4_module_flag_fragment_more                                    (0x20u)
#define internet_protocol_version4_module_option_type_end                                       (0)
#define internet_protocol_version4_module_option_type_no_operation                              (1)
#define internet_protocol_version4_module_option_type_security                                  (130)
#define internet_protocol_version4_module_option_type_loose_source_route                        (131)
#define internet_protocol_version4_module_option_type_strict_source_route                       (137)
#define internet_protocol_version4_module_option_type_record_route                              (7)
#define internet_protocol_version4_module_option_type_stream_identifier                         (136)
#define internet_protocol_version4_module_option_type_internet_timestamp                        (68)

#define internet_protocol_version4_module_version_get(datagram)                                 (((internet_protocol_version4_t *) (datagram))->version)
#define internet_protocol_version4_module_header_length_get(datagram)                           ((((internet_protocol_version4_t *) (datagram))->version) * 4)
#define internet_protocol_version4_module_type_of_service_precedence_get(datagram)              ((((internet_protocol_version4_t *) (datagram))->version) & 0xE0u)
#define internet_protocol_version4_module_type_of_service_delay_get(datagra)                    ((((internet_protocol_version4_t *) (datagram))->version) & 0x10u)
#define internet_protocol_version4_module_type_of_service_throughput_get(datagra)               ((((internet_protocol_version4_t *) (datagram))->version) & 0x08u)
#define internet_protocol_version4_module_type_of_service_reliability_get(datagra)              ((((internet_protocol_version4_t *) (datagram))->version) & 0x04u)
#define internet_protocol_version4_module_total_length_get(datagram)                            (ntohs(((internet_protocol_version4_t *) (datagram))->total))
#define internet_protocol_version4_module_identification_get(datagram)                          (ntohs(((internet_protocol_version4_t *) (datagram))->identification))
#define internet_protocol_version4_module_fragment_mf_get(datagram)                             (ntohs(((internet_protocol_version4_t *) (datagram))->fragment) & 0x4000u)
#define internet_protocol_version4_module_fragment_df_get(datagram)                             (ntohs(((internet_protocol_version4_t *) (datagram))->fragment) & 0x2000u)
#define internet_protocol_version4_module_fragment_offset_get(datagram)                         (htons(ntohs(((internet_protocol_version4_t *) (datagram))->fragment) & 0x1FFFu))

#define interent_protocol_version4_module_payload_get(datagram)                                 (&((uint8_t *) (datagram))[internet_protocol_version4_module_header_length_get(datagram)])

#define internet_protocol_version4_module_option_type_get(option)                               (*((uint8_t *)(option)))
#define internet_protocol_version4_module_option_length_get(option)                             (internet_protocol_version4_module_option_type_get(option) <= 1 ? 1 : ((uint8_t *)(option))[1])
#define internet_protocol_version4_module_option_data_get(option)                               (internet_protocol_version4_module_option_type_get(option) <= 1 ? nil : &((uint8_t *)(option))[2])

#define internet_protocol_version4_module_option_begin(datagram)                                (&((uint8_t *) (datagram))[20])
#define internet_protocol_version4_module_option_next(option)                                   &((uint8_t *)(option))[internet_protocol_version4_module_option_length_get(option)]
#define internet_protocol_version4_module_option_end(option, datagram)                          (option == interent_protocol_version4_module_payload_get(datagram) || *((uint8_t *)(option)) == 0)

extern uint16_t internet_protocol_version4_header_checksum_cal(internet_protocol_version4_t * packet);

extern internet_protocol_version4_module_t * internet_protocol_version4_module_gen(void);

#define internet_protocol_version4_module_rem(module)                                           ((module)->func->rem(module))
#define internet_protocol_version4_module_validate(module, packet, packetlen)                   ((module)->func->validate(module, packet, packetlen))
#define internet_protocol_version4_module_debug(module, stream, packet)                         ((module)->func->debug(module, stream, packet))
#define internet_protocol_version4_module_on(module, packet, packetlen, parent)                 ((module)->func->on(module, packet, packetlen, parent))

#endif // __SNORLAX__PROTOCOL_INTERNET_VERSION4__H__
