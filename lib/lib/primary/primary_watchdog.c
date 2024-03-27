#include "primary_watchdog.h"


int primary_watchdog_interval_from_id(uint16_t message_id) {
    switch (message_id) {
       case 700: return PRIMARY_INTERVAL_STEERING_WHEEL_VERSION;
       case 701: return PRIMARY_INTERVAL_ECU_VERSION;
       case 703: return PRIMARY_INTERVAL_LV_VERSION;
       case 702: return PRIMARY_INTERVAL_HV_MAINBOARD_VERSION;
       case 705: return PRIMARY_INTERVAL_HV_CELLBOARD_0_VERSION;
       case 706: return PRIMARY_INTERVAL_HV_CELLBOARD_1_VERSION;
       case 707: return PRIMARY_INTERVAL_HV_CELLBOARD_2_VERSION;
       case 708: return PRIMARY_INTERVAL_HV_CELLBOARD_3_VERSION;
       case 709: return PRIMARY_INTERVAL_HV_CELLBOARD_4_VERSION;
       case 710: return PRIMARY_INTERVAL_HV_CELLBOARD_5_VERSION;
       case 1792: return PRIMARY_INTERVAL_HV_ERRORS;
       case 1536: return PRIMARY_INTERVAL_HV_DEBUG_SIGNALS;
       case 1024: return PRIMARY_INTERVAL_HV_FANS_STATUS;
       case 1288: return PRIMARY_INTERVAL_HV_SET_FANS_STATUS_HANDCART;
       case 1544: return PRIMARY_INTERVAL_HV_FEEDBACK_STATUS;
       case 1568: return PRIMARY_INTERVAL_HV_FEEDBACK_TS_VOLTAGE;
       case 1576: return PRIMARY_INTERVAL_HV_FEEDBACK_MISC_VOLTAGE;
       case 1584: return PRIMARY_INTERVAL_HV_FEEDBACK_SD_VOLTAGE;
       case 1592: return PRIMARY_INTERVAL_HV_IMD_STATUS;
       case 1600: return PRIMARY_INTERVAL_HV_STATUS;
       case 1032: return PRIMARY_INTERVAL_HV_BALANCING_STATUS;
       case 1608: return PRIMARY_INTERVAL_LV_STATUS;
       case 1040: return PRIMARY_INTERVAL_LV_RADIATOR_SPEED;
       case 1048: return PRIMARY_INTERVAL_LV_PUMPS_SPEED;
       case 1616: return PRIMARY_INTERVAL_LV_ERRORS;
       case 1624: return PRIMARY_INTERVAL_LV_FEEDBACK_TS_VOLTAGE;
       case 1632: return PRIMARY_INTERVAL_LV_FEEDBACK_SD_VOLTAGE;
       case 1640: return PRIMARY_INTERVAL_LV_FEEDBACK_ECLOSURE_VOLTAGE;
       case 1648: return PRIMARY_INTERVAL_LV_FEEDBACK_GPIO_EXTENDER;
       case 1656: return PRIMARY_INTERVAL_LV_INVERTER_CONNECTION_STATUS;
       case 1056: return PRIMARY_INTERVAL_TLM_STATUS;
       case 1064: return PRIMARY_INTERVAL_TLM_UNIX_TIMESTAMP;
       case 1080: return PRIMARY_INTERVAL_TLM_LAPS_STATS;
       case 1664: return PRIMARY_INTERVAL_HANDCART_STATUS;
       case 1088: return PRIMARY_INTERVAL_HANDCART_SETTINGS;
       case 1672: return PRIMARY_INTERVAL_ECU_STATUS;
       case 1344: return PRIMARY_INTERVAL_ECU_INVERTER_STATUS;
       case 1680: return PRIMARY_INTERVAL_ECU_CONTROL_STATUS;
       case 1688: return PRIMARY_INTERVAL_ECU_ERRORS;
       case 1696: return PRIMARY_INTERVAL_ECU_FEEDBACKS;
       case 1704: return PRIMARY_INTERVAL_ECU_POWER_MAPS;
       case 1864: return PRIMARY_INTERVAL_ECU_SET_POWER_MAPS;
       case 1096: return PRIMARY_INTERVAL_ECU_PTT_STATUS;
       case 1352: return PRIMARY_INTERVAL_ECU_SET_PTT_STATUS;
       case 513: return PRIMARY_INTERVAL_INV_L_REQUEST;
       case 514: return PRIMARY_INTERVAL_INV_R_REQUEST;
       case 385: return PRIMARY_INTERVAL_INV_L_RESPONSE;
       case 386: return PRIMARY_INTERVAL_INV_R_RESPONSE;

    }
    return -1;
}

int primary_watchdog_index_from_id(uint16_t message_id) {
    switch (message_id) {
       case 1818: return PRIMARY_INDEX_NLG5_DIAG_TX;
       case 1816: return PRIMARY_INDEX_NLG5_DIAG_RX;
       case 1556: return PRIMARY_INDEX_NLG5_ERR;
       case 1555: return PRIMARY_INDEX_NLG5_TEMP;
       case 1554: return PRIMARY_INDEX_NLG5_ACT_II;
       case 1553: return PRIMARY_INDEX_NLG5_ACT_I;
       case 1552: return PRIMARY_INDEX_NLG5_ST;
       case 1560: return PRIMARY_INDEX_NLG5_CTL;
       case 0: return PRIMARY_INDEX_HV_JMP_TO_BLT;
       case 1: return PRIMARY_INDEX_HV_FLASH_MAINBOARD_TX;
       case 2: return PRIMARY_INDEX_HV_FLASH_MAINBOARD_RX;
       case 3: return PRIMARY_INDEX_HV_FLASH_CELLBOARD_0_TX;
       case 4: return PRIMARY_INDEX_HV_FLASH_CELLBOARD_0_RX;
       case 5: return PRIMARY_INDEX_HV_FLASH_CELLBOARD_1_TX;
       case 6: return PRIMARY_INDEX_HV_FLASH_CELLBOARD_1_RX;
       case 7: return PRIMARY_INDEX_HV_FLASH_CELLBOARD_2_TX;
       case 8: return PRIMARY_INDEX_HV_FLASH_CELLBOARD_2_RX;
       case 9: return PRIMARY_INDEX_HV_FLASH_CELLBOARD_3_TX;
       case 10: return PRIMARY_INDEX_HV_FLASH_CELLBOARD_3_RX;
       case 11: return PRIMARY_INDEX_HV_FLASH_CELLBOARD_4_TX;
       case 12: return PRIMARY_INDEX_HV_FLASH_CELLBOARD_4_RX;
       case 13: return PRIMARY_INDEX_HV_FLASH_CELLBOARD_5_TX;
       case 14: return PRIMARY_INDEX_HV_FLASH_CELLBOARD_5_RX;
       case 15: return PRIMARY_INDEX_LV_JMP_TO_BLT;
       case 16: return PRIMARY_INDEX_LV_FLASH_BMS_TX;
       case 17: return PRIMARY_INDEX_LV_FLASH_BMS_RX;
       case 18: return PRIMARY_INDEX_ECU_JMP_TO_BLT;
       case 19: return PRIMARY_INDEX_ECU_FLASH_TX;
       case 20: return PRIMARY_INDEX_ECU_FLASH_RX;
       case 21: return PRIMARY_INDEX_STEERING_WHEEL_JMP_TO_BLT;
       case 22: return PRIMARY_INDEX_STEERING_WHEEL_FLASH_TX;
       case 23: return PRIMARY_INDEX_STEERING_WHEEL_FLASH_RX;
       case 700: return PRIMARY_INDEX_STEERING_WHEEL_VERSION;
       case 701: return PRIMARY_INDEX_ECU_VERSION;
       case 703: return PRIMARY_INDEX_LV_VERSION;
       case 704: return PRIMARY_INDEX_TLM_VERSION;
       case 702: return PRIMARY_INDEX_HV_MAINBOARD_VERSION;
       case 705: return PRIMARY_INDEX_HV_CELLBOARD_0_VERSION;
       case 706: return PRIMARY_INDEX_HV_CELLBOARD_1_VERSION;
       case 707: return PRIMARY_INDEX_HV_CELLBOARD_2_VERSION;
       case 708: return PRIMARY_INDEX_HV_CELLBOARD_3_VERSION;
       case 709: return PRIMARY_INDEX_HV_CELLBOARD_4_VERSION;
       case 710: return PRIMARY_INDEX_HV_CELLBOARD_5_VERSION;
       case 1792: return PRIMARY_INDEX_HV_ERRORS;
       case 1536: return PRIMARY_INDEX_HV_DEBUG_SIGNALS;
       case 1024: return PRIMARY_INDEX_HV_FANS_STATUS;
       case 1288: return PRIMARY_INDEX_HV_SET_FANS_STATUS_HANDCART;
       case 1544: return PRIMARY_INDEX_HV_FEEDBACK_STATUS;
       case 1568: return PRIMARY_INDEX_HV_FEEDBACK_TS_VOLTAGE;
       case 1576: return PRIMARY_INDEX_HV_FEEDBACK_MISC_VOLTAGE;
       case 1584: return PRIMARY_INDEX_HV_FEEDBACK_SD_VOLTAGE;
       case 1592: return PRIMARY_INDEX_HV_IMD_STATUS;
       case 1600: return PRIMARY_INDEX_HV_STATUS;
       case 1800: return PRIMARY_INDEX_HV_SET_STATUS_ECU;
       case 1808: return PRIMARY_INDEX_HV_SET_STATUS_HANDCART;
       case 1032: return PRIMARY_INDEX_HV_BALANCING_STATUS;
       case 1304: return PRIMARY_INDEX_HV_SET_BALANCING_STATUS_HANDCART;
       case 1608: return PRIMARY_INDEX_LV_STATUS;
       case 1040: return PRIMARY_INDEX_LV_RADIATOR_SPEED;
       case 1048: return PRIMARY_INDEX_LV_PUMPS_SPEED;
       case 1312: return PRIMARY_INDEX_LV_SET_RADIATOR_SPEED;
       case 1320: return PRIMARY_INDEX_LV_SET_PUMPS_SPEED;
       case 1616: return PRIMARY_INDEX_LV_ERRORS;
       case 1624: return PRIMARY_INDEX_LV_FEEDBACK_TS_VOLTAGE;
       case 1632: return PRIMARY_INDEX_LV_FEEDBACK_SD_VOLTAGE;
       case 1640: return PRIMARY_INDEX_LV_FEEDBACK_ECLOSURE_VOLTAGE;
       case 1648: return PRIMARY_INDEX_LV_FEEDBACK_GPIO_EXTENDER;
       case 1832: return PRIMARY_INDEX_LV_CAN_FLASH_REQ_STEERING_WHEEL;
       case 1840: return PRIMARY_INDEX_LV_CAN_FLASH_ACK;
       case 1656: return PRIMARY_INDEX_LV_INVERTER_CONNECTION_STATUS;
       case 1848: return PRIMARY_INDEX_LV_SET_INVERTER_CONNECTION_STATUS;
       case 1056: return PRIMARY_INDEX_TLM_STATUS;
       case 1328: return PRIMARY_INDEX_TLM_SET_STATUS;
       case 1064: return PRIMARY_INDEX_TLM_UNIX_TIMESTAMP;
       case 1072: return PRIMARY_INDEX_TLM_LAP_TIME;
       case 1080: return PRIMARY_INDEX_TLM_LAPS_STATS;
       case 1664: return PRIMARY_INDEX_HANDCART_STATUS;
       case 1088: return PRIMARY_INDEX_HANDCART_SETTINGS;
       case 1336: return PRIMARY_INDEX_HANDCART_SET_SETTINGS;
       case 1672: return PRIMARY_INDEX_ECU_STATUS;
       case 1856: return PRIMARY_INDEX_ECU_SET_STATUS;
       case 1344: return PRIMARY_INDEX_ECU_INVERTER_STATUS;
       case 1680: return PRIMARY_INDEX_ECU_CONTROL_STATUS;
       case 1688: return PRIMARY_INDEX_ECU_ERRORS;
       case 1696: return PRIMARY_INDEX_ECU_FEEDBACKS;
       case 1704: return PRIMARY_INDEX_ECU_POWER_MAPS;
       case 1864: return PRIMARY_INDEX_ECU_SET_POWER_MAPS;
       case 1096: return PRIMARY_INDEX_ECU_PTT_STATUS;
       case 1352: return PRIMARY_INDEX_ECU_SET_PTT_STATUS;
       case 513: return PRIMARY_INDEX_INV_L_REQUEST;
       case 514: return PRIMARY_INDEX_INV_R_REQUEST;
       case 385: return PRIMARY_INDEX_INV_L_RESPONSE;
       case 386: return PRIMARY_INDEX_INV_R_RESPONSE;

    }
    return -1;
}

void primary_watchdog_free(primary_watchdog *watchdog) {
    free(watchdog);
}

void primary_watchdog_reset(primary_watchdog *watchdog, canlib_message_id id, canlib_watchdog_timestamp timestamp) {
    int index = primary_watchdog_index_from_id(id);
    if (index < 93 && CANLIB_BITTEST_ARRAY(watchdog->activated, index)) {
        CANLIB_BITCLEAR_ARRAY(watchdog->timeout, index);
        watchdog->last_reset[index] = timestamp;
    }
}

void primary_watchdog_reset_all(primary_watchdog *watchdog, canlib_watchdog_timestamp timestamp) {
    memset(watchdog->timeout, 0, sizeof(watchdog->timeout));
    memset(watchdog->last_reset, timestamp, sizeof(watchdog->last_reset));
}
void primary_watchdog_timeout(primary_watchdog *watchdog, canlib_watchdog_timestamp timestamp) {

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_STEERING_WHEEL_VERSION)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_STEERING_WHEEL_VERSION] > PRIMARY_INTERVAL_STEERING_WHEEL_VERSION * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_STEERING_WHEEL_VERSION);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_ECU_VERSION)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_ECU_VERSION] > PRIMARY_INTERVAL_ECU_VERSION * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_ECU_VERSION);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_LV_VERSION)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_LV_VERSION] > PRIMARY_INTERVAL_LV_VERSION * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_LV_VERSION);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_HV_MAINBOARD_VERSION)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_HV_MAINBOARD_VERSION] > PRIMARY_INTERVAL_HV_MAINBOARD_VERSION * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_HV_MAINBOARD_VERSION);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_HV_CELLBOARD_0_VERSION)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_HV_CELLBOARD_0_VERSION] > PRIMARY_INTERVAL_HV_CELLBOARD_0_VERSION * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_HV_CELLBOARD_0_VERSION);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_HV_CELLBOARD_1_VERSION)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_HV_CELLBOARD_1_VERSION] > PRIMARY_INTERVAL_HV_CELLBOARD_1_VERSION * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_HV_CELLBOARD_1_VERSION);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_HV_CELLBOARD_2_VERSION)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_HV_CELLBOARD_2_VERSION] > PRIMARY_INTERVAL_HV_CELLBOARD_2_VERSION * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_HV_CELLBOARD_2_VERSION);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_HV_CELLBOARD_3_VERSION)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_HV_CELLBOARD_3_VERSION] > PRIMARY_INTERVAL_HV_CELLBOARD_3_VERSION * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_HV_CELLBOARD_3_VERSION);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_HV_CELLBOARD_4_VERSION)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_HV_CELLBOARD_4_VERSION] > PRIMARY_INTERVAL_HV_CELLBOARD_4_VERSION * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_HV_CELLBOARD_4_VERSION);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_HV_CELLBOARD_5_VERSION)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_HV_CELLBOARD_5_VERSION] > PRIMARY_INTERVAL_HV_CELLBOARD_5_VERSION * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_HV_CELLBOARD_5_VERSION);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_HV_ERRORS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_HV_ERRORS] > PRIMARY_INTERVAL_HV_ERRORS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_HV_ERRORS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_HV_DEBUG_SIGNALS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_HV_DEBUG_SIGNALS] > PRIMARY_INTERVAL_HV_DEBUG_SIGNALS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_HV_DEBUG_SIGNALS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_HV_FANS_STATUS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_HV_FANS_STATUS] > PRIMARY_INTERVAL_HV_FANS_STATUS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_HV_FANS_STATUS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_HV_SET_FANS_STATUS_HANDCART)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_HV_SET_FANS_STATUS_HANDCART] > PRIMARY_INTERVAL_HV_SET_FANS_STATUS_HANDCART * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_HV_SET_FANS_STATUS_HANDCART);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_HV_FEEDBACK_STATUS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_HV_FEEDBACK_STATUS] > PRIMARY_INTERVAL_HV_FEEDBACK_STATUS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_HV_FEEDBACK_STATUS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_HV_FEEDBACK_TS_VOLTAGE)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_HV_FEEDBACK_TS_VOLTAGE] > PRIMARY_INTERVAL_HV_FEEDBACK_TS_VOLTAGE * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_HV_FEEDBACK_TS_VOLTAGE);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_HV_FEEDBACK_MISC_VOLTAGE)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_HV_FEEDBACK_MISC_VOLTAGE] > PRIMARY_INTERVAL_HV_FEEDBACK_MISC_VOLTAGE * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_HV_FEEDBACK_MISC_VOLTAGE);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_HV_FEEDBACK_SD_VOLTAGE)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_HV_FEEDBACK_SD_VOLTAGE] > PRIMARY_INTERVAL_HV_FEEDBACK_SD_VOLTAGE * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_HV_FEEDBACK_SD_VOLTAGE);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_HV_IMD_STATUS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_HV_IMD_STATUS] > PRIMARY_INTERVAL_HV_IMD_STATUS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_HV_IMD_STATUS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_HV_STATUS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_HV_STATUS] > PRIMARY_INTERVAL_HV_STATUS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_HV_STATUS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_HV_BALANCING_STATUS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_HV_BALANCING_STATUS] > PRIMARY_INTERVAL_HV_BALANCING_STATUS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_HV_BALANCING_STATUS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_LV_STATUS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_LV_STATUS] > PRIMARY_INTERVAL_LV_STATUS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_LV_STATUS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_LV_RADIATOR_SPEED)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_LV_RADIATOR_SPEED] > PRIMARY_INTERVAL_LV_RADIATOR_SPEED * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_LV_RADIATOR_SPEED);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_LV_PUMPS_SPEED)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_LV_PUMPS_SPEED] > PRIMARY_INTERVAL_LV_PUMPS_SPEED * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_LV_PUMPS_SPEED);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_LV_ERRORS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_LV_ERRORS] > PRIMARY_INTERVAL_LV_ERRORS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_LV_ERRORS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_LV_FEEDBACK_TS_VOLTAGE)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_LV_FEEDBACK_TS_VOLTAGE] > PRIMARY_INTERVAL_LV_FEEDBACK_TS_VOLTAGE * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_LV_FEEDBACK_TS_VOLTAGE);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_LV_FEEDBACK_SD_VOLTAGE)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_LV_FEEDBACK_SD_VOLTAGE] > PRIMARY_INTERVAL_LV_FEEDBACK_SD_VOLTAGE * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_LV_FEEDBACK_SD_VOLTAGE);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_LV_FEEDBACK_ECLOSURE_VOLTAGE)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_LV_FEEDBACK_ECLOSURE_VOLTAGE] > PRIMARY_INTERVAL_LV_FEEDBACK_ECLOSURE_VOLTAGE * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_LV_FEEDBACK_ECLOSURE_VOLTAGE);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_LV_FEEDBACK_GPIO_EXTENDER)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_LV_FEEDBACK_GPIO_EXTENDER] > PRIMARY_INTERVAL_LV_FEEDBACK_GPIO_EXTENDER * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_LV_FEEDBACK_GPIO_EXTENDER);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_LV_INVERTER_CONNECTION_STATUS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_LV_INVERTER_CONNECTION_STATUS] > PRIMARY_INTERVAL_LV_INVERTER_CONNECTION_STATUS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_LV_INVERTER_CONNECTION_STATUS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_TLM_STATUS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_TLM_STATUS] > PRIMARY_INTERVAL_TLM_STATUS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_TLM_STATUS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_TLM_UNIX_TIMESTAMP)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_TLM_UNIX_TIMESTAMP] > PRIMARY_INTERVAL_TLM_UNIX_TIMESTAMP * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_TLM_UNIX_TIMESTAMP);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_TLM_LAPS_STATS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_TLM_LAPS_STATS] > PRIMARY_INTERVAL_TLM_LAPS_STATS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_TLM_LAPS_STATS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_HANDCART_STATUS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_HANDCART_STATUS] > PRIMARY_INTERVAL_HANDCART_STATUS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_HANDCART_STATUS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_HANDCART_SETTINGS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_HANDCART_SETTINGS] > PRIMARY_INTERVAL_HANDCART_SETTINGS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_HANDCART_SETTINGS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_ECU_STATUS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_ECU_STATUS] > PRIMARY_INTERVAL_ECU_STATUS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_ECU_STATUS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_ECU_INVERTER_STATUS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_ECU_INVERTER_STATUS] > PRIMARY_INTERVAL_ECU_INVERTER_STATUS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_ECU_INVERTER_STATUS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_ECU_CONTROL_STATUS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_ECU_CONTROL_STATUS] > PRIMARY_INTERVAL_ECU_CONTROL_STATUS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_ECU_CONTROL_STATUS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_ECU_ERRORS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_ECU_ERRORS] > PRIMARY_INTERVAL_ECU_ERRORS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_ECU_ERRORS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_ECU_FEEDBACKS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_ECU_FEEDBACKS] > PRIMARY_INTERVAL_ECU_FEEDBACKS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_ECU_FEEDBACKS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_ECU_POWER_MAPS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_ECU_POWER_MAPS] > PRIMARY_INTERVAL_ECU_POWER_MAPS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_ECU_POWER_MAPS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_ECU_SET_POWER_MAPS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_ECU_SET_POWER_MAPS] > PRIMARY_INTERVAL_ECU_SET_POWER_MAPS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_ECU_SET_POWER_MAPS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_ECU_PTT_STATUS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_ECU_PTT_STATUS] > PRIMARY_INTERVAL_ECU_PTT_STATUS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_ECU_PTT_STATUS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_ECU_SET_PTT_STATUS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_ECU_SET_PTT_STATUS] > PRIMARY_INTERVAL_ECU_SET_PTT_STATUS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_ECU_SET_PTT_STATUS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_INV_L_REQUEST)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_INV_L_REQUEST] > PRIMARY_INTERVAL_INV_L_REQUEST * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_INV_L_REQUEST);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_INV_R_REQUEST)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_INV_R_REQUEST] > PRIMARY_INTERVAL_INV_R_REQUEST * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_INV_R_REQUEST);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_INV_L_RESPONSE)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_INV_L_RESPONSE] > PRIMARY_INTERVAL_INV_L_RESPONSE * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_INV_L_RESPONSE);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_INV_R_RESPONSE)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_INV_R_RESPONSE] > PRIMARY_INTERVAL_INV_R_RESPONSE * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_INV_R_RESPONSE);
    }

}


