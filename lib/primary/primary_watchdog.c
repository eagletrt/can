#include "primary_watchdog.h"


int primary_watchdog_interval_from_id(uint16_t message_id) {
    switch (message_id) {
       case 0: return PRIMARY_INTERVAL_HV_FLASH;
       case 700: return PRIMARY_INTERVAL_STEERING_WHEEL_VERSION;
       case 701: return PRIMARY_INTERVAL_ECU_VERSION;
       case 703: return PRIMARY_INTERVAL_LV_VERSION;
       case 704: return PRIMARY_INTERVAL_TLM_VERSION;
       case 702: return PRIMARY_INTERVAL_HV_MAINBOARD_VERSION;
       case 705: return PRIMARY_INTERVAL_HV_CELLBOARD_VERSION;
       case 32: return PRIMARY_INTERVAL_HV_ERRORS;
       case 512: return PRIMARY_INTERVAL_HV_DEBUG_SIGNALS;
       case 1536: return PRIMARY_INTERVAL_HV_FANS_STATUS;
       case 1024: return PRIMARY_INTERVAL_HV_SET_FANS_STATUS;
       case 520: return PRIMARY_INTERVAL_HV_FEEDBACK_STATUS;
       case 528: return PRIMARY_INTERVAL_HV_FEEDBACK_TS_VOLTAGE;
       case 536: return PRIMARY_INTERVAL_HV_FEEDBACK_MISC_VOLTAGE;
       case 544: return PRIMARY_INTERVAL_HV_FEEDBACK_SD_VOLTAGE;
       case 552: return PRIMARY_INTERVAL_HV_IMD_STATUS;
       case 560: return PRIMARY_INTERVAL_HV_STATUS;
       case 40: return PRIMARY_INTERVAL_HV_SET_STATUS_ECU;
       case 48: return PRIMARY_INTERVAL_HV_SET_STATUS_HANDCART;
       case 1544: return PRIMARY_INTERVAL_HV_BALANCING_STATUS;
       case 1032: return PRIMARY_INTERVAL_HV_SET_BALANCING_STATUS_STEERING_WHEEL;
       case 1040: return PRIMARY_INTERVAL_HV_SET_BALANCING_STATUS_HANDCART;
       case 568: return PRIMARY_INTERVAL_LV_STATUS;
       case 1568: return PRIMARY_INTERVAL_LV_CHARGING_STATUS;
       case 1576: return PRIMARY_INTERVAL_LV_COOLING_AGGRESSIVENESS;
       case 1584: return PRIMARY_INTERVAL_LV_RADIATOR_SPEED;
       case 1592: return PRIMARY_INTERVAL_LV_PUMPS_SPEED;
       case 1056: return PRIMARY_INTERVAL_LV_SET_RADIATOR_SPEED;
       case 1064: return PRIMARY_INTERVAL_LV_SET_PUMPS_SPEED;
       case 576: return PRIMARY_INTERVAL_LV_ERRORS;
       case 584: return PRIMARY_INTERVAL_LV_FEEDBACK;
       case 592: return PRIMARY_INTERVAL_LV_FEEDBACK_TS_VOLTAGE;
       case 600: return PRIMARY_INTERVAL_LV_FEEDBACK_SD_VOLTAGE;
       case 608: return PRIMARY_INTERVAL_LV_FEEDBACK_ENCLOSURE_VOLTAGE;
       case 616: return PRIMARY_INTERVAL_LV_FEEDBACK_GPIO_EXTENDER;
       case 624: return PRIMARY_INTERVAL_LV_INVERTER_CONNECTION_STATUS;
       case 80: return PRIMARY_INTERVAL_LV_SET_INVERTER_CONNECTION_STATUS;
       case 1600: return PRIMARY_INTERVAL_TLM_STATUS;
       case 1072: return PRIMARY_INTERVAL_TLM_SET_STATUS;
       case 632: return PRIMARY_INTERVAL_HANDCART_STATUS;
       case 1608: return PRIMARY_INTERVAL_HANDCART_SETTINGS;
       case 1080: return PRIMARY_INTERVAL_HANDCART_SET_SETTINGS;
       case 640: return PRIMARY_INTERVAL_ECU_STATUS;
       case 88: return PRIMARY_INTERVAL_ECU_SET_STATUS;
       case 1088: return PRIMARY_INTERVAL_ECU_INVERTER_STATUS;
       case 648: return PRIMARY_INTERVAL_ECU_CONTROL_STATUS;
       case 656: return PRIMARY_INTERVAL_ECU_ERRORS;
       case 664: return PRIMARY_INTERVAL_ECU_FEEDBACKS;
       case 672: return PRIMARY_INTERVAL_ECU_POWER_MAPS;
       case 96: return PRIMARY_INTERVAL_ECU_SET_POWER_MAPS;
       case 1616: return PRIMARY_INTERVAL_ECU_PTT_STATUS;
       case 1096: return PRIMARY_INTERVAL_ECU_SET_PTT_STATUS;
       case 513: return PRIMARY_INTERVAL_INV_L_REQUEST;
       case 680: return PRIMARY_INTERVAL_CONTROL_OUTPUT;
       case 688: return PRIMARY_INTERVAL_CONTROL_STATUS;
       case 514: return PRIMARY_INTERVAL_INV_R_REQUEST;
       case 385: return PRIMARY_INTERVAL_INV_L_RESPONSE;
       case 386: return PRIMARY_INTERVAL_INV_R_RESPONSE;
       case 1624: return PRIMARY_INTERVAL_LV_CURRENT_BATTERY;
       case 1632: return PRIMARY_INTERVAL_LV_CURRENT_CHARGER;
       case 1640: return PRIMARY_INTERVAL_LV_TOTAL_VOLTAGE;
       case 1648: return PRIMARY_INTERVAL_LV_CELLS_VOLTAGE;
       case 1656: return PRIMARY_INTERVAL_LV_CELLS_VOLTAGE_STATS;
       case 1664: return PRIMARY_INTERVAL_LV_CELLS_TEMP;
       case 1672: return PRIMARY_INTERVAL_LV_CELLS_TEMP_STATS;
       case 1680: return PRIMARY_INTERVAL_HV_CURRENT;
       case 1688: return PRIMARY_INTERVAL_HV_POWER;
       case 1696: return PRIMARY_INTERVAL_HV_ENERGY;
       case 1704: return PRIMARY_INTERVAL_HV_SOC;
       case 1712: return PRIMARY_INTERVAL_HV_TOTAL_VOLTAGE;
       case 1720: return PRIMARY_INTERVAL_HV_CELLS_VOLTAGE;
       case 1728: return PRIMARY_INTERVAL_HV_CELLS_VOLTAGE_STATS;
       case 1736: return PRIMARY_INTERVAL_HV_CELLS_TEMP;
       case 1744: return PRIMARY_INTERVAL_HV_CELLS_TEMP_STATS;
       case 1752: return PRIMARY_INTERVAL_AS_COMMANDS_STATUS;
       case 1104: return PRIMARY_INTERVAL_AS_COMMANDS_SET_STATUS;
       case 1760: return PRIMARY_INTERVAL_AS_COMMANDS_SET_VALUE;
       case 1768: return PRIMARY_INTERVAL_ECU_STEER_ACTUATOR_CURRENT;
       case 1776: return PRIMARY_INTERVAL_DEBUG_SIGNAL_CRASH_DEBUG;
       case 1784: return PRIMARY_INTERVAL_DEBUG_SIGNAL_CRASH_DEBUG_ACK;
       case 1792: return PRIMARY_INTERVAL_DEBUG_SIGNAL_1;
       case 1800: return PRIMARY_INTERVAL_DEBUG_SIGNAL_2;
       case 1808: return PRIMARY_INTERVAL_DEBUG_SIGNAL_3;
       case 1824: return PRIMARY_INTERVAL_DEBUG_SIGNAL_4;
       case 1112: return PRIMARY_INTERVAL_HV_TS_VOLTAGE;
       case 1832: return PRIMARY_INTERVAL_HV_CELLS_TEMPERATURE;
       case 1840: return PRIMARY_INTERVAL_HV_DISCHARGE_TEMPERATURE;
       case 1848: return PRIMARY_INTERVAL_HV_COOLING_TEMPERATURE;
       case 256: return PRIMARY_INTERVAL_CHARGER_1;
       case 272: return PRIMARY_INTERVAL_CHARGER_2;
       case 288: return PRIMARY_INTERVAL_CHARGER_3;
       case 304: return PRIMARY_INTERVAL_CHARGER_4;
       case 320: return PRIMARY_INTERVAL_CHARGER_5;
       case 336: return PRIMARY_INTERVAL_CHARGER_6;
       case 344: return PRIMARY_INTERVAL_CHARGER_7;
       case 352: return PRIMARY_INTERVAL_CHARGER_8;
       case 368: return PRIMARY_INTERVAL_CHARGER_9;
       case 384: return PRIMARY_INTERVAL_CHARGER_10;
       case 392: return PRIMARY_INTERVAL_CHARGER_11;
       case 400: return PRIMARY_INTERVAL_CHARGER_12;
       case 408: return PRIMARY_INTERVAL_CHARGER_13;
       case 416: return PRIMARY_INTERVAL_CHARGER_14;
       case 432: return PRIMARY_INTERVAL_CHARGER_15;
       case 448: return PRIMARY_INTERVAL_CHARGER_16;
       case 464: return PRIMARY_INTERVAL_CHARGER_17;
       case 480: return PRIMARY_INTERVAL_CHARGER_18;
       case 496: return PRIMARY_INTERVAL_CHARGER_19;
       case 696: return PRIMARY_INTERVAL_HV_FEEDBACK_DIGITAL;
       case 712: return PRIMARY_INTERVAL_HV_FEEDBACK_ANALOG;
       case 720: return PRIMARY_INTERVAL_HV_FEEDBACK_ANALOG_SD;
       case 736: return PRIMARY_INTERVAL_HV_ERROR;

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
       case 0: return PRIMARY_INDEX_HV_FLASH;
       case 1: return PRIMARY_INDEX_HV_FLASH_MAINBOARD_TX;
       case 2: return PRIMARY_INDEX_HV_FLASH_MAINBOARD_RX;
       case 4: return PRIMARY_INDEX_HV_FLASH_CELLBOARD_0_TX;
       case 5: return PRIMARY_INDEX_HV_FLASH_CELLBOARD_0_RX;
       case 6: return PRIMARY_INDEX_HV_FLASH_CELLBOARD_1_TX;
       case 7: return PRIMARY_INDEX_HV_FLASH_CELLBOARD_1_RX;
       case 8: return PRIMARY_INDEX_HV_FLASH_CELLBOARD_2_TX;
       case 9: return PRIMARY_INDEX_HV_FLASH_CELLBOARD_2_RX;
       case 10: return PRIMARY_INDEX_HV_FLASH_CELLBOARD_3_TX;
       case 11: return PRIMARY_INDEX_HV_FLASH_CELLBOARD_3_RX;
       case 12: return PRIMARY_INDEX_HV_FLASH_CELLBOARD_4_TX;
       case 13: return PRIMARY_INDEX_HV_FLASH_CELLBOARD_4_RX;
       case 14: return PRIMARY_INDEX_HV_FLASH_CELLBOARD_5_TX;
       case 15: return PRIMARY_INDEX_HV_FLASH_CELLBOARD_5_RX;
       case 16: return PRIMARY_INDEX_LV_JMP_TO_BLT;
       case 17: return PRIMARY_INDEX_LV_FLASH_TX;
       case 18: return PRIMARY_INDEX_LV_FLASH_RX;
       case 19: return PRIMARY_INDEX_ECU_JMP_TO_BLT;
       case 20: return PRIMARY_INDEX_ECU_FLASH_TX;
       case 21: return PRIMARY_INDEX_ECU_FLASH_RX;
       case 22: return PRIMARY_INDEX_STEERING_WHEEL_JMP_TO_BLT;
       case 23: return PRIMARY_INDEX_STEERING_WHEEL_FLASH_TX;
       case 24: return PRIMARY_INDEX_STEERING_WHEEL_FLASH_RX;
       case 700: return PRIMARY_INDEX_STEERING_WHEEL_VERSION;
       case 701: return PRIMARY_INDEX_ECU_VERSION;
       case 703: return PRIMARY_INDEX_LV_VERSION;
       case 704: return PRIMARY_INDEX_TLM_VERSION;
       case 702: return PRIMARY_INDEX_HV_MAINBOARD_VERSION;
       case 705: return PRIMARY_INDEX_HV_CELLBOARD_VERSION;
       case 32: return PRIMARY_INDEX_HV_ERRORS;
       case 512: return PRIMARY_INDEX_HV_DEBUG_SIGNALS;
       case 1536: return PRIMARY_INDEX_HV_FANS_STATUS;
       case 1024: return PRIMARY_INDEX_HV_SET_FANS_STATUS;
       case 520: return PRIMARY_INDEX_HV_FEEDBACK_STATUS;
       case 528: return PRIMARY_INDEX_HV_FEEDBACK_TS_VOLTAGE;
       case 536: return PRIMARY_INDEX_HV_FEEDBACK_MISC_VOLTAGE;
       case 544: return PRIMARY_INDEX_HV_FEEDBACK_SD_VOLTAGE;
       case 552: return PRIMARY_INDEX_HV_IMD_STATUS;
       case 560: return PRIMARY_INDEX_HV_STATUS;
       case 40: return PRIMARY_INDEX_HV_SET_STATUS_ECU;
       case 48: return PRIMARY_INDEX_HV_SET_STATUS_HANDCART;
       case 1544: return PRIMARY_INDEX_HV_BALANCING_STATUS;
       case 1032: return PRIMARY_INDEX_HV_SET_BALANCING_STATUS_STEERING_WHEEL;
       case 1040: return PRIMARY_INDEX_HV_SET_BALANCING_STATUS_HANDCART;
       case 568: return PRIMARY_INDEX_LV_STATUS;
       case 1568: return PRIMARY_INDEX_LV_CHARGING_STATUS;
       case 1576: return PRIMARY_INDEX_LV_COOLING_AGGRESSIVENESS;
       case 1048: return PRIMARY_INDEX_LV_SET_COOLING_AGGRESSIVENESS;
       case 1584: return PRIMARY_INDEX_LV_RADIATOR_SPEED;
       case 1592: return PRIMARY_INDEX_LV_PUMPS_SPEED;
       case 1056: return PRIMARY_INDEX_LV_SET_RADIATOR_SPEED;
       case 1064: return PRIMARY_INDEX_LV_SET_PUMPS_SPEED;
       case 576: return PRIMARY_INDEX_LV_ERRORS;
       case 584: return PRIMARY_INDEX_LV_FEEDBACK;
       case 592: return PRIMARY_INDEX_LV_FEEDBACK_TS_VOLTAGE;
       case 600: return PRIMARY_INDEX_LV_FEEDBACK_SD_VOLTAGE;
       case 608: return PRIMARY_INDEX_LV_FEEDBACK_ENCLOSURE_VOLTAGE;
       case 616: return PRIMARY_INDEX_LV_FEEDBACK_GPIO_EXTENDER;
       case 56: return PRIMARY_INDEX_LV_CAN_FLASH_REQ_TLM;
       case 64: return PRIMARY_INDEX_LV_CAN_FLASH_REQ_STEERING_WHEEL;
       case 72: return PRIMARY_INDEX_LV_CAN_FLASH_ACK;
       case 624: return PRIMARY_INDEX_LV_INVERTER_CONNECTION_STATUS;
       case 80: return PRIMARY_INDEX_LV_SET_INVERTER_CONNECTION_STATUS;
       case 1600: return PRIMARY_INDEX_TLM_STATUS;
       case 1072: return PRIMARY_INDEX_TLM_SET_STATUS;
       case 632: return PRIMARY_INDEX_HANDCART_STATUS;
       case 1608: return PRIMARY_INDEX_HANDCART_SETTINGS;
       case 1080: return PRIMARY_INDEX_HANDCART_SET_SETTINGS;
       case 640: return PRIMARY_INDEX_ECU_STATUS;
       case 88: return PRIMARY_INDEX_ECU_SET_STATUS;
       case 1088: return PRIMARY_INDEX_ECU_INVERTER_STATUS;
       case 648: return PRIMARY_INDEX_ECU_CONTROL_STATUS;
       case 656: return PRIMARY_INDEX_ECU_ERRORS;
       case 664: return PRIMARY_INDEX_ECU_FEEDBACKS;
       case 672: return PRIMARY_INDEX_ECU_POWER_MAPS;
       case 96: return PRIMARY_INDEX_ECU_SET_POWER_MAPS;
       case 1616: return PRIMARY_INDEX_ECU_PTT_STATUS;
       case 1096: return PRIMARY_INDEX_ECU_SET_PTT_STATUS;
       case 513: return PRIMARY_INDEX_INV_L_REQUEST;
       case 680: return PRIMARY_INDEX_CONTROL_OUTPUT;
       case 688: return PRIMARY_INDEX_CONTROL_STATUS;
       case 514: return PRIMARY_INDEX_INV_R_REQUEST;
       case 385: return PRIMARY_INDEX_INV_L_RESPONSE;
       case 386: return PRIMARY_INDEX_INV_R_RESPONSE;
       case 1624: return PRIMARY_INDEX_LV_CURRENT_BATTERY;
       case 1632: return PRIMARY_INDEX_LV_CURRENT_CHARGER;
       case 1640: return PRIMARY_INDEX_LV_TOTAL_VOLTAGE;
       case 1648: return PRIMARY_INDEX_LV_CELLS_VOLTAGE;
       case 1656: return PRIMARY_INDEX_LV_CELLS_VOLTAGE_STATS;
       case 1664: return PRIMARY_INDEX_LV_CELLS_TEMP;
       case 1672: return PRIMARY_INDEX_LV_CELLS_TEMP_STATS;
       case 1680: return PRIMARY_INDEX_HV_CURRENT;
       case 1688: return PRIMARY_INDEX_HV_POWER;
       case 1696: return PRIMARY_INDEX_HV_ENERGY;
       case 1704: return PRIMARY_INDEX_HV_SOC;
       case 1712: return PRIMARY_INDEX_HV_TOTAL_VOLTAGE;
       case 1720: return PRIMARY_INDEX_HV_CELLS_VOLTAGE;
       case 1728: return PRIMARY_INDEX_HV_CELLS_VOLTAGE_STATS;
       case 1736: return PRIMARY_INDEX_HV_CELLS_TEMP;
       case 1744: return PRIMARY_INDEX_HV_CELLS_TEMP_STATS;
       case 1752: return PRIMARY_INDEX_AS_COMMANDS_STATUS;
       case 1104: return PRIMARY_INDEX_AS_COMMANDS_SET_STATUS;
       case 1760: return PRIMARY_INDEX_AS_COMMANDS_SET_VALUE;
       case 1768: return PRIMARY_INDEX_ECU_STEER_ACTUATOR_CURRENT;
       case 1776: return PRIMARY_INDEX_DEBUG_SIGNAL_CRASH_DEBUG;
       case 1784: return PRIMARY_INDEX_DEBUG_SIGNAL_CRASH_DEBUG_ACK;
       case 1792: return PRIMARY_INDEX_DEBUG_SIGNAL_1;
       case 1800: return PRIMARY_INDEX_DEBUG_SIGNAL_2;
       case 1808: return PRIMARY_INDEX_DEBUG_SIGNAL_3;
       case 1824: return PRIMARY_INDEX_DEBUG_SIGNAL_4;
       case 50: return PRIMARY_INDEX_HV_FLASH_REQUEST;
       case 51: return PRIMARY_INDEX_HV_FLASH_RESPONSE;
       case 1112: return PRIMARY_INDEX_HV_TS_VOLTAGE;
       case 1832: return PRIMARY_INDEX_HV_CELLS_TEMPERATURE;
       case 1840: return PRIMARY_INDEX_HV_DISCHARGE_TEMPERATURE;
       case 1848: return PRIMARY_INDEX_HV_COOLING_TEMPERATURE;
       case 256: return PRIMARY_INDEX_CHARGER_1;
       case 272: return PRIMARY_INDEX_CHARGER_2;
       case 288: return PRIMARY_INDEX_CHARGER_3;
       case 304: return PRIMARY_INDEX_CHARGER_4;
       case 320: return PRIMARY_INDEX_CHARGER_5;
       case 336: return PRIMARY_INDEX_CHARGER_6;
       case 344: return PRIMARY_INDEX_CHARGER_7;
       case 352: return PRIMARY_INDEX_CHARGER_8;
       case 368: return PRIMARY_INDEX_CHARGER_9;
       case 384: return PRIMARY_INDEX_CHARGER_10;
       case 392: return PRIMARY_INDEX_CHARGER_11;
       case 400: return PRIMARY_INDEX_CHARGER_12;
       case 408: return PRIMARY_INDEX_CHARGER_13;
       case 416: return PRIMARY_INDEX_CHARGER_14;
       case 432: return PRIMARY_INDEX_CHARGER_15;
       case 448: return PRIMARY_INDEX_CHARGER_16;
       case 464: return PRIMARY_INDEX_CHARGER_17;
       case 480: return PRIMARY_INDEX_CHARGER_18;
       case 496: return PRIMARY_INDEX_CHARGER_19;
       case 696: return PRIMARY_INDEX_HV_FEEDBACK_DIGITAL;
       case 712: return PRIMARY_INDEX_HV_FEEDBACK_ANALOG;
       case 720: return PRIMARY_INDEX_HV_FEEDBACK_ANALOG_SD;
       case 728: return PRIMARY_INDEX_HV_FEEDBACK_ENZOMMA;
       case 736: return PRIMARY_INDEX_HV_ERROR;

    }
    return -1;
}

void primary_watchdog_free(primary_watchdog *watchdog) {
    free(watchdog);
}

void primary_watchdog_reset(primary_watchdog *watchdog, canlib_message_id id, canlib_watchdog_timestamp timestamp) {
    int index = primary_watchdog_index_from_id(id);
    if (index < 149 && CANLIB_BITTEST_ARRAY(watchdog->activated, index)) {
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
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_HV_FLASH)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_HV_FLASH] > PRIMARY_INTERVAL_HV_FLASH * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_HV_FLASH);
    }

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
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_TLM_VERSION)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_TLM_VERSION] > PRIMARY_INTERVAL_TLM_VERSION * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_TLM_VERSION);
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
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_HV_SET_STATUS_ECU)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_HV_SET_STATUS_ECU] > PRIMARY_INTERVAL_HV_SET_STATUS_ECU * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_HV_SET_STATUS_ECU);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_HV_SET_STATUS_HANDCART)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_HV_SET_STATUS_HANDCART] > PRIMARY_INTERVAL_HV_SET_STATUS_HANDCART * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_HV_SET_STATUS_HANDCART);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_HV_BALANCING_STATUS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_HV_BALANCING_STATUS] > PRIMARY_INTERVAL_HV_BALANCING_STATUS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_HV_BALANCING_STATUS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_HV_SET_BALANCING_STATUS_STEERING_WHEEL)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_HV_SET_BALANCING_STATUS_STEERING_WHEEL] > PRIMARY_INTERVAL_HV_SET_BALANCING_STATUS_STEERING_WHEEL * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_HV_SET_BALANCING_STATUS_STEERING_WHEEL);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_HV_SET_BALANCING_STATUS_HANDCART)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_HV_SET_BALANCING_STATUS_HANDCART] > PRIMARY_INTERVAL_HV_SET_BALANCING_STATUS_HANDCART * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_HV_SET_BALANCING_STATUS_HANDCART);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_LV_STATUS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_LV_STATUS] > PRIMARY_INTERVAL_LV_STATUS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_LV_STATUS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_LV_CHARGING_STATUS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_LV_CHARGING_STATUS] > PRIMARY_INTERVAL_LV_CHARGING_STATUS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_LV_CHARGING_STATUS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_LV_COOLING_AGGRESSIVENESS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_LV_COOLING_AGGRESSIVENESS] > PRIMARY_INTERVAL_LV_COOLING_AGGRESSIVENESS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_LV_COOLING_AGGRESSIVENESS);
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
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_LV_SET_RADIATOR_SPEED)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_LV_SET_RADIATOR_SPEED] > PRIMARY_INTERVAL_LV_SET_RADIATOR_SPEED * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_LV_SET_RADIATOR_SPEED);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_LV_SET_PUMPS_SPEED)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_LV_SET_PUMPS_SPEED] > PRIMARY_INTERVAL_LV_SET_PUMPS_SPEED * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_LV_SET_PUMPS_SPEED);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_LV_ERRORS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_LV_ERRORS] > PRIMARY_INTERVAL_LV_ERRORS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_LV_ERRORS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_LV_FEEDBACK)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_LV_FEEDBACK] > PRIMARY_INTERVAL_LV_FEEDBACK * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_LV_FEEDBACK);
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
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_LV_SET_INVERTER_CONNECTION_STATUS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_LV_SET_INVERTER_CONNECTION_STATUS] > PRIMARY_INTERVAL_LV_SET_INVERTER_CONNECTION_STATUS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_LV_SET_INVERTER_CONNECTION_STATUS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_TLM_STATUS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_TLM_STATUS] > PRIMARY_INTERVAL_TLM_STATUS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_TLM_STATUS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_TLM_SET_STATUS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_TLM_SET_STATUS] > PRIMARY_INTERVAL_TLM_SET_STATUS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_TLM_SET_STATUS);
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
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_HANDCART_SET_SETTINGS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_HANDCART_SET_SETTINGS] > PRIMARY_INTERVAL_HANDCART_SET_SETTINGS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_HANDCART_SET_SETTINGS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_ECU_STATUS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_ECU_STATUS] > PRIMARY_INTERVAL_ECU_STATUS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_ECU_STATUS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_ECU_SET_STATUS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_ECU_SET_STATUS] > PRIMARY_INTERVAL_ECU_SET_STATUS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_ECU_SET_STATUS);
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
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_AS_COMMANDS_STATUS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_AS_COMMANDS_STATUS] > PRIMARY_INTERVAL_AS_COMMANDS_STATUS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_AS_COMMANDS_STATUS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_AS_COMMANDS_SET_STATUS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_AS_COMMANDS_SET_STATUS] > PRIMARY_INTERVAL_AS_COMMANDS_SET_STATUS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_AS_COMMANDS_SET_STATUS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_AS_COMMANDS_SET_VALUE)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_AS_COMMANDS_SET_VALUE] > PRIMARY_INTERVAL_AS_COMMANDS_SET_VALUE * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_AS_COMMANDS_SET_VALUE);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_ECU_STEER_ACTUATOR_CURRENT)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_ECU_STEER_ACTUATOR_CURRENT] > PRIMARY_INTERVAL_ECU_STEER_ACTUATOR_CURRENT * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_ECU_STEER_ACTUATOR_CURRENT);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_DEBUG_SIGNAL_CRASH_DEBUG)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_DEBUG_SIGNAL_CRASH_DEBUG] > PRIMARY_INTERVAL_DEBUG_SIGNAL_CRASH_DEBUG * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_DEBUG_SIGNAL_CRASH_DEBUG);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_DEBUG_SIGNAL_CRASH_DEBUG_ACK)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_DEBUG_SIGNAL_CRASH_DEBUG_ACK] > PRIMARY_INTERVAL_DEBUG_SIGNAL_CRASH_DEBUG_ACK * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_DEBUG_SIGNAL_CRASH_DEBUG_ACK);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_DEBUG_SIGNAL_1)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_DEBUG_SIGNAL_1] > PRIMARY_INTERVAL_DEBUG_SIGNAL_1 * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_DEBUG_SIGNAL_1);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_DEBUG_SIGNAL_2)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_DEBUG_SIGNAL_2] > PRIMARY_INTERVAL_DEBUG_SIGNAL_2 * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_DEBUG_SIGNAL_2);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_DEBUG_SIGNAL_3)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_DEBUG_SIGNAL_3] > PRIMARY_INTERVAL_DEBUG_SIGNAL_3 * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_DEBUG_SIGNAL_3);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_DEBUG_SIGNAL_4)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_DEBUG_SIGNAL_4] > PRIMARY_INTERVAL_DEBUG_SIGNAL_4 * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_DEBUG_SIGNAL_4);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_HV_TS_VOLTAGE)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_HV_TS_VOLTAGE] > PRIMARY_INTERVAL_HV_TS_VOLTAGE * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_HV_TS_VOLTAGE);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_HV_CELLS_TEMPERATURE)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_HV_CELLS_TEMPERATURE] > PRIMARY_INTERVAL_HV_CELLS_TEMPERATURE * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_HV_CELLS_TEMPERATURE);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_HV_DISCHARGE_TEMPERATURE)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_HV_DISCHARGE_TEMPERATURE] > PRIMARY_INTERVAL_HV_DISCHARGE_TEMPERATURE * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_HV_DISCHARGE_TEMPERATURE);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_HV_COOLING_TEMPERATURE)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_HV_COOLING_TEMPERATURE] > PRIMARY_INTERVAL_HV_COOLING_TEMPERATURE * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_HV_COOLING_TEMPERATURE);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_CHARGER_1)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_CHARGER_1] > PRIMARY_INTERVAL_CHARGER_1 * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_CHARGER_1);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_CHARGER_2)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_CHARGER_2] > PRIMARY_INTERVAL_CHARGER_2 * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_CHARGER_2);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_CHARGER_3)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_CHARGER_3] > PRIMARY_INTERVAL_CHARGER_3 * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_CHARGER_3);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_CHARGER_4)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_CHARGER_4] > PRIMARY_INTERVAL_CHARGER_4 * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_CHARGER_4);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_CHARGER_5)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_CHARGER_5] > PRIMARY_INTERVAL_CHARGER_5 * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_CHARGER_5);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_CHARGER_6)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_CHARGER_6] > PRIMARY_INTERVAL_CHARGER_6 * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_CHARGER_6);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_CHARGER_7)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_CHARGER_7] > PRIMARY_INTERVAL_CHARGER_7 * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_CHARGER_7);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_CHARGER_8)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_CHARGER_8] > PRIMARY_INTERVAL_CHARGER_8 * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_CHARGER_8);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_CHARGER_9)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_CHARGER_9] > PRIMARY_INTERVAL_CHARGER_9 * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_CHARGER_9);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_CHARGER_10)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_CHARGER_10] > PRIMARY_INTERVAL_CHARGER_10 * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_CHARGER_10);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_CHARGER_11)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_CHARGER_11] > PRIMARY_INTERVAL_CHARGER_11 * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_CHARGER_11);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_CHARGER_12)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_CHARGER_12] > PRIMARY_INTERVAL_CHARGER_12 * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_CHARGER_12);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_CHARGER_13)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_CHARGER_13] > PRIMARY_INTERVAL_CHARGER_13 * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_CHARGER_13);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_CHARGER_14)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_CHARGER_14] > PRIMARY_INTERVAL_CHARGER_14 * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_CHARGER_14);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_CHARGER_15)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_CHARGER_15] > PRIMARY_INTERVAL_CHARGER_15 * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_CHARGER_15);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_CHARGER_16)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_CHARGER_16] > PRIMARY_INTERVAL_CHARGER_16 * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_CHARGER_16);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_CHARGER_17)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_CHARGER_17] > PRIMARY_INTERVAL_CHARGER_17 * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_CHARGER_17);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_CHARGER_18)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_CHARGER_18] > PRIMARY_INTERVAL_CHARGER_18 * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_CHARGER_18);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_CHARGER_19)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_CHARGER_19] > PRIMARY_INTERVAL_CHARGER_19 * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_CHARGER_19);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_HV_FEEDBACK_DIGITAL)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_HV_FEEDBACK_DIGITAL] > PRIMARY_INTERVAL_HV_FEEDBACK_DIGITAL * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_HV_FEEDBACK_DIGITAL);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_HV_FEEDBACK_ANALOG)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_HV_FEEDBACK_ANALOG] > PRIMARY_INTERVAL_HV_FEEDBACK_ANALOG * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_HV_FEEDBACK_ANALOG);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_HV_FEEDBACK_ANALOG_SD)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_HV_FEEDBACK_ANALOG_SD] > PRIMARY_INTERVAL_HV_FEEDBACK_ANALOG_SD * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_HV_FEEDBACK_ANALOG_SD);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_HV_ERROR)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_HV_ERROR] > PRIMARY_INTERVAL_HV_ERROR * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_HV_ERROR);
    }

}


