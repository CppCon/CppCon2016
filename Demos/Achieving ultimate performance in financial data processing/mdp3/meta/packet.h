#pragma once

// Copyright Crabel Capital Management 2016
// All rights reserved

#include "../packet.h"
#include "repeating_group.h"

namespace mdp3 { namespace meta {

template<
    typename Message,
    typename Context,
    bool (*Callable)(const Message &, Context &)
> struct dispatcher_slot_set_by_function {
    constexpr static unsigned MessageId = IdDeducer<Message>::value;

    static callback_t set(dispatcher &d) {
        return
            d.table[MessageId] =
                typed_callback<Message, Context, Callable>::caller;
    }
};

template<
    typename Message,
    typename Context,
    bool (Context::*Callable)(const Message &)
> struct dispatcher_slot_set_by_method {
    constexpr static unsigned MessageId = IdDeducer<Message>::value;

    static bool caller(const message_header *mh, void *ctx) {
        return (reinterpret_cast<Context *>(ctx)->*Callable)(*reinterpret_cast<const Message *>(mh->message()));
    }

    static callback_t set(dispatcher &d) {
        return d.table[MessageId] = caller;
    }
};

}}
