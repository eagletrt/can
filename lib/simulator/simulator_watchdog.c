#include "simulator_watchdog.h"


int simulator_watchdog_interval_from_id(uint16_t message_id) {
    switch (message_id) {
       case 1536: return SIMULATOR_INTERVAL_PEDAL_THROTTLE;
       case 1544: return SIMULATOR_INTERVAL_PEDAL_BRAKES_PRESSURE;
       case 1552: return SIMULATOR_INTERVAL_STEER_ANGLE;
       case 512: return SIMULATOR_INTERVAL_CONTROL_OUTPUT;
       case 520: return SIMULATOR_INTERVAL_CONTROL_STATUS;
       case 1560: return SIMULATOR_INTERVAL_FRONT_ANGULAR_VELOCITY;
       case 1568: return SIMULATOR_INTERVAL_DEBUG_SIGNAL_2;
       case 1576: return SIMULATOR_INTERVAL_INV_L_RCV;
       case 1584: return SIMULATOR_INTERVAL_INV_R_RCV;
       case 1592: return SIMULATOR_INTERVAL_AS_COMMANDS_STATUS;
       case 1024: return SIMULATOR_INTERVAL_AS_COMMANDS_SET_STATUS;
       case 1600: return SIMULATOR_INTERVAL_AS_COMMANDS_SET_VALUE;
       case 1608: return SIMULATOR_INTERVAL_VEHICLE_POSITION;
       case 1616: return SIMULATOR_INTERVAL_VEHICLE_SPEED;

    }
    return -1;
}

int simulator_watchdog_index_from_id(uint16_t message_id) {
    switch (message_id) {
       case 1260: return SIMULATOR_INDEX_IMU_ANGULAR_RATE;
       case 1261: return SIMULATOR_INDEX_IMU_ACCELERATION;
       case 1536: return SIMULATOR_INDEX_PEDAL_THROTTLE;
       case 1544: return SIMULATOR_INDEX_PEDAL_BRAKES_PRESSURE;
       case 1552: return SIMULATOR_INDEX_STEER_ANGLE;
       case 512: return SIMULATOR_INDEX_CONTROL_OUTPUT;
       case 520: return SIMULATOR_INDEX_CONTROL_STATUS;
       case 1560: return SIMULATOR_INDEX_FRONT_ANGULAR_VELOCITY;
       case 1568: return SIMULATOR_INDEX_DEBUG_SIGNAL_2;
       case 1576: return SIMULATOR_INDEX_INV_L_RCV;
       case 1584: return SIMULATOR_INDEX_INV_R_RCV;
       case 1592: return SIMULATOR_INDEX_AS_COMMANDS_STATUS;
       case 1024: return SIMULATOR_INDEX_AS_COMMANDS_SET_STATUS;
       case 1600: return SIMULATOR_INDEX_AS_COMMANDS_SET_VALUE;
       case 1608: return SIMULATOR_INDEX_VEHICLE_POSITION;
       case 1616: return SIMULATOR_INDEX_VEHICLE_SPEED;

    }
    return -1;
}

void simulator_watchdog_free(simulator_watchdog *watchdog) {
    free(watchdog);
}

void simulator_watchdog_reset(simulator_watchdog *watchdog, canlib_message_id id, canlib_watchdog_timestamp timestamp) {
    int index = simulator_watchdog_index_from_id(id);
    if (index < 16 && CANLIB_BITTEST_ARRAY(watchdog->activated, index)) {
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
        CANLIB_BITTEST_ARRAY(watchdog->activated, SIMULATOR_INDEX_PEDAL_THROTTLE)
        && timestamp - watchdog->last_reset[SIMULATOR_INDEX_PEDAL_THROTTLE] > SIMULATOR_INTERVAL_PEDAL_THROTTLE * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, SIMULATOR_INDEX_PEDAL_THROTTLE);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, SIMULATOR_INDEX_PEDAL_BRAKES_PRESSURE)
        && timestamp - watchdog->last_reset[SIMULATOR_INDEX_PEDAL_BRAKES_PRESSURE] > SIMULATOR_INTERVAL_PEDAL_BRAKES_PRESSURE * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, SIMULATOR_INDEX_PEDAL_BRAKES_PRESSURE);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, SIMULATOR_INDEX_STEER_ANGLE)
        && timestamp - watchdog->last_reset[SIMULATOR_INDEX_STEER_ANGLE] > SIMULATOR_INTERVAL_STEER_ANGLE * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, SIMULATOR_INDEX_STEER_ANGLE);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, SIMULATOR_INDEX_CONTROL_OUTPUT)
        && timestamp - watchdog->last_reset[SIMULATOR_INDEX_CONTROL_OUTPUT] > SIMULATOR_INTERVAL_CONTROL_OUTPUT * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, SIMULATOR_INDEX_CONTROL_OUTPUT);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, SIMULATOR_INDEX_CONTROL_STATUS)
        && timestamp - watchdog->last_reset[SIMULATOR_INDEX_CONTROL_STATUS] > SIMULATOR_INTERVAL_CONTROL_STATUS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, SIMULATOR_INDEX_CONTROL_STATUS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, SIMULATOR_INDEX_FRONT_ANGULAR_VELOCITY)
        && timestamp - watchdog->last_reset[SIMULATOR_INDEX_FRONT_ANGULAR_VELOCITY] > SIMULATOR_INTERVAL_FRONT_ANGULAR_VELOCITY * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, SIMULATOR_INDEX_FRONT_ANGULAR_VELOCITY);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, SIMULATOR_INDEX_DEBUG_SIGNAL_2)
        && timestamp - watchdog->last_reset[SIMULATOR_INDEX_DEBUG_SIGNAL_2] > SIMULATOR_INTERVAL_DEBUG_SIGNAL_2 * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, SIMULATOR_INDEX_DEBUG_SIGNAL_2);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, SIMULATOR_INDEX_INV_L_RCV)
        && timestamp - watchdog->last_reset[SIMULATOR_INDEX_INV_L_RCV] > SIMULATOR_INTERVAL_INV_L_RCV * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, SIMULATOR_INDEX_INV_L_RCV);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, SIMULATOR_INDEX_INV_R_RCV)
        && timestamp - watchdog->last_reset[SIMULATOR_INDEX_INV_R_RCV] > SIMULATOR_INTERVAL_INV_R_RCV * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, SIMULATOR_INDEX_INV_R_RCV);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, SIMULATOR_INDEX_AS_COMMANDS_STATUS)
        && timestamp - watchdog->last_reset[SIMULATOR_INDEX_AS_COMMANDS_STATUS] > SIMULATOR_INTERVAL_AS_COMMANDS_STATUS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, SIMULATOR_INDEX_AS_COMMANDS_STATUS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, SIMULATOR_INDEX_AS_COMMANDS_SET_STATUS)
        && timestamp - watchdog->last_reset[SIMULATOR_INDEX_AS_COMMANDS_SET_STATUS] > SIMULATOR_INTERVAL_AS_COMMANDS_SET_STATUS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, SIMULATOR_INDEX_AS_COMMANDS_SET_STATUS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, SIMULATOR_INDEX_AS_COMMANDS_SET_VALUE)
        && timestamp - watchdog->last_reset[SIMULATOR_INDEX_AS_COMMANDS_SET_VALUE] > SIMULATOR_INTERVAL_AS_COMMANDS_SET_VALUE * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, SIMULATOR_INDEX_AS_COMMANDS_SET_VALUE);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, SIMULATOR_INDEX_VEHICLE_POSITION)
        && timestamp - watchdog->last_reset[SIMULATOR_INDEX_VEHICLE_POSITION] > SIMULATOR_INTERVAL_VEHICLE_POSITION * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, SIMULATOR_INDEX_VEHICLE_POSITION);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, SIMULATOR_INDEX_VEHICLE_SPEED)
        && timestamp - watchdog->last_reset[SIMULATOR_INDEX_VEHICLE_SPEED] > SIMULATOR_INTERVAL_VEHICLE_SPEED * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, SIMULATOR_INDEX_VEHICLE_SPEED);
    }

}


