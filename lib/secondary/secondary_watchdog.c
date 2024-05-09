#include "secondary_watchdog.h"


int secondary_watchdog_interval_from_id(uint16_t message_id) {
    switch (message_id) {
       case 1552: return SECONDARY_INTERVAL_ANGULAR_VELOCITY;
       case 1560: return SECONDARY_INTERVAL_HV_SOC_ESTIMATION_STATE;
       case 1568: return SECONDARY_INTERVAL_HV_SOC_ESTIMATION_COVARIANCE;
       case 1576: return SECONDARY_INTERVAL_PEDAL_THROTTLE;
       case 1584: return SECONDARY_INTERVAL_PEDAL_BRAKES_PRESSURE;
       case 1592: return SECONDARY_INTERVAL_STEER_ANGLE;
       case 1616: return SECONDARY_INTERVAL_TLM_UNIX_TIMESTAMP;
       case 1632: return SECONDARY_INTERVAL_TLM_LAPS_STATS;
       case 1640: return SECONDARY_INTERVAL_TLM_NETWORK_INTERFACE;
       case 1648: return SECONDARY_INTERVAL_AMMO_COMPRESSION;
       case 1656: return SECONDARY_INTERVAL_LINK_DEFORMATION;
       case 1664: return SECONDARY_INTERVAL_DEBUG_SIGNAL_1;
       case 1672: return SECONDARY_INTERVAL_DEBUG_SIGNAL_2;
       case 1680: return SECONDARY_INTERVAL_COOLING_TEMP_PUMPS;
       case 1688: return SECONDARY_INTERVAL_COOLING_TEMP_RADIATORS;

    }
    return -1;
}

int secondary_watchdog_index_from_id(uint16_t message_id) {
    switch (message_id) {
       case 0: return SECONDARY_INDEX_ACQUISINATOR_JMP_TO_BLT;
       case 1: return SECONDARY_INDEX_ACQUISINATOR_FLASH_0_TX;
       case 2: return SECONDARY_INDEX_ACQUISINATOR_FLASH_0_RX;
       case 3: return SECONDARY_INDEX_ACQUISINATOR_FLASH_1_TX;
       case 4: return SECONDARY_INDEX_ACQUISINATOR_FLASH_1_RX;
       case 5: return SECONDARY_INDEX_ACQUISINATOR_FLASH_2_TX;
       case 6: return SECONDARY_INDEX_ACQUISINATOR_FLASH_2_RX;
       case 7: return SECONDARY_INDEX_ACQUISINATOR_FLASH_3_TX;
       case 8: return SECONDARY_INDEX_ACQUISINATOR_FLASH_3_RX;
       case 9: return SECONDARY_INDEX_ACQUISINATOR_FLASH_4_TX;
       case 10: return SECONDARY_INDEX_ACQUISINATOR_FLASH_4_RX;
       case 11: return SECONDARY_INDEX_ACQUISINATOR_FLASH_5_TX;
       case 12: return SECONDARY_INDEX_ACQUISINATOR_FLASH_5_RX;
       case 13: return SECONDARY_INDEX_ACQUISINATOR_FLASH_6_TX;
       case 14: return SECONDARY_INDEX_ACQUISINATOR_FLASH_6_RX;
       case 15: return SECONDARY_INDEX_ACQUISINATOR_FLASH_7_TX;
       case 16: return SECONDARY_INDEX_ACQUISINATOR_FLASH_7_RX;
       case 17: return SECONDARY_INDEX_ACQUISINATOR_FLASH_8_TX;
       case 18: return SECONDARY_INDEX_ACQUISINATOR_FLASH_8_RX;
       case 19: return SECONDARY_INDEX_ACQUISINATOR_FLASH_9_TX;
       case 20: return SECONDARY_INDEX_ACQUISINATOR_FLASH_9_RX;
       case 21: return SECONDARY_INDEX_ACQUISINATOR_FLASH_10_TX;
       case 22: return SECONDARY_INDEX_ACQUISINATOR_FLASH_10_RX;
       case 23: return SECONDARY_INDEX_ACQUISINATOR_FLASH_11_TX;
       case 24: return SECONDARY_INDEX_ACQUISINATOR_FLASH_11_RX;
       case 25: return SECONDARY_INDEX_ACQUISINATOR_FLASH_12_TX;
       case 26: return SECONDARY_INDEX_ACQUISINATOR_FLASH_12_RX;
       case 27: return SECONDARY_INDEX_ACQUISINATOR_FLASH_13_TX;
       case 28: return SECONDARY_INDEX_ACQUISINATOR_FLASH_13_RX;
       case 29: return SECONDARY_INDEX_ACQUISINATOR_FLASH_14_TX;
       case 30: return SECONDARY_INDEX_ACQUISINATOR_FLASH_14_RX;
       case 31: return SECONDARY_INDEX_ACQUISINATOR_FLASH_15_TX;
       case 32: return SECONDARY_INDEX_ACQUISINATOR_FLASH_15_RX;
       case 33: return SECONDARY_INDEX_ACQUISINATOR_FLASH_16_TX;
       case 34: return SECONDARY_INDEX_ACQUISINATOR_FLASH_16_RX;
       case 35: return SECONDARY_INDEX_ACQUISINATOR_FLASH_17_TX;
       case 36: return SECONDARY_INDEX_ACQUISINATOR_FLASH_17_RX;
       case 37: return SECONDARY_INDEX_ACQUISINATOR_FLASH_18_TX;
       case 38: return SECONDARY_INDEX_ACQUISINATOR_FLASH_18_RX;
       case 39: return SECONDARY_INDEX_ACQUISINATOR_FLASH_19_TX;
       case 40: return SECONDARY_INDEX_ACQUISINATOR_FLASH_19_RX;
       case 41: return SECONDARY_INDEX_ACQUISINATOR_FLASH_20_TX;
       case 42: return SECONDARY_INDEX_ACQUISINATOR_FLASH_20_RX;
       case 43: return SECONDARY_INDEX_ACQUISINATOR_FLASH_21_TX;
       case 44: return SECONDARY_INDEX_ACQUISINATOR_FLASH_21_RX;
       case 45: return SECONDARY_INDEX_ACQUISINATOR_FLASH_22_TX;
       case 46: return SECONDARY_INDEX_ACQUISINATOR_FLASH_22_RX;
       case 47: return SECONDARY_INDEX_ACQUISINATOR_FLASH_23_TX;
       case 48: return SECONDARY_INDEX_ACQUISINATOR_FLASH_23_RX;
       case 49: return SECONDARY_INDEX_ACQUISINATOR_FLASH_24_TX;
       case 50: return SECONDARY_INDEX_ACQUISINATOR_FLASH_24_RX;
       case 51: return SECONDARY_INDEX_ACQUISINATOR_FLASH_25_TX;
       case 52: return SECONDARY_INDEX_ACQUISINATOR_FLASH_25_RX;
       case 53: return SECONDARY_INDEX_ACQUISINATOR_FLASH_26_TX;
       case 54: return SECONDARY_INDEX_ACQUISINATOR_FLASH_26_RX;
       case 55: return SECONDARY_INDEX_ACQUISINATOR_FLASH_27_TX;
       case 56: return SECONDARY_INDEX_ACQUISINATOR_FLASH_27_RX;
       case 57: return SECONDARY_INDEX_ACQUISINATOR_FLASH_28_TX;
       case 58: return SECONDARY_INDEX_ACQUISINATOR_FLASH_28_RX;
       case 59: return SECONDARY_INDEX_ACQUISINATOR_FLASH_29_TX;
       case 60: return SECONDARY_INDEX_ACQUISINATOR_FLASH_29_RX;
       case 61: return SECONDARY_INDEX_ACQUISINATOR_FLASH_30_TX;
       case 62: return SECONDARY_INDEX_ACQUISINATOR_FLASH_30_RX;
       case 63: return SECONDARY_INDEX_ACQUISINATOR_FLASH_31_TX;
       case 64: return SECONDARY_INDEX_ACQUISINATOR_FLASH_31_RX;
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
       case 1560: return SECONDARY_INDEX_HV_SOC_ESTIMATION_STATE;
       case 1568: return SECONDARY_INDEX_HV_SOC_ESTIMATION_COVARIANCE;
       case 1576: return SECONDARY_INDEX_PEDAL_THROTTLE;
       case 1584: return SECONDARY_INDEX_PEDAL_BRAKES_PRESSURE;
       case 1592: return SECONDARY_INDEX_STEER_ANGLE;
       case 1600: return SECONDARY_INDEX_TPMS_PRESSURE;
       case 1608: return SECONDARY_INDEX_TPMS_TEMPERATURE;
       case 1616: return SECONDARY_INDEX_TLM_UNIX_TIMESTAMP;
       case 1624: return SECONDARY_INDEX_TLM_LAP_TIME;
       case 1632: return SECONDARY_INDEX_TLM_LAPS_STATS;
       case 1640: return SECONDARY_INDEX_TLM_NETWORK_INTERFACE;
       case 1648: return SECONDARY_INDEX_AMMO_COMPRESSION;
       case 1656: return SECONDARY_INDEX_LINK_DEFORMATION;
       case 72: return SECONDARY_INDEX_LINK_DEFORMATION_SET_CALIBRATION;
       case 1664: return SECONDARY_INDEX_DEBUG_SIGNAL_1;
       case 1672: return SECONDARY_INDEX_DEBUG_SIGNAL_2;
       case 1680: return SECONDARY_INDEX_COOLING_TEMP_PUMPS;
       case 1688: return SECONDARY_INDEX_COOLING_TEMP_RADIATORS;

    }
    return -1;
}

void secondary_watchdog_free(secondary_watchdog *watchdog) {
    free(watchdog);
}

void secondary_watchdog_reset(secondary_watchdog *watchdog, canlib_message_id id, canlib_watchdog_timestamp timestamp) {
    int index = secondary_watchdog_index_from_id(id);
    if (index < 104 && CANLIB_BITTEST_ARRAY(watchdog->activated, index)) {
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
        CANLIB_BITTEST_ARRAY(watchdog->activated, SECONDARY_INDEX_HV_SOC_ESTIMATION_STATE)
        && timestamp - watchdog->last_reset[SECONDARY_INDEX_HV_SOC_ESTIMATION_STATE] > SECONDARY_INTERVAL_HV_SOC_ESTIMATION_STATE * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, SECONDARY_INDEX_HV_SOC_ESTIMATION_STATE);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, SECONDARY_INDEX_HV_SOC_ESTIMATION_COVARIANCE)
        && timestamp - watchdog->last_reset[SECONDARY_INDEX_HV_SOC_ESTIMATION_COVARIANCE] > SECONDARY_INTERVAL_HV_SOC_ESTIMATION_COVARIANCE * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, SECONDARY_INDEX_HV_SOC_ESTIMATION_COVARIANCE);
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
        CANLIB_BITTEST_ARRAY(watchdog->activated, SECONDARY_INDEX_TLM_NETWORK_INTERFACE)
        && timestamp - watchdog->last_reset[SECONDARY_INDEX_TLM_NETWORK_INTERFACE] > SECONDARY_INTERVAL_TLM_NETWORK_INTERFACE * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, SECONDARY_INDEX_TLM_NETWORK_INTERFACE);
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
        CANLIB_BITTEST_ARRAY(watchdog->activated, SECONDARY_INDEX_COOLING_TEMP_PUMPS)
        && timestamp - watchdog->last_reset[SECONDARY_INDEX_COOLING_TEMP_PUMPS] > SECONDARY_INTERVAL_COOLING_TEMP_PUMPS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, SECONDARY_INDEX_COOLING_TEMP_PUMPS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, SECONDARY_INDEX_COOLING_TEMP_RADIATORS)
        && timestamp - watchdog->last_reset[SECONDARY_INDEX_COOLING_TEMP_RADIATORS] > SECONDARY_INTERVAL_COOLING_TEMP_RADIATORS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, SECONDARY_INDEX_COOLING_TEMP_RADIATORS);
    }

}


