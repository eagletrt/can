#ifndef bms_WATCHDOG_H
#define bms_WATCHDOG_H

#include <inttypes.h>

#ifdef __cplusplus
extern "C" {
#endif

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

#ifndef CANLIB_INTERVAL_THRESHOLD
#define CANLIB_INTERVAL_THRESHOLD 500
#endif // CANLIB_INTERVAL_THRESHOLD



#define BMS_INDEX_BOARD_STATUS 0
#define BMS_INDEX_TEMPERATURES_INFO 1
#define BMS_INDEX_TEMPERATURES 2
#define BMS_INDEX_VOLTAGES_INFO 3
#define BMS_INDEX_VOLTAGES 4
#define BMS_INDEX_SET_BALANCING_STATUS 5
#define BMS_INDEX_JMP_TO_BLT 6
#define BMS_INDEX_FLASH_CELLBOARD_0_TX 7
#define BMS_INDEX_FLASH_CELLBOARD_0_RX 8
#define BMS_INDEX_FLASH_CELLBOARD_1_TX 9
#define BMS_INDEX_FLASH_CELLBOARD_1_RX 10
#define BMS_INDEX_FLASH_CELLBOARD_2_TX 11
#define BMS_INDEX_FLASH_CELLBOARD_2_RX 12
#define BMS_INDEX_FLASH_CELLBOARD_3_TX 13
#define BMS_INDEX_FLASH_CELLBOARD_3_RX 14
#define BMS_INDEX_FLASH_CELLBOARD_4_TX 15
#define BMS_INDEX_FLASH_CELLBOARD_4_RX 16
#define BMS_INDEX_FLASH_CELLBOARD_5_TX 17
#define BMS_INDEX_FLASH_CELLBOARD_5_RX 18



typedef struct {
    uint8_t activated[3];
    uint8_t timeout[3];
    canlib_watchdog_timestamp last_reset[19];
} bms_watchdog;


bms_watchdog* bms_watchdog_new();
void bms_watchdog_free(bms_watchdog *watchdog);
void bms_watchdog_reset(bms_watchdog *watchdog, canlib_message_id id, canlib_watchdog_timestamp timestamp);
void bms_watchdog_reset_all(bms_watchdog *watchdog, canlib_watchdog_timestamp timestamp);
void bms_watchdog_timeout(bms_watchdog *watchdog, canlib_watchdog_timestamp timestamp);

static int bms_watchdog_interval_from_id(uint16_t message_id) {
    switch (message_id) {

    }
    return -1;
}

static int bms_watchdog_index_from_id(uint16_t message_id) {
    switch (message_id) {
       case 1537: return BMS_INDEX_BOARD_STATUS;
       case 512: return BMS_INDEX_TEMPERATURES_INFO;
       case 1280: return BMS_INDEX_TEMPERATURES;
       case 514: return BMS_INDEX_VOLTAGES_INFO;
       case 546: return BMS_INDEX_VOLTAGES;
       case 515: return BMS_INDEX_SET_BALANCING_STATUS;
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

    }
    return -1;
}
#ifdef primary_WATCHDOG_IMPLEMENTATION

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
    if (index < 19 && CANLIB_BITTEST_ARRAY(watchdog->activated, index)) {
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
#endif // primary_WATCHDOG_IMPLEMENTATION



#ifdef __cplusplus
}
#endif

#endif // bms_NETWORK_H
