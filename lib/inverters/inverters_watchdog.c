#include "inverters_watchdog.h"


int inverters_watchdog_interval_from_id(uint16_t message_id) {
    switch (message_id) {

    }
    return -1;
}

int inverters_watchdog_index_from_id(uint16_t message_id) {
    switch (message_id) {
       case 513: return INVERTERS_INDEX_INV_L_SEND;
       case 385: return INVERTERS_INDEX_INV_L_RCV;
       case 514: return INVERTERS_INDEX_INV_R_SEND;
       case 386: return INVERTERS_INDEX_INV_R_RCV;

    }
    return -1;
}

void inverters_watchdog_free(inverters_watchdog *watchdog) {
    free(watchdog);
}

void inverters_watchdog_reset(inverters_watchdog *watchdog, canlib_message_id id, canlib_watchdog_timestamp timestamp) {
    int index = inverters_watchdog_index_from_id(id);
    if (index < 4 && CANLIB_BITTEST_ARRAY(watchdog->activated, index)) {
        CANLIB_BITCLEAR_ARRAY(watchdog->timeout, index);
        watchdog->last_reset[index] = timestamp;
    }
}

void inverters_watchdog_reset_all(inverters_watchdog *watchdog, canlib_watchdog_timestamp timestamp) {
    memset(watchdog->timeout, 0, sizeof(watchdog->timeout));
    memset(watchdog->last_reset, timestamp, sizeof(watchdog->last_reset));
}
void inverters_watchdog_timeout(inverters_watchdog *watchdog, canlib_watchdog_timestamp timestamp) {

}


