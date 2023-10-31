#ifndef simulator_WATCHDOG_H
#define simulator_WATCHDOG_H

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

#define SIMULATOR_INTERVAL_PEDALS_OUTPUT 10
#define SIMULATOR_INTERVAL_STEERING_ANGLE 10
#define SIMULATOR_INTERVAL_CONTROL_STATE 100
#define SIMULATOR_INTERVAL_CONTROL_OUTPUT 100
#define SIMULATOR_INTERVAL_SPEED 10


#define SIMULATOR_INDEX_IMU_ANGULAR_RATE 0
#define SIMULATOR_INDEX_IMU_ACCELERATION 1
#define SIMULATOR_INDEX_PEDALS_OUTPUT 2
#define SIMULATOR_INDEX_STEERING_ANGLE 3
#define SIMULATOR_INDEX_CONTROL_STATE 4
#define SIMULATOR_INDEX_CONTROL_OUTPUT 5
#define SIMULATOR_INDEX_SPEED 6



typedef struct {
    uint8_t activated[1];
    uint8_t timeout[1];
    canlib_watchdog_timestamp last_reset[7];
} simulator_watchdog;

int simulator_watchdog_interval_from_id(uint16_t message_id);
int simulator_watchdog_index_from_id(uint16_t message_id);
void simulator_watchdog_free(simulator_watchdog *watchdog);
void simulator_watchdog_reset(simulator_watchdog *watchdog, canlib_message_id id, canlib_watchdog_timestamp timestamp);
void simulator_watchdog_reset_all(simulator_watchdog *watchdog, canlib_watchdog_timestamp timestamp);
void simulator_watchdog_timeout(simulator_watchdog *watchdog, canlib_watchdog_timestamp timestamp);



#ifdef __cplusplus
}
#endif

#endif // simulator_NETWORK_H
