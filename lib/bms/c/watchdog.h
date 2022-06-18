#ifndef bms_WATCHDOG_H
#define bms_WATCHDOG_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdint.h>
#include <stdlib.h>
#include <memory.h>

#ifndef CANLIB_WATCHDOG_TIMESTAMP_TYPE
#define CANLIB_WATCHDOG_TIMESTAMP_TYPE
typedef uint32_t canlib_watchdog_timestamp;
#endif // CANLIB_WATCHDOG_TIMESTAMP_TYPE

#ifndef CANLIB_MESSAGE_ID_TYPE
#define CANLIB_MESSAGE_ID_TYPE
typedef uint16_t canlib_message_id;
#endif // CANLIB_MESSAGE_ID_TYPE

#ifndef CANLIB_WATCHDOG_CALLBACK
#define CANLIB_WATCHDOG_CALLBACK
typedef void (*canlib_watchdog_callback)(int);
#endif // CANLIB_WATCHDOG_CALLBACK

#ifndef CANLIB_BITMASK_UTILS
#define CANLIB_BITMASK_UTILS

#define CANLIB_BITMASK_TYPE uint8_t
#define CANLIB_BITMASK_TYPE_BITS 8

#define CANLIB_BITMASK_ARRAY(b) (1 << ((b) % CANLIB_BITMASK_TYPE_BITS))
#define CANLIB_BITSLOT_ARRAY(b) ((b) / CANLIB_BITMASK_TYPE_BITS)
#define CANLIB_BITSET_ARRAY(a, b) ((a)[CANLIB_BITSLOT_ARRAY(b)] |= CANLIB_BITMASK_ARRAY(b))
#define CANLIB_BITCLEAR_ARRAY(a, b) ((a)[CANLIB_BITSLOT_ARRAY(b)] &= ~CANLIB_BITMASK_ARRAY(b))
#define CANLIB_BITTEST_ARRAY(a, b) ((a)[CANLIB_BITSLOT_ARRAY(b)] & CANLIB_BITMASK_ARRAY(b))
#define CANLIB_BITNSLOTS_ARRAY(nb) ((nb + CANLIB_BITMASK_TYPE_BITS - 1) / CANLIB_BITMASK_TYPE_BITS)

#define CANLIB_BITMASK(b) (1 << (b))
#define CANLIB_BITSET(a, b) ((a) |= CANLIB_BITMASK(b))
#define CANLIB_BITCLEAR(a, b) ((a) &= ~CANLIB_BITMASK(b))
#define CANLIB_BITTEST(a, b) ((a) & CANLIB_BITMASK(b))

#endif // CANLIB_BITMASK_UTILS

#ifndef CANLIB_UNUSED
#define CANLIB_UNUSED(expr) do { (void)(expr); } while (0)
#endif // CANLIB_UNUSED


#define bms_WATCHDOG_INDEX_BOARD_STATUS_CELLBOARD0 0
#define bms_WATCHDOG_INDEX_BOARD_STATUS_CELLBOARD1 1
#define bms_WATCHDOG_INDEX_BOARD_STATUS_CELLBOARD2 2
#define bms_WATCHDOG_INDEX_BOARD_STATUS_CELLBOARD3 3
#define bms_WATCHDOG_INDEX_BOARD_STATUS_CELLBOARD4 4
#define bms_WATCHDOG_INDEX_BOARD_STATUS_CELLBOARD5 5
#define bms_WATCHDOG_INDEX_TEMPERATURES_CELLBOARD0 6
#define bms_WATCHDOG_INDEX_TEMPERATURES_CELLBOARD1 7
#define bms_WATCHDOG_INDEX_TEMPERATURES_CELLBOARD2 8
#define bms_WATCHDOG_INDEX_TEMPERATURES_CELLBOARD3 9
#define bms_WATCHDOG_INDEX_TEMPERATURES_CELLBOARD4 10
#define bms_WATCHDOG_INDEX_TEMPERATURES_CELLBOARD5 11
#define bms_WATCHDOG_INDEX_VOLTAGES_CELLBOARD0 12
#define bms_WATCHDOG_INDEX_VOLTAGES_CELLBOARD1 13
#define bms_WATCHDOG_INDEX_VOLTAGES_CELLBOARD2 14
#define bms_WATCHDOG_INDEX_VOLTAGES_CELLBOARD3 15
#define bms_WATCHDOG_INDEX_VOLTAGES_CELLBOARD4 16
#define bms_WATCHDOG_INDEX_VOLTAGES_CELLBOARD5 17
#define bms_WATCHDOG_INDEX_BALANCING 18
#define bms_WATCHDOG_INDEX_FW_UPDATE 19
#define bms_WATCHDOG_INDEX_FLASH_CELLBOARD_0_TX 20
#define bms_WATCHDOG_INDEX_FLASH_CELLBOARD_0_RX 21
#define bms_WATCHDOG_INDEX_FLASH_CELLBOARD_1_TX 22
#define bms_WATCHDOG_INDEX_FLASH_CELLBOARD_1_RX 23
#define bms_WATCHDOG_INDEX_FLASH_CELLBOARD_2_TX 24
#define bms_WATCHDOG_INDEX_FLASH_CELLBOARD_2_RX 25
#define bms_WATCHDOG_INDEX_FLASH_CELLBOARD_3_TX 26
#define bms_WATCHDOG_INDEX_FLASH_CELLBOARD_3_RX 27
#define bms_WATCHDOG_INDEX_FLASH_CELLBOARD_4_TX 28
#define bms_WATCHDOG_INDEX_FLASH_CELLBOARD_4_RX 29
#define bms_WATCHDOG_INDEX_FLASH_CELLBOARD_5_TX 30
#define bms_WATCHDOG_INDEX_FLASH_CELLBOARD_5_RX 31

#define bms_INTERVAL_BOARD_STATUS -1
#define bms_INTERVAL_TEMPERATURES -1
#define bms_INTERVAL_VOLTAGES -1
#define bms_INTERVAL_BALANCING -1
#define bms_INTERVAL_FW_UPDATE -1
#define bms_INTERVAL_FLASH_CELLBOARD_0_TX -1
#define bms_INTERVAL_FLASH_CELLBOARD_0_RX -1
#define bms_INTERVAL_FLASH_CELLBOARD_1_TX -1
#define bms_INTERVAL_FLASH_CELLBOARD_1_RX -1
#define bms_INTERVAL_FLASH_CELLBOARD_2_TX -1
#define bms_INTERVAL_FLASH_CELLBOARD_2_RX -1
#define bms_INTERVAL_FLASH_CELLBOARD_3_TX -1
#define bms_INTERVAL_FLASH_CELLBOARD_3_RX -1
#define bms_INTERVAL_FLASH_CELLBOARD_4_TX -1
#define bms_INTERVAL_FLASH_CELLBOARD_4_RX -1
#define bms_INTERVAL_FLASH_CELLBOARD_5_TX -1
#define bms_INTERVAL_FLASH_CELLBOARD_5_RX -1


// Messages with this interval will be ignored by the watchdog as they are not
// expected to be sent regularly.
#define bms_INTERVAL_ONCE -1

#define bms_INTERVAL_WITH_THRESHOLD_BOARD_STATUS -1
#define bms_INTERVAL_WITH_THRESHOLD_TEMPERATURES -1
#define bms_INTERVAL_WITH_THRESHOLD_VOLTAGES -1
#define bms_INTERVAL_WITH_THRESHOLD_BALANCING -1
#define bms_INTERVAL_WITH_THRESHOLD_FW_UPDATE -1
#define bms_INTERVAL_WITH_THRESHOLD_FLASH_CELLBOARD_0_TX -1
#define bms_INTERVAL_WITH_THRESHOLD_FLASH_CELLBOARD_0_RX -1
#define bms_INTERVAL_WITH_THRESHOLD_FLASH_CELLBOARD_1_TX -1
#define bms_INTERVAL_WITH_THRESHOLD_FLASH_CELLBOARD_1_RX -1
#define bms_INTERVAL_WITH_THRESHOLD_FLASH_CELLBOARD_2_TX -1
#define bms_INTERVAL_WITH_THRESHOLD_FLASH_CELLBOARD_2_RX -1
#define bms_INTERVAL_WITH_THRESHOLD_FLASH_CELLBOARD_3_TX -1
#define bms_INTERVAL_WITH_THRESHOLD_FLASH_CELLBOARD_3_RX -1
#define bms_INTERVAL_WITH_THRESHOLD_FLASH_CELLBOARD_4_TX -1
#define bms_INTERVAL_WITH_THRESHOLD_FLASH_CELLBOARD_4_RX -1
#define bms_INTERVAL_WITH_THRESHOLD_FLASH_CELLBOARD_5_TX -1
#define bms_INTERVAL_WITH_THRESHOLD_FLASH_CELLBOARD_5_RX -1


typedef struct {
    uint8_t activated[4];
    uint8_t timeout[4];
    canlib_watchdog_timestamp last_reset[32];
} bms_watchdog;

static inline int bms_watchdog_interval_from_id(uint16_t message_id) {
    switch (message_id) {
        case 1536: return bms_INTERVAL_BOARD_STATUS;
        case 1568: return bms_INTERVAL_BOARD_STATUS;
        case 1600: return bms_INTERVAL_BOARD_STATUS;
        case 1632: return bms_INTERVAL_BOARD_STATUS;
        case 1664: return bms_INTERVAL_BOARD_STATUS;
        case 1696: return bms_INTERVAL_BOARD_STATUS;
        case 1281: return bms_INTERVAL_TEMPERATURES;
        case 1313: return bms_INTERVAL_TEMPERATURES;
        case 1345: return bms_INTERVAL_TEMPERATURES;
        case 1377: return bms_INTERVAL_TEMPERATURES;
        case 1409: return bms_INTERVAL_TEMPERATURES;
        case 1441: return bms_INTERVAL_TEMPERATURES;
        case 514: return bms_INTERVAL_VOLTAGES;
        case 546: return bms_INTERVAL_VOLTAGES;
        case 578: return bms_INTERVAL_VOLTAGES;
        case 610: return bms_INTERVAL_VOLTAGES;
        case 642: return bms_INTERVAL_VOLTAGES;
        case 674: return bms_INTERVAL_VOLTAGES;
        case 515: return bms_INTERVAL_BALANCING;
        case 10: return bms_INTERVAL_FW_UPDATE;
        case 16: return bms_INTERVAL_FLASH_CELLBOARD_0_TX;
        case 17: return bms_INTERVAL_FLASH_CELLBOARD_0_RX;
        case 18: return bms_INTERVAL_FLASH_CELLBOARD_1_TX;
        case 19: return bms_INTERVAL_FLASH_CELLBOARD_1_RX;
        case 20: return bms_INTERVAL_FLASH_CELLBOARD_2_TX;
        case 21: return bms_INTERVAL_FLASH_CELLBOARD_2_RX;
        case 22: return bms_INTERVAL_FLASH_CELLBOARD_3_TX;
        case 23: return bms_INTERVAL_FLASH_CELLBOARD_3_RX;
        case 24: return bms_INTERVAL_FLASH_CELLBOARD_4_TX;
        case 25: return bms_INTERVAL_FLASH_CELLBOARD_4_RX;
        case 26: return bms_INTERVAL_FLASH_CELLBOARD_5_TX;
        case 27: return bms_INTERVAL_FLASH_CELLBOARD_5_RX;
    }
    return -1;
}

static inline int bms_watchdog_index_from_id(canlib_message_id id) {
    switch (id) {
        case 1536: return bms_WATCHDOG_INDEX_BOARD_STATUS_CELLBOARD0;
        case 1568: return bms_WATCHDOG_INDEX_BOARD_STATUS_CELLBOARD1;
        case 1600: return bms_WATCHDOG_INDEX_BOARD_STATUS_CELLBOARD2;
        case 1632: return bms_WATCHDOG_INDEX_BOARD_STATUS_CELLBOARD3;
        case 1664: return bms_WATCHDOG_INDEX_BOARD_STATUS_CELLBOARD4;
        case 1696: return bms_WATCHDOG_INDEX_BOARD_STATUS_CELLBOARD5;
        case 1281: return bms_WATCHDOG_INDEX_TEMPERATURES_CELLBOARD0;
        case 1313: return bms_WATCHDOG_INDEX_TEMPERATURES_CELLBOARD1;
        case 1345: return bms_WATCHDOG_INDEX_TEMPERATURES_CELLBOARD2;
        case 1377: return bms_WATCHDOG_INDEX_TEMPERATURES_CELLBOARD3;
        case 1409: return bms_WATCHDOG_INDEX_TEMPERATURES_CELLBOARD4;
        case 1441: return bms_WATCHDOG_INDEX_TEMPERATURES_CELLBOARD5;
        case 514: return bms_WATCHDOG_INDEX_VOLTAGES_CELLBOARD0;
        case 546: return bms_WATCHDOG_INDEX_VOLTAGES_CELLBOARD1;
        case 578: return bms_WATCHDOG_INDEX_VOLTAGES_CELLBOARD2;
        case 610: return bms_WATCHDOG_INDEX_VOLTAGES_CELLBOARD3;
        case 642: return bms_WATCHDOG_INDEX_VOLTAGES_CELLBOARD4;
        case 674: return bms_WATCHDOG_INDEX_VOLTAGES_CELLBOARD5;
        case 515: return bms_WATCHDOG_INDEX_BALANCING;
        case 10: return bms_WATCHDOG_INDEX_FW_UPDATE;
        case 16: return bms_WATCHDOG_INDEX_FLASH_CELLBOARD_0_TX;
        case 17: return bms_WATCHDOG_INDEX_FLASH_CELLBOARD_0_RX;
        case 18: return bms_WATCHDOG_INDEX_FLASH_CELLBOARD_1_TX;
        case 19: return bms_WATCHDOG_INDEX_FLASH_CELLBOARD_1_RX;
        case 20: return bms_WATCHDOG_INDEX_FLASH_CELLBOARD_2_TX;
        case 21: return bms_WATCHDOG_INDEX_FLASH_CELLBOARD_2_RX;
        case 22: return bms_WATCHDOG_INDEX_FLASH_CELLBOARD_3_TX;
        case 23: return bms_WATCHDOG_INDEX_FLASH_CELLBOARD_3_RX;
        case 24: return bms_WATCHDOG_INDEX_FLASH_CELLBOARD_4_TX;
        case 25: return bms_WATCHDOG_INDEX_FLASH_CELLBOARD_4_RX;
        case 26: return bms_WATCHDOG_INDEX_FLASH_CELLBOARD_5_TX;
        case 27: return bms_WATCHDOG_INDEX_FLASH_CELLBOARD_5_RX;
    }
    return 32; // invalid
}

bms_watchdog* bms_watchdog_new();
void bms_watchdog_free(bms_watchdog *watchdog);
void bms_watchdog_reset(bms_watchdog *watchdog, canlib_message_id id, canlib_watchdog_timestamp timestamp);
void bms_watchdog_reset_all(bms_watchdog *watchdog, canlib_watchdog_timestamp timestamp);
void bms_watchdog_timeout(bms_watchdog *watchdog, canlib_watchdog_timestamp timestamp);
void bms_watchdog_timeout_100(bms_watchdog *watchdog, canlib_watchdog_timestamp timestamp);
void bms_watchdog_timeout_1000(bms_watchdog *watchdog, canlib_watchdog_timestamp timestamp);
void bms_watchdog_timeout_5000(bms_watchdog *watchdog, canlib_watchdog_timestamp timestamp);
void bms_watchdog_timeout_10(bms_watchdog *watchdog, canlib_watchdog_timestamp timestamp);
void bms_watchdog_timeout_50(bms_watchdog *watchdog, canlib_watchdog_timestamp timestamp);
void bms_watchdog_timeout_500(bms_watchdog *watchdog, canlib_watchdog_timestamp timestamp);

#ifdef bms_WATCHDOG_IMPLEMENTATION

bms_watchdog* bms_watchdog_new() {
    bms_watchdog *watchdog = (bms_watchdog*)malloc(sizeof(bms_watchdog));
    if (watchdog == NULL) {
        return NULL;
    }
    memset(watchdog->activated, 0, sizeof(watchdog->activated));
    memset(watchdog->timeout, 0, sizeof(watchdog->timeout));
    memset(watchdog->last_reset, 0, sizeof(watchdog->last_reset));
    return watchdog;
}


void bms_watchdog_free(bms_watchdog *watchdog) {
    free(watchdog);
}

void bms_watchdog_reset(bms_watchdog *watchdog, canlib_message_id id, canlib_watchdog_timestamp timestamp) {
    int index = bms_watchdog_index_from_id(id);
    if (index < 32 && CANLIB_BITTEST_ARRAY(watchdog->activated, index)) {
        CANLIB_BITCLEAR_ARRAY(watchdog->timeout, index);
        watchdog->last_reset[index] = timestamp;
    }
}

void bms_watchdog_reset_all(bms_watchdog *watchdog, canlib_watchdog_timestamp timestamp) {
    memset(watchdog->timeout, 0, sizeof(watchdog->timeout));
    memset(watchdog->last_reset, timestamp, sizeof(watchdog->last_reset));
}

void bms_watchdog_timeout(bms_watchdog *watchdog, canlib_watchdog_timestamp timestamp) {
}

void bms_watchdog_timeout_100(bms_watchdog *watchdog, canlib_watchdog_timestamp timestamp) {
    // no messages in this interval
    CANLIB_UNUSED(watchdog);
    CANLIB_UNUSED(timestamp);
}

void bms_watchdog_timeout_1000(bms_watchdog *watchdog, canlib_watchdog_timestamp timestamp) {
    // no messages in this interval
    CANLIB_UNUSED(watchdog);
    CANLIB_UNUSED(timestamp);
}

void bms_watchdog_timeout_5000(bms_watchdog *watchdog, canlib_watchdog_timestamp timestamp) {
    // no messages in this interval
    CANLIB_UNUSED(watchdog);
    CANLIB_UNUSED(timestamp);
}

void bms_watchdog_timeout_10(bms_watchdog *watchdog, canlib_watchdog_timestamp timestamp) {
    // no messages in this interval
    CANLIB_UNUSED(watchdog);
    CANLIB_UNUSED(timestamp);
}

void bms_watchdog_timeout_50(bms_watchdog *watchdog, canlib_watchdog_timestamp timestamp) {
    // no messages in this interval
    CANLIB_UNUSED(watchdog);
    CANLIB_UNUSED(timestamp);
}

void bms_watchdog_timeout_500(bms_watchdog *watchdog, canlib_watchdog_timestamp timestamp) {
    // no messages in this interval
    CANLIB_UNUSED(watchdog);
    CANLIB_UNUSED(timestamp);
}



#endif // bms_WATCHDOG_IMPLEMENTATION

#ifdef __cplusplus
}
#endif

#endif // bms_NETWORK_H