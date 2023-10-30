#include "simulator_watchdog.h"


int simulator_watchdog_interval_from_id(uint16_t message_id) {
    switch (message_id) {
       case 769: return SIMULATOR_INTERVAL_PEDALS;
       case 258: return SIMULATOR_INTERVAL_STEERING_ANGLE;
       case 1280: return SIMULATOR_INTERVAL_CONTROL_STATE;
       case 257: return SIMULATOR_INTERVAL_CONTROL_OUTPUT;
       case 513: return SIMULATOR_INTERVAL_SPEED;

    }
    return -1;
}

int simulator_watchdog_index_from_id(uint16_t message_id) {
    switch (message_id) {
       case 1260: return SIMULATOR_INDEX_ANGULAR_RATE;
       case 1261: return SIMULATOR_INDEX_ACCELERATION;
       case 769: return SIMULATOR_INDEX_PEDALS;
       case 258: return SIMULATOR_INDEX_STEERING_ANGLE;
       case 1280: return SIMULATOR_INDEX_CONTROL_STATE;
       case 257: return SIMULATOR_INDEX_CONTROL_OUTPUT;
       case 513: return SIMULATOR_INDEX_SPEED;

    }
    return -1;
}

void simulator_watchdog_free(simulator_watchdog *watchdog) {
    free(watchdog);
}

void simulator_watchdog_reset(simulator_watchdog *watchdog, canlib_message_id id, canlib_watchdog_timestamp timestamp) {
    int index = simulator_watchdog_index_from_id(id);
    if (index < 7 && CANLIB_BITTEST_ARRAY(watchdog->activated, index)) {
        CANLIB_BITCLEAR_ARRAY(watchdog->timeout, index);
        watchdog->last_reset[index] = timestamp;
    }
}

void simulator_watchdog_reset_all(simulator_watchdog *watchdog, canlib_watchdog_timestamp timestamp) {
    memset(watchdog->timeout, 0, sizeof(watchdog->timeout));
    memset(watchdog->last_reset, timestamp, sizeof(watchdog->last_reset));
}
void simulator_watchdog_timeout(simulator_watchdog *watchdog, canlib_watchdog_timestamp timestamp) {

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, SIMULATOR_INDEX_PEDALS)
        && timestamp - watchdog->last_reset[SIMULATOR_INDEX_PEDALS] > SIMULATOR_INTERVAL_PEDALS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, SIMULATOR_INDEX_PEDALS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, SIMULATOR_INDEX_STEERING_ANGLE)
        && timestamp - watchdog->last_reset[SIMULATOR_INDEX_STEERING_ANGLE] > SIMULATOR_INTERVAL_STEERING_ANGLE * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, SIMULATOR_INDEX_STEERING_ANGLE);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, SIMULATOR_INDEX_CONTROL_STATE)
        && timestamp - watchdog->last_reset[SIMULATOR_INDEX_CONTROL_STATE] > SIMULATOR_INTERVAL_CONTROL_STATE * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, SIMULATOR_INDEX_CONTROL_STATE);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, SIMULATOR_INDEX_CONTROL_OUTPUT)
        && timestamp - watchdog->last_reset[SIMULATOR_INDEX_CONTROL_OUTPUT] > SIMULATOR_INTERVAL_CONTROL_OUTPUT * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, SIMULATOR_INDEX_CONTROL_OUTPUT);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, SIMULATOR_INDEX_SPEED)
        && timestamp - watchdog->last_reset[SIMULATOR_INDEX_SPEED] > SIMULATOR_INTERVAL_SPEED * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, SIMULATOR_INDEX_SPEED);
    }

}


