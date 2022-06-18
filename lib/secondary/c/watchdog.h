#ifndef secondary_WATCHDOG_H
#define secondary_WATCHDOG_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdlib.h>
#include <memory.h>

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


#define secondary_WATCHDOG_INDEX_IMU_ANGULAR_RATE 0
#define secondary_WATCHDOG_INDEX_IMU_ACCELERATION 1
#define secondary_WATCHDOG_INDEX_IRTS_FL_0 2
#define secondary_WATCHDOG_INDEX_IRTS_FL_1 3
#define secondary_WATCHDOG_INDEX_IRTS_FL_2 4
#define secondary_WATCHDOG_INDEX_IRTS_FL_3 5
#define secondary_WATCHDOG_INDEX_IRTS_FR_0 6
#define secondary_WATCHDOG_INDEX_IRTS_FR_1 7
#define secondary_WATCHDOG_INDEX_IRTS_FR_2 8
#define secondary_WATCHDOG_INDEX_IRTS_FR_3 9
#define secondary_WATCHDOG_INDEX_IRTS_RL_0 10
#define secondary_WATCHDOG_INDEX_IRTS_RL_1 11
#define secondary_WATCHDOG_INDEX_IRTS_RL_2 12
#define secondary_WATCHDOG_INDEX_IRTS_RL_3 13
#define secondary_WATCHDOG_INDEX_IRTS_RR_0 14
#define secondary_WATCHDOG_INDEX_IRTS_RR_1 15
#define secondary_WATCHDOG_INDEX_IRTS_RR_2 16
#define secondary_WATCHDOG_INDEX_IRTS_RR_3 17
#define secondary_WATCHDOG_INDEX_GPS_COORDS 18
#define secondary_WATCHDOG_INDEX_GPS_SPEED 19
#define secondary_WATCHDOG_INDEX_LAP_COUNT 20
#define secondary_WATCHDOG_INDEX_PEDALS_OUTPUT 21
#define secondary_WATCHDOG_INDEX_CONTROL_OUTPUT 22
#define secondary_WATCHDOG_INDEX_STEERING_ANGLE 23


#define secondary_INTERVAL_IMU_ANGULAR_RATE -1
#define secondary_INTERVAL_IMU_ACCELERATION -1
#define secondary_INTERVAL_IRTS_FL_0 -1
#define secondary_INTERVAL_IRTS_FL_1 -1
#define secondary_INTERVAL_IRTS_FL_2 -1
#define secondary_INTERVAL_IRTS_FL_3 -1
#define secondary_INTERVAL_IRTS_FR_0 -1
#define secondary_INTERVAL_IRTS_FR_1 -1
#define secondary_INTERVAL_IRTS_FR_2 -1
#define secondary_INTERVAL_IRTS_FR_3 -1
#define secondary_INTERVAL_IRTS_RL_0 -1
#define secondary_INTERVAL_IRTS_RL_1 -1
#define secondary_INTERVAL_IRTS_RL_2 -1
#define secondary_INTERVAL_IRTS_RL_3 -1
#define secondary_INTERVAL_IRTS_RR_0 -1
#define secondary_INTERVAL_IRTS_RR_1 -1
#define secondary_INTERVAL_IRTS_RR_2 -1
#define secondary_INTERVAL_IRTS_RR_3 -1
#define secondary_INTERVAL_GPS_COORDS -1
#define secondary_INTERVAL_GPS_SPEED -1
#define secondary_INTERVAL_LAP_COUNT -1
#define secondary_INTERVAL_PEDALS_OUTPUT 100
#define secondary_INTERVAL_CONTROL_OUTPUT 100
#define secondary_INTERVAL_STEERING_ANGLE 100

// Messages with this interval will be ignored by the watchdog as they are not
// expected to be sent regularly.
#define secondary_INTERVAL_ONCE -1

typedef struct {
    uint8_t activated[3];
    uint8_t timeout[3];
    canlib_watchdog_timestamp last_reset[24];
} secondary_watchdog;

static inline int secondary_watchdog_index_from_id(canlib_message_id id);
static inline int secondary_watchdog_interval_from_id(uint16_t message_id);

secondary_watchdog* secondary_watchdog_new();
void secondary_watchdog_free(secondary_watchdog *watchdog);
void secondary_watchdog_reset(secondary_watchdog *watchdog, canlib_message_id id, canlib_watchdog_timestamp timestamp);
void secondary_watchdog_reset_all(secondary_watchdog *watchdog, canlib_watchdog_timestamp timestamp);
void secondary_watchdog_timeout(secondary_watchdog *watchdog, canlib_watchdog_timestamp timestamp);

#ifdef secondary_WATCHDOG_IMPLEMENTATION

static inline int secondary_watchdog_interval_from_id(uint16_t message_id) {
    switch (message_id) {
        case 1260: return secondary_INTERVAL_IMU_ANGULAR_RATE;
        case 1261: return secondary_INTERVAL_IMU_ACCELERATION;
        case 1460: return secondary_INTERVAL_IRTS_FL_0;
        case 1461: return secondary_INTERVAL_IRTS_FL_1;
        case 1462: return secondary_INTERVAL_IRTS_FL_2;
        case 1463: return secondary_INTERVAL_IRTS_FL_3;
        case 1464: return secondary_INTERVAL_IRTS_FR_0;
        case 1465: return secondary_INTERVAL_IRTS_FR_1;
        case 1466: return secondary_INTERVAL_IRTS_FR_2;
        case 1467: return secondary_INTERVAL_IRTS_FR_3;
        case 1468: return secondary_INTERVAL_IRTS_RL_0;
        case 1469: return secondary_INTERVAL_IRTS_RL_1;
        case 1470: return secondary_INTERVAL_IRTS_RL_2;
        case 1471: return secondary_INTERVAL_IRTS_RL_3;
        case 1472: return secondary_INTERVAL_IRTS_RR_0;
        case 1473: return secondary_INTERVAL_IRTS_RR_1;
        case 1474: return secondary_INTERVAL_IRTS_RR_2;
        case 1475: return secondary_INTERVAL_IRTS_RR_3;
        case 1025: return secondary_INTERVAL_GPS_COORDS;
        case 1057: return secondary_INTERVAL_GPS_SPEED;
        case 1089: return secondary_INTERVAL_LAP_COUNT;
        case 769: return secondary_INTERVAL_PEDALS_OUTPUT;
        case 801: return secondary_INTERVAL_CONTROL_OUTPUT;
        case 258: return secondary_INTERVAL_STEERING_ANGLE;
    }
    return -1;
}

static inline int secondary_watchdog_index_from_id(canlib_message_id id) {
    switch (id) {
        case 1260: return secondary_WATCHDOG_INDEX_IMU_ANGULAR_RATE;
        case 1261: return secondary_WATCHDOG_INDEX_IMU_ACCELERATION;
        case 1460: return secondary_WATCHDOG_INDEX_IRTS_FL_0;
        case 1461: return secondary_WATCHDOG_INDEX_IRTS_FL_1;
        case 1462: return secondary_WATCHDOG_INDEX_IRTS_FL_2;
        case 1463: return secondary_WATCHDOG_INDEX_IRTS_FL_3;
        case 1464: return secondary_WATCHDOG_INDEX_IRTS_FR_0;
        case 1465: return secondary_WATCHDOG_INDEX_IRTS_FR_1;
        case 1466: return secondary_WATCHDOG_INDEX_IRTS_FR_2;
        case 1467: return secondary_WATCHDOG_INDEX_IRTS_FR_3;
        case 1468: return secondary_WATCHDOG_INDEX_IRTS_RL_0;
        case 1469: return secondary_WATCHDOG_INDEX_IRTS_RL_1;
        case 1470: return secondary_WATCHDOG_INDEX_IRTS_RL_2;
        case 1471: return secondary_WATCHDOG_INDEX_IRTS_RL_3;
        case 1472: return secondary_WATCHDOG_INDEX_IRTS_RR_0;
        case 1473: return secondary_WATCHDOG_INDEX_IRTS_RR_1;
        case 1474: return secondary_WATCHDOG_INDEX_IRTS_RR_2;
        case 1475: return secondary_WATCHDOG_INDEX_IRTS_RR_3;
        case 1025: return secondary_WATCHDOG_INDEX_GPS_COORDS;
        case 1057: return secondary_WATCHDOG_INDEX_GPS_SPEED;
        case 1089: return secondary_WATCHDOG_INDEX_LAP_COUNT;
        case 769: return secondary_WATCHDOG_INDEX_PEDALS_OUTPUT;
        case 801: return secondary_WATCHDOG_INDEX_CONTROL_OUTPUT;
        case 258: return secondary_WATCHDOG_INDEX_STEERING_ANGLE;
    }
    return 24; // invalid
}

secondary_watchdog* secondary_watchdog_new() {
    secondary_watchdog *watchdog = (secondary_watchdog*)malloc(sizeof(secondary_watchdog));
    if (watchdog == NULL) {
        return NULL;
    }
    memset(watchdog->activated, 0, sizeof(watchdog->activated));
    memset(watchdog->timeout, 0, sizeof(watchdog->timeout));
    memset(watchdog->last_reset, 0, sizeof(watchdog->last_reset));
    return watchdog;
}


void secondary_watchdog_free(secondary_watchdog *watchdog) {
    free(watchdog);
}

void secondary_watchdog_reset(secondary_watchdog *watchdog, canlib_message_id id, canlib_watchdog_timestamp timestamp) {
    int index = secondary_watchdog_index_from_id(id);
    if (index < 24 && CANLIB_BITTEST_ARRAY(watchdog->activated, index)) {
        CANLIB_BITCLEAR_ARRAY(watchdog->timeout, index);
        watchdog->last_reset[index] = timestamp;
    }
}

void secondary_watchdog_reset_all(secondary_watchdog *watchdog, canlib_watchdog_timestamp timestamp) {
    memset(watchdog->timeout, 0, sizeof(watchdog->timeout));
    memset(watchdog->last_reset, timestamp, sizeof(watchdog->last_reset));
}

void secondary_watchdog_timeout(secondary_watchdog *watchdog, canlib_watchdog_timestamp timestamp) {
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, secondary_WATCHDOG_INDEX_PEDALS_OUTPUT)
        && timestamp - watchdog->last_reset[secondary_WATCHDOG_INDEX_PEDALS_OUTPUT] > secondary_INTERVAL_PEDALS_OUTPUT
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, secondary_WATCHDOG_INDEX_PEDALS_OUTPUT);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, secondary_WATCHDOG_INDEX_CONTROL_OUTPUT)
        && timestamp - watchdog->last_reset[secondary_WATCHDOG_INDEX_CONTROL_OUTPUT] > secondary_INTERVAL_CONTROL_OUTPUT
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, secondary_WATCHDOG_INDEX_CONTROL_OUTPUT);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, secondary_WATCHDOG_INDEX_STEERING_ANGLE)
        && timestamp - watchdog->last_reset[secondary_WATCHDOG_INDEX_STEERING_ANGLE] > secondary_INTERVAL_STEERING_ANGLE
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, secondary_WATCHDOG_INDEX_STEERING_ANGLE);
    }
}
void secondary_watchdog_timeout_100(secondary_watchdog *watchdog, canlib_watchdog_timestamp timestamp) {
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, secondary_WATCHDOG_INDEX_PEDALS_OUTPUT)
        && timestamp - watchdog->last_reset[secondary_WATCHDOG_INDEX_PEDALS_OUTPUT] > secondary_INTERVAL_PEDALS_OUTPUT
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, secondary_WATCHDOG_INDEX_PEDALS_OUTPUT);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, secondary_WATCHDOG_INDEX_CONTROL_OUTPUT)
        && timestamp - watchdog->last_reset[secondary_WATCHDOG_INDEX_CONTROL_OUTPUT] > secondary_INTERVAL_CONTROL_OUTPUT
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, secondary_WATCHDOG_INDEX_CONTROL_OUTPUT);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, secondary_WATCHDOG_INDEX_STEERING_ANGLE)
        && timestamp - watchdog->last_reset[secondary_WATCHDOG_INDEX_STEERING_ANGLE] > secondary_INTERVAL_STEERING_ANGLE
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, secondary_WATCHDOG_INDEX_STEERING_ANGLE);
    }
}

void secondary_watchdog_timeout_1000(secondary_watchdog *watchdog, canlib_watchdog_timestamp timestamp) {
    // no messages in this interval
    CANLIB_UNUSED(watchdog);
    CANLIB_UNUSED(timestamp);
}

void secondary_watchdog_timeout_5000(secondary_watchdog *watchdog, canlib_watchdog_timestamp timestamp) {
    // no messages in this interval
    CANLIB_UNUSED(watchdog);
    CANLIB_UNUSED(timestamp);
}

void secondary_watchdog_timeout_10(secondary_watchdog *watchdog, canlib_watchdog_timestamp timestamp) {
    // no messages in this interval
    CANLIB_UNUSED(watchdog);
    CANLIB_UNUSED(timestamp);
}

void secondary_watchdog_timeout_50(secondary_watchdog *watchdog, canlib_watchdog_timestamp timestamp) {
    // no messages in this interval
    CANLIB_UNUSED(watchdog);
    CANLIB_UNUSED(timestamp);
}

void secondary_watchdog_timeout_500(secondary_watchdog *watchdog, canlib_watchdog_timestamp timestamp) {
    // no messages in this interval
    CANLIB_UNUSED(watchdog);
    CANLIB_UNUSED(timestamp);
}



#endif // secondary_WATCHDOG_IMPLEMENTATION

#ifdef __cplusplus
}
#endif

#endif // secondary_NETWORK_H