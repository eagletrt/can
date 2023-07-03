#ifndef secondary_WATCHDOG_H
#define secondary_WATCHDOG_H

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

#define SECONDARY_INTERVAL_PEDALS_OUTPUT 10
#define SECONDARY_INTERVAL_STEERING_ANGLE 10
#define SECONDARY_INTERVAL_CONTROL_STATE 100


#define SECONDARY_INDEX_IMU_ANGULAR_RATE 0
#define SECONDARY_INDEX_IMU_ACCELERATION 1
#define SECONDARY_INDEX_IRTS_FL_0 2
#define SECONDARY_INDEX_IRTS_FL_1 3
#define SECONDARY_INDEX_IRTS_FL_2 4
#define SECONDARY_INDEX_IRTS_FL_3 5
#define SECONDARY_INDEX_IRTS_FR_0 6
#define SECONDARY_INDEX_IRTS_FR_1 7
#define SECONDARY_INDEX_IRTS_FR_2 8
#define SECONDARY_INDEX_IRTS_FR_3 9
#define SECONDARY_INDEX_IRTS_RL_0 10
#define SECONDARY_INDEX_IRTS_RL_1 11
#define SECONDARY_INDEX_IRTS_RL_2 12
#define SECONDARY_INDEX_IRTS_RL_3 13
#define SECONDARY_INDEX_IRTS_RR_0 14
#define SECONDARY_INDEX_IRTS_RR_1 15
#define SECONDARY_INDEX_IRTS_RR_2 16
#define SECONDARY_INDEX_IRTS_RR_3 17
#define SECONDARY_INDEX_GPS_COORDS 18
#define SECONDARY_INDEX_GPS_SPEED 19
#define SECONDARY_INDEX_LAP_COUNT 20
#define SECONDARY_INDEX_PEDALS_OUTPUT 21
#define SECONDARY_INDEX_STEERING_ANGLE 22
#define SECONDARY_INDEX_CONTROL_STATE 23
#define SECONDARY_INDEX_TPMS 24
#define SECONDARY_INDEX_LC_STATUS 25



typedef struct {
    uint8_t activated[4];
    uint8_t timeout[4];
    canlib_watchdog_timestamp last_reset[26];
} secondary_watchdog;


secondary_watchdog* secondary_watchdog_new();
void secondary_watchdog_free(secondary_watchdog *watchdog);
void secondary_watchdog_reset(secondary_watchdog *watchdog, canlib_message_id id, canlib_watchdog_timestamp timestamp);
void secondary_watchdog_reset_all(secondary_watchdog *watchdog, canlib_watchdog_timestamp timestamp);
void secondary_watchdog_timeout(secondary_watchdog *watchdog, canlib_watchdog_timestamp timestamp);

static int secondary_watchdog_interval_from_id(uint16_t message_id) {
    switch (message_id) {
       case 770: return SECONDARY_INTERVAL_PEDALS_OUTPUT;
       case 259: return SECONDARY_INTERVAL_STEERING_ANGLE;
       case 1280: return SECONDARY_INTERVAL_CONTROL_STATE;

    }
    return -1;
}

static int secondary_watchdog_index_from_id(uint16_t message_id) {
    switch (message_id) {
       case 1260: return SECONDARY_INDEX_IMU_ANGULAR_RATE;
       case 1261: return SECONDARY_INDEX_IMU_ACCELERATION;
       case 1460: return SECONDARY_INDEX_IRTS_FL_0;
       case 1461: return SECONDARY_INDEX_IRTS_FL_1;
       case 1462: return SECONDARY_INDEX_IRTS_FL_2;
       case 1463: return SECONDARY_INDEX_IRTS_FL_3;
       case 1464: return SECONDARY_INDEX_IRTS_FR_0;
       case 1465: return SECONDARY_INDEX_IRTS_FR_1;
       case 1466: return SECONDARY_INDEX_IRTS_FR_2;
       case 1467: return SECONDARY_INDEX_IRTS_FR_3;
       case 1468: return SECONDARY_INDEX_IRTS_RL_0;
       case 1469: return SECONDARY_INDEX_IRTS_RL_1;
       case 1470: return SECONDARY_INDEX_IRTS_RL_2;
       case 1471: return SECONDARY_INDEX_IRTS_RL_3;
       case 1472: return SECONDARY_INDEX_IRTS_RR_0;
       case 1473: return SECONDARY_INDEX_IRTS_RR_1;
       case 1474: return SECONDARY_INDEX_IRTS_RR_2;
       case 1475: return SECONDARY_INDEX_IRTS_RR_3;
       case 1026: return SECONDARY_INDEX_GPS_COORDS;
       case 1058: return SECONDARY_INDEX_GPS_SPEED;
       case 1090: return SECONDARY_INDEX_LAP_COUNT;
       case 770: return SECONDARY_INDEX_PEDALS_OUTPUT;
       case 259: return SECONDARY_INDEX_STEERING_ANGLE;
       case 1280: return SECONDARY_INDEX_CONTROL_STATE;
       case 514: return SECONDARY_INDEX_TPMS;
       case 769: return SECONDARY_INDEX_LC_STATUS;

    }
    return -1;
}
#ifdef secondary_WATCHDOG_IMPLEMENTATION

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
    if (index < 26 && CANLIB_BITTEST_ARRAY(watchdog->activated, index)) {
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
        CANLIB_BITTEST_ARRAY(watchdog->activated, SECONDARY_INDEX_PEDALS_OUTPUT)
        && timestamp - watchdog->last_reset[SECONDARY_INDEX_PEDALS_OUTPUT] > SECONDARY_INTERVAL_PEDALS_OUTPUT * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, SECONDARY_INDEX_PEDALS_OUTPUT);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, SECONDARY_INDEX_STEERING_ANGLE)
        && timestamp - watchdog->last_reset[SECONDARY_INDEX_STEERING_ANGLE] > SECONDARY_INTERVAL_STEERING_ANGLE * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, SECONDARY_INDEX_STEERING_ANGLE);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, SECONDARY_INDEX_CONTROL_STATE)
        && timestamp - watchdog->last_reset[SECONDARY_INDEX_CONTROL_STATE] > SECONDARY_INTERVAL_CONTROL_STATE * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, SECONDARY_INDEX_CONTROL_STATE);
    }

}
#endif // secondary_WATCHDOG_IMPLEMENTATION



#ifdef __cplusplus
}
#endif

#endif // secondary_NETWORK_H
