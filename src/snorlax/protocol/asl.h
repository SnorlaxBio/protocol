/**
 * @file        snorlax/protocol/asl.h
 * @brief       a sign language.
 * @details
 * 
 * @author      snorlax <ceo@snorlax.bio>
 * @since       July 24, 2024
 */

#ifndef   __SNORLAX__PROTOCOL_ASL__H__
#define   __SNORLAX__PROTOCOL_ASL__H__

#include <snorlax.h>

#define asl_type_int8                   0x01
#define asl_type_int16                  0x02
#define asl_type_int32                  0x03
#define asl_type_int64                  0x04
#define asl_type_uint8                  0x05
#define asl_type_uint16                 0x06
#define asl_type_uint32                 0x07
#define asl_type_uint64                 0x08
#define asl_type_string                 0x09
#define asl_type_struct                 0x10
#define asl_type_list                   0x11

struct asl_variable;
struct asl_primitive;
struct asl_int8;
struct asl_int16;
struct asl_int32;
struct asl_int64;
struct asl_uint8;
struct asl_uint16;
struct asl_uint32;
struct asl_uint64;
struct asl_object;
struct asl_string;
struct asl_struct;
struct asl_collection;
struct asl_list;

typedef struct asl_variable asl_variable_t;
typedef struct asl_primitive asl_primitive_t;
typedef struct asl_int8 asl_int8_t;
typedef struct asl_int16 asl_int16_t;
typedef struct asl_int32 asl_int32_t;
typedef struct asl_int64 asl_int64_t;
typedef struct asl_uint8 asl_uint8_t;
typedef struct asl_uint16 asl_uint16_t;
typedef struct asl_uint32 asl_uint32_t;
typedef struct asl_uint64 asl_uint64_t;
typedef struct asl_object asl_object_t;
typedef struct asl_string asl_string_t;
typedef struct asl_struct asl_struct_t;
typedef struct asl_collection asl_collection_t;
typedef struct asl_list asl_list_t;

struct asl_variable {
    uint8_t type;
} __attribute__((packed));

struct asl_primitive {
    uint8_t type;
} __attribute__((packed));

struct asl_int8 {
    uint8_t type;
    int8_t value;
} __attribute__((packed));

struct asl_int16 {
    uint8_t type;
    int16_t value;
} __attribute__((packed));

struct asl_int32 {
    uint8_t type;
    int32_t value;
} __attribute__((packed));

struct asl_int64 {
    uint8_t type;
    int64_t value;
} __attribute__((packed));

struct asl_uint8 {
    uint8_t type;
    uint8_t value;
} __attribute__((packed));

struct asl_uint16 {
    uint8_t type;
    uint16_t value;
} __attribute__((packed));

struct asl_uint32 {
    uint8_t type;
    uint32_t value;
} __attribute__((packed));

struct asl_uint64 {
    uint8_t type;
    uint64_t value;
} __attribute__((packed));

struct asl_object {
    uint8_t type;
    uint32_t len;
} __attribute__((packed));

struct asl_string {
    uint8_t type;
    uint32_t len;
    uint8_t value[1];
} __attribute__((packed));

struct asl_struct {
    uint8_t type;
    uint32_t len;
    uint32_t name;
    uint8_t value[1];
} __attribute__((packed));

struct asl_collection {
    uint8_t type;
    uint32_t len;
    uint32_t size;
    asl_variable_t items[1];
} __attribute__((packed));

struct asl_list {
    uint8_t type;
    uint32_t len;
    uint32_t size;
    asl_variable_t items[1];
} __attribute__((packed));

#endif // __SNORLAX__PROTOCOL_ASL__H__