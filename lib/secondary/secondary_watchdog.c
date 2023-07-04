#include "secondary_watchdog.h"


int secondary_watchdog_interval_from_id(uint16_t message_id) {
    switch (message_id) {
       case 770: return SECONDARY_INTERVAL_PEDALS_OUTPUT;
       case 256: return SECONDARY_INTERVAL_STEERING_ANGLE;
       case 1281: return SECONDARY_INTERVAL_CONTROL_STATE;

    }
    return -1;
}

int secondary_watchdog_index_from_id(uint16_t message_id) {
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
       case 256: return SECONDARY_INDEX_STEERING_ANGLE;
       case 1281: return SECONDARY_INDEX_CONTROL_STATE;
       case 514: return SECONDARY_INDEX_TPMS;
       case 771: return SECONDARY_INDEX_LC_STATUS;

    }
    return -1;
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


