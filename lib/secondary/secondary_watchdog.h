#ifndef secondary_WATCHDOG_H
#define secondary_WATCHDOG_H

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

#define SECONDARY_INTERVAL_ANGULAR_VELOCITY 10
#define SECONDARY_INTERVAL_PEDAL_THROTTLE 10
#define SECONDARY_INTERVAL_PEDAL_BRAKES_PRESSURE 10
#define SECONDARY_INTERVAL_STEER_ANGLE 10
#define SECONDARY_INTERVAL_TLM_UNIX_TIMESTAMP 1000
#define SECONDARY_INTERVAL_TLM_LAPS_STATS 1000
#define SECONDARY_INTERVAL_AMMO_COMPRESSION 10
#define SECONDARY_INTERVAL_LINK_DEFORMATION 10
#define SECONDARY_INTERVAL_DEBUG_SIGNAL_1 10
#define SECONDARY_INTERVAL_DEBUG_SIGNAL_2 10
#define SECONDARY_INTERVAL_COOLING_TEMP 500


#define SECONDARY_INDEX_ACQUISINATOR_JMP_TO_BLT 0
#define SECONDARY_INDEX_ACQUISINATOR_FLASH_TX 1
#define SECONDARY_INDEX_ACQUISINATOR_FLASH_RX 2
#define SECONDARY_INDEX_IMU_ANGULAR_RATE 3
#define SECONDARY_INDEX_IMU_ACCELERATION 4
#define SECONDARY_INDEX_IRTS_FL_0 5
#define SECONDARY_INDEX_IRTS_FL_1 6
#define SECONDARY_INDEX_IRTS_FL_2 7
#define SECONDARY_INDEX_IRTS_FL_3 8
#define SECONDARY_INDEX_IRTS_FR_0 9
#define SECONDARY_INDEX_IRTS_FR_1 10
#define SECONDARY_INDEX_IRTS_FR_2 11
#define SECONDARY_INDEX_IRTS_FR_3 12
#define SECONDARY_INDEX_IRTS_RL_0 13
#define SECONDARY_INDEX_IRTS_RL_1 14
#define SECONDARY_INDEX_IRTS_RL_2 15
#define SECONDARY_INDEX_IRTS_RL_3 16
#define SECONDARY_INDEX_IRTS_RR_0 17
#define SECONDARY_INDEX_IRTS_RR_1 18
#define SECONDARY_INDEX_IRTS_RR_2 19
#define SECONDARY_INDEX_IRTS_RR_3 20
#define SECONDARY_INDEX_GPS_COORDS 21
#define SECONDARY_INDEX_GPS_SPEED 22
#define SECONDARY_INDEX_ANGULAR_VELOCITY 23
#define SECONDARY_INDEX_PEDAL_THROTTLE 24
#define SECONDARY_INDEX_PEDAL_BRAKES_PRESSURE 25
#define SECONDARY_INDEX_STEER_ANGLE 26
#define SECONDARY_INDEX_TPMS_PRESSURE 27
#define SECONDARY_INDEX_TPMS_TEMPERATURE 28
#define SECONDARY_INDEX_TLM_UNIX_TIMESTAMP 29
#define SECONDARY_INDEX_TLM_LAP_TIME 30
#define SECONDARY_INDEX_TLM_LAPS_STATS 31
#define SECONDARY_INDEX_AMMO_COMPRESSION 32
#define SECONDARY_INDEX_LINK_DEFORMATION 33
#define SECONDARY_INDEX_LINK_DEFORMATION_SET_CALIBRATION 34
#define SECONDARY_INDEX_DEBUG_SIGNAL_1 35
#define SECONDARY_INDEX_DEBUG_SIGNAL_2 36
#define SECONDARY_INDEX_COOLING_TEMP 37



typedef struct {
    uint8_t activated[5];
    uint8_t timeout[5];
    canlib_watchdog_timestamp last_reset[38];
} secondary_watchdog;

int secondary_watchdog_interval_from_id(uint16_t message_id);
int secondary_watchdog_index_from_id(uint16_t message_id);
void secondary_watchdog_free(secondary_watchdog *watchdog);
void secondary_watchdog_reset(secondary_watchdog *watchdog, canlib_message_id id, canlib_watchdog_timestamp timestamp);
void secondary_watchdog_reset_all(secondary_watchdog *watchdog, canlib_watchdog_timestamp timestamp);
void secondary_watchdog_timeout(secondary_watchdog *watchdog, canlib_watchdog_timestamp timestamp);



#ifdef __cplusplus
}
#endif

#endif // secondary_NETWORK_H
