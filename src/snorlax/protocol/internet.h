/**
 * @file        snorlax/protocol/internet.h
 * @brief
 * @details
 * 
 * @author      snorlax <ceo@snorlax.bio>
 * @since       July 27, 2024
 */

#ifndef   __SNORLAX__PROTOCOL_INTERNET__H__
#define   __SNORLAX__PROTOCOL_INTERNET__H__

#include <snorlax.h>
#include <snorlax/protocol/module.h>

struct internet_protocol;

typedef struct internet_protocol internet_protocol_t;

struct internet_protocol_module;
struct internet_protocol_module_func;

typedef struct internet_protocol_module internet_protocol_module_t;
typedef struct internet_protocol_module_func internet_protocol_module_func_t;

struct internet_protocol {
    uint8_t prefix;
};

// interface ... 
struct internet_protocol_module {
    internet_protocol_module_func_t * func;
    sync_t * sync;
    protocol_module_t * parent;
    protocol_module_map_t * map;
};

struct internet_protocol_module_func {
    internet_protocol_module_t * (*rem)(internet_protocol_module_t *);
    int32_t (*validate)(internet_protocol_module_t *, const internet_protocol_t *, uint32_t);
    void (*debug)(internet_protocol_module_t *, FILE *, const internet_protocol_t *);
};


#endif // __SNORLAX__PROTOCOL_INTERNET__H__
