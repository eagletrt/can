#include "bms_watchdog.h"


int bms_watchdog_interval_from_id(uint16_t message_id) {
    switch (message_id) {
       case 0: return BMS_INTERVAL_CELLBOARD_FLASH;
       case 1545: return BMS_INTERVAL_CELLBOARD_VERSION;
       case 513: return BMS_INTERVAL_CELLBOARD_STATUS;
       case 1553: return BMS_INTERVAL_CELLBOARD_CELLS_VOLTAGE;
       case 1561: return BMS_INTERVAL_CELLBOARD_CELLS_TEMPERATURE;
       case 1025: return BMS_INTERVAL_CELLBOARD_SET_BALANCING_STATUS;
       case 1569: return BMS_INTERVAL_CELLBOARD_BALANCING_STATUS;
       case 521: return BMS_INTERVAL_CELLBOARD_ERROR;

    }
    return -1;
}

int bms_watchdog_index_from_id(uint16_t message_id) {
    switch (message_id) {
       case 1320: return BMS_INDEX_IVT_MSG_RESULT_WH;
       case 1319: return BMS_INDEX_IVT_MSG_RESULT_AS;
       case 1318: return BMS_INDEX_IVT_MSG_RESULT_W;
       case 1297: return BMS_INDEX_IVT_MSG_RESPONSE;
       case 1317: return BMS_INDEX_IVT_MSG_RESULT_T;
       case 1316: return BMS_INDEX_IVT_MSG_RESULT_U3;
       case 1315: return BMS_INDEX_IVT_MSG_RESULT_U2;
       case 1314: return BMS_INDEX_IVT_MSG_RESULT_U1;
       case 1313: return BMS_INDEX_IVT_MSG_RESULT_I;
       case 1041: return BMS_INDEX_IVT_MSG_CMD;
       case 1026: return BMS_INDEX_BOARD_STATUS;
       case 515: return BMS_INDEX_TEMPERATURES_INFO;
       case 1539: return BMS_INDEX_TEMPERATURES;
       case 516: return BMS_INDEX_VOLTAGES_INFO;
       case 1540: return BMS_INDEX_VOLTAGES;
       case 16: return BMS_INDEX_SET_BALANCING_STATUS;
       case 5: return BMS_INDEX_FLASH_CELLBOARD_0_RX;
       case 6: return BMS_INDEX_FLASH_CELLBOARD_1_TX;
       case 7: return BMS_INDEX_FLASH_CELLBOARD_1_RX;
       case 8: return BMS_INDEX_FLASH_CELLBOARD_2_TX;
       case 9: return BMS_INDEX_FLASH_CELLBOARD_2_RX;
       case 10: return BMS_INDEX_FLASH_CELLBOARD_3_TX;
       case 11: return BMS_INDEX_FLASH_CELLBOARD_3_RX;
       case 12: return BMS_INDEX_FLASH_CELLBOARD_4_TX;
       case 13: return BMS_INDEX_FLASH_CELLBOARD_4_RX;
       case 14: return BMS_INDEX_FLASH_CELLBOARD_5_TX;
       case 15: return BMS_INDEX_FLASH_CELLBOARD_5_RX;
       case 0: return BMS_INDEX_CELLBOARD_FLASH;
       case 1: return BMS_INDEX_CELLBOARD_FLASH_TX;
       case 2: return BMS_INDEX_CELLBOARD_FLASH_RX;
       case 3: return BMS_INDEX_CELLBOARD_FLASH_REQUEST;
       case 4: return BMS_INDEX_CELLBOARD_FLASH_RESPONSE;
       case 1537: return BMS_INDEX_CELLBOARD_DISCOVERY;
       case 1545: return BMS_INDEX_CELLBOARD_VERSION;
       case 513: return BMS_INDEX_CELLBOARD_STATUS;
       case 1553: return BMS_INDEX_CELLBOARD_CELLS_VOLTAGE;
       case 1561: return BMS_INDEX_CELLBOARD_CELLS_TEMPERATURE;
       case 1025: return BMS_INDEX_CELLBOARD_SET_BALANCING_STATUS;
       case 1569: return BMS_INDEX_CELLBOARD_BALANCING_STATUS;
       case 521: return BMS_INDEX_CELLBOARD_ERROR;

    }
    return -1;
}

void bms_watchdog_free(bms_watchdog *watchdog) {
    free(watchdog);
}

void bms_watchdog_reset(bms_watchdog *watchdog, canlib_message_id id, canlib_watchdog_timestamp timestamp) {
    int index = bms_watchdog_index_from_id(id);
    if (index < 40 && CANLIB_BITTEST_ARRAY(watchdog->activated, index)) {
        CANLIB_BITCLEAR_ARRAY(watchdog->timeout, index);
        watchdog->last_reset[index] = timestamp;
    }
}

void bms_watchdog_reset_all(bms_watchdog *watchdog, canlib_watchdog_timestamp timestamp) {
    memset(watchdog->timeout, 0, sizeof(watchdog->timeout));
    memset(watchdog->last_reset, timestamp, sizeof(watchdog->last_reset));
}
void bms_watchdog_timeout(bms_watchdog *watchdog, canlib_watchdog_timestamp timestamp) {

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, BMS_INDEX_CELLBOARD_FLASH)
        && timestamp - watchdog->last_reset[BMS_INDEX_CELLBOARD_FLASH] > BMS_INTERVAL_CELLBOARD_FLASH * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, BMS_INDEX_CELLBOARD_FLASH);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, BMS_INDEX_CELLBOARD_VERSION)
        && timestamp - watchdog->last_reset[BMS_INDEX_CELLBOARD_VERSION] > BMS_INTERVAL_CELLBOARD_VERSION * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, BMS_INDEX_CELLBOARD_VERSION);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, BMS_INDEX_CELLBOARD_STATUS)
        && timestamp - watchdog->last_reset[BMS_INDEX_CELLBOARD_STATUS] > BMS_INTERVAL_CELLBOARD_STATUS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, BMS_INDEX_CELLBOARD_STATUS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, BMS_INDEX_CELLBOARD_CELLS_VOLTAGE)
        && timestamp - watchdog->last_reset[BMS_INDEX_CELLBOARD_CELLS_VOLTAGE] > BMS_INTERVAL_CELLBOARD_CELLS_VOLTAGE * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, BMS_INDEX_CELLBOARD_CELLS_VOLTAGE);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, BMS_INDEX_CELLBOARD_CELLS_TEMPERATURE)
        && timestamp - watchdog->last_reset[BMS_INDEX_CELLBOARD_CELLS_TEMPERATURE] > BMS_INTERVAL_CELLBOARD_CELLS_TEMPERATURE * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, BMS_INDEX_CELLBOARD_CELLS_TEMPERATURE);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, BMS_INDEX_CELLBOARD_SET_BALANCING_STATUS)
        && timestamp - watchdog->last_reset[BMS_INDEX_CELLBOARD_SET_BALANCING_STATUS] > BMS_INTERVAL_CELLBOARD_SET_BALANCING_STATUS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, BMS_INDEX_CELLBOARD_SET_BALANCING_STATUS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, BMS_INDEX_CELLBOARD_BALANCING_STATUS)
        && timestamp - watchdog->last_reset[BMS_INDEX_CELLBOARD_BALANCING_STATUS] > BMS_INTERVAL_CELLBOARD_BALANCING_STATUS * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, BMS_INDEX_CELLBOARD_BALANCING_STATUS);
    }

    if (
        CANLIB_BITTEST_ARRAY(watchdog->activated, BMS_INDEX_CELLBOARD_ERROR)
        && timestamp - watchdog->last_reset[BMS_INDEX_CELLBOARD_ERROR] > BMS_INTERVAL_CELLBOARD_ERROR * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, BMS_INDEX_CELLBOARD_ERROR);
    }

}


