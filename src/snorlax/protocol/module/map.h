/**
 * @file        snorlax/protocol/module/map.h
 * @brief
 * @details
 * 
 * @author      snorlax <ceo@snorlax.bio>
 * @since       July 27, 2024
 */

#ifndef   __SNORLAX__PROTOCOL_MODULE_MAP__H__
#define   __SNORLAX__PROTOCOL_MODULE_MAP__H__

#include <snorlax.h>

struct protocol_module;

struct protocol_module_map;
struct protocol_module_map_func;

typedef struct protocol_module protocol_module_t;

typedef struct protocol_module_map protocol_module_map_t;
typedef struct protocol_module_map_func protocol_module_map_func_t;

struct protocol_module_map {
    protocol_module_map_func_t * func;
    sync_t * sync;
};

struct protocol_module_map_func {
    protocol_module_map_t * (*rem)(protocol_module_map_t *);
    protocol_module_t * (*get)(protocol_module_map_t *, uint32_t);
    void (*set)(protocol_module_map_t *, uint32_t, protocol_module_t *);
};

#define protocol_module_map_rem(map)                ((map)->func->rem(map))
#define protocol_module_map_get(map, no)            ((map)->func->get(map, no))
#define protocol_module_map_set(map, no, module)    ((map)->func->set(map, no, module))

#endif // __SNORLAX__PROTOCOL_MODULE_MAP__H__
