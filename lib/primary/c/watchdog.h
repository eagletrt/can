#ifndef primary_WATCHDOG_H
#define primary_WATCHDOG_H

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


#define primary_watchdog_index_STEER_VERSION 0
#define primary_watchdog_index_DAS_VERSION 1
#define primary_watchdog_index_HV_VERSION 2
#define primary_watchdog_index_LV_VERSION 3
#define primary_watchdog_index_TLM_VERSION 4
#define primary_watchdog_index_TIMESTAMP 5
#define primary_watchdog_index_SET_TLM_STATUS 6
#define primary_watchdog_index_TLM_STATUS 7
#define primary_watchdog_index_STEER_SYSTEM_STATUS 8
#define primary_watchdog_index_HV_VOLTAGE 9
#define primary_watchdog_index_HV_CURRENT 10
#define primary_watchdog_index_HV_TEMP 11
#define primary_watchdog_index_HV_ERRORS 12
#define primary_watchdog_index_HV_CAN_FORWARD 13
#define primary_watchdog_index_HV_CAN_FORWARD_STATUS 14
#define primary_watchdog_index_TS_STATUS 15
#define primary_watchdog_index_SET_TS_STATUS_DAS 16
#define primary_watchdog_index_SET_TS_STATUS_HANDCART 17
#define primary_watchdog_index_STEER_STATUS 18
#define primary_watchdog_index_SET_CAR_STATUS 19
#define primary_watchdog_index_SET_PEDALS_RANGE 20
#define primary_watchdog_index_SET_STEERING_ANGLE_RANGE 21
#define primary_watchdog_index_CAR_STATUS 22
#define primary_watchdog_index_DAS_ERRORS 23
#define primary_watchdog_index_LV_CURRENT 24
#define primary_watchdog_index_LV_VOLTAGE 25
#define primary_watchdog_index_LV_TOTAL_VOLTAGE 26
#define primary_watchdog_index_LV_TEMPERATURE 27
#define primary_watchdog_index_COOLING_STATUS 28
#define primary_watchdog_index_SET_RADIATOR_SPEED 29
#define primary_watchdog_index_SET_PUMPS_POWER 30
#define primary_watchdog_index_MARKER 31
#define primary_watchdog_index_HV_CELLS_VOLTAGE 32
#define primary_watchdog_index_HV_CELLS_TEMP 33
#define primary_watchdog_index_HV_CELL_BALANCING_STATUS 34
#define primary_watchdog_index_SET_CELL_BALANCING_STATUS 35
#define primary_watchdog_index_HANDCART_STATUS 36
#define primary_watchdog_index_SPEED 37
#define primary_watchdog_index_INV_L_SET_TORQUE 38
#define primary_watchdog_index_INV_L_RESPONSE 39


#define primary_STEER_VERSION_INTERVAL 1000
#define primary_DAS_VERSION_INTERVAL 1000
#define primary_HV_VERSION_INTERVAL 1000
#define primary_LV_VERSION_INTERVAL 1000
#define primary_TLM_VERSION_INTERVAL 1000
#define primary_TIMESTAMP_INTERVAL 1000
#define primary_SET_TLM_STATUS_INTERVAL -1
#define primary_TLM_STATUS_INTERVAL 1000
#define primary_STEER_SYSTEM_STATUS_INTERVAL 2000
#define primary_HV_VOLTAGE_INTERVAL 20
#define primary_HV_CURRENT_INTERVAL 20
#define primary_HV_TEMP_INTERVAL 200
#define primary_HV_ERRORS_INTERVAL 20
#define primary_HV_CAN_FORWARD_INTERVAL -1
#define primary_HV_CAN_FORWARD_STATUS_INTERVAL -1
#define primary_TS_STATUS_INTERVAL 20
#define primary_SET_TS_STATUS_INTERVAL -1
#define primary_STEER_STATUS_INTERVAL 100
#define primary_SET_CAR_STATUS_INTERVAL -1
#define primary_SET_PEDALS_RANGE_INTERVAL -1
#define primary_SET_STEERING_ANGLE_RANGE_INTERVAL -1
#define primary_CAR_STATUS_INTERVAL 100
#define primary_DAS_ERRORS_INTERVAL 20
#define primary_LV_CURRENT_INTERVAL 500
#define primary_LV_VOLTAGE_INTERVAL 200
#define primary_LV_TOTAL_VOLTAGE_INTERVAL 200
#define primary_LV_TEMPERATURE_INTERVAL 100
#define primary_COOLING_STATUS_INTERVAL 1000
#define primary_SET_RADIATOR_SPEED_INTERVAL -1
#define primary_SET_PUMPS_POWER_INTERVAL -1
#define primary_MARKER_INTERVAL -1
#define primary_HV_CELLS_VOLTAGE_INTERVAL 200
#define primary_HV_CELLS_TEMP_INTERVAL 100
#define primary_HV_CELL_BALANCING_STATUS_INTERVAL 500
#define primary_SET_CELL_BALANCING_STATUS_INTERVAL -1
#define primary_HANDCART_STATUS_INTERVAL 500
#define primary_SPEED_INTERVAL 100
#define primary_INV_L_SET_TORQUE_INTERVAL 20
#define primary_INV_L_RESPONSE_INTERVAL 100

// Messages with this interval will be ignored by the watchdog as they are not
// expected to be sent regularly.
#define primary_INTERVAL_ONCE -1

typedef struct {
    uint8_t activated[5];
    uint8_t timeout[5];
    canlib_watchdog_timestamp last_reset[40];
} primary_watchdog;

int primary_watchdog_index_from_id(canlib_message_id id);

primary_watchdog* primary_watchdog_new();
void primary_watchdog_reset(primary_watchdog *watchdog, canlib_message_id id, canlib_watchdog_timestamp timestamp);
void primary_watchdog_reset_all(primary_watchdog *watchdog, canlib_watchdog_timestamp timestamp);
void primary_watchdog_timeout(primary_watchdog *watchdog, canlib_watchdog_timestamp timestamp);

#ifdef primary_WATCHDOG_IMPLEMENTATION

int primary_watchdog_index_from_id(canlib_message_id id) {
    switch (id) {
        case 1024: return primary_watchdog_index_STEER_VERSION;
        case 1056: return primary_watchdog_index_DAS_VERSION;
        case 1088: return primary_watchdog_index_HV_VERSION;
        case 1120: return primary_watchdog_index_LV_VERSION;
        case 1152: return primary_watchdog_index_TLM_VERSION;
        case 256: return primary_watchdog_index_TIMESTAMP;
        case 257: return primary_watchdog_index_SET_TLM_STATUS;
        case 258: return primary_watchdog_index_TLM_STATUS;
        case 1793: return primary_watchdog_index_STEER_SYSTEM_STATUS;
        case 771: return primary_watchdog_index_HV_VOLTAGE;
        case 803: return primary_watchdog_index_HV_CURRENT;
        case 835: return primary_watchdog_index_HV_TEMP;
        case 3: return primary_watchdog_index_HV_ERRORS;
        case 4: return primary_watchdog_index_HV_CAN_FORWARD;
        case 5: return primary_watchdog_index_HV_CAN_FORWARD_STATUS;
        case 35: return primary_watchdog_index_TS_STATUS;
        case 36: return primary_watchdog_index_SET_TS_STATUS_DAS;
        case 68: return primary_watchdog_index_SET_TS_STATUS_HANDCART;
        case 262: return primary_watchdog_index_STEER_STATUS;
        case 774: return primary_watchdog_index_SET_CAR_STATUS;
        case 1030: return primary_watchdog_index_SET_PEDALS_RANGE;
        case 1062: return primary_watchdog_index_SET_STEERING_ANGLE_RANGE;
        case 514: return primary_watchdog_index_CAR_STATUS;
        case 2: return primary_watchdog_index_DAS_ERRORS;
        case 775: return primary_watchdog_index_LV_CURRENT;
        case 807: return primary_watchdog_index_LV_VOLTAGE;
        case 839: return primary_watchdog_index_LV_TOTAL_VOLTAGE;
        case 871: return primary_watchdog_index_LV_TEMPERATURE;
        case 903: return primary_watchdog_index_COOLING_STATUS;
        case 776: return primary_watchdog_index_SET_RADIATOR_SPEED;
        case 808: return primary_watchdog_index_SET_PUMPS_POWER;
        case 1: return primary_watchdog_index_MARKER;
        case 517: return primary_watchdog_index_HV_CELLS_VOLTAGE;
        case 549: return primary_watchdog_index_HV_CELLS_TEMP;
        case 581: return primary_watchdog_index_HV_CELL_BALANCING_STATUS;
        case 516: return primary_watchdog_index_SET_CELL_BALANCING_STATUS;
        case 772: return primary_watchdog_index_HANDCART_STATUS;
        case 546: return primary_watchdog_index_SPEED;
        case 513: return primary_watchdog_index_INV_L_SET_TORQUE;
        case 385: return primary_watchdog_index_INV_L_RESPONSE;
    }
    return 40; // invalid
}

primary_watchdog* primary_watchdog_new() {
    primary_watchdog *watchdog = (primary_watchdog*)malloc(sizeof(primary_watchdog));
    if (watchdog == NULL) {
        return NULL;
    }
    memset(watchdog->activated, 0, sizeof(watchdog->activated));
    memset(watchdog->timeout, 0, sizeof(watchdog->timeout));
    memset(watchdog->last_reset, 0, sizeof(watchdog->last_reset));
    return watchdog;
}

void primary_watchdog_reset(primary_watchdog *watchdog, canlib_message_id id, canlib_watchdog_timestamp timestamp) {
    int index = primary_watchdog_index_from_id(id);
    if (index < 40 && CANLIB_BITTEST_ARRAY(watchdog->activated, index)) {
        CANLIB_BITCLEAR_ARRAY(watchdog->timeout, index);
        watchdog->last_reset[index] = timestamp;
    }
}

void primary_watchdog_reset_all(primary_watchdog *watchdog, canlib_watchdog_timestamp timestamp) {
    memset(watchdog->timeout, 0, sizeof(watchdog->timeout));
    memset(watchdog->last_reset, timestamp, sizeof(watchdog->last_reset));
}

void primary_watchdog_timeout(primary_watchdog *watchdog, canlib_watchdog_timestamp timestamp) {
    memset(watchdog->timeout, 0, sizeof(watchdog->timeout));
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_watchdog_index_STEER_VERSION)
        && timestamp - watchdog->last_reset[primary_watchdog_index_STEER_VERSION] > primary_STEER_VERSION_INTERVAL
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_watchdog_index_STEER_VERSION);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_watchdog_index_DAS_VERSION)
        && timestamp - watchdog->last_reset[primary_watchdog_index_DAS_VERSION] > primary_DAS_VERSION_INTERVAL
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_watchdog_index_DAS_VERSION);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_watchdog_index_HV_VERSION)
        && timestamp - watchdog->last_reset[primary_watchdog_index_HV_VERSION] > primary_HV_VERSION_INTERVAL
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_watchdog_index_HV_VERSION);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_watchdog_index_LV_VERSION)
        && timestamp - watchdog->last_reset[primary_watchdog_index_LV_VERSION] > primary_LV_VERSION_INTERVAL
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_watchdog_index_LV_VERSION);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_watchdog_index_TLM_VERSION)
        && timestamp - watchdog->last_reset[primary_watchdog_index_TLM_VERSION] > primary_TLM_VERSION_INTERVAL
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_watchdog_index_TLM_VERSION);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_watchdog_index_TIMESTAMP)
        && timestamp - watchdog->last_reset[primary_watchdog_index_TIMESTAMP] > primary_TIMESTAMP_INTERVAL
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_watchdog_index_TIMESTAMP);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_watchdog_index_TLM_STATUS)
        && timestamp - watchdog->last_reset[primary_watchdog_index_TLM_STATUS] > primary_TLM_STATUS_INTERVAL
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_watchdog_index_TLM_STATUS);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_watchdog_index_STEER_SYSTEM_STATUS)
        && timestamp - watchdog->last_reset[primary_watchdog_index_STEER_SYSTEM_STATUS] > primary_STEER_SYSTEM_STATUS_INTERVAL
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_watchdog_index_STEER_SYSTEM_STATUS);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_watchdog_index_HV_VOLTAGE)
        && timestamp - watchdog->last_reset[primary_watchdog_index_HV_VOLTAGE] > primary_HV_VOLTAGE_INTERVAL
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_watchdog_index_HV_VOLTAGE);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_watchdog_index_HV_CURRENT)
        && timestamp - watchdog->last_reset[primary_watchdog_index_HV_CURRENT] > primary_HV_CURRENT_INTERVAL
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_watchdog_index_HV_CURRENT);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_watchdog_index_HV_TEMP)
        && timestamp - watchdog->last_reset[primary_watchdog_index_HV_TEMP] > primary_HV_TEMP_INTERVAL
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_watchdog_index_HV_TEMP);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_watchdog_index_HV_ERRORS)
        && timestamp - watchdog->last_reset[primary_watchdog_index_HV_ERRORS] > primary_HV_ERRORS_INTERVAL
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_watchdog_index_HV_ERRORS);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_watchdog_index_TS_STATUS)
        && timestamp - watchdog->last_reset[primary_watchdog_index_TS_STATUS] > primary_TS_STATUS_INTERVAL
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_watchdog_index_TS_STATUS);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_watchdog_index_STEER_STATUS)
        && timestamp - watchdog->last_reset[primary_watchdog_index_STEER_STATUS] > primary_STEER_STATUS_INTERVAL
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_watchdog_index_STEER_STATUS);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_watchdog_index_CAR_STATUS)
        && timestamp - watchdog->last_reset[primary_watchdog_index_CAR_STATUS] > primary_CAR_STATUS_INTERVAL
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_watchdog_index_CAR_STATUS);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_watchdog_index_DAS_ERRORS)
        && timestamp - watchdog->last_reset[primary_watchdog_index_DAS_ERRORS] > primary_DAS_ERRORS_INTERVAL
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_watchdog_index_DAS_ERRORS);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_watchdog_index_LV_CURRENT)
        && timestamp - watchdog->last_reset[primary_watchdog_index_LV_CURRENT] > primary_LV_CURRENT_INTERVAL
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_watchdog_index_LV_CURRENT);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_watchdog_index_LV_VOLTAGE)
        && timestamp - watchdog->last_reset[primary_watchdog_index_LV_VOLTAGE] > primary_LV_VOLTAGE_INTERVAL
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_watchdog_index_LV_VOLTAGE);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_watchdog_index_LV_TOTAL_VOLTAGE)
        && timestamp - watchdog->last_reset[primary_watchdog_index_LV_TOTAL_VOLTAGE] > primary_LV_TOTAL_VOLTAGE_INTERVAL
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_watchdog_index_LV_TOTAL_VOLTAGE);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_watchdog_index_LV_TEMPERATURE)
        && timestamp - watchdog->last_reset[primary_watchdog_index_LV_TEMPERATURE] > primary_LV_TEMPERATURE_INTERVAL
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_watchdog_index_LV_TEMPERATURE);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_watchdog_index_COOLING_STATUS)
        && timestamp - watchdog->last_reset[primary_watchdog_index_COOLING_STATUS] > primary_COOLING_STATUS_INTERVAL
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_watchdog_index_COOLING_STATUS);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_watchdog_index_HV_CELLS_VOLTAGE)
        && timestamp - watchdog->last_reset[primary_watchdog_index_HV_CELLS_VOLTAGE] > primary_HV_CELLS_VOLTAGE_INTERVAL
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_watchdog_index_HV_CELLS_VOLTAGE);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_watchdog_index_HV_CELLS_TEMP)
        && timestamp - watchdog->last_reset[primary_watchdog_index_HV_CELLS_TEMP] > primary_HV_CELLS_TEMP_INTERVAL
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_watchdog_index_HV_CELLS_TEMP);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_watchdog_index_HV_CELL_BALANCING_STATUS)
        && timestamp - watchdog->last_reset[primary_watchdog_index_HV_CELL_BALANCING_STATUS] > primary_HV_CELL_BALANCING_STATUS_INTERVAL
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_watchdog_index_HV_CELL_BALANCING_STATUS);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_watchdog_index_HANDCART_STATUS)
        && timestamp - watchdog->last_reset[primary_watchdog_index_HANDCART_STATUS] > primary_HANDCART_STATUS_INTERVAL
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_watchdog_index_HANDCART_STATUS);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_watchdog_index_SPEED)
        && timestamp - watchdog->last_reset[primary_watchdog_index_SPEED] > primary_SPEED_INTERVAL
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_watchdog_index_SPEED);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_watchdog_index_INV_L_SET_TORQUE)
        && timestamp - watchdog->last_reset[primary_watchdog_index_INV_L_SET_TORQUE] > primary_INV_L_SET_TORQUE_INTERVAL
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_watchdog_index_INV_L_SET_TORQUE);
    }
    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, primary_watchdog_index_INV_L_RESPONSE)
        && timestamp - watchdog->last_reset[primary_watchdog_index_INV_L_RESPONSE] > primary_INV_L_RESPONSE_INTERVAL
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, primary_watchdog_index_INV_L_RESPONSE);
    }
}

#endif // primary_WATCHDOG_IMPLEMENTATION

#ifdef __cplusplus
}
#endif

#endif // primary_NETWORK_H