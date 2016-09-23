#pragma once

// Copyright Crabel Capital Management 2016
// All rights reserved

#include "./mdp3.h"

namespace mdp3 {

struct packet_header {
    uint32_t sequenceNumber;
    uint64_t nanosecondsSinceEpoch;
} __attribute__ ((aligned(1), packed));

struct message_header {
    uint16_t messageSize;
    messageHeader header;

    const void *message() const {
        return reinterpret_cast<const void *>(this + 1);
    }

    const message_header *next() const {
        return reinterpret_cast<const message_header *>(
            reinterpret_cast<const char *>(this) + messageSize
        );
    }
} __attribute__ ((aligned(1), packed));

struct packet {
    packet_header header;
    message_header mHeader;

    unsigned sequenceNumber() const { return header.sequenceNumber; }
    uint64_t sendingTime() const { return header.nanosecondsSinceEpoch; }

    const message_header *firstHeader() const { return &mHeader; }

    const char *thy() const { return reinterpret_cast<const char *>(this); }

    template<typename T> const T *p(unsigned offset) const {
        return reinterpret_cast<const T *>(thy() + offset);
    }
} __attribute__ ((aligned(1), packed));

struct packet_view {
    const packet *p = nullptr;
    unsigned size = 0;

    packet_view() {}
    packet_view(const char *buffer, unsigned size):
        p(reinterpret_cast<const packet *>(buffer)), size(size)
    {}

    operator const packet *() const { return p; }
};

using callback_t =
    bool (*)(const message_header *messagePayload, void *context);

constexpr unsigned MAX_MESSAGE_ID = 42;

struct dispatcher {
    const packet *p = nullptr;
    const char *sentry = nullptr;
    void *context = nullptr;
    callback_t table[MAX_MESSAGE_ID + 1];
    const message_header *mh = nullptr;
    uint64_t reception = 0;
    union {
        struct {
            bool hardware_timestamp: 1;
        };
        uint8_t properties = 0;
    };

    dispatcher() { for(auto i = MAX_MESSAGE_ID + 1; i--; ) { table[i] = nullptr; }  }

    void newPacket(packet_view pv, uint64_t timestamp, bool hts) {
        p = pv.p;
        sentry = reinterpret_cast<const char *>(p) + pv.size;
        mh = p->firstHeader();
        reception = timestamp;
        hardware_timestamp = hts;
    }

    bool dispatch(const message_header *h) const {
        if(sentry <= reinterpret_cast<const char *>(h)) { return false; }
        if(!table[h->header.templateId]) { return true; }
        table[h->header.templateId](h, context);
        return true;
    }

    bool dispatch() {
        if(!dispatch(mh)) { return false; }
        mh = mh->next();
        return true;
    }
};

template<
    typename Message,
    typename Context,
    bool (*Callable)(const Message &, Context &)
> struct typed_callback {
    static bool caller(const message_header *header, void *context) {
        return
            Callable(
                *reinterpret_cast<const Message *>(header->message()),
                *reinterpret_cast<Context *>(context)
            );
    }
};

inline const packet *asPacket(const char *buffer) {
    return reinterpret_cast<const packet *>(buffer);
}

}
