#include "secondary_watchdog.h"


int secondary_watchdog_interval_from_id(uint16_t message_id) {
    switch (message_id) {
       case 1552: return SECONDARY_INTERVAL_ANGULAR_VELOCITY;
       case 1560: return SECONDARY_INTERVAL_PEDAL_THROTTLE;
       case 1568: return SECONDARY_INTERVAL_PEDAL_BRAKES_PRESSURE;
       case 1576: return SECONDARY_INTERVAL_STEER_ANGLE;
       case 1600: return SECONDARY_INTERVAL_TLM_UNIX_TIMESTAMP;
       case 1616: return SECONDARY_INTERVAL_TLM_LAPS_STATS;
       case 1624: return SECONDARY_INTERVAL_AMMO_COMPRESSION;
       case 1632: return SECONDARY_INTERVAL_LINK_DEFORMATION;
       case 1640: return SECONDARY_INTERVAL_DEBUG_SIGNAL_1;
       case 1648: return SECONDARY_INTERVAL_DEBUG_SIGNAL_2;
       case 1656: return SECONDARY_INTERVAL_COOLING_TEMP;

    }
    return -1;
}

int secondary_watchdog_index_from_id(uint16_t message_id) {
    switch (message_id) {
       case 1260: return SECONDARY_INDEX_IMU_ANGULAR_RATE;
       case 1261: return SECONDARY_INDEX_IMU_ACCELERATION;
       case 1456: return SECONDARY_INDEX_IRTS_FL_0;
       case 1457: return SECONDARY_INDEX_IRTS_FL_1;
       case 1458: return SECONDARY_INDEX_IRTS_FL_2;
       case 1459: return SECONDARY_INDEX_IRTS_FL_3;
       case 1464: return SECONDARY_INDEX_IRTS_FR_0;
       case 1465: return SECONDARY_INDEX_IRTS_FR_1;
       case 1466: return SECONDARY_INDEX_IRTS_FR_2;
       case 1467: return SECONDARY_INDEX_IRTS_FR_3;
       case 1468: return SECONDARY_INDEX_IRTS_RL_0;
       case 1469: return SECONDARY_INDEX_IRTS_RL_1;
       case 1470: return SECONDARY_INDEX_IRTS_RL_2;
       case 1471: return SECONDARY_INDEX_IRTS_RL_3;
       case 1200: return SECONDARY_INDEX_IRTS_RR_0;
       case 1201: return SECONDARY_INDEX_IRTS_RR_1;
       case 1202: return SECONDARY_INDEX_IRTS_RR_2;
       case 1203: return SECONDARY_INDEX_IRTS_RR_3;
       case 1536: return SECONDARY_INDEX_GPS_COORDS;
       case 1544: return SECONDARY_INDEX_GPS_SPEED;
       case 1552: return SECONDARY_INDEX_ANGULAR_VELOCITY;
       case 1560: return SECONDARY_INDEX_PEDAL_THROTTLE;
       case 1568: return SECONDARY_INDEX_PEDAL_BRAKES_PRESSURE;
       case 1576: return SECONDARY_INDEX_STEER_ANGLE;
       case 1584: return SECONDARY_INDEX_TPMS_PRESSURE;
       case 1592: return SECONDARY_INDEX_TPMS_TEMPERATURE;
       case 1600: return SECONDARY_INDEX_TLM_UNIX_TIMESTAMP;
       case 1608: return SECONDARY_INDEX_TLM_LAP_TIME;
       case 1616: return SECONDARY_INDEX_TLM_LAPS_STATS;
       case 1624: return SECONDARY_INDEX_AMMO_COMPRESSION;
       case 1632: return SECONDARY_INDEX_LINK_DEFORMATION;
       case 0: return SECONDARY_INDEX_LINK_DEFORMATION_SET_CALIBRATION;
       case 1640: return SECONDARY_INDEX_DEBUG_SIGNAL_1;
       case 1648: return SECONDARY_INDEX_DEBUG_SIGNAL_2;
       case 1656: return SECONDARY_INDEX_COOLING_TEMP;

    }
    return -1;
}

void secondary_watchdog_free(secondary_watchdog *watchdog) {
    free(watchdog);
}

void secondary_watchdog_reset(secondary_watchdog *watchdog, canlib_message_id id, canlib_watchdog_timestamp timestamp) {
    int index = secondary_watchdog_index_from_id(id);
    if (index < 35 && CANLIB_BITTEST_ARRAY(watchdog->activated, index)) {
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
        CANLIB_BITTEST_ARRAY(watchdog->activated, SECONDARY_INDEX_ANGULAR_VELOCITY)
        && timestamp - watchdog->last_reset[SECONDARY_INDEX_ANGULAR_VELOCITY] > SECONDARY_INTERVAL_ANGULAR_VELOCITY * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, SECONDARY_INDEX_ANGULAR_VELOCITY);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, SECONDARY_INDEX_PEDAL_THROTTLE)
        && timestamp - watchdog->last_reset[SECONDARY_INDEX_PEDAL_THROTTLE] > SECONDARY_INTERVAL_PEDAL_THROTTLE * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, SECONDARY_INDEX_PEDAL_THROTTLE);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, SECONDARY_INDEX_PEDAL_BRAKES_PRESSURE)
        && timestamp - watchdog->last_reset[SECONDARY_INDEX_PEDAL_BRAKES_PRESSURE] > SECONDARY_INTERVAL_PEDAL_BRAKES_PRESSURE * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, SECONDARY_INDEX_PEDAL_BRAKES_PRESSURE);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, SECONDARY_INDEX_STEER_ANGLE)
        && timestamp - watchdog->last_reset[SECONDARY_INDEX_STEER_ANGLE] > SECONDARY_INTERVAL_STEER_ANGLE * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, SECONDARY_INDEX_STEER_ANGLE);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, SECONDARY_INDEX_TLM_UNIX_TIMESTAMP)
        && timestamp - watchdog->last_reset[SECONDARY_INDEX_TLM_UNIX_TIMESTAMP] > SECONDARY_INTERVAL_TLM_UNIX_TIMESTAMP * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, SECONDARY_INDEX_TLM_UNIX_TIMESTAMP);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, SECONDARY_INDEX_TLM_LAPS_STATS)
        && timestamp - watchdog->last_reset[SECONDARY_INDEX_TLM_LAPS_STATS] > SECONDARY_INTERVAL_TLM_LAPS_STATS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, SECONDARY_INDEX_TLM_LAPS_STATS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, SECONDARY_INDEX_AMMO_COMPRESSION)
        && timestamp - watchdog->last_reset[SECONDARY_INDEX_AMMO_COMPRESSION] > SECONDARY_INTERVAL_AMMO_COMPRESSION * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, SECONDARY_INDEX_AMMO_COMPRESSION);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, SECONDARY_INDEX_LINK_DEFORMATION)
        && timestamp - watchdog->last_reset[SECONDARY_INDEX_LINK_DEFORMATION] > SECONDARY_INTERVAL_LINK_DEFORMATION * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, SECONDARY_INDEX_LINK_DEFORMATION);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, SECONDARY_INDEX_DEBUG_SIGNAL_1)
        && timestamp - watchdog->last_reset[SECONDARY_INDEX_DEBUG_SIGNAL_1] > SECONDARY_INTERVAL_DEBUG_SIGNAL_1 * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, SECONDARY_INDEX_DEBUG_SIGNAL_1);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, SECONDARY_INDEX_DEBUG_SIGNAL_2)
        && timestamp - watchdog->last_reset[SECONDARY_INDEX_DEBUG_SIGNAL_2] > SECONDARY_INTERVAL_DEBUG_SIGNAL_2 * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, SECONDARY_INDEX_DEBUG_SIGNAL_2);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, SECONDARY_INDEX_COOLING_TEMP)
        && timestamp - watchdog->last_reset[SECONDARY_INDEX_COOLING_TEMP] > SECONDARY_INTERVAL_COOLING_TEMP * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, SECONDARY_INDEX_COOLING_TEMP);
    }

}


