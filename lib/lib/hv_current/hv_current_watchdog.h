#ifndef hv_current_WATCHDOG_H
#define hv_current_WATCHDOG_H

#include <inttypes.h>
#include <string.h>
#include <stdlib.h>

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



#define HV_CURRENT_INDEX_IVT_MSG_RESULT_WH 0
#define HV_CURRENT_INDEX_IVT_MSG_RESULT_AS 1
#define HV_CURRENT_INDEX_IVT_MSG_RESULT_W 2
#define HV_CURRENT_INDEX_IVT_MSG_RESPONSE 3
#define HV_CURRENT_INDEX_IVT_MSG_RESULT_T 4
#define HV_CURRENT_INDEX_IVT_MSG_RESULT_U3 5
#define HV_CURRENT_INDEX_IVT_MSG_RESULT_U2 6
#define HV_CURRENT_INDEX_IVT_MSG_RESULT_U1 7
#define HV_CURRENT_INDEX_IVT_MSG_RESULT_I 8
#define HV_CURRENT_INDEX_IVT_MSG_CMD 9



typedef struct {
    uint8_t activated[2];
    uint8_t timeout[2];
    canlib_watchdog_timestamp last_reset[10];
} hv_current_watchdog;

int hv_current_watchdog_interval_from_id(uint16_t message_id);
int hv_current_watchdog_index_from_id(uint16_t message_id);
void hv_current_watchdog_free(hv_current_watchdog *watchdog);
void hv_current_watchdog_reset(hv_current_watchdog *watchdog, canlib_message_id id, canlib_watchdog_timestamp timestamp);
void hv_current_watchdog_reset_all(hv_current_watchdog *watchdog, canlib_watchdog_timestamp timestamp);
void hv_current_watchdog_timeout(hv_current_watchdog *watchdog, canlib_watchdog_timestamp timestamp);



#ifdef __cplusplus
}
#endif

#endif // hv_current_NETWORK_H
