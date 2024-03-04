#include "primary_watchdog.h"


int primary_watchdog_interval_from_id(uint16_t message_id) {
    switch (message_id) {
       case 700: return PRIMARY_INTERVAL_STEER_VERSION;
       case 701: return PRIMARY_INTERVAL_DAS_VERSION;
       case 702: return PRIMARY_INTERVAL_MAINBOARD_VERSION;
       case 703: return PRIMARY_INTERVAL_LV_VERSION;
       case 704: return PRIMARY_INTERVAL_TLM_VERSION;
       case 705: return PRIMARY_INTERVAL_CELLBOARD_VERSION;
       case 257: return PRIMARY_INTERVAL_AMBIENT_TEMPERATURE;
       case 1072: return PRIMARY_INTERVAL_DATA_LOGGER;
       case 264: return PRIMARY_INTERVAL_TLM_STATUS;
       case 1801: return PRIMARY_INTERVAL_STEER_SYSTEM_STATUS;
       case 772: return PRIMARY_INTERVAL_HV_VOLTAGE;
       case 804: return PRIMARY_INTERVAL_HV_CELL_VOLTAGE;
       case 836: return PRIMARY_INTERVAL_HV_CURRENT;
       case 868: return PRIMARY_INTERVAL_HV_TEMP;
       case 36: return PRIMARY_INTERVAL_HV_ERRORS;
       case 260: return PRIMARY_INTERVAL_HV_DEBUG_SIGNALS;
       case 84: return PRIMARY_INTERVAL_TS_STATUS;
       case 82: return PRIMARY_INTERVAL_SET_TS_STATUS_DAS;
       case 83: return PRIMARY_INTERVAL_SET_TS_STATUS_HANDCART;
       case 258: return PRIMARY_INTERVAL_STEER_STATUS;
       case 81: return PRIMARY_INTERVAL_CAR_STATUS;
       case 40: return PRIMARY_INTERVAL_DAS_ERRORS;
       case 777: return PRIMARY_INTERVAL_ECU_FEEDBACKS;
       case 809: return PRIMARY_INTERVAL_LV_STATUS;
       case 835: return PRIMARY_INTERVAL_LV_CURRENTS;
       case 867: return PRIMARY_INTERVAL_LV_CELLS_VOLTAGE;
       case 899: return PRIMARY_INTERVAL_LV_TOTAL_VOLTAGE;
       case 931: return PRIMARY_INTERVAL_LV_CELLS_TEMP;
       case 963: return PRIMARY_INTERVAL_COOLING_STATUS;
       case 263: return PRIMARY_INTERVAL_SET_INVERTER_CONNECTION_STATUS;
       case 259: return PRIMARY_INTERVAL_INVERTER_CONNECTION_STATUS;
       case 515: return PRIMARY_INTERVAL_LV_ERRORS;
       case 291: return PRIMARY_INTERVAL_LV_HEALTH_SIGNALS;
       case 323: return PRIMARY_INTERVAL_LV_FEEDBACKS;
       case 355: return PRIMARY_INTERVAL_SHUTDOWN_STATUS;
       case 1865: return PRIMARY_INTERVAL_LV_CAN_FLASH_ACK;
       case 517: return PRIMARY_INTERVAL_HV_CELLS_VOLTAGE;
       case 549: return PRIMARY_INTERVAL_HV_CELLS_TEMP;
       case 581: return PRIMARY_INTERVAL_HV_CELL_BALANCING_STATUS;
       case 520: return PRIMARY_INTERVAL_SPEED;
       case 513: return PRIMARY_INTERVAL_INV_L_REQUEST;
       case 514: return PRIMARY_INTERVAL_INV_R_REQUEST;
       case 385: return PRIMARY_INTERVAL_INV_L_RESPONSE;
       case 386: return PRIMARY_INTERVAL_INV_R_RESPONSE;
       case 296: return PRIMARY_INTERVAL_CONTROL_OUTPUT;
       case 768: return PRIMARY_INTERVAL_HANDCART_STATUS;
       case 800: return PRIMARY_INTERVAL_HANDCART_SETTINGS;
       case 832: return PRIMARY_INTERVAL_HANDCART_SETTINGS_SET;
       case 1027: return PRIMARY_INTERVAL_REGEN_MANUAL_COMMAND;

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
       case 0: return PRIMARY_INDEX_BMS_HV_JMP_TO_BLT;
       case 1: return PRIMARY_INDEX_FLASH_BMS_HV_TX;
       case 2: return PRIMARY_INDEX_FLASH_BMS_HV_RX;
       case 3: return PRIMARY_INDEX_HV_CAN_FORWARD;
       case 4: return PRIMARY_INDEX_FLASH_CELLBOARD_0_TX;
       case 5: return PRIMARY_INDEX_FLASH_CELLBOARD_0_RX;
       case 6: return PRIMARY_INDEX_FLASH_CELLBOARD_1_TX;
       case 7: return PRIMARY_INDEX_FLASH_CELLBOARD_1_RX;
       case 8: return PRIMARY_INDEX_FLASH_CELLBOARD_2_TX;
       case 9: return PRIMARY_INDEX_FLASH_CELLBOARD_2_RX;
       case 10: return PRIMARY_INDEX_FLASH_CELLBOARD_3_TX;
       case 11: return PRIMARY_INDEX_FLASH_CELLBOARD_3_RX;
       case 12: return PRIMARY_INDEX_FLASH_CELLBOARD_4_TX;
       case 13: return PRIMARY_INDEX_FLASH_CELLBOARD_4_RX;
       case 14: return PRIMARY_INDEX_FLASH_CELLBOARD_5_TX;
       case 15: return PRIMARY_INDEX_FLASH_CELLBOARD_5_RX;
       case 16: return PRIMARY_INDEX_BMS_LV_JMP_TO_BLT;
       case 17: return PRIMARY_INDEX_FLASH_BMS_LV_TX;
       case 18: return PRIMARY_INDEX_FLASH_BMS_LV_RX;
       case 19: return PRIMARY_INDEX_ECU_JMP_TO_BLT;
       case 20: return PRIMARY_INDEX_FLASH_ECU_TX;
       case 21: return PRIMARY_INDEX_FLASH_ECU_RX;
       case 22: return PRIMARY_INDEX_STEERING_JMP_TO_BLT;
       case 23: return PRIMARY_INDEX_FLASH_STEERING_TX;
       case 24: return PRIMARY_INDEX_FLASH_STEERING_RX;
       case 700: return PRIMARY_INDEX_STEER_VERSION;
       case 701: return PRIMARY_INDEX_DAS_VERSION;
       case 702: return PRIMARY_INDEX_MAINBOARD_VERSION;
       case 703: return PRIMARY_INDEX_LV_VERSION;
       case 704: return PRIMARY_INDEX_TLM_VERSION;
       case 705: return PRIMARY_INDEX_CELLBOARD_VERSION;
       case 257: return PRIMARY_INDEX_AMBIENT_TEMPERATURE;
       case 1072: return PRIMARY_INDEX_DATA_LOGGER;
       case 265: return PRIMARY_INDEX_SET_TLM_STATUS;
       case 264: return PRIMARY_INDEX_TLM_STATUS;
       case 1801: return PRIMARY_INDEX_STEER_SYSTEM_STATUS;
       case 772: return PRIMARY_INDEX_HV_VOLTAGE;
       case 804: return PRIMARY_INDEX_HV_CELL_VOLTAGE;
       case 836: return PRIMARY_INDEX_HV_CURRENT;
       case 868: return PRIMARY_INDEX_HV_TEMP;
       case 36: return PRIMARY_INDEX_HV_ERRORS;
       case 260: return PRIMARY_INDEX_HV_DEBUG_SIGNALS;
       case 32: return PRIMARY_INDEX_HV_FANS_OVERRIDE;
       case 37: return PRIMARY_INDEX_HV_CAN_FORWARD_STATUS;
       case 773: return PRIMARY_INDEX_HV_FANS_OVERRIDE_STATUS;
       case 771: return PRIMARY_INDEX_HV_FEEDBACK_STATUS;
       case 516: return PRIMARY_INDEX_HV_FEEDBACK_TS_VOLTAGE;
       case 548: return PRIMARY_INDEX_HV_FEEDBACK_MISC_VOLTAGE;
       case 580: return PRIMARY_INDEX_HV_FEEDBACK_SD_VOLTAGE;
       case 803: return PRIMARY_INDEX_HV_IMD_STATUS;
       case 84: return PRIMARY_INDEX_TS_STATUS;
       case 82: return PRIMARY_INDEX_SET_TS_STATUS_DAS;
       case 83: return PRIMARY_INDEX_SET_TS_STATUS_HANDCART;
       case 258: return PRIMARY_INDEX_STEER_STATUS;
       case 80: return PRIMARY_INDEX_SET_CAR_STATUS;
       case 1026: return PRIMARY_INDEX_SET_PEDAL_CALIBRATION;
       case 1032: return PRIMARY_INDEX_PEDAL_CALIBRATION_ACK;
       case 81: return PRIMARY_INDEX_CAR_STATUS;
       case 40: return PRIMARY_INDEX_DAS_ERRORS;
       case 777: return PRIMARY_INDEX_ECU_FEEDBACKS;
       case 809: return PRIMARY_INDEX_LV_STATUS;
       case 835: return PRIMARY_INDEX_LV_CURRENTS;
       case 867: return PRIMARY_INDEX_LV_CELLS_VOLTAGE;
       case 899: return PRIMARY_INDEX_LV_TOTAL_VOLTAGE;
       case 931: return PRIMARY_INDEX_LV_CELLS_TEMP;
       case 963: return PRIMARY_INDEX_COOLING_STATUS;
       case 775: return PRIMARY_INDEX_SET_RADIATOR_SPEED;
       case 807: return PRIMARY_INDEX_SET_PUMPS_SPEED;
       case 263: return PRIMARY_INDEX_SET_INVERTER_CONNECTION_STATUS;
       case 259: return PRIMARY_INDEX_INVERTER_CONNECTION_STATUS;
       case 515: return PRIMARY_INDEX_LV_ERRORS;
       case 291: return PRIMARY_INDEX_LV_HEALTH_SIGNALS;
       case 323: return PRIMARY_INDEX_LV_FEEDBACKS;
       case 355: return PRIMARY_INDEX_SHUTDOWN_STATUS;
       case 1833: return PRIMARY_INDEX_LV_CAN_FLASH_REQ;
       case 1865: return PRIMARY_INDEX_LV_CAN_FLASH_ACK;
       case 41: return PRIMARY_INDEX_MARKER;
       case 517: return PRIMARY_INDEX_HV_CELLS_VOLTAGE;
       case 549: return PRIMARY_INDEX_HV_CELLS_TEMP;
       case 581: return PRIMARY_INDEX_HV_CELL_BALANCING_STATUS;
       case 512: return PRIMARY_INDEX_SET_CELL_BALANCING_STATUS;
       case 520: return PRIMARY_INDEX_SPEED;
       case 513: return PRIMARY_INDEX_INV_L_REQUEST;
       case 514: return PRIMARY_INDEX_INV_R_REQUEST;
       case 385: return PRIMARY_INDEX_INV_L_RESPONSE;
       case 386: return PRIMARY_INDEX_INV_R_RESPONSE;
       case 296: return PRIMARY_INDEX_CONTROL_OUTPUT;
       case 518: return PRIMARY_INDEX_LC_RESET;
       case 768: return PRIMARY_INDEX_HANDCART_STATUS;
       case 800: return PRIMARY_INDEX_HANDCART_SETTINGS;
       case 832: return PRIMARY_INDEX_HANDCART_SETTINGS_SET;
       case 547: return PRIMARY_INDEX_SET_PTT_STATUS;
       case 579: return PRIMARY_INDEX_PTT_STATUS;
       case 1027: return PRIMARY_INDEX_REGEN_MANUAL_COMMAND;

    }
    return -1;
}

void primary_watchdog_free(primary_watchdog *watchdog) {
    free(watchdog);
}

void primary_watchdog_reset(primary_watchdog *watchdog, canlib_message_id id, canlib_watchdog_timestamp timestamp) {
    int index = primary_watchdog_index_from_id(id);
    if (index < 102 && CANLIB_BITTEST_ARRAY(watchdog->activated, index)) {
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
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_STEER_VERSION)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_STEER_VERSION] > PRIMARY_INTERVAL_STEER_VERSION * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_STEER_VERSION);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_DAS_VERSION)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_DAS_VERSION] > PRIMARY_INTERVAL_DAS_VERSION * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_DAS_VERSION);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_MAINBOARD_VERSION)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_MAINBOARD_VERSION] > PRIMARY_INTERVAL_MAINBOARD_VERSION * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_MAINBOARD_VERSION);
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
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_CELLBOARD_VERSION)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_CELLBOARD_VERSION] > PRIMARY_INTERVAL_CELLBOARD_VERSION * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_CELLBOARD_VERSION);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_AMBIENT_TEMPERATURE)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_AMBIENT_TEMPERATURE] > PRIMARY_INTERVAL_AMBIENT_TEMPERATURE * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_AMBIENT_TEMPERATURE);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_DATA_LOGGER)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_DATA_LOGGER] > PRIMARY_INTERVAL_DATA_LOGGER * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_DATA_LOGGER);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_TLM_STATUS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_TLM_STATUS] > PRIMARY_INTERVAL_TLM_STATUS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_TLM_STATUS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_STEER_SYSTEM_STATUS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_STEER_SYSTEM_STATUS] > PRIMARY_INTERVAL_STEER_SYSTEM_STATUS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_STEER_SYSTEM_STATUS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_HV_VOLTAGE)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_HV_VOLTAGE] > PRIMARY_INTERVAL_HV_VOLTAGE * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_HV_VOLTAGE);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_HV_CELL_VOLTAGE)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_HV_CELL_VOLTAGE] > PRIMARY_INTERVAL_HV_CELL_VOLTAGE * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_HV_CELL_VOLTAGE);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_HV_CURRENT)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_HV_CURRENT] > PRIMARY_INTERVAL_HV_CURRENT * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_HV_CURRENT);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_HV_TEMP)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_HV_TEMP] > PRIMARY_INTERVAL_HV_TEMP * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_HV_TEMP);
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
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_TS_STATUS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_TS_STATUS] > PRIMARY_INTERVAL_TS_STATUS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_TS_STATUS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_SET_TS_STATUS_DAS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_SET_TS_STATUS_DAS] > PRIMARY_INTERVAL_SET_TS_STATUS_DAS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_SET_TS_STATUS_DAS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_SET_TS_STATUS_HANDCART)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_SET_TS_STATUS_HANDCART] > PRIMARY_INTERVAL_SET_TS_STATUS_HANDCART * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_SET_TS_STATUS_HANDCART);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_STEER_STATUS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_STEER_STATUS] > PRIMARY_INTERVAL_STEER_STATUS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_STEER_STATUS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_CAR_STATUS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_CAR_STATUS] > PRIMARY_INTERVAL_CAR_STATUS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_CAR_STATUS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_DAS_ERRORS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_DAS_ERRORS] > PRIMARY_INTERVAL_DAS_ERRORS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_DAS_ERRORS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_ECU_FEEDBACKS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_ECU_FEEDBACKS] > PRIMARY_INTERVAL_ECU_FEEDBACKS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_ECU_FEEDBACKS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_LV_STATUS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_LV_STATUS] > PRIMARY_INTERVAL_LV_STATUS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_LV_STATUS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_LV_CURRENTS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_LV_CURRENTS] > PRIMARY_INTERVAL_LV_CURRENTS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_LV_CURRENTS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_LV_CELLS_VOLTAGE)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_LV_CELLS_VOLTAGE] > PRIMARY_INTERVAL_LV_CELLS_VOLTAGE * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_LV_CELLS_VOLTAGE);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_LV_TOTAL_VOLTAGE)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_LV_TOTAL_VOLTAGE] > PRIMARY_INTERVAL_LV_TOTAL_VOLTAGE * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_LV_TOTAL_VOLTAGE);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_LV_CELLS_TEMP)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_LV_CELLS_TEMP] > PRIMARY_INTERVAL_LV_CELLS_TEMP * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_LV_CELLS_TEMP);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_COOLING_STATUS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_COOLING_STATUS] > PRIMARY_INTERVAL_COOLING_STATUS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_COOLING_STATUS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_SET_INVERTER_CONNECTION_STATUS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_SET_INVERTER_CONNECTION_STATUS] > PRIMARY_INTERVAL_SET_INVERTER_CONNECTION_STATUS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_SET_INVERTER_CONNECTION_STATUS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_INVERTER_CONNECTION_STATUS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_INVERTER_CONNECTION_STATUS] > PRIMARY_INTERVAL_INVERTER_CONNECTION_STATUS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_INVERTER_CONNECTION_STATUS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_LV_ERRORS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_LV_ERRORS] > PRIMARY_INTERVAL_LV_ERRORS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_LV_ERRORS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_LV_HEALTH_SIGNALS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_LV_HEALTH_SIGNALS] > PRIMARY_INTERVAL_LV_HEALTH_SIGNALS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_LV_HEALTH_SIGNALS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_LV_FEEDBACKS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_LV_FEEDBACKS] > PRIMARY_INTERVAL_LV_FEEDBACKS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_LV_FEEDBACKS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_SHUTDOWN_STATUS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_SHUTDOWN_STATUS] > PRIMARY_INTERVAL_SHUTDOWN_STATUS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_SHUTDOWN_STATUS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_LV_CAN_FLASH_ACK)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_LV_CAN_FLASH_ACK] > PRIMARY_INTERVAL_LV_CAN_FLASH_ACK * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_LV_CAN_FLASH_ACK);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_HV_CELLS_VOLTAGE)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_HV_CELLS_VOLTAGE] > PRIMARY_INTERVAL_HV_CELLS_VOLTAGE * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_HV_CELLS_VOLTAGE);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_HV_CELLS_TEMP)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_HV_CELLS_TEMP] > PRIMARY_INTERVAL_HV_CELLS_TEMP * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_HV_CELLS_TEMP);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_HV_CELL_BALANCING_STATUS)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_HV_CELL_BALANCING_STATUS] > PRIMARY_INTERVAL_HV_CELL_BALANCING_STATUS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_HV_CELL_BALANCING_STATUS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_SPEED)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_SPEED] > PRIMARY_INTERVAL_SPEED * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_SPEED);
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

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_CONTROL_OUTPUT)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_CONTROL_OUTPUT] > PRIMARY_INTERVAL_CONTROL_OUTPUT * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_CONTROL_OUTPUT);
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
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_HANDCART_SETTINGS_SET)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_HANDCART_SETTINGS_SET] > PRIMARY_INTERVAL_HANDCART_SETTINGS_SET * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_HANDCART_SETTINGS_SET);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, PRIMARY_INDEX_REGEN_MANUAL_COMMAND)
        && timestamp - watchdog->last_reset[PRIMARY_INDEX_REGEN_MANUAL_COMMAND] > PRIMARY_INTERVAL_REGEN_MANUAL_COMMAND * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, PRIMARY_INDEX_REGEN_MANUAL_COMMAND);
    }

}


