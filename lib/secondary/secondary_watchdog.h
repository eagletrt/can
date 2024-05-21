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

#define SECONDARY_INTERVAL_VEHICLE_POSITION 10
#define SECONDARY_INTERVAL_VEHICLE_SPEED 10
#define SECONDARY_INTERVAL_ANGULAR_VELOCITY 10
#define SECONDARY_INTERVAL_HV_SOC_ESTIMATION_STATE 50
#define SECONDARY_INTERVAL_HV_SOC_ESTIMATION_COVARIANCE 50
#define SECONDARY_INTERVAL_PEDAL_THROTTLE 10
#define SECONDARY_INTERVAL_PEDAL_BRAKES_PRESSURE 10
#define SECONDARY_INTERVAL_STEER_ANGLE 10
#define SECONDARY_INTERVAL_TLM_UNIX_TIMESTAMP 1000
#define SECONDARY_INTERVAL_TLM_LAPS_STATS 1000
#define SECONDARY_INTERVAL_TLM_NETWORK_INTERFACE 1000
#define SECONDARY_INTERVAL_AMMO_COMPRESSION 10
#define SECONDARY_INTERVAL_LINK_DEFORMATION_FL_WHEEL 10
#define SECONDARY_INTERVAL_LINK_DEFORMATION_FR_WHEEL 10
#define SECONDARY_INTERVAL_LINK_DEFORMATION_RL_WHEEL 10
#define SECONDARY_INTERVAL_LINK_DEFORMATION_RR_WHEEL 10
#define SECONDARY_INTERVAL_DEBUG_SIGNAL_1 10
#define SECONDARY_INTERVAL_DEBUG_SIGNAL_2 10
#define SECONDARY_INTERVAL_COOLING_TEMP_PUMPS 500
#define SECONDARY_INTERVAL_COOLING_TEMP_RADIATORS 500


#define SECONDARY_INDEX_ACQUISINATOR_JMP_TO_BLT 0
#define SECONDARY_INDEX_ACQUISINATOR_FLASH_0_TX 1
#define SECONDARY_INDEX_ACQUISINATOR_FLASH_0_RX 2
#define SECONDARY_INDEX_ACQUISINATOR_FLASH_1_TX 3
#define SECONDARY_INDEX_ACQUISINATOR_FLASH_1_RX 4
#define SECONDARY_INDEX_ACQUISINATOR_FLASH_2_TX 5
#define SECONDARY_INDEX_ACQUISINATOR_FLASH_2_RX 6
#define SECONDARY_INDEX_ACQUISINATOR_FLASH_3_TX 7
#define SECONDARY_INDEX_ACQUISINATOR_FLASH_3_RX 8
#define SECONDARY_INDEX_ACQUISINATOR_FLASH_4_TX 9
#define SECONDARY_INDEX_ACQUISINATOR_FLASH_4_RX 10
#define SECONDARY_INDEX_ACQUISINATOR_FLASH_5_TX 11
#define SECONDARY_INDEX_ACQUISINATOR_FLASH_5_RX 12
#define SECONDARY_INDEX_ACQUISINATOR_FLASH_6_TX 13
#define SECONDARY_INDEX_ACQUISINATOR_FLASH_6_RX 14
#define SECONDARY_INDEX_ACQUISINATOR_FLASH_7_TX 15
#define SECONDARY_INDEX_ACQUISINATOR_FLASH_7_RX 16
#define SECONDARY_INDEX_ACQUISINATOR_FLASH_8_TX 17
#define SECONDARY_INDEX_ACQUISINATOR_FLASH_8_RX 18
#define SECONDARY_INDEX_ACQUISINATOR_FLASH_9_TX 19
#define SECONDARY_INDEX_ACQUISINATOR_FLASH_9_RX 20
#define SECONDARY_INDEX_ACQUISINATOR_FLASH_10_TX 21
#define SECONDARY_INDEX_ACQUISINATOR_FLASH_10_RX 22
#define SECONDARY_INDEX_ACQUISINATOR_FLASH_11_TX 23
#define SECONDARY_INDEX_ACQUISINATOR_FLASH_11_RX 24
#define SECONDARY_INDEX_ACQUISINATOR_FLASH_12_TX 25
#define SECONDARY_INDEX_ACQUISINATOR_FLASH_12_RX 26
#define SECONDARY_INDEX_ACQUISINATOR_FLASH_13_TX 27
#define SECONDARY_INDEX_ACQUISINATOR_FLASH_13_RX 28
#define SECONDARY_INDEX_ACQUISINATOR_FLASH_14_TX 29
#define SECONDARY_INDEX_ACQUISINATOR_FLASH_14_RX 30
#define SECONDARY_INDEX_ACQUISINATOR_FLASH_15_TX 31
#define SECONDARY_INDEX_ACQUISINATOR_FLASH_15_RX 32
#define SECONDARY_INDEX_ACQUISINATOR_FLASH_16_TX 33
#define SECONDARY_INDEX_ACQUISINATOR_FLASH_16_RX 34
#define SECONDARY_INDEX_ACQUISINATOR_FLASH_17_TX 35
#define SECONDARY_INDEX_ACQUISINATOR_FLASH_17_RX 36
#define SECONDARY_INDEX_ACQUISINATOR_FLASH_18_TX 37
#define SECONDARY_INDEX_ACQUISINATOR_FLASH_18_RX 38
#define SECONDARY_INDEX_ACQUISINATOR_FLASH_19_TX 39
#define SECONDARY_INDEX_ACQUISINATOR_FLASH_19_RX 40
#define SECONDARY_INDEX_ACQUISINATOR_FLASH_20_TX 41
#define SECONDARY_INDEX_ACQUISINATOR_FLASH_20_RX 42
#define SECONDARY_INDEX_ACQUISINATOR_FLASH_21_TX 43
#define SECONDARY_INDEX_ACQUISINATOR_FLASH_21_RX 44
#define SECONDARY_INDEX_ACQUISINATOR_FLASH_22_TX 45
#define SECONDARY_INDEX_ACQUISINATOR_FLASH_22_RX 46
#define SECONDARY_INDEX_ACQUISINATOR_FLASH_23_TX 47
#define SECONDARY_INDEX_ACQUISINATOR_FLASH_23_RX 48
#define SECONDARY_INDEX_ACQUISINATOR_FLASH_24_TX 49
#define SECONDARY_INDEX_ACQUISINATOR_FLASH_24_RX 50
#define SECONDARY_INDEX_ACQUISINATOR_FLASH_25_TX 51
#define SECONDARY_INDEX_ACQUISINATOR_FLASH_25_RX 52
#define SECONDARY_INDEX_ACQUISINATOR_FLASH_26_TX 53
#define SECONDARY_INDEX_ACQUISINATOR_FLASH_26_RX 54
#define SECONDARY_INDEX_ACQUISINATOR_FLASH_27_TX 55
#define SECONDARY_INDEX_ACQUISINATOR_FLASH_27_RX 56
#define SECONDARY_INDEX_ACQUISINATOR_FLASH_28_TX 57
#define SECONDARY_INDEX_ACQUISINATOR_FLASH_28_RX 58
#define SECONDARY_INDEX_ACQUISINATOR_FLASH_29_TX 59
#define SECONDARY_INDEX_ACQUISINATOR_FLASH_29_RX 60
#define SECONDARY_INDEX_ACQUISINATOR_FLASH_30_TX 61
#define SECONDARY_INDEX_ACQUISINATOR_FLASH_30_RX 62
#define SECONDARY_INDEX_ACQUISINATOR_FLASH_31_TX 63
#define SECONDARY_INDEX_ACQUISINATOR_FLASH_31_RX 64
#define SECONDARY_INDEX_IMU_ANGULAR_RATE 65
#define SECONDARY_INDEX_IMU_ACCELERATION 66
#define SECONDARY_INDEX_IRTS_FL_0 67
#define SECONDARY_INDEX_IRTS_FL_1 68
#define SECONDARY_INDEX_IRTS_FL_2 69
#define SECONDARY_INDEX_IRTS_FL_3 70
#define SECONDARY_INDEX_IRTS_FR_0 71
#define SECONDARY_INDEX_IRTS_FR_1 72
#define SECONDARY_INDEX_IRTS_FR_2 73
#define SECONDARY_INDEX_IRTS_FR_3 74
#define SECONDARY_INDEX_IRTS_RL_0 75
#define SECONDARY_INDEX_IRTS_RL_1 76
#define SECONDARY_INDEX_IRTS_RL_2 77
#define SECONDARY_INDEX_IRTS_RL_3 78
#define SECONDARY_INDEX_IRTS_RR_0 79
#define SECONDARY_INDEX_IRTS_RR_1 80
#define SECONDARY_INDEX_IRTS_RR_2 81
#define SECONDARY_INDEX_IRTS_RR_3 82
#define SECONDARY_INDEX_VEHICLE_POSITION 83
#define SECONDARY_INDEX_VEHICLE_SPEED 84
#define SECONDARY_INDEX_ANGULAR_VELOCITY 85
#define SECONDARY_INDEX_HV_SOC_ESTIMATION_STATE 86
#define SECONDARY_INDEX_HV_SOC_ESTIMATION_COVARIANCE 87
#define SECONDARY_INDEX_PEDAL_THROTTLE 88
#define SECONDARY_INDEX_PEDAL_BRAKES_PRESSURE 89
#define SECONDARY_INDEX_STEER_ANGLE 90
#define SECONDARY_INDEX_TPMS_PRESSURE 91
#define SECONDARY_INDEX_TPMS_TEMPERATURE 92
#define SECONDARY_INDEX_TLM_UNIX_TIMESTAMP 93
#define SECONDARY_INDEX_TLM_LAP_TIME 94
#define SECONDARY_INDEX_TLM_LAPS_STATS 95
#define SECONDARY_INDEX_TLM_NETWORK_INTERFACE 96
#define SECONDARY_INDEX_AMMO_COMPRESSION 97
#define SECONDARY_INDEX_LINK_DEFORMATION_FL_WHEEL 98
#define SECONDARY_INDEX_LINK_DEFORMATION_FR_WHEEL 99
#define SECONDARY_INDEX_LINK_DEFORMATION_RL_WHEEL 100
#define SECONDARY_INDEX_LINK_DEFORMATION_RR_WHEEL 101
#define SECONDARY_INDEX_LINK_DEFORMATION_SET_CALIBRATION 102
#define SECONDARY_INDEX_AMMO_POS_SET_CALIBRATION 103
#define SECONDARY_INDEX_DEBUG_SIGNAL_1 104
#define SECONDARY_INDEX_DEBUG_SIGNAL_2 105
#define SECONDARY_INDEX_COOLING_TEMP_PUMPS 106
#define SECONDARY_INDEX_COOLING_TEMP_RADIATORS 107



typedef struct {
    uint8_t activated[14];
    uint8_t timeout[14];
    canlib_watchdog_timestamp last_reset[108];
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
