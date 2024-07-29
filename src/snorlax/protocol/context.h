/**
 * @file        snorlax/protocol/context.h
 * @brief
 * @details
 * 
 * @author      snorlax <ceo@snorlax.bio>
 * @since       July 28, 2024
 */

#ifndef   __SNORLAX__PROTOCOL_CONTEXT__H__
#define   __SNORLAX__PROTOCOL_CONTEXT__H__

#include <snorlax.h>

struct protocol_context;
struct protocol_context_func;

typedef struct protocol_context protocol_context_t;
typedef struct protocol_context_func protocol_context_func_t;

struct protocol_context {
    protocol_context_func_t * func;
    sync_t * sync;
};

struct protocol_context_func {
    protocol_context_t * (*rem)(protocol_context_t *);
};

#define protocol_context_rem(context)       ((context)->func->rem(context))

#endif // __SNORLAX__PROTOCOL_CONTEXT__H__
