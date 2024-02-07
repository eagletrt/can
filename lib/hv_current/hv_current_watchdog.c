#include "hv_current_watchdog.h"


int hv_current_watchdog_interval_from_id(uint16_t message_id) {
    switch (message_id) {

    }
    return -1;
}

int hv_current_watchdog_index_from_id(uint16_t message_id) {
    switch (message_id) {
       case 1320: return HV_CURRENT_INDEX_IVT_MSG_RESULT_WH;
       case 1319: return HV_CURRENT_INDEX_IVT_MSG_RESULT_AS;
       case 1318: return HV_CURRENT_INDEX_IVT_MSG_RESULT_W;
       case 1297: return HV_CURRENT_INDEX_IVT_MSG_RESPONSE;
       case 1317: return HV_CURRENT_INDEX_IVT_MSG_RESULT_T;
       case 1316: return HV_CURRENT_INDEX_IVT_MSG_RESULT_U3;
       case 1315: return HV_CURRENT_INDEX_IVT_MSG_RESULT_U2;
       case 1314: return HV_CURRENT_INDEX_IVT_MSG_RESULT_U1;
       case 1313: return HV_CURRENT_INDEX_IVT_MSG_RESULT_I;
       case 1041: return HV_CURRENT_INDEX_IVT_MSG_CMD;

    }
    return -1;
}

void hv_current_watchdog_free(hv_current_watchdog *watchdog) {
    free(watchdog);
}

void hv_current_watchdog_reset(hv_current_watchdog *watchdog, canlib_message_id id, canlib_watchdog_timestamp timestamp) {
    int index = hv_current_watchdog_index_from_id(id);
    if (index < 10 && CANLIB_BITTEST_ARRAY(watchdog->activated, index)) {
        CANLIB_BITCLEAR_ARRAY(watchdog->timeout, index);
        watchdog->last_reset[index] = timestamp;
    }
}

void hv_current_watchdog_reset_all(hv_current_watchdog *watchdog, canlib_watchdog_timestamp timestamp) {
    memset(watchdog->timeout, 0, sizeof(watchdog->timeout));
    memset(watchdog->last_reset, timestamp, sizeof(watchdog->last_reset));
}
void hv_current_watchdog_timeout(hv_current_watchdog *watchdog, canlib_watchdog_timestamp timestamp) {

}


