#ifndef inverters_WATCHDOG_H
#define inverters_WATCHDOG_H

#include <inttypes.h>

#ifdef __cplusplus
extern "C" {
#endif

#ifndef CANLIB_WATCHDOG_TIMESTAMP_TYPE
#define CANLIB_WATCHDOG_TIMESTAMP_TYPE
typedef uint32_t canlib_watchdog_timestamp;
#endif // CANLIB_WATCHDOG_TIMESTAMP_TYPE

#ifndef CANLIB_MESSAGE_ID_TYPE
#define CANLIB_MESSAGE_ID_TYPE
typedef uint16_t canlib_message_id;
#endif // CANLIB_MESSAGE_ID_TYPE

#ifndef CANLIB_WATCHDOG_CALLBACK
#define CANLIB_WATCHDOG_CALLBACK
typedef void (*canlib_watchdog_callback)(int);
#endif // CANLIB_WATCHDOG_CALLBACK

#ifndef CANLIB_BITMASK_UTILS
#define CANLIB_BITMASK_UTILS

#define CANLIB_BITMASK_TYPE uint8_t
#define CANLIB_BITMASK_TYPE_BITS 8

#define CANLIB_BITMASK_ARRAY(b) (1 << ((b) % CANLIB_BITMASK_TYPE_BITS))
#define CANLIB_BITSLOT_ARRAY(b) ((b) / CANLIB_BITMASK_TYPE_BITS)
#define CANLIB_BITSET_ARRAY(a, b) ((a)[CANLIB_BITSLOT_ARRAY(b)] |= CANLIB_BITMASK_ARRAY(b))
#define CANLIB_BITCLEAR_ARRAY(a, b) ((a)[CANLIB_BITSLOT_ARRAY(b)] &= ~CANLIB_BITMASK_ARRAY(b))
#define CANLIB_BITTEST_ARRAY(a, b) ((a)[CANLIB_BITSLOT_ARRAY(b)] & CANLIB_BITMASK_ARRAY(b))
#define CANLIB_BITNSLOTS_ARRAY(nb) ((nb + CANLIB_BITMASK_TYPE_BITS - 1) / CANLIB_BITMASK_TYPE_BITS)

#define CANLIB_BITMASK(b) (1 << (b))
#define CANLIB_BITSET(a, b) ((a) |= CANLIB_BITMASK(b))
#define CANLIB_BITCLEAR(a, b) ((a) &= ~CANLIB_BITMASK(b))
#define CANLIB_BITTEST(a, b) ((a) & CANLIB_BITMASK(b))

#endif // CANLIB_BITMASK_UTILS

#ifndef CANLIB_UNUSED
#define CANLIB_UNUSED(expr) do { (void)(expr); } while (0)
#endif // CANLIB_UNUSED

#ifndef CANLIB_INTERVAL_THRESHOLD
#define CANLIB_INTERVAL_THRESHOLD 500
#endif // CANLIB_INTERVAL_THRESHOLD



#define INVERTERS_INDEX_INV_L_SEND 0
#define INVERTERS_INDEX_INV_L_RCV 1
#define INVERTERS_INDEX_INV_R_SEND 2
#define INVERTERS_INDEX_INV_R_RCV 3



typedef struct {
    uint8_t activated[1];
    uint8_t timeout[1];
    canlib_watchdog_timestamp last_reset[4];
} inverters_watchdog;


inverters_watchdog* inverters_watchdog_new();
void inverters_watchdog_free(inverters_watchdog *watchdog);
void inverters_watchdog_reset(inverters_watchdog *watchdog, canlib_message_id id, canlib_watchdog_timestamp timestamp);
void inverters_watchdog_reset_all(inverters_watchdog *watchdog, canlib_watchdog_timestamp timestamp);
void inverters_watchdog_timeout(inverters_watchdog *watchdog, canlib_watchdog_timestamp timestamp);

static int inverters_watchdog_interval_from_id(uint16_t message_id) {
    switch (message_id) {

    }
    return -1;
}

static int inverters_watchdog_index_from_id(uint16_t message_id) {
    switch (message_id) {
       case 513: return INVERTERS_INDEX_INV_L_SEND;
       case 385: return INVERTERS_INDEX_INV_L_RCV;
       case 314: return INVERTERS_INDEX_INV_R_SEND;
       case 386: return INVERTERS_INDEX_INV_R_RCV;

    }
    return -1;
}
#ifdef primary_WATCHDOG_IMPLEMENTATION

inverters_watchdog* inverters_watchdog_new() {
    inverters_watchdog *watchdog = (inverters_watchdog*)malloc(sizeof(inverters_watchdog));
    if (watchdog == NULL) {
        return NULL;
    }
    memset(watchdog->activated, 0, sizeof(watchdog->activated));
    memset(watchdog->timeout, 0, sizeof(watchdog->timeout));
    memset(watchdog->last_reset, 0, sizeof(watchdog->last_reset));
    return watchdog;
}

void inverters_watchdog_free(inverters_watchdog *watchdog) {
    free(watchdog);
}

void inverters_watchdog_reset(inverters_watchdog *watchdog, canlib_message_id id, canlib_watchdog_timestamp timestamp) {
    int index = inverters_watchdog_index_from_id(id);
    if (index < 4 && CANLIB_BITTEST_ARRAY(watchdog->activated, index)) {
        CANLIB_BITCLEAR_ARRAY(watchdog->timeout, index);
        watchdog->last_reset[index] = timestamp;
    }
}

void inverters_watchdog_reset_all(inverters_watchdog *watchdog, canlib_watchdog_timestamp timestamp) {
    memset(watchdog->timeout, 0, sizeof(watchdog->timeout));
    memset(watchdog->last_reset, timestamp, sizeof(watchdog->last_reset));
}
void inverters_watchdog_timeout(inverters_watchdog *watchdog, canlib_watchdog_timestamp timestamp) {

}
#endif // primary_WATCHDOG_IMPLEMENTATION



#ifdef __cplusplus
}
#endif

#endif // inverters_NETWORK_H
