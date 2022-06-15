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

#define CANLIB_UNUSED(expr) do { (void)(expr); } while (0)

#define PRIf32 "f"
#define PRIf64 "f"

#endif // CANLIB_SHARED

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

#ifndef CANLIB_SEPARATOR
#define CANLIB_SEPARATOR ","
#endif // CANLIB_SEPARATOR

#ifndef CANLIB_MESSAGE_ID_TYPE
#define CANLIB_MESSAGE_ID_TYPE
typedef uint16_t canlib_message_id;
#endif // CANLIB_MESSAGE_ID_TYPE

// Info

#define primary_NUMBER_OF_MESSAGES 58

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
    void* raw_message;
    void* conversion_message;
} primary_devices[primary_NUMBER_OF_MESSAGES];

// ============== SIZES ============== //


#define primary_BMS_HV_JMP_TO_BLT_SIZE 0
#define primary_STEER_VERSION_SIZE 2
#define primary_DAS_VERSION_SIZE 2
#define primary_HV_VERSION_SIZE 2
#define primary_LV_VERSION_SIZE 2
#define primary_TLM_VERSION_SIZE 2
#define primary_TIMESTAMP_SIZE 4
#define primary_SET_TLM_STATUS_SIZE 3
#define primary_TLM_STATUS_SIZE 3
#define primary_STEER_SYSTEM_STATUS_SIZE 1
#define primary_HV_VOLTAGE_SIZE 8
#define primary_HV_CURRENT_SIZE 4
#define primary_HV_TEMP_SIZE 3
#define primary_HV_ERRORS_SIZE 4
#define primary_HV_CAN_FORWARD_SIZE 1
#define primary_HV_CAN_FORWARD_STATUS_SIZE 1
#define primary_TS_STATUS_SIZE 1
#define primary_SET_TS_STATUS_SIZE 1
#define primary_STEER_STATUS_SIZE 1
#define primary_SET_CAR_STATUS_SIZE 1
#define primary_SET_PEDALS_RANGE_SIZE 1
#define primary_SET_STEERING_ANGLE_RANGE_SIZE 1
#define primary_CAR_STATUS_SIZE 1
#define primary_DAS_ERRORS_SIZE 1
#define primary_LV_CURRENT_SIZE 2
#define primary_LV_VOLTAGE_SIZE 8
#define primary_LV_TOTAL_VOLTAGE_SIZE 4
#define primary_LV_TEMPERATURE_SIZE 8
#define primary_COOLING_STATUS_SIZE 6
#define primary_SET_RADIATOR_SPEED_SIZE 1
#define primary_SET_PUMPS_SPEED_SIZE 1
#define primary_SET_INVERTER_CONNECTION_STATUS_SIZE 1
#define primary_INVERTER_CONNECTION_STATUS_SIZE 1
#define primary_SHUTDOWN_STATUS_SIZE 1
#define primary_MARKER_SIZE 0
#define primary_HV_CELLS_VOLTAGE_SIZE 7
#define primary_HV_CELLS_TEMP_SIZE 8
#define primary_HV_CELL_BALANCING_STATUS_SIZE 1
#define primary_SET_CELL_BALANCING_STATUS_SIZE 1
#define primary_HANDCART_STATUS_SIZE 1
#define primary_SPEED_SIZE 4
#define primary_INV_L_REQUEST_SIZE 8
#define primary_INV_R_REQUEST_SIZE 8
#define primary_INV_L_RESPONSE_SIZE 8
#define primary_INV_R_RESPONSE_SIZE 8
#define primary_FLASH_CELLBOARD_0_TX_SIZE 0
#define primary_FLASH_CELLBOARD_0_RX_SIZE 0
#define primary_FLASH_CELLBOARD_1_TX_SIZE 0
#define primary_FLASH_CELLBOARD_1_RX_SIZE 0
#define primary_FLASH_CELLBOARD_2_TX_SIZE 0
#define primary_FLASH_CELLBOARD_2_RX_SIZE 0
#define primary_FLASH_CELLBOARD_3_TX_SIZE 0
#define primary_FLASH_CELLBOARD_3_RX_SIZE 0
#define primary_FLASH_CELLBOARD_4_TX_SIZE 0
#define primary_FLASH_CELLBOARD_4_RX_SIZE 0
#define primary_FLASH_CELLBOARD_5_TX_SIZE 0
#define primary_FLASH_CELLBOARD_5_RX_SIZE 0

// ============== BIT SETS ============== //


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

typedef primary_uint8 primary_DasErrors;
#define primary_DasErrors_DEFAULT 0
#define primary_DasErrors_PEDAL_ADC 1
#define primary_DasErrors_PEDAL_IMPLAUSIBILITY 2
#define primary_DasErrors_IMU_TOUT 4
#define primary_DasErrors_IRTS_TOUT 8
#define primary_DasErrors_TS_TOUT 16
#define primary_DasErrors_INVL_TOUT 32
#define primary_DasErrors_INVR_TOUT 64
#define primary_DasErrors_FSM 128

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


// ============== ENUMS ============== //


typedef enum CANLIB_PARKING {
    primary_RaceType_ACCELERATION = 0,
    primary_RaceType_SKIDPAD = 1,
    primary_RaceType_AUTOCROSS = 2,
    primary_RaceType_ENDURANCE = 3,
} primary_RaceType;

typedef enum CANLIB_PARKING {
    primary_InverterStatus_OFF = 0,
    primary_InverterStatus_IDLE = 1,
    primary_InverterStatus_ON = 2,
} primary_InverterStatus;

typedef enum CANLIB_PARKING {
    primary_CarStatus_IDLE = 0,
    primary_CarStatus_SETUP = 1,
    primary_CarStatus_RUN = 2,
} primary_CarStatus;

typedef enum CANLIB_PARKING {
    primary_Toggle_ON = 0,
    primary_Toggle_OFF = 1,
} primary_Toggle;

typedef enum CANLIB_PARKING {
    primary_TractionControl_OFF = 0,
    primary_TractionControl_SLIP_CONTROL = 1,
    primary_TractionControl_TORQUE_VECTORING = 2,
    primary_TractionControl_COMPLETE = 3,
} primary_TractionControl;

typedef enum CANLIB_PARKING {
    primary_TsStatus_OFF = 0,
    primary_TsStatus_PRECHARGE = 1,
    primary_TsStatus_ON = 2,
    primary_TsStatus_FATAL = 3,
} primary_TsStatus;

typedef enum CANLIB_PARKING {
    primary_Map_R = 0,
    primary_Map_D20 = 1,
    primary_Map_D40 = 2,
    primary_Map_D60 = 3,
    primary_Map_D80 = 4,
    primary_Map_D100 = 5,
} primary_Map;

typedef enum CANLIB_PARKING {
    primary_SetCarStatus_IDLE = 0,
    primary_SetCarStatus_RUN = 1,
} primary_SetCarStatus;

typedef enum CANLIB_PARKING {
    primary_Bound_SET_MAX = 0,
    primary_Bound_SET_MIN = 1,
} primary_Bound;

typedef enum CANLIB_PARKING {
    primary_Pedal_ACCELERATOR = 0,
    primary_Pedal_BRAKE = 1,
} primary_Pedal;

typedef enum CANLIB_PARKING {
    primary_Cooling_MAX = 0,
    primary_Cooling_OFF = 1,
} primary_Cooling;


// Structs


typedef struct CANLIB_PARKING {
    primary_uint8 _placeholder; // C++ doesn't like empty structs
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_BMS_HV_JMP_TO_BLT;

typedef struct CANLIB_PARKING {
    primary_uint8 component_version;
    primary_uint8 cancicd_version;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_STEER_VERSION;

typedef struct CANLIB_PARKING {
    primary_uint8 component_version;
    primary_uint8 cancicd_version;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_DAS_VERSION;

typedef struct CANLIB_PARKING {
    primary_uint8 component_version;
    primary_uint8 cancicd_version;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_HV_VERSION;

typedef struct CANLIB_PARKING {
    primary_uint8 component_version;
    primary_uint8 cancicd_version;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_LV_VERSION;

typedef struct CANLIB_PARKING {
    primary_uint8 component_version;
    primary_uint8 cancicd_version;
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
    primary_uint8 driver;
    primary_uint8 circuit;
    primary_RaceType race_type;
    primary_Toggle tlm_status;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_SET_TLM_STATUS;

typedef struct CANLIB_PARKING {
    primary_uint8 driver;
    primary_uint8 circuit;
    primary_RaceType race_type;
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
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_HV_CURRENT;
typedef struct CANLIB_PARKING {
    primary_float32 current;
    primary_float32 power;
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
    primary_Toggle can_forward_status;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_HV_CAN_FORWARD_STATUS;

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
    primary_Map map;
    primary_TractionControl traction_control;
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
    primary_uint16 inverters_radiator_speed;
    primary_uint16 motors_radiator_speed;
    primary_uint16 pump_speed;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_COOLING_STATUS;
typedef struct CANLIB_PARKING {
    primary_float32 inverters_radiator_speed;
    primary_float32 motors_radiator_speed;
    primary_float32 pump_speed;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_COOLING_STATUS_conversion;

typedef struct CANLIB_PARKING {
    primary_Cooling radiator_speed;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_SET_RADIATOR_SPEED;

typedef struct CANLIB_PARKING {
    primary_Cooling pumps_speed;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_SET_PUMPS_SPEED;

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
    primary_bool in;
    primary_bool end;
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
    primary_uint16 voltage_0;
    primary_uint16 voltage_1;
    primary_uint16 voltage_2;
    primary_uint8 start_index;
#ifdef CANLIB_TIMESTAMP
    primary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} primary_message_HV_CELLS_VOLTAGE;
typedef struct CANLIB_PARKING {
    primary_float32 voltage_0;
    primary_float32 voltage_1;
    primary_float32 voltage_2;
    primary_uint8 start_index;
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
    primary_uint8 temp_6;
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
    primary_float32 temp_6;
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


// ============== STEER_VERSION ============== //

primary_byte_size primary_serialize_STEER_VERSION(
    uint8_t* data,
    primary_uint8 component_version,
    primary_uint8 cancicd_version
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
    primary_uint8 cancicd_version
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
    primary_uint8 cancicd_version
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
    primary_uint8 cancicd_version
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
    primary_uint8 cancicd_version
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
    primary_uint8 driver,
    primary_uint8 circuit,
    primary_RaceType race_type,
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
    primary_uint8 driver,
    primary_uint8 circuit,
    primary_RaceType race_type,
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
    primary_uint16 power
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
    primary_float32 power
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
);

void primary_raw_to_conversion_HV_CURRENT(
    primary_message_HV_CURRENT_conversion* conversion,
    primary_uint16 current,
    primary_uint16 power
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
    primary_Map map,
    primary_TractionControl traction_control
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
    primary_uint16 inverters_radiator_speed,
    primary_uint16 motors_radiator_speed,
    primary_uint16 pump_speed
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
    primary_float32 inverters_radiator_speed,
    primary_float32 motors_radiator_speed,
    primary_float32 pump_speed
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
);

void primary_raw_to_conversion_COOLING_STATUS(
    primary_message_COOLING_STATUS_conversion* conversion,
    primary_uint16 inverters_radiator_speed,
    primary_uint16 motors_radiator_speed,
    primary_uint16 pump_speed
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
    primary_Cooling radiator_speed
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
int primary_to_string_SET_RADIATOR_SPEED(primary_message_SET_RADIATOR_SPEED* message, char* buffer);
int primary_fields_SET_RADIATOR_SPEED(char* buffer);
int primary_to_string_file_SET_RADIATOR_SPEED(primary_message_SET_RADIATOR_SPEED* message, FILE* buffer);
int primary_fields_file_SET_RADIATOR_SPEED(FILE* buffer);


// ============== SET_PUMPS_SPEED ============== //

primary_byte_size primary_serialize_SET_PUMPS_SPEED(
    uint8_t* data,
    primary_Cooling pumps_speed
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
int primary_to_string_SET_PUMPS_SPEED(primary_message_SET_PUMPS_SPEED* message, char* buffer);
int primary_fields_SET_PUMPS_SPEED(char* buffer);
int primary_to_string_file_SET_PUMPS_SPEED(primary_message_SET_PUMPS_SPEED* message, FILE* buffer);
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


// ============== SHUTDOWN_STATUS ============== //

primary_byte_size primary_serialize_SHUTDOWN_STATUS(
    uint8_t* data,
    primary_bool in,
    primary_bool end
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
    primary_uint16 voltage_0,
    primary_uint16 voltage_1,
    primary_uint16 voltage_2,
    primary_uint8 start_index
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
    primary_float32 voltage_0,
    primary_float32 voltage_1,
    primary_float32 voltage_2,
    primary_uint8 start_index
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
);

void primary_raw_to_conversion_HV_CELLS_VOLTAGE(
    primary_message_HV_CELLS_VOLTAGE_conversion* conversion,
    primary_uint16 voltage_0,
    primary_uint16 voltage_1,
    primary_uint16 voltage_2,
    primary_uint8 start_index
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
    primary_uint8 temp_5,
    primary_uint8 temp_6
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
    primary_float32 temp_5,
    primary_float32 temp_6
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
    primary_uint8 temp_5,
    primary_uint8 temp_6
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




// ============== UTILS ============== //

void primary_devices_new(primary_devices* map);
int primary_devices_index_from_id(canlib_message_id message_id, primary_devices* map);
void primary_fields_from_id(canlib_message_id message_id, FILE *buffer);
void primary_string_from_id(canlib_message_id message_id, void* message, FILE *buffer);
void primary_deserialize_from_id(
    canlib_message_id message_id,
    uint8_t* data,
    void* raw_message,
    void* message
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);

#ifdef primary_IMPLEMENTATION
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

primary_byte_size primary_serialize_STEER_VERSION(
    uint8_t* data,
    primary_uint8 component_version,
    primary_uint8 cancicd_version
) {
    data[0] = component_version;
    data[1] = cancicd_version;
    return 2;
}

primary_byte_size primary_serialize_struct_STEER_VERSION(
    uint8_t* data,
    primary_message_STEER_VERSION* message
) {
    data[0] = message->component_version;
    data[1] = message->cancicd_version;
    return 2;
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
    message->component_version = data[0];
    message->cancicd_version = data[1];
}

// ============== STRING ============== //

int primary_to_string_STEER_VERSION(primary_message_STEER_VERSION* message, char* buffer) {
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
        "%" PRIu8,
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
    primary_uint8 cancicd_version
) {
    data[0] = component_version;
    data[1] = cancicd_version;
    return 2;
}

primary_byte_size primary_serialize_struct_DAS_VERSION(
    uint8_t* data,
    primary_message_DAS_VERSION* message
) {
    data[0] = message->component_version;
    data[1] = message->cancicd_version;
    return 2;
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
    message->component_version = data[0];
    message->cancicd_version = data[1];
}

// ============== STRING ============== //

int primary_to_string_DAS_VERSION(primary_message_DAS_VERSION* message, char* buffer) {
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
        "%" PRIu8,
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
    primary_uint8 cancicd_version
) {
    data[0] = component_version;
    data[1] = cancicd_version;
    return 2;
}

primary_byte_size primary_serialize_struct_HV_VERSION(
    uint8_t* data,
    primary_message_HV_VERSION* message
) {
    data[0] = message->component_version;
    data[1] = message->cancicd_version;
    return 2;
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
    message->component_version = data[0];
    message->cancicd_version = data[1];
}

// ============== STRING ============== //

int primary_to_string_HV_VERSION(primary_message_HV_VERSION* message, char* buffer) {
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
        "%" PRIu8,
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
    primary_uint8 cancicd_version
) {
    data[0] = component_version;
    data[1] = cancicd_version;
    return 2;
}

primary_byte_size primary_serialize_struct_LV_VERSION(
    uint8_t* data,
    primary_message_LV_VERSION* message
) {
    data[0] = message->component_version;
    data[1] = message->cancicd_version;
    return 2;
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
    message->component_version = data[0];
    message->cancicd_version = data[1];
}

// ============== STRING ============== //

int primary_to_string_LV_VERSION(primary_message_LV_VERSION* message, char* buffer) {
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
        "%" PRIu8,
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
    primary_uint8 cancicd_version
) {
    data[0] = component_version;
    data[1] = cancicd_version;
    return 2;
}

primary_byte_size primary_serialize_struct_TLM_VERSION(
    uint8_t* data,
    primary_message_TLM_VERSION* message
) {
    data[0] = message->component_version;
    data[1] = message->cancicd_version;
    return 2;
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
    message->component_version = data[0];
    message->cancicd_version = data[1];
}

// ============== STRING ============== //

int primary_to_string_TLM_VERSION(primary_message_TLM_VERSION* message, char* buffer) {
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
        "%" PRIu8,
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
    primary_uint8 driver,
    primary_uint8 circuit,
    primary_RaceType race_type,
    primary_Toggle tlm_status
) {
    data[0] = driver;
    data[1] = circuit;
    data[2] = race_type << 6 | tlm_status << 5;
    return 3;
}

primary_byte_size primary_serialize_struct_SET_TLM_STATUS(
    uint8_t* data,
    primary_message_SET_TLM_STATUS* message
) {
    data[0] = message->driver;
    data[1] = message->circuit;
    data[2] = message->race_type << 6 | message->tlm_status << 5;
    return 3;
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
    message->driver = data[0];
    message->circuit = data[1];
    message->race_type = (primary_RaceType) ((data[2] & 192) >> 6);
    message->tlm_status = (primary_Toggle) ((data[2] & 32) >> 5);
}

// ============== STRING ============== //

int primary_to_string_SET_TLM_STATUS(primary_message_SET_TLM_STATUS* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->driver,
        message->circuit,
        message->race_type,
        message->tlm_status
    );
}
int primary_fields_SET_TLM_STATUS(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "driver" CANLIB_SEPARATOR 
        "circuit" CANLIB_SEPARATOR 
        "race_type" CANLIB_SEPARATOR 
        "tlm_status"
    );
}
int primary_to_string_file_SET_TLM_STATUS(primary_message_SET_TLM_STATUS* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->driver,
        message->circuit,
        message->race_type,
        message->tlm_status
    );
}
int primary_fields_file_SET_TLM_STATUS(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "driver" CANLIB_SEPARATOR 
        "circuit" CANLIB_SEPARATOR 
        "race_type" CANLIB_SEPARATOR 
        "tlm_status"
    );
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_TLM_STATUS(
    uint8_t* data,
    primary_uint8 driver,
    primary_uint8 circuit,
    primary_RaceType race_type,
    primary_Toggle tlm_status
) {
    data[0] = driver;
    data[1] = circuit;
    data[2] = race_type << 6 | tlm_status << 5;
    return 3;
}

primary_byte_size primary_serialize_struct_TLM_STATUS(
    uint8_t* data,
    primary_message_TLM_STATUS* message
) {
    data[0] = message->driver;
    data[1] = message->circuit;
    data[2] = message->race_type << 6 | message->tlm_status << 5;
    return 3;
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
    message->driver = data[0];
    message->circuit = data[1];
    message->race_type = (primary_RaceType) ((data[2] & 192) >> 6);
    message->tlm_status = (primary_Toggle) ((data[2] & 32) >> 5);
}

// ============== STRING ============== //

int primary_to_string_TLM_STATUS(primary_message_TLM_STATUS* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->driver,
        message->circuit,
        message->race_type,
        message->tlm_status
    );
}
int primary_fields_TLM_STATUS(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "driver" CANLIB_SEPARATOR 
        "circuit" CANLIB_SEPARATOR 
        "race_type" CANLIB_SEPARATOR 
        "tlm_status"
    );
}
int primary_to_string_file_TLM_STATUS(primary_message_TLM_STATUS* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->driver,
        message->circuit,
        message->race_type,
        message->tlm_status
    );
}
int primary_fields_file_TLM_STATUS(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "driver" CANLIB_SEPARATOR 
        "circuit" CANLIB_SEPARATOR 
        "race_type" CANLIB_SEPARATOR 
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
    conversion->pack_voltage = (((primary_float32)pack_voltage) / 142.469565) + 0;
    conversion->bus_voltage = (((primary_float32)bus_voltage) / 142.469565) + 0;
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
    conversion->pack_voltage = (((primary_float32)raw->pack_voltage) / 142.469565) + 0;
    conversion->bus_voltage = (((primary_float32)raw->bus_voltage) / 142.469565) + 0;
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
    raw->pack_voltage = (primary_uint16)((pack_voltage + 0) * 142.469565);
    raw->bus_voltage = (primary_uint16)((bus_voltage + 0) * 142.469565);
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
    raw->pack_voltage = (primary_uint16)((conversion->pack_voltage + 0) * 142.469565);
    raw->bus_voltage = (primary_uint16)((conversion->bus_voltage + 0) * 142.469565);
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
    primary_uint16 power
) {
    data[0] = current & 255;
    data[1] = (current >> 8) & 255;
    data[2] = power & 255;
    data[3] = (power >> 8) & 255;
    return 4;
}

primary_byte_size primary_serialize_struct_HV_CURRENT(
    uint8_t* data,
    primary_message_HV_CURRENT* message
) {
    data[0] = message->current & 255;
    data[1] = (message->current >> 8) & 255;
    data[2] = message->power & 255;
    data[3] = (message->power >> 8) & 255;
    return 4;
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
}// ============== CONVERSION ============== //

void primary_raw_to_conversion_HV_CURRENT(
    primary_message_HV_CURRENT_conversion* conversion,
    primary_uint16 current,
    primary_uint16 power
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
){
#ifdef CANLIB_TIMESTAMP
    conversion->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    conversion->current = (((primary_float32)current) / 312.07619) - 10;
    conversion->power = (((primary_float32)power) / 655.36) + 0;
}

void primary_raw_to_conversion_struct_HV_CURRENT(
    primary_message_HV_CURRENT_conversion* conversion,
    primary_message_HV_CURRENT* raw
){
#ifdef CANLIB_TIMESTAMP
    conversion->_timestamp = raw->_timestamp;
#endif // CANLIB_TIMESTAMP
    conversion->current = (((primary_float32)raw->current) / 312.07619) - 10;
    conversion->power = (((primary_float32)raw->power) / 655.36) + 0;
}

void primary_conversion_to_raw_HV_CURRENT(
    primary_message_HV_CURRENT* raw,
    primary_float32 current,
    primary_float32 power
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
){
#ifdef CANLIB_TIMESTAMP
    raw->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    raw->current = (primary_uint16)((current + 10) * 312.07619);
    raw->power = (primary_uint16)((power + 0) * 655.36);
}

void primary_conversion_to_raw_struct_HV_CURRENT(
    primary_message_HV_CURRENT* raw,
    primary_message_HV_CURRENT_conversion* conversion
){
#ifdef CANLIB_TIMESTAMP
    raw->_timestamp = conversion->_timestamp;
#endif // CANLIB_TIMESTAMP
    raw->current = (primary_uint16)((conversion->current + 10) * 312.07619);
    raw->power = (primary_uint16)((conversion->power + 0) * 655.36);
}

// ============== STRING ============== //

int primary_to_string_HV_CURRENT(primary_message_HV_CURRENT_conversion* message, char* buffer) {
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
        message->current,
        message->power
    );
}
int primary_fields_HV_CURRENT(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "current" CANLIB_SEPARATOR 
        "power"
    );
}
int primary_to_string_file_HV_CURRENT(primary_message_HV_CURRENT_conversion* message, FILE* buffer) {
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
        message->current,
        message->power
    );
}
int primary_fields_file_HV_CURRENT(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "current" CANLIB_SEPARATOR 
        "power"
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
    conversion->average_temp = (((primary_float32)average_temp) / 2.56) - 20;
    conversion->max_temp = (((primary_float32)max_temp) / 2.56) - 20;
    conversion->min_temp = (((primary_float32)min_temp) / 2.56) - 20;
}

void primary_raw_to_conversion_struct_HV_TEMP(
    primary_message_HV_TEMP_conversion* conversion,
    primary_message_HV_TEMP* raw
){
#ifdef CANLIB_TIMESTAMP
    conversion->_timestamp = raw->_timestamp;
#endif // CANLIB_TIMESTAMP
    conversion->average_temp = (((primary_float32)raw->average_temp) / 2.56) - 20;
    conversion->max_temp = (((primary_float32)raw->max_temp) / 2.56) - 20;
    conversion->min_temp = (((primary_float32)raw->min_temp) / 2.56) - 20;
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
    raw->average_temp = (primary_uint8)((average_temp + 20) * 2.56);
    raw->max_temp = (primary_uint8)((max_temp + 20) * 2.56);
    raw->min_temp = (primary_uint8)((min_temp + 20) * 2.56);
}

void primary_conversion_to_raw_struct_HV_TEMP(
    primary_message_HV_TEMP* raw,
    primary_message_HV_TEMP_conversion* conversion
){
#ifdef CANLIB_TIMESTAMP
    raw->_timestamp = conversion->_timestamp;
#endif // CANLIB_TIMESTAMP
    raw->average_temp = (primary_uint8)((conversion->average_temp + 20) * 2.56);
    raw->max_temp = (primary_uint8)((conversion->max_temp + 20) * 2.56);
    raw->min_temp = (primary_uint8)((conversion->min_temp + 20) * 2.56);
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
    primary_Map map,
    primary_TractionControl traction_control
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
        message->map,
        message->traction_control
    );
}
int primary_fields_STEER_STATUS(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "map" CANLIB_SEPARATOR 
        "traction_control"
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
        message->map,
        message->traction_control
    );
}
int primary_fields_file_STEER_STATUS(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "map" CANLIB_SEPARATOR 
        "traction_control"
    );
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_SET_CAR_STATUS(
    uint8_t* data,
    primary_SetCarStatus car_status_set
) {
    data[0] = car_status_set << 7;
    return 1;
}

primary_byte_size primary_serialize_struct_SET_CAR_STATUS(
    uint8_t* data,
    primary_message_SET_CAR_STATUS* message
) {
    data[0] = message->car_status_set << 7;
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
    message->car_status_set = (primary_SetCarStatus) ((data[0] & 128) >> 7);
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
    data[0] = inverter_l << 6 | inverter_r << 4 | car_status << 2;
    return 1;
}

primary_byte_size primary_serialize_struct_CAR_STATUS(
    uint8_t* data,
    primary_message_CAR_STATUS* message
) {
    data[0] = message->inverter_l << 6 | message->inverter_r << 4 | message->car_status << 2;
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
    message->inverter_l = (primary_InverterStatus) ((data[0] & 192) >> 6);
    message->inverter_r = (primary_InverterStatus) ((data[0] & 48) >> 4);
    message->car_status = (primary_CarStatus) ((data[0] & 12) >> 2);
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
    data[0] = das_error;
    return 1;
}

primary_byte_size primary_serialize_struct_DAS_ERRORS(
    uint8_t* data,
    primary_message_DAS_ERRORS* message
) {
    data[0] = message->das_error;
    return 1;
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
    message->das_error = data[0];
}

// ============== STRING ============== //

int primary_to_string_DAS_ERRORS(primary_message_DAS_ERRORS* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8,
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
        "%" PRIu8,
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
    conversion->current = (((primary_float32)current) / 1310.72) + 0;
}

void primary_raw_to_conversion_struct_LV_CURRENT(
    primary_message_LV_CURRENT_conversion* conversion,
    primary_message_LV_CURRENT* raw
){
#ifdef CANLIB_TIMESTAMP
    conversion->_timestamp = raw->_timestamp;
#endif // CANLIB_TIMESTAMP
    conversion->current = (((primary_float32)raw->current) / 1310.72) + 0;
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
    raw->current = (primary_uint16)((current + 0) * 1310.72);
}

void primary_conversion_to_raw_struct_LV_CURRENT(
    primary_message_LV_CURRENT* raw,
    primary_message_LV_CURRENT_conversion* conversion
){
#ifdef CANLIB_TIMESTAMP
    raw->_timestamp = conversion->_timestamp;
#endif // CANLIB_TIMESTAMP
    raw->current = (primary_uint16)((conversion->current + 0) * 1310.72);
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
    conversion->bp_temperature_1 = (((primary_float32)bp_temperature_1) / 655.36) - 20;
    conversion->bp_temperature_2 = (((primary_float32)bp_temperature_2) / 655.36) - 20;
    conversion->dcdc12_temperature = (((primary_float32)dcdc12_temperature) / 655.36) - 20;
    conversion->dcdc24_temperature = (((primary_float32)dcdc24_temperature) / 655.36) - 20;
}

void primary_raw_to_conversion_struct_LV_TEMPERATURE(
    primary_message_LV_TEMPERATURE_conversion* conversion,
    primary_message_LV_TEMPERATURE* raw
){
#ifdef CANLIB_TIMESTAMP
    conversion->_timestamp = raw->_timestamp;
#endif // CANLIB_TIMESTAMP
    conversion->bp_temperature_1 = (((primary_float32)raw->bp_temperature_1) / 655.36) - 20;
    conversion->bp_temperature_2 = (((primary_float32)raw->bp_temperature_2) / 655.36) - 20;
    conversion->dcdc12_temperature = (((primary_float32)raw->dcdc12_temperature) / 655.36) - 20;
    conversion->dcdc24_temperature = (((primary_float32)raw->dcdc24_temperature) / 655.36) - 20;
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
    raw->bp_temperature_1 = (primary_uint16)((bp_temperature_1 + 20) * 655.36);
    raw->bp_temperature_2 = (primary_uint16)((bp_temperature_2 + 20) * 655.36);
    raw->dcdc12_temperature = (primary_uint16)((dcdc12_temperature + 20) * 655.36);
    raw->dcdc24_temperature = (primary_uint16)((dcdc24_temperature + 20) * 655.36);
}

void primary_conversion_to_raw_struct_LV_TEMPERATURE(
    primary_message_LV_TEMPERATURE* raw,
    primary_message_LV_TEMPERATURE_conversion* conversion
){
#ifdef CANLIB_TIMESTAMP
    raw->_timestamp = conversion->_timestamp;
#endif // CANLIB_TIMESTAMP
    raw->bp_temperature_1 = (primary_uint16)((conversion->bp_temperature_1 + 20) * 655.36);
    raw->bp_temperature_2 = (primary_uint16)((conversion->bp_temperature_2 + 20) * 655.36);
    raw->dcdc12_temperature = (primary_uint16)((conversion->dcdc12_temperature + 20) * 655.36);
    raw->dcdc24_temperature = (primary_uint16)((conversion->dcdc24_temperature + 20) * 655.36);
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
    primary_uint16 inverters_radiator_speed,
    primary_uint16 motors_radiator_speed,
    primary_uint16 pump_speed
) {
    data[0] = inverters_radiator_speed & 255;
    data[1] = (inverters_radiator_speed >> 8) & 255;
    data[2] = motors_radiator_speed & 255;
    data[3] = (motors_radiator_speed >> 8) & 255;
    data[4] = pump_speed & 255;
    data[5] = (pump_speed >> 8) & 255;
    return 6;
}

primary_byte_size primary_serialize_struct_COOLING_STATUS(
    uint8_t* data,
    primary_message_COOLING_STATUS* message
) {
    data[0] = message->inverters_radiator_speed & 255;
    data[1] = (message->inverters_radiator_speed >> 8) & 255;
    data[2] = message->motors_radiator_speed & 255;
    data[3] = (message->motors_radiator_speed >> 8) & 255;
    data[4] = message->pump_speed & 255;
    data[5] = (message->pump_speed >> 8) & 255;
    return 6;
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
    message->inverters_radiator_speed = data[0] | (data[1] << 8);
    message->motors_radiator_speed = data[2] | (data[3] << 8);
    message->pump_speed = data[4] | (data[5] << 8);
}// ============== CONVERSION ============== //

void primary_raw_to_conversion_COOLING_STATUS(
    primary_message_COOLING_STATUS_conversion* conversion,
    primary_uint16 inverters_radiator_speed,
    primary_uint16 motors_radiator_speed,
    primary_uint16 pump_speed
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
){
#ifdef CANLIB_TIMESTAMP
    conversion->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    conversion->inverters_radiator_speed = (((primary_float32)inverters_radiator_speed) / 65536.0) + 0;
    conversion->motors_radiator_speed = (((primary_float32)motors_radiator_speed) / 65536.0) + 0;
    conversion->pump_speed = (((primary_float32)pump_speed) / 65536.0) + 0;
}

void primary_raw_to_conversion_struct_COOLING_STATUS(
    primary_message_COOLING_STATUS_conversion* conversion,
    primary_message_COOLING_STATUS* raw
){
#ifdef CANLIB_TIMESTAMP
    conversion->_timestamp = raw->_timestamp;
#endif // CANLIB_TIMESTAMP
    conversion->inverters_radiator_speed = (((primary_float32)raw->inverters_radiator_speed) / 65536.0) + 0;
    conversion->motors_radiator_speed = (((primary_float32)raw->motors_radiator_speed) / 65536.0) + 0;
    conversion->pump_speed = (((primary_float32)raw->pump_speed) / 65536.0) + 0;
}

void primary_conversion_to_raw_COOLING_STATUS(
    primary_message_COOLING_STATUS* raw,
    primary_float32 inverters_radiator_speed,
    primary_float32 motors_radiator_speed,
    primary_float32 pump_speed
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
){
#ifdef CANLIB_TIMESTAMP
    raw->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    raw->inverters_radiator_speed = (primary_uint16)((inverters_radiator_speed + 0) * 65536.0);
    raw->motors_radiator_speed = (primary_uint16)((motors_radiator_speed + 0) * 65536.0);
    raw->pump_speed = (primary_uint16)((pump_speed + 0) * 65536.0);
}

void primary_conversion_to_raw_struct_COOLING_STATUS(
    primary_message_COOLING_STATUS* raw,
    primary_message_COOLING_STATUS_conversion* conversion
){
#ifdef CANLIB_TIMESTAMP
    raw->_timestamp = conversion->_timestamp;
#endif // CANLIB_TIMESTAMP
    raw->inverters_radiator_speed = (primary_uint16)((conversion->inverters_radiator_speed + 0) * 65536.0);
    raw->motors_radiator_speed = (primary_uint16)((conversion->motors_radiator_speed + 0) * 65536.0);
    raw->pump_speed = (primary_uint16)((conversion->pump_speed + 0) * 65536.0);
}

// ============== STRING ============== //

int primary_to_string_COOLING_STATUS(primary_message_COOLING_STATUS_conversion* message, char* buffer) {
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
        message->inverters_radiator_speed,
        message->motors_radiator_speed,
        message->pump_speed
    );
}
int primary_fields_COOLING_STATUS(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "inverters_radiator_speed" CANLIB_SEPARATOR 
        "motors_radiator_speed" CANLIB_SEPARATOR 
        "pump_speed"
    );
}
int primary_to_string_file_COOLING_STATUS(primary_message_COOLING_STATUS_conversion* message, FILE* buffer) {
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
        message->inverters_radiator_speed,
        message->motors_radiator_speed,
        message->pump_speed
    );
}
int primary_fields_file_COOLING_STATUS(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "inverters_radiator_speed" CANLIB_SEPARATOR 
        "motors_radiator_speed" CANLIB_SEPARATOR 
        "pump_speed"
    );
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_SET_RADIATOR_SPEED(
    uint8_t* data,
    primary_Cooling radiator_speed
) {
    data[0] = radiator_speed << 7;
    return 1;
}

primary_byte_size primary_serialize_struct_SET_RADIATOR_SPEED(
    uint8_t* data,
    primary_message_SET_RADIATOR_SPEED* message
) {
    data[0] = message->radiator_speed << 7;
    return 1;
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
    message->radiator_speed = (primary_Cooling) ((data[0] & 128) >> 7);
}

// ============== STRING ============== //

int primary_to_string_SET_RADIATOR_SPEED(primary_message_SET_RADIATOR_SPEED* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->radiator_speed
    );
}
int primary_fields_SET_RADIATOR_SPEED(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "radiator_speed"
    );
}
int primary_to_string_file_SET_RADIATOR_SPEED(primary_message_SET_RADIATOR_SPEED* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->radiator_speed
    );
}
int primary_fields_file_SET_RADIATOR_SPEED(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "radiator_speed"
    );
}

// ============== SERIALIZE ============== //

primary_byte_size primary_serialize_SET_PUMPS_SPEED(
    uint8_t* data,
    primary_Cooling pumps_speed
) {
    data[0] = pumps_speed << 7;
    return 1;
}

primary_byte_size primary_serialize_struct_SET_PUMPS_SPEED(
    uint8_t* data,
    primary_message_SET_PUMPS_SPEED* message
) {
    data[0] = message->pumps_speed << 7;
    return 1;
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
    message->pumps_speed = (primary_Cooling) ((data[0] & 128) >> 7);
}

// ============== STRING ============== //

int primary_to_string_SET_PUMPS_SPEED(primary_message_SET_PUMPS_SPEED* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8,
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
int primary_to_string_file_SET_PUMPS_SPEED(primary_message_SET_PUMPS_SPEED* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8,
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

primary_byte_size primary_serialize_SHUTDOWN_STATUS(
    uint8_t* data,
    primary_bool in,
    primary_bool end
) {
    data[0] = in << 7 | end << 6;
    return 1;
}

primary_byte_size primary_serialize_struct_SHUTDOWN_STATUS(
    uint8_t* data,
    primary_message_SHUTDOWN_STATUS* message
) {
    data[0] = message->in << 7 | message->end << 6;
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
    message->in = (data[0] & 128) >> 7;
    message->end = (data[0] & 64) >> 6;
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
        message->in,
        message->end
    );
}
int primary_fields_SHUTDOWN_STATUS(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "in" CANLIB_SEPARATOR 
        "end"
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
        message->in,
        message->end
    );
}
int primary_fields_file_SHUTDOWN_STATUS(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "in" CANLIB_SEPARATOR 
        "end"
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
    primary_uint16 voltage_0,
    primary_uint16 voltage_1,
    primary_uint16 voltage_2,
    primary_uint8 start_index
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
    primary_uint16 voltage_0,
    primary_uint16 voltage_1,
    primary_uint16 voltage_2,
    primary_uint8 start_index
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
){
#ifdef CANLIB_TIMESTAMP
    conversion->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    conversion->voltage_0 = (((primary_float32)voltage_0) / 10000.0) + 0;
    conversion->voltage_1 = (((primary_float32)voltage_1) / 10000.0) + 0;
    conversion->voltage_2 = (((primary_float32)voltage_2) / 10000.0) + 0;
    conversion->start_index = start_index;
}

void primary_raw_to_conversion_struct_HV_CELLS_VOLTAGE(
    primary_message_HV_CELLS_VOLTAGE_conversion* conversion,
    primary_message_HV_CELLS_VOLTAGE* raw
){
#ifdef CANLIB_TIMESTAMP
    conversion->_timestamp = raw->_timestamp;
#endif // CANLIB_TIMESTAMP
    conversion->voltage_0 = (((primary_float32)raw->voltage_0) / 10000.0) + 0;
    conversion->voltage_1 = (((primary_float32)raw->voltage_1) / 10000.0) + 0;
    conversion->voltage_2 = (((primary_float32)raw->voltage_2) / 10000.0) + 0;
    conversion->start_index = raw->start_index;
}

void primary_conversion_to_raw_HV_CELLS_VOLTAGE(
    primary_message_HV_CELLS_VOLTAGE* raw,
    primary_float32 voltage_0,
    primary_float32 voltage_1,
    primary_float32 voltage_2,
    primary_uint8 start_index
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
){
#ifdef CANLIB_TIMESTAMP
    raw->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    raw->voltage_0 = (primary_uint16)((voltage_0 + 0) * 10000.0);
    raw->voltage_1 = (primary_uint16)((voltage_1 + 0) * 10000.0);
    raw->voltage_2 = (primary_uint16)((voltage_2 + 0) * 10000.0);
    raw->start_index = start_index;
}

void primary_conversion_to_raw_struct_HV_CELLS_VOLTAGE(
    primary_message_HV_CELLS_VOLTAGE* raw,
    primary_message_HV_CELLS_VOLTAGE_conversion* conversion
){
#ifdef CANLIB_TIMESTAMP
    raw->_timestamp = conversion->_timestamp;
#endif // CANLIB_TIMESTAMP
    raw->voltage_0 = (primary_uint16)((conversion->voltage_0 + 0) * 10000.0);
    raw->voltage_1 = (primary_uint16)((conversion->voltage_1 + 0) * 10000.0);
    raw->voltage_2 = (primary_uint16)((conversion->voltage_2 + 0) * 10000.0);
    raw->start_index = conversion->start_index;
}

// ============== STRING ============== //

int primary_to_string_HV_CELLS_VOLTAGE(primary_message_HV_CELLS_VOLTAGE_conversion* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIu8,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->voltage_0,
        message->voltage_1,
        message->voltage_2,
        message->start_index
    );
}
int primary_fields_HV_CELLS_VOLTAGE(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "voltage_0" CANLIB_SEPARATOR 
        "voltage_1" CANLIB_SEPARATOR 
        "voltage_2" CANLIB_SEPARATOR 
        "start_index"
    );
}
int primary_to_string_file_HV_CELLS_VOLTAGE(primary_message_HV_CELLS_VOLTAGE_conversion* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIu8,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->voltage_0,
        message->voltage_1,
        message->voltage_2,
        message->start_index
    );
}
int primary_fields_file_HV_CELLS_VOLTAGE(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "voltage_0" CANLIB_SEPARATOR 
        "voltage_1" CANLIB_SEPARATOR 
        "voltage_2" CANLIB_SEPARATOR 
        "start_index"
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
    primary_uint8 temp_5,
    primary_uint8 temp_6
) {
    data[0] = start_index;
    data[1] = temp_0;
    data[2] = temp_1;
    data[3] = temp_2;
    data[4] = temp_3;
    data[5] = temp_4;
    data[6] = temp_5;
    data[7] = temp_6;
    return 8;
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
    data[7] = message->temp_6;
    return 8;
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
    message->temp_6 = data[7];
}// ============== CONVERSION ============== //

void primary_raw_to_conversion_HV_CELLS_TEMP(
    primary_message_HV_CELLS_TEMP_conversion* conversion,
    primary_uint8 start_index,
    primary_uint8 temp_0,
    primary_uint8 temp_1,
    primary_uint8 temp_2,
    primary_uint8 temp_3,
    primary_uint8 temp_4,
    primary_uint8 temp_5,
    primary_uint8 temp_6
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
){
#ifdef CANLIB_TIMESTAMP
    conversion->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    conversion->start_index = start_index;
    conversion->temp_0 = (((primary_float32)temp_0) / 2.56) - 20;
    conversion->temp_1 = (((primary_float32)temp_1) / 2.56) - 20;
    conversion->temp_2 = (((primary_float32)temp_2) / 2.56) - 20;
    conversion->temp_3 = (((primary_float32)temp_3) / 2.56) - 20;
    conversion->temp_4 = (((primary_float32)temp_4) / 2.56) - 20;
    conversion->temp_5 = (((primary_float32)temp_5) / 2.56) - 20;
    conversion->temp_6 = (((primary_float32)temp_6) / 2.56) - 20;
}

void primary_raw_to_conversion_struct_HV_CELLS_TEMP(
    primary_message_HV_CELLS_TEMP_conversion* conversion,
    primary_message_HV_CELLS_TEMP* raw
){
#ifdef CANLIB_TIMESTAMP
    conversion->_timestamp = raw->_timestamp;
#endif // CANLIB_TIMESTAMP
    conversion->start_index = raw->start_index;
    conversion->temp_0 = (((primary_float32)raw->temp_0) / 2.56) - 20;
    conversion->temp_1 = (((primary_float32)raw->temp_1) / 2.56) - 20;
    conversion->temp_2 = (((primary_float32)raw->temp_2) / 2.56) - 20;
    conversion->temp_3 = (((primary_float32)raw->temp_3) / 2.56) - 20;
    conversion->temp_4 = (((primary_float32)raw->temp_4) / 2.56) - 20;
    conversion->temp_5 = (((primary_float32)raw->temp_5) / 2.56) - 20;
    conversion->temp_6 = (((primary_float32)raw->temp_6) / 2.56) - 20;
}

void primary_conversion_to_raw_HV_CELLS_TEMP(
    primary_message_HV_CELLS_TEMP* raw,
    primary_uint8 start_index,
    primary_float32 temp_0,
    primary_float32 temp_1,
    primary_float32 temp_2,
    primary_float32 temp_3,
    primary_float32 temp_4,
    primary_float32 temp_5,
    primary_float32 temp_6
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
){
#ifdef CANLIB_TIMESTAMP
    raw->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    raw->start_index = start_index;
    raw->temp_0 = (primary_uint8)((temp_0 + 20) * 2.56);
    raw->temp_1 = (primary_uint8)((temp_1 + 20) * 2.56);
    raw->temp_2 = (primary_uint8)((temp_2 + 20) * 2.56);
    raw->temp_3 = (primary_uint8)((temp_3 + 20) * 2.56);
    raw->temp_4 = (primary_uint8)((temp_4 + 20) * 2.56);
    raw->temp_5 = (primary_uint8)((temp_5 + 20) * 2.56);
    raw->temp_6 = (primary_uint8)((temp_6 + 20) * 2.56);
}

void primary_conversion_to_raw_struct_HV_CELLS_TEMP(
    primary_message_HV_CELLS_TEMP* raw,
    primary_message_HV_CELLS_TEMP_conversion* conversion
){
#ifdef CANLIB_TIMESTAMP
    raw->_timestamp = conversion->_timestamp;
#endif // CANLIB_TIMESTAMP
    raw->start_index = conversion->start_index;
    raw->temp_0 = (primary_uint8)((conversion->temp_0 + 20) * 2.56);
    raw->temp_1 = (primary_uint8)((conversion->temp_1 + 20) * 2.56);
    raw->temp_2 = (primary_uint8)((conversion->temp_2 + 20) * 2.56);
    raw->temp_3 = (primary_uint8)((conversion->temp_3 + 20) * 2.56);
    raw->temp_4 = (primary_uint8)((conversion->temp_4 + 20) * 2.56);
    raw->temp_5 = (primary_uint8)((conversion->temp_5 + 20) * 2.56);
    raw->temp_6 = (primary_uint8)((conversion->temp_6 + 20) * 2.56);
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
        message->temp_5,
        message->temp_6
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
        "temp_5" CANLIB_SEPARATOR 
        "temp_6"
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
        message->temp_5,
        message->temp_6
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
        "temp_5" CANLIB_SEPARATOR 
        "temp_6"
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
    conversion->encoder_r = (((primary_float32)encoder_r) / 0.731429) - 70;
    conversion->encoder_l = (((primary_float32)encoder_l) / 0.731429) - 70;
    conversion->inverter_r = (((primary_float32)inverter_r) / 0.731429) - 70;
    conversion->inverter_l = (((primary_float32)inverter_l) / 0.731429) - 70;
}

void primary_raw_to_conversion_struct_SPEED(
    primary_message_SPEED_conversion* conversion,
    primary_message_SPEED* raw
){
#ifdef CANLIB_TIMESTAMP
    conversion->_timestamp = raw->_timestamp;
#endif // CANLIB_TIMESTAMP
    conversion->encoder_r = (((primary_float32)raw->encoder_r) / 0.731429) - 70;
    conversion->encoder_l = (((primary_float32)raw->encoder_l) / 0.731429) - 70;
    conversion->inverter_r = (((primary_float32)raw->inverter_r) / 0.731429) - 70;
    conversion->inverter_l = (((primary_float32)raw->inverter_l) / 0.731429) - 70;
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
    raw->encoder_r = (primary_uint8)((encoder_r + 70) * 0.731429);
    raw->encoder_l = (primary_uint8)((encoder_l + 70) * 0.731429);
    raw->inverter_r = (primary_uint8)((inverter_r + 70) * 0.731429);
    raw->inverter_l = (primary_uint8)((inverter_l + 70) * 0.731429);
}

void primary_conversion_to_raw_struct_SPEED(
    primary_message_SPEED* raw,
    primary_message_SPEED_conversion* conversion
){
#ifdef CANLIB_TIMESTAMP
    raw->_timestamp = conversion->_timestamp;
#endif // CANLIB_TIMESTAMP
    raw->encoder_r = (primary_uint8)((conversion->encoder_r + 70) * 0.731429);
    raw->encoder_l = (primary_uint8)((conversion->encoder_l + 70) * 0.731429);
    raw->inverter_r = (primary_uint8)((conversion->inverter_r + 70) * 0.731429);
    raw->inverter_l = (primary_uint8)((conversion->inverter_l + 70) * 0.731429);
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


// ============== UTILS ============== //

void primary_fields_from_id(canlib_message_id message_id, FILE *buffer) {
    switch (message_id) {
    case 0:
        primary_fields_file_BMS_HV_JMP_TO_BLT(buffer);
        break;
    case 1025:
        primary_fields_file_STEER_VERSION(buffer);
        break;
    case 1057:
        primary_fields_file_DAS_VERSION(buffer);
        break;
    case 1089:
        primary_fields_file_HV_VERSION(buffer);
        break;
    case 1121:
        primary_fields_file_LV_VERSION(buffer);
        break;
    case 1153:
        primary_fields_file_TLM_VERSION(buffer);
        break;
    case 257:
        primary_fields_file_TIMESTAMP(buffer);
        break;
    case 258:
        primary_fields_file_SET_TLM_STATUS(buffer);
        break;
    case 259:
        primary_fields_file_TLM_STATUS(buffer);
        break;
    case 1794:
        primary_fields_file_STEER_SYSTEM_STATUS(buffer);
        break;
    case 772:
        primary_fields_file_HV_VOLTAGE(buffer);
        break;
    case 804:
        primary_fields_file_HV_CURRENT(buffer);
        break;
    case 836:
        primary_fields_file_HV_TEMP(buffer);
        break;
    case 4:
        primary_fields_file_HV_ERRORS(buffer);
        break;
    case 5:
        primary_fields_file_HV_CAN_FORWARD(buffer);
        break;
    case 6:
        primary_fields_file_HV_CAN_FORWARD_STATUS(buffer);
        break;
    case 36:
        primary_fields_file_TS_STATUS(buffer);
        break;
    case 37:
        primary_fields_file_SET_TS_STATUS(buffer);
        break;
    case 69:
        primary_fields_file_SET_TS_STATUS(buffer);
        break;
    case 263:
        primary_fields_file_STEER_STATUS(buffer);
        break;
    case 775:
        primary_fields_file_SET_CAR_STATUS(buffer);
        break;
    case 1031:
        primary_fields_file_SET_PEDALS_RANGE(buffer);
        break;
    case 1063:
        primary_fields_file_SET_STEERING_ANGLE_RANGE(buffer);
        break;
    case 515:
        primary_fields_file_CAR_STATUS(buffer);
        break;
    case 3:
        primary_fields_file_DAS_ERRORS(buffer);
        break;
    case 776:
        primary_fields_file_LV_CURRENT(buffer);
        break;
    case 808:
        primary_fields_file_LV_VOLTAGE(buffer);
        break;
    case 840:
        primary_fields_file_LV_TOTAL_VOLTAGE(buffer);
        break;
    case 872:
        primary_fields_file_LV_TEMPERATURE(buffer);
        break;
    case 904:
        primary_fields_file_COOLING_STATUS(buffer);
        break;
    case 777:
        primary_fields_file_SET_RADIATOR_SPEED(buffer);
        break;
    case 809:
        primary_fields_file_SET_PUMPS_SPEED(buffer);
        break;
    case 265:
        primary_fields_file_SET_INVERTER_CONNECTION_STATUS(buffer);
        break;
    case 264:
        primary_fields_file_INVERTER_CONNECTION_STATUS(buffer);
        break;
    case 296:
        primary_fields_file_SHUTDOWN_STATUS(buffer);
        break;
    case 2:
        primary_fields_file_MARKER(buffer);
        break;
    case 518:
        primary_fields_file_HV_CELLS_VOLTAGE(buffer);
        break;
    case 550:
        primary_fields_file_HV_CELLS_TEMP(buffer);
        break;
    case 582:
        primary_fields_file_HV_CELL_BALANCING_STATUS(buffer);
        break;
    case 517:
        primary_fields_file_SET_CELL_BALANCING_STATUS(buffer);
        break;
    case 773:
        primary_fields_file_HANDCART_STATUS(buffer);
        break;
    case 547:
        primary_fields_file_SPEED(buffer);
        break;
    case 513:
        primary_fields_file_INV_L_REQUEST(buffer);
        break;
    case 514:
        primary_fields_file_INV_R_REQUEST(buffer);
        break;
    case 385:
        primary_fields_file_INV_L_RESPONSE(buffer);
        break;
    case 386:
        primary_fields_file_INV_R_RESPONSE(buffer);
        break;
    case 16:
        primary_fields_file_FLASH_CELLBOARD_0_TX(buffer);
        break;
    case 17:
        primary_fields_file_FLASH_CELLBOARD_0_RX(buffer);
        break;
    case 18:
        primary_fields_file_FLASH_CELLBOARD_1_TX(buffer);
        break;
    case 19:
        primary_fields_file_FLASH_CELLBOARD_1_RX(buffer);
        break;
    case 20:
        primary_fields_file_FLASH_CELLBOARD_2_TX(buffer);
        break;
    case 21:
        primary_fields_file_FLASH_CELLBOARD_2_RX(buffer);
        break;
    case 22:
        primary_fields_file_FLASH_CELLBOARD_3_TX(buffer);
        break;
    case 23:
        primary_fields_file_FLASH_CELLBOARD_3_RX(buffer);
        break;
    case 24:
        primary_fields_file_FLASH_CELLBOARD_4_TX(buffer);
        break;
    case 25:
        primary_fields_file_FLASH_CELLBOARD_4_RX(buffer);
        break;
    case 26:
        primary_fields_file_FLASH_CELLBOARD_5_TX(buffer);
        break;
    case 27:
        primary_fields_file_FLASH_CELLBOARD_5_RX(buffer);
        break;
    }
}

void primary_string_from_id(canlib_message_id message_id, void* message, FILE *buffer) {
    switch (message_id) {
        case 0:
            primary_to_string_file_BMS_HV_JMP_TO_BLT((primary_message_BMS_HV_JMP_TO_BLT*) message, buffer);
        break;
        case 1025:
            primary_to_string_file_STEER_VERSION((primary_message_STEER_VERSION*) message, buffer);
        break;
        case 1057:
            primary_to_string_file_DAS_VERSION((primary_message_DAS_VERSION*) message, buffer);
        break;
        case 1089:
            primary_to_string_file_HV_VERSION((primary_message_HV_VERSION*) message, buffer);
        break;
        case 1121:
            primary_to_string_file_LV_VERSION((primary_message_LV_VERSION*) message, buffer);
        break;
        case 1153:
            primary_to_string_file_TLM_VERSION((primary_message_TLM_VERSION*) message, buffer);
        break;
        case 257:
            primary_to_string_file_TIMESTAMP((primary_message_TIMESTAMP*) message, buffer);
        break;
        case 258:
            primary_to_string_file_SET_TLM_STATUS((primary_message_SET_TLM_STATUS*) message, buffer);
        break;
        case 259:
            primary_to_string_file_TLM_STATUS((primary_message_TLM_STATUS*) message, buffer);
        break;
        case 1794:
            primary_to_string_file_STEER_SYSTEM_STATUS((primary_message_STEER_SYSTEM_STATUS*) message, buffer);
        break;
        case 772:
            primary_to_string_file_HV_VOLTAGE((primary_message_HV_VOLTAGE_conversion*) message, buffer);
        break;
        case 804:
            primary_to_string_file_HV_CURRENT((primary_message_HV_CURRENT_conversion*) message, buffer);
        break;
        case 836:
            primary_to_string_file_HV_TEMP((primary_message_HV_TEMP_conversion*) message, buffer);
        break;
        case 4:
            primary_to_string_file_HV_ERRORS((primary_message_HV_ERRORS*) message, buffer);
        break;
        case 5:
            primary_to_string_file_HV_CAN_FORWARD((primary_message_HV_CAN_FORWARD*) message, buffer);
        break;
        case 6:
            primary_to_string_file_HV_CAN_FORWARD_STATUS((primary_message_HV_CAN_FORWARD_STATUS*) message, buffer);
        break;
        case 36:
            primary_to_string_file_TS_STATUS((primary_message_TS_STATUS*) message, buffer);
        break;
        case 37:
            primary_to_string_file_SET_TS_STATUS((primary_message_SET_TS_STATUS*) message, buffer);
        break;
        case 69:
            primary_to_string_file_SET_TS_STATUS((primary_message_SET_TS_STATUS*) message, buffer);
        break;
        case 263:
            primary_to_string_file_STEER_STATUS((primary_message_STEER_STATUS*) message, buffer);
        break;
        case 775:
            primary_to_string_file_SET_CAR_STATUS((primary_message_SET_CAR_STATUS*) message, buffer);
        break;
        case 1031:
            primary_to_string_file_SET_PEDALS_RANGE((primary_message_SET_PEDALS_RANGE*) message, buffer);
        break;
        case 1063:
            primary_to_string_file_SET_STEERING_ANGLE_RANGE((primary_message_SET_STEERING_ANGLE_RANGE*) message, buffer);
        break;
        case 515:
            primary_to_string_file_CAR_STATUS((primary_message_CAR_STATUS*) message, buffer);
        break;
        case 3:
            primary_to_string_file_DAS_ERRORS((primary_message_DAS_ERRORS*) message, buffer);
        break;
        case 776:
            primary_to_string_file_LV_CURRENT((primary_message_LV_CURRENT_conversion*) message, buffer);
        break;
        case 808:
            primary_to_string_file_LV_VOLTAGE((primary_message_LV_VOLTAGE_conversion*) message, buffer);
        break;
        case 840:
            primary_to_string_file_LV_TOTAL_VOLTAGE((primary_message_LV_TOTAL_VOLTAGE_conversion*) message, buffer);
        break;
        case 872:
            primary_to_string_file_LV_TEMPERATURE((primary_message_LV_TEMPERATURE_conversion*) message, buffer);
        break;
        case 904:
            primary_to_string_file_COOLING_STATUS((primary_message_COOLING_STATUS_conversion*) message, buffer);
        break;
        case 777:
            primary_to_string_file_SET_RADIATOR_SPEED((primary_message_SET_RADIATOR_SPEED*) message, buffer);
        break;
        case 809:
            primary_to_string_file_SET_PUMPS_SPEED((primary_message_SET_PUMPS_SPEED*) message, buffer);
        break;
        case 265:
            primary_to_string_file_SET_INVERTER_CONNECTION_STATUS((primary_message_SET_INVERTER_CONNECTION_STATUS*) message, buffer);
        break;
        case 264:
            primary_to_string_file_INVERTER_CONNECTION_STATUS((primary_message_INVERTER_CONNECTION_STATUS*) message, buffer);
        break;
        case 296:
            primary_to_string_file_SHUTDOWN_STATUS((primary_message_SHUTDOWN_STATUS*) message, buffer);
        break;
        case 2:
            primary_to_string_file_MARKER((primary_message_MARKER*) message, buffer);
        break;
        case 518:
            primary_to_string_file_HV_CELLS_VOLTAGE((primary_message_HV_CELLS_VOLTAGE_conversion*) message, buffer);
        break;
        case 550:
            primary_to_string_file_HV_CELLS_TEMP((primary_message_HV_CELLS_TEMP_conversion*) message, buffer);
        break;
        case 582:
            primary_to_string_file_HV_CELL_BALANCING_STATUS((primary_message_HV_CELL_BALANCING_STATUS*) message, buffer);
        break;
        case 517:
            primary_to_string_file_SET_CELL_BALANCING_STATUS((primary_message_SET_CELL_BALANCING_STATUS*) message, buffer);
        break;
        case 773:
            primary_to_string_file_HANDCART_STATUS((primary_message_HANDCART_STATUS*) message, buffer);
        break;
        case 547:
            primary_to_string_file_SPEED((primary_message_SPEED_conversion*) message, buffer);
        break;
        case 513:
            primary_to_string_file_INV_L_REQUEST((primary_message_INV_L_REQUEST*) message, buffer);
        break;
        case 514:
            primary_to_string_file_INV_R_REQUEST((primary_message_INV_R_REQUEST*) message, buffer);
        break;
        case 385:
            primary_to_string_file_INV_L_RESPONSE((primary_message_INV_L_RESPONSE*) message, buffer);
        break;
        case 386:
            primary_to_string_file_INV_R_RESPONSE((primary_message_INV_R_RESPONSE*) message, buffer);
        break;
        case 16:
            primary_to_string_file_FLASH_CELLBOARD_0_TX((primary_message_FLASH_CELLBOARD_0_TX*) message, buffer);
        break;
        case 17:
            primary_to_string_file_FLASH_CELLBOARD_0_RX((primary_message_FLASH_CELLBOARD_0_RX*) message, buffer);
        break;
        case 18:
            primary_to_string_file_FLASH_CELLBOARD_1_TX((primary_message_FLASH_CELLBOARD_1_TX*) message, buffer);
        break;
        case 19:
            primary_to_string_file_FLASH_CELLBOARD_1_RX((primary_message_FLASH_CELLBOARD_1_RX*) message, buffer);
        break;
        case 20:
            primary_to_string_file_FLASH_CELLBOARD_2_TX((primary_message_FLASH_CELLBOARD_2_TX*) message, buffer);
        break;
        case 21:
            primary_to_string_file_FLASH_CELLBOARD_2_RX((primary_message_FLASH_CELLBOARD_2_RX*) message, buffer);
        break;
        case 22:
            primary_to_string_file_FLASH_CELLBOARD_3_TX((primary_message_FLASH_CELLBOARD_3_TX*) message, buffer);
        break;
        case 23:
            primary_to_string_file_FLASH_CELLBOARD_3_RX((primary_message_FLASH_CELLBOARD_3_RX*) message, buffer);
        break;
        case 24:
            primary_to_string_file_FLASH_CELLBOARD_4_TX((primary_message_FLASH_CELLBOARD_4_TX*) message, buffer);
        break;
        case 25:
            primary_to_string_file_FLASH_CELLBOARD_4_RX((primary_message_FLASH_CELLBOARD_4_RX*) message, buffer);
        break;
        case 26:
            primary_to_string_file_FLASH_CELLBOARD_5_TX((primary_message_FLASH_CELLBOARD_5_TX*) message, buffer);
        break;
        case 27:
            primary_to_string_file_FLASH_CELLBOARD_5_RX((primary_message_FLASH_CELLBOARD_5_RX*) message, buffer);
        break;
    }
}

void primary_deserialize_from_id(
    canlib_message_id message_id,
    uint8_t* data,
    void* raw_message,
    void* message
#ifdef CANLIB_TIMESTAMP
    , primary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
) {
    switch (message_id) {
        case 0:
            primary_deserialize_BMS_HV_JMP_TO_BLT(
                (primary_message_BMS_HV_JMP_TO_BLT*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 1025:
            primary_deserialize_STEER_VERSION(
                (primary_message_STEER_VERSION*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 1057:
            primary_deserialize_DAS_VERSION(
                (primary_message_DAS_VERSION*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 1089:
            primary_deserialize_HV_VERSION(
                (primary_message_HV_VERSION*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 1121:
            primary_deserialize_LV_VERSION(
                (primary_message_LV_VERSION*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 1153:
            primary_deserialize_TLM_VERSION(
                (primary_message_TLM_VERSION*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 257:
            primary_deserialize_TIMESTAMP(
                (primary_message_TIMESTAMP*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 258:
            primary_deserialize_SET_TLM_STATUS(
                (primary_message_SET_TLM_STATUS*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 259:
            primary_deserialize_TLM_STATUS(
                (primary_message_TLM_STATUS*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 1794:
            primary_deserialize_STEER_SYSTEM_STATUS(
                (primary_message_STEER_SYSTEM_STATUS*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 772:
            primary_deserialize_HV_VOLTAGE(
                (primary_message_HV_VOLTAGE*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            primary_raw_to_conversion_struct_HV_VOLTAGE(
                (primary_message_HV_VOLTAGE_conversion*) message,
                (primary_message_HV_VOLTAGE*) raw_message
            );
        break;
        case 804:
            primary_deserialize_HV_CURRENT(
                (primary_message_HV_CURRENT*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            primary_raw_to_conversion_struct_HV_CURRENT(
                (primary_message_HV_CURRENT_conversion*) message,
                (primary_message_HV_CURRENT*) raw_message
            );
        break;
        case 836:
            primary_deserialize_HV_TEMP(
                (primary_message_HV_TEMP*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            primary_raw_to_conversion_struct_HV_TEMP(
                (primary_message_HV_TEMP_conversion*) message,
                (primary_message_HV_TEMP*) raw_message
            );
        break;
        case 4:
            primary_deserialize_HV_ERRORS(
                (primary_message_HV_ERRORS*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 5:
            primary_deserialize_HV_CAN_FORWARD(
                (primary_message_HV_CAN_FORWARD*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 6:
            primary_deserialize_HV_CAN_FORWARD_STATUS(
                (primary_message_HV_CAN_FORWARD_STATUS*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 36:
            primary_deserialize_TS_STATUS(
                (primary_message_TS_STATUS*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 37:
            primary_deserialize_SET_TS_STATUS(
                (primary_message_SET_TS_STATUS*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 69:
            primary_deserialize_SET_TS_STATUS(
                (primary_message_SET_TS_STATUS*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 263:
            primary_deserialize_STEER_STATUS(
                (primary_message_STEER_STATUS*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 775:
            primary_deserialize_SET_CAR_STATUS(
                (primary_message_SET_CAR_STATUS*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 1031:
            primary_deserialize_SET_PEDALS_RANGE(
                (primary_message_SET_PEDALS_RANGE*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 1063:
            primary_deserialize_SET_STEERING_ANGLE_RANGE(
                (primary_message_SET_STEERING_ANGLE_RANGE*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 515:
            primary_deserialize_CAR_STATUS(
                (primary_message_CAR_STATUS*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 3:
            primary_deserialize_DAS_ERRORS(
                (primary_message_DAS_ERRORS*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 776:
            primary_deserialize_LV_CURRENT(
                (primary_message_LV_CURRENT*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            primary_raw_to_conversion_struct_LV_CURRENT(
                (primary_message_LV_CURRENT_conversion*) message,
                (primary_message_LV_CURRENT*) raw_message
            );
        break;
        case 808:
            primary_deserialize_LV_VOLTAGE(
                (primary_message_LV_VOLTAGE*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            primary_raw_to_conversion_struct_LV_VOLTAGE(
                (primary_message_LV_VOLTAGE_conversion*) message,
                (primary_message_LV_VOLTAGE*) raw_message
            );
        break;
        case 840:
            primary_deserialize_LV_TOTAL_VOLTAGE(
                (primary_message_LV_TOTAL_VOLTAGE*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            primary_raw_to_conversion_struct_LV_TOTAL_VOLTAGE(
                (primary_message_LV_TOTAL_VOLTAGE_conversion*) message,
                (primary_message_LV_TOTAL_VOLTAGE*) raw_message
            );
        break;
        case 872:
            primary_deserialize_LV_TEMPERATURE(
                (primary_message_LV_TEMPERATURE*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            primary_raw_to_conversion_struct_LV_TEMPERATURE(
                (primary_message_LV_TEMPERATURE_conversion*) message,
                (primary_message_LV_TEMPERATURE*) raw_message
            );
        break;
        case 904:
            primary_deserialize_COOLING_STATUS(
                (primary_message_COOLING_STATUS*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            primary_raw_to_conversion_struct_COOLING_STATUS(
                (primary_message_COOLING_STATUS_conversion*) message,
                (primary_message_COOLING_STATUS*) raw_message
            );
        break;
        case 777:
            primary_deserialize_SET_RADIATOR_SPEED(
                (primary_message_SET_RADIATOR_SPEED*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 809:
            primary_deserialize_SET_PUMPS_SPEED(
                (primary_message_SET_PUMPS_SPEED*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 265:
            primary_deserialize_SET_INVERTER_CONNECTION_STATUS(
                (primary_message_SET_INVERTER_CONNECTION_STATUS*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 264:
            primary_deserialize_INVERTER_CONNECTION_STATUS(
                (primary_message_INVERTER_CONNECTION_STATUS*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 296:
            primary_deserialize_SHUTDOWN_STATUS(
                (primary_message_SHUTDOWN_STATUS*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 2:
            primary_deserialize_MARKER(
                (primary_message_MARKER*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 518:
            primary_deserialize_HV_CELLS_VOLTAGE(
                (primary_message_HV_CELLS_VOLTAGE*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            primary_raw_to_conversion_struct_HV_CELLS_VOLTAGE(
                (primary_message_HV_CELLS_VOLTAGE_conversion*) message,
                (primary_message_HV_CELLS_VOLTAGE*) raw_message
            );
        break;
        case 550:
            primary_deserialize_HV_CELLS_TEMP(
                (primary_message_HV_CELLS_TEMP*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            primary_raw_to_conversion_struct_HV_CELLS_TEMP(
                (primary_message_HV_CELLS_TEMP_conversion*) message,
                (primary_message_HV_CELLS_TEMP*) raw_message
            );
        break;
        case 582:
            primary_deserialize_HV_CELL_BALANCING_STATUS(
                (primary_message_HV_CELL_BALANCING_STATUS*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 517:
            primary_deserialize_SET_CELL_BALANCING_STATUS(
                (primary_message_SET_CELL_BALANCING_STATUS*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 773:
            primary_deserialize_HANDCART_STATUS(
                (primary_message_HANDCART_STATUS*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 547:
            primary_deserialize_SPEED(
                (primary_message_SPEED*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            primary_raw_to_conversion_struct_SPEED(
                (primary_message_SPEED_conversion*) message,
                (primary_message_SPEED*) raw_message
            );
        break;
        case 513:
            primary_deserialize_INV_L_REQUEST(
                (primary_message_INV_L_REQUEST*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 514:
            primary_deserialize_INV_R_REQUEST(
                (primary_message_INV_R_REQUEST*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 385:
            primary_deserialize_INV_L_RESPONSE(
                (primary_message_INV_L_RESPONSE*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 386:
            primary_deserialize_INV_R_RESPONSE(
                (primary_message_INV_R_RESPONSE*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 16:
            primary_deserialize_FLASH_CELLBOARD_0_TX(
                (primary_message_FLASH_CELLBOARD_0_TX*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 17:
            primary_deserialize_FLASH_CELLBOARD_0_RX(
                (primary_message_FLASH_CELLBOARD_0_RX*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 18:
            primary_deserialize_FLASH_CELLBOARD_1_TX(
                (primary_message_FLASH_CELLBOARD_1_TX*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 19:
            primary_deserialize_FLASH_CELLBOARD_1_RX(
                (primary_message_FLASH_CELLBOARD_1_RX*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 20:
            primary_deserialize_FLASH_CELLBOARD_2_TX(
                (primary_message_FLASH_CELLBOARD_2_TX*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 21:
            primary_deserialize_FLASH_CELLBOARD_2_RX(
                (primary_message_FLASH_CELLBOARD_2_RX*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 22:
            primary_deserialize_FLASH_CELLBOARD_3_TX(
                (primary_message_FLASH_CELLBOARD_3_TX*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 23:
            primary_deserialize_FLASH_CELLBOARD_3_RX(
                (primary_message_FLASH_CELLBOARD_3_RX*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 24:
            primary_deserialize_FLASH_CELLBOARD_4_TX(
                (primary_message_FLASH_CELLBOARD_4_TX*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 25:
            primary_deserialize_FLASH_CELLBOARD_4_RX(
                (primary_message_FLASH_CELLBOARD_4_RX*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 26:
            primary_deserialize_FLASH_CELLBOARD_5_TX(
                (primary_message_FLASH_CELLBOARD_5_TX*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 27:
            primary_deserialize_FLASH_CELLBOARD_5_RX(
                (primary_message_FLASH_CELLBOARD_5_RX*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
    }
}

void primary_devices_new(primary_devices* map) {
    (*map)[0].id = 0;
    (*map)[0].raw_message = (void*) malloc(sizeof(primary_message_BMS_HV_JMP_TO_BLT));
    (*map)[0].conversion_message = NULL;

    (*map)[1].id = 1025;
    (*map)[1].raw_message = (void*) malloc(sizeof(primary_message_STEER_VERSION));
    (*map)[1].conversion_message = NULL;

    (*map)[2].id = 1057;
    (*map)[2].raw_message = (void*) malloc(sizeof(primary_message_DAS_VERSION));
    (*map)[2].conversion_message = NULL;

    (*map)[3].id = 1089;
    (*map)[3].raw_message = (void*) malloc(sizeof(primary_message_HV_VERSION));
    (*map)[3].conversion_message = NULL;

    (*map)[4].id = 1121;
    (*map)[4].raw_message = (void*) malloc(sizeof(primary_message_LV_VERSION));
    (*map)[4].conversion_message = NULL;

    (*map)[5].id = 1153;
    (*map)[5].raw_message = (void*) malloc(sizeof(primary_message_TLM_VERSION));
    (*map)[5].conversion_message = NULL;

    (*map)[6].id = 257;
    (*map)[6].raw_message = (void*) malloc(sizeof(primary_message_TIMESTAMP));
    (*map)[6].conversion_message = NULL;

    (*map)[7].id = 258;
    (*map)[7].raw_message = (void*) malloc(sizeof(primary_message_SET_TLM_STATUS));
    (*map)[7].conversion_message = NULL;

    (*map)[8].id = 259;
    (*map)[8].raw_message = (void*) malloc(sizeof(primary_message_TLM_STATUS));
    (*map)[8].conversion_message = NULL;

    (*map)[9].id = 1794;
    (*map)[9].raw_message = (void*) malloc(sizeof(primary_message_STEER_SYSTEM_STATUS));
    (*map)[9].conversion_message = NULL;

    (*map)[10].id = 772;
    (*map)[10].raw_message = (void*) malloc(sizeof(primary_message_HV_VOLTAGE));
    (*map)[10].conversion_message = (void*) malloc(sizeof(primary_message_HV_VOLTAGE_conversion));

    (*map)[11].id = 804;
    (*map)[11].raw_message = (void*) malloc(sizeof(primary_message_HV_CURRENT));
    (*map)[11].conversion_message = (void*) malloc(sizeof(primary_message_HV_CURRENT_conversion));

    (*map)[12].id = 836;
    (*map)[12].raw_message = (void*) malloc(sizeof(primary_message_HV_TEMP));
    (*map)[12].conversion_message = (void*) malloc(sizeof(primary_message_HV_TEMP_conversion));

    (*map)[13].id = 4;
    (*map)[13].raw_message = (void*) malloc(sizeof(primary_message_HV_ERRORS));
    (*map)[13].conversion_message = NULL;

    (*map)[14].id = 5;
    (*map)[14].raw_message = (void*) malloc(sizeof(primary_message_HV_CAN_FORWARD));
    (*map)[14].conversion_message = NULL;

    (*map)[15].id = 6;
    (*map)[15].raw_message = (void*) malloc(sizeof(primary_message_HV_CAN_FORWARD_STATUS));
    (*map)[15].conversion_message = NULL;

    (*map)[16].id = 36;
    (*map)[16].raw_message = (void*) malloc(sizeof(primary_message_TS_STATUS));
    (*map)[16].conversion_message = NULL;

    (*map)[17].id = 37;
    (*map)[17].raw_message = (void*) malloc(sizeof(primary_message_SET_TS_STATUS));
    (*map)[17].conversion_message = NULL;

    (*map)[18].id = 69;
    (*map)[18].raw_message = (void*) malloc(sizeof(primary_message_SET_TS_STATUS));
    (*map)[18].conversion_message = NULL;

    (*map)[19].id = 263;
    (*map)[19].raw_message = (void*) malloc(sizeof(primary_message_STEER_STATUS));
    (*map)[19].conversion_message = NULL;

    (*map)[20].id = 775;
    (*map)[20].raw_message = (void*) malloc(sizeof(primary_message_SET_CAR_STATUS));
    (*map)[20].conversion_message = NULL;

    (*map)[21].id = 1031;
    (*map)[21].raw_message = (void*) malloc(sizeof(primary_message_SET_PEDALS_RANGE));
    (*map)[21].conversion_message = NULL;

    (*map)[22].id = 1063;
    (*map)[22].raw_message = (void*) malloc(sizeof(primary_message_SET_STEERING_ANGLE_RANGE));
    (*map)[22].conversion_message = NULL;

    (*map)[23].id = 515;
    (*map)[23].raw_message = (void*) malloc(sizeof(primary_message_CAR_STATUS));
    (*map)[23].conversion_message = NULL;

    (*map)[24].id = 3;
    (*map)[24].raw_message = (void*) malloc(sizeof(primary_message_DAS_ERRORS));
    (*map)[24].conversion_message = NULL;

    (*map)[25].id = 776;
    (*map)[25].raw_message = (void*) malloc(sizeof(primary_message_LV_CURRENT));
    (*map)[25].conversion_message = (void*) malloc(sizeof(primary_message_LV_CURRENT_conversion));

    (*map)[26].id = 808;
    (*map)[26].raw_message = (void*) malloc(sizeof(primary_message_LV_VOLTAGE));
    (*map)[26].conversion_message = (void*) malloc(sizeof(primary_message_LV_VOLTAGE_conversion));

    (*map)[27].id = 840;
    (*map)[27].raw_message = (void*) malloc(sizeof(primary_message_LV_TOTAL_VOLTAGE));
    (*map)[27].conversion_message = (void*) malloc(sizeof(primary_message_LV_TOTAL_VOLTAGE_conversion));

    (*map)[28].id = 872;
    (*map)[28].raw_message = (void*) malloc(sizeof(primary_message_LV_TEMPERATURE));
    (*map)[28].conversion_message = (void*) malloc(sizeof(primary_message_LV_TEMPERATURE_conversion));

    (*map)[29].id = 904;
    (*map)[29].raw_message = (void*) malloc(sizeof(primary_message_COOLING_STATUS));
    (*map)[29].conversion_message = (void*) malloc(sizeof(primary_message_COOLING_STATUS_conversion));

    (*map)[30].id = 777;
    (*map)[30].raw_message = (void*) malloc(sizeof(primary_message_SET_RADIATOR_SPEED));
    (*map)[30].conversion_message = NULL;

    (*map)[31].id = 809;
    (*map)[31].raw_message = (void*) malloc(sizeof(primary_message_SET_PUMPS_SPEED));
    (*map)[31].conversion_message = NULL;

    (*map)[32].id = 265;
    (*map)[32].raw_message = (void*) malloc(sizeof(primary_message_SET_INVERTER_CONNECTION_STATUS));
    (*map)[32].conversion_message = NULL;

    (*map)[33].id = 264;
    (*map)[33].raw_message = (void*) malloc(sizeof(primary_message_INVERTER_CONNECTION_STATUS));
    (*map)[33].conversion_message = NULL;

    (*map)[34].id = 296;
    (*map)[34].raw_message = (void*) malloc(sizeof(primary_message_SHUTDOWN_STATUS));
    (*map)[34].conversion_message = NULL;

    (*map)[35].id = 2;
    (*map)[35].raw_message = (void*) malloc(sizeof(primary_message_MARKER));
    (*map)[35].conversion_message = NULL;

    (*map)[36].id = 518;
    (*map)[36].raw_message = (void*) malloc(sizeof(primary_message_HV_CELLS_VOLTAGE));
    (*map)[36].conversion_message = (void*) malloc(sizeof(primary_message_HV_CELLS_VOLTAGE_conversion));

    (*map)[37].id = 550;
    (*map)[37].raw_message = (void*) malloc(sizeof(primary_message_HV_CELLS_TEMP));
    (*map)[37].conversion_message = (void*) malloc(sizeof(primary_message_HV_CELLS_TEMP_conversion));

    (*map)[38].id = 582;
    (*map)[38].raw_message = (void*) malloc(sizeof(primary_message_HV_CELL_BALANCING_STATUS));
    (*map)[38].conversion_message = NULL;

    (*map)[39].id = 517;
    (*map)[39].raw_message = (void*) malloc(sizeof(primary_message_SET_CELL_BALANCING_STATUS));
    (*map)[39].conversion_message = NULL;

    (*map)[40].id = 773;
    (*map)[40].raw_message = (void*) malloc(sizeof(primary_message_HANDCART_STATUS));
    (*map)[40].conversion_message = NULL;

    (*map)[41].id = 547;
    (*map)[41].raw_message = (void*) malloc(sizeof(primary_message_SPEED));
    (*map)[41].conversion_message = (void*) malloc(sizeof(primary_message_SPEED_conversion));

    (*map)[42].id = 513;
    (*map)[42].raw_message = (void*) malloc(sizeof(primary_message_INV_L_REQUEST));
    (*map)[42].conversion_message = NULL;

    (*map)[43].id = 514;
    (*map)[43].raw_message = (void*) malloc(sizeof(primary_message_INV_R_REQUEST));
    (*map)[43].conversion_message = NULL;

    (*map)[44].id = 385;
    (*map)[44].raw_message = (void*) malloc(sizeof(primary_message_INV_L_RESPONSE));
    (*map)[44].conversion_message = NULL;

    (*map)[45].id = 386;
    (*map)[45].raw_message = (void*) malloc(sizeof(primary_message_INV_R_RESPONSE));
    (*map)[45].conversion_message = NULL;

    (*map)[46].id = 16;
    (*map)[46].raw_message = (void*) malloc(sizeof(primary_message_FLASH_CELLBOARD_0_TX));
    (*map)[46].conversion_message = NULL;

    (*map)[47].id = 17;
    (*map)[47].raw_message = (void*) malloc(sizeof(primary_message_FLASH_CELLBOARD_0_RX));
    (*map)[47].conversion_message = NULL;

    (*map)[48].id = 18;
    (*map)[48].raw_message = (void*) malloc(sizeof(primary_message_FLASH_CELLBOARD_1_TX));
    (*map)[48].conversion_message = NULL;

    (*map)[49].id = 19;
    (*map)[49].raw_message = (void*) malloc(sizeof(primary_message_FLASH_CELLBOARD_1_RX));
    (*map)[49].conversion_message = NULL;

    (*map)[50].id = 20;
    (*map)[50].raw_message = (void*) malloc(sizeof(primary_message_FLASH_CELLBOARD_2_TX));
    (*map)[50].conversion_message = NULL;

    (*map)[51].id = 21;
    (*map)[51].raw_message = (void*) malloc(sizeof(primary_message_FLASH_CELLBOARD_2_RX));
    (*map)[51].conversion_message = NULL;

    (*map)[52].id = 22;
    (*map)[52].raw_message = (void*) malloc(sizeof(primary_message_FLASH_CELLBOARD_3_TX));
    (*map)[52].conversion_message = NULL;

    (*map)[53].id = 23;
    (*map)[53].raw_message = (void*) malloc(sizeof(primary_message_FLASH_CELLBOARD_3_RX));
    (*map)[53].conversion_message = NULL;

    (*map)[54].id = 24;
    (*map)[54].raw_message = (void*) malloc(sizeof(primary_message_FLASH_CELLBOARD_4_TX));
    (*map)[54].conversion_message = NULL;

    (*map)[55].id = 25;
    (*map)[55].raw_message = (void*) malloc(sizeof(primary_message_FLASH_CELLBOARD_4_RX));
    (*map)[55].conversion_message = NULL;

    (*map)[56].id = 26;
    (*map)[56].raw_message = (void*) malloc(sizeof(primary_message_FLASH_CELLBOARD_5_TX));
    (*map)[56].conversion_message = NULL;

    (*map)[57].id = 27;
    (*map)[57].raw_message = (void*) malloc(sizeof(primary_message_FLASH_CELLBOARD_5_RX));
    (*map)[57].conversion_message = NULL;

}

int primary_devices_index_from_id(canlib_message_id message_id, primary_devices* map) {
    for (int index = 0; index < primary_NUMBER_OF_MESSAGES; index++) {
        if ((*map)[index].id == message_id)
            return index;
    }
    return -1;
}

#endif

#ifdef __cplusplus
}
#endif

#endif // primary_NETWORK_H