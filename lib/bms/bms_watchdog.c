#include "bms_watchdog.h"


int bms_watchdog_interval_from_id(uint16_t message_id) {
    switch (message_id) {
       case 1539: return BMS_INTERVAL_CELLBOARD_VERSION;

    }
    return -1;
}

int bms_watchdog_index_from_id(uint16_t message_id) {
    switch (message_id) {
       case 1025: return BMS_INDEX_BOARD_STATUS;
       case 514: return BMS_INDEX_TEMPERATURES_INFO;
       case 1538: return BMS_INDEX_TEMPERATURES;
       case 516: return BMS_INDEX_VOLTAGES_INFO;
       case 1540: return BMS_INDEX_VOLTAGES;
       case 16: return BMS_INDEX_SET_BALANCING_STATUS;
       case 0: return BMS_INDEX_JMP_TO_BLT;
       case 4: return BMS_INDEX_FLASH_CELLBOARD_0_TX;
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
       case 1539: return BMS_INDEX_CELLBOARD_VERSION;

    }
    return -1;
}

void bms_watchdog_free(bms_watchdog *watchdog) {
    free(watchdog);
}

void bms_watchdog_reset(bms_watchdog *watchdog, canlib_message_id id, canlib_watchdog_timestamp timestamp) {
    int index = bms_watchdog_index_from_id(id);
    if (index < 20 && CANLIB_BITTEST_ARRAY(watchdog->activated, index)) {
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
        CANLIB_BITTEST_ARRAY(watchdog->activated, BMS_INDEX_CELLBOARD_VERSION)
        && timestamp - watchdog->last_reset[BMS_INDEX_CELLBOARD_VERSION] > BMS_INTERVAL_CELLBOARD_VERSION * 3
    ) {
        CANLIB_BITSET_ARRAY(watchdog->timeout, BMS_INDEX_CELLBOARD_VERSION);
    }

}


