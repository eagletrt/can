#include "primary_watchdog.h"


int primary_watchdog_interval_from_id(uint16_t message_id) {
    switch (message_id) {
       case 700: return PRIMARY_INTERVAL_STEERING_WHEEL_VERSION;
       case 701: return PRIMARY_INTERVAL_ECU_VERSION;
       case 703: return PRIMARY_INTERVAL_LV_VERSION;
       case 702: return PRIMARY_INTERVAL_HV_MAINBOARD_VERSION;
       case 705: return PRIMARY_INTERVAL_HV_CELLBOARD_VERSION;
       case 24: return PRIMARY_INTERVAL_HV_ERRORS;
       case 512: return PRIMARY_INTERVAL_HV_DEBUG_SIGNALS;
       case 1536: return PRIMARY_INTERVAL_HV_FANS_STATUS;
       case 1024: return PRIMARY_INTERVAL_HV_SET_FANS_STATUS;
       case 520: return PRIMARY_INTERVAL_HV_FEEDBACK_STATUS;
       case 528: return PRIMARY_INTERVAL_HV_FEEDBACK_TS_VOLTAGE;
       case 536: return PRIMARY_INTERVAL_HV_FEEDBACK_MISC_VOLTAGE;
       case 544: return PRIMARY_INTERVAL_HV_FEEDBACK_SD_VOLTAGE;
       case 552: return PRIMARY_INTERVAL_HV_IMD_STATUS;
       case 560: return PRIMARY_INTERVAL_HV_STATUS;
       case 1544: return PRIMARY_INTERVAL_HV_BALANCING_STATUS;
       case 568: return PRIMARY_INTERVAL_LV_STATUS;
       case 1568: return PRIMARY_INTERVAL_LV_RADIATOR_SPEED;
       case 1576: return PRIMARY_INTERVAL_LV_PUMPS_SPEED;
       case 576: return PRIMARY_INTERVAL_LV_ERRORS;
       case 584: return PRIMARY_INTERVAL_LV_FEEDBACK_TS_VOLTAGE;
       case 592: return PRIMARY_INTERVAL_LV_FEEDBACK_SD_VOLTAGE;
       case 600: return PRIMARY_INTERVAL_LV_FEEDBACK_ENCLOSURE_VOLTAGE;
       case 608: return PRIMARY_INTERVAL_LV_FEEDBACK_GPIO_EXTENDER;
       case 616: return PRIMARY_INTERVAL_LV_INVERTER_CONNECTION_STATUS;
       case 1584: return PRIMARY_INTERVAL_TLM_STATUS;
       case 624: return PRIMARY_INTERVAL_HANDCART_STATUS;
       case 1592: return PRIMARY_INTERVAL_HANDCART_SETTINGS;
       case 632: return PRIMARY_INTERVAL_ECU_STATUS;
       case 1080: return PRIMARY_INTERVAL_ECU_INVERTER_STATUS;
       case 640: return PRIMARY_INTERVAL_ECU_CONTROL_STATUS;
       case 648: return PRIMARY_INTERVAL_ECU_ERRORS;
       case 656: return PRIMARY_INTERVAL_ECU_FEEDBACKS;
       case 664: return PRIMARY_INTERVAL_ECU_POWER_MAPS;
       case 80: return PRIMARY_INTERVAL_ECU_SET_POWER_MAPS;
       case 1600: return PRIMARY_INTERVAL_ECU_PTT_STATUS;
       case 1088: return PRIMARY_INTERVAL_ECU_SET_PTT_STATUS;
       case 513: return PRIMARY_INTERVAL_INV_L_REQUEST;
       case 672: return PRIMARY_INTERVAL_CONTROL_OUTPUT;
       case 680: return PRIMARY_INTERVAL_CONTROL_STATUS;
       case 514: return PRIMARY_INTERVAL_INV_R_REQUEST;
       case 385: return PRIMARY_INTERVAL_INV_L_RESPONSE;
       case 386: return PRIMARY_INTERVAL_INV_R_RESPONSE;
       case 1608: return PRIMARY_INTERVAL_LV_CURRENT_BATTERY;
       case 1616: return PRIMARY_INTERVAL_LV_CURRENT_CHARGER;
       case 1624: return PRIMARY_INTERVAL_LV_TOTAL_VOLTAGE;
       case 1632: return PRIMARY_INTERVAL_LV_CELLS_VOLTAGE;
       case 1640: return PRIMARY_INTERVAL_LV_CELLS_VOLTAGE_STATS;
       case 1648: return PRIMARY_INTERVAL_LV_CELLS_TEMP;
       case 1656: return PRIMARY_INTERVAL_LV_CELLS_TEMP_STATS;
       case 1664: return PRIMARY_INTERVAL_HV_CURRENT;
       case 1672: return PRIMARY_INTERVAL_HV_POWER;
       case 1680: return PRIMARY_INTERVAL_HV_ENERGY;
       case 1688: return PRIMARY_INTERVAL_HV_SOC;
       case 1696: return PRIMARY_INTERVAL_HV_TOTAL_VOLTAGE;
       case 1704: return PRIMARY_INTERVAL_HV_CELLS_VOLTAGE;
       case 1712: return PRIMARY_INTERVAL_HV_CELLS_VOLTAGE_STATS;
       case 1720: return PRIMARY_INTERVAL_HV_CELLS_TEMP;
       case 1728: return PRIMARY_INTERVAL_HV_CELLS_TEMP_STATS;
       case 1736: return PRIMARY_INTERVAL_DEBUG_SIGNAL_1;

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
       case 705: return PRIMARY_INDEX_HV_CELLBOARD_VERSION;
       case 24: return PRIMARY_INDEX_HV_ERRORS;
       case 512: return PRIMARY_INDEX_HV_DEBUG_SIGNALS;
       case 1536: return PRIMARY_INDEX_HV_FANS_STATUS;
       case 1024: return PRIMARY_INDEX_HV_SET_FANS_STATUS;
       case 520: return PRIMARY_INDEX_HV_FEEDBACK_STATUS;
       case 528: return PRIMARY_INDEX_HV_FEEDBACK_TS_VOLTAGE;
       case 536: return PRIMARY_INDEX_HV_FEEDBACK_MISC_VOLTAGE;
       case 544: return PRIMARY_INDEX_HV_FEEDBACK_SD_VOLTAGE;
       case 552: return PRIMARY_INDEX_HV_IMD_STATUS;
       case 560: return PRIMARY_INDEX_HV_STATUS;
       case 32: return PRIMARY_INDEX_HV_SET_STATUS_ECU;
       case 40: return PRIMARY_INDEX_HV_SET_STATUS_HANDCART;
       case 1544: return PRIMARY_INDEX_HV_BALANCING_STATUS;
       case 1040: return PRIMARY_INDEX_HV_SET_BALANCING_STATUS_HANDCART;
       case 568: return PRIMARY_INDEX_LV_STATUS;
       case 1568: return PRIMARY_INDEX_LV_RADIATOR_SPEED;
       case 1576: return PRIMARY_INDEX_LV_PUMPS_SPEED;
       case 1048: return PRIMARY_INDEX_LV_SET_RADIATOR_SPEED;
       case 1056: return PRIMARY_INDEX_LV_SET_PUMPS_SPEED;
       case 576: return PRIMARY_INDEX_LV_ERRORS;
       case 584: return PRIMARY_INDEX_LV_FEEDBACK_TS_VOLTAGE;
       case 592: return PRIMARY_INDEX_LV_FEEDBACK_SD_VOLTAGE;
       case 600: return PRIMARY_INDEX_LV_FEEDBACK_ENCLOSURE_VOLTAGE;
       case 608: return PRIMARY_INDEX_LV_FEEDBACK_GPIO_EXTENDER;
       case 48: return PRIMARY_INDEX_LV_CAN_FLASH_REQ;
       case 56: return PRIMARY_INDEX_LV_CAN_FLASH_ACK;
       case 616: return PRIMARY_INDEX_LV_INVERTER_CONNECTION_STATUS;
       case 64: return PRIMARY_INDEX_LV_SET_INVERTER_CONNECTION_STATUS;
       case 1584: return PRIMARY_INDEX_TLM_STATUS;
       case 1064: return PRIMARY_INDEX_TLM_SET_STATUS;
       case 624: return PRIMARY_INDEX_HANDCART_STATUS;
       case 1592: return PRIMARY_INDEX_HANDCART_SETTINGS;
       case 1072: return PRIMARY_INDEX_HANDCART_SET_SETTINGS;
       case 632: return PRIMARY_INDEX_ECU_STATUS;
       case 72: return PRIMARY_INDEX_ECU_SET_STATUS;
       case 1080: return PRIMARY_INDEX_ECU_INVERTER_STATUS;
       case 640: return PRIMARY_INDEX_ECU_CONTROL_STATUS;
       case 648: return PRIMARY_INDEX_ECU_ERRORS;
       case 656: return PRIMARY_INDEX_ECU_FEEDBACKS;
       case 664: return PRIMARY_INDEX_ECU_POWER_MAPS;
       case 80: return PRIMARY_INDEX_ECU_SET_POWER_MAPS;
       case 1600: return PRIMARY_INDEX_ECU_PTT_STATUS;
       case 1088: return PRIMARY_INDEX_ECU_SET_PTT_STATUS;
       case 513: return PRIMARY_INDEX_INV_L_REQUEST;
       case 672: return PRIMARY_INDEX_CONTROL_OUTPUT;
       case 680: return PRIMARY_INDEX_CONTROL_STATUS;
       case 514: return PRIMARY_INDEX_INV_R_REQUEST;
       case 385: return PRIMARY_INDEX_INV_L_RESPONSE;
       case 386: return PRIMARY_INDEX_INV_R_RESPONSE;
       case 1608: return PRIMARY_INDEX_LV_CURRENT_BATTERY;
       case 1616: return PRIMARY_INDEX_LV_CURRENT_CHARGER;
       case 1624: return PRIMARY_INDEX_LV_TOTAL_VOLTAGE;
       case 1632: return PRIMARY_INDEX_LV_CELLS_VOLTAGE;
       case 1640: return PRIMARY_INDEX_LV_CELLS_VOLTAGE_STATS;
       case 1648: return PRIMARY_INDEX_LV_CELLS_TEMP;
       case 1656: return PRIMARY_INDEX_LV_CELLS_TEMP_STATS;
       case 1664: return PRIMARY_INDEX_HV_CURRENT;
       case 1672: return PRIMARY_INDEX_HV_POWER;
       case 1680: return PRIMARY_INDEX_HV_ENERGY;
       case 1688: return PRIMARY_INDEX_HV_SOC;
       case 1696: return PRIMARY_INDEX_HV_TOTAL_VOLTAGE;
       case 1704: return PRIMARY_INDEX_HV_CELLS_VOLTAGE;
       case 1712: return PRIMARY_INDEX_HV_CELLS_VOLTAGE_STATS;
       case 1720: return PRIMARY_INDEX_HV_CELLS_TEMP;
       case 1728: return PRIMARY_INDEX_HV_CELLS_TEMP_STATS;
       case 1736: return PRIMARY_INDEX_DEBUG_SIGNAL_1;

    }
    return -1;
}

void primary_watchdog_free(primary_watchdog *watchdog) {
    free(watchdog);
}

void primary_watchdog_reset(primary_watchdog *watchdog, canlib_message_id id, canlib_watchdog_timestamp timestamp) {
    int index = primary_watchdog_index_from_id(id);
    if (index < 104 && CANLIB_BITTEST_ARRAY(watchdog->activated, index)) {
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
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_HV_CELLBOARD_VERSION)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_HV_CELLBOARD_VERSION] > PRIMARY_INTERVAL_HV_CELLBOARD_VERSION * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_HV_CELLBOARD_VERSION);
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
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_HV_SET_FANS_STATUS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_HV_SET_FANS_STATUS] > PRIMARY_INTERVAL_HV_SET_FANS_STATUS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_HV_SET_FANS_STATUS);
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
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_LV_FEEDBACK_ENCLOSURE_VOLTAGE)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_LV_FEEDBACK_ENCLOSURE_VOLTAGE] > PRIMARY_INTERVAL_LV_FEEDBACK_ENCLOSURE_VOLTAGE * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_LV_FEEDBACK_ENCLOSURE_VOLTAGE);
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
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_CONTROL_OUTPUT)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_CONTROL_OUTPUT] > PRIMARY_INTERVAL_CONTROL_OUTPUT * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_CONTROL_OUTPUT);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_CONTROL_STATUS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_CONTROL_STATUS] > PRIMARY_INTERVAL_CONTROL_STATUS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_CONTROL_STATUS);
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

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_LV_CURRENT_BATTERY)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_LV_CURRENT_BATTERY] > PRIMARY_INTERVAL_LV_CURRENT_BATTERY * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_LV_CURRENT_BATTERY);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_LV_CURRENT_CHARGER)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_LV_CURRENT_CHARGER] > PRIMARY_INTERVAL_LV_CURRENT_CHARGER * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_LV_CURRENT_CHARGER);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_LV_TOTAL_VOLTAGE)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_LV_TOTAL_VOLTAGE] > PRIMARY_INTERVAL_LV_TOTAL_VOLTAGE * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_LV_TOTAL_VOLTAGE);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_LV_CELLS_VOLTAGE)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_LV_CELLS_VOLTAGE] > PRIMARY_INTERVAL_LV_CELLS_VOLTAGE * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_LV_CELLS_VOLTAGE);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_LV_CELLS_VOLTAGE_STATS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_LV_CELLS_VOLTAGE_STATS] > PRIMARY_INTERVAL_LV_CELLS_VOLTAGE_STATS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_LV_CELLS_VOLTAGE_STATS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_LV_CELLS_TEMP)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_LV_CELLS_TEMP] > PRIMARY_INTERVAL_LV_CELLS_TEMP * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_LV_CELLS_TEMP);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_LV_CELLS_TEMP_STATS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_LV_CELLS_TEMP_STATS] > PRIMARY_INTERVAL_LV_CELLS_TEMP_STATS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_LV_CELLS_TEMP_STATS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_HV_CURRENT)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_HV_CURRENT] > PRIMARY_INTERVAL_HV_CURRENT * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_HV_CURRENT);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_HV_POWER)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_HV_POWER] > PRIMARY_INTERVAL_HV_POWER * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_HV_POWER);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_HV_ENERGY)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_HV_ENERGY] > PRIMARY_INTERVAL_HV_ENERGY * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_HV_ENERGY);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_HV_SOC)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_HV_SOC] > PRIMARY_INTERVAL_HV_SOC * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_HV_SOC);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_HV_TOTAL_VOLTAGE)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_HV_TOTAL_VOLTAGE] > PRIMARY_INTERVAL_HV_TOTAL_VOLTAGE * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_HV_TOTAL_VOLTAGE);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_HV_CELLS_VOLTAGE)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_HV_CELLS_VOLTAGE] > PRIMARY_INTERVAL_HV_CELLS_VOLTAGE * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_HV_CELLS_VOLTAGE);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_HV_CELLS_VOLTAGE_STATS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_HV_CELLS_VOLTAGE_STATS] > PRIMARY_INTERVAL_HV_CELLS_VOLTAGE_STATS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_HV_CELLS_VOLTAGE_STATS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_HV_CELLS_TEMP)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_HV_CELLS_TEMP] > PRIMARY_INTERVAL_HV_CELLS_TEMP * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_HV_CELLS_TEMP);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_HV_CELLS_TEMP_STATS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_HV_CELLS_TEMP_STATS] > PRIMARY_INTERVAL_HV_CELLS_TEMP_STATS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_HV_CELLS_TEMP_STATS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_DEBUG_SIGNAL_1)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_DEBUG_SIGNAL_1] > PRIMARY_INTERVAL_DEBUG_SIGNAL_1 * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_DEBUG_SIGNAL_1);
    }

}


