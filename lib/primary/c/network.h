#ifndef primary_NETWORK_H
#define primary_NETWORK_H

#ifdef __cplusplus
extern "C" {
#endif

#include <inttypes.h>
#include <stdbool.h>
#include <assert.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <memory.h>
#include <stdio.h>

#ifndef CANLIB_BUILD
#define CANLIB_BUILD_TIME 1657736003
#define CANLIB_BUILD_HASH 0x2c313203
#endif // CANLIB_BUILD

#ifndef CANLIB_ASSERTS
#define CANLIB_ASSERTS

static_assert(sizeof(float) == 4, "canlib: sizeof(float) != 4 BYTES");
static_assert(sizeof(double) == 8, "canlib: sizeof(double) != 8 BYTES");

/* Is it little endian?

          ████████                        ████████
        ██        ██                  ████        ████
      ██▒▒▒▒        ██              ██▒▒              ██
    ██▒▒▒▒▒▒      ▒▒▒▒██          ██▒▒▒▒            ▒▒▒▒██
    ██▒▒▒▒▒▒      ▒▒▒▒██          ██▒▒▒▒  ▒▒▒▒▒▒    ▒▒▒▒██
  ██  ▒▒▒▒        ▒▒▒▒▒▒██      ██▒▒▒▒  ▒▒▒▒▒▒▒▒▒▒  ▒▒▒▒▒▒██
  ██                ▒▒▒▒██      ██      ▒▒▒▒▒▒▒▒▒▒    ▒▒▒▒██
██▒▒      ▒▒▒▒▒▒          ██    ██      ▒▒▒▒▒▒▒▒▒▒        ██
██      ▒▒▒▒▒▒▒▒▒▒        ██    ██▒▒      ▒▒▒▒▒▒          ██
██      ▒▒▒▒▒▒▒▒▒▒    ▒▒▒▒██      ██                ▒▒▒▒██
██▒▒▒▒  ▒▒▒▒▒▒▒▒▒▒  ▒▒▒▒▒▒██      ██  ▒▒▒▒        ▒▒▒▒▒▒██
  ██▒▒▒▒  ▒▒▒▒▒▒    ▒▒▒▒██          ██▒▒▒▒▒▒      ▒▒▒▒██
  ██▒▒▒▒            ▒▒▒▒██          ██▒▒▒▒▒▒      ▒▒▒▒██
    ██▒▒              ██              ██▒▒▒▒        ██
      ████        ████                  ██        ██
          ████████                        ████████

                                    Or is it big endian? */
#ifndef __CANLIB_ENDIAN_ORDER
    #define __CANLIB_ENDIAN_ORDER 1094861636L // "ABCD"
#endif
#if !defined(__CANLIB_LITTLE_ENDIAN) && !defined(__CANLIB_BIG_ENDIAN) && !defined(__CANLIB_PDP_ENDIAN)
    #if __CANLIB_ENDIAN_ORDER==0x41424344UL
        #define __CANLIB_LITTLE_ENDIAN
    #elif __CANLIB_ENDIAN_ORDER==0x44434241UL
        #define __CANLIB_BIG_ENDIAN
    #elif __CANLIB_ENDIAN_ORDER==0x42414443UL
        #define __CANLIB_PDP_ENDIAN
    #else
        #error "canlib: endianess not supported"
    #endif
#endif

#ifndef __CANLIB_LITTLE_ENDIAN
    #error "canlib: endianess not supported"
#endif

#endif // CANLIB_ASSERTS

#ifndef CANLIB_SHARED
#define CANLIB_SHARED

/* We know it's PACKING but PARKING sounds a bit better ;) */
#if defined(__MINGW32__)
#define CANLIB_PARKING __attribute__((__gcc_struct__, __packed__)) // , __aligned__(1)))
#else
#define CANLIB_PARKING __attribute__((__packed__)) // , __aligned__(1)))
#endif

#define PRIf32 "f"
#define PRIf64 "f"

#endif // CANLIB_SHARED

#ifndef CANLIB_BITMASK_UTILS
#define CANLIB_BITMASK_UTILS

// *** START DANGEROUS THINGS ***

#define CANLIB_BITMASK_TYPE uint8_t
#define CANLIB_BITMASK_TYPE_BITS 8

#define CANLIB_BITMASK_ARRAY(b) (1 << ((b) % CANLIB_BITMASK_TYPE_BITS))
#define CANLIB_BITSLOT_ARRAY(b) ((b) / CANLIB_BITMASK_TYPE_BITS)
#define CANLIB_BITSET_ARRAY(a, b) ((a)[CANLIB_BITSLOT_ARRAY(b)] |= CANLIB_BITMASK_ARRAY(b))
#define CANLIB_BITCLEAR_ARRAY(a, b) ((a)[CANLIB_BITSLOT_ARRAY(b)] &= ~CANLIB_BITMASK_ARRAY(b))
#define CANLIB_BITTEST_ARRAY(a, b) ((a)[CANLIB_BITSLOT_ARRAY(b)] & CANLIB_BITMASK_ARRAY(b))
#define CANLIB_BITNSLOTS_ARRAY(nb) ((nb + CANLIB_BITMASK_TYPE_BITS - 1) / CANLIB_BITMASK_TYPE_BITS)

// *** END DANGEROUS THINGS ***

#define CANLIB_BITSET_BITMASK(a, b) ((a) |= (b))
#define CANLIB_BITCLEAR_BITMASK(a, b) ((a) &= ~(b))
#define CANLIB_BITTEST_BITMASK(a, b) ((a) & (b))

#define CANLIB_BITMASK(b) (1 << (b))
#define CANLIB_BITSET(a, b) ((a) |= CANLIB_BITMASK(b))
#define CANLIB_BITCLEAR(a, b) ((a) &= ~CANLIB_BITMASK(b))
#define CANLIB_BITTEST(a, b) ((a) & CANLIB_BITMASK(b))

#endif // CANLIB_BITMASK_UTILS

#ifndef CANLIB_UNUSED
#define CANLIB_UNUSED(expr) do { (void)(expr); } while (0)
#endif // CANLIB_UNUSED

#ifndef CANLIB_SEPARATOR
#define CANLIB_SEPARATOR ","
#endif // CANLIB_SEPARATOR

#ifndef CANLIB_MESSAGE_ID_TYPE
#define CANLIB_MESSAGE_ID_TYPE
typedef uint16_t canlib_message_id;
#endif // CANLIB_MESSAGE_ID_TYPE

// Info

#define primary_MESSAGE_COUNT 76

// Custom types

#define primary_int8 int8_t
#define primary_uint8 uint8_t
#define primary_int16 int16_t
#define primary_uint16 uint16_t
#define primary_int32 int32_t
#define primary_uint32 uint32_t
#define primary_int64 int64_t
#define primary_uint64 uint64_t
#define primary_float32 float
#define primary_float64 double
#define primary_bool bool
#define primary_byte_size uint32_t

typedef union {
    primary_uint8 bytes[4];
    primary_float32 value;
} primary_float32_helper;

typedef union {
    primary_uint8 bytes[8];
    primary_float64 value;
} primary_float64_helper;

#ifdef __cplusplus
#define primary_float32_to_bytes(float, index) (reinterpret_cast<primary_uint8*>(&((float)))[(index)])
#define primary_float64_to_bytes(float, index) (reinterpret_cast<primary_uint8*>(&((float)))[(index)])
#else
#define primary_float32_to_bytes(float, index) (((primary_float32_helper) (float)).bytes[(index)])
#define primary_float64_to_bytes(float, index) (((primary_float64_helper) (float)).bytes[(index)])
#endif

typedef struct {
    uint16_t id;
    void* message_raw;
    void* message_conversion;
} primary_devices[primary_MESSAGE_COUNT];

// ============== INDEXES ============ //


#define primary_INDEX_BMS_HV_JMP_TO_BLT 0
#define primary_INDEX_BMS_LV_JMP_TO_BLT 1
#define primary_INDEX_STEER_VERSION 2
#define primary_INDEX_DAS_VERSION 3
#define primary_INDEX_HV_VERSION 4
#define primary_INDEX_LV_VERSION 5
#define primary_INDEX_TLM_VERSION 6
#define primary_INDEX_TIMESTAMP 7
#define primary_INDEX_SET_TLM_STATUS 8
#define primary_INDEX_TLM_STATUS 9
#define primary_INDEX_STEER_SYSTEM_STATUS 10
#define primary_INDEX_HV_VOLTAGE 11
#define primary_INDEX_HV_CURRENT 12
#define primary_INDEX_HV_TEMP 13
#define primary_INDEX_HV_ERRORS 14
#define primary_INDEX_HV_CAN_FORWARD 15
#define primary_INDEX_HV_FANS_OVERRIDE 16
#define primary_INDEX_HV_CAN_FORWARD_STATUS 17
#define primary_INDEX_HV_FANS_OVERRIDE_STATUS 18
#define primary_INDEX_HV_FEEDBACKS_STATUS 19
#define primary_INDEX_HV_IMD_STATUS 20
#define primary_INDEX_TS_STATUS 21
#define primary_INDEX_SET_TS_STATUS_DAS 22
#define primary_INDEX_SET_TS_STATUS_HANDCART 23
#define primary_INDEX_STEER_STATUS 24
#define primary_INDEX_SET_CAR_STATUS 25
#define primary_INDEX_SET_PEDALS_RANGE 26
#define primary_INDEX_SET_STEERING_ANGLE_RANGE 27
#define primary_INDEX_CAR_STATUS 28
#define primary_INDEX_DAS_ERRORS 29
#define primary_INDEX_LV_CURRENT 30
#define primary_INDEX_LV_VOLTAGE 31
#define primary_INDEX_LV_TOTAL_VOLTAGE 32
#define primary_INDEX_LV_TEMPERATURE 33
#define primary_INDEX_COOLING_STATUS 34
#define primary_INDEX_SET_RADIATOR_SPEED 35
#define primary_INDEX_SET_PUMPS_SPEED 36
#define primary_INDEX_SET_INVERTER_CONNECTION_STATUS 37
#define primary_INDEX_INVERTER_CONNECTION_STATUS 38
#define primary_INDEX_LV_ERRORS 39
#define primary_INDEX_SHUTDOWN_STATUS 40
#define primary_INDEX_MARKER 41
#define primary_INDEX_HV_CELLS_VOLTAGE 42
#define primary_INDEX_HV_CELLS_TEMP 43
#define primary_INDEX_HV_CELL_BALANCING_STATUS 44
#define primary_INDEX_SET_CELL_BALANCING_STATUS 45
#define primary_INDEX_HANDCART_STATUS 46
#define primary_INDEX_SPEED 47
#define primary_INDEX_INV_L_REQUEST 48
#define primary_INDEX_INV_R_REQUEST 49
#define primary_INDEX_INV_L_RESPONSE 50
#define primary_INDEX_INV_R_RESPONSE 51
#define primary_INDEX_FLASH_CELLBOARD_0_TX 52
#define primary_INDEX_FLASH_CELLBOARD_0_RX 53
#define primary_INDEX_FLASH_CELLBOARD_1_TX 54
#define primary_INDEX_FLASH_CELLBOARD_1_RX 55
#define primary_INDEX_FLASH_CELLBOARD_2_TX 56
#define primary_INDEX_FLASH_CELLBOARD_2_RX 57
#define primary_INDEX_FLASH_CELLBOARD_3_TX 58
#define primary_INDEX_FLASH_CELLBOARD_3_RX 59
#define primary_INDEX_FLASH_CELLBOARD_4_TX 60
#define primary_INDEX_FLASH_CELLBOARD_4_RX 61
#define primary_INDEX_FLASH_CELLBOARD_5_TX 62
#define primary_INDEX_FLASH_CELLBOARD_5_RX 63
#define primary_INDEX_FLASH_BMS_HV_TX 64
#define primary_INDEX_FLASH_BMS_HV_RX 65
#define primary_INDEX_FLASH_BMS_LV_TX 66
#define primary_INDEX_FLASH_BMS_LV_RX 67
#define primary_INDEX_BRUSA_NLG5_CTL 68
#define primary_INDEX_BRUSA_ST 69
#define primary_INDEX_BRUSA_ACT_I 70
#define primary_INDEX_BRUSA_ACT_II 71
#define primary_INDEX_BRUSA_TEMP 72
#define primary_INDEX_BRUSA_ERR 73
#define primary_INDEX_BMS_HV_CHIMERA 74
#define primary_INDEX_ECU_CHIMERA 75

// ============== SIZES ============== //


#define primary_SIZE_BMS_HV_JMP_TO_BLT 0
#define primary_SIZE_BMS_LV_JMP_TO_BLT 0
#define primary_SIZE_STEER_VERSION 5
#define primary_SIZE_DAS_VERSION 5
#define primary_SIZE_HV_VERSION 5
#define primary_SIZE_LV_VERSION 5
#define primary_SIZE_TLM_VERSION 5
#define primary_SIZE_TIMESTAMP 4
#define primary_SIZE_SET_TLM_STATUS 1
#define primary_SIZE_TLM_STATUS 1
#define primary_SIZE_STEER_SYSTEM_STATUS 1
#define primary_SIZE_HV_VOLTAGE 8
#define primary_SIZE_HV_CURRENT 7
#define primary_SIZE_HV_TEMP 3
#define primary_SIZE_HV_ERRORS 4
#define primary_SIZE_HV_CAN_FORWARD 1
#define primary_SIZE_HV_FANS_OVERRIDE 3
#define primary_SIZE_HV_CAN_FORWARD_STATUS 1
#define primary_SIZE_HV_FANS_OVERRIDE_STATUS 3
#define primary_SIZE_HV_FEEDBACKS_STATUS 6
#define primary_SIZE_HV_IMD_STATUS 5
#define primary_SIZE_TS_STATUS 1
#define primary_SIZE_SET_TS_STATUS 1
#define primary_SIZE_STEER_STATUS 1
#define primary_SIZE_SET_CAR_STATUS 1
#define primary_SIZE_SET_PEDALS_RANGE 1
#define primary_SIZE_SET_STEERING_ANGLE_RANGE 1
#define primary_SIZE_CAR_STATUS 1
#define primary_SIZE_DAS_ERRORS 2
#define primary_SIZE_LV_CURRENT 2
#define primary_SIZE_LV_VOLTAGE 8
#define primary_SIZE_LV_TOTAL_VOLTAGE 4
#define primary_SIZE_LV_TEMPERATURE 8
#define primary_SIZE_COOLING_STATUS 4
#define primary_SIZE_SET_RADIATOR_SPEED 2
#define primary_SIZE_SET_PUMPS_SPEED 2
#define primary_SIZE_SET_INVERTER_CONNECTION_STATUS 1
#define primary_SIZE_INVERTER_CONNECTION_STATUS 1
#define primary_SIZE_LV_ERRORS 6
#define primary_SIZE_SHUTDOWN_STATUS 1
#define primary_SIZE_MARKER 0
#define primary_SIZE_HV_CELLS_VOLTAGE 7
#define primary_SIZE_HV_CELLS_TEMP 7
#define primary_SIZE_HV_CELL_BALANCING_STATUS 1
#define primary_SIZE_SET_CELL_BALANCING_STATUS 1
#define primary_SIZE_HANDCART_STATUS 1
#define primary_SIZE_SPEED 4
#define primary_SIZE_INV_L_REQUEST 8
#define primary_SIZE_INV_R_REQUEST 8
#define primary_SIZE_INV_L_RESPONSE 8
#define primary_SIZE_INV_R_RESPONSE 8
#define primary_SIZE_FLASH_CELLBOARD_0_TX 0
#define primary_SIZE_FLASH_CELLBOARD_0_RX 0
#define primary_SIZE_FLASH_CELLBOARD_1_TX 0
#define primary_SIZE_FLASH_CELLBOARD_1_RX 0
#define primary_SIZE_FLASH_CELLBOARD_2_TX 0
#define primary_SIZE_FLASH_CELLBOARD_2_RX 0
#define primary_SIZE_FLASH_CELLBOARD_3_TX 0
#define primary_SIZE_FLASH_CELLBOARD_3_RX 0
#define primary_SIZE_FLASH_CELLBOARD_4_TX 0
#define primary_SIZE_FLASH_CELLBOARD_4_RX 0
#define primary_SIZE_FLASH_CELLBOARD_5_TX 0
#define primary_SIZE_FLASH_CELLBOARD_5_RX 0
#define primary_SIZE_FLASH_BMS_HV_TX 0
#define primary_SIZE_FLASH_BMS_HV_RX 0
#define primary_SIZE_FLASH_BMS_LV_TX 0
#define primary_SIZE_FLASH_BMS_LV_RX 0
#define primary_SIZE_BRUSA_NLG5_CTL 0
#define primary_SIZE_BRUSA_ST 0
#define primary_SIZE_BRUSA_ACT_I 0
#define primary_SIZE_BRUSA_ACT_II 0
#define primary_SIZE_BRUSA_TEMP 0
#define primary_SIZE_BRUSA_ERR 0
#define primary_SIZE_BMS_HV_CHIMERA 0
#define primary_SIZE_ECU_CHIMERA 0

// ============== BIT SETS =========== //


typedef primary_uint16 primary_HvErrors;
#define primary_HvErrors_DEFAULT 0
#define primary_HvErrors_CELL_LOW_VOLTAGE 1
#define primary_HvErrors_CELL_UNDER_VOLTAGE 2
#define primary_HvErrors_CELL_OVER_VOLTAGE 4
#define primary_HvErrors_CELL_HIGH_TEMPERATURE 8
#define primary_HvErrors_CELL_OVER_TEMPERATURE 16
#define primary_HvErrors_OVER_CURRENT 32
#define primary_HvErrors_CAN 64
#define primary_HvErrors_INT_VOLTAGE_MISMATCH 128
#define primary_HvErrors_CELLBOARD_COMM 256
#define primary_HvErrors_CELLBOARD_INTERNAL 512
#define primary_HvErrors_FEEDBACK 1024
#define primary_HvErrors_FEEDBACK_CIRCUITRY 2048
#define primary_HvErrors_EEPROM_COMM 4096
#define primary_HvErrors_EEPROM_WRITE 8192

#define primary_MAX_STRING_LENGTH_HvErrors 223
int primary_to_string_HvErrors(primary_HvErrors value, char* buffer);

typedef primary_uint32 primary_LvErrors;
#define primary_LvErrors_DEFAULT 0
#define primary_LvErrors_CELL_UNDERVOLTAGE 1
#define primary_LvErrors_CELL_OVERVOLTAGE 2
#define primary_LvErrors_OPEN_WIRE 4
#define primary_LvErrors_CAN 8
#define primary_LvErrors_SPI 16
#define primary_LvErrors_OVER_CURRENT 32
#define primary_LvErrors_DCDC12_UNDER_TEMPERATURE 64
#define primary_LvErrors_DCDC12_OVER_TEMPERATURE 128
#define primary_LvErrors_DCDC24_UNDER_TEMPERATURE 256
#define primary_LvErrors_DCDC24_OVER_TEMPERATURE 512
#define primary_LvErrors_CELL_UNDER_TEMPERATURE 1024
#define primary_LvErrors_CELL_OVER_TEMPERATURE 2048
#define primary_LvErrors_RELAY 4096
#define primary_LvErrors_LTC6810 8192
#define primary_LvErrors_VOLTAGES_NOT_READY 16384
#define primary_LvErrors_MCP23017 32768
#define primary_LvErrors_RADIATOR 65536
#define primary_LvErrors_FAN 131072
#define primary_LvErrors_PUMP 262144
#define primary_LvErrors_ADC_INIT 524288
#define primary_LvErrors_DCDC12 1048576
#define primary_LvErrors_DCDC24 2097152

#define primary_MAX_STRING_LENGTH_LvErrors 292
int primary_to_string_LvErrors(primary_LvErrors value, char* buffer);

typedef primary_uint16 primary_DasErrors;
#define primary_DasErrors_DEFAULT 0
#define primary_DasErrors_PEDAL_ADC 1
#define primary_DasErrors_PEDAL_IMPLAUSIBILITY 2
#define primary_DasErrors_IMU_TOUT 4
#define primary_DasErrors_IRTS_TOUT 8
#define primary_DasErrors_TS_TOUT 16
#define primary_DasErrors_INVL_TOUT 32
#define primary_DasErrors_INVR_TOUT 64
#define primary_DasErrors_STEER_TOUT 128
#define primary_DasErrors_FSM 256

#define primary_MAX_STRING_LENGTH_DasErrors 93
int primary_to_string_DasErrors(primary_DasErrors value, char* buffer);

typedef primary_uint32 primary_InvStatus;
#define primary_InvStatus_DEFAULT 0
#define primary_InvStatus_DRIVE_ENABLE 1
#define primary_InvStatus_NCR0 2
#define primary_InvStatus_LIMP 4
#define primary_InvStatus_LIMM 8
#define primary_InvStatus_DRIVE_OK 16
#define primary_InvStatus_ICNS 32
#define primary_InvStatus_T_NLIM 64
#define primary_InvStatus_P_N 128
#define primary_InvStatus_N_I 256
#define primary_InvStatus_N0 512
#define primary_InvStatus_RSW 1024
#define primary_InvStatus_CAL0 2048
#define primary_InvStatus_CAL 4096
#define primary_InvStatus_TOL 8192
#define primary_InvStatus_DRIVE_READY 16384
#define primary_InvStatus_BRK 32768
#define primary_InvStatus_SIGN_MAG 65536
#define primary_InvStatus_NCLIP 131072
#define primary_InvStatus_NCLIPP 262144
#define primary_InvStatus_NCLIPM 524288
#define primary_InvStatus_IRD_DIG 1048576
#define primary_InvStatus_IUSE_RCHD 2097152
#define primary_InvStatus_IRD_N 4194304
#define primary_InvStatus_IRD_TI 8388608
#define primary_InvStatus_IRD_TIR 16777216
#define primary_InvStatus_HZ10 33554432
#define primary_InvStatus_IRD_TM 67108864
#define primary_InvStatus_IRD_ANA 134217728
#define primary_InvStatus_IWCNS 268435456
#define primary_InvStatus_RFE_PULSE 536870912
#define primary_InvStatus_MD 1073741824
#define primary_InvStatus_HND_WHL 2147483648

#define primary_MAX_STRING_LENGTH_InvStatus 208
int primary_to_string_InvStatus(primary_InvStatus value, char* buffer);

typedef primary_uint32 primary_InvErrors;
#define primary_InvErrors_DEFAULT 0
#define primary_InvErrors_BAD_PARAM 1
#define primary_InvErrors_HW_FAULT 2
#define primary_InvErrors_SAFETY_FAULT 4
#define primary_InvErrors_CAN_TIMEOUT 8
#define primary_InvErrors_ENCODER_ERR 16
#define primary_InvErrors_NO_POWER_VOLTAGE 32
#define primary_InvErrors_HI_MOTOR_TEMP 64
#define primary_InvErrors_HI_DEVICE_TEMP 128
#define primary_InvErrors_OVERVOLTAGE 256
#define primary_InvErrors_OVERCURRENT 512
#define primary_InvErrors_RACEAWAY 1024
#define primary_InvErrors_USER_ERR 2048
#define primary_InvErrors_UNKNOWN_ERR_12 4096
#define primary_InvErrors_UNKNOWN_ERR_13 8192
#define primary_InvErrors_CURRENT_ERR 16384
#define primary_InvErrors_BALLAST_OVERLOAD 32768
#define primary_InvErrors_DEVICE_ID_ERR 65536
#define primary_InvErrors_RUN_SIG_FAULT 131072
#define primary_InvErrors_UNKNOWN_ERR_19 262144
#define primary_InvErrors_UNKNOWN_ERR_20 524288
#define primary_InvErrors_POWERVOLTAGE_WARN 1048576
#define primary_InvErrors_HI_MOTOR_TEMP_WARN 2097152
#define primary_InvErrors_HI_DEVICE_TEMP_WARN 4194304
#define primary_InvErrors_VOUT_LIMIT_WARN 8388608
#define primary_InvErrors_OVERCURRENT_WARN 16777216
#define primary_InvErrors_RACEAWAY_WARN 33554432
#define primary_InvErrors_UNKNOWN_ERR_27 67108864
#define primary_InvErrors_UNKNOWN_ERR_28 134217728
#define primary_InvErrors_UNKNOWN_ERR_29 268435456
#define primary_InvErrors_UNKNOWN_ERR_30 536870912
#define primary_InvErrors_BALLAST_OVERLOAD_WARN 1073741824

#define primary_MAX_STRING_LENGTH_InvErrors 447
int primary_to_string_InvErrors(primary_InvErrors value, char* buffer);

typedef primary_uint16 primary_Inv_IOInfo;
#define primary_Inv_IOInfo_DEFAULT 0
#define primary_Inv_IOInfo_LMT1 1
#define primary_Inv_IOInfo_LMT2 2
#define primary_Inv_IOInfo_IN2 4
#define primary_Inv_IOInfo_IN1 8
#define primary_Inv_IOInfo_FRG 16
#define primary_Inv_IOInfo_RFE 32
#define primary_Inv_IOInfo_UNK6 64
#define primary_Inv_IOInfo_UNK7 128
#define primary_Inv_IOInfo_OUT1 256
#define primary_Inv_IOInfo_OUT2 512
#define primary_Inv_IOInfo_BTB 1024
#define primary_Inv_IOInfo_GO 2048
#define primary_Inv_IOInfo_OUT3 4096
#define primary_Inv_IOInfo_OUT4 8192
#define primary_Inv_IOInfo_G_OFF 16384
#define primary_Inv_IOInfo_BRK1 32768

#define primary_MAX_STRING_LENGTH_Inv_IOInfo 74
int primary_to_string_Inv_IOInfo(primary_Inv_IOInfo value, char* buffer);

typedef primary_uint32 primary_HvFeedbacks;
#define primary_HvFeedbacks_DEFAULT 0
#define primary_HvFeedbacks_FEEDBACK_TSAL_GREEN_FAULT 1
#define primary_HvFeedbacks_FEEDBACK_IMD_LATCHED 2
#define primary_HvFeedbacks_FEEDBACK_TSAL_GREEN_FAULT_LATCHED 4
#define primary_HvFeedbacks_FEEDBACK_BMS_LATCHED 8
#define primary_HvFeedbacks_FEEDBACK_EXT_LATCHED 16
#define primary_HvFeedbacks_FEEDBACK_TSAL_GREEN 32
#define primary_HvFeedbacks_FEEDBACK_TS_OVER_60V_STATUS 64
#define primary_HvFeedbacks_FEEDBACK_AIRN_STATUS 128
#define primary_HvFeedbacks_FEEDBACK_AIRP_STATUS 256
#define primary_HvFeedbacks_FEEDBACK_AIRP_GATE 512
#define primary_HvFeedbacks_FEEDBACK_AIRN_GATE 1024
#define primary_HvFeedbacks_FEEDBACK_PRECHARGE_STATUS 2048
#define primary_HvFeedbacks_FEEDBACK_TSP_OVER_60V_STATUS 4096
#define primary_HvFeedbacks_FEEDBACK_CHECK_MUX 8192
#define primary_HvFeedbacks_FEEDBACK_SD_IN 16384
#define primary_HvFeedbacks_FEEDBACK_SD_OUT 32768
#define primary_HvFeedbacks_FEEDBACK_RELAY_SD 65536
#define primary_HvFeedbacks_FEEDBACK_IMD_FAULT 131072
#define primary_HvFeedbacks_FEEDBACK_SD_END 262144

#define primary_MAX_STRING_LENGTH_HvFeedbacks 409
int primary_to_string_HvFeedbacks(primary_HvFeedbacks value, char* buffer);


// ============== ENUMS ============== //


typedef enum CANLIB_PARKING {
    primary_RaceType_ACCELERATION = 0,
    primary_RaceType_SKIDPAD = 1,
    primary_RaceType_AUTOCROSS = 2,
    primary_RaceType_ENDURANCE = 3,
} primary_RaceType;

#define primary_MAX_STRING_LENGTH_RaceType 13
int primary_to_string_RaceType(primary_RaceType value, char* buffer);

typedef enum CANLIB_PARKING {
    primary_InverterStatus_OFF = 0,
    primary_InverterStatus_IDLE = 1,
    primary_InverterStatus_ON = 2,
} primary_InverterStatus;

#define primary_MAX_STRING_LENGTH_InverterStatus 5
int primary_to_string_InverterStatus(primary_InverterStatus value, char* buffer);

typedef enum CANLIB_PARKING {
    primary_CarStatus_IDLE = 0,
    primary_CarStatus_PRE_SETUP = 1,
    primary_CarStatus_TS_ON = 2,
    primary_CarStatus_POST_SETUP = 3,
    primary_CarStatus_DRIVE = 4,
    primary_CarStatus_TEARDOWN = 5,
} primary_CarStatus;

#define primary_MAX_STRING_LENGTH_CarStatus 11
int primary_to_string_CarStatus(primary_CarStatus value, char* buffer);

typedef enum CANLIB_PARKING {
    primary_Toggle_ON = 0,
    primary_Toggle_OFF = 1,
} primary_Toggle;

#define primary_MAX_STRING_LENGTH_Toggle 4
int primary_to_string_Toggle(primary_Toggle value, char* buffer);

typedef enum CANLIB_PARKING {
    primary_TractionControl_OFF = 0,
    primary_TractionControl_SLIP_CONTROL = 1,
    primary_TractionControl_TORQUE_VECTORING = 2,
    primary_TractionControl_COMPLETE = 3,
} primary_TractionControl;

#define primary_MAX_STRING_LENGTH_TractionControl 17
int primary_to_string_TractionControl(primary_TractionControl value, char* buffer);

typedef enum CANLIB_PARKING {
    primary_TsStatus_OFF = 0,
    primary_TsStatus_PRECHARGE = 1,
    primary_TsStatus_ON = 2,
    primary_TsStatus_FATAL = 3,
} primary_TsStatus;

#define primary_MAX_STRING_LENGTH_TsStatus 10
int primary_to_string_TsStatus(primary_TsStatus value, char* buffer);

typedef enum CANLIB_PARKING {
    primary_Map_R = 0,
    primary_Map_D20 = 1,
    primary_Map_D40 = 2,
    primary_Map_D60 = 3,
    primary_Map_D80 = 4,
    primary_Map_D100 = 5,
} primary_Map;

#define primary_MAX_STRING_LENGTH_Map 5
int primary_to_string_Map(primary_Map value, char* buffer);

typedef enum CANLIB_PARKING {
    primary_SetCarStatus_IDLE = 0,
    primary_SetCarStatus_READY = 1,
    primary_SetCarStatus_DRIVE = 2,
} primary_SetCarStatus;

#define primary_MAX_STRING_LENGTH_SetCarStatus 6
int primary_to_string_SetCarStatus(primary_SetCarStatus value, char* buffer);

typedef enum CANLIB_PARKING {
    primary_Bound_SET_MAX = 0,
    primary_Bound_SET_MIN = 1,
} primary_Bound;

#define primary_MAX_STRING_LENGTH_Bound 8
int primary_to_string_Bound(primary_Bound value, char* buffer);

typedef enum CANLIB_PARKING {
    primary_Pedal_ACCELERATOR = 0,
    primary_Pedal_BRAKE = 1,
} primary_Pedal;

#define primary_MAX_STRING_LENGTH_Pedal 12
int primary_to_string_Pedal(primary_Pedal value, char* buffer);

typedef enum CANLIB_PARKING {
    primary_ImdStatus_IMD_SC = 0,
    primary_ImdStatus_IMD_NORMAL = 1,
    primary_ImdStatus_IMD_UNDER_VOLTAGE = 2,
    primary_ImdStatus_IMD_START_MEASURE = 3,
    primary_ImdStatus_IMD_DEVICE_ERROR = 4,
    primary_ImdStatus_IMD_EARTH_FAULT = 5,
} primary_ImdStatus;

#define primary_MAX_STRING_LENGTH_ImdStatus 18
int primary_to_string_ImdStatus(primary_ImdStatus value, char* buffer);


// Structs


typedef struct CANLIB_PARKING {
    primary_uint8 _placeholder; // C++ doesn't like empty structs
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_BMS_HV_JMP_TO_BLT;

typedef struct CANLIB_PARKING {
    primary_uint8 _placeholder; // C++ doesn't like empty structs
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_BMS_LV_JMP_TO_BLT;

typedef struct CANLIB_PARKING {
    primary_uint8 component_version;
    primary_uint32 cancicd_version;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_STEER_VERSION;

typedef struct CANLIB_PARKING {
    primary_uint8 component_version;
    primary_uint32 cancicd_version;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_DAS_VERSION;

typedef struct CANLIB_PARKING {
    primary_uint8 component_version;
    primary_uint32 cancicd_version;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_HV_VERSION;

typedef struct CANLIB_PARKING {
    primary_uint8 component_version;
    primary_uint32 cancicd_version;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_LV_VERSION;

typedef struct CANLIB_PARKING {
    primary_uint8 component_version;
    primary_uint32 cancicd_version;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_TLM_VERSION;

typedef struct CANLIB_PARKING {
    primary_uint32 timestamp;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_TIMESTAMP;

typedef struct CANLIB_PARKING {
    primary_Toggle tlm_status;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_SET_TLM_STATUS;

typedef struct CANLIB_PARKING {
    primary_Toggle tlm_status;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_TLM_STATUS;

typedef struct CANLIB_PARKING {
    primary_uint8 soc_temp;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_STEER_SYSTEM_STATUS;

typedef struct CANLIB_PARKING {
    primary_uint16 pack_voltage;
    primary_uint16 bus_voltage;
    primary_uint16 max_cell_voltage;
    primary_uint16 min_cell_voltage;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_HV_VOLTAGE;

typedef struct CANLIB_PARKING {
    primary_float32 pack_voltage;
    primary_float32 bus_voltage;
    primary_float32 max_cell_voltage;
    primary_float32 min_cell_voltage;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_HV_VOLTAGE_conversion;

typedef struct CANLIB_PARKING {
    primary_uint16 current;
    primary_uint16 power;
    primary_uint16 energy;
    primary_uint8 soc;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_HV_CURRENT;

typedef struct CANLIB_PARKING {
    primary_float32 current;
    primary_float32 power;
    primary_float32 energy;
    primary_float32 soc;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_HV_CURRENT_conversion;

typedef struct CANLIB_PARKING {
    primary_uint8 average_temp;
    primary_uint8 max_temp;
    primary_uint8 min_temp;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_HV_TEMP;

typedef struct CANLIB_PARKING {
    primary_float32 average_temp;
    primary_float32 max_temp;
    primary_float32 min_temp;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_HV_TEMP_conversion;

typedef struct CANLIB_PARKING {
    primary_HvErrors warnings;
    primary_HvErrors errors;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_HV_ERRORS;

typedef struct CANLIB_PARKING {
    primary_Toggle can_forward_set;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_HV_CAN_FORWARD;

typedef struct CANLIB_PARKING {
    primary_Toggle fans_override;
    primary_uint16 fans_speed;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_HV_FANS_OVERRIDE;

typedef struct CANLIB_PARKING {
    primary_Toggle fans_override;
    primary_float32 fans_speed;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_HV_FANS_OVERRIDE_conversion;

typedef struct CANLIB_PARKING {
    primary_Toggle can_forward_status;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_HV_CAN_FORWARD_STATUS;

typedef struct CANLIB_PARKING {
    primary_Toggle fans_override;
    primary_uint16 fans_speed;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_HV_FANS_OVERRIDE_STATUS;

typedef struct CANLIB_PARKING {
    primary_Toggle fans_override;
    primary_float32 fans_speed;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_HV_FANS_OVERRIDE_STATUS_conversion;

typedef struct CANLIB_PARKING {
    primary_HvFeedbacks feedbacks_status;
    primary_HvFeedbacks is_circuitry_error;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_HV_FEEDBACKS_STATUS;

typedef struct CANLIB_PARKING {
    primary_bool imd_fault;
    primary_ImdStatus imd_status;
    primary_int32 imd_info;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_HV_IMD_STATUS;

typedef struct CANLIB_PARKING {
    primary_TsStatus ts_status;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_TS_STATUS;

typedef struct CANLIB_PARKING {
    primary_Toggle ts_status_set;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_SET_TS_STATUS;

typedef struct CANLIB_PARKING {
    primary_TractionControl traction_control;
    primary_Map map;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_STEER_STATUS;

typedef struct CANLIB_PARKING {
    primary_SetCarStatus car_status_set;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_SET_CAR_STATUS;

typedef struct CANLIB_PARKING {
    primary_Bound bound;
    primary_Pedal pedal;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_SET_PEDALS_RANGE;

typedef struct CANLIB_PARKING {
    primary_Bound bound;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_SET_STEERING_ANGLE_RANGE;

typedef struct CANLIB_PARKING {
    primary_InverterStatus inverter_l;
    primary_InverterStatus inverter_r;
    primary_CarStatus car_status;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_CAR_STATUS;

typedef struct CANLIB_PARKING {
    primary_DasErrors das_error;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_DAS_ERRORS;

typedef struct CANLIB_PARKING {
    primary_uint16 current;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_LV_CURRENT;

typedef struct CANLIB_PARKING {
    primary_float32 current;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_LV_CURRENT_conversion;

typedef struct CANLIB_PARKING {
    primary_uint16 voltage_1;
    primary_uint16 voltage_2;
    primary_uint16 voltage_3;
    primary_uint16 voltage_4;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_LV_VOLTAGE;

typedef struct CANLIB_PARKING {
    primary_float32 voltage_1;
    primary_float32 voltage_2;
    primary_float32 voltage_3;
    primary_float32 voltage_4;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_LV_VOLTAGE_conversion;

typedef struct CANLIB_PARKING {
    primary_uint32 total_voltage;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_LV_TOTAL_VOLTAGE;

typedef struct CANLIB_PARKING {
    primary_float32 total_voltage;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_LV_TOTAL_VOLTAGE_conversion;

typedef struct CANLIB_PARKING {
    primary_uint16 bp_temperature_1;
    primary_uint16 bp_temperature_2;
    primary_uint16 dcdc12_temperature;
    primary_uint16 dcdc24_temperature;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_LV_TEMPERATURE;

typedef struct CANLIB_PARKING {
    primary_float32 bp_temperature_1;
    primary_float32 bp_temperature_2;
    primary_float32 dcdc12_temperature;
    primary_float32 dcdc24_temperature;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_LV_TEMPERATURE_conversion;

typedef struct CANLIB_PARKING {
    primary_uint16 radiators_speed;
    primary_uint16 pumps_speed;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_COOLING_STATUS;

typedef struct CANLIB_PARKING {
    primary_float32 radiators_speed;
    primary_float32 pumps_speed;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_COOLING_STATUS_conversion;

typedef struct CANLIB_PARKING {
    primary_uint16 radiators_speed;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_SET_RADIATOR_SPEED;

typedef struct CANLIB_PARKING {
    primary_float32 radiators_speed;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_SET_RADIATOR_SPEED_conversion;

typedef struct CANLIB_PARKING {
    primary_uint16 pumps_speed;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_SET_PUMPS_SPEED;

typedef struct CANLIB_PARKING {
    primary_float32 pumps_speed;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_SET_PUMPS_SPEED_conversion;

typedef struct CANLIB_PARKING {
    primary_Toggle status;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_SET_INVERTER_CONNECTION_STATUS;

typedef struct CANLIB_PARKING {
    primary_Toggle status;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_INVERTER_CONNECTION_STATUS;

typedef struct CANLIB_PARKING {
    primary_LvErrors warnings;
    primary_LvErrors errors;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_LV_ERRORS;

typedef struct CANLIB_PARKING {
    primary_bool input;
    primary_bool output;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_SHUTDOWN_STATUS;

typedef struct CANLIB_PARKING {
    primary_uint8 _placeholder; // C++ doesn't like empty structs
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_MARKER;

typedef struct CANLIB_PARKING {
    primary_uint8 start_index;
    primary_uint16 voltage_0;
    primary_uint16 voltage_1;
    primary_uint16 voltage_2;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_HV_CELLS_VOLTAGE;

typedef struct CANLIB_PARKING {
    primary_uint8 start_index;
    primary_float32 voltage_0;
    primary_float32 voltage_1;
    primary_float32 voltage_2;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_HV_CELLS_VOLTAGE_conversion;

typedef struct CANLIB_PARKING {
    primary_uint8 start_index;
    primary_uint8 temp_0;
    primary_uint8 temp_1;
    primary_uint8 temp_2;
    primary_uint8 temp_3;
    primary_uint8 temp_4;
    primary_uint8 temp_5;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_HV_CELLS_TEMP;

typedef struct CANLIB_PARKING {
    primary_uint8 start_index;
    primary_float32 temp_0;
    primary_float32 temp_1;
    primary_float32 temp_2;
    primary_float32 temp_3;
    primary_float32 temp_4;
    primary_float32 temp_5;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_HV_CELLS_TEMP_conversion;

typedef struct CANLIB_PARKING {
    primary_Toggle balancing_status;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_HV_CELL_BALANCING_STATUS;

typedef struct CANLIB_PARKING {
    primary_Toggle set_balancing_status;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_SET_CELL_BALANCING_STATUS;

typedef struct CANLIB_PARKING {
    primary_bool connected;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_HANDCART_STATUS;

typedef struct CANLIB_PARKING {
    primary_uint8 encoder_r;
    primary_uint8 encoder_l;
    primary_uint8 inverter_r;
    primary_uint8 inverter_l;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_SPEED;

typedef struct CANLIB_PARKING {
    primary_float32 encoder_r;
    primary_float32 encoder_l;
    primary_float32 inverter_r;
    primary_float32 inverter_l;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_SPEED_conversion;

typedef struct CANLIB_PARKING {
    primary_uint8 data_0;
    primary_uint8 data_1;
    primary_uint8 data_2;
    primary_uint8 data_3;
    primary_uint8 data_4;
    primary_uint8 data_5;
    primary_uint8 data_6;
    primary_uint8 data_7;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_INV_L_REQUEST;

typedef struct CANLIB_PARKING {
    primary_uint8 data_0;
    primary_uint8 data_1;
    primary_uint8 data_2;
    primary_uint8 data_3;
    primary_uint8 data_4;
    primary_uint8 data_5;
    primary_uint8 data_6;
    primary_uint8 data_7;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_INV_R_REQUEST;

typedef struct CANLIB_PARKING {
    primary_uint8 reg_id;
    primary_uint8 data_0;
    primary_uint8 data_1;
    primary_uint8 data_2;
    primary_uint8 data_3;
    primary_uint8 data_4;
    primary_uint8 data_5;
    primary_uint8 data_6;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_INV_L_RESPONSE;

typedef struct CANLIB_PARKING {
    primary_uint8 reg_id;
    primary_uint8 data_0;
    primary_uint8 data_1;
    primary_uint8 data_2;
    primary_uint8 data_3;
    primary_uint8 data_4;
    primary_uint8 data_5;
    primary_uint8 data_6;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_INV_R_RESPONSE;

typedef struct CANLIB_PARKING {
    primary_uint8 _placeholder; // C++ doesn't like empty structs
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_FLASH_CELLBOARD_0_TX;

typedef struct CANLIB_PARKING {
    primary_uint8 _placeholder; // C++ doesn't like empty structs
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_FLASH_CELLBOARD_0_RX;

typedef struct CANLIB_PARKING {
    primary_uint8 _placeholder; // C++ doesn't like empty structs
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_FLASH_CELLBOARD_1_TX;

typedef struct CANLIB_PARKING {
    primary_uint8 _placeholder; // C++ doesn't like empty structs
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_FLASH_CELLBOARD_1_RX;

typedef struct CANLIB_PARKING {
    primary_uint8 _placeholder; // C++ doesn't like empty structs
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_FLASH_CELLBOARD_2_TX;

typedef struct CANLIB_PARKING {
    primary_uint8 _placeholder; // C++ doesn't like empty structs
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_FLASH_CELLBOARD_2_RX;

typedef struct CANLIB_PARKING {
    primary_uint8 _placeholder; // C++ doesn't like empty structs
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_FLASH_CELLBOARD_3_TX;

typedef struct CANLIB_PARKING {
    primary_uint8 _placeholder; // C++ doesn't like empty structs
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_FLASH_CELLBOARD_3_RX;

typedef struct CANLIB_PARKING {
    primary_uint8 _placeholder; // C++ doesn't like empty structs
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_FLASH_CELLBOARD_4_TX;

typedef struct CANLIB_PARKING {
    primary_uint8 _placeholder; // C++ doesn't like empty structs
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_FLASH_CELLBOARD_4_RX;

typedef struct CANLIB_PARKING {
    primary_uint8 _placeholder; // C++ doesn't like empty structs
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_FLASH_CELLBOARD_5_TX;

typedef struct CANLIB_PARKING {
    primary_uint8 _placeholder; // C++ doesn't like empty structs
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_FLASH_CELLBOARD_5_RX;

typedef struct CANLIB_PARKING {
    primary_uint8 _placeholder; // C++ doesn't like empty structs
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_FLASH_BMS_HV_TX;

typedef struct CANLIB_PARKING {
    primary_uint8 _placeholder; // C++ doesn't like empty structs
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_FLASH_BMS_HV_RX;

typedef struct CANLIB_PARKING {
    primary_uint8 _placeholder; // C++ doesn't like empty structs
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_FLASH_BMS_LV_TX;

typedef struct CANLIB_PARKING {
    primary_uint8 _placeholder; // C++ doesn't like empty structs
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_FLASH_BMS_LV_RX;

typedef struct CANLIB_PARKING {
    primary_uint8 _placeholder; // C++ doesn't like empty structs
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_BRUSA_NLG5_CTL;

typedef struct CANLIB_PARKING {
    primary_uint8 _placeholder; // C++ doesn't like empty structs
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_BRUSA_ST;

typedef struct CANLIB_PARKING {
    primary_uint8 _placeholder; // C++ doesn't like empty structs
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_BRUSA_ACT_I;

typedef struct CANLIB_PARKING {
    primary_uint8 _placeholder; // C++ doesn't like empty structs
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_BRUSA_ACT_II;

typedef struct CANLIB_PARKING {
    primary_uint8 _placeholder; // C++ doesn't like empty structs
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_BRUSA_TEMP;

typedef struct CANLIB_PARKING {
    primary_uint8 _placeholder; // C++ doesn't like empty structs
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_BRUSA_ERR;

typedef struct CANLIB_PARKING {
    primary_uint8 _placeholder; // C++ doesn't like empty structs
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_BMS_HV_CHIMERA;

typedef struct CANLIB_PARKING {
    primary_uint8 _placeholder; // C++ doesn't like empty structs
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_ECU_CHIMERA;


typedef union CANLIB_PARKING {
    primary_message_BMS_HV_JMP_TO_BLT _BMS_HV_JMP_TO_BLT;
    primary_message_BMS_LV_JMP_TO_BLT _BMS_LV_JMP_TO_BLT;
    primary_message_STEER_VERSION _STEER_VERSION;
    primary_message_DAS_VERSION _DAS_VERSION;
    primary_message_HV_VERSION _HV_VERSION;
    primary_message_LV_VERSION _LV_VERSION;
    primary_message_TLM_VERSION _TLM_VERSION;
    primary_message_TIMESTAMP _TIMESTAMP;
    primary_message_SET_TLM_STATUS _SET_TLM_STATUS;
    primary_message_TLM_STATUS _TLM_STATUS;
    primary_message_STEER_SYSTEM_STATUS _STEER_SYSTEM_STATUS;
    primary_message_HV_VOLTAGE _HV_VOLTAGE;
    primary_message_HV_CURRENT _HV_CURRENT;
    primary_message_HV_TEMP _HV_TEMP;
    primary_message_HV_ERRORS _HV_ERRORS;
    primary_message_HV_CAN_FORWARD _HV_CAN_FORWARD;
    primary_message_HV_FANS_OVERRIDE _HV_FANS_OVERRIDE;
    primary_message_HV_CAN_FORWARD_STATUS _HV_CAN_FORWARD_STATUS;
    primary_message_HV_FANS_OVERRIDE_STATUS _HV_FANS_OVERRIDE_STATUS;
    primary_message_HV_FEEDBACKS_STATUS _HV_FEEDBACKS_STATUS;
    primary_message_HV_IMD_STATUS _HV_IMD_STATUS;
    primary_message_TS_STATUS _TS_STATUS;
    primary_message_SET_TS_STATUS _SET_TS_STATUS;
    primary_message_STEER_STATUS _STEER_STATUS;
    primary_message_SET_CAR_STATUS _SET_CAR_STATUS;
    primary_message_SET_PEDALS_RANGE _SET_PEDALS_RANGE;
    primary_message_SET_STEERING_ANGLE_RANGE _SET_STEERING_ANGLE_RANGE;
    primary_message_CAR_STATUS _CAR_STATUS;
    primary_message_DAS_ERRORS _DAS_ERRORS;
    primary_message_LV_CURRENT _LV_CURRENT;
    primary_message_LV_VOLTAGE _LV_VOLTAGE;
    primary_message_LV_TOTAL_VOLTAGE _LV_TOTAL_VOLTAGE;
    primary_message_LV_TEMPERATURE _LV_TEMPERATURE;
    primary_message_COOLING_STATUS _COOLING_STATUS;
    primary_message_SET_RADIATOR_SPEED _SET_RADIATOR_SPEED;
    primary_message_SET_PUMPS_SPEED _SET_PUMPS_SPEED;
    primary_message_SET_INVERTER_CONNECTION_STATUS _SET_INVERTER_CONNECTION_STATUS;
    primary_message_INVERTER_CONNECTION_STATUS _INVERTER_CONNECTION_STATUS;
    primary_message_LV_ERRORS _LV_ERRORS;
    primary_message_SHUTDOWN_STATUS _SHUTDOWN_STATUS;
    primary_message_MARKER _MARKER;
    primary_message_HV_CELLS_VOLTAGE _HV_CELLS_VOLTAGE;
    primary_message_HV_CELLS_TEMP _HV_CELLS_TEMP;
    primary_message_HV_CELL_BALANCING_STATUS _HV_CELL_BALANCING_STATUS;
    primary_message_SET_CELL_BALANCING_STATUS _SET_CELL_BALANCING_STATUS;
    primary_message_HANDCART_STATUS _HANDCART_STATUS;
    primary_message_SPEED _SPEED;
    primary_message_INV_L_REQUEST _INV_L_REQUEST;
    primary_message_INV_R_REQUEST _INV_R_REQUEST;
    primary_message_INV_L_RESPONSE _INV_L_RESPONSE;
    primary_message_INV_R_RESPONSE _INV_R_RESPONSE;
    primary_message_FLASH_CELLBOARD_0_TX _FLASH_CELLBOARD_0_TX;
    primary_message_FLASH_CELLBOARD_0_RX _FLASH_CELLBOARD_0_RX;
    primary_message_FLASH_CELLBOARD_1_TX _FLASH_CELLBOARD_1_TX;
    primary_message_FLASH_CELLBOARD_1_RX _FLASH_CELLBOARD_1_RX;
    primary_message_FLASH_CELLBOARD_2_TX _FLASH_CELLBOARD_2_TX;
    primary_message_FLASH_CELLBOARD_2_RX _FLASH_CELLBOARD_2_RX;
    primary_message_FLASH_CELLBOARD_3_TX _FLASH_CELLBOARD_3_TX;
    primary_message_FLASH_CELLBOARD_3_RX _FLASH_CELLBOARD_3_RX;
    primary_message_FLASH_CELLBOARD_4_TX _FLASH_CELLBOARD_4_TX;
    primary_message_FLASH_CELLBOARD_4_RX _FLASH_CELLBOARD_4_RX;
    primary_message_FLASH_CELLBOARD_5_TX _FLASH_CELLBOARD_5_TX;
    primary_message_FLASH_CELLBOARD_5_RX _FLASH_CELLBOARD_5_RX;
    primary_message_FLASH_BMS_HV_TX _FLASH_BMS_HV_TX;
    primary_message_FLASH_BMS_HV_RX _FLASH_BMS_HV_RX;
    primary_message_FLASH_BMS_LV_TX _FLASH_BMS_LV_TX;
    primary_message_FLASH_BMS_LV_RX _FLASH_BMS_LV_RX;
    primary_message_BRUSA_NLG5_CTL _BRUSA_NLG5_CTL;
    primary_message_BRUSA_ST _BRUSA_ST;
    primary_message_BRUSA_ACT_I _BRUSA_ACT_I;
    primary_message_BRUSA_ACT_II _BRUSA_ACT_II;
    primary_message_BRUSA_TEMP _BRUSA_TEMP;
    primary_message_BRUSA_ERR _BRUSA_ERR;
    primary_message_BMS_HV_CHIMERA _BMS_HV_CHIMERA;
    primary_message_ECU_CHIMERA _ECU_CHIMERA;
} _primary_all_structs_raw;

typedef union CANLIB_PARKING {
    primary_message_HV_VOLTAGE_conversion _HV_VOLTAGE;
    primary_message_HV_CURRENT_conversion _HV_CURRENT;
    primary_message_HV_TEMP_conversion _HV_TEMP;
    primary_message_HV_FANS_OVERRIDE_conversion _HV_FANS_OVERRIDE;
    primary_message_HV_FANS_OVERRIDE_STATUS_conversion _HV_FANS_OVERRIDE_STATUS;
    primary_message_LV_CURRENT_conversion _LV_CURRENT;
    primary_message_LV_VOLTAGE_conversion _LV_VOLTAGE;
    primary_message_LV_TOTAL_VOLTAGE_conversion _LV_TOTAL_VOLTAGE;
    primary_message_LV_TEMPERATURE_conversion _LV_TEMPERATURE;
    primary_message_COOLING_STATUS_conversion _COOLING_STATUS;
    primary_message_SET_RADIATOR_SPEED_conversion _SET_RADIATOR_SPEED;
    primary_message_SET_PUMPS_SPEED_conversion _SET_PUMPS_SPEED;
    primary_message_HV_CELLS_VOLTAGE_conversion _HV_CELLS_VOLTAGE;
    primary_message_HV_CELLS_TEMP_conversion _HV_CELLS_TEMP;
    primary_message_SPEED_conversion _SPEED;
} _primary_all_structs_conversion;

typedef union CANLIB_PARKING {
    _primary_all_structs_raw raw;
    _primary_all_structs_conversion conversion;
} _primary_all_structs;

#define primary_MAX_STRUCT_SIZE_RAW sizeof(_primary_all_structs_raw)
#define primary_MAX_STRUCT_SIZE_CONVERSION sizeof(_primary_all_structs_conversion)
#define primary_MAX_STRUCT_SIZE sizeof(_primary_all_structs)


// ============== BMS_HV_JMP_TO_BLT ============== //

primary_byte_size primary_serialize_BMS_HV_JMP_TO_BLT(
    uint8_t* data
);
primary_byte_size primary_serialize_struct_BMS_HV_JMP_TO_BLT(
    uint8_t* data,
    primary_message_BMS_HV_JMP_TO_BLT* message
);
void primary_deserialize_BMS_HV_JMP_TO_BLT(
    primary_message_BMS_HV_JMP_TO_BLT* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_BMS_HV_JMP_TO_BLT(primary_message_BMS_HV_JMP_TO_BLT* message, char* buffer);
int primary_fields_BMS_HV_JMP_TO_BLT(char* buffer);
int primary_to_string_file_BMS_HV_JMP_TO_BLT(primary_message_BMS_HV_JMP_TO_BLT* message, FILE* buffer);
int primary_fields_file_BMS_HV_JMP_TO_BLT(FILE* buffer);


// ============== BMS_LV_JMP_TO_BLT ============== //

primary_byte_size primary_serialize_BMS_LV_JMP_TO_BLT(
    uint8_t* data
);
primary_byte_size primary_serialize_struct_BMS_LV_JMP_TO_BLT(
    uint8_t* data,
    primary_message_BMS_LV_JMP_TO_BLT* message
);
void primary_deserialize_BMS_LV_JMP_TO_BLT(
    primary_message_BMS_LV_JMP_TO_BLT* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_BMS_LV_JMP_TO_BLT(primary_message_BMS_LV_JMP_TO_BLT* message, char* buffer);
int primary_fields_BMS_LV_JMP_TO_BLT(char* buffer);
int primary_to_string_file_BMS_LV_JMP_TO_BLT(primary_message_BMS_LV_JMP_TO_BLT* message, FILE* buffer);
int primary_fields_file_BMS_LV_JMP_TO_BLT(FILE* buffer);


// ============== STEER_VERSION ============== //

primary_byte_size primary_serialize_STEER_VERSION(
    uint8_t* data,
    primary_uint8 component_version,
    primary_uint32 cancicd_version
);
primary_byte_size primary_serialize_struct_STEER_VERSION(
    uint8_t* data,
    primary_message_STEER_VERSION* message
);
void primary_deserialize_STEER_VERSION(
    primary_message_STEER_VERSION* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_STEER_VERSION(primary_message_STEER_VERSION* message, char* buffer);
int primary_fields_STEER_VERSION(char* buffer);
int primary_to_string_file_STEER_VERSION(primary_message_STEER_VERSION* message, FILE* buffer);
int primary_fields_file_STEER_VERSION(FILE* buffer);


// ============== DAS_VERSION ============== //

primary_byte_size primary_serialize_DAS_VERSION(
    uint8_t* data,
    primary_uint8 component_version,
    primary_uint32 cancicd_version
);
primary_byte_size primary_serialize_struct_DAS_VERSION(
    uint8_t* data,
    primary_message_DAS_VERSION* message
);
void primary_deserialize_DAS_VERSION(
    primary_message_DAS_VERSION* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_DAS_VERSION(primary_message_DAS_VERSION* message, char* buffer);
int primary_fields_DAS_VERSION(char* buffer);
int primary_to_string_file_DAS_VERSION(primary_message_DAS_VERSION* message, FILE* buffer);
int primary_fields_file_DAS_VERSION(FILE* buffer);


// ============== HV_VERSION ============== //

primary_byte_size primary_serialize_HV_VERSION(
    uint8_t* data,
    primary_uint8 component_version,
    primary_uint32 cancicd_version
);
primary_byte_size primary_serialize_struct_HV_VERSION(
    uint8_t* data,
    primary_message_HV_VERSION* message
);
void primary_deserialize_HV_VERSION(
    primary_message_HV_VERSION* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_HV_VERSION(primary_message_HV_VERSION* message, char* buffer);
int primary_fields_HV_VERSION(char* buffer);
int primary_to_string_file_HV_VERSION(primary_message_HV_VERSION* message, FILE* buffer);
int primary_fields_file_HV_VERSION(FILE* buffer);


// ============== LV_VERSION ============== //

primary_byte_size primary_serialize_LV_VERSION(
    uint8_t* data,
    primary_uint8 component_version,
    primary_uint32 cancicd_version
);
primary_byte_size primary_serialize_struct_LV_VERSION(
    uint8_t* data,
    primary_message_LV_VERSION* message
);
void primary_deserialize_LV_VERSION(
    primary_message_LV_VERSION* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_LV_VERSION(primary_message_LV_VERSION* message, char* buffer);
int primary_fields_LV_VERSION(char* buffer);
int primary_to_string_file_LV_VERSION(primary_message_LV_VERSION* message, FILE* buffer);
int primary_fields_file_LV_VERSION(FILE* buffer);


// ============== TLM_VERSION ============== //

primary_byte_size primary_serialize_TLM_VERSION(
    uint8_t* data,
    primary_uint8 component_version,
    primary_uint32 cancicd_version
);
primary_byte_size primary_serialize_struct_TLM_VERSION(
    uint8_t* data,
    primary_message_TLM_VERSION* message
);
void primary_deserialize_TLM_VERSION(
    primary_message_TLM_VERSION* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_TLM_VERSION(primary_message_TLM_VERSION* message, char* buffer);
int primary_fields_TLM_VERSION(char* buffer);
int primary_to_string_file_TLM_VERSION(primary_message_TLM_VERSION* message, FILE* buffer);
int primary_fields_file_TLM_VERSION(FILE* buffer);


// ============== TIMESTAMP ============== //

primary_byte_size primary_serialize_TIMESTAMP(
    uint8_t* data,
    primary_uint32 timestamp
);
primary_byte_size primary_serialize_struct_TIMESTAMP(
    uint8_t* data,
    primary_message_TIMESTAMP* message
);
void primary_deserialize_TIMESTAMP(
    primary_message_TIMESTAMP* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_TIMESTAMP(primary_message_TIMESTAMP* message, char* buffer);
int primary_fields_TIMESTAMP(char* buffer);
int primary_to_string_file_TIMESTAMP(primary_message_TIMESTAMP* message, FILE* buffer);
int primary_fields_file_TIMESTAMP(FILE* buffer);


// ============== SET_TLM_STATUS ============== //

primary_byte_size primary_serialize_SET_TLM_STATUS(
    uint8_t* data,
    primary_Toggle tlm_status
);
primary_byte_size primary_serialize_struct_SET_TLM_STATUS(
    uint8_t* data,
    primary_message_SET_TLM_STATUS* message
);
void primary_deserialize_SET_TLM_STATUS(
    primary_message_SET_TLM_STATUS* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_SET_TLM_STATUS(primary_message_SET_TLM_STATUS* message, char* buffer);
int primary_fields_SET_TLM_STATUS(char* buffer);
int primary_to_string_file_SET_TLM_STATUS(primary_message_SET_TLM_STATUS* message, FILE* buffer);
int primary_fields_file_SET_TLM_STATUS(FILE* buffer);


// ============== TLM_STATUS ============== //

primary_byte_size primary_serialize_TLM_STATUS(
    uint8_t* data,
    primary_Toggle tlm_status
);
primary_byte_size primary_serialize_struct_TLM_STATUS(
    uint8_t* data,
    primary_message_TLM_STATUS* message
);
void primary_deserialize_TLM_STATUS(
    primary_message_TLM_STATUS* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_TLM_STATUS(primary_message_TLM_STATUS* message, char* buffer);
int primary_fields_TLM_STATUS(char* buffer);
int primary_to_string_file_TLM_STATUS(primary_message_TLM_STATUS* message, FILE* buffer);
int primary_fields_file_TLM_STATUS(FILE* buffer);


// ============== STEER_SYSTEM_STATUS ============== //

primary_byte_size primary_serialize_STEER_SYSTEM_STATUS(
    uint8_t* data,
    primary_uint8 soc_temp
);
primary_byte_size primary_serialize_struct_STEER_SYSTEM_STATUS(
    uint8_t* data,
    primary_message_STEER_SYSTEM_STATUS* message
);
void primary_deserialize_STEER_SYSTEM_STATUS(
    primary_message_STEER_SYSTEM_STATUS* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_STEER_SYSTEM_STATUS(primary_message_STEER_SYSTEM_STATUS* message, char* buffer);
int primary_fields_STEER_SYSTEM_STATUS(char* buffer);
int primary_to_string_file_STEER_SYSTEM_STATUS(primary_message_STEER_SYSTEM_STATUS* message, FILE* buffer);
int primary_fields_file_STEER_SYSTEM_STATUS(FILE* buffer);


// ============== HV_VOLTAGE ============== //

primary_byte_size primary_serialize_HV_VOLTAGE(
    uint8_t* data,
    primary_uint16 pack_voltage,
    primary_uint16 bus_voltage,
    primary_uint16 max_cell_voltage,
    primary_uint16 min_cell_voltage
);
primary_byte_size primary_serialize_struct_HV_VOLTAGE(
    uint8_t* data,
    primary_message_HV_VOLTAGE* message
);
void primary_deserialize_HV_VOLTAGE(
    primary_message_HV_VOLTAGE* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
void primary_raw_to_conversion_struct_HV_VOLTAGE(
    primary_message_HV_VOLTAGE_conversion* conversion,
    primary_message_HV_VOLTAGE* raw
);

void primary_conversion_to_raw_struct_HV_VOLTAGE(
    primary_message_HV_VOLTAGE* raw,
    primary_message_HV_VOLTAGE_conversion* conversion
);

void primary_conversion_to_raw_HV_VOLTAGE(
    primary_message_HV_VOLTAGE* raw,
    primary_float32 pack_voltage,
    primary_float32 bus_voltage,
    primary_float32 max_cell_voltage,
    primary_float32 min_cell_voltage
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
);

void primary_raw_to_conversion_HV_VOLTAGE(
    primary_message_HV_VOLTAGE_conversion* conversion,
    primary_uint16 pack_voltage,
    primary_uint16 bus_voltage,
    primary_uint16 max_cell_voltage,
    primary_uint16 min_cell_voltage
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_HV_VOLTAGE(primary_message_HV_VOLTAGE_conversion* message, char* buffer);
int primary_fields_HV_VOLTAGE(char* buffer);
int primary_to_string_file_HV_VOLTAGE(primary_message_HV_VOLTAGE_conversion* message, FILE* buffer);
int primary_fields_file_HV_VOLTAGE(FILE* buffer);


// ============== HV_CURRENT ============== //

primary_byte_size primary_serialize_HV_CURRENT(
    uint8_t* data,
    primary_uint16 current,
    primary_uint16 power,
    primary_uint16 energy,
    primary_uint8 soc
);
primary_byte_size primary_serialize_struct_HV_CURRENT(
    uint8_t* data,
    primary_message_HV_CURRENT* message
);
void primary_deserialize_HV_CURRENT(
    primary_message_HV_CURRENT* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
void primary_raw_to_conversion_struct_HV_CURRENT(
    primary_message_HV_CURRENT_conversion* conversion,
    primary_message_HV_CURRENT* raw
);

void primary_conversion_to_raw_struct_HV_CURRENT(
    primary_message_HV_CURRENT* raw,
    primary_message_HV_CURRENT_conversion* conversion
);

void primary_conversion_to_raw_HV_CURRENT(
    primary_message_HV_CURRENT* raw,
    primary_float32 current,
    primary_float32 power,
    primary_float32 energy,
    primary_float32 soc
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
);

void primary_raw_to_conversion_HV_CURRENT(
    primary_message_HV_CURRENT_conversion* conversion,
    primary_uint16 current,
    primary_uint16 power,
    primary_uint16 energy,
    primary_uint8 soc
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_HV_CURRENT(primary_message_HV_CURRENT_conversion* message, char* buffer);
int primary_fields_HV_CURRENT(char* buffer);
int primary_to_string_file_HV_CURRENT(primary_message_HV_CURRENT_conversion* message, FILE* buffer);
int primary_fields_file_HV_CURRENT(FILE* buffer);


// ============== HV_TEMP ============== //

primary_byte_size primary_serialize_HV_TEMP(
    uint8_t* data,
    primary_uint8 average_temp,
    primary_uint8 max_temp,
    primary_uint8 min_temp
);
primary_byte_size primary_serialize_struct_HV_TEMP(
    uint8_t* data,
    primary_message_HV_TEMP* message
);
void primary_deserialize_HV_TEMP(
    primary_message_HV_TEMP* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
void primary_raw_to_conversion_struct_HV_TEMP(
    primary_message_HV_TEMP_conversion* conversion,
    primary_message_HV_TEMP* raw
);

void primary_conversion_to_raw_struct_HV_TEMP(
    primary_message_HV_TEMP* raw,
    primary_message_HV_TEMP_conversion* conversion
);

void primary_conversion_to_raw_HV_TEMP(
    primary_message_HV_TEMP* raw,
    primary_float32 average_temp,
    primary_float32 max_temp,
    primary_float32 min_temp
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
);

void primary_raw_to_conversion_HV_TEMP(
    primary_message_HV_TEMP_conversion* conversion,
    primary_uint8 average_temp,
    primary_uint8 max_temp,
    primary_uint8 min_temp
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_HV_TEMP(primary_message_HV_TEMP_conversion* message, char* buffer);
int primary_fields_HV_TEMP(char* buffer);
int primary_to_string_file_HV_TEMP(primary_message_HV_TEMP_conversion* message, FILE* buffer);
int primary_fields_file_HV_TEMP(FILE* buffer);


// ============== HV_ERRORS ============== //

primary_byte_size primary_serialize_HV_ERRORS(
    uint8_t* data,
    primary_HvErrors warnings,
    primary_HvErrors errors
);
primary_byte_size primary_serialize_struct_HV_ERRORS(
    uint8_t* data,
    primary_message_HV_ERRORS* message
);
void primary_deserialize_HV_ERRORS(
    primary_message_HV_ERRORS* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_HV_ERRORS(primary_message_HV_ERRORS* message, char* buffer);
int primary_fields_HV_ERRORS(char* buffer);
int primary_to_string_file_HV_ERRORS(primary_message_HV_ERRORS* message, FILE* buffer);
int primary_fields_file_HV_ERRORS(FILE* buffer);


// ============== HV_CAN_FORWARD ============== //

primary_byte_size primary_serialize_HV_CAN_FORWARD(
    uint8_t* data,
    primary_Toggle can_forward_set
);
primary_byte_size primary_serialize_struct_HV_CAN_FORWARD(
    uint8_t* data,
    primary_message_HV_CAN_FORWARD* message
);
void primary_deserialize_HV_CAN_FORWARD(
    primary_message_HV_CAN_FORWARD* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_HV_CAN_FORWARD(primary_message_HV_CAN_FORWARD* message, char* buffer);
int primary_fields_HV_CAN_FORWARD(char* buffer);
int primary_to_string_file_HV_CAN_FORWARD(primary_message_HV_CAN_FORWARD* message, FILE* buffer);
int primary_fields_file_HV_CAN_FORWARD(FILE* buffer);


// ============== HV_FANS_OVERRIDE ============== //

primary_byte_size primary_serialize_HV_FANS_OVERRIDE(
    uint8_t* data,
    primary_Toggle fans_override,
    primary_uint16 fans_speed
);
primary_byte_size primary_serialize_struct_HV_FANS_OVERRIDE(
    uint8_t* data,
    primary_message_HV_FANS_OVERRIDE* message
);
void primary_deserialize_HV_FANS_OVERRIDE(
    primary_message_HV_FANS_OVERRIDE* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
void primary_raw_to_conversion_struct_HV_FANS_OVERRIDE(
    primary_message_HV_FANS_OVERRIDE_conversion* conversion,
    primary_message_HV_FANS_OVERRIDE* raw
);

void primary_conversion_to_raw_struct_HV_FANS_OVERRIDE(
    primary_message_HV_FANS_OVERRIDE* raw,
    primary_message_HV_FANS_OVERRIDE_conversion* conversion
);

void primary_conversion_to_raw_HV_FANS_OVERRIDE(
    primary_message_HV_FANS_OVERRIDE* raw,
    primary_Toggle fans_override,
    primary_float32 fans_speed
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
);

void primary_raw_to_conversion_HV_FANS_OVERRIDE(
    primary_message_HV_FANS_OVERRIDE_conversion* conversion,
    primary_Toggle fans_override,
    primary_uint16 fans_speed
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_HV_FANS_OVERRIDE(primary_message_HV_FANS_OVERRIDE_conversion* message, char* buffer);
int primary_fields_HV_FANS_OVERRIDE(char* buffer);
int primary_to_string_file_HV_FANS_OVERRIDE(primary_message_HV_FANS_OVERRIDE_conversion* message, FILE* buffer);
int primary_fields_file_HV_FANS_OVERRIDE(FILE* buffer);


// ============== HV_CAN_FORWARD_STATUS ============== //

primary_byte_size primary_serialize_HV_CAN_FORWARD_STATUS(
    uint8_t* data,
    primary_Toggle can_forward_status
);
primary_byte_size primary_serialize_struct_HV_CAN_FORWARD_STATUS(
    uint8_t* data,
    primary_message_HV_CAN_FORWARD_STATUS* message
);
void primary_deserialize_HV_CAN_FORWARD_STATUS(
    primary_message_HV_CAN_FORWARD_STATUS* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_HV_CAN_FORWARD_STATUS(primary_message_HV_CAN_FORWARD_STATUS* message, char* buffer);
int primary_fields_HV_CAN_FORWARD_STATUS(char* buffer);
int primary_to_string_file_HV_CAN_FORWARD_STATUS(primary_message_HV_CAN_FORWARD_STATUS* message, FILE* buffer);
int primary_fields_file_HV_CAN_FORWARD_STATUS(FILE* buffer);


// ============== HV_FANS_OVERRIDE_STATUS ============== //

primary_byte_size primary_serialize_HV_FANS_OVERRIDE_STATUS(
    uint8_t* data,
    primary_Toggle fans_override,
    primary_uint16 fans_speed
);
primary_byte_size primary_serialize_struct_HV_FANS_OVERRIDE_STATUS(
    uint8_t* data,
    primary_message_HV_FANS_OVERRIDE_STATUS* message
);
void primary_deserialize_HV_FANS_OVERRIDE_STATUS(
    primary_message_HV_FANS_OVERRIDE_STATUS* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
void primary_raw_to_conversion_struct_HV_FANS_OVERRIDE_STATUS(
    primary_message_HV_FANS_OVERRIDE_STATUS_conversion* conversion,
    primary_message_HV_FANS_OVERRIDE_STATUS* raw
);

void primary_conversion_to_raw_struct_HV_FANS_OVERRIDE_STATUS(
    primary_message_HV_FANS_OVERRIDE_STATUS* raw,
    primary_message_HV_FANS_OVERRIDE_STATUS_conversion* conversion
);

void primary_conversion_to_raw_HV_FANS_OVERRIDE_STATUS(
    primary_message_HV_FANS_OVERRIDE_STATUS* raw,
    primary_Toggle fans_override,
    primary_float32 fans_speed
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
);

void primary_raw_to_conversion_HV_FANS_OVERRIDE_STATUS(
    primary_message_HV_FANS_OVERRIDE_STATUS_conversion* conversion,
    primary_Toggle fans_override,
    primary_uint16 fans_speed
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_HV_FANS_OVERRIDE_STATUS(primary_message_HV_FANS_OVERRIDE_STATUS_conversion* message, char* buffer);
int primary_fields_HV_FANS_OVERRIDE_STATUS(char* buffer);
int primary_to_string_file_HV_FANS_OVERRIDE_STATUS(primary_message_HV_FANS_OVERRIDE_STATUS_conversion* message, FILE* buffer);
int primary_fields_file_HV_FANS_OVERRIDE_STATUS(FILE* buffer);


// ============== HV_FEEDBACKS_STATUS ============== //

primary_byte_size primary_serialize_HV_FEEDBACKS_STATUS(
    uint8_t* data,
    primary_HvFeedbacks feedbacks_status,
    primary_HvFeedbacks is_circuitry_error
);
primary_byte_size primary_serialize_struct_HV_FEEDBACKS_STATUS(
    uint8_t* data,
    primary_message_HV_FEEDBACKS_STATUS* message
);
void primary_deserialize_HV_FEEDBACKS_STATUS(
    primary_message_HV_FEEDBACKS_STATUS* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_HV_FEEDBACKS_STATUS(primary_message_HV_FEEDBACKS_STATUS* message, char* buffer);
int primary_fields_HV_FEEDBACKS_STATUS(char* buffer);
int primary_to_string_file_HV_FEEDBACKS_STATUS(primary_message_HV_FEEDBACKS_STATUS* message, FILE* buffer);
int primary_fields_file_HV_FEEDBACKS_STATUS(FILE* buffer);


// ============== HV_IMD_STATUS ============== //

primary_byte_size primary_serialize_HV_IMD_STATUS(
    uint8_t* data,
    primary_bool imd_fault,
    primary_ImdStatus imd_status,
    primary_int32 imd_info
);
primary_byte_size primary_serialize_struct_HV_IMD_STATUS(
    uint8_t* data,
    primary_message_HV_IMD_STATUS* message
);
void primary_deserialize_HV_IMD_STATUS(
    primary_message_HV_IMD_STATUS* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_HV_IMD_STATUS(primary_message_HV_IMD_STATUS* message, char* buffer);
int primary_fields_HV_IMD_STATUS(char* buffer);
int primary_to_string_file_HV_IMD_STATUS(primary_message_HV_IMD_STATUS* message, FILE* buffer);
int primary_fields_file_HV_IMD_STATUS(FILE* buffer);


// ============== TS_STATUS ============== //

primary_byte_size primary_serialize_TS_STATUS(
    uint8_t* data,
    primary_TsStatus ts_status
);
primary_byte_size primary_serialize_struct_TS_STATUS(
    uint8_t* data,
    primary_message_TS_STATUS* message
);
void primary_deserialize_TS_STATUS(
    primary_message_TS_STATUS* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_TS_STATUS(primary_message_TS_STATUS* message, char* buffer);
int primary_fields_TS_STATUS(char* buffer);
int primary_to_string_file_TS_STATUS(primary_message_TS_STATUS* message, FILE* buffer);
int primary_fields_file_TS_STATUS(FILE* buffer);


// ============== SET_TS_STATUS ============== //

primary_byte_size primary_serialize_SET_TS_STATUS(
    uint8_t* data,
    primary_Toggle ts_status_set
);
primary_byte_size primary_serialize_struct_SET_TS_STATUS(
    uint8_t* data,
    primary_message_SET_TS_STATUS* message
);
void primary_deserialize_SET_TS_STATUS(
    primary_message_SET_TS_STATUS* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_SET_TS_STATUS(primary_message_SET_TS_STATUS* message, char* buffer);
int primary_fields_SET_TS_STATUS(char* buffer);
int primary_to_string_file_SET_TS_STATUS(primary_message_SET_TS_STATUS* message, FILE* buffer);
int primary_fields_file_SET_TS_STATUS(FILE* buffer);


// ============== STEER_STATUS ============== //

primary_byte_size primary_serialize_STEER_STATUS(
    uint8_t* data,
    primary_TractionControl traction_control,
    primary_Map map
);
primary_byte_size primary_serialize_struct_STEER_STATUS(
    uint8_t* data,
    primary_message_STEER_STATUS* message
);
void primary_deserialize_STEER_STATUS(
    primary_message_STEER_STATUS* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_STEER_STATUS(primary_message_STEER_STATUS* message, char* buffer);
int primary_fields_STEER_STATUS(char* buffer);
int primary_to_string_file_STEER_STATUS(primary_message_STEER_STATUS* message, FILE* buffer);
int primary_fields_file_STEER_STATUS(FILE* buffer);


// ============== SET_CAR_STATUS ============== //

primary_byte_size primary_serialize_SET_CAR_STATUS(
    uint8_t* data,
    primary_SetCarStatus car_status_set
);
primary_byte_size primary_serialize_struct_SET_CAR_STATUS(
    uint8_t* data,
    primary_message_SET_CAR_STATUS* message
);
void primary_deserialize_SET_CAR_STATUS(
    primary_message_SET_CAR_STATUS* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_SET_CAR_STATUS(primary_message_SET_CAR_STATUS* message, char* buffer);
int primary_fields_SET_CAR_STATUS(char* buffer);
int primary_to_string_file_SET_CAR_STATUS(primary_message_SET_CAR_STATUS* message, FILE* buffer);
int primary_fields_file_SET_CAR_STATUS(FILE* buffer);


// ============== SET_PEDALS_RANGE ============== //

primary_byte_size primary_serialize_SET_PEDALS_RANGE(
    uint8_t* data,
    primary_Bound bound,
    primary_Pedal pedal
);
primary_byte_size primary_serialize_struct_SET_PEDALS_RANGE(
    uint8_t* data,
    primary_message_SET_PEDALS_RANGE* message
);
void primary_deserialize_SET_PEDALS_RANGE(
    primary_message_SET_PEDALS_RANGE* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_SET_PEDALS_RANGE(primary_message_SET_PEDALS_RANGE* message, char* buffer);
int primary_fields_SET_PEDALS_RANGE(char* buffer);
int primary_to_string_file_SET_PEDALS_RANGE(primary_message_SET_PEDALS_RANGE* message, FILE* buffer);
int primary_fields_file_SET_PEDALS_RANGE(FILE* buffer);


// ============== SET_STEERING_ANGLE_RANGE ============== //

primary_byte_size primary_serialize_SET_STEERING_ANGLE_RANGE(
    uint8_t* data,
    primary_Bound bound
);
primary_byte_size primary_serialize_struct_SET_STEERING_ANGLE_RANGE(
    uint8_t* data,
    primary_message_SET_STEERING_ANGLE_RANGE* message
);
void primary_deserialize_SET_STEERING_ANGLE_RANGE(
    primary_message_SET_STEERING_ANGLE_RANGE* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_SET_STEERING_ANGLE_RANGE(primary_message_SET_STEERING_ANGLE_RANGE* message, char* buffer);
int primary_fields_SET_STEERING_ANGLE_RANGE(char* buffer);
int primary_to_string_file_SET_STEERING_ANGLE_RANGE(primary_message_SET_STEERING_ANGLE_RANGE* message, FILE* buffer);
int primary_fields_file_SET_STEERING_ANGLE_RANGE(FILE* buffer);


// ============== CAR_STATUS ============== //

primary_byte_size primary_serialize_CAR_STATUS(
    uint8_t* data,
    primary_InverterStatus inverter_l,
    primary_InverterStatus inverter_r,
    primary_CarStatus car_status
);
primary_byte_size primary_serialize_struct_CAR_STATUS(
    uint8_t* data,
    primary_message_CAR_STATUS* message
);
void primary_deserialize_CAR_STATUS(
    primary_message_CAR_STATUS* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_CAR_STATUS(primary_message_CAR_STATUS* message, char* buffer);
int primary_fields_CAR_STATUS(char* buffer);
int primary_to_string_file_CAR_STATUS(primary_message_CAR_STATUS* message, FILE* buffer);
int primary_fields_file_CAR_STATUS(FILE* buffer);


// ============== DAS_ERRORS ============== //

primary_byte_size primary_serialize_DAS_ERRORS(
    uint8_t* data,
    primary_DasErrors das_error
);
primary_byte_size primary_serialize_struct_DAS_ERRORS(
    uint8_t* data,
    primary_message_DAS_ERRORS* message
);
void primary_deserialize_DAS_ERRORS(
    primary_message_DAS_ERRORS* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_DAS_ERRORS(primary_message_DAS_ERRORS* message, char* buffer);
int primary_fields_DAS_ERRORS(char* buffer);
int primary_to_string_file_DAS_ERRORS(primary_message_DAS_ERRORS* message, FILE* buffer);
int primary_fields_file_DAS_ERRORS(FILE* buffer);


// ============== LV_CURRENT ============== //

primary_byte_size primary_serialize_LV_CURRENT(
    uint8_t* data,
    primary_uint16 current
);
primary_byte_size primary_serialize_struct_LV_CURRENT(
    uint8_t* data,
    primary_message_LV_CURRENT* message
);
void primary_deserialize_LV_CURRENT(
    primary_message_LV_CURRENT* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
void primary_raw_to_conversion_struct_LV_CURRENT(
    primary_message_LV_CURRENT_conversion* conversion,
    primary_message_LV_CURRENT* raw
);

void primary_conversion_to_raw_struct_LV_CURRENT(
    primary_message_LV_CURRENT* raw,
    primary_message_LV_CURRENT_conversion* conversion
);

void primary_conversion_to_raw_LV_CURRENT(
    primary_message_LV_CURRENT* raw,
    primary_float32 current
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
);

void primary_raw_to_conversion_LV_CURRENT(
    primary_message_LV_CURRENT_conversion* conversion,
    primary_uint16 current
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_LV_CURRENT(primary_message_LV_CURRENT_conversion* message, char* buffer);
int primary_fields_LV_CURRENT(char* buffer);
int primary_to_string_file_LV_CURRENT(primary_message_LV_CURRENT_conversion* message, FILE* buffer);
int primary_fields_file_LV_CURRENT(FILE* buffer);


// ============== LV_VOLTAGE ============== //

primary_byte_size primary_serialize_LV_VOLTAGE(
    uint8_t* data,
    primary_uint16 voltage_1,
    primary_uint16 voltage_2,
    primary_uint16 voltage_3,
    primary_uint16 voltage_4
);
primary_byte_size primary_serialize_struct_LV_VOLTAGE(
    uint8_t* data,
    primary_message_LV_VOLTAGE* message
);
void primary_deserialize_LV_VOLTAGE(
    primary_message_LV_VOLTAGE* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
void primary_raw_to_conversion_struct_LV_VOLTAGE(
    primary_message_LV_VOLTAGE_conversion* conversion,
    primary_message_LV_VOLTAGE* raw
);

void primary_conversion_to_raw_struct_LV_VOLTAGE(
    primary_message_LV_VOLTAGE* raw,
    primary_message_LV_VOLTAGE_conversion* conversion
);

void primary_conversion_to_raw_LV_VOLTAGE(
    primary_message_LV_VOLTAGE* raw,
    primary_float32 voltage_1,
    primary_float32 voltage_2,
    primary_float32 voltage_3,
    primary_float32 voltage_4
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
);

void primary_raw_to_conversion_LV_VOLTAGE(
    primary_message_LV_VOLTAGE_conversion* conversion,
    primary_uint16 voltage_1,
    primary_uint16 voltage_2,
    primary_uint16 voltage_3,
    primary_uint16 voltage_4
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_LV_VOLTAGE(primary_message_LV_VOLTAGE_conversion* message, char* buffer);
int primary_fields_LV_VOLTAGE(char* buffer);
int primary_to_string_file_LV_VOLTAGE(primary_message_LV_VOLTAGE_conversion* message, FILE* buffer);
int primary_fields_file_LV_VOLTAGE(FILE* buffer);


// ============== LV_TOTAL_VOLTAGE ============== //

primary_byte_size primary_serialize_LV_TOTAL_VOLTAGE(
    uint8_t* data,
    primary_uint32 total_voltage
);
primary_byte_size primary_serialize_struct_LV_TOTAL_VOLTAGE(
    uint8_t* data,
    primary_message_LV_TOTAL_VOLTAGE* message
);
void primary_deserialize_LV_TOTAL_VOLTAGE(
    primary_message_LV_TOTAL_VOLTAGE* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
void primary_raw_to_conversion_struct_LV_TOTAL_VOLTAGE(
    primary_message_LV_TOTAL_VOLTAGE_conversion* conversion,
    primary_message_LV_TOTAL_VOLTAGE* raw
);

void primary_conversion_to_raw_struct_LV_TOTAL_VOLTAGE(
    primary_message_LV_TOTAL_VOLTAGE* raw,
    primary_message_LV_TOTAL_VOLTAGE_conversion* conversion
);

void primary_conversion_to_raw_LV_TOTAL_VOLTAGE(
    primary_message_LV_TOTAL_VOLTAGE* raw,
    primary_float32 total_voltage
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
);

void primary_raw_to_conversion_LV_TOTAL_VOLTAGE(
    primary_message_LV_TOTAL_VOLTAGE_conversion* conversion,
    primary_uint32 total_voltage
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_LV_TOTAL_VOLTAGE(primary_message_LV_TOTAL_VOLTAGE_conversion* message, char* buffer);
int primary_fields_LV_TOTAL_VOLTAGE(char* buffer);
int primary_to_string_file_LV_TOTAL_VOLTAGE(primary_message_LV_TOTAL_VOLTAGE_conversion* message, FILE* buffer);
int primary_fields_file_LV_TOTAL_VOLTAGE(FILE* buffer);


// ============== LV_TEMPERATURE ============== //

primary_byte_size primary_serialize_LV_TEMPERATURE(
    uint8_t* data,
    primary_uint16 bp_temperature_1,
    primary_uint16 bp_temperature_2,
    primary_uint16 dcdc12_temperature,
    primary_uint16 dcdc24_temperature
);
primary_byte_size primary_serialize_struct_LV_TEMPERATURE(
    uint8_t* data,
    primary_message_LV_TEMPERATURE* message
);
void primary_deserialize_LV_TEMPERATURE(
    primary_message_LV_TEMPERATURE* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
void primary_raw_to_conversion_struct_LV_TEMPERATURE(
    primary_message_LV_TEMPERATURE_conversion* conversion,
    primary_message_LV_TEMPERATURE* raw
);

void primary_conversion_to_raw_struct_LV_TEMPERATURE(
    primary_message_LV_TEMPERATURE* raw,
    primary_message_LV_TEMPERATURE_conversion* conversion
);

void primary_conversion_to_raw_LV_TEMPERATURE(
    primary_message_LV_TEMPERATURE* raw,
    primary_float32 bp_temperature_1,
    primary_float32 bp_temperature_2,
    primary_float32 dcdc12_temperature,
    primary_float32 dcdc24_temperature
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
);

void primary_raw_to_conversion_LV_TEMPERATURE(
    primary_message_LV_TEMPERATURE_conversion* conversion,
    primary_uint16 bp_temperature_1,
    primary_uint16 bp_temperature_2,
    primary_uint16 dcdc12_temperature,
    primary_uint16 dcdc24_temperature
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_LV_TEMPERATURE(primary_message_LV_TEMPERATURE_conversion* message, char* buffer);
int primary_fields_LV_TEMPERATURE(char* buffer);
int primary_to_string_file_LV_TEMPERATURE(primary_message_LV_TEMPERATURE_conversion* message, FILE* buffer);
int primary_fields_file_LV_TEMPERATURE(FILE* buffer);


// ============== COOLING_STATUS ============== //

primary_byte_size primary_serialize_COOLING_STATUS(
    uint8_t* data,
    primary_uint16 radiators_speed,
    primary_uint16 pumps_speed
);
primary_byte_size primary_serialize_struct_COOLING_STATUS(
    uint8_t* data,
    primary_message_COOLING_STATUS* message
);
void primary_deserialize_COOLING_STATUS(
    primary_message_COOLING_STATUS* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
void primary_raw_to_conversion_struct_COOLING_STATUS(
    primary_message_COOLING_STATUS_conversion* conversion,
    primary_message_COOLING_STATUS* raw
);

void primary_conversion_to_raw_struct_COOLING_STATUS(
    primary_message_COOLING_STATUS* raw,
    primary_message_COOLING_STATUS_conversion* conversion
);

void primary_conversion_to_raw_COOLING_STATUS(
    primary_message_COOLING_STATUS* raw,
    primary_float32 radiators_speed,
    primary_float32 pumps_speed
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
);

void primary_raw_to_conversion_COOLING_STATUS(
    primary_message_COOLING_STATUS_conversion* conversion,
    primary_uint16 radiators_speed,
    primary_uint16 pumps_speed
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_COOLING_STATUS(primary_message_COOLING_STATUS_conversion* message, char* buffer);
int primary_fields_COOLING_STATUS(char* buffer);
int primary_to_string_file_COOLING_STATUS(primary_message_COOLING_STATUS_conversion* message, FILE* buffer);
int primary_fields_file_COOLING_STATUS(FILE* buffer);


// ============== SET_RADIATOR_SPEED ============== //

primary_byte_size primary_serialize_SET_RADIATOR_SPEED(
    uint8_t* data,
    primary_uint16 radiators_speed
);
primary_byte_size primary_serialize_struct_SET_RADIATOR_SPEED(
    uint8_t* data,
    primary_message_SET_RADIATOR_SPEED* message
);
void primary_deserialize_SET_RADIATOR_SPEED(
    primary_message_SET_RADIATOR_SPEED* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
void primary_raw_to_conversion_struct_SET_RADIATOR_SPEED(
    primary_message_SET_RADIATOR_SPEED_conversion* conversion,
    primary_message_SET_RADIATOR_SPEED* raw
);

void primary_conversion_to_raw_struct_SET_RADIATOR_SPEED(
    primary_message_SET_RADIATOR_SPEED* raw,
    primary_message_SET_RADIATOR_SPEED_conversion* conversion
);

void primary_conversion_to_raw_SET_RADIATOR_SPEED(
    primary_message_SET_RADIATOR_SPEED* raw,
    primary_float32 radiators_speed
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
);

void primary_raw_to_conversion_SET_RADIATOR_SPEED(
    primary_message_SET_RADIATOR_SPEED_conversion* conversion,
    primary_uint16 radiators_speed
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_SET_RADIATOR_SPEED(primary_message_SET_RADIATOR_SPEED_conversion* message, char* buffer);
int primary_fields_SET_RADIATOR_SPEED(char* buffer);
int primary_to_string_file_SET_RADIATOR_SPEED(primary_message_SET_RADIATOR_SPEED_conversion* message, FILE* buffer);
int primary_fields_file_SET_RADIATOR_SPEED(FILE* buffer);


// ============== SET_PUMPS_SPEED ============== //

primary_byte_size primary_serialize_SET_PUMPS_SPEED(
    uint8_t* data,
    primary_uint16 pumps_speed
);
primary_byte_size primary_serialize_struct_SET_PUMPS_SPEED(
    uint8_t* data,
    primary_message_SET_PUMPS_SPEED* message
);
void primary_deserialize_SET_PUMPS_SPEED(
    primary_message_SET_PUMPS_SPEED* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
void primary_raw_to_conversion_struct_SET_PUMPS_SPEED(
    primary_message_SET_PUMPS_SPEED_conversion* conversion,
    primary_message_SET_PUMPS_SPEED* raw
);

void primary_conversion_to_raw_struct_SET_PUMPS_SPEED(
    primary_message_SET_PUMPS_SPEED* raw,
    primary_message_SET_PUMPS_SPEED_conversion* conversion
);

void primary_conversion_to_raw_SET_PUMPS_SPEED(
    primary_message_SET_PUMPS_SPEED* raw,
    primary_float32 pumps_speed
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
);

void primary_raw_to_conversion_SET_PUMPS_SPEED(
    primary_message_SET_PUMPS_SPEED_conversion* conversion,
    primary_uint16 pumps_speed
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_SET_PUMPS_SPEED(primary_message_SET_PUMPS_SPEED_conversion* message, char* buffer);
int primary_fields_SET_PUMPS_SPEED(char* buffer);
int primary_to_string_file_SET_PUMPS_SPEED(primary_message_SET_PUMPS_SPEED_conversion* message, FILE* buffer);
int primary_fields_file_SET_PUMPS_SPEED(FILE* buffer);


// ============== SET_INVERTER_CONNECTION_STATUS ============== //

primary_byte_size primary_serialize_SET_INVERTER_CONNECTION_STATUS(
    uint8_t* data,
    primary_Toggle status
);
primary_byte_size primary_serialize_struct_SET_INVERTER_CONNECTION_STATUS(
    uint8_t* data,
    primary_message_SET_INVERTER_CONNECTION_STATUS* message
);
void primary_deserialize_SET_INVERTER_CONNECTION_STATUS(
    primary_message_SET_INVERTER_CONNECTION_STATUS* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_SET_INVERTER_CONNECTION_STATUS(primary_message_SET_INVERTER_CONNECTION_STATUS* message, char* buffer);
int primary_fields_SET_INVERTER_CONNECTION_STATUS(char* buffer);
int primary_to_string_file_SET_INVERTER_CONNECTION_STATUS(primary_message_SET_INVERTER_CONNECTION_STATUS* message, FILE* buffer);
int primary_fields_file_SET_INVERTER_CONNECTION_STATUS(FILE* buffer);


// ============== INVERTER_CONNECTION_STATUS ============== //

primary_byte_size primary_serialize_INVERTER_CONNECTION_STATUS(
    uint8_t* data,
    primary_Toggle status
);
primary_byte_size primary_serialize_struct_INVERTER_CONNECTION_STATUS(
    uint8_t* data,
    primary_message_INVERTER_CONNECTION_STATUS* message
);
void primary_deserialize_INVERTER_CONNECTION_STATUS(
    primary_message_INVERTER_CONNECTION_STATUS* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_INVERTER_CONNECTION_STATUS(primary_message_INVERTER_CONNECTION_STATUS* message, char* buffer);
int primary_fields_INVERTER_CONNECTION_STATUS(char* buffer);
int primary_to_string_file_INVERTER_CONNECTION_STATUS(primary_message_INVERTER_CONNECTION_STATUS* message, FILE* buffer);
int primary_fields_file_INVERTER_CONNECTION_STATUS(FILE* buffer);


// ============== LV_ERRORS ============== //

primary_byte_size primary_serialize_LV_ERRORS(
    uint8_t* data,
    primary_LvErrors warnings,
    primary_LvErrors errors
);
primary_byte_size primary_serialize_struct_LV_ERRORS(
    uint8_t* data,
    primary_message_LV_ERRORS* message
);
void primary_deserialize_LV_ERRORS(
    primary_message_LV_ERRORS* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_LV_ERRORS(primary_message_LV_ERRORS* message, char* buffer);
int primary_fields_LV_ERRORS(char* buffer);
int primary_to_string_file_LV_ERRORS(primary_message_LV_ERRORS* message, FILE* buffer);
int primary_fields_file_LV_ERRORS(FILE* buffer);


// ============== SHUTDOWN_STATUS ============== //

primary_byte_size primary_serialize_SHUTDOWN_STATUS(
    uint8_t* data,
    primary_bool input,
    primary_bool output
);
primary_byte_size primary_serialize_struct_SHUTDOWN_STATUS(
    uint8_t* data,
    primary_message_SHUTDOWN_STATUS* message
);
void primary_deserialize_SHUTDOWN_STATUS(
    primary_message_SHUTDOWN_STATUS* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_SHUTDOWN_STATUS(primary_message_SHUTDOWN_STATUS* message, char* buffer);
int primary_fields_SHUTDOWN_STATUS(char* buffer);
int primary_to_string_file_SHUTDOWN_STATUS(primary_message_SHUTDOWN_STATUS* message, FILE* buffer);
int primary_fields_file_SHUTDOWN_STATUS(FILE* buffer);


// ============== MARKER ============== //

primary_byte_size primary_serialize_MARKER(
    uint8_t* data
);
primary_byte_size primary_serialize_struct_MARKER(
    uint8_t* data,
    primary_message_MARKER* message
);
void primary_deserialize_MARKER(
    primary_message_MARKER* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_MARKER(primary_message_MARKER* message, char* buffer);
int primary_fields_MARKER(char* buffer);
int primary_to_string_file_MARKER(primary_message_MARKER* message, FILE* buffer);
int primary_fields_file_MARKER(FILE* buffer);


// ============== HV_CELLS_VOLTAGE ============== //

primary_byte_size primary_serialize_HV_CELLS_VOLTAGE(
    uint8_t* data,
    primary_uint8 start_index,
    primary_uint16 voltage_0,
    primary_uint16 voltage_1,
    primary_uint16 voltage_2
);
primary_byte_size primary_serialize_struct_HV_CELLS_VOLTAGE(
    uint8_t* data,
    primary_message_HV_CELLS_VOLTAGE* message
);
void primary_deserialize_HV_CELLS_VOLTAGE(
    primary_message_HV_CELLS_VOLTAGE* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
void primary_raw_to_conversion_struct_HV_CELLS_VOLTAGE(
    primary_message_HV_CELLS_VOLTAGE_conversion* conversion,
    primary_message_HV_CELLS_VOLTAGE* raw
);

void primary_conversion_to_raw_struct_HV_CELLS_VOLTAGE(
    primary_message_HV_CELLS_VOLTAGE* raw,
    primary_message_HV_CELLS_VOLTAGE_conversion* conversion
);

void primary_conversion_to_raw_HV_CELLS_VOLTAGE(
    primary_message_HV_CELLS_VOLTAGE* raw,
    primary_uint8 start_index,
    primary_float32 voltage_0,
    primary_float32 voltage_1,
    primary_float32 voltage_2
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
);

void primary_raw_to_conversion_HV_CELLS_VOLTAGE(
    primary_message_HV_CELLS_VOLTAGE_conversion* conversion,
    primary_uint8 start_index,
    primary_uint16 voltage_0,
    primary_uint16 voltage_1,
    primary_uint16 voltage_2
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_HV_CELLS_VOLTAGE(primary_message_HV_CELLS_VOLTAGE_conversion* message, char* buffer);
int primary_fields_HV_CELLS_VOLTAGE(char* buffer);
int primary_to_string_file_HV_CELLS_VOLTAGE(primary_message_HV_CELLS_VOLTAGE_conversion* message, FILE* buffer);
int primary_fields_file_HV_CELLS_VOLTAGE(FILE* buffer);


// ============== HV_CELLS_TEMP ============== //

primary_byte_size primary_serialize_HV_CELLS_TEMP(
    uint8_t* data,
    primary_uint8 start_index,
    primary_uint8 temp_0,
    primary_uint8 temp_1,
    primary_uint8 temp_2,
    primary_uint8 temp_3,
    primary_uint8 temp_4,
    primary_uint8 temp_5
);
primary_byte_size primary_serialize_struct_HV_CELLS_TEMP(
    uint8_t* data,
    primary_message_HV_CELLS_TEMP* message
);
void primary_deserialize_HV_CELLS_TEMP(
    primary_message_HV_CELLS_TEMP* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
void primary_raw_to_conversion_struct_HV_CELLS_TEMP(
    primary_message_HV_CELLS_TEMP_conversion* conversion,
    primary_message_HV_CELLS_TEMP* raw
);

void primary_conversion_to_raw_struct_HV_CELLS_TEMP(
    primary_message_HV_CELLS_TEMP* raw,
    primary_message_HV_CELLS_TEMP_conversion* conversion
);

void primary_conversion_to_raw_HV_CELLS_TEMP(
    primary_message_HV_CELLS_TEMP* raw,
    primary_uint8 start_index,
    primary_float32 temp_0,
    primary_float32 temp_1,
    primary_float32 temp_2,
    primary_float32 temp_3,
    primary_float32 temp_4,
    primary_float32 temp_5
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
);

void primary_raw_to_conversion_HV_CELLS_TEMP(
    primary_message_HV_CELLS_TEMP_conversion* conversion,
    primary_uint8 start_index,
    primary_uint8 temp_0,
    primary_uint8 temp_1,
    primary_uint8 temp_2,
    primary_uint8 temp_3,
    primary_uint8 temp_4,
    primary_uint8 temp_5
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_HV_CELLS_TEMP(primary_message_HV_CELLS_TEMP_conversion* message, char* buffer);
int primary_fields_HV_CELLS_TEMP(char* buffer);
int primary_to_string_file_HV_CELLS_TEMP(primary_message_HV_CELLS_TEMP_conversion* message, FILE* buffer);
int primary_fields_file_HV_CELLS_TEMP(FILE* buffer);


// ============== HV_CELL_BALANCING_STATUS ============== //

primary_byte_size primary_serialize_HV_CELL_BALANCING_STATUS(
    uint8_t* data,
    primary_Toggle balancing_status
);
primary_byte_size primary_serialize_struct_HV_CELL_BALANCING_STATUS(
    uint8_t* data,
    primary_message_HV_CELL_BALANCING_STATUS* message
);
void primary_deserialize_HV_CELL_BALANCING_STATUS(
    primary_message_HV_CELL_BALANCING_STATUS* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_HV_CELL_BALANCING_STATUS(primary_message_HV_CELL_BALANCING_STATUS* message, char* buffer);
int primary_fields_HV_CELL_BALANCING_STATUS(char* buffer);
int primary_to_string_file_HV_CELL_BALANCING_STATUS(primary_message_HV_CELL_BALANCING_STATUS* message, FILE* buffer);
int primary_fields_file_HV_CELL_BALANCING_STATUS(FILE* buffer);


// ============== SET_CELL_BALANCING_STATUS ============== //

primary_byte_size primary_serialize_SET_CELL_BALANCING_STATUS(
    uint8_t* data,
    primary_Toggle set_balancing_status
);
primary_byte_size primary_serialize_struct_SET_CELL_BALANCING_STATUS(
    uint8_t* data,
    primary_message_SET_CELL_BALANCING_STATUS* message
);
void primary_deserialize_SET_CELL_BALANCING_STATUS(
    primary_message_SET_CELL_BALANCING_STATUS* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_SET_CELL_BALANCING_STATUS(primary_message_SET_CELL_BALANCING_STATUS* message, char* buffer);
int primary_fields_SET_CELL_BALANCING_STATUS(char* buffer);
int primary_to_string_file_SET_CELL_BALANCING_STATUS(primary_message_SET_CELL_BALANCING_STATUS* message, FILE* buffer);
int primary_fields_file_SET_CELL_BALANCING_STATUS(FILE* buffer);


// ============== HANDCART_STATUS ============== //

primary_byte_size primary_serialize_HANDCART_STATUS(
    uint8_t* data,
    primary_bool connected
);
primary_byte_size primary_serialize_struct_HANDCART_STATUS(
    uint8_t* data,
    primary_message_HANDCART_STATUS* message
);
void primary_deserialize_HANDCART_STATUS(
    primary_message_HANDCART_STATUS* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_HANDCART_STATUS(primary_message_HANDCART_STATUS* message, char* buffer);
int primary_fields_HANDCART_STATUS(char* buffer);
int primary_to_string_file_HANDCART_STATUS(primary_message_HANDCART_STATUS* message, FILE* buffer);
int primary_fields_file_HANDCART_STATUS(FILE* buffer);


// ============== SPEED ============== //

primary_byte_size primary_serialize_SPEED(
    uint8_t* data,
    primary_uint8 encoder_r,
    primary_uint8 encoder_l,
    primary_uint8 inverter_r,
    primary_uint8 inverter_l
);
primary_byte_size primary_serialize_struct_SPEED(
    uint8_t* data,
    primary_message_SPEED* message
);
void primary_deserialize_SPEED(
    primary_message_SPEED* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
void primary_raw_to_conversion_struct_SPEED(
    primary_message_SPEED_conversion* conversion,
    primary_message_SPEED* raw
);

void primary_conversion_to_raw_struct_SPEED(
    primary_message_SPEED* raw,
    primary_message_SPEED_conversion* conversion
);

void primary_conversion_to_raw_SPEED(
    primary_message_SPEED* raw,
    primary_float32 encoder_r,
    primary_float32 encoder_l,
    primary_float32 inverter_r,
    primary_float32 inverter_l
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
);

void primary_raw_to_conversion_SPEED(
    primary_message_SPEED_conversion* conversion,
    primary_uint8 encoder_r,
    primary_uint8 encoder_l,
    primary_uint8 inverter_r,
    primary_uint8 inverter_l
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_SPEED(primary_message_SPEED_conversion* message, char* buffer);
int primary_fields_SPEED(char* buffer);
int primary_to_string_file_SPEED(primary_message_SPEED_conversion* message, FILE* buffer);
int primary_fields_file_SPEED(FILE* buffer);


// ============== INV_L_REQUEST ============== //

primary_byte_size primary_serialize_INV_L_REQUEST(
    uint8_t* data,
    primary_uint8 data_0,
    primary_uint8 data_1,
    primary_uint8 data_2,
    primary_uint8 data_3,
    primary_uint8 data_4,
    primary_uint8 data_5,
    primary_uint8 data_6,
    primary_uint8 data_7
);
primary_byte_size primary_serialize_struct_INV_L_REQUEST(
    uint8_t* data,
    primary_message_INV_L_REQUEST* message
);
void primary_deserialize_INV_L_REQUEST(
    primary_message_INV_L_REQUEST* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_INV_L_REQUEST(primary_message_INV_L_REQUEST* message, char* buffer);
int primary_fields_INV_L_REQUEST(char* buffer);
int primary_to_string_file_INV_L_REQUEST(primary_message_INV_L_REQUEST* message, FILE* buffer);
int primary_fields_file_INV_L_REQUEST(FILE* buffer);


// ============== INV_R_REQUEST ============== //

primary_byte_size primary_serialize_INV_R_REQUEST(
    uint8_t* data,
    primary_uint8 data_0,
    primary_uint8 data_1,
    primary_uint8 data_2,
    primary_uint8 data_3,
    primary_uint8 data_4,
    primary_uint8 data_5,
    primary_uint8 data_6,
    primary_uint8 data_7
);
primary_byte_size primary_serialize_struct_INV_R_REQUEST(
    uint8_t* data,
    primary_message_INV_R_REQUEST* message
);
void primary_deserialize_INV_R_REQUEST(
    primary_message_INV_R_REQUEST* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_INV_R_REQUEST(primary_message_INV_R_REQUEST* message, char* buffer);
int primary_fields_INV_R_REQUEST(char* buffer);
int primary_to_string_file_INV_R_REQUEST(primary_message_INV_R_REQUEST* message, FILE* buffer);
int primary_fields_file_INV_R_REQUEST(FILE* buffer);


// ============== INV_L_RESPONSE ============== //

primary_byte_size primary_serialize_INV_L_RESPONSE(
    uint8_t* data,
    primary_uint8 reg_id,
    primary_uint8 data_0,
    primary_uint8 data_1,
    primary_uint8 data_2,
    primary_uint8 data_3,
    primary_uint8 data_4,
    primary_uint8 data_5,
    primary_uint8 data_6
);
primary_byte_size primary_serialize_struct_INV_L_RESPONSE(
    uint8_t* data,
    primary_message_INV_L_RESPONSE* message
);
void primary_deserialize_INV_L_RESPONSE(
    primary_message_INV_L_RESPONSE* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_INV_L_RESPONSE(primary_message_INV_L_RESPONSE* message, char* buffer);
int primary_fields_INV_L_RESPONSE(char* buffer);
int primary_to_string_file_INV_L_RESPONSE(primary_message_INV_L_RESPONSE* message, FILE* buffer);
int primary_fields_file_INV_L_RESPONSE(FILE* buffer);


// ============== INV_R_RESPONSE ============== //

primary_byte_size primary_serialize_INV_R_RESPONSE(
    uint8_t* data,
    primary_uint8 reg_id,
    primary_uint8 data_0,
    primary_uint8 data_1,
    primary_uint8 data_2,
    primary_uint8 data_3,
    primary_uint8 data_4,
    primary_uint8 data_5,
    primary_uint8 data_6
);
primary_byte_size primary_serialize_struct_INV_R_RESPONSE(
    uint8_t* data,
    primary_message_INV_R_RESPONSE* message
);
void primary_deserialize_INV_R_RESPONSE(
    primary_message_INV_R_RESPONSE* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_INV_R_RESPONSE(primary_message_INV_R_RESPONSE* message, char* buffer);
int primary_fields_INV_R_RESPONSE(char* buffer);
int primary_to_string_file_INV_R_RESPONSE(primary_message_INV_R_RESPONSE* message, FILE* buffer);
int primary_fields_file_INV_R_RESPONSE(FILE* buffer);


// ============== FLASH_CELLBOARD_0_TX ============== //

primary_byte_size primary_serialize_FLASH_CELLBOARD_0_TX(
    uint8_t* data
);
primary_byte_size primary_serialize_struct_FLASH_CELLBOARD_0_TX(
    uint8_t* data,
    primary_message_FLASH_CELLBOARD_0_TX* message
);
void primary_deserialize_FLASH_CELLBOARD_0_TX(
    primary_message_FLASH_CELLBOARD_0_TX* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_FLASH_CELLBOARD_0_TX(primary_message_FLASH_CELLBOARD_0_TX* message, char* buffer);
int primary_fields_FLASH_CELLBOARD_0_TX(char* buffer);
int primary_to_string_file_FLASH_CELLBOARD_0_TX(primary_message_FLASH_CELLBOARD_0_TX* message, FILE* buffer);
int primary_fields_file_FLASH_CELLBOARD_0_TX(FILE* buffer);


// ============== FLASH_CELLBOARD_0_RX ============== //

primary_byte_size primary_serialize_FLASH_CELLBOARD_0_RX(
    uint8_t* data
);
primary_byte_size primary_serialize_struct_FLASH_CELLBOARD_0_RX(
    uint8_t* data,
    primary_message_FLASH_CELLBOARD_0_RX* message
);
void primary_deserialize_FLASH_CELLBOARD_0_RX(
    primary_message_FLASH_CELLBOARD_0_RX* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_FLASH_CELLBOARD_0_RX(primary_message_FLASH_CELLBOARD_0_RX* message, char* buffer);
int primary_fields_FLASH_CELLBOARD_0_RX(char* buffer);
int primary_to_string_file_FLASH_CELLBOARD_0_RX(primary_message_FLASH_CELLBOARD_0_RX* message, FILE* buffer);
int primary_fields_file_FLASH_CELLBOARD_0_RX(FILE* buffer);


// ============== FLASH_CELLBOARD_1_TX ============== //

primary_byte_size primary_serialize_FLASH_CELLBOARD_1_TX(
    uint8_t* data
);
primary_byte_size primary_serialize_struct_FLASH_CELLBOARD_1_TX(
    uint8_t* data,
    primary_message_FLASH_CELLBOARD_1_TX* message
);
void primary_deserialize_FLASH_CELLBOARD_1_TX(
    primary_message_FLASH_CELLBOARD_1_TX* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_FLASH_CELLBOARD_1_TX(primary_message_FLASH_CELLBOARD_1_TX* message, char* buffer);
int primary_fields_FLASH_CELLBOARD_1_TX(char* buffer);
int primary_to_string_file_FLASH_CELLBOARD_1_TX(primary_message_FLASH_CELLBOARD_1_TX* message, FILE* buffer);
int primary_fields_file_FLASH_CELLBOARD_1_TX(FILE* buffer);


// ============== FLASH_CELLBOARD_1_RX ============== //

primary_byte_size primary_serialize_FLASH_CELLBOARD_1_RX(
    uint8_t* data
);
primary_byte_size primary_serialize_struct_FLASH_CELLBOARD_1_RX(
    uint8_t* data,
    primary_message_FLASH_CELLBOARD_1_RX* message
);
void primary_deserialize_FLASH_CELLBOARD_1_RX(
    primary_message_FLASH_CELLBOARD_1_RX* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_FLASH_CELLBOARD_1_RX(primary_message_FLASH_CELLBOARD_1_RX* message, char* buffer);
int primary_fields_FLASH_CELLBOARD_1_RX(char* buffer);
int primary_to_string_file_FLASH_CELLBOARD_1_RX(primary_message_FLASH_CELLBOARD_1_RX* message, FILE* buffer);
int primary_fields_file_FLASH_CELLBOARD_1_RX(FILE* buffer);


// ============== FLASH_CELLBOARD_2_TX ============== //

primary_byte_size primary_serialize_FLASH_CELLBOARD_2_TX(
    uint8_t* data
);
primary_byte_size primary_serialize_struct_FLASH_CELLBOARD_2_TX(
    uint8_t* data,
    primary_message_FLASH_CELLBOARD_2_TX* message
);
void primary_deserialize_FLASH_CELLBOARD_2_TX(
    primary_message_FLASH_CELLBOARD_2_TX* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_FLASH_CELLBOARD_2_TX(primary_message_FLASH_CELLBOARD_2_TX* message, char* buffer);
int primary_fields_FLASH_CELLBOARD_2_TX(char* buffer);
int primary_to_string_file_FLASH_CELLBOARD_2_TX(primary_message_FLASH_CELLBOARD_2_TX* message, FILE* buffer);
int primary_fields_file_FLASH_CELLBOARD_2_TX(FILE* buffer);


// ============== FLASH_CELLBOARD_2_RX ============== //

primary_byte_size primary_serialize_FLASH_CELLBOARD_2_RX(
    uint8_t* data
);
primary_byte_size primary_serialize_struct_FLASH_CELLBOARD_2_RX(
    uint8_t* data,
    primary_message_FLASH_CELLBOARD_2_RX* message
);
void primary_deserialize_FLASH_CELLBOARD_2_RX(
    primary_message_FLASH_CELLBOARD_2_RX* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_FLASH_CELLBOARD_2_RX(primary_message_FLASH_CELLBOARD_2_RX* message, char* buffer);
int primary_fields_FLASH_CELLBOARD_2_RX(char* buffer);
int primary_to_string_file_FLASH_CELLBOARD_2_RX(primary_message_FLASH_CELLBOARD_2_RX* message, FILE* buffer);
int primary_fields_file_FLASH_CELLBOARD_2_RX(FILE* buffer);


// ============== FLASH_CELLBOARD_3_TX ============== //

primary_byte_size primary_serialize_FLASH_CELLBOARD_3_TX(
    uint8_t* data
);
primary_byte_size primary_serialize_struct_FLASH_CELLBOARD_3_TX(
    uint8_t* data,
    primary_message_FLASH_CELLBOARD_3_TX* message
);
void primary_deserialize_FLASH_CELLBOARD_3_TX(
    primary_message_FLASH_CELLBOARD_3_TX* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_FLASH_CELLBOARD_3_TX(primary_message_FLASH_CELLBOARD_3_TX* message, char* buffer);
int primary_fields_FLASH_CELLBOARD_3_TX(char* buffer);
int primary_to_string_file_FLASH_CELLBOARD_3_TX(primary_message_FLASH_CELLBOARD_3_TX* message, FILE* buffer);
int primary_fields_file_FLASH_CELLBOARD_3_TX(FILE* buffer);


// ============== FLASH_CELLBOARD_3_RX ============== //

primary_byte_size primary_serialize_FLASH_CELLBOARD_3_RX(
    uint8_t* data
);
primary_byte_size primary_serialize_struct_FLASH_CELLBOARD_3_RX(
    uint8_t* data,
    primary_message_FLASH_CELLBOARD_3_RX* message
);
void primary_deserialize_FLASH_CELLBOARD_3_RX(
    primary_message_FLASH_CELLBOARD_3_RX* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_FLASH_CELLBOARD_3_RX(primary_message_FLASH_CELLBOARD_3_RX* message, char* buffer);
int primary_fields_FLASH_CELLBOARD_3_RX(char* buffer);
int primary_to_string_file_FLASH_CELLBOARD_3_RX(primary_message_FLASH_CELLBOARD_3_RX* message, FILE* buffer);
int primary_fields_file_FLASH_CELLBOARD_3_RX(FILE* buffer);


// ============== FLASH_CELLBOARD_4_TX ============== //

primary_byte_size primary_serialize_FLASH_CELLBOARD_4_TX(
    uint8_t* data
);
primary_byte_size primary_serialize_struct_FLASH_CELLBOARD_4_TX(
    uint8_t* data,
    primary_message_FLASH_CELLBOARD_4_TX* message
);
void primary_deserialize_FLASH_CELLBOARD_4_TX(
    primary_message_FLASH_CELLBOARD_4_TX* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_FLASH_CELLBOARD_4_TX(primary_message_FLASH_CELLBOARD_4_TX* message, char* buffer);
int primary_fields_FLASH_CELLBOARD_4_TX(char* buffer);
int primary_to_string_file_FLASH_CELLBOARD_4_TX(primary_message_FLASH_CELLBOARD_4_TX* message, FILE* buffer);
int primary_fields_file_FLASH_CELLBOARD_4_TX(FILE* buffer);


// ============== FLASH_CELLBOARD_4_RX ============== //

primary_byte_size primary_serialize_FLASH_CELLBOARD_4_RX(
    uint8_t* data
);
primary_byte_size primary_serialize_struct_FLASH_CELLBOARD_4_RX(
    uint8_t* data,
    primary_message_FLASH_CELLBOARD_4_RX* message
);
void primary_deserialize_FLASH_CELLBOARD_4_RX(
    primary_message_FLASH_CELLBOARD_4_RX* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_FLASH_CELLBOARD_4_RX(primary_message_FLASH_CELLBOARD_4_RX* message, char* buffer);
int primary_fields_FLASH_CELLBOARD_4_RX(char* buffer);
int primary_to_string_file_FLASH_CELLBOARD_4_RX(primary_message_FLASH_CELLBOARD_4_RX* message, FILE* buffer);
int primary_fields_file_FLASH_CELLBOARD_4_RX(FILE* buffer);


// ============== FLASH_CELLBOARD_5_TX ============== //

primary_byte_size primary_serialize_FLASH_CELLBOARD_5_TX(
    uint8_t* data
);
primary_byte_size primary_serialize_struct_FLASH_CELLBOARD_5_TX(
    uint8_t* data,
    primary_message_FLASH_CELLBOARD_5_TX* message
);
void primary_deserialize_FLASH_CELLBOARD_5_TX(
    primary_message_FLASH_CELLBOARD_5_TX* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_FLASH_CELLBOARD_5_TX(primary_message_FLASH_CELLBOARD_5_TX* message, char* buffer);
int primary_fields_FLASH_CELLBOARD_5_TX(char* buffer);
int primary_to_string_file_FLASH_CELLBOARD_5_TX(primary_message_FLASH_CELLBOARD_5_TX* message, FILE* buffer);
int primary_fields_file_FLASH_CELLBOARD_5_TX(FILE* buffer);


// ============== FLASH_CELLBOARD_5_RX ============== //

primary_byte_size primary_serialize_FLASH_CELLBOARD_5_RX(
    uint8_t* data
);
primary_byte_size primary_serialize_struct_FLASH_CELLBOARD_5_RX(
    uint8_t* data,
    primary_message_FLASH_CELLBOARD_5_RX* message
);
void primary_deserialize_FLASH_CELLBOARD_5_RX(
    primary_message_FLASH_CELLBOARD_5_RX* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_FLASH_CELLBOARD_5_RX(primary_message_FLASH_CELLBOARD_5_RX* message, char* buffer);
int primary_fields_FLASH_CELLBOARD_5_RX(char* buffer);
int primary_to_string_file_FLASH_CELLBOARD_5_RX(primary_message_FLASH_CELLBOARD_5_RX* message, FILE* buffer);
int primary_fields_file_FLASH_CELLBOARD_5_RX(FILE* buffer);


// ============== FLASH_BMS_HV_TX ============== //

primary_byte_size primary_serialize_FLASH_BMS_HV_TX(
    uint8_t* data
);
primary_byte_size primary_serialize_struct_FLASH_BMS_HV_TX(
    uint8_t* data,
    primary_message_FLASH_BMS_HV_TX* message
);
void primary_deserialize_FLASH_BMS_HV_TX(
    primary_message_FLASH_BMS_HV_TX* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_FLASH_BMS_HV_TX(primary_message_FLASH_BMS_HV_TX* message, char* buffer);
int primary_fields_FLASH_BMS_HV_TX(char* buffer);
int primary_to_string_file_FLASH_BMS_HV_TX(primary_message_FLASH_BMS_HV_TX* message, FILE* buffer);
int primary_fields_file_FLASH_BMS_HV_TX(FILE* buffer);


// ============== FLASH_BMS_HV_RX ============== //

primary_byte_size primary_serialize_FLASH_BMS_HV_RX(
    uint8_t* data
);
primary_byte_size primary_serialize_struct_FLASH_BMS_HV_RX(
    uint8_t* data,
    primary_message_FLASH_BMS_HV_RX* message
);
void primary_deserialize_FLASH_BMS_HV_RX(
    primary_message_FLASH_BMS_HV_RX* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_FLASH_BMS_HV_RX(primary_message_FLASH_BMS_HV_RX* message, char* buffer);
int primary_fields_FLASH_BMS_HV_RX(char* buffer);
int primary_to_string_file_FLASH_BMS_HV_RX(primary_message_FLASH_BMS_HV_RX* message, FILE* buffer);
int primary_fields_file_FLASH_BMS_HV_RX(FILE* buffer);


// ============== FLASH_BMS_LV_TX ============== //

primary_byte_size primary_serialize_FLASH_BMS_LV_TX(
    uint8_t* data
);
primary_byte_size primary_serialize_struct_FLASH_BMS_LV_TX(
    uint8_t* data,
    primary_message_FLASH_BMS_LV_TX* message
);
void primary_deserialize_FLASH_BMS_LV_TX(
    primary_message_FLASH_BMS_LV_TX* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_FLASH_BMS_LV_TX(primary_message_FLASH_BMS_LV_TX* message, char* buffer);
int primary_fields_FLASH_BMS_LV_TX(char* buffer);
int primary_to_string_file_FLASH_BMS_LV_TX(primary_message_FLASH_BMS_LV_TX* message, FILE* buffer);
int primary_fields_file_FLASH_BMS_LV_TX(FILE* buffer);


// ============== FLASH_BMS_LV_RX ============== //

primary_byte_size primary_serialize_FLASH_BMS_LV_RX(
    uint8_t* data
);
primary_byte_size primary_serialize_struct_FLASH_BMS_LV_RX(
    uint8_t* data,
    primary_message_FLASH_BMS_LV_RX* message
);
void primary_deserialize_FLASH_BMS_LV_RX(
    primary_message_FLASH_BMS_LV_RX* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_FLASH_BMS_LV_RX(primary_message_FLASH_BMS_LV_RX* message, char* buffer);
int primary_fields_FLASH_BMS_LV_RX(char* buffer);
int primary_to_string_file_FLASH_BMS_LV_RX(primary_message_FLASH_BMS_LV_RX* message, FILE* buffer);
int primary_fields_file_FLASH_BMS_LV_RX(FILE* buffer);


// ============== BRUSA_NLG5_CTL ============== //

primary_byte_size primary_serialize_BRUSA_NLG5_CTL(
    uint8_t* data
);
primary_byte_size primary_serialize_struct_BRUSA_NLG5_CTL(
    uint8_t* data,
    primary_message_BRUSA_NLG5_CTL* message
);
void primary_deserialize_BRUSA_NLG5_CTL(
    primary_message_BRUSA_NLG5_CTL* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_BRUSA_NLG5_CTL(primary_message_BRUSA_NLG5_CTL* message, char* buffer);
int primary_fields_BRUSA_NLG5_CTL(char* buffer);
int primary_to_string_file_BRUSA_NLG5_CTL(primary_message_BRUSA_NLG5_CTL* message, FILE* buffer);
int primary_fields_file_BRUSA_NLG5_CTL(FILE* buffer);


// ============== BRUSA_ST ============== //

primary_byte_size primary_serialize_BRUSA_ST(
    uint8_t* data
);
primary_byte_size primary_serialize_struct_BRUSA_ST(
    uint8_t* data,
    primary_message_BRUSA_ST* message
);
void primary_deserialize_BRUSA_ST(
    primary_message_BRUSA_ST* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_BRUSA_ST(primary_message_BRUSA_ST* message, char* buffer);
int primary_fields_BRUSA_ST(char* buffer);
int primary_to_string_file_BRUSA_ST(primary_message_BRUSA_ST* message, FILE* buffer);
int primary_fields_file_BRUSA_ST(FILE* buffer);


// ============== BRUSA_ACT_I ============== //

primary_byte_size primary_serialize_BRUSA_ACT_I(
    uint8_t* data
);
primary_byte_size primary_serialize_struct_BRUSA_ACT_I(
    uint8_t* data,
    primary_message_BRUSA_ACT_I* message
);
void primary_deserialize_BRUSA_ACT_I(
    primary_message_BRUSA_ACT_I* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_BRUSA_ACT_I(primary_message_BRUSA_ACT_I* message, char* buffer);
int primary_fields_BRUSA_ACT_I(char* buffer);
int primary_to_string_file_BRUSA_ACT_I(primary_message_BRUSA_ACT_I* message, FILE* buffer);
int primary_fields_file_BRUSA_ACT_I(FILE* buffer);


// ============== BRUSA_ACT_II ============== //

primary_byte_size primary_serialize_BRUSA_ACT_II(
    uint8_t* data
);
primary_byte_size primary_serialize_struct_BRUSA_ACT_II(
    uint8_t* data,
    primary_message_BRUSA_ACT_II* message
);
void primary_deserialize_BRUSA_ACT_II(
    primary_message_BRUSA_ACT_II* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_BRUSA_ACT_II(primary_message_BRUSA_ACT_II* message, char* buffer);
int primary_fields_BRUSA_ACT_II(char* buffer);
int primary_to_string_file_BRUSA_ACT_II(primary_message_BRUSA_ACT_II* message, FILE* buffer);
int primary_fields_file_BRUSA_ACT_II(FILE* buffer);


// ============== BRUSA_TEMP ============== //

primary_byte_size primary_serialize_BRUSA_TEMP(
    uint8_t* data
);
primary_byte_size primary_serialize_struct_BRUSA_TEMP(
    uint8_t* data,
    primary_message_BRUSA_TEMP* message
);
void primary_deserialize_BRUSA_TEMP(
    primary_message_BRUSA_TEMP* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_BRUSA_TEMP(primary_message_BRUSA_TEMP* message, char* buffer);
int primary_fields_BRUSA_TEMP(char* buffer);
int primary_to_string_file_BRUSA_TEMP(primary_message_BRUSA_TEMP* message, FILE* buffer);
int primary_fields_file_BRUSA_TEMP(FILE* buffer);


// ============== BRUSA_ERR ============== //

primary_byte_size primary_serialize_BRUSA_ERR(
    uint8_t* data
);
primary_byte_size primary_serialize_struct_BRUSA_ERR(
    uint8_t* data,
    primary_message_BRUSA_ERR* message
);
void primary_deserialize_BRUSA_ERR(
    primary_message_BRUSA_ERR* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_BRUSA_ERR(primary_message_BRUSA_ERR* message, char* buffer);
int primary_fields_BRUSA_ERR(char* buffer);
int primary_to_string_file_BRUSA_ERR(primary_message_BRUSA_ERR* message, FILE* buffer);
int primary_fields_file_BRUSA_ERR(FILE* buffer);


// ============== BMS_HV_CHIMERA ============== //

primary_byte_size primary_serialize_BMS_HV_CHIMERA(
    uint8_t* data
);
primary_byte_size primary_serialize_struct_BMS_HV_CHIMERA(
    uint8_t* data,
    primary_message_BMS_HV_CHIMERA* message
);
void primary_deserialize_BMS_HV_CHIMERA(
    primary_message_BMS_HV_CHIMERA* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_BMS_HV_CHIMERA(primary_message_BMS_HV_CHIMERA* message, char* buffer);
int primary_fields_BMS_HV_CHIMERA(char* buffer);
int primary_to_string_file_BMS_HV_CHIMERA(primary_message_BMS_HV_CHIMERA* message, FILE* buffer);
int primary_fields_file_BMS_HV_CHIMERA(FILE* buffer);


// ============== ECU_CHIMERA ============== //

primary_byte_size primary_serialize_ECU_CHIMERA(
    uint8_t* data
);
primary_byte_size primary_serialize_struct_ECU_CHIMERA(
    uint8_t* data,
    primary_message_ECU_CHIMERA* message
);
void primary_deserialize_ECU_CHIMERA(
    primary_message_ECU_CHIMERA* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int primary_to_string_ECU_CHIMERA(primary_message_ECU_CHIMERA* message, char* buffer);
int primary_fields_ECU_CHIMERA(char* buffer);
int primary_to_string_file_ECU_CHIMERA(primary_message_ECU_CHIMERA* message, FILE* buffer);
int primary_fields_file_ECU_CHIMERA(FILE* buffer);



// ============== UTILS ============== //

static inline int primary_index_from_id(canlib_message_id id) {
    switch (id) {
        case 0: return primary_INDEX_BMS_HV_JMP_TO_BLT;
        case 32: return primary_INDEX_BMS_LV_JMP_TO_BLT;
        case 1025: return primary_INDEX_STEER_VERSION;
        case 1057: return primary_INDEX_DAS_VERSION;
        case 1089: return primary_INDEX_HV_VERSION;
        case 1121: return primary_INDEX_LV_VERSION;
        case 1153: return primary_INDEX_TLM_VERSION;
        case 257: return primary_INDEX_TIMESTAMP;
        case 258: return primary_INDEX_SET_TLM_STATUS;
        case 259: return primary_INDEX_TLM_STATUS;
        case 1794: return primary_INDEX_STEER_SYSTEM_STATUS;
        case 772: return primary_INDEX_HV_VOLTAGE;
        case 804: return primary_INDEX_HV_CURRENT;
        case 836: return primary_INDEX_HV_TEMP;
        case 4: return primary_INDEX_HV_ERRORS;
        case 5: return primary_INDEX_HV_CAN_FORWARD;
        case 37: return primary_INDEX_HV_FANS_OVERRIDE;
        case 6: return primary_INDEX_HV_CAN_FORWARD_STATUS;
        case 774: return primary_INDEX_HV_FANS_OVERRIDE_STATUS;
        case 775: return primary_INDEX_HV_FEEDBACKS_STATUS;
        case 807: return primary_INDEX_HV_IMD_STATUS;
        case 36: return primary_INDEX_TS_STATUS;
        case 69: return primary_INDEX_SET_TS_STATUS_DAS;
        case 101: return primary_INDEX_SET_TS_STATUS_HANDCART;
        case 264: return primary_INDEX_STEER_STATUS;
        case 776: return primary_INDEX_SET_CAR_STATUS;
        case 1032: return primary_INDEX_SET_PEDALS_RANGE;
        case 1064: return primary_INDEX_SET_STEERING_ANGLE_RANGE;
        case 515: return primary_INDEX_CAR_STATUS;
        case 3: return primary_INDEX_DAS_ERRORS;
        case 839: return primary_INDEX_LV_CURRENT;
        case 871: return primary_INDEX_LV_VOLTAGE;
        case 903: return primary_INDEX_LV_TOTAL_VOLTAGE;
        case 935: return primary_INDEX_LV_TEMPERATURE;
        case 967: return primary_INDEX_COOLING_STATUS;
        case 777: return primary_INDEX_SET_RADIATOR_SPEED;
        case 809: return primary_INDEX_SET_PUMPS_SPEED;
        case 265: return primary_INDEX_SET_INVERTER_CONNECTION_STATUS;
        case 263: return primary_INDEX_INVERTER_CONNECTION_STATUS;
        case 7: return primary_INDEX_LV_ERRORS;
        case 295: return primary_INDEX_SHUTDOWN_STATUS;
        case 2: return primary_INDEX_MARKER;
        case 518: return primary_INDEX_HV_CELLS_VOLTAGE;
        case 550: return primary_INDEX_HV_CELLS_TEMP;
        case 582: return primary_INDEX_HV_CELL_BALANCING_STATUS;
        case 517: return primary_INDEX_SET_CELL_BALANCING_STATUS;
        case 773: return primary_INDEX_HANDCART_STATUS;
        case 547: return primary_INDEX_SPEED;
        case 513: return primary_INDEX_INV_L_REQUEST;
        case 514: return primary_INDEX_INV_R_REQUEST;
        case 385: return primary_INDEX_INV_L_RESPONSE;
        case 386: return primary_INDEX_INV_R_RESPONSE;
        case 16: return primary_INDEX_FLASH_CELLBOARD_0_TX;
        case 17: return primary_INDEX_FLASH_CELLBOARD_0_RX;
        case 18: return primary_INDEX_FLASH_CELLBOARD_1_TX;
        case 19: return primary_INDEX_FLASH_CELLBOARD_1_RX;
        case 20: return primary_INDEX_FLASH_CELLBOARD_2_TX;
        case 21: return primary_INDEX_FLASH_CELLBOARD_2_RX;
        case 22: return primary_INDEX_FLASH_CELLBOARD_3_TX;
        case 23: return primary_INDEX_FLASH_CELLBOARD_3_RX;
        case 24: return primary_INDEX_FLASH_CELLBOARD_4_TX;
        case 25: return primary_INDEX_FLASH_CELLBOARD_4_RX;
        case 26: return primary_INDEX_FLASH_CELLBOARD_5_TX;
        case 27: return primary_INDEX_FLASH_CELLBOARD_5_RX;
        case 2017: return primary_INDEX_FLASH_BMS_HV_TX;
        case 1639: return primary_INDEX_FLASH_BMS_HV_RX;
        case 2033: return primary_INDEX_FLASH_BMS_LV_TX;
        case 1655: return primary_INDEX_FLASH_BMS_LV_RX;
        case 618: return primary_INDEX_BRUSA_NLG5_CTL;
        case 610: return primary_INDEX_BRUSA_ST;
        case 611: return primary_INDEX_BRUSA_ACT_I;
        case 612: return primary_INDEX_BRUSA_ACT_II;
        case 613: return primary_INDEX_BRUSA_TEMP;
        case 614: return primary_INDEX_BRUSA_ERR;
        case 170: return primary_INDEX_BMS_HV_CHIMERA;
        case 85: return primary_INDEX_ECU_CHIMERA;
    }
    return 76; // invalid
}

int primary_fields_from_id(canlib_message_id message_id, char *buffer);
int primary_to_string_from_id(canlib_message_id message_id, void* message, char *buffer);
int primary_fields_file_from_id(canlib_message_id message_id, FILE *buffer);
int primary_to_string_file_from_id(canlib_message_id message_id, void* message, FILE *buffer);
void* primary_deserialize_from_id(
    canlib_message_id message_id,
    uint8_t* data,
    void* message_raw,
    void* message_conversion
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
primary_devices* primary_devices_new();
void primary_devices_free(primary_devices* devices);
void primary_devices_deserialize_from_id(
    primary_devices* devices,
    canlib_message_id message_id,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);

#ifdef primary_NETWORK_IMPLEMENTATION


int primary_to_string_HvErrors(primary_HvErrors value, char* buffer) {
    int offset = 0;
    if (CANLIB_BITTEST_BITMASK(value, 1)) offset += sprintf(buffer + offset, "CELL_LOW_VOLTAGE ");
    if (CANLIB_BITTEST_BITMASK(value, 2)) offset += sprintf(buffer + offset, "CELL_UNDER_VOLTAGE ");
    if (CANLIB_BITTEST_BITMASK(value, 4)) offset += sprintf(buffer + offset, "CELL_OVER_VOLTAGE ");
    if (CANLIB_BITTEST_BITMASK(value, 8)) offset += sprintf(buffer + offset, "CELL_HIGH_TEMPERATURE ");
    if (CANLIB_BITTEST_BITMASK(value, 16)) offset += sprintf(buffer + offset, "CELL_OVER_TEMPERATURE ");
    if (CANLIB_BITTEST_BITMASK(value, 32)) offset += sprintf(buffer + offset, "OVER_CURRENT ");
    if (CANLIB_BITTEST_BITMASK(value, 64)) offset += sprintf(buffer + offset, "CAN ");
    if (CANLIB_BITTEST_BITMASK(value, 128)) offset += sprintf(buffer + offset, "INT_VOLTAGE_MISMATCH ");
    if (CANLIB_BITTEST_BITMASK(value, 256)) offset += sprintf(buffer + offset, "CELLBOARD_COMM ");
    if (CANLIB_BITTEST_BITMASK(value, 512)) offset += sprintf(buffer + offset, "CELLBOARD_INTERNAL ");
    if (CANLIB_BITTEST_BITMASK(value, 1024)) offset += sprintf(buffer + offset, "FEEDBACK ");
    if (CANLIB_BITTEST_BITMASK(value, 2048)) offset += sprintf(buffer + offset, "FEEDBACK_CIRCUITRY ");
    if (CANLIB_BITTEST_BITMASK(value, 4096)) offset += sprintf(buffer + offset, "EEPROM_COMM ");
    if (CANLIB_BITTEST_BITMASK(value, 8192)) offset += sprintf(buffer + offset, "EEPROM_WRITE ");
    buffer[offset] = '\0';
    return offset;
}

int primary_to_string_LvErrors(primary_LvErrors value, char* buffer) {
    int offset = 0;
    if (CANLIB_BITTEST_BITMASK(value, 1)) offset += sprintf(buffer + offset, "CELL_UNDERVOLTAGE ");
    if (CANLIB_BITTEST_BITMASK(value, 2)) offset += sprintf(buffer + offset, "CELL_OVERVOLTAGE ");
    if (CANLIB_BITTEST_BITMASK(value, 4)) offset += sprintf(buffer + offset, "OPEN_WIRE ");
    if (CANLIB_BITTEST_BITMASK(value, 8)) offset += sprintf(buffer + offset, "CAN ");
    if (CANLIB_BITTEST_BITMASK(value, 16)) offset += sprintf(buffer + offset, "SPI ");
    if (CANLIB_BITTEST_BITMASK(value, 32)) offset += sprintf(buffer + offset, "OVER_CURRENT ");
    if (CANLIB_BITTEST_BITMASK(value, 64)) offset += sprintf(buffer + offset, "DCDC12_UNDER_TEMPERATURE ");
    if (CANLIB_BITTEST_BITMASK(value, 128)) offset += sprintf(buffer + offset, "DCDC12_OVER_TEMPERATURE ");
    if (CANLIB_BITTEST_BITMASK(value, 256)) offset += sprintf(buffer + offset, "DCDC24_UNDER_TEMPERATURE ");
    if (CANLIB_BITTEST_BITMASK(value, 512)) offset += sprintf(buffer + offset, "DCDC24_OVER_TEMPERATURE ");
    if (CANLIB_BITTEST_BITMASK(value, 1024)) offset += sprintf(buffer + offset, "CELL_UNDER_TEMPERATURE ");
    if (CANLIB_BITTEST_BITMASK(value, 2048)) offset += sprintf(buffer + offset, "CELL_OVER_TEMPERATURE ");
    if (CANLIB_BITTEST_BITMASK(value, 4096)) offset += sprintf(buffer + offset, "RELAY ");
    if (CANLIB_BITTEST_BITMASK(value, 8192)) offset += sprintf(buffer + offset, "LTC6810 ");
    if (CANLIB_BITTEST_BITMASK(value, 16384)) offset += sprintf(buffer + offset, "VOLTAGES_NOT_READY ");
    if (CANLIB_BITTEST_BITMASK(value, 32768)) offset += sprintf(buffer + offset, "MCP23017 ");
    if (CANLIB_BITTEST_BITMASK(value, 65536)) offset += sprintf(buffer + offset, "RADIATOR ");
    if (CANLIB_BITTEST_BITMASK(value, 131072)) offset += sprintf(buffer + offset, "FAN ");
    if (CANLIB_BITTEST_BITMASK(value, 262144)) offset += sprintf(buffer + offset, "PUMP ");
    if (CANLIB_BITTEST_BITMASK(value, 524288)) offset += sprintf(buffer + offset, "ADC_INIT ");
    if (CANLIB_BITTEST_BITMASK(value, 1048576)) offset += sprintf(buffer + offset, "DCDC12 ");
    if (CANLIB_BITTEST_BITMASK(value, 2097152)) offset += sprintf(buffer + offset, "DCDC24 ");
    buffer[offset] = '\0';
    return offset;
}

int primary_to_string_DasErrors(primary_DasErrors value, char* buffer) {
    int offset = 0;
    if (CANLIB_BITTEST_BITMASK(value, 1)) offset += sprintf(buffer + offset, "PEDAL_ADC ");
    if (CANLIB_BITTEST_BITMASK(value, 2)) offset += sprintf(buffer + offset, "PEDAL_IMPLAUSIBILITY ");
    if (CANLIB_BITTEST_BITMASK(value, 4)) offset += sprintf(buffer + offset, "IMU_TOUT ");
    if (CANLIB_BITTEST_BITMASK(value, 8)) offset += sprintf(buffer + offset, "IRTS_TOUT ");
    if (CANLIB_BITTEST_BITMASK(value, 16)) offset += sprintf(buffer + offset, "TS_TOUT ");
    if (CANLIB_BITTEST_BITMASK(value, 32)) offset += sprintf(buffer + offset, "INVL_TOUT ");
    if (CANLIB_BITTEST_BITMASK(value, 64)) offset += sprintf(buffer + offset, "INVR_TOUT ");
    if (CANLIB_BITTEST_BITMASK(value, 128)) offset += sprintf(buffer + offset, "STEER_TOUT ");
    if (CANLIB_BITTEST_BITMASK(value, 256)) offset += sprintf(buffer + offset, "FSM ");
    buffer[offset] = '\0';
    return offset;
}

int primary_to_string_InvStatus(primary_InvStatus value, char* buffer) {
    int offset = 0;
    if (CANLIB_BITTEST_BITMASK(value, 1)) offset += sprintf(buffer + offset, "DRIVE_ENABLE ");
    if (CANLIB_BITTEST_BITMASK(value, 2)) offset += sprintf(buffer + offset, "NCR0 ");
    if (CANLIB_BITTEST_BITMASK(value, 4)) offset += sprintf(buffer + offset, "LIMP ");
    if (CANLIB_BITTEST_BITMASK(value, 8)) offset += sprintf(buffer + offset, "LIMM ");
    if (CANLIB_BITTEST_BITMASK(value, 16)) offset += sprintf(buffer + offset, "DRIVE_OK ");
    if (CANLIB_BITTEST_BITMASK(value, 32)) offset += sprintf(buffer + offset, "ICNS ");
    if (CANLIB_BITTEST_BITMASK(value, 64)) offset += sprintf(buffer + offset, "T_NLIM ");
    if (CANLIB_BITTEST_BITMASK(value, 128)) offset += sprintf(buffer + offset, "P_N ");
    if (CANLIB_BITTEST_BITMASK(value, 256)) offset += sprintf(buffer + offset, "N_I ");
    if (CANLIB_BITTEST_BITMASK(value, 512)) offset += sprintf(buffer + offset, "N0 ");
    if (CANLIB_BITTEST_BITMASK(value, 1024)) offset += sprintf(buffer + offset, "RSW ");
    if (CANLIB_BITTEST_BITMASK(value, 2048)) offset += sprintf(buffer + offset, "CAL0 ");
    if (CANLIB_BITTEST_BITMASK(value, 4096)) offset += sprintf(buffer + offset, "CAL ");
    if (CANLIB_BITTEST_BITMASK(value, 8192)) offset += sprintf(buffer + offset, "TOL ");
    if (CANLIB_BITTEST_BITMASK(value, 16384)) offset += sprintf(buffer + offset, "DRIVE_READY ");
    if (CANLIB_BITTEST_BITMASK(value, 32768)) offset += sprintf(buffer + offset, "BRK ");
    if (CANLIB_BITTEST_BITMASK(value, 65536)) offset += sprintf(buffer + offset, "SIGN_MAG ");
    if (CANLIB_BITTEST_BITMASK(value, 131072)) offset += sprintf(buffer + offset, "NCLIP ");
    if (CANLIB_BITTEST_BITMASK(value, 262144)) offset += sprintf(buffer + offset, "NCLIPP ");
    if (CANLIB_BITTEST_BITMASK(value, 524288)) offset += sprintf(buffer + offset, "NCLIPM ");
    if (CANLIB_BITTEST_BITMASK(value, 1048576)) offset += sprintf(buffer + offset, "IRD_DIG ");
    if (CANLIB_BITTEST_BITMASK(value, 2097152)) offset += sprintf(buffer + offset, "IUSE_RCHD ");
    if (CANLIB_BITTEST_BITMASK(value, 4194304)) offset += sprintf(buffer + offset, "IRD_N ");
    if (CANLIB_BITTEST_BITMASK(value, 8388608)) offset += sprintf(buffer + offset, "IRD_TI ");
    if (CANLIB_BITTEST_BITMASK(value, 16777216)) offset += sprintf(buffer + offset, "IRD_TIR ");
    if (CANLIB_BITTEST_BITMASK(value, 33554432)) offset += sprintf(buffer + offset, "HZ10 ");
    if (CANLIB_BITTEST_BITMASK(value, 67108864)) offset += sprintf(buffer + offset, "IRD_TM ");
    if (CANLIB_BITTEST_BITMASK(value, 134217728)) offset += sprintf(buffer + offset, "IRD_ANA ");
    if (CANLIB_BITTEST_BITMASK(value, 268435456)) offset += sprintf(buffer + offset, "IWCNS ");
    if (CANLIB_BITTEST_BITMASK(value, 536870912)) offset += sprintf(buffer + offset, "RFE_PULSE ");
    if (CANLIB_BITTEST_BITMASK(value, 1073741824)) offset += sprintf(buffer + offset, "MD ");
    if (CANLIB_BITTEST_BITMASK(value, 2147483648)) offset += sprintf(buffer + offset, "HND_WHL ");
    buffer[offset] = '\0';
    return offset;
}

int primary_to_string_InvErrors(primary_InvErrors value, char* buffer) {
    int offset = 0;
    if (CANLIB_BITTEST_BITMASK(value, 1)) offset += sprintf(buffer + offset, "BAD_PARAM ");
    if (CANLIB_BITTEST_BITMASK(value, 2)) offset += sprintf(buffer + offset, "HW_FAULT ");
    if (CANLIB_BITTEST_BITMASK(value, 4)) offset += sprintf(buffer + offset, "SAFETY_FAULT ");
    if (CANLIB_BITTEST_BITMASK(value, 8)) offset += sprintf(buffer + offset, "CAN_TIMEOUT ");
    if (CANLIB_BITTEST_BITMASK(value, 16)) offset += sprintf(buffer + offset, "ENCODER_ERR ");
    if (CANLIB_BITTEST_BITMASK(value, 32)) offset += sprintf(buffer + offset, "NO_POWER_VOLTAGE ");
    if (CANLIB_BITTEST_BITMASK(value, 64)) offset += sprintf(buffer + offset, "HI_MOTOR_TEMP ");
    if (CANLIB_BITTEST_BITMASK(value, 128)) offset += sprintf(buffer + offset, "HI_DEVICE_TEMP ");
    if (CANLIB_BITTEST_BITMASK(value, 256)) offset += sprintf(buffer + offset, "OVERVOLTAGE ");
    if (CANLIB_BITTEST_BITMASK(value, 512)) offset += sprintf(buffer + offset, "OVERCURRENT ");
    if (CANLIB_BITTEST_BITMASK(value, 1024)) offset += sprintf(buffer + offset, "RACEAWAY ");
    if (CANLIB_BITTEST_BITMASK(value, 2048)) offset += sprintf(buffer + offset, "USER_ERR ");
    if (CANLIB_BITTEST_BITMASK(value, 4096)) offset += sprintf(buffer + offset, "UNKNOWN_ERR_12 ");
    if (CANLIB_BITTEST_BITMASK(value, 8192)) offset += sprintf(buffer + offset, "UNKNOWN_ERR_13 ");
    if (CANLIB_BITTEST_BITMASK(value, 16384)) offset += sprintf(buffer + offset, "CURRENT_ERR ");
    if (CANLIB_BITTEST_BITMASK(value, 32768)) offset += sprintf(buffer + offset, "BALLAST_OVERLOAD ");
    if (CANLIB_BITTEST_BITMASK(value, 65536)) offset += sprintf(buffer + offset, "DEVICE_ID_ERR ");
    if (CANLIB_BITTEST_BITMASK(value, 131072)) offset += sprintf(buffer + offset, "RUN_SIG_FAULT ");
    if (CANLIB_BITTEST_BITMASK(value, 262144)) offset += sprintf(buffer + offset, "UNKNOWN_ERR_19 ");
    if (CANLIB_BITTEST_BITMASK(value, 524288)) offset += sprintf(buffer + offset, "UNKNOWN_ERR_20 ");
    if (CANLIB_BITTEST_BITMASK(value, 1048576)) offset += sprintf(buffer + offset, "POWERVOLTAGE_WARN ");
    if (CANLIB_BITTEST_BITMASK(value, 2097152)) offset += sprintf(buffer + offset, "HI_MOTOR_TEMP_WARN ");
    if (CANLIB_BITTEST_BITMASK(value, 4194304)) offset += sprintf(buffer + offset, "HI_DEVICE_TEMP_WARN ");
    if (CANLIB_BITTEST_BITMASK(value, 8388608)) offset += sprintf(buffer + offset, "VOUT_LIMIT_WARN ");
    if (CANLIB_BITTEST_BITMASK(value, 16777216)) offset += sprintf(buffer + offset, "OVERCURRENT_WARN ");
    if (CANLIB_BITTEST_BITMASK(value, 33554432)) offset += sprintf(buffer + offset, "RACEAWAY_WARN ");
    if (CANLIB_BITTEST_BITMASK(value, 67108864)) offset += sprintf(buffer + offset, "UNKNOWN_ERR_27 ");
    if (CANLIB_BITTEST_BITMASK(value, 134217728)) offset += sprintf(buffer + offset, "UNKNOWN_ERR_28 ");
    if (CANLIB_BITTEST_BITMASK(value, 268435456)) offset += sprintf(buffer + offset, "UNKNOWN_ERR_29 ");
    if (CANLIB_BITTEST_BITMASK(value, 536870912)) offset += sprintf(buffer + offset, "UNKNOWN_ERR_30 ");
    if (CANLIB_BITTEST_BITMASK(value, 1073741824)) offset += sprintf(buffer + offset, "BALLAST_OVERLOAD_WARN ");
    buffer[offset] = '\0';
    return offset;
}

int primary_to_string_Inv_IOInfo(primary_Inv_IOInfo value, char* buffer) {
    int offset = 0;
    if (CANLIB_BITTEST_BITMASK(value, 1)) offset += sprintf(buffer + offset, "LMT1 ");
    if (CANLIB_BITTEST_BITMASK(value, 2)) offset += sprintf(buffer + offset, "LMT2 ");
    if (CANLIB_BITTEST_BITMASK(value, 4)) offset += sprintf(buffer + offset, "IN2 ");
    if (CANLIB_BITTEST_BITMASK(value, 8)) offset += sprintf(buffer + offset, "IN1 ");
    if (CANLIB_BITTEST_BITMASK(value, 16)) offset += sprintf(buffer + offset, "FRG ");
    if (CANLIB_BITTEST_BITMASK(value, 32)) offset += sprintf(buffer + offset, "RFE ");
    if (CANLIB_BITTEST_BITMASK(value, 64)) offset += sprintf(buffer + offset, "UNK6 ");
    if (CANLIB_BITTEST_BITMASK(value, 128)) offset += sprintf(buffer + offset, "UNK7 ");
    if (CANLIB_BITTEST_BITMASK(value, 256)) offset += sprintf(buffer + offset, "OUT1 ");
    if (CANLIB_BITTEST_BITMASK(value, 512)) offset += sprintf(buffer + offset, "OUT2 ");
    if (CANLIB_BITTEST_BITMASK(value, 1024)) offset += sprintf(buffer + offset, "BTB ");
    if (CANLIB_BITTEST_BITMASK(value, 2048)) offset += sprintf(buffer + offset, "GO ");
    if (CANLIB_BITTEST_BITMASK(value, 4096)) offset += sprintf(buffer + offset, "OUT3 ");
    if (CANLIB_BITTEST_BITMASK(value, 8192)) offset += sprintf(buffer + offset, "OUT4 ");
    if (CANLIB_BITTEST_BITMASK(value, 16384)) offset += sprintf(buffer + offset, "G_OFF ");
    if (CANLIB_BITTEST_BITMASK(value, 32768)) offset += sprintf(buffer + offset, "BRK1 ");
    buffer[offset] = '\0';
    return offset;
}

int primary_to_string_HvFeedbacks(primary_HvFeedbacks value, char* buffer) {
    int offset = 0;
    if (CANLIB_BITTEST_BITMASK(value, 1)) offset += sprintf(buffer + offset, "FEEDBACK_TSAL_GREEN_FAULT ");
    if (CANLIB_BITTEST_BITMASK(value, 2)) offset += sprintf(buffer + offset, "FEEDBACK_IMD_LATCHED ");
    if (CANLIB_BITTEST_BITMASK(value, 4)) offset += sprintf(buffer + offset, "FEEDBACK_TSAL_GREEN_FAULT_LATCHED ");
    if (CANLIB_BITTEST_BITMASK(value, 8)) offset += sprintf(buffer + offset, "FEEDBACK_BMS_LATCHED ");
    if (CANLIB_BITTEST_BITMASK(value, 16)) offset += sprintf(buffer + offset, "FEEDBACK_EXT_LATCHED ");
    if (CANLIB_BITTEST_BITMASK(value, 32)) offset += sprintf(buffer + offset, "FEEDBACK_TSAL_GREEN ");
    if (CANLIB_BITTEST_BITMASK(value, 64)) offset += sprintf(buffer + offset, "FEEDBACK_TS_OVER_60V_STATUS ");
    if (CANLIB_BITTEST_BITMASK(value, 128)) offset += sprintf(buffer + offset, "FEEDBACK_AIRN_STATUS ");
    if (CANLIB_BITTEST_BITMASK(value, 256)) offset += sprintf(buffer + offset, "FEEDBACK_AIRP_STATUS ");
    if (CANLIB_BITTEST_BITMASK(value, 512)) offset += sprintf(buffer + offset, "FEEDBACK_AIRP_GATE ");
    if (CANLIB_BITTEST_BITMASK(value, 1024)) offset += sprintf(buffer + offset, "FEEDBACK_AIRN_GATE ");
    if (CANLIB_BITTEST_BITMASK(value, 2048)) offset += sprintf(buffer + offset, "FEEDBACK_PRECHARGE_STATUS ");
    if (CANLIB_BITTEST_BITMASK(value, 4096)) offset += sprintf(buffer + offset, "FEEDBACK_TSP_OVER_60V_STATUS ");
    if (CANLIB_BITTEST_BITMASK(value, 8192)) offset += sprintf(buffer + offset, "FEEDBACK_CHECK_MUX ");
    if (CANLIB_BITTEST_BITMASK(value, 16384)) offset += sprintf(buffer + offset, "FEEDBACK_SD_IN ");
    if (CANLIB_BITTEST_BITMASK(value, 32768)) offset += sprintf(buffer + offset, "FEEDBACK_SD_OUT ");
    if (CANLIB_BITTEST_BITMASK(value, 65536)) offset += sprintf(buffer + offset, "FEEDBACK_RELAY_SD ");
    if (CANLIB_BITTEST_BITMASK(value, 131072)) offset += sprintf(buffer + offset, "FEEDBACK_IMD_FAULT ");
    if (CANLIB_BITTEST_BITMASK(value, 262144)) offset += sprintf(buffer + offset, "FEEDBACK_SD_END ");
    buffer[offset] = '\0';
    return offset;
}



int primary_to_string_RaceType(primary_RaceType value, char* buffer) {
    switch (value) {
        case 0: return sprintf(buffer, "ACCELERATION");
        case 1: return sprintf(buffer, "SKIDPAD");
        case 2: return sprintf(buffer, "AUTOCROSS");
        case 3: return sprintf(buffer, "ENDURANCE");
    }
    return 0;
}

int primary_to_string_InverterStatus(primary_InverterStatus value, char* buffer) {
    switch (value) {
        case 0: return sprintf(buffer, "OFF");
        case 1: return sprintf(buffer, "IDLE");
        case 2: return sprintf(buffer, "ON");
    }
    return 0;
}

int primary_to_string_CarStatus(primary_CarStatus value, char* buffer) {
    switch (value) {
        case 0: return sprintf(buffer, "IDLE");
        case 1: return sprintf(buffer, "PRE_SETUP");
        case 2: return sprintf(buffer, "TS_ON");
        case 3: return sprintf(buffer, "POST_SETUP");
        case 4: return sprintf(buffer, "DRIVE");
        case 5: return sprintf(buffer, "TEARDOWN");
    }
    return 0;
}

int primary_to_string_Toggle(primary_Toggle value, char* buffer) {
    switch (value) {
        case 0: return sprintf(buffer, "ON");
        case 1: return sprintf(buffer, "OFF");
    }
    return 0;
}

int primary_to_string_TractionControl(primary_TractionControl value, char* buffer) {
    switch (value) {
        case 0: return sprintf(buffer, "OFF");
        case 1: return sprintf(buffer, "SLIP_CONTROL");
        case 2: return sprintf(buffer, "TORQUE_VECTORING");
        case 3: return sprintf(buffer, "COMPLETE");
    }
    return 0;
}

int primary_to_string_TsStatus(primary_TsStatus value, char* buffer) {
    switch (value) {
        case 0: return sprintf(buffer, "OFF");
        case 1: return sprintf(buffer, "PRECHARGE");
        case 2: return sprintf(buffer, "ON");
        case 3: return sprintf(buffer, "FATAL");
    }
    return 0;
}

int primary_to_string_Map(primary_Map value, char* buffer) {
    switch (value) {
        case 0: return sprintf(buffer, "R");
        case 1: return sprintf(buffer, "D20");
        case 2: return sprintf(buffer, "D40");
        case 3: return sprintf(buffer, "D60");
        case 4: return sprintf(buffer, "D80");
        case 5: return sprintf(buffer, "D100");
    }
    return 0;
}

int primary_to_string_SetCarStatus(primary_SetCarStatus value, char* buffer) {
    switch (value) {
        case 0: return sprintf(buffer, "IDLE");
        case 1: return sprintf(buffer, "READY");
        case 2: return sprintf(buffer, "DRIVE");
    }
    return 0;
}

int primary_to_string_Bound(primary_Bound value, char* buffer) {
    switch (value) {
        case 0: return sprintf(buffer, "SET_MAX");
        case 1: return sprintf(buffer, "SET_MIN");
    }
    return 0;
}

int primary_to_string_Pedal(primary_Pedal value, char* buffer) {
    switch (value) {
        case 0: return sprintf(buffer, "ACCELERATOR");
        case 1: return sprintf(buffer, "BRAKE");
    }
    return 0;
}

int primary_to_string_ImdStatus(primary_ImdStatus value, char* buffer) {
    switch (value) {
        case 0: return sprintf(buffer, "IMD_SC");
        case 1: return sprintf(buffer, "IMD_NORMAL");
        case 2: return sprintf(buffer, "IMD_UNDER_VOLTAGE");
        case 3: return sprintf(buffer, "IMD_START_MEASURE");
        case 4: return sprintf(buffer, "IMD_DEVICE_ERROR");
        case 5: return sprintf(buffer, "IMD_EARTH_FAULT");
    }
    return 0;
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_BMS_HV_JMP_TO_BLT(
    uint8_t* data
) {
    CANLIB_UNUSED(data);
    return 0;
}

primary_byte_size primary_serialize_struct_BMS_HV_JMP_TO_BLT(
    uint8_t* data,
    primary_message_BMS_HV_JMP_TO_BLT* message
) {
    CANLIB_UNUSED(data);
    CANLIB_UNUSED(message);
    return 0;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_BMS_HV_JMP_TO_BLT(
    primary_message_BMS_HV_JMP_TO_BLT* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(data);
#ifdef CANLIB_TIMESTAMP
    CANLIB_UNUSED(_timestamp);
#endif // CANLIB_TIMESTAMP
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
}

// ============== STRING ============== //

int primary_to_string_BMS_HV_JMP_TO_BLT(primary_message_BMS_HV_JMP_TO_BLT* message, char* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_fields_BMS_HV_JMP_TO_BLT(char* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_to_string_file_BMS_HV_JMP_TO_BLT(primary_message_BMS_HV_JMP_TO_BLT* message, FILE* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_fields_file_BMS_HV_JMP_TO_BLT(FILE* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_BMS_LV_JMP_TO_BLT(
    uint8_t* data
) {
    CANLIB_UNUSED(data);
    return 0;
}

primary_byte_size primary_serialize_struct_BMS_LV_JMP_TO_BLT(
    uint8_t* data,
    primary_message_BMS_LV_JMP_TO_BLT* message
) {
    CANLIB_UNUSED(data);
    CANLIB_UNUSED(message);
    return 0;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_BMS_LV_JMP_TO_BLT(
    primary_message_BMS_LV_JMP_TO_BLT* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(data);
#ifdef CANLIB_TIMESTAMP
    CANLIB_UNUSED(_timestamp);
#endif // CANLIB_TIMESTAMP
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
}

// ============== STRING ============== //

int primary_to_string_BMS_LV_JMP_TO_BLT(primary_message_BMS_LV_JMP_TO_BLT* message, char* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_fields_BMS_LV_JMP_TO_BLT(char* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_to_string_file_BMS_LV_JMP_TO_BLT(primary_message_BMS_LV_JMP_TO_BLT* message, FILE* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_fields_file_BMS_LV_JMP_TO_BLT(FILE* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_STEER_VERSION(
    uint8_t* data,
    primary_uint8 component_version,
    primary_uint32 cancicd_version
) {
    data[0] = cancicd_version & 255;
    data[1] = (cancicd_version >> 8) & 255;
    data[2] = (cancicd_version >> 16) & 255;
    data[3] = (cancicd_version >> 24) & 255;
    data[4] = component_version;
    return 5;
}

primary_byte_size primary_serialize_struct_STEER_VERSION(
    uint8_t* data,
    primary_message_STEER_VERSION* message
) {
    data[0] = message->cancicd_version & 255;
    data[1] = (message->cancicd_version >> 8) & 255;
    data[2] = (message->cancicd_version >> 16) & 255;
    data[3] = (message->cancicd_version >> 24) & 255;
    data[4] = message->component_version;
    return 5;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_STEER_VERSION(
    primary_message_STEER_VERSION* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->cancicd_version = data[0] | (data[1] << 8) | (data[2] << 16) | (data[3] << 24);
    message->component_version = data[4];
}

// ============== STRING ============== //

int primary_to_string_STEER_VERSION(primary_message_STEER_VERSION* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu32,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->component_version,
        message->cancicd_version
    );
}

int primary_fields_STEER_VERSION(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "component_version" CANLIB_SEPARATOR 
        "cancicd_version"
    );
}

int primary_to_string_file_STEER_VERSION(primary_message_STEER_VERSION* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu32,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->component_version,
        message->cancicd_version
    );
}

int primary_fields_file_STEER_VERSION(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "component_version" CANLIB_SEPARATOR 
        "cancicd_version"
    );
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_DAS_VERSION(
    uint8_t* data,
    primary_uint8 component_version,
    primary_uint32 cancicd_version
) {
    data[0] = cancicd_version & 255;
    data[1] = (cancicd_version >> 8) & 255;
    data[2] = (cancicd_version >> 16) & 255;
    data[3] = (cancicd_version >> 24) & 255;
    data[4] = component_version;
    return 5;
}

primary_byte_size primary_serialize_struct_DAS_VERSION(
    uint8_t* data,
    primary_message_DAS_VERSION* message
) {
    data[0] = message->cancicd_version & 255;
    data[1] = (message->cancicd_version >> 8) & 255;
    data[2] = (message->cancicd_version >> 16) & 255;
    data[3] = (message->cancicd_version >> 24) & 255;
    data[4] = message->component_version;
    return 5;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_DAS_VERSION(
    primary_message_DAS_VERSION* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->cancicd_version = data[0] | (data[1] << 8) | (data[2] << 16) | (data[3] << 24);
    message->component_version = data[4];
}

// ============== STRING ============== //

int primary_to_string_DAS_VERSION(primary_message_DAS_VERSION* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu32,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->component_version,
        message->cancicd_version
    );
}

int primary_fields_DAS_VERSION(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "component_version" CANLIB_SEPARATOR 
        "cancicd_version"
    );
}

int primary_to_string_file_DAS_VERSION(primary_message_DAS_VERSION* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu32,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->component_version,
        message->cancicd_version
    );
}

int primary_fields_file_DAS_VERSION(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "component_version" CANLIB_SEPARATOR 
        "cancicd_version"
    );
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_HV_VERSION(
    uint8_t* data,
    primary_uint8 component_version,
    primary_uint32 cancicd_version
) {
    data[0] = cancicd_version & 255;
    data[1] = (cancicd_version >> 8) & 255;
    data[2] = (cancicd_version >> 16) & 255;
    data[3] = (cancicd_version >> 24) & 255;
    data[4] = component_version;
    return 5;
}

primary_byte_size primary_serialize_struct_HV_VERSION(
    uint8_t* data,
    primary_message_HV_VERSION* message
) {
    data[0] = message->cancicd_version & 255;
    data[1] = (message->cancicd_version >> 8) & 255;
    data[2] = (message->cancicd_version >> 16) & 255;
    data[3] = (message->cancicd_version >> 24) & 255;
    data[4] = message->component_version;
    return 5;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_HV_VERSION(
    primary_message_HV_VERSION* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->cancicd_version = data[0] | (data[1] << 8) | (data[2] << 16) | (data[3] << 24);
    message->component_version = data[4];
}

// ============== STRING ============== //

int primary_to_string_HV_VERSION(primary_message_HV_VERSION* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu32,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->component_version,
        message->cancicd_version
    );
}

int primary_fields_HV_VERSION(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "component_version" CANLIB_SEPARATOR 
        "cancicd_version"
    );
}

int primary_to_string_file_HV_VERSION(primary_message_HV_VERSION* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu32,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->component_version,
        message->cancicd_version
    );
}

int primary_fields_file_HV_VERSION(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "component_version" CANLIB_SEPARATOR 
        "cancicd_version"
    );
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_LV_VERSION(
    uint8_t* data,
    primary_uint8 component_version,
    primary_uint32 cancicd_version
) {
    data[0] = cancicd_version & 255;
    data[1] = (cancicd_version >> 8) & 255;
    data[2] = (cancicd_version >> 16) & 255;
    data[3] = (cancicd_version >> 24) & 255;
    data[4] = component_version;
    return 5;
}

primary_byte_size primary_serialize_struct_LV_VERSION(
    uint8_t* data,
    primary_message_LV_VERSION* message
) {
    data[0] = message->cancicd_version & 255;
    data[1] = (message->cancicd_version >> 8) & 255;
    data[2] = (message->cancicd_version >> 16) & 255;
    data[3] = (message->cancicd_version >> 24) & 255;
    data[4] = message->component_version;
    return 5;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_LV_VERSION(
    primary_message_LV_VERSION* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->cancicd_version = data[0] | (data[1] << 8) | (data[2] << 16) | (data[3] << 24);
    message->component_version = data[4];
}

// ============== STRING ============== //

int primary_to_string_LV_VERSION(primary_message_LV_VERSION* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu32,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->component_version,
        message->cancicd_version
    );
}

int primary_fields_LV_VERSION(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "component_version" CANLIB_SEPARATOR 
        "cancicd_version"
    );
}

int primary_to_string_file_LV_VERSION(primary_message_LV_VERSION* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu32,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->component_version,
        message->cancicd_version
    );
}

int primary_fields_file_LV_VERSION(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "component_version" CANLIB_SEPARATOR 
        "cancicd_version"
    );
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_TLM_VERSION(
    uint8_t* data,
    primary_uint8 component_version,
    primary_uint32 cancicd_version
) {
    data[0] = cancicd_version & 255;
    data[1] = (cancicd_version >> 8) & 255;
    data[2] = (cancicd_version >> 16) & 255;
    data[3] = (cancicd_version >> 24) & 255;
    data[4] = component_version;
    return 5;
}

primary_byte_size primary_serialize_struct_TLM_VERSION(
    uint8_t* data,
    primary_message_TLM_VERSION* message
) {
    data[0] = message->cancicd_version & 255;
    data[1] = (message->cancicd_version >> 8) & 255;
    data[2] = (message->cancicd_version >> 16) & 255;
    data[3] = (message->cancicd_version >> 24) & 255;
    data[4] = message->component_version;
    return 5;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_TLM_VERSION(
    primary_message_TLM_VERSION* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->cancicd_version = data[0] | (data[1] << 8) | (data[2] << 16) | (data[3] << 24);
    message->component_version = data[4];
}

// ============== STRING ============== //

int primary_to_string_TLM_VERSION(primary_message_TLM_VERSION* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu32,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->component_version,
        message->cancicd_version
    );
}

int primary_fields_TLM_VERSION(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "component_version" CANLIB_SEPARATOR 
        "cancicd_version"
    );
}

int primary_to_string_file_TLM_VERSION(primary_message_TLM_VERSION* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu32,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->component_version,
        message->cancicd_version
    );
}

int primary_fields_file_TLM_VERSION(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "component_version" CANLIB_SEPARATOR 
        "cancicd_version"
    );
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_TIMESTAMP(
    uint8_t* data,
    primary_uint32 timestamp
) {
    data[0] = timestamp & 255;
    data[1] = (timestamp >> 8) & 255;
    data[2] = (timestamp >> 16) & 255;
    data[3] = (timestamp >> 24) & 255;
    return 4;
}

primary_byte_size primary_serialize_struct_TIMESTAMP(
    uint8_t* data,
    primary_message_TIMESTAMP* message
) {
    data[0] = message->timestamp & 255;
    data[1] = (message->timestamp >> 8) & 255;
    data[2] = (message->timestamp >> 16) & 255;
    data[3] = (message->timestamp >> 24) & 255;
    return 4;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_TIMESTAMP(
    primary_message_TIMESTAMP* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->timestamp = data[0] | (data[1] << 8) | (data[2] << 16) | (data[3] << 24);
}

// ============== STRING ============== //

int primary_to_string_TIMESTAMP(primary_message_TIMESTAMP* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu32,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->timestamp
    );
}

int primary_fields_TIMESTAMP(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "timestamp"
    );
}

int primary_to_string_file_TIMESTAMP(primary_message_TIMESTAMP* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu32,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->timestamp
    );
}

int primary_fields_file_TIMESTAMP(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "timestamp"
    );
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_SET_TLM_STATUS(
    uint8_t* data,
    primary_Toggle tlm_status
) {
    data[0] = tlm_status << 7;
    return 1;
}

primary_byte_size primary_serialize_struct_SET_TLM_STATUS(
    uint8_t* data,
    primary_message_SET_TLM_STATUS* message
) {
    data[0] = message->tlm_status << 7;
    return 1;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_SET_TLM_STATUS(
    primary_message_SET_TLM_STATUS* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->tlm_status = (primary_Toggle) ((data[0] & 128) >> 7);
}

// ============== STRING ============== //

int primary_to_string_SET_TLM_STATUS(primary_message_SET_TLM_STATUS* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->tlm_status
    );
}

int primary_fields_SET_TLM_STATUS(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "tlm_status"
    );
}

int primary_to_string_file_SET_TLM_STATUS(primary_message_SET_TLM_STATUS* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->tlm_status
    );
}

int primary_fields_file_SET_TLM_STATUS(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "tlm_status"
    );
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_TLM_STATUS(
    uint8_t* data,
    primary_Toggle tlm_status
) {
    data[0] = tlm_status << 7;
    return 1;
}

primary_byte_size primary_serialize_struct_TLM_STATUS(
    uint8_t* data,
    primary_message_TLM_STATUS* message
) {
    data[0] = message->tlm_status << 7;
    return 1;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_TLM_STATUS(
    primary_message_TLM_STATUS* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->tlm_status = (primary_Toggle) ((data[0] & 128) >> 7);
}

// ============== STRING ============== //

int primary_to_string_TLM_STATUS(primary_message_TLM_STATUS* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->tlm_status
    );
}

int primary_fields_TLM_STATUS(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "tlm_status"
    );
}

int primary_to_string_file_TLM_STATUS(primary_message_TLM_STATUS* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->tlm_status
    );
}

int primary_fields_file_TLM_STATUS(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "tlm_status"
    );
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_STEER_SYSTEM_STATUS(
    uint8_t* data,
    primary_uint8 soc_temp
) {
    data[0] = soc_temp;
    return 1;
}

primary_byte_size primary_serialize_struct_STEER_SYSTEM_STATUS(
    uint8_t* data,
    primary_message_STEER_SYSTEM_STATUS* message
) {
    data[0] = message->soc_temp;
    return 1;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_STEER_SYSTEM_STATUS(
    primary_message_STEER_SYSTEM_STATUS* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->soc_temp = data[0];
}

// ============== STRING ============== //

int primary_to_string_STEER_SYSTEM_STATUS(primary_message_STEER_SYSTEM_STATUS* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->soc_temp
    );
}

int primary_fields_STEER_SYSTEM_STATUS(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "soc_temp"
    );
}

int primary_to_string_file_STEER_SYSTEM_STATUS(primary_message_STEER_SYSTEM_STATUS* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->soc_temp
    );
}

int primary_fields_file_STEER_SYSTEM_STATUS(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "soc_temp"
    );
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_HV_VOLTAGE(
    uint8_t* data,
    primary_uint16 pack_voltage,
    primary_uint16 bus_voltage,
    primary_uint16 max_cell_voltage,
    primary_uint16 min_cell_voltage
) {
    data[0] = pack_voltage & 255;
    data[1] = (pack_voltage >> 8) & 255;
    data[2] = bus_voltage & 255;
    data[3] = (bus_voltage >> 8) & 255;
    data[4] = max_cell_voltage & 255;
    data[5] = (max_cell_voltage >> 8) & 255;
    data[6] = min_cell_voltage & 255;
    data[7] = (min_cell_voltage >> 8) & 255;
    return 8;
}

primary_byte_size primary_serialize_struct_HV_VOLTAGE(
    uint8_t* data,
    primary_message_HV_VOLTAGE* message
) {
    data[0] = message->pack_voltage & 255;
    data[1] = (message->pack_voltage >> 8) & 255;
    data[2] = message->bus_voltage & 255;
    data[3] = (message->bus_voltage >> 8) & 255;
    data[4] = message->max_cell_voltage & 255;
    data[5] = (message->max_cell_voltage >> 8) & 255;
    data[6] = message->min_cell_voltage & 255;
    data[7] = (message->min_cell_voltage >> 8) & 255;
    return 8;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_HV_VOLTAGE(
    primary_message_HV_VOLTAGE* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->pack_voltage = data[0] | (data[1] << 8);
    message->bus_voltage = data[2] | (data[3] << 8);
    message->max_cell_voltage = data[4] | (data[5] << 8);
    message->min_cell_voltage = data[6] | (data[7] << 8);
}// ============== CONVERSION ============== //

void primary_raw_to_conversion_HV_VOLTAGE(
    primary_message_HV_VOLTAGE_conversion* conversion,
    primary_uint16 pack_voltage,
    primary_uint16 bus_voltage,
    primary_uint16 max_cell_voltage,
    primary_uint16 min_cell_voltage
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
){
#ifdef CANLIB_TIMESTAMP
    conversion->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    conversion->pack_voltage = (((primary_float32)pack_voltage) / 142.467391) + 0;
    conversion->bus_voltage = (((primary_float32)bus_voltage) / 142.467391) + 0;
    conversion->max_cell_voltage = (((primary_float32)max_cell_voltage) / 10000.0) + 0;
    conversion->min_cell_voltage = (((primary_float32)min_cell_voltage) / 10000.0) + 0;
}

void primary_raw_to_conversion_struct_HV_VOLTAGE(
    primary_message_HV_VOLTAGE_conversion* conversion,
    primary_message_HV_VOLTAGE* raw
){
#ifdef CANLIB_TIMESTAMP
    conversion->_timestamp = raw->_timestamp;
#endif // CANLIB_TIMESTAMP
    conversion->pack_voltage = (((primary_float32)raw->pack_voltage) / 142.467391) + 0;
    conversion->bus_voltage = (((primary_float32)raw->bus_voltage) / 142.467391) + 0;
    conversion->max_cell_voltage = (((primary_float32)raw->max_cell_voltage) / 10000.0) + 0;
    conversion->min_cell_voltage = (((primary_float32)raw->min_cell_voltage) / 10000.0) + 0;
}

void primary_conversion_to_raw_HV_VOLTAGE(
    primary_message_HV_VOLTAGE* raw,
    primary_float32 pack_voltage,
    primary_float32 bus_voltage,
    primary_float32 max_cell_voltage,
    primary_float32 min_cell_voltage
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
){
#ifdef CANLIB_TIMESTAMP
    raw->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    raw->pack_voltage = (primary_uint16)((pack_voltage + 0) * 142.467391);
    raw->bus_voltage = (primary_uint16)((bus_voltage + 0) * 142.467391);
    raw->max_cell_voltage = (primary_uint16)((max_cell_voltage + 0) * 10000.0);
    raw->min_cell_voltage = (primary_uint16)((min_cell_voltage + 0) * 10000.0);
}

void primary_conversion_to_raw_struct_HV_VOLTAGE(
    primary_message_HV_VOLTAGE* raw,
    primary_message_HV_VOLTAGE_conversion* conversion
){
#ifdef CANLIB_TIMESTAMP
    raw->_timestamp = conversion->_timestamp;
#endif // CANLIB_TIMESTAMP
    raw->pack_voltage = (primary_uint16)((conversion->pack_voltage + 0) * 142.467391);
    raw->bus_voltage = (primary_uint16)((conversion->bus_voltage + 0) * 142.467391);
    raw->max_cell_voltage = (primary_uint16)((conversion->max_cell_voltage + 0) * 10000.0);
    raw->min_cell_voltage = (primary_uint16)((conversion->min_cell_voltage + 0) * 10000.0);
}

// ============== STRING ============== //
int primary_to_string_HV_VOLTAGE(primary_message_HV_VOLTAGE_conversion* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->pack_voltage,
        message->bus_voltage,
        message->max_cell_voltage,
        message->min_cell_voltage
    );
}

int primary_fields_HV_VOLTAGE(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "pack_voltage" CANLIB_SEPARATOR 
        "bus_voltage" CANLIB_SEPARATOR 
        "max_cell_voltage" CANLIB_SEPARATOR 
        "min_cell_voltage"
    );
}

int primary_to_string_file_HV_VOLTAGE(primary_message_HV_VOLTAGE_conversion* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->pack_voltage,
        message->bus_voltage,
        message->max_cell_voltage,
        message->min_cell_voltage
    );
}

int primary_fields_file_HV_VOLTAGE(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "pack_voltage" CANLIB_SEPARATOR 
        "bus_voltage" CANLIB_SEPARATOR 
        "max_cell_voltage" CANLIB_SEPARATOR 
        "min_cell_voltage"
    );
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_HV_CURRENT(
    uint8_t* data,
    primary_uint16 current,
    primary_uint16 power,
    primary_uint16 energy,
    primary_uint8 soc
) {
    data[0] = current & 255;
    data[1] = (current >> 8) & 255;
    data[2] = power & 255;
    data[3] = (power >> 8) & 255;
    data[4] = energy & 255;
    data[5] = (energy >> 8) & 255;
    data[6] = soc;
    return 7;
}

primary_byte_size primary_serialize_struct_HV_CURRENT(
    uint8_t* data,
    primary_message_HV_CURRENT* message
) {
    data[0] = message->current & 255;
    data[1] = (message->current >> 8) & 255;
    data[2] = message->power & 255;
    data[3] = (message->power >> 8) & 255;
    data[4] = message->energy & 255;
    data[5] = (message->energy >> 8) & 255;
    data[6] = message->soc;
    return 7;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_HV_CURRENT(
    primary_message_HV_CURRENT* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->current = data[0] | (data[1] << 8);
    message->power = data[2] | (data[3] << 8);
    message->energy = data[4] | (data[5] << 8);
    message->soc = data[6];
}// ============== CONVERSION ============== //

void primary_raw_to_conversion_HV_CURRENT(
    primary_message_HV_CURRENT_conversion* conversion,
    primary_uint16 current,
    primary_uint16 power,
    primary_uint16 energy,
    primary_uint8 soc
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
){
#ifdef CANLIB_TIMESTAMP
    conversion->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    conversion->current = (((primary_float32)current) / 312.071429) - 10;
    conversion->power = (((primary_float32)power) / 655.35) + 0;
    conversion->energy = (((primary_float32)energy) / 9.362143) + 0;
    conversion->soc = (((primary_float32)soc) / 2.55) + 0;
}

void primary_raw_to_conversion_struct_HV_CURRENT(
    primary_message_HV_CURRENT_conversion* conversion,
    primary_message_HV_CURRENT* raw
){
#ifdef CANLIB_TIMESTAMP
    conversion->_timestamp = raw->_timestamp;
#endif // CANLIB_TIMESTAMP
    conversion->current = (((primary_float32)raw->current) / 312.071429) - 10;
    conversion->power = (((primary_float32)raw->power) / 655.35) + 0;
    conversion->energy = (((primary_float32)raw->energy) / 9.362143) + 0;
    conversion->soc = (((primary_float32)raw->soc) / 2.55) + 0;
}

void primary_conversion_to_raw_HV_CURRENT(
    primary_message_HV_CURRENT* raw,
    primary_float32 current,
    primary_float32 power,
    primary_float32 energy,
    primary_float32 soc
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
){
#ifdef CANLIB_TIMESTAMP
    raw->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    raw->current = (primary_uint16)((current + 10) * 312.071429);
    raw->power = (primary_uint16)((power + 0) * 655.35);
    raw->energy = (primary_uint16)((energy + 0) * 9.362143);
    raw->soc = (primary_uint8)((soc + 0) * 2.55);
}

void primary_conversion_to_raw_struct_HV_CURRENT(
    primary_message_HV_CURRENT* raw,
    primary_message_HV_CURRENT_conversion* conversion
){
#ifdef CANLIB_TIMESTAMP
    raw->_timestamp = conversion->_timestamp;
#endif // CANLIB_TIMESTAMP
    raw->current = (primary_uint16)((conversion->current + 10) * 312.071429);
    raw->power = (primary_uint16)((conversion->power + 0) * 655.35);
    raw->energy = (primary_uint16)((conversion->energy + 0) * 9.362143);
    raw->soc = (primary_uint8)((conversion->soc + 0) * 2.55);
}

// ============== STRING ============== //
int primary_to_string_HV_CURRENT(primary_message_HV_CURRENT_conversion* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->current,
        message->power,
        message->energy,
        message->soc
    );
}

int primary_fields_HV_CURRENT(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "current" CANLIB_SEPARATOR 
        "power" CANLIB_SEPARATOR 
        "energy" CANLIB_SEPARATOR 
        "soc"
    );
}

int primary_to_string_file_HV_CURRENT(primary_message_HV_CURRENT_conversion* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->current,
        message->power,
        message->energy,
        message->soc
    );
}

int primary_fields_file_HV_CURRENT(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "current" CANLIB_SEPARATOR 
        "power" CANLIB_SEPARATOR 
        "energy" CANLIB_SEPARATOR 
        "soc"
    );
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_HV_TEMP(
    uint8_t* data,
    primary_uint8 average_temp,
    primary_uint8 max_temp,
    primary_uint8 min_temp
) {
    data[0] = average_temp;
    data[1] = max_temp;
    data[2] = min_temp;
    return 3;
}

primary_byte_size primary_serialize_struct_HV_TEMP(
    uint8_t* data,
    primary_message_HV_TEMP* message
) {
    data[0] = message->average_temp;
    data[1] = message->max_temp;
    data[2] = message->min_temp;
    return 3;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_HV_TEMP(
    primary_message_HV_TEMP* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->average_temp = data[0];
    message->max_temp = data[1];
    message->min_temp = data[2];
}// ============== CONVERSION ============== //

void primary_raw_to_conversion_HV_TEMP(
    primary_message_HV_TEMP_conversion* conversion,
    primary_uint8 average_temp,
    primary_uint8 max_temp,
    primary_uint8 min_temp
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
){
#ifdef CANLIB_TIMESTAMP
    conversion->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    conversion->average_temp = (((primary_float32)average_temp) / 2.55) - 20;
    conversion->max_temp = (((primary_float32)max_temp) / 2.55) - 20;
    conversion->min_temp = (((primary_float32)min_temp) / 2.55) - 20;
}

void primary_raw_to_conversion_struct_HV_TEMP(
    primary_message_HV_TEMP_conversion* conversion,
    primary_message_HV_TEMP* raw
){
#ifdef CANLIB_TIMESTAMP
    conversion->_timestamp = raw->_timestamp;
#endif // CANLIB_TIMESTAMP
    conversion->average_temp = (((primary_float32)raw->average_temp) / 2.55) - 20;
    conversion->max_temp = (((primary_float32)raw->max_temp) / 2.55) - 20;
    conversion->min_temp = (((primary_float32)raw->min_temp) / 2.55) - 20;
}

void primary_conversion_to_raw_HV_TEMP(
    primary_message_HV_TEMP* raw,
    primary_float32 average_temp,
    primary_float32 max_temp,
    primary_float32 min_temp
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
){
#ifdef CANLIB_TIMESTAMP
    raw->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    raw->average_temp = (primary_uint8)((average_temp + 20) * 2.55);
    raw->max_temp = (primary_uint8)((max_temp + 20) * 2.55);
    raw->min_temp = (primary_uint8)((min_temp + 20) * 2.55);
}

void primary_conversion_to_raw_struct_HV_TEMP(
    primary_message_HV_TEMP* raw,
    primary_message_HV_TEMP_conversion* conversion
){
#ifdef CANLIB_TIMESTAMP
    raw->_timestamp = conversion->_timestamp;
#endif // CANLIB_TIMESTAMP
    raw->average_temp = (primary_uint8)((conversion->average_temp + 20) * 2.55);
    raw->max_temp = (primary_uint8)((conversion->max_temp + 20) * 2.55);
    raw->min_temp = (primary_uint8)((conversion->min_temp + 20) * 2.55);
}

// ============== STRING ============== //
int primary_to_string_HV_TEMP(primary_message_HV_TEMP_conversion* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->average_temp,
        message->max_temp,
        message->min_temp
    );
}

int primary_fields_HV_TEMP(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "average_temp" CANLIB_SEPARATOR 
        "max_temp" CANLIB_SEPARATOR 
        "min_temp"
    );
}

int primary_to_string_file_HV_TEMP(primary_message_HV_TEMP_conversion* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->average_temp,
        message->max_temp,
        message->min_temp
    );
}

int primary_fields_file_HV_TEMP(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "average_temp" CANLIB_SEPARATOR 
        "max_temp" CANLIB_SEPARATOR 
        "min_temp"
    );
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_HV_ERRORS(
    uint8_t* data,
    primary_HvErrors warnings,
    primary_HvErrors errors
) {
    data[0] = warnings & 255;
    data[1] = (warnings >> 8) & 255;
    data[2] = errors & 255;
    data[3] = (errors >> 8) & 255;
    return 4;
}

primary_byte_size primary_serialize_struct_HV_ERRORS(
    uint8_t* data,
    primary_message_HV_ERRORS* message
) {
    data[0] = message->warnings & 255;
    data[1] = (message->warnings >> 8) & 255;
    data[2] = message->errors & 255;
    data[3] = (message->errors >> 8) & 255;
    return 4;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_HV_ERRORS(
    primary_message_HV_ERRORS* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->warnings = data[0] | (data[1] << 8);
    message->errors = data[2] | (data[3] << 8);
}

// ============== STRING ============== //

int primary_to_string_HV_ERRORS(primary_message_HV_ERRORS* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->warnings,
        message->errors
    );
}

int primary_fields_HV_ERRORS(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "warnings" CANLIB_SEPARATOR 
        "errors"
    );
}

int primary_to_string_file_HV_ERRORS(primary_message_HV_ERRORS* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->warnings,
        message->errors
    );
}

int primary_fields_file_HV_ERRORS(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "warnings" CANLIB_SEPARATOR 
        "errors"
    );
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_HV_CAN_FORWARD(
    uint8_t* data,
    primary_Toggle can_forward_set
) {
    data[0] = can_forward_set << 7;
    return 1;
}

primary_byte_size primary_serialize_struct_HV_CAN_FORWARD(
    uint8_t* data,
    primary_message_HV_CAN_FORWARD* message
) {
    data[0] = message->can_forward_set << 7;
    return 1;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_HV_CAN_FORWARD(
    primary_message_HV_CAN_FORWARD* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->can_forward_set = (primary_Toggle) ((data[0] & 128) >> 7);
}

// ============== STRING ============== //

int primary_to_string_HV_CAN_FORWARD(primary_message_HV_CAN_FORWARD* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->can_forward_set
    );
}

int primary_fields_HV_CAN_FORWARD(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "can_forward_set"
    );
}

int primary_to_string_file_HV_CAN_FORWARD(primary_message_HV_CAN_FORWARD* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->can_forward_set
    );
}

int primary_fields_file_HV_CAN_FORWARD(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "can_forward_set"
    );
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_HV_FANS_OVERRIDE(
    uint8_t* data,
    primary_Toggle fans_override,
    primary_uint16 fans_speed
) {
    data[0] = fans_speed & 255;
    data[1] = (fans_speed >> 8) & 255;
    data[2] = fans_override << 7;
    return 3;
}

primary_byte_size primary_serialize_struct_HV_FANS_OVERRIDE(
    uint8_t* data,
    primary_message_HV_FANS_OVERRIDE* message
) {
    data[0] = message->fans_speed & 255;
    data[1] = (message->fans_speed >> 8) & 255;
    data[2] = message->fans_override << 7;
    return 3;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_HV_FANS_OVERRIDE(
    primary_message_HV_FANS_OVERRIDE* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->fans_speed = data[0] | (data[1] << 8);
    message->fans_override = (primary_Toggle) ((data[2] & 128) >> 7);
}// ============== CONVERSION ============== //

void primary_raw_to_conversion_HV_FANS_OVERRIDE(
    primary_message_HV_FANS_OVERRIDE_conversion* conversion,
    primary_Toggle fans_override,
    primary_uint16 fans_speed
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
){
#ifdef CANLIB_TIMESTAMP
    conversion->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    conversion->fans_override = fans_override;
    conversion->fans_speed = (((primary_float32)fans_speed) / 65535.0) + 0;
}

void primary_raw_to_conversion_struct_HV_FANS_OVERRIDE(
    primary_message_HV_FANS_OVERRIDE_conversion* conversion,
    primary_message_HV_FANS_OVERRIDE* raw
){
#ifdef CANLIB_TIMESTAMP
    conversion->_timestamp = raw->_timestamp;
#endif // CANLIB_TIMESTAMP
    conversion->fans_override = raw->fans_override;
    conversion->fans_speed = (((primary_float32)raw->fans_speed) / 65535.0) + 0;
}

void primary_conversion_to_raw_HV_FANS_OVERRIDE(
    primary_message_HV_FANS_OVERRIDE* raw,
    primary_Toggle fans_override,
    primary_float32 fans_speed
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
){
#ifdef CANLIB_TIMESTAMP
    raw->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    raw->fans_override = fans_override;
    raw->fans_speed = (primary_uint16)((fans_speed + 0) * 65535.0);
}

void primary_conversion_to_raw_struct_HV_FANS_OVERRIDE(
    primary_message_HV_FANS_OVERRIDE* raw,
    primary_message_HV_FANS_OVERRIDE_conversion* conversion
){
#ifdef CANLIB_TIMESTAMP
    raw->_timestamp = conversion->_timestamp;
#endif // CANLIB_TIMESTAMP
    raw->fans_override = conversion->fans_override;
    raw->fans_speed = (primary_uint16)((conversion->fans_speed + 0) * 65535.0);
}

// ============== STRING ============== //
int primary_to_string_HV_FANS_OVERRIDE(primary_message_HV_FANS_OVERRIDE_conversion* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIf32,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->fans_override,
        message->fans_speed
    );
}

int primary_fields_HV_FANS_OVERRIDE(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "fans_override" CANLIB_SEPARATOR 
        "fans_speed"
    );
}

int primary_to_string_file_HV_FANS_OVERRIDE(primary_message_HV_FANS_OVERRIDE_conversion* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIf32,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->fans_override,
        message->fans_speed
    );
}

int primary_fields_file_HV_FANS_OVERRIDE(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "fans_override" CANLIB_SEPARATOR 
        "fans_speed"
    );
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_HV_CAN_FORWARD_STATUS(
    uint8_t* data,
    primary_Toggle can_forward_status
) {
    data[0] = can_forward_status << 7;
    return 1;
}

primary_byte_size primary_serialize_struct_HV_CAN_FORWARD_STATUS(
    uint8_t* data,
    primary_message_HV_CAN_FORWARD_STATUS* message
) {
    data[0] = message->can_forward_status << 7;
    return 1;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_HV_CAN_FORWARD_STATUS(
    primary_message_HV_CAN_FORWARD_STATUS* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->can_forward_status = (primary_Toggle) ((data[0] & 128) >> 7);
}

// ============== STRING ============== //

int primary_to_string_HV_CAN_FORWARD_STATUS(primary_message_HV_CAN_FORWARD_STATUS* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->can_forward_status
    );
}

int primary_fields_HV_CAN_FORWARD_STATUS(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "can_forward_status"
    );
}

int primary_to_string_file_HV_CAN_FORWARD_STATUS(primary_message_HV_CAN_FORWARD_STATUS* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->can_forward_status
    );
}

int primary_fields_file_HV_CAN_FORWARD_STATUS(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "can_forward_status"
    );
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_HV_FANS_OVERRIDE_STATUS(
    uint8_t* data,
    primary_Toggle fans_override,
    primary_uint16 fans_speed
) {
    data[0] = fans_speed & 255;
    data[1] = (fans_speed >> 8) & 255;
    data[2] = fans_override << 7;
    return 3;
}

primary_byte_size primary_serialize_struct_HV_FANS_OVERRIDE_STATUS(
    uint8_t* data,
    primary_message_HV_FANS_OVERRIDE_STATUS* message
) {
    data[0] = message->fans_speed & 255;
    data[1] = (message->fans_speed >> 8) & 255;
    data[2] = message->fans_override << 7;
    return 3;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_HV_FANS_OVERRIDE_STATUS(
    primary_message_HV_FANS_OVERRIDE_STATUS* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->fans_speed = data[0] | (data[1] << 8);
    message->fans_override = (primary_Toggle) ((data[2] & 128) >> 7);
}// ============== CONVERSION ============== //

void primary_raw_to_conversion_HV_FANS_OVERRIDE_STATUS(
    primary_message_HV_FANS_OVERRIDE_STATUS_conversion* conversion,
    primary_Toggle fans_override,
    primary_uint16 fans_speed
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
){
#ifdef CANLIB_TIMESTAMP
    conversion->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    conversion->fans_override = fans_override;
    conversion->fans_speed = (((primary_float32)fans_speed) / 65535.0) + 0;
}

void primary_raw_to_conversion_struct_HV_FANS_OVERRIDE_STATUS(
    primary_message_HV_FANS_OVERRIDE_STATUS_conversion* conversion,
    primary_message_HV_FANS_OVERRIDE_STATUS* raw
){
#ifdef CANLIB_TIMESTAMP
    conversion->_timestamp = raw->_timestamp;
#endif // CANLIB_TIMESTAMP
    conversion->fans_override = raw->fans_override;
    conversion->fans_speed = (((primary_float32)raw->fans_speed) / 65535.0) + 0;
}

void primary_conversion_to_raw_HV_FANS_OVERRIDE_STATUS(
    primary_message_HV_FANS_OVERRIDE_STATUS* raw,
    primary_Toggle fans_override,
    primary_float32 fans_speed
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
){
#ifdef CANLIB_TIMESTAMP
    raw->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    raw->fans_override = fans_override;
    raw->fans_speed = (primary_uint16)((fans_speed + 0) * 65535.0);
}

void primary_conversion_to_raw_struct_HV_FANS_OVERRIDE_STATUS(
    primary_message_HV_FANS_OVERRIDE_STATUS* raw,
    primary_message_HV_FANS_OVERRIDE_STATUS_conversion* conversion
){
#ifdef CANLIB_TIMESTAMP
    raw->_timestamp = conversion->_timestamp;
#endif // CANLIB_TIMESTAMP
    raw->fans_override = conversion->fans_override;
    raw->fans_speed = (primary_uint16)((conversion->fans_speed + 0) * 65535.0);
}

// ============== STRING ============== //
int primary_to_string_HV_FANS_OVERRIDE_STATUS(primary_message_HV_FANS_OVERRIDE_STATUS_conversion* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIf32,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->fans_override,
        message->fans_speed
    );
}

int primary_fields_HV_FANS_OVERRIDE_STATUS(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "fans_override" CANLIB_SEPARATOR 
        "fans_speed"
    );
}

int primary_to_string_file_HV_FANS_OVERRIDE_STATUS(primary_message_HV_FANS_OVERRIDE_STATUS_conversion* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIf32,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->fans_override,
        message->fans_speed
    );
}

int primary_fields_file_HV_FANS_OVERRIDE_STATUS(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "fans_override" CANLIB_SEPARATOR 
        "fans_speed"
    );
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_HV_FEEDBACKS_STATUS(
    uint8_t* data,
    primary_HvFeedbacks feedbacks_status,
    primary_HvFeedbacks is_circuitry_error
) {
    data[0] = feedbacks_status & 255;
    data[1] = (feedbacks_status >> 8) & 255;
    data[2] = (feedbacks_status >> 16) & 255;
    data[3] = is_circuitry_error & 255;
    data[4] = (is_circuitry_error >> 8) & 255;
    data[5] = (is_circuitry_error >> 16) & 255;
    return 6;
}

primary_byte_size primary_serialize_struct_HV_FEEDBACKS_STATUS(
    uint8_t* data,
    primary_message_HV_FEEDBACKS_STATUS* message
) {
    data[0] = message->feedbacks_status & 255;
    data[1] = (message->feedbacks_status >> 8) & 255;
    data[2] = (message->feedbacks_status >> 16) & 255;
    data[3] = message->is_circuitry_error & 255;
    data[4] = (message->is_circuitry_error >> 8) & 255;
    data[5] = (message->is_circuitry_error >> 16) & 255;
    return 6;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_HV_FEEDBACKS_STATUS(
    primary_message_HV_FEEDBACKS_STATUS* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->feedbacks_status = data[0] | (data[1] << 8) | (data[2] << 16);
    message->is_circuitry_error = data[3] | (data[4] << 8) | (data[5] << 16);
}

// ============== STRING ============== //

int primary_to_string_HV_FEEDBACKS_STATUS(primary_message_HV_FEEDBACKS_STATUS* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu32 CANLIB_SEPARATOR 
        "%" PRIu32,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->feedbacks_status,
        message->is_circuitry_error
    );
}

int primary_fields_HV_FEEDBACKS_STATUS(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "feedbacks_status" CANLIB_SEPARATOR 
        "is_circuitry_error"
    );
}

int primary_to_string_file_HV_FEEDBACKS_STATUS(primary_message_HV_FEEDBACKS_STATUS* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu32 CANLIB_SEPARATOR 
        "%" PRIu32,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->feedbacks_status,
        message->is_circuitry_error
    );
}

int primary_fields_file_HV_FEEDBACKS_STATUS(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "feedbacks_status" CANLIB_SEPARATOR 
        "is_circuitry_error"
    );
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_HV_IMD_STATUS(
    uint8_t* data,
    primary_bool imd_fault,
    primary_ImdStatus imd_status,
    primary_int32 imd_info
) {
    data[0] = imd_info & 255;
    data[1] = (imd_info >> 8) & 255;
    data[2] = (imd_info >> 16) & 255;
    data[3] = (imd_info >> 24) & 255;
    data[4] = imd_status << 5 | imd_fault << 4;
    return 5;
}

primary_byte_size primary_serialize_struct_HV_IMD_STATUS(
    uint8_t* data,
    primary_message_HV_IMD_STATUS* message
) {
    data[0] = message->imd_info & 255;
    data[1] = (message->imd_info >> 8) & 255;
    data[2] = (message->imd_info >> 16) & 255;
    data[3] = (message->imd_info >> 24) & 255;
    data[4] = message->imd_status << 5 | message->imd_fault << 4;
    return 5;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_HV_IMD_STATUS(
    primary_message_HV_IMD_STATUS* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->imd_info = data[0] | (data[1] << 8) | (data[2] << 16) | (data[3] << 24);
    message->imd_status = (primary_ImdStatus) ((data[4] & 224) >> 5);
    message->imd_fault = (data[4] & 16) >> 4;
}

// ============== STRING ============== //

int primary_to_string_HV_IMD_STATUS(primary_message_HV_IMD_STATUS* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIi32,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->imd_fault,
        message->imd_status,
        message->imd_info
    );
}

int primary_fields_HV_IMD_STATUS(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "imd_fault" CANLIB_SEPARATOR 
        "imd_status" CANLIB_SEPARATOR 
        "imd_info"
    );
}

int primary_to_string_file_HV_IMD_STATUS(primary_message_HV_IMD_STATUS* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIi32,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->imd_fault,
        message->imd_status,
        message->imd_info
    );
}

int primary_fields_file_HV_IMD_STATUS(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "imd_fault" CANLIB_SEPARATOR 
        "imd_status" CANLIB_SEPARATOR 
        "imd_info"
    );
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_TS_STATUS(
    uint8_t* data,
    primary_TsStatus ts_status
) {
    data[0] = ts_status << 6;
    return 1;
}

primary_byte_size primary_serialize_struct_TS_STATUS(
    uint8_t* data,
    primary_message_TS_STATUS* message
) {
    data[0] = message->ts_status << 6;
    return 1;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_TS_STATUS(
    primary_message_TS_STATUS* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->ts_status = (primary_TsStatus) ((data[0] & 192) >> 6);
}

// ============== STRING ============== //

int primary_to_string_TS_STATUS(primary_message_TS_STATUS* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->ts_status
    );
}

int primary_fields_TS_STATUS(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "ts_status"
    );
}

int primary_to_string_file_TS_STATUS(primary_message_TS_STATUS* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->ts_status
    );
}

int primary_fields_file_TS_STATUS(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "ts_status"
    );
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_SET_TS_STATUS(
    uint8_t* data,
    primary_Toggle ts_status_set
) {
    data[0] = ts_status_set << 7;
    return 1;
}

primary_byte_size primary_serialize_struct_SET_TS_STATUS(
    uint8_t* data,
    primary_message_SET_TS_STATUS* message
) {
    data[0] = message->ts_status_set << 7;
    return 1;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_SET_TS_STATUS(
    primary_message_SET_TS_STATUS* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->ts_status_set = (primary_Toggle) ((data[0] & 128) >> 7);
}

// ============== STRING ============== //

int primary_to_string_SET_TS_STATUS(primary_message_SET_TS_STATUS* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->ts_status_set
    );
}

int primary_fields_SET_TS_STATUS(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "ts_status_set"
    );
}

int primary_to_string_file_SET_TS_STATUS(primary_message_SET_TS_STATUS* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->ts_status_set
    );
}

int primary_fields_file_SET_TS_STATUS(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "ts_status_set"
    );
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_STEER_STATUS(
    uint8_t* data,
    primary_TractionControl traction_control,
    primary_Map map
) {
    data[0] = map << 5 | traction_control << 3;
    return 1;
}

primary_byte_size primary_serialize_struct_STEER_STATUS(
    uint8_t* data,
    primary_message_STEER_STATUS* message
) {
    data[0] = message->map << 5 | message->traction_control << 3;
    return 1;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_STEER_STATUS(
    primary_message_STEER_STATUS* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->map = (primary_Map) ((data[0] & 224) >> 5);
    message->traction_control = (primary_TractionControl) ((data[0] & 24) >> 3);
}

// ============== STRING ============== //

int primary_to_string_STEER_STATUS(primary_message_STEER_STATUS* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->traction_control,
        message->map
    );
}

int primary_fields_STEER_STATUS(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "traction_control" CANLIB_SEPARATOR 
        "map"
    );
}

int primary_to_string_file_STEER_STATUS(primary_message_STEER_STATUS* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->traction_control,
        message->map
    );
}

int primary_fields_file_STEER_STATUS(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "traction_control" CANLIB_SEPARATOR 
        "map"
    );
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_SET_CAR_STATUS(
    uint8_t* data,
    primary_SetCarStatus car_status_set
) {
    data[0] = car_status_set << 6;
    return 1;
}

primary_byte_size primary_serialize_struct_SET_CAR_STATUS(
    uint8_t* data,
    primary_message_SET_CAR_STATUS* message
) {
    data[0] = message->car_status_set << 6;
    return 1;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_SET_CAR_STATUS(
    primary_message_SET_CAR_STATUS* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->car_status_set = (primary_SetCarStatus) ((data[0] & 192) >> 6);
}

// ============== STRING ============== //

int primary_to_string_SET_CAR_STATUS(primary_message_SET_CAR_STATUS* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->car_status_set
    );
}

int primary_fields_SET_CAR_STATUS(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "car_status_set"
    );
}

int primary_to_string_file_SET_CAR_STATUS(primary_message_SET_CAR_STATUS* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->car_status_set
    );
}

int primary_fields_file_SET_CAR_STATUS(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "car_status_set"
    );
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_SET_PEDALS_RANGE(
    uint8_t* data,
    primary_Bound bound,
    primary_Pedal pedal
) {
    data[0] = bound << 7 | pedal << 6;
    return 1;
}

primary_byte_size primary_serialize_struct_SET_PEDALS_RANGE(
    uint8_t* data,
    primary_message_SET_PEDALS_RANGE* message
) {
    data[0] = message->bound << 7 | message->pedal << 6;
    return 1;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_SET_PEDALS_RANGE(
    primary_message_SET_PEDALS_RANGE* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->bound = (primary_Bound) ((data[0] & 128) >> 7);
    message->pedal = (primary_Pedal) ((data[0] & 64) >> 6);
}

// ============== STRING ============== //

int primary_to_string_SET_PEDALS_RANGE(primary_message_SET_PEDALS_RANGE* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->bound,
        message->pedal
    );
}

int primary_fields_SET_PEDALS_RANGE(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "bound" CANLIB_SEPARATOR 
        "pedal"
    );
}

int primary_to_string_file_SET_PEDALS_RANGE(primary_message_SET_PEDALS_RANGE* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->bound,
        message->pedal
    );
}

int primary_fields_file_SET_PEDALS_RANGE(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "bound" CANLIB_SEPARATOR 
        "pedal"
    );
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_SET_STEERING_ANGLE_RANGE(
    uint8_t* data,
    primary_Bound bound
) {
    data[0] = bound << 7;
    return 1;
}

primary_byte_size primary_serialize_struct_SET_STEERING_ANGLE_RANGE(
    uint8_t* data,
    primary_message_SET_STEERING_ANGLE_RANGE* message
) {
    data[0] = message->bound << 7;
    return 1;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_SET_STEERING_ANGLE_RANGE(
    primary_message_SET_STEERING_ANGLE_RANGE* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->bound = (primary_Bound) ((data[0] & 128) >> 7);
}

// ============== STRING ============== //

int primary_to_string_SET_STEERING_ANGLE_RANGE(primary_message_SET_STEERING_ANGLE_RANGE* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->bound
    );
}

int primary_fields_SET_STEERING_ANGLE_RANGE(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "bound"
    );
}

int primary_to_string_file_SET_STEERING_ANGLE_RANGE(primary_message_SET_STEERING_ANGLE_RANGE* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->bound
    );
}

int primary_fields_file_SET_STEERING_ANGLE_RANGE(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "bound"
    );
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_CAR_STATUS(
    uint8_t* data,
    primary_InverterStatus inverter_l,
    primary_InverterStatus inverter_r,
    primary_CarStatus car_status
) {
    data[0] = car_status << 5 | inverter_l << 3 | inverter_r << 1;
    return 1;
}

primary_byte_size primary_serialize_struct_CAR_STATUS(
    uint8_t* data,
    primary_message_CAR_STATUS* message
) {
    data[0] = message->car_status << 5 | message->inverter_l << 3 | message->inverter_r << 1;
    return 1;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_CAR_STATUS(
    primary_message_CAR_STATUS* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->car_status = (primary_CarStatus) ((data[0] & 224) >> 5);
    message->inverter_l = (primary_InverterStatus) ((data[0] & 24) >> 3);
    message->inverter_r = (primary_InverterStatus) ((data[0] & 6) >> 1);
}

// ============== STRING ============== //

int primary_to_string_CAR_STATUS(primary_message_CAR_STATUS* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->inverter_l,
        message->inverter_r,
        message->car_status
    );
}

int primary_fields_CAR_STATUS(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "inverter_l" CANLIB_SEPARATOR 
        "inverter_r" CANLIB_SEPARATOR 
        "car_status"
    );
}

int primary_to_string_file_CAR_STATUS(primary_message_CAR_STATUS* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->inverter_l,
        message->inverter_r,
        message->car_status
    );
}

int primary_fields_file_CAR_STATUS(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "inverter_l" CANLIB_SEPARATOR 
        "inverter_r" CANLIB_SEPARATOR 
        "car_status"
    );
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_DAS_ERRORS(
    uint8_t* data,
    primary_DasErrors das_error
) {
    data[0] = das_error & 255;
    data[1] = (das_error >> 8) & 255;
    return 2;
}

primary_byte_size primary_serialize_struct_DAS_ERRORS(
    uint8_t* data,
    primary_message_DAS_ERRORS* message
) {
    data[0] = message->das_error & 255;
    data[1] = (message->das_error >> 8) & 255;
    return 2;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_DAS_ERRORS(
    primary_message_DAS_ERRORS* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->das_error = data[0] | (data[1] << 8);
}

// ============== STRING ============== //

int primary_to_string_DAS_ERRORS(primary_message_DAS_ERRORS* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu16,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->das_error
    );
}

int primary_fields_DAS_ERRORS(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "das_error"
    );
}

int primary_to_string_file_DAS_ERRORS(primary_message_DAS_ERRORS* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu16,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->das_error
    );
}

int primary_fields_file_DAS_ERRORS(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "das_error"
    );
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_LV_CURRENT(
    uint8_t* data,
    primary_uint16 current
) {
    data[0] = current & 255;
    data[1] = (current >> 8) & 255;
    return 2;
}

primary_byte_size primary_serialize_struct_LV_CURRENT(
    uint8_t* data,
    primary_message_LV_CURRENT* message
) {
    data[0] = message->current & 255;
    data[1] = (message->current >> 8) & 255;
    return 2;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_LV_CURRENT(
    primary_message_LV_CURRENT* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->current = data[0] | (data[1] << 8);
}// ============== CONVERSION ============== //

void primary_raw_to_conversion_LV_CURRENT(
    primary_message_LV_CURRENT_conversion* conversion,
    primary_uint16 current
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
){
#ifdef CANLIB_TIMESTAMP
    conversion->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    conversion->current = (((primary_float32)current) / 1092.25) - 10;
}

void primary_raw_to_conversion_struct_LV_CURRENT(
    primary_message_LV_CURRENT_conversion* conversion,
    primary_message_LV_CURRENT* raw
){
#ifdef CANLIB_TIMESTAMP
    conversion->_timestamp = raw->_timestamp;
#endif // CANLIB_TIMESTAMP
    conversion->current = (((primary_float32)raw->current) / 1092.25) - 10;
}

void primary_conversion_to_raw_LV_CURRENT(
    primary_message_LV_CURRENT* raw,
    primary_float32 current
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
){
#ifdef CANLIB_TIMESTAMP
    raw->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    raw->current = (primary_uint16)((current + 10) * 1092.25);
}

void primary_conversion_to_raw_struct_LV_CURRENT(
    primary_message_LV_CURRENT* raw,
    primary_message_LV_CURRENT_conversion* conversion
){
#ifdef CANLIB_TIMESTAMP
    raw->_timestamp = conversion->_timestamp;
#endif // CANLIB_TIMESTAMP
    raw->current = (primary_uint16)((conversion->current + 10) * 1092.25);
}

// ============== STRING ============== //
int primary_to_string_LV_CURRENT(primary_message_LV_CURRENT_conversion* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIf32,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->current
    );
}

int primary_fields_LV_CURRENT(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "current"
    );
}

int primary_to_string_file_LV_CURRENT(primary_message_LV_CURRENT_conversion* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIf32,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->current
    );
}

int primary_fields_file_LV_CURRENT(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "current"
    );
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_LV_VOLTAGE(
    uint8_t* data,
    primary_uint16 voltage_1,
    primary_uint16 voltage_2,
    primary_uint16 voltage_3,
    primary_uint16 voltage_4
) {
    data[0] = voltage_1 & 255;
    data[1] = (voltage_1 >> 8) & 255;
    data[2] = voltage_2 & 255;
    data[3] = (voltage_2 >> 8) & 255;
    data[4] = voltage_3 & 255;
    data[5] = (voltage_3 >> 8) & 255;
    data[6] = voltage_4 & 255;
    data[7] = (voltage_4 >> 8) & 255;
    return 8;
}

primary_byte_size primary_serialize_struct_LV_VOLTAGE(
    uint8_t* data,
    primary_message_LV_VOLTAGE* message
) {
    data[0] = message->voltage_1 & 255;
    data[1] = (message->voltage_1 >> 8) & 255;
    data[2] = message->voltage_2 & 255;
    data[3] = (message->voltage_2 >> 8) & 255;
    data[4] = message->voltage_3 & 255;
    data[5] = (message->voltage_3 >> 8) & 255;
    data[6] = message->voltage_4 & 255;
    data[7] = (message->voltage_4 >> 8) & 255;
    return 8;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_LV_VOLTAGE(
    primary_message_LV_VOLTAGE* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->voltage_1 = data[0] | (data[1] << 8);
    message->voltage_2 = data[2] | (data[3] << 8);
    message->voltage_3 = data[4] | (data[5] << 8);
    message->voltage_4 = data[6] | (data[7] << 8);
}// ============== CONVERSION ============== //

void primary_raw_to_conversion_LV_VOLTAGE(
    primary_message_LV_VOLTAGE_conversion* conversion,
    primary_uint16 voltage_1,
    primary_uint16 voltage_2,
    primary_uint16 voltage_3,
    primary_uint16 voltage_4
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
){
#ifdef CANLIB_TIMESTAMP
    conversion->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    conversion->voltage_1 = (((primary_float32)voltage_1) / 10000.0) + 0;
    conversion->voltage_2 = (((primary_float32)voltage_2) / 10000.0) + 0;
    conversion->voltage_3 = (((primary_float32)voltage_3) / 10000.0) + 0;
    conversion->voltage_4 = (((primary_float32)voltage_4) / 10000.0) + 0;
}

void primary_raw_to_conversion_struct_LV_VOLTAGE(
    primary_message_LV_VOLTAGE_conversion* conversion,
    primary_message_LV_VOLTAGE* raw
){
#ifdef CANLIB_TIMESTAMP
    conversion->_timestamp = raw->_timestamp;
#endif // CANLIB_TIMESTAMP
    conversion->voltage_1 = (((primary_float32)raw->voltage_1) / 10000.0) + 0;
    conversion->voltage_2 = (((primary_float32)raw->voltage_2) / 10000.0) + 0;
    conversion->voltage_3 = (((primary_float32)raw->voltage_3) / 10000.0) + 0;
    conversion->voltage_4 = (((primary_float32)raw->voltage_4) / 10000.0) + 0;
}

void primary_conversion_to_raw_LV_VOLTAGE(
    primary_message_LV_VOLTAGE* raw,
    primary_float32 voltage_1,
    primary_float32 voltage_2,
    primary_float32 voltage_3,
    primary_float32 voltage_4
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
){
#ifdef CANLIB_TIMESTAMP
    raw->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    raw->voltage_1 = (primary_uint16)((voltage_1 + 0) * 10000.0);
    raw->voltage_2 = (primary_uint16)((voltage_2 + 0) * 10000.0);
    raw->voltage_3 = (primary_uint16)((voltage_3 + 0) * 10000.0);
    raw->voltage_4 = (primary_uint16)((voltage_4 + 0) * 10000.0);
}

void primary_conversion_to_raw_struct_LV_VOLTAGE(
    primary_message_LV_VOLTAGE* raw,
    primary_message_LV_VOLTAGE_conversion* conversion
){
#ifdef CANLIB_TIMESTAMP
    raw->_timestamp = conversion->_timestamp;
#endif // CANLIB_TIMESTAMP
    raw->voltage_1 = (primary_uint16)((conversion->voltage_1 + 0) * 10000.0);
    raw->voltage_2 = (primary_uint16)((conversion->voltage_2 + 0) * 10000.0);
    raw->voltage_3 = (primary_uint16)((conversion->voltage_3 + 0) * 10000.0);
    raw->voltage_4 = (primary_uint16)((conversion->voltage_4 + 0) * 10000.0);
}

// ============== STRING ============== //
int primary_to_string_LV_VOLTAGE(primary_message_LV_VOLTAGE_conversion* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->voltage_1,
        message->voltage_2,
        message->voltage_3,
        message->voltage_4
    );
}

int primary_fields_LV_VOLTAGE(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "voltage_1" CANLIB_SEPARATOR 
        "voltage_2" CANLIB_SEPARATOR 
        "voltage_3" CANLIB_SEPARATOR 
        "voltage_4"
    );
}

int primary_to_string_file_LV_VOLTAGE(primary_message_LV_VOLTAGE_conversion* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->voltage_1,
        message->voltage_2,
        message->voltage_3,
        message->voltage_4
    );
}

int primary_fields_file_LV_VOLTAGE(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "voltage_1" CANLIB_SEPARATOR 
        "voltage_2" CANLIB_SEPARATOR 
        "voltage_3" CANLIB_SEPARATOR 
        "voltage_4"
    );
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_LV_TOTAL_VOLTAGE(
    uint8_t* data,
    primary_uint32 total_voltage
) {
    data[0] = total_voltage & 255;
    data[1] = (total_voltage >> 8) & 255;
    data[2] = (total_voltage >> 16) & 255;
    data[3] = (total_voltage >> 24) & 255;
    return 4;
}

primary_byte_size primary_serialize_struct_LV_TOTAL_VOLTAGE(
    uint8_t* data,
    primary_message_LV_TOTAL_VOLTAGE* message
) {
    data[0] = message->total_voltage & 255;
    data[1] = (message->total_voltage >> 8) & 255;
    data[2] = (message->total_voltage >> 16) & 255;
    data[3] = (message->total_voltage >> 24) & 255;
    return 4;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_LV_TOTAL_VOLTAGE(
    primary_message_LV_TOTAL_VOLTAGE* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->total_voltage = data[0] | (data[1] << 8) | (data[2] << 16) | (data[3] << 24);
}// ============== CONVERSION ============== //

void primary_raw_to_conversion_LV_TOTAL_VOLTAGE(
    primary_message_LV_TOTAL_VOLTAGE_conversion* conversion,
    primary_uint32 total_voltage
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
){
#ifdef CANLIB_TIMESTAMP
    conversion->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    conversion->total_voltage = (((primary_float32)total_voltage) / 10000.0) + 0;
}

void primary_raw_to_conversion_struct_LV_TOTAL_VOLTAGE(
    primary_message_LV_TOTAL_VOLTAGE_conversion* conversion,
    primary_message_LV_TOTAL_VOLTAGE* raw
){
#ifdef CANLIB_TIMESTAMP
    conversion->_timestamp = raw->_timestamp;
#endif // CANLIB_TIMESTAMP
    conversion->total_voltage = (((primary_float32)raw->total_voltage) / 10000.0) + 0;
}

void primary_conversion_to_raw_LV_TOTAL_VOLTAGE(
    primary_message_LV_TOTAL_VOLTAGE* raw,
    primary_float32 total_voltage
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
){
#ifdef CANLIB_TIMESTAMP
    raw->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    raw->total_voltage = (primary_uint32)((total_voltage + 0) * 10000.0);
}

void primary_conversion_to_raw_struct_LV_TOTAL_VOLTAGE(
    primary_message_LV_TOTAL_VOLTAGE* raw,
    primary_message_LV_TOTAL_VOLTAGE_conversion* conversion
){
#ifdef CANLIB_TIMESTAMP
    raw->_timestamp = conversion->_timestamp;
#endif // CANLIB_TIMESTAMP
    raw->total_voltage = (primary_uint32)((conversion->total_voltage + 0) * 10000.0);
}

// ============== STRING ============== //
int primary_to_string_LV_TOTAL_VOLTAGE(primary_message_LV_TOTAL_VOLTAGE_conversion* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIf32,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->total_voltage
    );
}

int primary_fields_LV_TOTAL_VOLTAGE(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "total_voltage"
    );
}

int primary_to_string_file_LV_TOTAL_VOLTAGE(primary_message_LV_TOTAL_VOLTAGE_conversion* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIf32,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->total_voltage
    );
}

int primary_fields_file_LV_TOTAL_VOLTAGE(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "total_voltage"
    );
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_LV_TEMPERATURE(
    uint8_t* data,
    primary_uint16 bp_temperature_1,
    primary_uint16 bp_temperature_2,
    primary_uint16 dcdc12_temperature,
    primary_uint16 dcdc24_temperature
) {
    data[0] = bp_temperature_1 & 255;
    data[1] = (bp_temperature_1 >> 8) & 255;
    data[2] = bp_temperature_2 & 255;
    data[3] = (bp_temperature_2 >> 8) & 255;
    data[4] = dcdc12_temperature & 255;
    data[5] = (dcdc12_temperature >> 8) & 255;
    data[6] = dcdc24_temperature & 255;
    data[7] = (dcdc24_temperature >> 8) & 255;
    return 8;
}

primary_byte_size primary_serialize_struct_LV_TEMPERATURE(
    uint8_t* data,
    primary_message_LV_TEMPERATURE* message
) {
    data[0] = message->bp_temperature_1 & 255;
    data[1] = (message->bp_temperature_1 >> 8) & 255;
    data[2] = message->bp_temperature_2 & 255;
    data[3] = (message->bp_temperature_2 >> 8) & 255;
    data[4] = message->dcdc12_temperature & 255;
    data[5] = (message->dcdc12_temperature >> 8) & 255;
    data[6] = message->dcdc24_temperature & 255;
    data[7] = (message->dcdc24_temperature >> 8) & 255;
    return 8;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_LV_TEMPERATURE(
    primary_message_LV_TEMPERATURE* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->bp_temperature_1 = data[0] | (data[1] << 8);
    message->bp_temperature_2 = data[2] | (data[3] << 8);
    message->dcdc12_temperature = data[4] | (data[5] << 8);
    message->dcdc24_temperature = data[6] | (data[7] << 8);
}// ============== CONVERSION ============== //

void primary_raw_to_conversion_LV_TEMPERATURE(
    primary_message_LV_TEMPERATURE_conversion* conversion,
    primary_uint16 bp_temperature_1,
    primary_uint16 bp_temperature_2,
    primary_uint16 dcdc12_temperature,
    primary_uint16 dcdc24_temperature
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
){
#ifdef CANLIB_TIMESTAMP
    conversion->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    conversion->bp_temperature_1 = (((primary_float32)bp_temperature_1) / 655.35) - 20;
    conversion->bp_temperature_2 = (((primary_float32)bp_temperature_2) / 655.35) - 20;
    conversion->dcdc12_temperature = (((primary_float32)dcdc12_temperature) / 655.35) - 20;
    conversion->dcdc24_temperature = (((primary_float32)dcdc24_temperature) / 655.35) - 20;
}

void primary_raw_to_conversion_struct_LV_TEMPERATURE(
    primary_message_LV_TEMPERATURE_conversion* conversion,
    primary_message_LV_TEMPERATURE* raw
){
#ifdef CANLIB_TIMESTAMP
    conversion->_timestamp = raw->_timestamp;
#endif // CANLIB_TIMESTAMP
    conversion->bp_temperature_1 = (((primary_float32)raw->bp_temperature_1) / 655.35) - 20;
    conversion->bp_temperature_2 = (((primary_float32)raw->bp_temperature_2) / 655.35) - 20;
    conversion->dcdc12_temperature = (((primary_float32)raw->dcdc12_temperature) / 655.35) - 20;
    conversion->dcdc24_temperature = (((primary_float32)raw->dcdc24_temperature) / 655.35) - 20;
}

void primary_conversion_to_raw_LV_TEMPERATURE(
    primary_message_LV_TEMPERATURE* raw,
    primary_float32 bp_temperature_1,
    primary_float32 bp_temperature_2,
    primary_float32 dcdc12_temperature,
    primary_float32 dcdc24_temperature
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
){
#ifdef CANLIB_TIMESTAMP
    raw->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    raw->bp_temperature_1 = (primary_uint16)((bp_temperature_1 + 20) * 655.35);
    raw->bp_temperature_2 = (primary_uint16)((bp_temperature_2 + 20) * 655.35);
    raw->dcdc12_temperature = (primary_uint16)((dcdc12_temperature + 20) * 655.35);
    raw->dcdc24_temperature = (primary_uint16)((dcdc24_temperature + 20) * 655.35);
}

void primary_conversion_to_raw_struct_LV_TEMPERATURE(
    primary_message_LV_TEMPERATURE* raw,
    primary_message_LV_TEMPERATURE_conversion* conversion
){
#ifdef CANLIB_TIMESTAMP
    raw->_timestamp = conversion->_timestamp;
#endif // CANLIB_TIMESTAMP
    raw->bp_temperature_1 = (primary_uint16)((conversion->bp_temperature_1 + 20) * 655.35);
    raw->bp_temperature_2 = (primary_uint16)((conversion->bp_temperature_2 + 20) * 655.35);
    raw->dcdc12_temperature = (primary_uint16)((conversion->dcdc12_temperature + 20) * 655.35);
    raw->dcdc24_temperature = (primary_uint16)((conversion->dcdc24_temperature + 20) * 655.35);
}

// ============== STRING ============== //
int primary_to_string_LV_TEMPERATURE(primary_message_LV_TEMPERATURE_conversion* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->bp_temperature_1,
        message->bp_temperature_2,
        message->dcdc12_temperature,
        message->dcdc24_temperature
    );
}

int primary_fields_LV_TEMPERATURE(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "bp_temperature_1" CANLIB_SEPARATOR 
        "bp_temperature_2" CANLIB_SEPARATOR 
        "dcdc12_temperature" CANLIB_SEPARATOR 
        "dcdc24_temperature"
    );
}

int primary_to_string_file_LV_TEMPERATURE(primary_message_LV_TEMPERATURE_conversion* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->bp_temperature_1,
        message->bp_temperature_2,
        message->dcdc12_temperature,
        message->dcdc24_temperature
    );
}

int primary_fields_file_LV_TEMPERATURE(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "bp_temperature_1" CANLIB_SEPARATOR 
        "bp_temperature_2" CANLIB_SEPARATOR 
        "dcdc12_temperature" CANLIB_SEPARATOR 
        "dcdc24_temperature"
    );
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_COOLING_STATUS(
    uint8_t* data,
    primary_uint16 radiators_speed,
    primary_uint16 pumps_speed
) {
    data[0] = radiators_speed & 255;
    data[1] = (radiators_speed >> 8) & 255;
    data[2] = pumps_speed & 255;
    data[3] = (pumps_speed >> 8) & 255;
    return 4;
}

primary_byte_size primary_serialize_struct_COOLING_STATUS(
    uint8_t* data,
    primary_message_COOLING_STATUS* message
) {
    data[0] = message->radiators_speed & 255;
    data[1] = (message->radiators_speed >> 8) & 255;
    data[2] = message->pumps_speed & 255;
    data[3] = (message->pumps_speed >> 8) & 255;
    return 4;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_COOLING_STATUS(
    primary_message_COOLING_STATUS* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->radiators_speed = data[0] | (data[1] << 8);
    message->pumps_speed = data[2] | (data[3] << 8);
}// ============== CONVERSION ============== //

void primary_raw_to_conversion_COOLING_STATUS(
    primary_message_COOLING_STATUS_conversion* conversion,
    primary_uint16 radiators_speed,
    primary_uint16 pumps_speed
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
){
#ifdef CANLIB_TIMESTAMP
    conversion->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    conversion->radiators_speed = (((primary_float32)radiators_speed) / 32767.5) - 1;
    conversion->pumps_speed = (((primary_float32)pumps_speed) / 32767.5) - 1;
}

void primary_raw_to_conversion_struct_COOLING_STATUS(
    primary_message_COOLING_STATUS_conversion* conversion,
    primary_message_COOLING_STATUS* raw
){
#ifdef CANLIB_TIMESTAMP
    conversion->_timestamp = raw->_timestamp;
#endif // CANLIB_TIMESTAMP
    conversion->radiators_speed = (((primary_float32)raw->radiators_speed) / 32767.5) - 1;
    conversion->pumps_speed = (((primary_float32)raw->pumps_speed) / 32767.5) - 1;
}

void primary_conversion_to_raw_COOLING_STATUS(
    primary_message_COOLING_STATUS* raw,
    primary_float32 radiators_speed,
    primary_float32 pumps_speed
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
){
#ifdef CANLIB_TIMESTAMP
    raw->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    raw->radiators_speed = (primary_uint16)((radiators_speed + 1) * 32767.5);
    raw->pumps_speed = (primary_uint16)((pumps_speed + 1) * 32767.5);
}

void primary_conversion_to_raw_struct_COOLING_STATUS(
    primary_message_COOLING_STATUS* raw,
    primary_message_COOLING_STATUS_conversion* conversion
){
#ifdef CANLIB_TIMESTAMP
    raw->_timestamp = conversion->_timestamp;
#endif // CANLIB_TIMESTAMP
    raw->radiators_speed = (primary_uint16)((conversion->radiators_speed + 1) * 32767.5);
    raw->pumps_speed = (primary_uint16)((conversion->pumps_speed + 1) * 32767.5);
}

// ============== STRING ============== //
int primary_to_string_COOLING_STATUS(primary_message_COOLING_STATUS_conversion* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->radiators_speed,
        message->pumps_speed
    );
}

int primary_fields_COOLING_STATUS(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "radiators_speed" CANLIB_SEPARATOR 
        "pumps_speed"
    );
}

int primary_to_string_file_COOLING_STATUS(primary_message_COOLING_STATUS_conversion* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->radiators_speed,
        message->pumps_speed
    );
}

int primary_fields_file_COOLING_STATUS(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "radiators_speed" CANLIB_SEPARATOR 
        "pumps_speed"
    );
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_SET_RADIATOR_SPEED(
    uint8_t* data,
    primary_uint16 radiators_speed
) {
    data[0] = radiators_speed & 255;
    data[1] = (radiators_speed >> 8) & 255;
    return 2;
}

primary_byte_size primary_serialize_struct_SET_RADIATOR_SPEED(
    uint8_t* data,
    primary_message_SET_RADIATOR_SPEED* message
) {
    data[0] = message->radiators_speed & 255;
    data[1] = (message->radiators_speed >> 8) & 255;
    return 2;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_SET_RADIATOR_SPEED(
    primary_message_SET_RADIATOR_SPEED* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->radiators_speed = data[0] | (data[1] << 8);
}// ============== CONVERSION ============== //

void primary_raw_to_conversion_SET_RADIATOR_SPEED(
    primary_message_SET_RADIATOR_SPEED_conversion* conversion,
    primary_uint16 radiators_speed
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
){
#ifdef CANLIB_TIMESTAMP
    conversion->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    conversion->radiators_speed = (((primary_float32)radiators_speed) / 32767.5) - 1;
}

void primary_raw_to_conversion_struct_SET_RADIATOR_SPEED(
    primary_message_SET_RADIATOR_SPEED_conversion* conversion,
    primary_message_SET_RADIATOR_SPEED* raw
){
#ifdef CANLIB_TIMESTAMP
    conversion->_timestamp = raw->_timestamp;
#endif // CANLIB_TIMESTAMP
    conversion->radiators_speed = (((primary_float32)raw->radiators_speed) / 32767.5) - 1;
}

void primary_conversion_to_raw_SET_RADIATOR_SPEED(
    primary_message_SET_RADIATOR_SPEED* raw,
    primary_float32 radiators_speed
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
){
#ifdef CANLIB_TIMESTAMP
    raw->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    raw->radiators_speed = (primary_uint16)((radiators_speed + 1) * 32767.5);
}

void primary_conversion_to_raw_struct_SET_RADIATOR_SPEED(
    primary_message_SET_RADIATOR_SPEED* raw,
    primary_message_SET_RADIATOR_SPEED_conversion* conversion
){
#ifdef CANLIB_TIMESTAMP
    raw->_timestamp = conversion->_timestamp;
#endif // CANLIB_TIMESTAMP
    raw->radiators_speed = (primary_uint16)((conversion->radiators_speed + 1) * 32767.5);
}

// ============== STRING ============== //
int primary_to_string_SET_RADIATOR_SPEED(primary_message_SET_RADIATOR_SPEED_conversion* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIf32,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->radiators_speed
    );
}

int primary_fields_SET_RADIATOR_SPEED(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "radiators_speed"
    );
}

int primary_to_string_file_SET_RADIATOR_SPEED(primary_message_SET_RADIATOR_SPEED_conversion* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIf32,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->radiators_speed
    );
}

int primary_fields_file_SET_RADIATOR_SPEED(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "radiators_speed"
    );
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_SET_PUMPS_SPEED(
    uint8_t* data,
    primary_uint16 pumps_speed
) {
    data[0] = pumps_speed & 255;
    data[1] = (pumps_speed >> 8) & 255;
    return 2;
}

primary_byte_size primary_serialize_struct_SET_PUMPS_SPEED(
    uint8_t* data,
    primary_message_SET_PUMPS_SPEED* message
) {
    data[0] = message->pumps_speed & 255;
    data[1] = (message->pumps_speed >> 8) & 255;
    return 2;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_SET_PUMPS_SPEED(
    primary_message_SET_PUMPS_SPEED* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->pumps_speed = data[0] | (data[1] << 8);
}// ============== CONVERSION ============== //

void primary_raw_to_conversion_SET_PUMPS_SPEED(
    primary_message_SET_PUMPS_SPEED_conversion* conversion,
    primary_uint16 pumps_speed
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
){
#ifdef CANLIB_TIMESTAMP
    conversion->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    conversion->pumps_speed = (((primary_float32)pumps_speed) / 32767.5) - 1;
}

void primary_raw_to_conversion_struct_SET_PUMPS_SPEED(
    primary_message_SET_PUMPS_SPEED_conversion* conversion,
    primary_message_SET_PUMPS_SPEED* raw
){
#ifdef CANLIB_TIMESTAMP
    conversion->_timestamp = raw->_timestamp;
#endif // CANLIB_TIMESTAMP
    conversion->pumps_speed = (((primary_float32)raw->pumps_speed) / 32767.5) - 1;
}

void primary_conversion_to_raw_SET_PUMPS_SPEED(
    primary_message_SET_PUMPS_SPEED* raw,
    primary_float32 pumps_speed
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
){
#ifdef CANLIB_TIMESTAMP
    raw->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    raw->pumps_speed = (primary_uint16)((pumps_speed + 1) * 32767.5);
}

void primary_conversion_to_raw_struct_SET_PUMPS_SPEED(
    primary_message_SET_PUMPS_SPEED* raw,
    primary_message_SET_PUMPS_SPEED_conversion* conversion
){
#ifdef CANLIB_TIMESTAMP
    raw->_timestamp = conversion->_timestamp;
#endif // CANLIB_TIMESTAMP
    raw->pumps_speed = (primary_uint16)((conversion->pumps_speed + 1) * 32767.5);
}

// ============== STRING ============== //
int primary_to_string_SET_PUMPS_SPEED(primary_message_SET_PUMPS_SPEED_conversion* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIf32,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->pumps_speed
    );
}

int primary_fields_SET_PUMPS_SPEED(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "pumps_speed"
    );
}

int primary_to_string_file_SET_PUMPS_SPEED(primary_message_SET_PUMPS_SPEED_conversion* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIf32,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->pumps_speed
    );
}

int primary_fields_file_SET_PUMPS_SPEED(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "pumps_speed"
    );
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_SET_INVERTER_CONNECTION_STATUS(
    uint8_t* data,
    primary_Toggle status
) {
    data[0] = status << 7;
    return 1;
}

primary_byte_size primary_serialize_struct_SET_INVERTER_CONNECTION_STATUS(
    uint8_t* data,
    primary_message_SET_INVERTER_CONNECTION_STATUS* message
) {
    data[0] = message->status << 7;
    return 1;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_SET_INVERTER_CONNECTION_STATUS(
    primary_message_SET_INVERTER_CONNECTION_STATUS* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->status = (primary_Toggle) ((data[0] & 128) >> 7);
}

// ============== STRING ============== //

int primary_to_string_SET_INVERTER_CONNECTION_STATUS(primary_message_SET_INVERTER_CONNECTION_STATUS* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->status
    );
}

int primary_fields_SET_INVERTER_CONNECTION_STATUS(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "status"
    );
}

int primary_to_string_file_SET_INVERTER_CONNECTION_STATUS(primary_message_SET_INVERTER_CONNECTION_STATUS* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->status
    );
}

int primary_fields_file_SET_INVERTER_CONNECTION_STATUS(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "status"
    );
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_INVERTER_CONNECTION_STATUS(
    uint8_t* data,
    primary_Toggle status
) {
    data[0] = status << 7;
    return 1;
}

primary_byte_size primary_serialize_struct_INVERTER_CONNECTION_STATUS(
    uint8_t* data,
    primary_message_INVERTER_CONNECTION_STATUS* message
) {
    data[0] = message->status << 7;
    return 1;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_INVERTER_CONNECTION_STATUS(
    primary_message_INVERTER_CONNECTION_STATUS* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->status = (primary_Toggle) ((data[0] & 128) >> 7);
}

// ============== STRING ============== //

int primary_to_string_INVERTER_CONNECTION_STATUS(primary_message_INVERTER_CONNECTION_STATUS* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->status
    );
}

int primary_fields_INVERTER_CONNECTION_STATUS(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "status"
    );
}

int primary_to_string_file_INVERTER_CONNECTION_STATUS(primary_message_INVERTER_CONNECTION_STATUS* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->status
    );
}

int primary_fields_file_INVERTER_CONNECTION_STATUS(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "status"
    );
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_LV_ERRORS(
    uint8_t* data,
    primary_LvErrors warnings,
    primary_LvErrors errors
) {
    data[0] = warnings & 255;
    data[1] = (warnings >> 8) & 255;
    data[2] = (warnings >> 16) & 255;
    data[3] = errors & 255;
    data[4] = (errors >> 8) & 255;
    data[5] = (errors >> 16) & 255;
    return 6;
}

primary_byte_size primary_serialize_struct_LV_ERRORS(
    uint8_t* data,
    primary_message_LV_ERRORS* message
) {
    data[0] = message->warnings & 255;
    data[1] = (message->warnings >> 8) & 255;
    data[2] = (message->warnings >> 16) & 255;
    data[3] = message->errors & 255;
    data[4] = (message->errors >> 8) & 255;
    data[5] = (message->errors >> 16) & 255;
    return 6;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_LV_ERRORS(
    primary_message_LV_ERRORS* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->warnings = data[0] | (data[1] << 8) | (data[2] << 16);
    message->errors = data[3] | (data[4] << 8) | (data[5] << 16);
}

// ============== STRING ============== //

int primary_to_string_LV_ERRORS(primary_message_LV_ERRORS* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu32 CANLIB_SEPARATOR 
        "%" PRIu32,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->warnings,
        message->errors
    );
}

int primary_fields_LV_ERRORS(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "warnings" CANLIB_SEPARATOR 
        "errors"
    );
}

int primary_to_string_file_LV_ERRORS(primary_message_LV_ERRORS* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu32 CANLIB_SEPARATOR 
        "%" PRIu32,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->warnings,
        message->errors
    );
}

int primary_fields_file_LV_ERRORS(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "warnings" CANLIB_SEPARATOR 
        "errors"
    );
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_SHUTDOWN_STATUS(
    uint8_t* data,
    primary_bool input,
    primary_bool output
) {
    data[0] = input << 7 | output << 6;
    return 1;
}

primary_byte_size primary_serialize_struct_SHUTDOWN_STATUS(
    uint8_t* data,
    primary_message_SHUTDOWN_STATUS* message
) {
    data[0] = message->input << 7 | message->output << 6;
    return 1;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_SHUTDOWN_STATUS(
    primary_message_SHUTDOWN_STATUS* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->input = (data[0] & 128) >> 7;
    message->output = (data[0] & 64) >> 6;
}

// ============== STRING ============== //

int primary_to_string_SHUTDOWN_STATUS(primary_message_SHUTDOWN_STATUS* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->input,
        message->output
    );
}

int primary_fields_SHUTDOWN_STATUS(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "input" CANLIB_SEPARATOR 
        "output"
    );
}

int primary_to_string_file_SHUTDOWN_STATUS(primary_message_SHUTDOWN_STATUS* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->input,
        message->output
    );
}

int primary_fields_file_SHUTDOWN_STATUS(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "input" CANLIB_SEPARATOR 
        "output"
    );
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_MARKER(
    uint8_t* data
) {
    CANLIB_UNUSED(data);
    return 0;
}

primary_byte_size primary_serialize_struct_MARKER(
    uint8_t* data,
    primary_message_MARKER* message
) {
    CANLIB_UNUSED(data);
    CANLIB_UNUSED(message);
    return 0;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_MARKER(
    primary_message_MARKER* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(data);
#ifdef CANLIB_TIMESTAMP
    CANLIB_UNUSED(_timestamp);
#endif // CANLIB_TIMESTAMP
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
}

// ============== STRING ============== //

int primary_to_string_MARKER(primary_message_MARKER* message, char* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_fields_MARKER(char* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_to_string_file_MARKER(primary_message_MARKER* message, FILE* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_fields_file_MARKER(FILE* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_HV_CELLS_VOLTAGE(
    uint8_t* data,
    primary_uint8 start_index,
    primary_uint16 voltage_0,
    primary_uint16 voltage_1,
    primary_uint16 voltage_2
) {
    data[0] = voltage_0 & 255;
    data[1] = (voltage_0 >> 8) & 255;
    data[2] = voltage_1 & 255;
    data[3] = (voltage_1 >> 8) & 255;
    data[4] = voltage_2 & 255;
    data[5] = (voltage_2 >> 8) & 255;
    data[6] = start_index;
    return 7;
}

primary_byte_size primary_serialize_struct_HV_CELLS_VOLTAGE(
    uint8_t* data,
    primary_message_HV_CELLS_VOLTAGE* message
) {
    data[0] = message->voltage_0 & 255;
    data[1] = (message->voltage_0 >> 8) & 255;
    data[2] = message->voltage_1 & 255;
    data[3] = (message->voltage_1 >> 8) & 255;
    data[4] = message->voltage_2 & 255;
    data[5] = (message->voltage_2 >> 8) & 255;
    data[6] = message->start_index;
    return 7;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_HV_CELLS_VOLTAGE(
    primary_message_HV_CELLS_VOLTAGE* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->voltage_0 = data[0] | (data[1] << 8);
    message->voltage_1 = data[2] | (data[3] << 8);
    message->voltage_2 = data[4] | (data[5] << 8);
    message->start_index = data[6];
}// ============== CONVERSION ============== //

void primary_raw_to_conversion_HV_CELLS_VOLTAGE(
    primary_message_HV_CELLS_VOLTAGE_conversion* conversion,
    primary_uint8 start_index,
    primary_uint16 voltage_0,
    primary_uint16 voltage_1,
    primary_uint16 voltage_2
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
){
#ifdef CANLIB_TIMESTAMP
    conversion->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    conversion->start_index = start_index;
    conversion->voltage_0 = (((primary_float32)voltage_0) / 10000.0) + 0;
    conversion->voltage_1 = (((primary_float32)voltage_1) / 10000.0) + 0;
    conversion->voltage_2 = (((primary_float32)voltage_2) / 10000.0) + 0;
}

void primary_raw_to_conversion_struct_HV_CELLS_VOLTAGE(
    primary_message_HV_CELLS_VOLTAGE_conversion* conversion,
    primary_message_HV_CELLS_VOLTAGE* raw
){
#ifdef CANLIB_TIMESTAMP
    conversion->_timestamp = raw->_timestamp;
#endif // CANLIB_TIMESTAMP
    conversion->start_index = raw->start_index;
    conversion->voltage_0 = (((primary_float32)raw->voltage_0) / 10000.0) + 0;
    conversion->voltage_1 = (((primary_float32)raw->voltage_1) / 10000.0) + 0;
    conversion->voltage_2 = (((primary_float32)raw->voltage_2) / 10000.0) + 0;
}

void primary_conversion_to_raw_HV_CELLS_VOLTAGE(
    primary_message_HV_CELLS_VOLTAGE* raw,
    primary_uint8 start_index,
    primary_float32 voltage_0,
    primary_float32 voltage_1,
    primary_float32 voltage_2
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
){
#ifdef CANLIB_TIMESTAMP
    raw->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    raw->start_index = start_index;
    raw->voltage_0 = (primary_uint16)((voltage_0 + 0) * 10000.0);
    raw->voltage_1 = (primary_uint16)((voltage_1 + 0) * 10000.0);
    raw->voltage_2 = (primary_uint16)((voltage_2 + 0) * 10000.0);
}

void primary_conversion_to_raw_struct_HV_CELLS_VOLTAGE(
    primary_message_HV_CELLS_VOLTAGE* raw,
    primary_message_HV_CELLS_VOLTAGE_conversion* conversion
){
#ifdef CANLIB_TIMESTAMP
    raw->_timestamp = conversion->_timestamp;
#endif // CANLIB_TIMESTAMP
    raw->start_index = conversion->start_index;
    raw->voltage_0 = (primary_uint16)((conversion->voltage_0 + 0) * 10000.0);
    raw->voltage_1 = (primary_uint16)((conversion->voltage_1 + 0) * 10000.0);
    raw->voltage_2 = (primary_uint16)((conversion->voltage_2 + 0) * 10000.0);
}

// ============== STRING ============== //
int primary_to_string_HV_CELLS_VOLTAGE(primary_message_HV_CELLS_VOLTAGE_conversion* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->start_index,
        message->voltage_0,
        message->voltage_1,
        message->voltage_2
    );
}

int primary_fields_HV_CELLS_VOLTAGE(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "start_index" CANLIB_SEPARATOR 
        "voltage_0" CANLIB_SEPARATOR 
        "voltage_1" CANLIB_SEPARATOR 
        "voltage_2"
    );
}

int primary_to_string_file_HV_CELLS_VOLTAGE(primary_message_HV_CELLS_VOLTAGE_conversion* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->start_index,
        message->voltage_0,
        message->voltage_1,
        message->voltage_2
    );
}

int primary_fields_file_HV_CELLS_VOLTAGE(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "start_index" CANLIB_SEPARATOR 
        "voltage_0" CANLIB_SEPARATOR 
        "voltage_1" CANLIB_SEPARATOR 
        "voltage_2"
    );
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_HV_CELLS_TEMP(
    uint8_t* data,
    primary_uint8 start_index,
    primary_uint8 temp_0,
    primary_uint8 temp_1,
    primary_uint8 temp_2,
    primary_uint8 temp_3,
    primary_uint8 temp_4,
    primary_uint8 temp_5
) {
    data[0] = start_index;
    data[1] = temp_0;
    data[2] = temp_1;
    data[3] = temp_2;
    data[4] = temp_3;
    data[5] = temp_4;
    data[6] = temp_5;
    return 7;
}

primary_byte_size primary_serialize_struct_HV_CELLS_TEMP(
    uint8_t* data,
    primary_message_HV_CELLS_TEMP* message
) {
    data[0] = message->start_index;
    data[1] = message->temp_0;
    data[2] = message->temp_1;
    data[3] = message->temp_2;
    data[4] = message->temp_3;
    data[5] = message->temp_4;
    data[6] = message->temp_5;
    return 7;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_HV_CELLS_TEMP(
    primary_message_HV_CELLS_TEMP* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->start_index = data[0];
    message->temp_0 = data[1];
    message->temp_1 = data[2];
    message->temp_2 = data[3];
    message->temp_3 = data[4];
    message->temp_4 = data[5];
    message->temp_5 = data[6];
}// ============== CONVERSION ============== //

void primary_raw_to_conversion_HV_CELLS_TEMP(
    primary_message_HV_CELLS_TEMP_conversion* conversion,
    primary_uint8 start_index,
    primary_uint8 temp_0,
    primary_uint8 temp_1,
    primary_uint8 temp_2,
    primary_uint8 temp_3,
    primary_uint8 temp_4,
    primary_uint8 temp_5
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
){
#ifdef CANLIB_TIMESTAMP
    conversion->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    conversion->start_index = start_index;
    conversion->temp_0 = (((primary_float32)temp_0) / 2.55) - 20;
    conversion->temp_1 = (((primary_float32)temp_1) / 2.55) - 20;
    conversion->temp_2 = (((primary_float32)temp_2) / 2.55) - 20;
    conversion->temp_3 = (((primary_float32)temp_3) / 2.55) - 20;
    conversion->temp_4 = (((primary_float32)temp_4) / 2.55) - 20;
    conversion->temp_5 = (((primary_float32)temp_5) / 2.55) - 20;
}

void primary_raw_to_conversion_struct_HV_CELLS_TEMP(
    primary_message_HV_CELLS_TEMP_conversion* conversion,
    primary_message_HV_CELLS_TEMP* raw
){
#ifdef CANLIB_TIMESTAMP
    conversion->_timestamp = raw->_timestamp;
#endif // CANLIB_TIMESTAMP
    conversion->start_index = raw->start_index;
    conversion->temp_0 = (((primary_float32)raw->temp_0) / 2.55) - 20;
    conversion->temp_1 = (((primary_float32)raw->temp_1) / 2.55) - 20;
    conversion->temp_2 = (((primary_float32)raw->temp_2) / 2.55) - 20;
    conversion->temp_3 = (((primary_float32)raw->temp_3) / 2.55) - 20;
    conversion->temp_4 = (((primary_float32)raw->temp_4) / 2.55) - 20;
    conversion->temp_5 = (((primary_float32)raw->temp_5) / 2.55) - 20;
}

void primary_conversion_to_raw_HV_CELLS_TEMP(
    primary_message_HV_CELLS_TEMP* raw,
    primary_uint8 start_index,
    primary_float32 temp_0,
    primary_float32 temp_1,
    primary_float32 temp_2,
    primary_float32 temp_3,
    primary_float32 temp_4,
    primary_float32 temp_5
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
){
#ifdef CANLIB_TIMESTAMP
    raw->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    raw->start_index = start_index;
    raw->temp_0 = (primary_uint8)((temp_0 + 20) * 2.55);
    raw->temp_1 = (primary_uint8)((temp_1 + 20) * 2.55);
    raw->temp_2 = (primary_uint8)((temp_2 + 20) * 2.55);
    raw->temp_3 = (primary_uint8)((temp_3 + 20) * 2.55);
    raw->temp_4 = (primary_uint8)((temp_4 + 20) * 2.55);
    raw->temp_5 = (primary_uint8)((temp_5 + 20) * 2.55);
}

void primary_conversion_to_raw_struct_HV_CELLS_TEMP(
    primary_message_HV_CELLS_TEMP* raw,
    primary_message_HV_CELLS_TEMP_conversion* conversion
){
#ifdef CANLIB_TIMESTAMP
    raw->_timestamp = conversion->_timestamp;
#endif // CANLIB_TIMESTAMP
    raw->start_index = conversion->start_index;
    raw->temp_0 = (primary_uint8)((conversion->temp_0 + 20) * 2.55);
    raw->temp_1 = (primary_uint8)((conversion->temp_1 + 20) * 2.55);
    raw->temp_2 = (primary_uint8)((conversion->temp_2 + 20) * 2.55);
    raw->temp_3 = (primary_uint8)((conversion->temp_3 + 20) * 2.55);
    raw->temp_4 = (primary_uint8)((conversion->temp_4 + 20) * 2.55);
    raw->temp_5 = (primary_uint8)((conversion->temp_5 + 20) * 2.55);
}

// ============== STRING ============== //
int primary_to_string_HV_CELLS_TEMP(primary_message_HV_CELLS_TEMP_conversion* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->start_index,
        message->temp_0,
        message->temp_1,
        message->temp_2,
        message->temp_3,
        message->temp_4,
        message->temp_5
    );
}

int primary_fields_HV_CELLS_TEMP(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "start_index" CANLIB_SEPARATOR 
        "temp_0" CANLIB_SEPARATOR 
        "temp_1" CANLIB_SEPARATOR 
        "temp_2" CANLIB_SEPARATOR 
        "temp_3" CANLIB_SEPARATOR 
        "temp_4" CANLIB_SEPARATOR 
        "temp_5"
    );
}

int primary_to_string_file_HV_CELLS_TEMP(primary_message_HV_CELLS_TEMP_conversion* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->start_index,
        message->temp_0,
        message->temp_1,
        message->temp_2,
        message->temp_3,
        message->temp_4,
        message->temp_5
    );
}

int primary_fields_file_HV_CELLS_TEMP(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "start_index" CANLIB_SEPARATOR 
        "temp_0" CANLIB_SEPARATOR 
        "temp_1" CANLIB_SEPARATOR 
        "temp_2" CANLIB_SEPARATOR 
        "temp_3" CANLIB_SEPARATOR 
        "temp_4" CANLIB_SEPARATOR 
        "temp_5"
    );
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_HV_CELL_BALANCING_STATUS(
    uint8_t* data,
    primary_Toggle balancing_status
) {
    data[0] = balancing_status << 7;
    return 1;
}

primary_byte_size primary_serialize_struct_HV_CELL_BALANCING_STATUS(
    uint8_t* data,
    primary_message_HV_CELL_BALANCING_STATUS* message
) {
    data[0] = message->balancing_status << 7;
    return 1;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_HV_CELL_BALANCING_STATUS(
    primary_message_HV_CELL_BALANCING_STATUS* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->balancing_status = (primary_Toggle) ((data[0] & 128) >> 7);
}

// ============== STRING ============== //

int primary_to_string_HV_CELL_BALANCING_STATUS(primary_message_HV_CELL_BALANCING_STATUS* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->balancing_status
    );
}

int primary_fields_HV_CELL_BALANCING_STATUS(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "balancing_status"
    );
}

int primary_to_string_file_HV_CELL_BALANCING_STATUS(primary_message_HV_CELL_BALANCING_STATUS* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->balancing_status
    );
}

int primary_fields_file_HV_CELL_BALANCING_STATUS(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "balancing_status"
    );
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_SET_CELL_BALANCING_STATUS(
    uint8_t* data,
    primary_Toggle set_balancing_status
) {
    data[0] = set_balancing_status << 7;
    return 1;
}

primary_byte_size primary_serialize_struct_SET_CELL_BALANCING_STATUS(
    uint8_t* data,
    primary_message_SET_CELL_BALANCING_STATUS* message
) {
    data[0] = message->set_balancing_status << 7;
    return 1;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_SET_CELL_BALANCING_STATUS(
    primary_message_SET_CELL_BALANCING_STATUS* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->set_balancing_status = (primary_Toggle) ((data[0] & 128) >> 7);
}

// ============== STRING ============== //

int primary_to_string_SET_CELL_BALANCING_STATUS(primary_message_SET_CELL_BALANCING_STATUS* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->set_balancing_status
    );
}

int primary_fields_SET_CELL_BALANCING_STATUS(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "set_balancing_status"
    );
}

int primary_to_string_file_SET_CELL_BALANCING_STATUS(primary_message_SET_CELL_BALANCING_STATUS* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->set_balancing_status
    );
}

int primary_fields_file_SET_CELL_BALANCING_STATUS(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "set_balancing_status"
    );
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_HANDCART_STATUS(
    uint8_t* data,
    primary_bool connected
) {
    data[0] = connected << 7;
    return 1;
}

primary_byte_size primary_serialize_struct_HANDCART_STATUS(
    uint8_t* data,
    primary_message_HANDCART_STATUS* message
) {
    data[0] = message->connected << 7;
    return 1;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_HANDCART_STATUS(
    primary_message_HANDCART_STATUS* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->connected = (data[0] & 128) >> 7;
}

// ============== STRING ============== //

int primary_to_string_HANDCART_STATUS(primary_message_HANDCART_STATUS* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->connected
    );
}

int primary_fields_HANDCART_STATUS(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "connected"
    );
}

int primary_to_string_file_HANDCART_STATUS(primary_message_HANDCART_STATUS* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->connected
    );
}

int primary_fields_file_HANDCART_STATUS(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "connected"
    );
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_SPEED(
    uint8_t* data,
    primary_uint8 encoder_r,
    primary_uint8 encoder_l,
    primary_uint8 inverter_r,
    primary_uint8 inverter_l
) {
    data[0] = encoder_r;
    data[1] = encoder_l;
    data[2] = inverter_r;
    data[3] = inverter_l;
    return 4;
}

primary_byte_size primary_serialize_struct_SPEED(
    uint8_t* data,
    primary_message_SPEED* message
) {
    data[0] = message->encoder_r;
    data[1] = message->encoder_l;
    data[2] = message->inverter_r;
    data[3] = message->inverter_l;
    return 4;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_SPEED(
    primary_message_SPEED* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->encoder_r = data[0];
    message->encoder_l = data[1];
    message->inverter_r = data[2];
    message->inverter_l = data[3];
}// ============== CONVERSION ============== //

void primary_raw_to_conversion_SPEED(
    primary_message_SPEED_conversion* conversion,
    primary_uint8 encoder_r,
    primary_uint8 encoder_l,
    primary_uint8 inverter_r,
    primary_uint8 inverter_l
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
){
#ifdef CANLIB_TIMESTAMP
    conversion->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    conversion->encoder_r = (((primary_float32)encoder_r) / 0.728571) - 70;
    conversion->encoder_l = (((primary_float32)encoder_l) / 0.728571) - 70;
    conversion->inverter_r = (((primary_float32)inverter_r) / 0.728571) - 70;
    conversion->inverter_l = (((primary_float32)inverter_l) / 0.728571) - 70;
}

void primary_raw_to_conversion_struct_SPEED(
    primary_message_SPEED_conversion* conversion,
    primary_message_SPEED* raw
){
#ifdef CANLIB_TIMESTAMP
    conversion->_timestamp = raw->_timestamp;
#endif // CANLIB_TIMESTAMP
    conversion->encoder_r = (((primary_float32)raw->encoder_r) / 0.728571) - 70;
    conversion->encoder_l = (((primary_float32)raw->encoder_l) / 0.728571) - 70;
    conversion->inverter_r = (((primary_float32)raw->inverter_r) / 0.728571) - 70;
    conversion->inverter_l = (((primary_float32)raw->inverter_l) / 0.728571) - 70;
}

void primary_conversion_to_raw_SPEED(
    primary_message_SPEED* raw,
    primary_float32 encoder_r,
    primary_float32 encoder_l,
    primary_float32 inverter_r,
    primary_float32 inverter_l
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
){
#ifdef CANLIB_TIMESTAMP
    raw->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    raw->encoder_r = (primary_uint8)((encoder_r + 70) * 0.728571);
    raw->encoder_l = (primary_uint8)((encoder_l + 70) * 0.728571);
    raw->inverter_r = (primary_uint8)((inverter_r + 70) * 0.728571);
    raw->inverter_l = (primary_uint8)((inverter_l + 70) * 0.728571);
}

void primary_conversion_to_raw_struct_SPEED(
    primary_message_SPEED* raw,
    primary_message_SPEED_conversion* conversion
){
#ifdef CANLIB_TIMESTAMP
    raw->_timestamp = conversion->_timestamp;
#endif // CANLIB_TIMESTAMP
    raw->encoder_r = (primary_uint8)((conversion->encoder_r + 70) * 0.728571);
    raw->encoder_l = (primary_uint8)((conversion->encoder_l + 70) * 0.728571);
    raw->inverter_r = (primary_uint8)((conversion->inverter_r + 70) * 0.728571);
    raw->inverter_l = (primary_uint8)((conversion->inverter_l + 70) * 0.728571);
}

// ============== STRING ============== //
int primary_to_string_SPEED(primary_message_SPEED_conversion* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->encoder_r,
        message->encoder_l,
        message->inverter_r,
        message->inverter_l
    );
}

int primary_fields_SPEED(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "encoder_r" CANLIB_SEPARATOR 
        "encoder_l" CANLIB_SEPARATOR 
        "inverter_r" CANLIB_SEPARATOR 
        "inverter_l"
    );
}

int primary_to_string_file_SPEED(primary_message_SPEED_conversion* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->encoder_r,
        message->encoder_l,
        message->inverter_r,
        message->inverter_l
    );
}

int primary_fields_file_SPEED(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "encoder_r" CANLIB_SEPARATOR 
        "encoder_l" CANLIB_SEPARATOR 
        "inverter_r" CANLIB_SEPARATOR 
        "inverter_l"
    );
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_INV_L_REQUEST(
    uint8_t* data,
    primary_uint8 data_0,
    primary_uint8 data_1,
    primary_uint8 data_2,
    primary_uint8 data_3,
    primary_uint8 data_4,
    primary_uint8 data_5,
    primary_uint8 data_6,
    primary_uint8 data_7
) {
    data[0] = data_0;
    data[1] = data_1;
    data[2] = data_2;
    data[3] = data_3;
    data[4] = data_4;
    data[5] = data_5;
    data[6] = data_6;
    data[7] = data_7;
    return 8;
}

primary_byte_size primary_serialize_struct_INV_L_REQUEST(
    uint8_t* data,
    primary_message_INV_L_REQUEST* message
) {
    data[0] = message->data_0;
    data[1] = message->data_1;
    data[2] = message->data_2;
    data[3] = message->data_3;
    data[4] = message->data_4;
    data[5] = message->data_5;
    data[6] = message->data_6;
    data[7] = message->data_7;
    return 8;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_INV_L_REQUEST(
    primary_message_INV_L_REQUEST* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->data_0 = data[0];
    message->data_1 = data[1];
    message->data_2 = data[2];
    message->data_3 = data[3];
    message->data_4 = data[4];
    message->data_5 = data[5];
    message->data_6 = data[6];
    message->data_7 = data[7];
}

// ============== STRING ============== //

int primary_to_string_INV_L_REQUEST(primary_message_INV_L_REQUEST* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->data_0,
        message->data_1,
        message->data_2,
        message->data_3,
        message->data_4,
        message->data_5,
        message->data_6,
        message->data_7
    );
}

int primary_fields_INV_L_REQUEST(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "data_0" CANLIB_SEPARATOR 
        "data_1" CANLIB_SEPARATOR 
        "data_2" CANLIB_SEPARATOR 
        "data_3" CANLIB_SEPARATOR 
        "data_4" CANLIB_SEPARATOR 
        "data_5" CANLIB_SEPARATOR 
        "data_6" CANLIB_SEPARATOR 
        "data_7"
    );
}

int primary_to_string_file_INV_L_REQUEST(primary_message_INV_L_REQUEST* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->data_0,
        message->data_1,
        message->data_2,
        message->data_3,
        message->data_4,
        message->data_5,
        message->data_6,
        message->data_7
    );
}

int primary_fields_file_INV_L_REQUEST(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "data_0" CANLIB_SEPARATOR 
        "data_1" CANLIB_SEPARATOR 
        "data_2" CANLIB_SEPARATOR 
        "data_3" CANLIB_SEPARATOR 
        "data_4" CANLIB_SEPARATOR 
        "data_5" CANLIB_SEPARATOR 
        "data_6" CANLIB_SEPARATOR 
        "data_7"
    );
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_INV_R_REQUEST(
    uint8_t* data,
    primary_uint8 data_0,
    primary_uint8 data_1,
    primary_uint8 data_2,
    primary_uint8 data_3,
    primary_uint8 data_4,
    primary_uint8 data_5,
    primary_uint8 data_6,
    primary_uint8 data_7
) {
    data[0] = data_0;
    data[1] = data_1;
    data[2] = data_2;
    data[3] = data_3;
    data[4] = data_4;
    data[5] = data_5;
    data[6] = data_6;
    data[7] = data_7;
    return 8;
}

primary_byte_size primary_serialize_struct_INV_R_REQUEST(
    uint8_t* data,
    primary_message_INV_R_REQUEST* message
) {
    data[0] = message->data_0;
    data[1] = message->data_1;
    data[2] = message->data_2;
    data[3] = message->data_3;
    data[4] = message->data_4;
    data[5] = message->data_5;
    data[6] = message->data_6;
    data[7] = message->data_7;
    return 8;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_INV_R_REQUEST(
    primary_message_INV_R_REQUEST* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->data_0 = data[0];
    message->data_1 = data[1];
    message->data_2 = data[2];
    message->data_3 = data[3];
    message->data_4 = data[4];
    message->data_5 = data[5];
    message->data_6 = data[6];
    message->data_7 = data[7];
}

// ============== STRING ============== //

int primary_to_string_INV_R_REQUEST(primary_message_INV_R_REQUEST* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->data_0,
        message->data_1,
        message->data_2,
        message->data_3,
        message->data_4,
        message->data_5,
        message->data_6,
        message->data_7
    );
}

int primary_fields_INV_R_REQUEST(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "data_0" CANLIB_SEPARATOR 
        "data_1" CANLIB_SEPARATOR 
        "data_2" CANLIB_SEPARATOR 
        "data_3" CANLIB_SEPARATOR 
        "data_4" CANLIB_SEPARATOR 
        "data_5" CANLIB_SEPARATOR 
        "data_6" CANLIB_SEPARATOR 
        "data_7"
    );
}

int primary_to_string_file_INV_R_REQUEST(primary_message_INV_R_REQUEST* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->data_0,
        message->data_1,
        message->data_2,
        message->data_3,
        message->data_4,
        message->data_5,
        message->data_6,
        message->data_7
    );
}

int primary_fields_file_INV_R_REQUEST(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "data_0" CANLIB_SEPARATOR 
        "data_1" CANLIB_SEPARATOR 
        "data_2" CANLIB_SEPARATOR 
        "data_3" CANLIB_SEPARATOR 
        "data_4" CANLIB_SEPARATOR 
        "data_5" CANLIB_SEPARATOR 
        "data_6" CANLIB_SEPARATOR 
        "data_7"
    );
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_INV_L_RESPONSE(
    uint8_t* data,
    primary_uint8 reg_id,
    primary_uint8 data_0,
    primary_uint8 data_1,
    primary_uint8 data_2,
    primary_uint8 data_3,
    primary_uint8 data_4,
    primary_uint8 data_5,
    primary_uint8 data_6
) {
    data[0] = reg_id;
    data[1] = data_0;
    data[2] = data_1;
    data[3] = data_2;
    data[4] = data_3;
    data[5] = data_4;
    data[6] = data_5;
    data[7] = data_6;
    return 8;
}

primary_byte_size primary_serialize_struct_INV_L_RESPONSE(
    uint8_t* data,
    primary_message_INV_L_RESPONSE* message
) {
    data[0] = message->reg_id;
    data[1] = message->data_0;
    data[2] = message->data_1;
    data[3] = message->data_2;
    data[4] = message->data_3;
    data[5] = message->data_4;
    data[6] = message->data_5;
    data[7] = message->data_6;
    return 8;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_INV_L_RESPONSE(
    primary_message_INV_L_RESPONSE* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->reg_id = data[0];
    message->data_0 = data[1];
    message->data_1 = data[2];
    message->data_2 = data[3];
    message->data_3 = data[4];
    message->data_4 = data[5];
    message->data_5 = data[6];
    message->data_6 = data[7];
}

// ============== STRING ============== //

int primary_to_string_INV_L_RESPONSE(primary_message_INV_L_RESPONSE* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->reg_id,
        message->data_0,
        message->data_1,
        message->data_2,
        message->data_3,
        message->data_4,
        message->data_5,
        message->data_6
    );
}

int primary_fields_INV_L_RESPONSE(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "reg_id" CANLIB_SEPARATOR 
        "data_0" CANLIB_SEPARATOR 
        "data_1" CANLIB_SEPARATOR 
        "data_2" CANLIB_SEPARATOR 
        "data_3" CANLIB_SEPARATOR 
        "data_4" CANLIB_SEPARATOR 
        "data_5" CANLIB_SEPARATOR 
        "data_6"
    );
}

int primary_to_string_file_INV_L_RESPONSE(primary_message_INV_L_RESPONSE* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->reg_id,
        message->data_0,
        message->data_1,
        message->data_2,
        message->data_3,
        message->data_4,
        message->data_5,
        message->data_6
    );
}

int primary_fields_file_INV_L_RESPONSE(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "reg_id" CANLIB_SEPARATOR 
        "data_0" CANLIB_SEPARATOR 
        "data_1" CANLIB_SEPARATOR 
        "data_2" CANLIB_SEPARATOR 
        "data_3" CANLIB_SEPARATOR 
        "data_4" CANLIB_SEPARATOR 
        "data_5" CANLIB_SEPARATOR 
        "data_6"
    );
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_INV_R_RESPONSE(
    uint8_t* data,
    primary_uint8 reg_id,
    primary_uint8 data_0,
    primary_uint8 data_1,
    primary_uint8 data_2,
    primary_uint8 data_3,
    primary_uint8 data_4,
    primary_uint8 data_5,
    primary_uint8 data_6
) {
    data[0] = reg_id;
    data[1] = data_0;
    data[2] = data_1;
    data[3] = data_2;
    data[4] = data_3;
    data[5] = data_4;
    data[6] = data_5;
    data[7] = data_6;
    return 8;
}

primary_byte_size primary_serialize_struct_INV_R_RESPONSE(
    uint8_t* data,
    primary_message_INV_R_RESPONSE* message
) {
    data[0] = message->reg_id;
    data[1] = message->data_0;
    data[2] = message->data_1;
    data[3] = message->data_2;
    data[4] = message->data_3;
    data[5] = message->data_4;
    data[6] = message->data_5;
    data[7] = message->data_6;
    return 8;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_INV_R_RESPONSE(
    primary_message_INV_R_RESPONSE* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->reg_id = data[0];
    message->data_0 = data[1];
    message->data_1 = data[2];
    message->data_2 = data[3];
    message->data_3 = data[4];
    message->data_4 = data[5];
    message->data_5 = data[6];
    message->data_6 = data[7];
}

// ============== STRING ============== //

int primary_to_string_INV_R_RESPONSE(primary_message_INV_R_RESPONSE* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->reg_id,
        message->data_0,
        message->data_1,
        message->data_2,
        message->data_3,
        message->data_4,
        message->data_5,
        message->data_6
    );
}

int primary_fields_INV_R_RESPONSE(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "reg_id" CANLIB_SEPARATOR 
        "data_0" CANLIB_SEPARATOR 
        "data_1" CANLIB_SEPARATOR 
        "data_2" CANLIB_SEPARATOR 
        "data_3" CANLIB_SEPARATOR 
        "data_4" CANLIB_SEPARATOR 
        "data_5" CANLIB_SEPARATOR 
        "data_6"
    );
}

int primary_to_string_file_INV_R_RESPONSE(primary_message_INV_R_RESPONSE* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->reg_id,
        message->data_0,
        message->data_1,
        message->data_2,
        message->data_3,
        message->data_4,
        message->data_5,
        message->data_6
    );
}

int primary_fields_file_INV_R_RESPONSE(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "reg_id" CANLIB_SEPARATOR 
        "data_0" CANLIB_SEPARATOR 
        "data_1" CANLIB_SEPARATOR 
        "data_2" CANLIB_SEPARATOR 
        "data_3" CANLIB_SEPARATOR 
        "data_4" CANLIB_SEPARATOR 
        "data_5" CANLIB_SEPARATOR 
        "data_6"
    );
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_FLASH_CELLBOARD_0_TX(
    uint8_t* data
) {
    CANLIB_UNUSED(data);
    return 0;
}

primary_byte_size primary_serialize_struct_FLASH_CELLBOARD_0_TX(
    uint8_t* data,
    primary_message_FLASH_CELLBOARD_0_TX* message
) {
    CANLIB_UNUSED(data);
    CANLIB_UNUSED(message);
    return 0;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_FLASH_CELLBOARD_0_TX(
    primary_message_FLASH_CELLBOARD_0_TX* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(data);
#ifdef CANLIB_TIMESTAMP
    CANLIB_UNUSED(_timestamp);
#endif // CANLIB_TIMESTAMP
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
}

// ============== STRING ============== //

int primary_to_string_FLASH_CELLBOARD_0_TX(primary_message_FLASH_CELLBOARD_0_TX* message, char* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_fields_FLASH_CELLBOARD_0_TX(char* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_to_string_file_FLASH_CELLBOARD_0_TX(primary_message_FLASH_CELLBOARD_0_TX* message, FILE* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_fields_file_FLASH_CELLBOARD_0_TX(FILE* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_FLASH_CELLBOARD_0_RX(
    uint8_t* data
) {
    CANLIB_UNUSED(data);
    return 0;
}

primary_byte_size primary_serialize_struct_FLASH_CELLBOARD_0_RX(
    uint8_t* data,
    primary_message_FLASH_CELLBOARD_0_RX* message
) {
    CANLIB_UNUSED(data);
    CANLIB_UNUSED(message);
    return 0;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_FLASH_CELLBOARD_0_RX(
    primary_message_FLASH_CELLBOARD_0_RX* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(data);
#ifdef CANLIB_TIMESTAMP
    CANLIB_UNUSED(_timestamp);
#endif // CANLIB_TIMESTAMP
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
}

// ============== STRING ============== //

int primary_to_string_FLASH_CELLBOARD_0_RX(primary_message_FLASH_CELLBOARD_0_RX* message, char* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_fields_FLASH_CELLBOARD_0_RX(char* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_to_string_file_FLASH_CELLBOARD_0_RX(primary_message_FLASH_CELLBOARD_0_RX* message, FILE* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_fields_file_FLASH_CELLBOARD_0_RX(FILE* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_FLASH_CELLBOARD_1_TX(
    uint8_t* data
) {
    CANLIB_UNUSED(data);
    return 0;
}

primary_byte_size primary_serialize_struct_FLASH_CELLBOARD_1_TX(
    uint8_t* data,
    primary_message_FLASH_CELLBOARD_1_TX* message
) {
    CANLIB_UNUSED(data);
    CANLIB_UNUSED(message);
    return 0;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_FLASH_CELLBOARD_1_TX(
    primary_message_FLASH_CELLBOARD_1_TX* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(data);
#ifdef CANLIB_TIMESTAMP
    CANLIB_UNUSED(_timestamp);
#endif // CANLIB_TIMESTAMP
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
}

// ============== STRING ============== //

int primary_to_string_FLASH_CELLBOARD_1_TX(primary_message_FLASH_CELLBOARD_1_TX* message, char* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_fields_FLASH_CELLBOARD_1_TX(char* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_to_string_file_FLASH_CELLBOARD_1_TX(primary_message_FLASH_CELLBOARD_1_TX* message, FILE* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_fields_file_FLASH_CELLBOARD_1_TX(FILE* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_FLASH_CELLBOARD_1_RX(
    uint8_t* data
) {
    CANLIB_UNUSED(data);
    return 0;
}

primary_byte_size primary_serialize_struct_FLASH_CELLBOARD_1_RX(
    uint8_t* data,
    primary_message_FLASH_CELLBOARD_1_RX* message
) {
    CANLIB_UNUSED(data);
    CANLIB_UNUSED(message);
    return 0;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_FLASH_CELLBOARD_1_RX(
    primary_message_FLASH_CELLBOARD_1_RX* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(data);
#ifdef CANLIB_TIMESTAMP
    CANLIB_UNUSED(_timestamp);
#endif // CANLIB_TIMESTAMP
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
}

// ============== STRING ============== //

int primary_to_string_FLASH_CELLBOARD_1_RX(primary_message_FLASH_CELLBOARD_1_RX* message, char* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_fields_FLASH_CELLBOARD_1_RX(char* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_to_string_file_FLASH_CELLBOARD_1_RX(primary_message_FLASH_CELLBOARD_1_RX* message, FILE* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_fields_file_FLASH_CELLBOARD_1_RX(FILE* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_FLASH_CELLBOARD_2_TX(
    uint8_t* data
) {
    CANLIB_UNUSED(data);
    return 0;
}

primary_byte_size primary_serialize_struct_FLASH_CELLBOARD_2_TX(
    uint8_t* data,
    primary_message_FLASH_CELLBOARD_2_TX* message
) {
    CANLIB_UNUSED(data);
    CANLIB_UNUSED(message);
    return 0;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_FLASH_CELLBOARD_2_TX(
    primary_message_FLASH_CELLBOARD_2_TX* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(data);
#ifdef CANLIB_TIMESTAMP
    CANLIB_UNUSED(_timestamp);
#endif // CANLIB_TIMESTAMP
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
}

// ============== STRING ============== //

int primary_to_string_FLASH_CELLBOARD_2_TX(primary_message_FLASH_CELLBOARD_2_TX* message, char* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_fields_FLASH_CELLBOARD_2_TX(char* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_to_string_file_FLASH_CELLBOARD_2_TX(primary_message_FLASH_CELLBOARD_2_TX* message, FILE* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_fields_file_FLASH_CELLBOARD_2_TX(FILE* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_FLASH_CELLBOARD_2_RX(
    uint8_t* data
) {
    CANLIB_UNUSED(data);
    return 0;
}

primary_byte_size primary_serialize_struct_FLASH_CELLBOARD_2_RX(
    uint8_t* data,
    primary_message_FLASH_CELLBOARD_2_RX* message
) {
    CANLIB_UNUSED(data);
    CANLIB_UNUSED(message);
    return 0;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_FLASH_CELLBOARD_2_RX(
    primary_message_FLASH_CELLBOARD_2_RX* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(data);
#ifdef CANLIB_TIMESTAMP
    CANLIB_UNUSED(_timestamp);
#endif // CANLIB_TIMESTAMP
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
}

// ============== STRING ============== //

int primary_to_string_FLASH_CELLBOARD_2_RX(primary_message_FLASH_CELLBOARD_2_RX* message, char* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_fields_FLASH_CELLBOARD_2_RX(char* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_to_string_file_FLASH_CELLBOARD_2_RX(primary_message_FLASH_CELLBOARD_2_RX* message, FILE* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_fields_file_FLASH_CELLBOARD_2_RX(FILE* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_FLASH_CELLBOARD_3_TX(
    uint8_t* data
) {
    CANLIB_UNUSED(data);
    return 0;
}

primary_byte_size primary_serialize_struct_FLASH_CELLBOARD_3_TX(
    uint8_t* data,
    primary_message_FLASH_CELLBOARD_3_TX* message
) {
    CANLIB_UNUSED(data);
    CANLIB_UNUSED(message);
    return 0;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_FLASH_CELLBOARD_3_TX(
    primary_message_FLASH_CELLBOARD_3_TX* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(data);
#ifdef CANLIB_TIMESTAMP
    CANLIB_UNUSED(_timestamp);
#endif // CANLIB_TIMESTAMP
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
}

// ============== STRING ============== //

int primary_to_string_FLASH_CELLBOARD_3_TX(primary_message_FLASH_CELLBOARD_3_TX* message, char* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_fields_FLASH_CELLBOARD_3_TX(char* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_to_string_file_FLASH_CELLBOARD_3_TX(primary_message_FLASH_CELLBOARD_3_TX* message, FILE* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_fields_file_FLASH_CELLBOARD_3_TX(FILE* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_FLASH_CELLBOARD_3_RX(
    uint8_t* data
) {
    CANLIB_UNUSED(data);
    return 0;
}

primary_byte_size primary_serialize_struct_FLASH_CELLBOARD_3_RX(
    uint8_t* data,
    primary_message_FLASH_CELLBOARD_3_RX* message
) {
    CANLIB_UNUSED(data);
    CANLIB_UNUSED(message);
    return 0;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_FLASH_CELLBOARD_3_RX(
    primary_message_FLASH_CELLBOARD_3_RX* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(data);
#ifdef CANLIB_TIMESTAMP
    CANLIB_UNUSED(_timestamp);
#endif // CANLIB_TIMESTAMP
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
}

// ============== STRING ============== //

int primary_to_string_FLASH_CELLBOARD_3_RX(primary_message_FLASH_CELLBOARD_3_RX* message, char* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_fields_FLASH_CELLBOARD_3_RX(char* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_to_string_file_FLASH_CELLBOARD_3_RX(primary_message_FLASH_CELLBOARD_3_RX* message, FILE* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_fields_file_FLASH_CELLBOARD_3_RX(FILE* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_FLASH_CELLBOARD_4_TX(
    uint8_t* data
) {
    CANLIB_UNUSED(data);
    return 0;
}

primary_byte_size primary_serialize_struct_FLASH_CELLBOARD_4_TX(
    uint8_t* data,
    primary_message_FLASH_CELLBOARD_4_TX* message
) {
    CANLIB_UNUSED(data);
    CANLIB_UNUSED(message);
    return 0;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_FLASH_CELLBOARD_4_TX(
    primary_message_FLASH_CELLBOARD_4_TX* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(data);
#ifdef CANLIB_TIMESTAMP
    CANLIB_UNUSED(_timestamp);
#endif // CANLIB_TIMESTAMP
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
}

// ============== STRING ============== //

int primary_to_string_FLASH_CELLBOARD_4_TX(primary_message_FLASH_CELLBOARD_4_TX* message, char* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_fields_FLASH_CELLBOARD_4_TX(char* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_to_string_file_FLASH_CELLBOARD_4_TX(primary_message_FLASH_CELLBOARD_4_TX* message, FILE* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_fields_file_FLASH_CELLBOARD_4_TX(FILE* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_FLASH_CELLBOARD_4_RX(
    uint8_t* data
) {
    CANLIB_UNUSED(data);
    return 0;
}

primary_byte_size primary_serialize_struct_FLASH_CELLBOARD_4_RX(
    uint8_t* data,
    primary_message_FLASH_CELLBOARD_4_RX* message
) {
    CANLIB_UNUSED(data);
    CANLIB_UNUSED(message);
    return 0;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_FLASH_CELLBOARD_4_RX(
    primary_message_FLASH_CELLBOARD_4_RX* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(data);
#ifdef CANLIB_TIMESTAMP
    CANLIB_UNUSED(_timestamp);
#endif // CANLIB_TIMESTAMP
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
}

// ============== STRING ============== //

int primary_to_string_FLASH_CELLBOARD_4_RX(primary_message_FLASH_CELLBOARD_4_RX* message, char* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_fields_FLASH_CELLBOARD_4_RX(char* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_to_string_file_FLASH_CELLBOARD_4_RX(primary_message_FLASH_CELLBOARD_4_RX* message, FILE* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_fields_file_FLASH_CELLBOARD_4_RX(FILE* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_FLASH_CELLBOARD_5_TX(
    uint8_t* data
) {
    CANLIB_UNUSED(data);
    return 0;
}

primary_byte_size primary_serialize_struct_FLASH_CELLBOARD_5_TX(
    uint8_t* data,
    primary_message_FLASH_CELLBOARD_5_TX* message
) {
    CANLIB_UNUSED(data);
    CANLIB_UNUSED(message);
    return 0;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_FLASH_CELLBOARD_5_TX(
    primary_message_FLASH_CELLBOARD_5_TX* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(data);
#ifdef CANLIB_TIMESTAMP
    CANLIB_UNUSED(_timestamp);
#endif // CANLIB_TIMESTAMP
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
}

// ============== STRING ============== //

int primary_to_string_FLASH_CELLBOARD_5_TX(primary_message_FLASH_CELLBOARD_5_TX* message, char* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_fields_FLASH_CELLBOARD_5_TX(char* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_to_string_file_FLASH_CELLBOARD_5_TX(primary_message_FLASH_CELLBOARD_5_TX* message, FILE* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_fields_file_FLASH_CELLBOARD_5_TX(FILE* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_FLASH_CELLBOARD_5_RX(
    uint8_t* data
) {
    CANLIB_UNUSED(data);
    return 0;
}

primary_byte_size primary_serialize_struct_FLASH_CELLBOARD_5_RX(
    uint8_t* data,
    primary_message_FLASH_CELLBOARD_5_RX* message
) {
    CANLIB_UNUSED(data);
    CANLIB_UNUSED(message);
    return 0;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_FLASH_CELLBOARD_5_RX(
    primary_message_FLASH_CELLBOARD_5_RX* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(data);
#ifdef CANLIB_TIMESTAMP
    CANLIB_UNUSED(_timestamp);
#endif // CANLIB_TIMESTAMP
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
}

// ============== STRING ============== //

int primary_to_string_FLASH_CELLBOARD_5_RX(primary_message_FLASH_CELLBOARD_5_RX* message, char* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_fields_FLASH_CELLBOARD_5_RX(char* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_to_string_file_FLASH_CELLBOARD_5_RX(primary_message_FLASH_CELLBOARD_5_RX* message, FILE* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_fields_file_FLASH_CELLBOARD_5_RX(FILE* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_FLASH_BMS_HV_TX(
    uint8_t* data
) {
    CANLIB_UNUSED(data);
    return 0;
}

primary_byte_size primary_serialize_struct_FLASH_BMS_HV_TX(
    uint8_t* data,
    primary_message_FLASH_BMS_HV_TX* message
) {
    CANLIB_UNUSED(data);
    CANLIB_UNUSED(message);
    return 0;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_FLASH_BMS_HV_TX(
    primary_message_FLASH_BMS_HV_TX* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(data);
#ifdef CANLIB_TIMESTAMP
    CANLIB_UNUSED(_timestamp);
#endif // CANLIB_TIMESTAMP
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
}

// ============== STRING ============== //

int primary_to_string_FLASH_BMS_HV_TX(primary_message_FLASH_BMS_HV_TX* message, char* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_fields_FLASH_BMS_HV_TX(char* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_to_string_file_FLASH_BMS_HV_TX(primary_message_FLASH_BMS_HV_TX* message, FILE* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_fields_file_FLASH_BMS_HV_TX(FILE* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_FLASH_BMS_HV_RX(
    uint8_t* data
) {
    CANLIB_UNUSED(data);
    return 0;
}

primary_byte_size primary_serialize_struct_FLASH_BMS_HV_RX(
    uint8_t* data,
    primary_message_FLASH_BMS_HV_RX* message
) {
    CANLIB_UNUSED(data);
    CANLIB_UNUSED(message);
    return 0;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_FLASH_BMS_HV_RX(
    primary_message_FLASH_BMS_HV_RX* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(data);
#ifdef CANLIB_TIMESTAMP
    CANLIB_UNUSED(_timestamp);
#endif // CANLIB_TIMESTAMP
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
}

// ============== STRING ============== //

int primary_to_string_FLASH_BMS_HV_RX(primary_message_FLASH_BMS_HV_RX* message, char* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_fields_FLASH_BMS_HV_RX(char* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_to_string_file_FLASH_BMS_HV_RX(primary_message_FLASH_BMS_HV_RX* message, FILE* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_fields_file_FLASH_BMS_HV_RX(FILE* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_FLASH_BMS_LV_TX(
    uint8_t* data
) {
    CANLIB_UNUSED(data);
    return 0;
}

primary_byte_size primary_serialize_struct_FLASH_BMS_LV_TX(
    uint8_t* data,
    primary_message_FLASH_BMS_LV_TX* message
) {
    CANLIB_UNUSED(data);
    CANLIB_UNUSED(message);
    return 0;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_FLASH_BMS_LV_TX(
    primary_message_FLASH_BMS_LV_TX* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(data);
#ifdef CANLIB_TIMESTAMP
    CANLIB_UNUSED(_timestamp);
#endif // CANLIB_TIMESTAMP
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
}

// ============== STRING ============== //

int primary_to_string_FLASH_BMS_LV_TX(primary_message_FLASH_BMS_LV_TX* message, char* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_fields_FLASH_BMS_LV_TX(char* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_to_string_file_FLASH_BMS_LV_TX(primary_message_FLASH_BMS_LV_TX* message, FILE* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_fields_file_FLASH_BMS_LV_TX(FILE* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_FLASH_BMS_LV_RX(
    uint8_t* data
) {
    CANLIB_UNUSED(data);
    return 0;
}

primary_byte_size primary_serialize_struct_FLASH_BMS_LV_RX(
    uint8_t* data,
    primary_message_FLASH_BMS_LV_RX* message
) {
    CANLIB_UNUSED(data);
    CANLIB_UNUSED(message);
    return 0;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_FLASH_BMS_LV_RX(
    primary_message_FLASH_BMS_LV_RX* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(data);
#ifdef CANLIB_TIMESTAMP
    CANLIB_UNUSED(_timestamp);
#endif // CANLIB_TIMESTAMP
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
}

// ============== STRING ============== //

int primary_to_string_FLASH_BMS_LV_RX(primary_message_FLASH_BMS_LV_RX* message, char* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_fields_FLASH_BMS_LV_RX(char* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_to_string_file_FLASH_BMS_LV_RX(primary_message_FLASH_BMS_LV_RX* message, FILE* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_fields_file_FLASH_BMS_LV_RX(FILE* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_BRUSA_NLG5_CTL(
    uint8_t* data
) {
    CANLIB_UNUSED(data);
    return 0;
}

primary_byte_size primary_serialize_struct_BRUSA_NLG5_CTL(
    uint8_t* data,
    primary_message_BRUSA_NLG5_CTL* message
) {
    CANLIB_UNUSED(data);
    CANLIB_UNUSED(message);
    return 0;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_BRUSA_NLG5_CTL(
    primary_message_BRUSA_NLG5_CTL* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(data);
#ifdef CANLIB_TIMESTAMP
    CANLIB_UNUSED(_timestamp);
#endif // CANLIB_TIMESTAMP
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
}

// ============== STRING ============== //

int primary_to_string_BRUSA_NLG5_CTL(primary_message_BRUSA_NLG5_CTL* message, char* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_fields_BRUSA_NLG5_CTL(char* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_to_string_file_BRUSA_NLG5_CTL(primary_message_BRUSA_NLG5_CTL* message, FILE* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_fields_file_BRUSA_NLG5_CTL(FILE* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_BRUSA_ST(
    uint8_t* data
) {
    CANLIB_UNUSED(data);
    return 0;
}

primary_byte_size primary_serialize_struct_BRUSA_ST(
    uint8_t* data,
    primary_message_BRUSA_ST* message
) {
    CANLIB_UNUSED(data);
    CANLIB_UNUSED(message);
    return 0;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_BRUSA_ST(
    primary_message_BRUSA_ST* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(data);
#ifdef CANLIB_TIMESTAMP
    CANLIB_UNUSED(_timestamp);
#endif // CANLIB_TIMESTAMP
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
}

// ============== STRING ============== //

int primary_to_string_BRUSA_ST(primary_message_BRUSA_ST* message, char* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_fields_BRUSA_ST(char* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_to_string_file_BRUSA_ST(primary_message_BRUSA_ST* message, FILE* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_fields_file_BRUSA_ST(FILE* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_BRUSA_ACT_I(
    uint8_t* data
) {
    CANLIB_UNUSED(data);
    return 0;
}

primary_byte_size primary_serialize_struct_BRUSA_ACT_I(
    uint8_t* data,
    primary_message_BRUSA_ACT_I* message
) {
    CANLIB_UNUSED(data);
    CANLIB_UNUSED(message);
    return 0;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_BRUSA_ACT_I(
    primary_message_BRUSA_ACT_I* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(data);
#ifdef CANLIB_TIMESTAMP
    CANLIB_UNUSED(_timestamp);
#endif // CANLIB_TIMESTAMP
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
}

// ============== STRING ============== //

int primary_to_string_BRUSA_ACT_I(primary_message_BRUSA_ACT_I* message, char* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_fields_BRUSA_ACT_I(char* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_to_string_file_BRUSA_ACT_I(primary_message_BRUSA_ACT_I* message, FILE* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_fields_file_BRUSA_ACT_I(FILE* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_BRUSA_ACT_II(
    uint8_t* data
) {
    CANLIB_UNUSED(data);
    return 0;
}

primary_byte_size primary_serialize_struct_BRUSA_ACT_II(
    uint8_t* data,
    primary_message_BRUSA_ACT_II* message
) {
    CANLIB_UNUSED(data);
    CANLIB_UNUSED(message);
    return 0;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_BRUSA_ACT_II(
    primary_message_BRUSA_ACT_II* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(data);
#ifdef CANLIB_TIMESTAMP
    CANLIB_UNUSED(_timestamp);
#endif // CANLIB_TIMESTAMP
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
}

// ============== STRING ============== //

int primary_to_string_BRUSA_ACT_II(primary_message_BRUSA_ACT_II* message, char* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_fields_BRUSA_ACT_II(char* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_to_string_file_BRUSA_ACT_II(primary_message_BRUSA_ACT_II* message, FILE* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_fields_file_BRUSA_ACT_II(FILE* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_BRUSA_TEMP(
    uint8_t* data
) {
    CANLIB_UNUSED(data);
    return 0;
}

primary_byte_size primary_serialize_struct_BRUSA_TEMP(
    uint8_t* data,
    primary_message_BRUSA_TEMP* message
) {
    CANLIB_UNUSED(data);
    CANLIB_UNUSED(message);
    return 0;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_BRUSA_TEMP(
    primary_message_BRUSA_TEMP* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(data);
#ifdef CANLIB_TIMESTAMP
    CANLIB_UNUSED(_timestamp);
#endif // CANLIB_TIMESTAMP
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
}

// ============== STRING ============== //

int primary_to_string_BRUSA_TEMP(primary_message_BRUSA_TEMP* message, char* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_fields_BRUSA_TEMP(char* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_to_string_file_BRUSA_TEMP(primary_message_BRUSA_TEMP* message, FILE* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_fields_file_BRUSA_TEMP(FILE* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_BRUSA_ERR(
    uint8_t* data
) {
    CANLIB_UNUSED(data);
    return 0;
}

primary_byte_size primary_serialize_struct_BRUSA_ERR(
    uint8_t* data,
    primary_message_BRUSA_ERR* message
) {
    CANLIB_UNUSED(data);
    CANLIB_UNUSED(message);
    return 0;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_BRUSA_ERR(
    primary_message_BRUSA_ERR* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(data);
#ifdef CANLIB_TIMESTAMP
    CANLIB_UNUSED(_timestamp);
#endif // CANLIB_TIMESTAMP
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
}

// ============== STRING ============== //

int primary_to_string_BRUSA_ERR(primary_message_BRUSA_ERR* message, char* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_fields_BRUSA_ERR(char* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_to_string_file_BRUSA_ERR(primary_message_BRUSA_ERR* message, FILE* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_fields_file_BRUSA_ERR(FILE* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_BMS_HV_CHIMERA(
    uint8_t* data
) {
    CANLIB_UNUSED(data);
    return 0;
}

primary_byte_size primary_serialize_struct_BMS_HV_CHIMERA(
    uint8_t* data,
    primary_message_BMS_HV_CHIMERA* message
) {
    CANLIB_UNUSED(data);
    CANLIB_UNUSED(message);
    return 0;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_BMS_HV_CHIMERA(
    primary_message_BMS_HV_CHIMERA* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(data);
#ifdef CANLIB_TIMESTAMP
    CANLIB_UNUSED(_timestamp);
#endif // CANLIB_TIMESTAMP
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
}

// ============== STRING ============== //

int primary_to_string_BMS_HV_CHIMERA(primary_message_BMS_HV_CHIMERA* message, char* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_fields_BMS_HV_CHIMERA(char* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_to_string_file_BMS_HV_CHIMERA(primary_message_BMS_HV_CHIMERA* message, FILE* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_fields_file_BMS_HV_CHIMERA(FILE* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_ECU_CHIMERA(
    uint8_t* data
) {
    CANLIB_UNUSED(data);
    return 0;
}

primary_byte_size primary_serialize_struct_ECU_CHIMERA(
    uint8_t* data,
    primary_message_ECU_CHIMERA* message
) {
    CANLIB_UNUSED(data);
    CANLIB_UNUSED(message);
    return 0;
}

// ============== DESERIALIZE ============== //

void primary_deserialize_ECU_CHIMERA(
    primary_message_ECU_CHIMERA* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(data);
#ifdef CANLIB_TIMESTAMP
    CANLIB_UNUSED(_timestamp);
#endif // CANLIB_TIMESTAMP
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
}

// ============== STRING ============== //

int primary_to_string_ECU_CHIMERA(primary_message_ECU_CHIMERA* message, char* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_fields_ECU_CHIMERA(char* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_to_string_file_ECU_CHIMERA(primary_message_ECU_CHIMERA* message, FILE* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int primary_fields_file_ECU_CHIMERA(FILE* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}


// ============== UTILS ============== //

int primary_fields_from_id(canlib_message_id message_id, char* buffer) {
    switch (message_id) {
        case 0:
            return primary_fields_BMS_HV_JMP_TO_BLT(buffer);
        case 32:
            return primary_fields_BMS_LV_JMP_TO_BLT(buffer);
        case 1025:
            return primary_fields_STEER_VERSION(buffer);
        case 1057:
            return primary_fields_DAS_VERSION(buffer);
        case 1089:
            return primary_fields_HV_VERSION(buffer);
        case 1121:
            return primary_fields_LV_VERSION(buffer);
        case 1153:
            return primary_fields_TLM_VERSION(buffer);
        case 257:
            return primary_fields_TIMESTAMP(buffer);
        case 258:
            return primary_fields_SET_TLM_STATUS(buffer);
        case 259:
            return primary_fields_TLM_STATUS(buffer);
        case 1794:
            return primary_fields_STEER_SYSTEM_STATUS(buffer);
        case 772:
            return primary_fields_HV_VOLTAGE(buffer);
        case 804:
            return primary_fields_HV_CURRENT(buffer);
        case 836:
            return primary_fields_HV_TEMP(buffer);
        case 4:
            return primary_fields_HV_ERRORS(buffer);
        case 5:
            return primary_fields_HV_CAN_FORWARD(buffer);
        case 37:
            return primary_fields_HV_FANS_OVERRIDE(buffer);
        case 6:
            return primary_fields_HV_CAN_FORWARD_STATUS(buffer);
        case 774:
            return primary_fields_HV_FANS_OVERRIDE_STATUS(buffer);
        case 775:
            return primary_fields_HV_FEEDBACKS_STATUS(buffer);
        case 807:
            return primary_fields_HV_IMD_STATUS(buffer);
        case 36:
            return primary_fields_TS_STATUS(buffer);
        case 69:
            return primary_fields_SET_TS_STATUS(buffer);
        case 101:
            return primary_fields_SET_TS_STATUS(buffer);
        case 264:
            return primary_fields_STEER_STATUS(buffer);
        case 776:
            return primary_fields_SET_CAR_STATUS(buffer);
        case 1032:
            return primary_fields_SET_PEDALS_RANGE(buffer);
        case 1064:
            return primary_fields_SET_STEERING_ANGLE_RANGE(buffer);
        case 515:
            return primary_fields_CAR_STATUS(buffer);
        case 3:
            return primary_fields_DAS_ERRORS(buffer);
        case 839:
            return primary_fields_LV_CURRENT(buffer);
        case 871:
            return primary_fields_LV_VOLTAGE(buffer);
        case 903:
            return primary_fields_LV_TOTAL_VOLTAGE(buffer);
        case 935:
            return primary_fields_LV_TEMPERATURE(buffer);
        case 967:
            return primary_fields_COOLING_STATUS(buffer);
        case 777:
            return primary_fields_SET_RADIATOR_SPEED(buffer);
        case 809:
            return primary_fields_SET_PUMPS_SPEED(buffer);
        case 265:
            return primary_fields_SET_INVERTER_CONNECTION_STATUS(buffer);
        case 263:
            return primary_fields_INVERTER_CONNECTION_STATUS(buffer);
        case 7:
            return primary_fields_LV_ERRORS(buffer);
        case 295:
            return primary_fields_SHUTDOWN_STATUS(buffer);
        case 2:
            return primary_fields_MARKER(buffer);
        case 518:
            return primary_fields_HV_CELLS_VOLTAGE(buffer);
        case 550:
            return primary_fields_HV_CELLS_TEMP(buffer);
        case 582:
            return primary_fields_HV_CELL_BALANCING_STATUS(buffer);
        case 517:
            return primary_fields_SET_CELL_BALANCING_STATUS(buffer);
        case 773:
            return primary_fields_HANDCART_STATUS(buffer);
        case 547:
            return primary_fields_SPEED(buffer);
        case 513:
            return primary_fields_INV_L_REQUEST(buffer);
        case 514:
            return primary_fields_INV_R_REQUEST(buffer);
        case 385:
            return primary_fields_INV_L_RESPONSE(buffer);
        case 386:
            return primary_fields_INV_R_RESPONSE(buffer);
        case 16:
            return primary_fields_FLASH_CELLBOARD_0_TX(buffer);
        case 17:
            return primary_fields_FLASH_CELLBOARD_0_RX(buffer);
        case 18:
            return primary_fields_FLASH_CELLBOARD_1_TX(buffer);
        case 19:
            return primary_fields_FLASH_CELLBOARD_1_RX(buffer);
        case 20:
            return primary_fields_FLASH_CELLBOARD_2_TX(buffer);
        case 21:
            return primary_fields_FLASH_CELLBOARD_2_RX(buffer);
        case 22:
            return primary_fields_FLASH_CELLBOARD_3_TX(buffer);
        case 23:
            return primary_fields_FLASH_CELLBOARD_3_RX(buffer);
        case 24:
            return primary_fields_FLASH_CELLBOARD_4_TX(buffer);
        case 25:
            return primary_fields_FLASH_CELLBOARD_4_RX(buffer);
        case 26:
            return primary_fields_FLASH_CELLBOARD_5_TX(buffer);
        case 27:
            return primary_fields_FLASH_CELLBOARD_5_RX(buffer);
        case 2017:
            return primary_fields_FLASH_BMS_HV_TX(buffer);
        case 1639:
            return primary_fields_FLASH_BMS_HV_RX(buffer);
        case 2033:
            return primary_fields_FLASH_BMS_LV_TX(buffer);
        case 1655:
            return primary_fields_FLASH_BMS_LV_RX(buffer);
        case 618:
            return primary_fields_BRUSA_NLG5_CTL(buffer);
        case 610:
            return primary_fields_BRUSA_ST(buffer);
        case 611:
            return primary_fields_BRUSA_ACT_I(buffer);
        case 612:
            return primary_fields_BRUSA_ACT_II(buffer);
        case 613:
            return primary_fields_BRUSA_TEMP(buffer);
        case 614:
            return primary_fields_BRUSA_ERR(buffer);
        case 170:
            return primary_fields_BMS_HV_CHIMERA(buffer);
        case 85:
            return primary_fields_ECU_CHIMERA(buffer);
    }
    return 0;
}

int primary_to_string_from_id(canlib_message_id message_id, void* message, char* buffer) {
    switch (message_id) {
        case 0:
            return primary_to_string_BMS_HV_JMP_TO_BLT((primary_message_BMS_HV_JMP_TO_BLT*) message, buffer);
        case 32:
            return primary_to_string_BMS_LV_JMP_TO_BLT((primary_message_BMS_LV_JMP_TO_BLT*) message, buffer);
        case 1025:
            return primary_to_string_STEER_VERSION((primary_message_STEER_VERSION*) message, buffer);
        case 1057:
            return primary_to_string_DAS_VERSION((primary_message_DAS_VERSION*) message, buffer);
        case 1089:
            return primary_to_string_HV_VERSION((primary_message_HV_VERSION*) message, buffer);
        case 1121:
            return primary_to_string_LV_VERSION((primary_message_LV_VERSION*) message, buffer);
        case 1153:
            return primary_to_string_TLM_VERSION((primary_message_TLM_VERSION*) message, buffer);
        case 257:
            return primary_to_string_TIMESTAMP((primary_message_TIMESTAMP*) message, buffer);
        case 258:
            return primary_to_string_SET_TLM_STATUS((primary_message_SET_TLM_STATUS*) message, buffer);
        case 259:
            return primary_to_string_TLM_STATUS((primary_message_TLM_STATUS*) message, buffer);
        case 1794:
            return primary_to_string_STEER_SYSTEM_STATUS((primary_message_STEER_SYSTEM_STATUS*) message, buffer);
        case 772:
            return primary_to_string_HV_VOLTAGE((primary_message_HV_VOLTAGE_conversion*) message, buffer);
        case 804:
            return primary_to_string_HV_CURRENT((primary_message_HV_CURRENT_conversion*) message, buffer);
        case 836:
            return primary_to_string_HV_TEMP((primary_message_HV_TEMP_conversion*) message, buffer);
        case 4:
            return primary_to_string_HV_ERRORS((primary_message_HV_ERRORS*) message, buffer);
        case 5:
            return primary_to_string_HV_CAN_FORWARD((primary_message_HV_CAN_FORWARD*) message, buffer);
        case 37:
            return primary_to_string_HV_FANS_OVERRIDE((primary_message_HV_FANS_OVERRIDE_conversion*) message, buffer);
        case 6:
            return primary_to_string_HV_CAN_FORWARD_STATUS((primary_message_HV_CAN_FORWARD_STATUS*) message, buffer);
        case 774:
            return primary_to_string_HV_FANS_OVERRIDE_STATUS((primary_message_HV_FANS_OVERRIDE_STATUS_conversion*) message, buffer);
        case 775:
            return primary_to_string_HV_FEEDBACKS_STATUS((primary_message_HV_FEEDBACKS_STATUS*) message, buffer);
        case 807:
            return primary_to_string_HV_IMD_STATUS((primary_message_HV_IMD_STATUS*) message, buffer);
        case 36:
            return primary_to_string_TS_STATUS((primary_message_TS_STATUS*) message, buffer);
        case 69:
            return primary_to_string_SET_TS_STATUS((primary_message_SET_TS_STATUS*) message, buffer);
        case 101:
            return primary_to_string_SET_TS_STATUS((primary_message_SET_TS_STATUS*) message, buffer);
        case 264:
            return primary_to_string_STEER_STATUS((primary_message_STEER_STATUS*) message, buffer);
        case 776:
            return primary_to_string_SET_CAR_STATUS((primary_message_SET_CAR_STATUS*) message, buffer);
        case 1032:
            return primary_to_string_SET_PEDALS_RANGE((primary_message_SET_PEDALS_RANGE*) message, buffer);
        case 1064:
            return primary_to_string_SET_STEERING_ANGLE_RANGE((primary_message_SET_STEERING_ANGLE_RANGE*) message, buffer);
        case 515:
            return primary_to_string_CAR_STATUS((primary_message_CAR_STATUS*) message, buffer);
        case 3:
            return primary_to_string_DAS_ERRORS((primary_message_DAS_ERRORS*) message, buffer);
        case 839:
            return primary_to_string_LV_CURRENT((primary_message_LV_CURRENT_conversion*) message, buffer);
        case 871:
            return primary_to_string_LV_VOLTAGE((primary_message_LV_VOLTAGE_conversion*) message, buffer);
        case 903:
            return primary_to_string_LV_TOTAL_VOLTAGE((primary_message_LV_TOTAL_VOLTAGE_conversion*) message, buffer);
        case 935:
            return primary_to_string_LV_TEMPERATURE((primary_message_LV_TEMPERATURE_conversion*) message, buffer);
        case 967:
            return primary_to_string_COOLING_STATUS((primary_message_COOLING_STATUS_conversion*) message, buffer);
        case 777:
            return primary_to_string_SET_RADIATOR_SPEED((primary_message_SET_RADIATOR_SPEED_conversion*) message, buffer);
        case 809:
            return primary_to_string_SET_PUMPS_SPEED((primary_message_SET_PUMPS_SPEED_conversion*) message, buffer);
        case 265:
            return primary_to_string_SET_INVERTER_CONNECTION_STATUS((primary_message_SET_INVERTER_CONNECTION_STATUS*) message, buffer);
        case 263:
            return primary_to_string_INVERTER_CONNECTION_STATUS((primary_message_INVERTER_CONNECTION_STATUS*) message, buffer);
        case 7:
            return primary_to_string_LV_ERRORS((primary_message_LV_ERRORS*) message, buffer);
        case 295:
            return primary_to_string_SHUTDOWN_STATUS((primary_message_SHUTDOWN_STATUS*) message, buffer);
        case 2:
            return primary_to_string_MARKER((primary_message_MARKER*) message, buffer);
        case 518:
            return primary_to_string_HV_CELLS_VOLTAGE((primary_message_HV_CELLS_VOLTAGE_conversion*) message, buffer);
        case 550:
            return primary_to_string_HV_CELLS_TEMP((primary_message_HV_CELLS_TEMP_conversion*) message, buffer);
        case 582:
            return primary_to_string_HV_CELL_BALANCING_STATUS((primary_message_HV_CELL_BALANCING_STATUS*) message, buffer);
        case 517:
            return primary_to_string_SET_CELL_BALANCING_STATUS((primary_message_SET_CELL_BALANCING_STATUS*) message, buffer);
        case 773:
            return primary_to_string_HANDCART_STATUS((primary_message_HANDCART_STATUS*) message, buffer);
        case 547:
            return primary_to_string_SPEED((primary_message_SPEED_conversion*) message, buffer);
        case 513:
            return primary_to_string_INV_L_REQUEST((primary_message_INV_L_REQUEST*) message, buffer);
        case 514:
            return primary_to_string_INV_R_REQUEST((primary_message_INV_R_REQUEST*) message, buffer);
        case 385:
            return primary_to_string_INV_L_RESPONSE((primary_message_INV_L_RESPONSE*) message, buffer);
        case 386:
            return primary_to_string_INV_R_RESPONSE((primary_message_INV_R_RESPONSE*) message, buffer);
        case 16:
            return primary_to_string_FLASH_CELLBOARD_0_TX((primary_message_FLASH_CELLBOARD_0_TX*) message, buffer);
        case 17:
            return primary_to_string_FLASH_CELLBOARD_0_RX((primary_message_FLASH_CELLBOARD_0_RX*) message, buffer);
        case 18:
            return primary_to_string_FLASH_CELLBOARD_1_TX((primary_message_FLASH_CELLBOARD_1_TX*) message, buffer);
        case 19:
            return primary_to_string_FLASH_CELLBOARD_1_RX((primary_message_FLASH_CELLBOARD_1_RX*) message, buffer);
        case 20:
            return primary_to_string_FLASH_CELLBOARD_2_TX((primary_message_FLASH_CELLBOARD_2_TX*) message, buffer);
        case 21:
            return primary_to_string_FLASH_CELLBOARD_2_RX((primary_message_FLASH_CELLBOARD_2_RX*) message, buffer);
        case 22:
            return primary_to_string_FLASH_CELLBOARD_3_TX((primary_message_FLASH_CELLBOARD_3_TX*) message, buffer);
        case 23:
            return primary_to_string_FLASH_CELLBOARD_3_RX((primary_message_FLASH_CELLBOARD_3_RX*) message, buffer);
        case 24:
            return primary_to_string_FLASH_CELLBOARD_4_TX((primary_message_FLASH_CELLBOARD_4_TX*) message, buffer);
        case 25:
            return primary_to_string_FLASH_CELLBOARD_4_RX((primary_message_FLASH_CELLBOARD_4_RX*) message, buffer);
        case 26:
            return primary_to_string_FLASH_CELLBOARD_5_TX((primary_message_FLASH_CELLBOARD_5_TX*) message, buffer);
        case 27:
            return primary_to_string_FLASH_CELLBOARD_5_RX((primary_message_FLASH_CELLBOARD_5_RX*) message, buffer);
        case 2017:
            return primary_to_string_FLASH_BMS_HV_TX((primary_message_FLASH_BMS_HV_TX*) message, buffer);
        case 1639:
            return primary_to_string_FLASH_BMS_HV_RX((primary_message_FLASH_BMS_HV_RX*) message, buffer);
        case 2033:
            return primary_to_string_FLASH_BMS_LV_TX((primary_message_FLASH_BMS_LV_TX*) message, buffer);
        case 1655:
            return primary_to_string_FLASH_BMS_LV_RX((primary_message_FLASH_BMS_LV_RX*) message, buffer);
        case 618:
            return primary_to_string_BRUSA_NLG5_CTL((primary_message_BRUSA_NLG5_CTL*) message, buffer);
        case 610:
            return primary_to_string_BRUSA_ST((primary_message_BRUSA_ST*) message, buffer);
        case 611:
            return primary_to_string_BRUSA_ACT_I((primary_message_BRUSA_ACT_I*) message, buffer);
        case 612:
            return primary_to_string_BRUSA_ACT_II((primary_message_BRUSA_ACT_II*) message, buffer);
        case 613:
            return primary_to_string_BRUSA_TEMP((primary_message_BRUSA_TEMP*) message, buffer);
        case 614:
            return primary_to_string_BRUSA_ERR((primary_message_BRUSA_ERR*) message, buffer);
        case 170:
            return primary_to_string_BMS_HV_CHIMERA((primary_message_BMS_HV_CHIMERA*) message, buffer);
        case 85:
            return primary_to_string_ECU_CHIMERA((primary_message_ECU_CHIMERA*) message, buffer);
    }
    return 0;
}

int primary_fields_file_from_id(canlib_message_id message_id, FILE *buffer) {
    switch (message_id) {
        case 0:
            return primary_fields_file_BMS_HV_JMP_TO_BLT(buffer);
        case 32:
            return primary_fields_file_BMS_LV_JMP_TO_BLT(buffer);
        case 1025:
            return primary_fields_file_STEER_VERSION(buffer);
        case 1057:
            return primary_fields_file_DAS_VERSION(buffer);
        case 1089:
            return primary_fields_file_HV_VERSION(buffer);
        case 1121:
            return primary_fields_file_LV_VERSION(buffer);
        case 1153:
            return primary_fields_file_TLM_VERSION(buffer);
        case 257:
            return primary_fields_file_TIMESTAMP(buffer);
        case 258:
            return primary_fields_file_SET_TLM_STATUS(buffer);
        case 259:
            return primary_fields_file_TLM_STATUS(buffer);
        case 1794:
            return primary_fields_file_STEER_SYSTEM_STATUS(buffer);
        case 772:
            return primary_fields_file_HV_VOLTAGE(buffer);
        case 804:
            return primary_fields_file_HV_CURRENT(buffer);
        case 836:
            return primary_fields_file_HV_TEMP(buffer);
        case 4:
            return primary_fields_file_HV_ERRORS(buffer);
        case 5:
            return primary_fields_file_HV_CAN_FORWARD(buffer);
        case 37:
            return primary_fields_file_HV_FANS_OVERRIDE(buffer);
        case 6:
            return primary_fields_file_HV_CAN_FORWARD_STATUS(buffer);
        case 774:
            return primary_fields_file_HV_FANS_OVERRIDE_STATUS(buffer);
        case 775:
            return primary_fields_file_HV_FEEDBACKS_STATUS(buffer);
        case 807:
            return primary_fields_file_HV_IMD_STATUS(buffer);
        case 36:
            return primary_fields_file_TS_STATUS(buffer);
        case 69:
            return primary_fields_file_SET_TS_STATUS(buffer);
        case 101:
            return primary_fields_file_SET_TS_STATUS(buffer);
        case 264:
            return primary_fields_file_STEER_STATUS(buffer);
        case 776:
            return primary_fields_file_SET_CAR_STATUS(buffer);
        case 1032:
            return primary_fields_file_SET_PEDALS_RANGE(buffer);
        case 1064:
            return primary_fields_file_SET_STEERING_ANGLE_RANGE(buffer);
        case 515:
            return primary_fields_file_CAR_STATUS(buffer);
        case 3:
            return primary_fields_file_DAS_ERRORS(buffer);
        case 839:
            return primary_fields_file_LV_CURRENT(buffer);
        case 871:
            return primary_fields_file_LV_VOLTAGE(buffer);
        case 903:
            return primary_fields_file_LV_TOTAL_VOLTAGE(buffer);
        case 935:
            return primary_fields_file_LV_TEMPERATURE(buffer);
        case 967:
            return primary_fields_file_COOLING_STATUS(buffer);
        case 777:
            return primary_fields_file_SET_RADIATOR_SPEED(buffer);
        case 809:
            return primary_fields_file_SET_PUMPS_SPEED(buffer);
        case 265:
            return primary_fields_file_SET_INVERTER_CONNECTION_STATUS(buffer);
        case 263:
            return primary_fields_file_INVERTER_CONNECTION_STATUS(buffer);
        case 7:
            return primary_fields_file_LV_ERRORS(buffer);
        case 295:
            return primary_fields_file_SHUTDOWN_STATUS(buffer);
        case 2:
            return primary_fields_file_MARKER(buffer);
        case 518:
            return primary_fields_file_HV_CELLS_VOLTAGE(buffer);
        case 550:
            return primary_fields_file_HV_CELLS_TEMP(buffer);
        case 582:
            return primary_fields_file_HV_CELL_BALANCING_STATUS(buffer);
        case 517:
            return primary_fields_file_SET_CELL_BALANCING_STATUS(buffer);
        case 773:
            return primary_fields_file_HANDCART_STATUS(buffer);
        case 547:
            return primary_fields_file_SPEED(buffer);
        case 513:
            return primary_fields_file_INV_L_REQUEST(buffer);
        case 514:
            return primary_fields_file_INV_R_REQUEST(buffer);
        case 385:
            return primary_fields_file_INV_L_RESPONSE(buffer);
        case 386:
            return primary_fields_file_INV_R_RESPONSE(buffer);
        case 16:
            return primary_fields_file_FLASH_CELLBOARD_0_TX(buffer);
        case 17:
            return primary_fields_file_FLASH_CELLBOARD_0_RX(buffer);
        case 18:
            return primary_fields_file_FLASH_CELLBOARD_1_TX(buffer);
        case 19:
            return primary_fields_file_FLASH_CELLBOARD_1_RX(buffer);
        case 20:
            return primary_fields_file_FLASH_CELLBOARD_2_TX(buffer);
        case 21:
            return primary_fields_file_FLASH_CELLBOARD_2_RX(buffer);
        case 22:
            return primary_fields_file_FLASH_CELLBOARD_3_TX(buffer);
        case 23:
            return primary_fields_file_FLASH_CELLBOARD_3_RX(buffer);
        case 24:
            return primary_fields_file_FLASH_CELLBOARD_4_TX(buffer);
        case 25:
            return primary_fields_file_FLASH_CELLBOARD_4_RX(buffer);
        case 26:
            return primary_fields_file_FLASH_CELLBOARD_5_TX(buffer);
        case 27:
            return primary_fields_file_FLASH_CELLBOARD_5_RX(buffer);
        case 2017:
            return primary_fields_file_FLASH_BMS_HV_TX(buffer);
        case 1639:
            return primary_fields_file_FLASH_BMS_HV_RX(buffer);
        case 2033:
            return primary_fields_file_FLASH_BMS_LV_TX(buffer);
        case 1655:
            return primary_fields_file_FLASH_BMS_LV_RX(buffer);
        case 618:
            return primary_fields_file_BRUSA_NLG5_CTL(buffer);
        case 610:
            return primary_fields_file_BRUSA_ST(buffer);
        case 611:
            return primary_fields_file_BRUSA_ACT_I(buffer);
        case 612:
            return primary_fields_file_BRUSA_ACT_II(buffer);
        case 613:
            return primary_fields_file_BRUSA_TEMP(buffer);
        case 614:
            return primary_fields_file_BRUSA_ERR(buffer);
        case 170:
            return primary_fields_file_BMS_HV_CHIMERA(buffer);
        case 85:
            return primary_fields_file_ECU_CHIMERA(buffer);
    }
    return 0;
}

int primary_to_string_file_from_id(canlib_message_id message_id, void* message, FILE *buffer) {
    switch (message_id) {
        case 0:
            return primary_to_string_file_BMS_HV_JMP_TO_BLT((primary_message_BMS_HV_JMP_TO_BLT*) message, buffer);
        case 32:
            return primary_to_string_file_BMS_LV_JMP_TO_BLT((primary_message_BMS_LV_JMP_TO_BLT*) message, buffer);
        case 1025:
            return primary_to_string_file_STEER_VERSION((primary_message_STEER_VERSION*) message, buffer);
        case 1057:
            return primary_to_string_file_DAS_VERSION((primary_message_DAS_VERSION*) message, buffer);
        case 1089:
            return primary_to_string_file_HV_VERSION((primary_message_HV_VERSION*) message, buffer);
        case 1121:
            return primary_to_string_file_LV_VERSION((primary_message_LV_VERSION*) message, buffer);
        case 1153:
            return primary_to_string_file_TLM_VERSION((primary_message_TLM_VERSION*) message, buffer);
        case 257:
            return primary_to_string_file_TIMESTAMP((primary_message_TIMESTAMP*) message, buffer);
        case 258:
            return primary_to_string_file_SET_TLM_STATUS((primary_message_SET_TLM_STATUS*) message, buffer);
        case 259:
            return primary_to_string_file_TLM_STATUS((primary_message_TLM_STATUS*) message, buffer);
        case 1794:
            return primary_to_string_file_STEER_SYSTEM_STATUS((primary_message_STEER_SYSTEM_STATUS*) message, buffer);
        case 772:
            return primary_to_string_file_HV_VOLTAGE((primary_message_HV_VOLTAGE_conversion*) message, buffer);
        case 804:
            return primary_to_string_file_HV_CURRENT((primary_message_HV_CURRENT_conversion*) message, buffer);
        case 836:
            return primary_to_string_file_HV_TEMP((primary_message_HV_TEMP_conversion*) message, buffer);
        case 4:
            return primary_to_string_file_HV_ERRORS((primary_message_HV_ERRORS*) message, buffer);
        case 5:
            return primary_to_string_file_HV_CAN_FORWARD((primary_message_HV_CAN_FORWARD*) message, buffer);
        case 37:
            return primary_to_string_file_HV_FANS_OVERRIDE((primary_message_HV_FANS_OVERRIDE_conversion*) message, buffer);
        case 6:
            return primary_to_string_file_HV_CAN_FORWARD_STATUS((primary_message_HV_CAN_FORWARD_STATUS*) message, buffer);
        case 774:
            return primary_to_string_file_HV_FANS_OVERRIDE_STATUS((primary_message_HV_FANS_OVERRIDE_STATUS_conversion*) message, buffer);
        case 775:
            return primary_to_string_file_HV_FEEDBACKS_STATUS((primary_message_HV_FEEDBACKS_STATUS*) message, buffer);
        case 807:
            return primary_to_string_file_HV_IMD_STATUS((primary_message_HV_IMD_STATUS*) message, buffer);
        case 36:
            return primary_to_string_file_TS_STATUS((primary_message_TS_STATUS*) message, buffer);
        case 69:
            return primary_to_string_file_SET_TS_STATUS((primary_message_SET_TS_STATUS*) message, buffer);
        case 101:
            return primary_to_string_file_SET_TS_STATUS((primary_message_SET_TS_STATUS*) message, buffer);
        case 264:
            return primary_to_string_file_STEER_STATUS((primary_message_STEER_STATUS*) message, buffer);
        case 776:
            return primary_to_string_file_SET_CAR_STATUS((primary_message_SET_CAR_STATUS*) message, buffer);
        case 1032:
            return primary_to_string_file_SET_PEDALS_RANGE((primary_message_SET_PEDALS_RANGE*) message, buffer);
        case 1064:
            return primary_to_string_file_SET_STEERING_ANGLE_RANGE((primary_message_SET_STEERING_ANGLE_RANGE*) message, buffer);
        case 515:
            return primary_to_string_file_CAR_STATUS((primary_message_CAR_STATUS*) message, buffer);
        case 3:
            return primary_to_string_file_DAS_ERRORS((primary_message_DAS_ERRORS*) message, buffer);
        case 839:
            return primary_to_string_file_LV_CURRENT((primary_message_LV_CURRENT_conversion*) message, buffer);
        case 871:
            return primary_to_string_file_LV_VOLTAGE((primary_message_LV_VOLTAGE_conversion*) message, buffer);
        case 903:
            return primary_to_string_file_LV_TOTAL_VOLTAGE((primary_message_LV_TOTAL_VOLTAGE_conversion*) message, buffer);
        case 935:
            return primary_to_string_file_LV_TEMPERATURE((primary_message_LV_TEMPERATURE_conversion*) message, buffer);
        case 967:
            return primary_to_string_file_COOLING_STATUS((primary_message_COOLING_STATUS_conversion*) message, buffer);
        case 777:
            return primary_to_string_file_SET_RADIATOR_SPEED((primary_message_SET_RADIATOR_SPEED_conversion*) message, buffer);
        case 809:
            return primary_to_string_file_SET_PUMPS_SPEED((primary_message_SET_PUMPS_SPEED_conversion*) message, buffer);
        case 265:
            return primary_to_string_file_SET_INVERTER_CONNECTION_STATUS((primary_message_SET_INVERTER_CONNECTION_STATUS*) message, buffer);
        case 263:
            return primary_to_string_file_INVERTER_CONNECTION_STATUS((primary_message_INVERTER_CONNECTION_STATUS*) message, buffer);
        case 7:
            return primary_to_string_file_LV_ERRORS((primary_message_LV_ERRORS*) message, buffer);
        case 295:
            return primary_to_string_file_SHUTDOWN_STATUS((primary_message_SHUTDOWN_STATUS*) message, buffer);
        case 2:
            return primary_to_string_file_MARKER((primary_message_MARKER*) message, buffer);
        case 518:
            return primary_to_string_file_HV_CELLS_VOLTAGE((primary_message_HV_CELLS_VOLTAGE_conversion*) message, buffer);
        case 550:
            return primary_to_string_file_HV_CELLS_TEMP((primary_message_HV_CELLS_TEMP_conversion*) message, buffer);
        case 582:
            return primary_to_string_file_HV_CELL_BALANCING_STATUS((primary_message_HV_CELL_BALANCING_STATUS*) message, buffer);
        case 517:
            return primary_to_string_file_SET_CELL_BALANCING_STATUS((primary_message_SET_CELL_BALANCING_STATUS*) message, buffer);
        case 773:
            return primary_to_string_file_HANDCART_STATUS((primary_message_HANDCART_STATUS*) message, buffer);
        case 547:
            return primary_to_string_file_SPEED((primary_message_SPEED_conversion*) message, buffer);
        case 513:
            return primary_to_string_file_INV_L_REQUEST((primary_message_INV_L_REQUEST*) message, buffer);
        case 514:
            return primary_to_string_file_INV_R_REQUEST((primary_message_INV_R_REQUEST*) message, buffer);
        case 385:
            return primary_to_string_file_INV_L_RESPONSE((primary_message_INV_L_RESPONSE*) message, buffer);
        case 386:
            return primary_to_string_file_INV_R_RESPONSE((primary_message_INV_R_RESPONSE*) message, buffer);
        case 16:
            return primary_to_string_file_FLASH_CELLBOARD_0_TX((primary_message_FLASH_CELLBOARD_0_TX*) message, buffer);
        case 17:
            return primary_to_string_file_FLASH_CELLBOARD_0_RX((primary_message_FLASH_CELLBOARD_0_RX*) message, buffer);
        case 18:
            return primary_to_string_file_FLASH_CELLBOARD_1_TX((primary_message_FLASH_CELLBOARD_1_TX*) message, buffer);
        case 19:
            return primary_to_string_file_FLASH_CELLBOARD_1_RX((primary_message_FLASH_CELLBOARD_1_RX*) message, buffer);
        case 20:
            return primary_to_string_file_FLASH_CELLBOARD_2_TX((primary_message_FLASH_CELLBOARD_2_TX*) message, buffer);
        case 21:
            return primary_to_string_file_FLASH_CELLBOARD_2_RX((primary_message_FLASH_CELLBOARD_2_RX*) message, buffer);
        case 22:
            return primary_to_string_file_FLASH_CELLBOARD_3_TX((primary_message_FLASH_CELLBOARD_3_TX*) message, buffer);
        case 23:
            return primary_to_string_file_FLASH_CELLBOARD_3_RX((primary_message_FLASH_CELLBOARD_3_RX*) message, buffer);
        case 24:
            return primary_to_string_file_FLASH_CELLBOARD_4_TX((primary_message_FLASH_CELLBOARD_4_TX*) message, buffer);
        case 25:
            return primary_to_string_file_FLASH_CELLBOARD_4_RX((primary_message_FLASH_CELLBOARD_4_RX*) message, buffer);
        case 26:
            return primary_to_string_file_FLASH_CELLBOARD_5_TX((primary_message_FLASH_CELLBOARD_5_TX*) message, buffer);
        case 27:
            return primary_to_string_file_FLASH_CELLBOARD_5_RX((primary_message_FLASH_CELLBOARD_5_RX*) message, buffer);
        case 2017:
            return primary_to_string_file_FLASH_BMS_HV_TX((primary_message_FLASH_BMS_HV_TX*) message, buffer);
        case 1639:
            return primary_to_string_file_FLASH_BMS_HV_RX((primary_message_FLASH_BMS_HV_RX*) message, buffer);
        case 2033:
            return primary_to_string_file_FLASH_BMS_LV_TX((primary_message_FLASH_BMS_LV_TX*) message, buffer);
        case 1655:
            return primary_to_string_file_FLASH_BMS_LV_RX((primary_message_FLASH_BMS_LV_RX*) message, buffer);
        case 618:
            return primary_to_string_file_BRUSA_NLG5_CTL((primary_message_BRUSA_NLG5_CTL*) message, buffer);
        case 610:
            return primary_to_string_file_BRUSA_ST((primary_message_BRUSA_ST*) message, buffer);
        case 611:
            return primary_to_string_file_BRUSA_ACT_I((primary_message_BRUSA_ACT_I*) message, buffer);
        case 612:
            return primary_to_string_file_BRUSA_ACT_II((primary_message_BRUSA_ACT_II*) message, buffer);
        case 613:
            return primary_to_string_file_BRUSA_TEMP((primary_message_BRUSA_TEMP*) message, buffer);
        case 614:
            return primary_to_string_file_BRUSA_ERR((primary_message_BRUSA_ERR*) message, buffer);
        case 170:
            return primary_to_string_file_BMS_HV_CHIMERA((primary_message_BMS_HV_CHIMERA*) message, buffer);
        case 85:
            return primary_to_string_file_ECU_CHIMERA((primary_message_ECU_CHIMERA*) message, buffer);
    }
    return 0;
}

void* primary_deserialize_from_id(
    canlib_message_id message_id,
    uint8_t* data,
    void* message_raw,
    void* message_conversion
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
) {
    switch (message_id) {
        case 0: {
            primary_deserialize_BMS_HV_JMP_TO_BLT(
                (primary_message_BMS_HV_JMP_TO_BLT*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 32: {
            primary_deserialize_BMS_LV_JMP_TO_BLT(
                (primary_message_BMS_LV_JMP_TO_BLT*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 1025: {
            primary_deserialize_STEER_VERSION(
                (primary_message_STEER_VERSION*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 1057: {
            primary_deserialize_DAS_VERSION(
                (primary_message_DAS_VERSION*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 1089: {
            primary_deserialize_HV_VERSION(
                (primary_message_HV_VERSION*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 1121: {
            primary_deserialize_LV_VERSION(
                (primary_message_LV_VERSION*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 1153: {
            primary_deserialize_TLM_VERSION(
                (primary_message_TLM_VERSION*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 257: {
            primary_deserialize_TIMESTAMP(
                (primary_message_TIMESTAMP*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 258: {
            primary_deserialize_SET_TLM_STATUS(
                (primary_message_SET_TLM_STATUS*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 259: {
            primary_deserialize_TLM_STATUS(
                (primary_message_TLM_STATUS*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 1794: {
            primary_deserialize_STEER_SYSTEM_STATUS(
                (primary_message_STEER_SYSTEM_STATUS*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 772: {
            primary_deserialize_HV_VOLTAGE(
                (primary_message_HV_VOLTAGE*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            primary_raw_to_conversion_struct_HV_VOLTAGE(
                (primary_message_HV_VOLTAGE_conversion*) message_conversion,
                (primary_message_HV_VOLTAGE*) message_raw
            );
            return message_conversion;
        }
        case 804: {
            primary_deserialize_HV_CURRENT(
                (primary_message_HV_CURRENT*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            primary_raw_to_conversion_struct_HV_CURRENT(
                (primary_message_HV_CURRENT_conversion*) message_conversion,
                (primary_message_HV_CURRENT*) message_raw
            );
            return message_conversion;
        }
        case 836: {
            primary_deserialize_HV_TEMP(
                (primary_message_HV_TEMP*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            primary_raw_to_conversion_struct_HV_TEMP(
                (primary_message_HV_TEMP_conversion*) message_conversion,
                (primary_message_HV_TEMP*) message_raw
            );
            return message_conversion;
        }
        case 4: {
            primary_deserialize_HV_ERRORS(
                (primary_message_HV_ERRORS*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 5: {
            primary_deserialize_HV_CAN_FORWARD(
                (primary_message_HV_CAN_FORWARD*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 37: {
            primary_deserialize_HV_FANS_OVERRIDE(
                (primary_message_HV_FANS_OVERRIDE*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            primary_raw_to_conversion_struct_HV_FANS_OVERRIDE(
                (primary_message_HV_FANS_OVERRIDE_conversion*) message_conversion,
                (primary_message_HV_FANS_OVERRIDE*) message_raw
            );
            return message_conversion;
        }
        case 6: {
            primary_deserialize_HV_CAN_FORWARD_STATUS(
                (primary_message_HV_CAN_FORWARD_STATUS*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 774: {
            primary_deserialize_HV_FANS_OVERRIDE_STATUS(
                (primary_message_HV_FANS_OVERRIDE_STATUS*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            primary_raw_to_conversion_struct_HV_FANS_OVERRIDE_STATUS(
                (primary_message_HV_FANS_OVERRIDE_STATUS_conversion*) message_conversion,
                (primary_message_HV_FANS_OVERRIDE_STATUS*) message_raw
            );
            return message_conversion;
        }
        case 775: {
            primary_deserialize_HV_FEEDBACKS_STATUS(
                (primary_message_HV_FEEDBACKS_STATUS*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 807: {
            primary_deserialize_HV_IMD_STATUS(
                (primary_message_HV_IMD_STATUS*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 36: {
            primary_deserialize_TS_STATUS(
                (primary_message_TS_STATUS*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 69: {
            primary_deserialize_SET_TS_STATUS(
                (primary_message_SET_TS_STATUS*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 101: {
            primary_deserialize_SET_TS_STATUS(
                (primary_message_SET_TS_STATUS*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 264: {
            primary_deserialize_STEER_STATUS(
                (primary_message_STEER_STATUS*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 776: {
            primary_deserialize_SET_CAR_STATUS(
                (primary_message_SET_CAR_STATUS*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 1032: {
            primary_deserialize_SET_PEDALS_RANGE(
                (primary_message_SET_PEDALS_RANGE*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 1064: {
            primary_deserialize_SET_STEERING_ANGLE_RANGE(
                (primary_message_SET_STEERING_ANGLE_RANGE*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 515: {
            primary_deserialize_CAR_STATUS(
                (primary_message_CAR_STATUS*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 3: {
            primary_deserialize_DAS_ERRORS(
                (primary_message_DAS_ERRORS*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 839: {
            primary_deserialize_LV_CURRENT(
                (primary_message_LV_CURRENT*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            primary_raw_to_conversion_struct_LV_CURRENT(
                (primary_message_LV_CURRENT_conversion*) message_conversion,
                (primary_message_LV_CURRENT*) message_raw
            );
            return message_conversion;
        }
        case 871: {
            primary_deserialize_LV_VOLTAGE(
                (primary_message_LV_VOLTAGE*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            primary_raw_to_conversion_struct_LV_VOLTAGE(
                (primary_message_LV_VOLTAGE_conversion*) message_conversion,
                (primary_message_LV_VOLTAGE*) message_raw
            );
            return message_conversion;
        }
        case 903: {
            primary_deserialize_LV_TOTAL_VOLTAGE(
                (primary_message_LV_TOTAL_VOLTAGE*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            primary_raw_to_conversion_struct_LV_TOTAL_VOLTAGE(
                (primary_message_LV_TOTAL_VOLTAGE_conversion*) message_conversion,
                (primary_message_LV_TOTAL_VOLTAGE*) message_raw
            );
            return message_conversion;
        }
        case 935: {
            primary_deserialize_LV_TEMPERATURE(
                (primary_message_LV_TEMPERATURE*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            primary_raw_to_conversion_struct_LV_TEMPERATURE(
                (primary_message_LV_TEMPERATURE_conversion*) message_conversion,
                (primary_message_LV_TEMPERATURE*) message_raw
            );
            return message_conversion;
        }
        case 967: {
            primary_deserialize_COOLING_STATUS(
                (primary_message_COOLING_STATUS*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            primary_raw_to_conversion_struct_COOLING_STATUS(
                (primary_message_COOLING_STATUS_conversion*) message_conversion,
                (primary_message_COOLING_STATUS*) message_raw
            );
            return message_conversion;
        }
        case 777: {
            primary_deserialize_SET_RADIATOR_SPEED(
                (primary_message_SET_RADIATOR_SPEED*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            primary_raw_to_conversion_struct_SET_RADIATOR_SPEED(
                (primary_message_SET_RADIATOR_SPEED_conversion*) message_conversion,
                (primary_message_SET_RADIATOR_SPEED*) message_raw
            );
            return message_conversion;
        }
        case 809: {
            primary_deserialize_SET_PUMPS_SPEED(
                (primary_message_SET_PUMPS_SPEED*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            primary_raw_to_conversion_struct_SET_PUMPS_SPEED(
                (primary_message_SET_PUMPS_SPEED_conversion*) message_conversion,
                (primary_message_SET_PUMPS_SPEED*) message_raw
            );
            return message_conversion;
        }
        case 265: {
            primary_deserialize_SET_INVERTER_CONNECTION_STATUS(
                (primary_message_SET_INVERTER_CONNECTION_STATUS*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 263: {
            primary_deserialize_INVERTER_CONNECTION_STATUS(
                (primary_message_INVERTER_CONNECTION_STATUS*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 7: {
            primary_deserialize_LV_ERRORS(
                (primary_message_LV_ERRORS*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 295: {
            primary_deserialize_SHUTDOWN_STATUS(
                (primary_message_SHUTDOWN_STATUS*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 2: {
            primary_deserialize_MARKER(
                (primary_message_MARKER*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 518: {
            primary_deserialize_HV_CELLS_VOLTAGE(
                (primary_message_HV_CELLS_VOLTAGE*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            primary_raw_to_conversion_struct_HV_CELLS_VOLTAGE(
                (primary_message_HV_CELLS_VOLTAGE_conversion*) message_conversion,
                (primary_message_HV_CELLS_VOLTAGE*) message_raw
            );
            return message_conversion;
        }
        case 550: {
            primary_deserialize_HV_CELLS_TEMP(
                (primary_message_HV_CELLS_TEMP*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            primary_raw_to_conversion_struct_HV_CELLS_TEMP(
                (primary_message_HV_CELLS_TEMP_conversion*) message_conversion,
                (primary_message_HV_CELLS_TEMP*) message_raw
            );
            return message_conversion;
        }
        case 582: {
            primary_deserialize_HV_CELL_BALANCING_STATUS(
                (primary_message_HV_CELL_BALANCING_STATUS*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 517: {
            primary_deserialize_SET_CELL_BALANCING_STATUS(
                (primary_message_SET_CELL_BALANCING_STATUS*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 773: {
            primary_deserialize_HANDCART_STATUS(
                (primary_message_HANDCART_STATUS*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 547: {
            primary_deserialize_SPEED(
                (primary_message_SPEED*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            primary_raw_to_conversion_struct_SPEED(
                (primary_message_SPEED_conversion*) message_conversion,
                (primary_message_SPEED*) message_raw
            );
            return message_conversion;
        }
        case 513: {
            primary_deserialize_INV_L_REQUEST(
                (primary_message_INV_L_REQUEST*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 514: {
            primary_deserialize_INV_R_REQUEST(
                (primary_message_INV_R_REQUEST*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 385: {
            primary_deserialize_INV_L_RESPONSE(
                (primary_message_INV_L_RESPONSE*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 386: {
            primary_deserialize_INV_R_RESPONSE(
                (primary_message_INV_R_RESPONSE*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 16: {
            primary_deserialize_FLASH_CELLBOARD_0_TX(
                (primary_message_FLASH_CELLBOARD_0_TX*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 17: {
            primary_deserialize_FLASH_CELLBOARD_0_RX(
                (primary_message_FLASH_CELLBOARD_0_RX*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 18: {
            primary_deserialize_FLASH_CELLBOARD_1_TX(
                (primary_message_FLASH_CELLBOARD_1_TX*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 19: {
            primary_deserialize_FLASH_CELLBOARD_1_RX(
                (primary_message_FLASH_CELLBOARD_1_RX*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 20: {
            primary_deserialize_FLASH_CELLBOARD_2_TX(
                (primary_message_FLASH_CELLBOARD_2_TX*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 21: {
            primary_deserialize_FLASH_CELLBOARD_2_RX(
                (primary_message_FLASH_CELLBOARD_2_RX*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 22: {
            primary_deserialize_FLASH_CELLBOARD_3_TX(
                (primary_message_FLASH_CELLBOARD_3_TX*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 23: {
            primary_deserialize_FLASH_CELLBOARD_3_RX(
                (primary_message_FLASH_CELLBOARD_3_RX*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 24: {
            primary_deserialize_FLASH_CELLBOARD_4_TX(
                (primary_message_FLASH_CELLBOARD_4_TX*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 25: {
            primary_deserialize_FLASH_CELLBOARD_4_RX(
                (primary_message_FLASH_CELLBOARD_4_RX*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 26: {
            primary_deserialize_FLASH_CELLBOARD_5_TX(
                (primary_message_FLASH_CELLBOARD_5_TX*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 27: {
            primary_deserialize_FLASH_CELLBOARD_5_RX(
                (primary_message_FLASH_CELLBOARD_5_RX*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 2017: {
            primary_deserialize_FLASH_BMS_HV_TX(
                (primary_message_FLASH_BMS_HV_TX*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 1639: {
            primary_deserialize_FLASH_BMS_HV_RX(
                (primary_message_FLASH_BMS_HV_RX*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 2033: {
            primary_deserialize_FLASH_BMS_LV_TX(
                (primary_message_FLASH_BMS_LV_TX*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 1655: {
            primary_deserialize_FLASH_BMS_LV_RX(
                (primary_message_FLASH_BMS_LV_RX*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 618: {
            primary_deserialize_BRUSA_NLG5_CTL(
                (primary_message_BRUSA_NLG5_CTL*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 610: {
            primary_deserialize_BRUSA_ST(
                (primary_message_BRUSA_ST*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 611: {
            primary_deserialize_BRUSA_ACT_I(
                (primary_message_BRUSA_ACT_I*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 612: {
            primary_deserialize_BRUSA_ACT_II(
                (primary_message_BRUSA_ACT_II*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 613: {
            primary_deserialize_BRUSA_TEMP(
                (primary_message_BRUSA_TEMP*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 614: {
            primary_deserialize_BRUSA_ERR(
                (primary_message_BRUSA_ERR*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 170: {
            primary_deserialize_BMS_HV_CHIMERA(
                (primary_message_BMS_HV_CHIMERA*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 85: {
            primary_deserialize_ECU_CHIMERA(
                (primary_message_ECU_CHIMERA*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
    }
    return NULL;
}

primary_devices* primary_devices_new() {
    primary_devices* devices = (primary_devices*) malloc(sizeof(primary_devices));
    (*devices)[primary_INDEX_BMS_HV_JMP_TO_BLT].id = 0;
    (*devices)[primary_INDEX_BMS_HV_JMP_TO_BLT].message_raw = (void*) malloc(sizeof(primary_message_BMS_HV_JMP_TO_BLT));
    (*devices)[primary_INDEX_BMS_HV_JMP_TO_BLT].message_conversion = NULL;
    (*devices)[primary_INDEX_BMS_LV_JMP_TO_BLT].id = 32;
    (*devices)[primary_INDEX_BMS_LV_JMP_TO_BLT].message_raw = (void*) malloc(sizeof(primary_message_BMS_LV_JMP_TO_BLT));
    (*devices)[primary_INDEX_BMS_LV_JMP_TO_BLT].message_conversion = NULL;
    (*devices)[primary_INDEX_STEER_VERSION].id = 1025;
    (*devices)[primary_INDEX_STEER_VERSION].message_raw = (void*) malloc(sizeof(primary_message_STEER_VERSION));
    (*devices)[primary_INDEX_STEER_VERSION].message_conversion = NULL;
    (*devices)[primary_INDEX_DAS_VERSION].id = 1057;
    (*devices)[primary_INDEX_DAS_VERSION].message_raw = (void*) malloc(sizeof(primary_message_DAS_VERSION));
    (*devices)[primary_INDEX_DAS_VERSION].message_conversion = NULL;
    (*devices)[primary_INDEX_HV_VERSION].id = 1089;
    (*devices)[primary_INDEX_HV_VERSION].message_raw = (void*) malloc(sizeof(primary_message_HV_VERSION));
    (*devices)[primary_INDEX_HV_VERSION].message_conversion = NULL;
    (*devices)[primary_INDEX_LV_VERSION].id = 1121;
    (*devices)[primary_INDEX_LV_VERSION].message_raw = (void*) malloc(sizeof(primary_message_LV_VERSION));
    (*devices)[primary_INDEX_LV_VERSION].message_conversion = NULL;
    (*devices)[primary_INDEX_TLM_VERSION].id = 1153;
    (*devices)[primary_INDEX_TLM_VERSION].message_raw = (void*) malloc(sizeof(primary_message_TLM_VERSION));
    (*devices)[primary_INDEX_TLM_VERSION].message_conversion = NULL;
    (*devices)[primary_INDEX_TIMESTAMP].id = 257;
    (*devices)[primary_INDEX_TIMESTAMP].message_raw = (void*) malloc(sizeof(primary_message_TIMESTAMP));
    (*devices)[primary_INDEX_TIMESTAMP].message_conversion = NULL;
    (*devices)[primary_INDEX_SET_TLM_STATUS].id = 258;
    (*devices)[primary_INDEX_SET_TLM_STATUS].message_raw = (void*) malloc(sizeof(primary_message_SET_TLM_STATUS));
    (*devices)[primary_INDEX_SET_TLM_STATUS].message_conversion = NULL;
    (*devices)[primary_INDEX_TLM_STATUS].id = 259;
    (*devices)[primary_INDEX_TLM_STATUS].message_raw = (void*) malloc(sizeof(primary_message_TLM_STATUS));
    (*devices)[primary_INDEX_TLM_STATUS].message_conversion = NULL;
    (*devices)[primary_INDEX_STEER_SYSTEM_STATUS].id = 1794;
    (*devices)[primary_INDEX_STEER_SYSTEM_STATUS].message_raw = (void*) malloc(sizeof(primary_message_STEER_SYSTEM_STATUS));
    (*devices)[primary_INDEX_STEER_SYSTEM_STATUS].message_conversion = NULL;
    (*devices)[primary_INDEX_HV_VOLTAGE].id = 772;
    (*devices)[primary_INDEX_HV_VOLTAGE].message_raw = (void*) malloc(sizeof(primary_message_HV_VOLTAGE));
    (*devices)[primary_INDEX_HV_VOLTAGE].message_conversion = (void*) malloc(sizeof(primary_message_HV_VOLTAGE_conversion));
    (*devices)[primary_INDEX_HV_CURRENT].id = 804;
    (*devices)[primary_INDEX_HV_CURRENT].message_raw = (void*) malloc(sizeof(primary_message_HV_CURRENT));
    (*devices)[primary_INDEX_HV_CURRENT].message_conversion = (void*) malloc(sizeof(primary_message_HV_CURRENT_conversion));
    (*devices)[primary_INDEX_HV_TEMP].id = 836;
    (*devices)[primary_INDEX_HV_TEMP].message_raw = (void*) malloc(sizeof(primary_message_HV_TEMP));
    (*devices)[primary_INDEX_HV_TEMP].message_conversion = (void*) malloc(sizeof(primary_message_HV_TEMP_conversion));
    (*devices)[primary_INDEX_HV_ERRORS].id = 4;
    (*devices)[primary_INDEX_HV_ERRORS].message_raw = (void*) malloc(sizeof(primary_message_HV_ERRORS));
    (*devices)[primary_INDEX_HV_ERRORS].message_conversion = NULL;
    (*devices)[primary_INDEX_HV_CAN_FORWARD].id = 5;
    (*devices)[primary_INDEX_HV_CAN_FORWARD].message_raw = (void*) malloc(sizeof(primary_message_HV_CAN_FORWARD));
    (*devices)[primary_INDEX_HV_CAN_FORWARD].message_conversion = NULL;
    (*devices)[primary_INDEX_HV_FANS_OVERRIDE].id = 37;
    (*devices)[primary_INDEX_HV_FANS_OVERRIDE].message_raw = (void*) malloc(sizeof(primary_message_HV_FANS_OVERRIDE));
    (*devices)[primary_INDEX_HV_FANS_OVERRIDE].message_conversion = (void*) malloc(sizeof(primary_message_HV_FANS_OVERRIDE_conversion));
    (*devices)[primary_INDEX_HV_CAN_FORWARD_STATUS].id = 6;
    (*devices)[primary_INDEX_HV_CAN_FORWARD_STATUS].message_raw = (void*) malloc(sizeof(primary_message_HV_CAN_FORWARD_STATUS));
    (*devices)[primary_INDEX_HV_CAN_FORWARD_STATUS].message_conversion = NULL;
    (*devices)[primary_INDEX_HV_FANS_OVERRIDE_STATUS].id = 774;
    (*devices)[primary_INDEX_HV_FANS_OVERRIDE_STATUS].message_raw = (void*) malloc(sizeof(primary_message_HV_FANS_OVERRIDE_STATUS));
    (*devices)[primary_INDEX_HV_FANS_OVERRIDE_STATUS].message_conversion = (void*) malloc(sizeof(primary_message_HV_FANS_OVERRIDE_STATUS_conversion));
    (*devices)[primary_INDEX_HV_FEEDBACKS_STATUS].id = 775;
    (*devices)[primary_INDEX_HV_FEEDBACKS_STATUS].message_raw = (void*) malloc(sizeof(primary_message_HV_FEEDBACKS_STATUS));
    (*devices)[primary_INDEX_HV_FEEDBACKS_STATUS].message_conversion = NULL;
    (*devices)[primary_INDEX_HV_IMD_STATUS].id = 807;
    (*devices)[primary_INDEX_HV_IMD_STATUS].message_raw = (void*) malloc(sizeof(primary_message_HV_IMD_STATUS));
    (*devices)[primary_INDEX_HV_IMD_STATUS].message_conversion = NULL;
    (*devices)[primary_INDEX_TS_STATUS].id = 36;
    (*devices)[primary_INDEX_TS_STATUS].message_raw = (void*) malloc(sizeof(primary_message_TS_STATUS));
    (*devices)[primary_INDEX_TS_STATUS].message_conversion = NULL;
    (*devices)[primary_INDEX_SET_TS_STATUS_DAS].id = 69;
    (*devices)[primary_INDEX_SET_TS_STATUS_DAS].message_raw = (void*) malloc(sizeof(primary_message_SET_TS_STATUS));
    (*devices)[primary_INDEX_SET_TS_STATUS_DAS].message_conversion = NULL;
    (*devices)[primary_INDEX_SET_TS_STATUS_HANDCART].id = 101;
    (*devices)[primary_INDEX_SET_TS_STATUS_HANDCART].message_raw = (void*) malloc(sizeof(primary_message_SET_TS_STATUS));
    (*devices)[primary_INDEX_SET_TS_STATUS_HANDCART].message_conversion = NULL;
    (*devices)[primary_INDEX_SET_TS_STATUS_DAS].id = 69;
    (*devices)[primary_INDEX_SET_TS_STATUS_DAS].message_raw = (void*) malloc(sizeof(primary_message_SET_TS_STATUS));
    (*devices)[primary_INDEX_SET_TS_STATUS_DAS].message_conversion = NULL;
    (*devices)[primary_INDEX_SET_TS_STATUS_HANDCART].id = 101;
    (*devices)[primary_INDEX_SET_TS_STATUS_HANDCART].message_raw = (void*) malloc(sizeof(primary_message_SET_TS_STATUS));
    (*devices)[primary_INDEX_SET_TS_STATUS_HANDCART].message_conversion = NULL;
    (*devices)[primary_INDEX_STEER_STATUS].id = 264;
    (*devices)[primary_INDEX_STEER_STATUS].message_raw = (void*) malloc(sizeof(primary_message_STEER_STATUS));
    (*devices)[primary_INDEX_STEER_STATUS].message_conversion = NULL;
    (*devices)[primary_INDEX_SET_CAR_STATUS].id = 776;
    (*devices)[primary_INDEX_SET_CAR_STATUS].message_raw = (void*) malloc(sizeof(primary_message_SET_CAR_STATUS));
    (*devices)[primary_INDEX_SET_CAR_STATUS].message_conversion = NULL;
    (*devices)[primary_INDEX_SET_PEDALS_RANGE].id = 1032;
    (*devices)[primary_INDEX_SET_PEDALS_RANGE].message_raw = (void*) malloc(sizeof(primary_message_SET_PEDALS_RANGE));
    (*devices)[primary_INDEX_SET_PEDALS_RANGE].message_conversion = NULL;
    (*devices)[primary_INDEX_SET_STEERING_ANGLE_RANGE].id = 1064;
    (*devices)[primary_INDEX_SET_STEERING_ANGLE_RANGE].message_raw = (void*) malloc(sizeof(primary_message_SET_STEERING_ANGLE_RANGE));
    (*devices)[primary_INDEX_SET_STEERING_ANGLE_RANGE].message_conversion = NULL;
    (*devices)[primary_INDEX_CAR_STATUS].id = 515;
    (*devices)[primary_INDEX_CAR_STATUS].message_raw = (void*) malloc(sizeof(primary_message_CAR_STATUS));
    (*devices)[primary_INDEX_CAR_STATUS].message_conversion = NULL;
    (*devices)[primary_INDEX_DAS_ERRORS].id = 3;
    (*devices)[primary_INDEX_DAS_ERRORS].message_raw = (void*) malloc(sizeof(primary_message_DAS_ERRORS));
    (*devices)[primary_INDEX_DAS_ERRORS].message_conversion = NULL;
    (*devices)[primary_INDEX_LV_CURRENT].id = 839;
    (*devices)[primary_INDEX_LV_CURRENT].message_raw = (void*) malloc(sizeof(primary_message_LV_CURRENT));
    (*devices)[primary_INDEX_LV_CURRENT].message_conversion = (void*) malloc(sizeof(primary_message_LV_CURRENT_conversion));
    (*devices)[primary_INDEX_LV_VOLTAGE].id = 871;
    (*devices)[primary_INDEX_LV_VOLTAGE].message_raw = (void*) malloc(sizeof(primary_message_LV_VOLTAGE));
    (*devices)[primary_INDEX_LV_VOLTAGE].message_conversion = (void*) malloc(sizeof(primary_message_LV_VOLTAGE_conversion));
    (*devices)[primary_INDEX_LV_TOTAL_VOLTAGE].id = 903;
    (*devices)[primary_INDEX_LV_TOTAL_VOLTAGE].message_raw = (void*) malloc(sizeof(primary_message_LV_TOTAL_VOLTAGE));
    (*devices)[primary_INDEX_LV_TOTAL_VOLTAGE].message_conversion = (void*) malloc(sizeof(primary_message_LV_TOTAL_VOLTAGE_conversion));
    (*devices)[primary_INDEX_LV_TEMPERATURE].id = 935;
    (*devices)[primary_INDEX_LV_TEMPERATURE].message_raw = (void*) malloc(sizeof(primary_message_LV_TEMPERATURE));
    (*devices)[primary_INDEX_LV_TEMPERATURE].message_conversion = (void*) malloc(sizeof(primary_message_LV_TEMPERATURE_conversion));
    (*devices)[primary_INDEX_COOLING_STATUS].id = 967;
    (*devices)[primary_INDEX_COOLING_STATUS].message_raw = (void*) malloc(sizeof(primary_message_COOLING_STATUS));
    (*devices)[primary_INDEX_COOLING_STATUS].message_conversion = (void*) malloc(sizeof(primary_message_COOLING_STATUS_conversion));
    (*devices)[primary_INDEX_SET_RADIATOR_SPEED].id = 777;
    (*devices)[primary_INDEX_SET_RADIATOR_SPEED].message_raw = (void*) malloc(sizeof(primary_message_SET_RADIATOR_SPEED));
    (*devices)[primary_INDEX_SET_RADIATOR_SPEED].message_conversion = (void*) malloc(sizeof(primary_message_SET_RADIATOR_SPEED_conversion));
    (*devices)[primary_INDEX_SET_PUMPS_SPEED].id = 809;
    (*devices)[primary_INDEX_SET_PUMPS_SPEED].message_raw = (void*) malloc(sizeof(primary_message_SET_PUMPS_SPEED));
    (*devices)[primary_INDEX_SET_PUMPS_SPEED].message_conversion = (void*) malloc(sizeof(primary_message_SET_PUMPS_SPEED_conversion));
    (*devices)[primary_INDEX_SET_INVERTER_CONNECTION_STATUS].id = 265;
    (*devices)[primary_INDEX_SET_INVERTER_CONNECTION_STATUS].message_raw = (void*) malloc(sizeof(primary_message_SET_INVERTER_CONNECTION_STATUS));
    (*devices)[primary_INDEX_SET_INVERTER_CONNECTION_STATUS].message_conversion = NULL;
    (*devices)[primary_INDEX_INVERTER_CONNECTION_STATUS].id = 263;
    (*devices)[primary_INDEX_INVERTER_CONNECTION_STATUS].message_raw = (void*) malloc(sizeof(primary_message_INVERTER_CONNECTION_STATUS));
    (*devices)[primary_INDEX_INVERTER_CONNECTION_STATUS].message_conversion = NULL;
    (*devices)[primary_INDEX_LV_ERRORS].id = 7;
    (*devices)[primary_INDEX_LV_ERRORS].message_raw = (void*) malloc(sizeof(primary_message_LV_ERRORS));
    (*devices)[primary_INDEX_LV_ERRORS].message_conversion = NULL;
    (*devices)[primary_INDEX_SHUTDOWN_STATUS].id = 295;
    (*devices)[primary_INDEX_SHUTDOWN_STATUS].message_raw = (void*) malloc(sizeof(primary_message_SHUTDOWN_STATUS));
    (*devices)[primary_INDEX_SHUTDOWN_STATUS].message_conversion = NULL;
    (*devices)[primary_INDEX_MARKER].id = 2;
    (*devices)[primary_INDEX_MARKER].message_raw = (void*) malloc(sizeof(primary_message_MARKER));
    (*devices)[primary_INDEX_MARKER].message_conversion = NULL;
    (*devices)[primary_INDEX_HV_CELLS_VOLTAGE].id = 518;
    (*devices)[primary_INDEX_HV_CELLS_VOLTAGE].message_raw = (void*) malloc(sizeof(primary_message_HV_CELLS_VOLTAGE));
    (*devices)[primary_INDEX_HV_CELLS_VOLTAGE].message_conversion = (void*) malloc(sizeof(primary_message_HV_CELLS_VOLTAGE_conversion));
    (*devices)[primary_INDEX_HV_CELLS_TEMP].id = 550;
    (*devices)[primary_INDEX_HV_CELLS_TEMP].message_raw = (void*) malloc(sizeof(primary_message_HV_CELLS_TEMP));
    (*devices)[primary_INDEX_HV_CELLS_TEMP].message_conversion = (void*) malloc(sizeof(primary_message_HV_CELLS_TEMP_conversion));
    (*devices)[primary_INDEX_HV_CELL_BALANCING_STATUS].id = 582;
    (*devices)[primary_INDEX_HV_CELL_BALANCING_STATUS].message_raw = (void*) malloc(sizeof(primary_message_HV_CELL_BALANCING_STATUS));
    (*devices)[primary_INDEX_HV_CELL_BALANCING_STATUS].message_conversion = NULL;
    (*devices)[primary_INDEX_SET_CELL_BALANCING_STATUS].id = 517;
    (*devices)[primary_INDEX_SET_CELL_BALANCING_STATUS].message_raw = (void*) malloc(sizeof(primary_message_SET_CELL_BALANCING_STATUS));
    (*devices)[primary_INDEX_SET_CELL_BALANCING_STATUS].message_conversion = NULL;
    (*devices)[primary_INDEX_HANDCART_STATUS].id = 773;
    (*devices)[primary_INDEX_HANDCART_STATUS].message_raw = (void*) malloc(sizeof(primary_message_HANDCART_STATUS));
    (*devices)[primary_INDEX_HANDCART_STATUS].message_conversion = NULL;
    (*devices)[primary_INDEX_SPEED].id = 547;
    (*devices)[primary_INDEX_SPEED].message_raw = (void*) malloc(sizeof(primary_message_SPEED));
    (*devices)[primary_INDEX_SPEED].message_conversion = (void*) malloc(sizeof(primary_message_SPEED_conversion));
    (*devices)[primary_INDEX_INV_L_REQUEST].id = 513;
    (*devices)[primary_INDEX_INV_L_REQUEST].message_raw = (void*) malloc(sizeof(primary_message_INV_L_REQUEST));
    (*devices)[primary_INDEX_INV_L_REQUEST].message_conversion = NULL;
    (*devices)[primary_INDEX_INV_R_REQUEST].id = 514;
    (*devices)[primary_INDEX_INV_R_REQUEST].message_raw = (void*) malloc(sizeof(primary_message_INV_R_REQUEST));
    (*devices)[primary_INDEX_INV_R_REQUEST].message_conversion = NULL;
    (*devices)[primary_INDEX_INV_L_RESPONSE].id = 385;
    (*devices)[primary_INDEX_INV_L_RESPONSE].message_raw = (void*) malloc(sizeof(primary_message_INV_L_RESPONSE));
    (*devices)[primary_INDEX_INV_L_RESPONSE].message_conversion = NULL;
    (*devices)[primary_INDEX_INV_R_RESPONSE].id = 386;
    (*devices)[primary_INDEX_INV_R_RESPONSE].message_raw = (void*) malloc(sizeof(primary_message_INV_R_RESPONSE));
    (*devices)[primary_INDEX_INV_R_RESPONSE].message_conversion = NULL;
    (*devices)[primary_INDEX_FLASH_CELLBOARD_0_TX].id = 16;
    (*devices)[primary_INDEX_FLASH_CELLBOARD_0_TX].message_raw = (void*) malloc(sizeof(primary_message_FLASH_CELLBOARD_0_TX));
    (*devices)[primary_INDEX_FLASH_CELLBOARD_0_TX].message_conversion = NULL;
    (*devices)[primary_INDEX_FLASH_CELLBOARD_0_RX].id = 17;
    (*devices)[primary_INDEX_FLASH_CELLBOARD_0_RX].message_raw = (void*) malloc(sizeof(primary_message_FLASH_CELLBOARD_0_RX));
    (*devices)[primary_INDEX_FLASH_CELLBOARD_0_RX].message_conversion = NULL;
    (*devices)[primary_INDEX_FLASH_CELLBOARD_1_TX].id = 18;
    (*devices)[primary_INDEX_FLASH_CELLBOARD_1_TX].message_raw = (void*) malloc(sizeof(primary_message_FLASH_CELLBOARD_1_TX));
    (*devices)[primary_INDEX_FLASH_CELLBOARD_1_TX].message_conversion = NULL;
    (*devices)[primary_INDEX_FLASH_CELLBOARD_1_RX].id = 19;
    (*devices)[primary_INDEX_FLASH_CELLBOARD_1_RX].message_raw = (void*) malloc(sizeof(primary_message_FLASH_CELLBOARD_1_RX));
    (*devices)[primary_INDEX_FLASH_CELLBOARD_1_RX].message_conversion = NULL;
    (*devices)[primary_INDEX_FLASH_CELLBOARD_2_TX].id = 20;
    (*devices)[primary_INDEX_FLASH_CELLBOARD_2_TX].message_raw = (void*) malloc(sizeof(primary_message_FLASH_CELLBOARD_2_TX));
    (*devices)[primary_INDEX_FLASH_CELLBOARD_2_TX].message_conversion = NULL;
    (*devices)[primary_INDEX_FLASH_CELLBOARD_2_RX].id = 21;
    (*devices)[primary_INDEX_FLASH_CELLBOARD_2_RX].message_raw = (void*) malloc(sizeof(primary_message_FLASH_CELLBOARD_2_RX));
    (*devices)[primary_INDEX_FLASH_CELLBOARD_2_RX].message_conversion = NULL;
    (*devices)[primary_INDEX_FLASH_CELLBOARD_3_TX].id = 22;
    (*devices)[primary_INDEX_FLASH_CELLBOARD_3_TX].message_raw = (void*) malloc(sizeof(primary_message_FLASH_CELLBOARD_3_TX));
    (*devices)[primary_INDEX_FLASH_CELLBOARD_3_TX].message_conversion = NULL;
    (*devices)[primary_INDEX_FLASH_CELLBOARD_3_RX].id = 23;
    (*devices)[primary_INDEX_FLASH_CELLBOARD_3_RX].message_raw = (void*) malloc(sizeof(primary_message_FLASH_CELLBOARD_3_RX));
    (*devices)[primary_INDEX_FLASH_CELLBOARD_3_RX].message_conversion = NULL;
    (*devices)[primary_INDEX_FLASH_CELLBOARD_4_TX].id = 24;
    (*devices)[primary_INDEX_FLASH_CELLBOARD_4_TX].message_raw = (void*) malloc(sizeof(primary_message_FLASH_CELLBOARD_4_TX));
    (*devices)[primary_INDEX_FLASH_CELLBOARD_4_TX].message_conversion = NULL;
    (*devices)[primary_INDEX_FLASH_CELLBOARD_4_RX].id = 25;
    (*devices)[primary_INDEX_FLASH_CELLBOARD_4_RX].message_raw = (void*) malloc(sizeof(primary_message_FLASH_CELLBOARD_4_RX));
    (*devices)[primary_INDEX_FLASH_CELLBOARD_4_RX].message_conversion = NULL;
    (*devices)[primary_INDEX_FLASH_CELLBOARD_5_TX].id = 26;
    (*devices)[primary_INDEX_FLASH_CELLBOARD_5_TX].message_raw = (void*) malloc(sizeof(primary_message_FLASH_CELLBOARD_5_TX));
    (*devices)[primary_INDEX_FLASH_CELLBOARD_5_TX].message_conversion = NULL;
    (*devices)[primary_INDEX_FLASH_CELLBOARD_5_RX].id = 27;
    (*devices)[primary_INDEX_FLASH_CELLBOARD_5_RX].message_raw = (void*) malloc(sizeof(primary_message_FLASH_CELLBOARD_5_RX));
    (*devices)[primary_INDEX_FLASH_CELLBOARD_5_RX].message_conversion = NULL;
    (*devices)[primary_INDEX_FLASH_BMS_HV_TX].id = 2017;
    (*devices)[primary_INDEX_FLASH_BMS_HV_TX].message_raw = (void*) malloc(sizeof(primary_message_FLASH_BMS_HV_TX));
    (*devices)[primary_INDEX_FLASH_BMS_HV_TX].message_conversion = NULL;
    (*devices)[primary_INDEX_FLASH_BMS_HV_RX].id = 1639;
    (*devices)[primary_INDEX_FLASH_BMS_HV_RX].message_raw = (void*) malloc(sizeof(primary_message_FLASH_BMS_HV_RX));
    (*devices)[primary_INDEX_FLASH_BMS_HV_RX].message_conversion = NULL;
    (*devices)[primary_INDEX_FLASH_BMS_LV_TX].id = 2033;
    (*devices)[primary_INDEX_FLASH_BMS_LV_TX].message_raw = (void*) malloc(sizeof(primary_message_FLASH_BMS_LV_TX));
    (*devices)[primary_INDEX_FLASH_BMS_LV_TX].message_conversion = NULL;
    (*devices)[primary_INDEX_FLASH_BMS_LV_RX].id = 1655;
    (*devices)[primary_INDEX_FLASH_BMS_LV_RX].message_raw = (void*) malloc(sizeof(primary_message_FLASH_BMS_LV_RX));
    (*devices)[primary_INDEX_FLASH_BMS_LV_RX].message_conversion = NULL;
    (*devices)[primary_INDEX_BRUSA_NLG5_CTL].id = 618;
    (*devices)[primary_INDEX_BRUSA_NLG5_CTL].message_raw = (void*) malloc(sizeof(primary_message_BRUSA_NLG5_CTL));
    (*devices)[primary_INDEX_BRUSA_NLG5_CTL].message_conversion = NULL;
    (*devices)[primary_INDEX_BRUSA_ST].id = 610;
    (*devices)[primary_INDEX_BRUSA_ST].message_raw = (void*) malloc(sizeof(primary_message_BRUSA_ST));
    (*devices)[primary_INDEX_BRUSA_ST].message_conversion = NULL;
    (*devices)[primary_INDEX_BRUSA_ACT_I].id = 611;
    (*devices)[primary_INDEX_BRUSA_ACT_I].message_raw = (void*) malloc(sizeof(primary_message_BRUSA_ACT_I));
    (*devices)[primary_INDEX_BRUSA_ACT_I].message_conversion = NULL;
    (*devices)[primary_INDEX_BRUSA_ACT_II].id = 612;
    (*devices)[primary_INDEX_BRUSA_ACT_II].message_raw = (void*) malloc(sizeof(primary_message_BRUSA_ACT_II));
    (*devices)[primary_INDEX_BRUSA_ACT_II].message_conversion = NULL;
    (*devices)[primary_INDEX_BRUSA_TEMP].id = 613;
    (*devices)[primary_INDEX_BRUSA_TEMP].message_raw = (void*) malloc(sizeof(primary_message_BRUSA_TEMP));
    (*devices)[primary_INDEX_BRUSA_TEMP].message_conversion = NULL;
    (*devices)[primary_INDEX_BRUSA_ERR].id = 614;
    (*devices)[primary_INDEX_BRUSA_ERR].message_raw = (void*) malloc(sizeof(primary_message_BRUSA_ERR));
    (*devices)[primary_INDEX_BRUSA_ERR].message_conversion = NULL;
    (*devices)[primary_INDEX_BMS_HV_CHIMERA].id = 170;
    (*devices)[primary_INDEX_BMS_HV_CHIMERA].message_raw = (void*) malloc(sizeof(primary_message_BMS_HV_CHIMERA));
    (*devices)[primary_INDEX_BMS_HV_CHIMERA].message_conversion = NULL;
    (*devices)[primary_INDEX_ECU_CHIMERA].id = 85;
    (*devices)[primary_INDEX_ECU_CHIMERA].message_raw = (void*) malloc(sizeof(primary_message_ECU_CHIMERA));
    (*devices)[primary_INDEX_ECU_CHIMERA].message_conversion = NULL;
    return devices;
}

void primary_devices_free(primary_devices* devices) {
    free((*devices)[primary_INDEX_BMS_HV_JMP_TO_BLT].message_raw);
    free((*devices)[primary_INDEX_BMS_LV_JMP_TO_BLT].message_raw);
    free((*devices)[primary_INDEX_STEER_VERSION].message_raw);
    free((*devices)[primary_INDEX_DAS_VERSION].message_raw);
    free((*devices)[primary_INDEX_HV_VERSION].message_raw);
    free((*devices)[primary_INDEX_LV_VERSION].message_raw);
    free((*devices)[primary_INDEX_TLM_VERSION].message_raw);
    free((*devices)[primary_INDEX_TIMESTAMP].message_raw);
    free((*devices)[primary_INDEX_SET_TLM_STATUS].message_raw);
    free((*devices)[primary_INDEX_TLM_STATUS].message_raw);
    free((*devices)[primary_INDEX_STEER_SYSTEM_STATUS].message_raw);
    free((*devices)[primary_INDEX_HV_VOLTAGE].message_raw);
    free((*devices)[primary_INDEX_HV_VOLTAGE].message_conversion);
    free((*devices)[primary_INDEX_HV_CURRENT].message_raw);
    free((*devices)[primary_INDEX_HV_CURRENT].message_conversion);
    free((*devices)[primary_INDEX_HV_TEMP].message_raw);
    free((*devices)[primary_INDEX_HV_TEMP].message_conversion);
    free((*devices)[primary_INDEX_HV_ERRORS].message_raw);
    free((*devices)[primary_INDEX_HV_CAN_FORWARD].message_raw);
    free((*devices)[primary_INDEX_HV_FANS_OVERRIDE].message_raw);
    free((*devices)[primary_INDEX_HV_FANS_OVERRIDE].message_conversion);
    free((*devices)[primary_INDEX_HV_CAN_FORWARD_STATUS].message_raw);
    free((*devices)[primary_INDEX_HV_FANS_OVERRIDE_STATUS].message_raw);
    free((*devices)[primary_INDEX_HV_FANS_OVERRIDE_STATUS].message_conversion);
    free((*devices)[primary_INDEX_HV_FEEDBACKS_STATUS].message_raw);
    free((*devices)[primary_INDEX_HV_IMD_STATUS].message_raw);
    free((*devices)[primary_INDEX_TS_STATUS].message_raw);
    free((*devices)[primary_INDEX_SET_TS_STATUS_DAS].message_raw);
    free((*devices)[primary_INDEX_SET_TS_STATUS_HANDCART].message_raw);
    free((*devices)[primary_INDEX_SET_TS_STATUS_DAS].message_raw);
    free((*devices)[primary_INDEX_SET_TS_STATUS_HANDCART].message_raw);
    free((*devices)[primary_INDEX_STEER_STATUS].message_raw);
    free((*devices)[primary_INDEX_SET_CAR_STATUS].message_raw);
    free((*devices)[primary_INDEX_SET_PEDALS_RANGE].message_raw);
    free((*devices)[primary_INDEX_SET_STEERING_ANGLE_RANGE].message_raw);
    free((*devices)[primary_INDEX_CAR_STATUS].message_raw);
    free((*devices)[primary_INDEX_DAS_ERRORS].message_raw);
    free((*devices)[primary_INDEX_LV_CURRENT].message_raw);
    free((*devices)[primary_INDEX_LV_CURRENT].message_conversion);
    free((*devices)[primary_INDEX_LV_VOLTAGE].message_raw);
    free((*devices)[primary_INDEX_LV_VOLTAGE].message_conversion);
    free((*devices)[primary_INDEX_LV_TOTAL_VOLTAGE].message_raw);
    free((*devices)[primary_INDEX_LV_TOTAL_VOLTAGE].message_conversion);
    free((*devices)[primary_INDEX_LV_TEMPERATURE].message_raw);
    free((*devices)[primary_INDEX_LV_TEMPERATURE].message_conversion);
    free((*devices)[primary_INDEX_COOLING_STATUS].message_raw);
    free((*devices)[primary_INDEX_COOLING_STATUS].message_conversion);
    free((*devices)[primary_INDEX_SET_RADIATOR_SPEED].message_raw);
    free((*devices)[primary_INDEX_SET_RADIATOR_SPEED].message_conversion);
    free((*devices)[primary_INDEX_SET_PUMPS_SPEED].message_raw);
    free((*devices)[primary_INDEX_SET_PUMPS_SPEED].message_conversion);
    free((*devices)[primary_INDEX_SET_INVERTER_CONNECTION_STATUS].message_raw);
    free((*devices)[primary_INDEX_INVERTER_CONNECTION_STATUS].message_raw);
    free((*devices)[primary_INDEX_LV_ERRORS].message_raw);
    free((*devices)[primary_INDEX_SHUTDOWN_STATUS].message_raw);
    free((*devices)[primary_INDEX_MARKER].message_raw);
    free((*devices)[primary_INDEX_HV_CELLS_VOLTAGE].message_raw);
    free((*devices)[primary_INDEX_HV_CELLS_VOLTAGE].message_conversion);
    free((*devices)[primary_INDEX_HV_CELLS_TEMP].message_raw);
    free((*devices)[primary_INDEX_HV_CELLS_TEMP].message_conversion);
    free((*devices)[primary_INDEX_HV_CELL_BALANCING_STATUS].message_raw);
    free((*devices)[primary_INDEX_SET_CELL_BALANCING_STATUS].message_raw);
    free((*devices)[primary_INDEX_HANDCART_STATUS].message_raw);
    free((*devices)[primary_INDEX_SPEED].message_raw);
    free((*devices)[primary_INDEX_SPEED].message_conversion);
    free((*devices)[primary_INDEX_INV_L_REQUEST].message_raw);
    free((*devices)[primary_INDEX_INV_R_REQUEST].message_raw);
    free((*devices)[primary_INDEX_INV_L_RESPONSE].message_raw);
    free((*devices)[primary_INDEX_INV_R_RESPONSE].message_raw);
    free((*devices)[primary_INDEX_FLASH_CELLBOARD_0_TX].message_raw);
    free((*devices)[primary_INDEX_FLASH_CELLBOARD_0_RX].message_raw);
    free((*devices)[primary_INDEX_FLASH_CELLBOARD_1_TX].message_raw);
    free((*devices)[primary_INDEX_FLASH_CELLBOARD_1_RX].message_raw);
    free((*devices)[primary_INDEX_FLASH_CELLBOARD_2_TX].message_raw);
    free((*devices)[primary_INDEX_FLASH_CELLBOARD_2_RX].message_raw);
    free((*devices)[primary_INDEX_FLASH_CELLBOARD_3_TX].message_raw);
    free((*devices)[primary_INDEX_FLASH_CELLBOARD_3_RX].message_raw);
    free((*devices)[primary_INDEX_FLASH_CELLBOARD_4_TX].message_raw);
    free((*devices)[primary_INDEX_FLASH_CELLBOARD_4_RX].message_raw);
    free((*devices)[primary_INDEX_FLASH_CELLBOARD_5_TX].message_raw);
    free((*devices)[primary_INDEX_FLASH_CELLBOARD_5_RX].message_raw);
    free((*devices)[primary_INDEX_FLASH_BMS_HV_TX].message_raw);
    free((*devices)[primary_INDEX_FLASH_BMS_HV_RX].message_raw);
    free((*devices)[primary_INDEX_FLASH_BMS_LV_TX].message_raw);
    free((*devices)[primary_INDEX_FLASH_BMS_LV_RX].message_raw);
    free((*devices)[primary_INDEX_BRUSA_NLG5_CTL].message_raw);
    free((*devices)[primary_INDEX_BRUSA_ST].message_raw);
    free((*devices)[primary_INDEX_BRUSA_ACT_I].message_raw);
    free((*devices)[primary_INDEX_BRUSA_ACT_II].message_raw);
    free((*devices)[primary_INDEX_BRUSA_TEMP].message_raw);
    free((*devices)[primary_INDEX_BRUSA_ERR].message_raw);
    free((*devices)[primary_INDEX_BMS_HV_CHIMERA].message_raw);
    free((*devices)[primary_INDEX_ECU_CHIMERA].message_raw);
    free(devices);
}

void primary_devices_deserialize_from_id(
    primary_devices* devices,
    canlib_message_id message_id,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
) {
    switch (message_id) {
        case 0: {
            primary_deserialize_BMS_HV_JMP_TO_BLT(
                (primary_message_BMS_HV_JMP_TO_BLT*) &(*devices)[primary_INDEX_BMS_HV_JMP_TO_BLT].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 32: {
            primary_deserialize_BMS_LV_JMP_TO_BLT(
                (primary_message_BMS_LV_JMP_TO_BLT*) &(*devices)[primary_INDEX_BMS_LV_JMP_TO_BLT].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 1025: {
            primary_deserialize_STEER_VERSION(
                (primary_message_STEER_VERSION*) &(*devices)[primary_INDEX_STEER_VERSION].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 1057: {
            primary_deserialize_DAS_VERSION(
                (primary_message_DAS_VERSION*) &(*devices)[primary_INDEX_DAS_VERSION].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 1089: {
            primary_deserialize_HV_VERSION(
                (primary_message_HV_VERSION*) &(*devices)[primary_INDEX_HV_VERSION].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 1121: {
            primary_deserialize_LV_VERSION(
                (primary_message_LV_VERSION*) &(*devices)[primary_INDEX_LV_VERSION].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 1153: {
            primary_deserialize_TLM_VERSION(
                (primary_message_TLM_VERSION*) &(*devices)[primary_INDEX_TLM_VERSION].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 257: {
            primary_deserialize_TIMESTAMP(
                (primary_message_TIMESTAMP*) &(*devices)[primary_INDEX_TIMESTAMP].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 258: {
            primary_deserialize_SET_TLM_STATUS(
                (primary_message_SET_TLM_STATUS*) &(*devices)[primary_INDEX_SET_TLM_STATUS].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 259: {
            primary_deserialize_TLM_STATUS(
                (primary_message_TLM_STATUS*) &(*devices)[primary_INDEX_TLM_STATUS].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 1794: {
            primary_deserialize_STEER_SYSTEM_STATUS(
                (primary_message_STEER_SYSTEM_STATUS*) &(*devices)[primary_INDEX_STEER_SYSTEM_STATUS].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 772: {
            primary_deserialize_HV_VOLTAGE(
                (primary_message_HV_VOLTAGE*) &(*devices)[primary_INDEX_HV_VOLTAGE].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            primary_raw_to_conversion_struct_HV_VOLTAGE(
                (primary_message_HV_VOLTAGE_conversion*) &(*devices)[primary_INDEX_HV_VOLTAGE].message_conversion,
                (primary_message_HV_VOLTAGE*) &(*devices)[primary_INDEX_HV_VOLTAGE].message_raw
            );
            return;
        }
        case 804: {
            primary_deserialize_HV_CURRENT(
                (primary_message_HV_CURRENT*) &(*devices)[primary_INDEX_HV_CURRENT].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            primary_raw_to_conversion_struct_HV_CURRENT(
                (primary_message_HV_CURRENT_conversion*) &(*devices)[primary_INDEX_HV_CURRENT].message_conversion,
                (primary_message_HV_CURRENT*) &(*devices)[primary_INDEX_HV_CURRENT].message_raw
            );
            return;
        }
        case 836: {
            primary_deserialize_HV_TEMP(
                (primary_message_HV_TEMP*) &(*devices)[primary_INDEX_HV_TEMP].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            primary_raw_to_conversion_struct_HV_TEMP(
                (primary_message_HV_TEMP_conversion*) &(*devices)[primary_INDEX_HV_TEMP].message_conversion,
                (primary_message_HV_TEMP*) &(*devices)[primary_INDEX_HV_TEMP].message_raw
            );
            return;
        }
        case 4: {
            primary_deserialize_HV_ERRORS(
                (primary_message_HV_ERRORS*) &(*devices)[primary_INDEX_HV_ERRORS].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 5: {
            primary_deserialize_HV_CAN_FORWARD(
                (primary_message_HV_CAN_FORWARD*) &(*devices)[primary_INDEX_HV_CAN_FORWARD].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 37: {
            primary_deserialize_HV_FANS_OVERRIDE(
                (primary_message_HV_FANS_OVERRIDE*) &(*devices)[primary_INDEX_HV_FANS_OVERRIDE].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            primary_raw_to_conversion_struct_HV_FANS_OVERRIDE(
                (primary_message_HV_FANS_OVERRIDE_conversion*) &(*devices)[primary_INDEX_HV_FANS_OVERRIDE].message_conversion,
                (primary_message_HV_FANS_OVERRIDE*) &(*devices)[primary_INDEX_HV_FANS_OVERRIDE].message_raw
            );
            return;
        }
        case 6: {
            primary_deserialize_HV_CAN_FORWARD_STATUS(
                (primary_message_HV_CAN_FORWARD_STATUS*) &(*devices)[primary_INDEX_HV_CAN_FORWARD_STATUS].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 774: {
            primary_deserialize_HV_FANS_OVERRIDE_STATUS(
                (primary_message_HV_FANS_OVERRIDE_STATUS*) &(*devices)[primary_INDEX_HV_FANS_OVERRIDE_STATUS].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            primary_raw_to_conversion_struct_HV_FANS_OVERRIDE_STATUS(
                (primary_message_HV_FANS_OVERRIDE_STATUS_conversion*) &(*devices)[primary_INDEX_HV_FANS_OVERRIDE_STATUS].message_conversion,
                (primary_message_HV_FANS_OVERRIDE_STATUS*) &(*devices)[primary_INDEX_HV_FANS_OVERRIDE_STATUS].message_raw
            );
            return;
        }
        case 775: {
            primary_deserialize_HV_FEEDBACKS_STATUS(
                (primary_message_HV_FEEDBACKS_STATUS*) &(*devices)[primary_INDEX_HV_FEEDBACKS_STATUS].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 807: {
            primary_deserialize_HV_IMD_STATUS(
                (primary_message_HV_IMD_STATUS*) &(*devices)[primary_INDEX_HV_IMD_STATUS].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 36: {
            primary_deserialize_TS_STATUS(
                (primary_message_TS_STATUS*) &(*devices)[primary_INDEX_TS_STATUS].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 69: {
            primary_deserialize_SET_TS_STATUS(
                (primary_message_SET_TS_STATUS*) &(*devices)[primary_INDEX_SET_TS_STATUS_DAS].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 101: {
            primary_deserialize_SET_TS_STATUS(
                (primary_message_SET_TS_STATUS*) &(*devices)[primary_INDEX_SET_TS_STATUS_HANDCART].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 264: {
            primary_deserialize_STEER_STATUS(
                (primary_message_STEER_STATUS*) &(*devices)[primary_INDEX_STEER_STATUS].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 776: {
            primary_deserialize_SET_CAR_STATUS(
                (primary_message_SET_CAR_STATUS*) &(*devices)[primary_INDEX_SET_CAR_STATUS].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 1032: {
            primary_deserialize_SET_PEDALS_RANGE(
                (primary_message_SET_PEDALS_RANGE*) &(*devices)[primary_INDEX_SET_PEDALS_RANGE].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 1064: {
            primary_deserialize_SET_STEERING_ANGLE_RANGE(
                (primary_message_SET_STEERING_ANGLE_RANGE*) &(*devices)[primary_INDEX_SET_STEERING_ANGLE_RANGE].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 515: {
            primary_deserialize_CAR_STATUS(
                (primary_message_CAR_STATUS*) &(*devices)[primary_INDEX_CAR_STATUS].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 3: {
            primary_deserialize_DAS_ERRORS(
                (primary_message_DAS_ERRORS*) &(*devices)[primary_INDEX_DAS_ERRORS].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 839: {
            primary_deserialize_LV_CURRENT(
                (primary_message_LV_CURRENT*) &(*devices)[primary_INDEX_LV_CURRENT].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            primary_raw_to_conversion_struct_LV_CURRENT(
                (primary_message_LV_CURRENT_conversion*) &(*devices)[primary_INDEX_LV_CURRENT].message_conversion,
                (primary_message_LV_CURRENT*) &(*devices)[primary_INDEX_LV_CURRENT].message_raw
            );
            return;
        }
        case 871: {
            primary_deserialize_LV_VOLTAGE(
                (primary_message_LV_VOLTAGE*) &(*devices)[primary_INDEX_LV_VOLTAGE].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            primary_raw_to_conversion_struct_LV_VOLTAGE(
                (primary_message_LV_VOLTAGE_conversion*) &(*devices)[primary_INDEX_LV_VOLTAGE].message_conversion,
                (primary_message_LV_VOLTAGE*) &(*devices)[primary_INDEX_LV_VOLTAGE].message_raw
            );
            return;
        }
        case 903: {
            primary_deserialize_LV_TOTAL_VOLTAGE(
                (primary_message_LV_TOTAL_VOLTAGE*) &(*devices)[primary_INDEX_LV_TOTAL_VOLTAGE].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            primary_raw_to_conversion_struct_LV_TOTAL_VOLTAGE(
                (primary_message_LV_TOTAL_VOLTAGE_conversion*) &(*devices)[primary_INDEX_LV_TOTAL_VOLTAGE].message_conversion,
                (primary_message_LV_TOTAL_VOLTAGE*) &(*devices)[primary_INDEX_LV_TOTAL_VOLTAGE].message_raw
            );
            return;
        }
        case 935: {
            primary_deserialize_LV_TEMPERATURE(
                (primary_message_LV_TEMPERATURE*) &(*devices)[primary_INDEX_LV_TEMPERATURE].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            primary_raw_to_conversion_struct_LV_TEMPERATURE(
                (primary_message_LV_TEMPERATURE_conversion*) &(*devices)[primary_INDEX_LV_TEMPERATURE].message_conversion,
                (primary_message_LV_TEMPERATURE*) &(*devices)[primary_INDEX_LV_TEMPERATURE].message_raw
            );
            return;
        }
        case 967: {
            primary_deserialize_COOLING_STATUS(
                (primary_message_COOLING_STATUS*) &(*devices)[primary_INDEX_COOLING_STATUS].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            primary_raw_to_conversion_struct_COOLING_STATUS(
                (primary_message_COOLING_STATUS_conversion*) &(*devices)[primary_INDEX_COOLING_STATUS].message_conversion,
                (primary_message_COOLING_STATUS*) &(*devices)[primary_INDEX_COOLING_STATUS].message_raw
            );
            return;
        }
        case 777: {
            primary_deserialize_SET_RADIATOR_SPEED(
                (primary_message_SET_RADIATOR_SPEED*) &(*devices)[primary_INDEX_SET_RADIATOR_SPEED].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            primary_raw_to_conversion_struct_SET_RADIATOR_SPEED(
                (primary_message_SET_RADIATOR_SPEED_conversion*) &(*devices)[primary_INDEX_SET_RADIATOR_SPEED].message_conversion,
                (primary_message_SET_RADIATOR_SPEED*) &(*devices)[primary_INDEX_SET_RADIATOR_SPEED].message_raw
            );
            return;
        }
        case 809: {
            primary_deserialize_SET_PUMPS_SPEED(
                (primary_message_SET_PUMPS_SPEED*) &(*devices)[primary_INDEX_SET_PUMPS_SPEED].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            primary_raw_to_conversion_struct_SET_PUMPS_SPEED(
                (primary_message_SET_PUMPS_SPEED_conversion*) &(*devices)[primary_INDEX_SET_PUMPS_SPEED].message_conversion,
                (primary_message_SET_PUMPS_SPEED*) &(*devices)[primary_INDEX_SET_PUMPS_SPEED].message_raw
            );
            return;
        }
        case 265: {
            primary_deserialize_SET_INVERTER_CONNECTION_STATUS(
                (primary_message_SET_INVERTER_CONNECTION_STATUS*) &(*devices)[primary_INDEX_SET_INVERTER_CONNECTION_STATUS].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 263: {
            primary_deserialize_INVERTER_CONNECTION_STATUS(
                (primary_message_INVERTER_CONNECTION_STATUS*) &(*devices)[primary_INDEX_INVERTER_CONNECTION_STATUS].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 7: {
            primary_deserialize_LV_ERRORS(
                (primary_message_LV_ERRORS*) &(*devices)[primary_INDEX_LV_ERRORS].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 295: {
            primary_deserialize_SHUTDOWN_STATUS(
                (primary_message_SHUTDOWN_STATUS*) &(*devices)[primary_INDEX_SHUTDOWN_STATUS].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 2: {
            primary_deserialize_MARKER(
                (primary_message_MARKER*) &(*devices)[primary_INDEX_MARKER].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 518: {
            primary_deserialize_HV_CELLS_VOLTAGE(
                (primary_message_HV_CELLS_VOLTAGE*) &(*devices)[primary_INDEX_HV_CELLS_VOLTAGE].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            primary_raw_to_conversion_struct_HV_CELLS_VOLTAGE(
                (primary_message_HV_CELLS_VOLTAGE_conversion*) &(*devices)[primary_INDEX_HV_CELLS_VOLTAGE].message_conversion,
                (primary_message_HV_CELLS_VOLTAGE*) &(*devices)[primary_INDEX_HV_CELLS_VOLTAGE].message_raw
            );
            return;
        }
        case 550: {
            primary_deserialize_HV_CELLS_TEMP(
                (primary_message_HV_CELLS_TEMP*) &(*devices)[primary_INDEX_HV_CELLS_TEMP].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            primary_raw_to_conversion_struct_HV_CELLS_TEMP(
                (primary_message_HV_CELLS_TEMP_conversion*) &(*devices)[primary_INDEX_HV_CELLS_TEMP].message_conversion,
                (primary_message_HV_CELLS_TEMP*) &(*devices)[primary_INDEX_HV_CELLS_TEMP].message_raw
            );
            return;
        }
        case 582: {
            primary_deserialize_HV_CELL_BALANCING_STATUS(
                (primary_message_HV_CELL_BALANCING_STATUS*) &(*devices)[primary_INDEX_HV_CELL_BALANCING_STATUS].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 517: {
            primary_deserialize_SET_CELL_BALANCING_STATUS(
                (primary_message_SET_CELL_BALANCING_STATUS*) &(*devices)[primary_INDEX_SET_CELL_BALANCING_STATUS].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 773: {
            primary_deserialize_HANDCART_STATUS(
                (primary_message_HANDCART_STATUS*) &(*devices)[primary_INDEX_HANDCART_STATUS].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 547: {
            primary_deserialize_SPEED(
                (primary_message_SPEED*) &(*devices)[primary_INDEX_SPEED].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            primary_raw_to_conversion_struct_SPEED(
                (primary_message_SPEED_conversion*) &(*devices)[primary_INDEX_SPEED].message_conversion,
                (primary_message_SPEED*) &(*devices)[primary_INDEX_SPEED].message_raw
            );
            return;
        }
        case 513: {
            primary_deserialize_INV_L_REQUEST(
                (primary_message_INV_L_REQUEST*) &(*devices)[primary_INDEX_INV_L_REQUEST].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 514: {
            primary_deserialize_INV_R_REQUEST(
                (primary_message_INV_R_REQUEST*) &(*devices)[primary_INDEX_INV_R_REQUEST].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 385: {
            primary_deserialize_INV_L_RESPONSE(
                (primary_message_INV_L_RESPONSE*) &(*devices)[primary_INDEX_INV_L_RESPONSE].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 386: {
            primary_deserialize_INV_R_RESPONSE(
                (primary_message_INV_R_RESPONSE*) &(*devices)[primary_INDEX_INV_R_RESPONSE].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 16: {
            primary_deserialize_FLASH_CELLBOARD_0_TX(
                (primary_message_FLASH_CELLBOARD_0_TX*) &(*devices)[primary_INDEX_FLASH_CELLBOARD_0_TX].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 17: {
            primary_deserialize_FLASH_CELLBOARD_0_RX(
                (primary_message_FLASH_CELLBOARD_0_RX*) &(*devices)[primary_INDEX_FLASH_CELLBOARD_0_RX].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 18: {
            primary_deserialize_FLASH_CELLBOARD_1_TX(
                (primary_message_FLASH_CELLBOARD_1_TX*) &(*devices)[primary_INDEX_FLASH_CELLBOARD_1_TX].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 19: {
            primary_deserialize_FLASH_CELLBOARD_1_RX(
                (primary_message_FLASH_CELLBOARD_1_RX*) &(*devices)[primary_INDEX_FLASH_CELLBOARD_1_RX].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 20: {
            primary_deserialize_FLASH_CELLBOARD_2_TX(
                (primary_message_FLASH_CELLBOARD_2_TX*) &(*devices)[primary_INDEX_FLASH_CELLBOARD_2_TX].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 21: {
            primary_deserialize_FLASH_CELLBOARD_2_RX(
                (primary_message_FLASH_CELLBOARD_2_RX*) &(*devices)[primary_INDEX_FLASH_CELLBOARD_2_RX].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 22: {
            primary_deserialize_FLASH_CELLBOARD_3_TX(
                (primary_message_FLASH_CELLBOARD_3_TX*) &(*devices)[primary_INDEX_FLASH_CELLBOARD_3_TX].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 23: {
            primary_deserialize_FLASH_CELLBOARD_3_RX(
                (primary_message_FLASH_CELLBOARD_3_RX*) &(*devices)[primary_INDEX_FLASH_CELLBOARD_3_RX].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 24: {
            primary_deserialize_FLASH_CELLBOARD_4_TX(
                (primary_message_FLASH_CELLBOARD_4_TX*) &(*devices)[primary_INDEX_FLASH_CELLBOARD_4_TX].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 25: {
            primary_deserialize_FLASH_CELLBOARD_4_RX(
                (primary_message_FLASH_CELLBOARD_4_RX*) &(*devices)[primary_INDEX_FLASH_CELLBOARD_4_RX].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 26: {
            primary_deserialize_FLASH_CELLBOARD_5_TX(
                (primary_message_FLASH_CELLBOARD_5_TX*) &(*devices)[primary_INDEX_FLASH_CELLBOARD_5_TX].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 27: {
            primary_deserialize_FLASH_CELLBOARD_5_RX(
                (primary_message_FLASH_CELLBOARD_5_RX*) &(*devices)[primary_INDEX_FLASH_CELLBOARD_5_RX].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 2017: {
            primary_deserialize_FLASH_BMS_HV_TX(
                (primary_message_FLASH_BMS_HV_TX*) &(*devices)[primary_INDEX_FLASH_BMS_HV_TX].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 1639: {
            primary_deserialize_FLASH_BMS_HV_RX(
                (primary_message_FLASH_BMS_HV_RX*) &(*devices)[primary_INDEX_FLASH_BMS_HV_RX].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 2033: {
            primary_deserialize_FLASH_BMS_LV_TX(
                (primary_message_FLASH_BMS_LV_TX*) &(*devices)[primary_INDEX_FLASH_BMS_LV_TX].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 1655: {
            primary_deserialize_FLASH_BMS_LV_RX(
                (primary_message_FLASH_BMS_LV_RX*) &(*devices)[primary_INDEX_FLASH_BMS_LV_RX].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 618: {
            primary_deserialize_BRUSA_NLG5_CTL(
                (primary_message_BRUSA_NLG5_CTL*) &(*devices)[primary_INDEX_BRUSA_NLG5_CTL].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 610: {
            primary_deserialize_BRUSA_ST(
                (primary_message_BRUSA_ST*) &(*devices)[primary_INDEX_BRUSA_ST].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 611: {
            primary_deserialize_BRUSA_ACT_I(
                (primary_message_BRUSA_ACT_I*) &(*devices)[primary_INDEX_BRUSA_ACT_I].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 612: {
            primary_deserialize_BRUSA_ACT_II(
                (primary_message_BRUSA_ACT_II*) &(*devices)[primary_INDEX_BRUSA_ACT_II].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 613: {
            primary_deserialize_BRUSA_TEMP(
                (primary_message_BRUSA_TEMP*) &(*devices)[primary_INDEX_BRUSA_TEMP].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 614: {
            primary_deserialize_BRUSA_ERR(
                (primary_message_BRUSA_ERR*) &(*devices)[primary_INDEX_BRUSA_ERR].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 170: {
            primary_deserialize_BMS_HV_CHIMERA(
                (primary_message_BMS_HV_CHIMERA*) &(*devices)[primary_INDEX_BMS_HV_CHIMERA].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 85: {
            primary_deserialize_ECU_CHIMERA(
                (primary_message_ECU_CHIMERA*) &(*devices)[primary_INDEX_ECU_CHIMERA].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
    }
}

#endif // primary_NETWORK_IMPLEMENTATION

#ifdef __cplusplus
}
#endif

#endif // primary_NETWORK_H