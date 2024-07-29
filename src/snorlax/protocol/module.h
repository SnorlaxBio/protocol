/**
 * @file        snorlax/protocol/module.h
 * @brief
 * @details
 * 
 * @author      snorlax <ceo@snorlax.bio>
 * @since       July 27, 2024
 */

#ifndef   __SNORLAX__PROTOCOL_MODULE__H__
#define   __SNORLAX__PROTOCOL_MODULE__H__

#include <snorlax.h>
#include <snorlax/protocol.h>

struct protocol_module;
struct protocol_module_func;

struct protocol_module_map;

typedef struct protocol_module protocol_module_t;
typedef struct protocol_module_func protocol_module_func_t;

typedef struct protocol_module_map protocol_module_map_t;

struct protocol_module {
    protocol_module_func_t * func;
    sync_t * sync;
    protocol_module_t * parent;
    protocol_module_map_t * map;
};

struct protocol_module_func {
    protocol_module_t * (*rem)(protocol_module_t *);
    int32_t (*validate)(protocol_module_t *, const uint8_t *, uint32_t);
    void (*debug)(protocol_module_t *, FILE *, const protocol_t *);
    int32_t (*on)(protocol_module_t *, protocol_t *, uint32_t, protocol_t *);
};

#define protocol_module_rem(module)                             ((module)->func->rem(module))
#define protocol_module_validate(module, data, datalen)         ((module)->func->validate(module, data, datalen))
#define protocol_module_debug(module, stream, data)             ((module)->func->debug(module, stream, data))
#define protocol_module_on(module, packet, packetlen, parent)   ((module)->func->on(module, packet, packetlen, parent))

#endif // __SNORLAX__PROTOCOL_MODULE__H__
