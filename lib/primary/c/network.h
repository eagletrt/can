#ifndef primary_NETWORK_H
#define primary_NETWORK_H

#include <stdbool.h>
#include <assert.h>
#include <stdint.h>
#include <string.h>
#include <stdio.h>

#ifndef CANLIB_ASSERTS
#define CANLIB_ASSERTS

static_assert(sizeof(float) == 4, "sizeof(float) != 4 BYTES");
static_assert(sizeof(double) == 8, "sizeof(double) != 8 BYTES");

#endif // CANLIB_ASSERTS

#ifndef CANLIB_SHARED
#define CANLIB_SHARED

#if defined(__MINGW32__)
#define __CANLIB_PACKED __attribute__((__gcc_struct__, __packed__)) // , __aligned__(1)))
#else
#define __CANLIB_PACKED __attribute__((__packed__)) // , __aligned__(1)))
#endif

#define CANLIB_BITMASK(b) (1 << (b))
#define CANLIB_BITSET(a, b) ((a) |= CANLIB_BITMASK(b))
#define CANLIB_BITCLEAR(a, b) ((a) &= ~CANLIB_BITMASK(b))
#define CANLIB_BITTEST(a, b) ((a) & CANLIB_BITMASK(b))

#endif // CANLIB_SHARED

#ifndef CANLIB_SEPARATOR
#define CANLIB_SEPARATOR ","
#endif // CANLIB_SEPARATOR

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

typedef union {
    uint8_t bytes[4];
    primary_float32 value;
} primary_float32_helper;

typedef union {
    uint8_t bytes[8];
    primary_float64 value;
} primary_float64_helper;

// Frequencies


#define primary_STEER_VERSION_FREQUENCY 1000
#define primary_DAS_VERSION_FREQUENCY 1000
#define primary_HV_VERSION_FREQUENCY 1000
#define primary_LV_VERSION_FREQUENCY 1000
#define primary_TLM_VERSION_FREQUENCY 1000
#define primary_TIMESTAMP_FREQUENCY 1000
#define primary_SET_TLM_STATUS_FREQUENCY -1
#define primary_TLM_STATUS_FREQUENCY 1000
#define primary_STEER_SYSTEM_STATUS_FREQUENCY 2000
#define primary_HV_VOLTAGE_FREQUENCY 20
#define primary_HV_CURRENT_FREQUENCY 20
#define primary_HV_TEMP_FREQUENCY 200
#define primary_HV_ERRORS_FREQUENCY 20
#define primary_TS_STATUS_FREQUENCY 20
#define primary_SET_TS_STATUS_FREQUENCY -1
#define primary_STEER_STATUS_FREQUENCY 100
#define primary_SET_CAR_STATUS_FREQUENCY -1
#define primary_SET_PEDALS_RANGE_FREQUENCY -1
#define primary_CAR_STATUS_FREQUENCY 100
#define primary_DAS_ERRORS_FREQUENCY 20
#define primary_LV_CURRENT_FREQUENCY 500
#define primary_LV_VOLTAGE_FREQUENCY 200
#define primary_LV_TEMPERATURE_FREQUENCY 200
#define primary_COOLING_STATUS_FREQUENCY 1000
#define primary_MARKER_FREQUENCY -1
#define primary_HV_CELLS_VOLTAGE_FREQUENCY 200
#define primary_HV_CELLS_TEMP_FREQUENCY 100
#define primary_HV_CELL_BALANCING_STATUS_FREQUENCY 500
#define primary_SET_CELL_BALANCING_STATUS_FREQUENCY -1
#define primary_HANDCART_STATUS_FREQUENCY 500
#define primary_SPEED_FREQUENCY 100
#define primary_INV_L_SET_TORQUE_FREQUENCY 20
#define primary_INV_L_RESPONSE_FREQUENCY 100

// Sizes


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
#define primary_HV_TEMP_SIZE 6
#define primary_HV_ERRORS_SIZE 4
#define primary_TS_STATUS_SIZE 1
#define primary_SET_TS_STATUS_SIZE 1
#define primary_STEER_STATUS_SIZE 1
#define primary_SET_CAR_STATUS_SIZE 1
#define primary_SET_PEDALS_RANGE_SIZE 1
#define primary_CAR_STATUS_SIZE 1
#define primary_DAS_ERRORS_SIZE 1
#define primary_LV_CURRENT_SIZE 1
#define primary_LV_VOLTAGE_SIZE 6
#define primary_LV_TEMPERATURE_SIZE 2
#define primary_COOLING_STATUS_SIZE 3
#define primary_MARKER_SIZE 0
#define primary_HV_CELLS_VOLTAGE_SIZE 7
#define primary_HV_CELLS_TEMP_SIZE 8
#define primary_HV_CELL_BALANCING_STATUS_SIZE 1
#define primary_SET_CELL_BALANCING_STATUS_SIZE 1
#define primary_HANDCART_STATUS_SIZE 1
#define primary_SPEED_SIZE 8
#define primary_INV_L_SET_TORQUE_SIZE 3
#define primary_INV_L_RESPONSE_SIZE 5

// Bitsets


typedef primary_uint16 primary_HvErrors;
#define primary_HvErrors_DEFAULT 0
#define primary_HvErrors_LTC_PEC_ERROR 0
#define primary_HvErrors_CELL_UNDER_VOLTAGE 1
#define primary_HvErrors_CELL_OVER_VOLTAGE 2
#define primary_HvErrors_CELL_OVER_TEMPERATURE 3
#define primary_HvErrors_OVER_CURRENT 4
#define primary_HvErrors_ADC_INIT 5
#define primary_HvErrors_ADC_TIMEOUT 6
#define primary_HvErrors_INT_VOLTAGE_MISMATCH 7
#define primary_HvErrors_FEEDBACK_HARD 8
#define primary_HvErrors_FEEDBACK_SOFT 9

typedef primary_uint8 primary_DasErrors;
#define primary_DasErrors_DEFAULT 0
#define primary_DasErrors_PEDAL_ADC 0
#define primary_DasErrors_PEDAL_IMPLAUSIBILITY 1
#define primary_DasErrors_IMU_TOUT 2
#define primary_DasErrors_IRTS_TOUT 3
#define primary_DasErrors_TS_TOUT 4
#define primary_DasErrors_INVL_TOUT 5
#define primary_DasErrors_INVR_TOUT 6
#define primary_DasErrors_FSM 7

typedef primary_uint32 primary_InvStatus;
#define primary_InvStatus_DEFAULT 0
#define primary_InvStatus_DRIVE_ENABLE 0
#define primary_InvStatus_NCR0 1
#define primary_InvStatus_LIMP 2
#define primary_InvStatus_LIMM 3
#define primary_InvStatus_DRIVE_OK 4
#define primary_InvStatus_ICNS 5
#define primary_InvStatus_T_NLIM 6
#define primary_InvStatus_P_N 7
#define primary_InvStatus_N_I 8
#define primary_InvStatus_N0 9
#define primary_InvStatus_RSW 10
#define primary_InvStatus_CAL0 11
#define primary_InvStatus_CAL 12
#define primary_InvStatus_TOL 13
#define primary_InvStatus_DRIVE_READY 14
#define primary_InvStatus_BRK 15
#define primary_InvStatus_SIGN_MAG 16
#define primary_InvStatus_NCLIP 17
#define primary_InvStatus_NCLIPP 18
#define primary_InvStatus_NCLIPM 19
#define primary_InvStatus_IRD_DIG 20
#define primary_InvStatus_IUSE_RCHD 21
#define primary_InvStatus_IRD_N 22
#define primary_InvStatus_IRD_TI 23
#define primary_InvStatus_IRD_TIR 24
#define primary_InvStatus_HZ10 25
#define primary_InvStatus_IRD_TM 26
#define primary_InvStatus_IRD_ANA 27
#define primary_InvStatus_IWCNS 28
#define primary_InvStatus_RFE_PULSE 29
#define primary_InvStatus_MD 30
#define primary_InvStatus_HND_WHL 31

typedef primary_uint32 primary_InvErrors;
#define primary_InvErrors_DEFAULT 0
#define primary_InvErrors_BAD_PARAM 0
#define primary_InvErrors_HW_FAULT 1
#define primary_InvErrors_SAFETY_FAULT 2
#define primary_InvErrors_CAN_TIMEOUT 3
#define primary_InvErrors_ENCODER_ERR 4
#define primary_InvErrors_NO_POWER_VOLTAGE 5
#define primary_InvErrors_HI_MOTOR_TEMP 6
#define primary_InvErrors_HI_DEVICE_TEMP 7
#define primary_InvErrors_OVERVOLTAGE 8
#define primary_InvErrors_OVERCURRENT 9
#define primary_InvErrors_RACEAWAY 10
#define primary_InvErrors_USER_ERR 11
#define primary_InvErrors_UNKNOWN_ERR_12 12
#define primary_InvErrors_UNKNOWN_ERR_13 13
#define primary_InvErrors_CURRENT_ERR 14
#define primary_InvErrors_BALLAST_OVERLOAD 15
#define primary_InvErrors_DEVICE_ID_ERR 16
#define primary_InvErrors_RUN_SIG_FAULT 17
#define primary_InvErrors_UNKNOWN_ERR_19 18
#define primary_InvErrors_UNKNOWN_ERR_20 19
#define primary_InvErrors_POWERVOLTAGE_WARN 20
#define primary_InvErrors_HI_MOTOR_TEMP_WARN 21
#define primary_InvErrors_HI_DEVICE_TEMP_WARN 22
#define primary_InvErrors_VOUT_LIMIT_WARN 23
#define primary_InvErrors_OVERCURRENT_WARN 24
#define primary_InvErrors_RACEAWAY_WARN 25
#define primary_InvErrors_UNKNOWN_ERR_27 26
#define primary_InvErrors_UNKNOWN_ERR_28 27
#define primary_InvErrors_UNKNOWN_ERR_29 28
#define primary_InvErrors_UNKNOWN_ERR_30 29
#define primary_InvErrors_BALLAST_OVERLOAD_WARN 30

typedef primary_uint32 primary_RegVal;
#define primary_RegVal_DEFAULT 0


// Enums


typedef enum __CANLIB_PACKED {
    RaceType_ACCELERATION = 0,
    RaceType_SKIDPAD = 1,
    RaceType_AUTOCROSS = 2,
    RaceType_ENDURANCE = 3,
} primary_RaceType;

typedef enum __CANLIB_PACKED {
    InverterStatus_OFF = 0,
    InverterStatus_IDLE = 1,
    InverterStatus_ON = 2,
} primary_InverterStatus;

typedef enum __CANLIB_PACKED {
    CarStatus_IDLE = 0,
    CarStatus_SETUP = 1,
    CarStatus_RUN = 2,
} primary_CarStatus;

typedef enum __CANLIB_PACKED {
    Toggle_ON = 0,
    Toggle_OFF = 1,
} primary_Toggle;

typedef enum __CANLIB_PACKED {
    TractionControl_OFF = 0,
    TractionControl_SLIP_CONTROL = 1,
    TractionControl_TORQUE_VECTORING = 2,
    TractionControl_COMPLETE = 3,
} primary_TractionControl;

typedef enum __CANLIB_PACKED {
    TsStatus_OFF = 0,
    TsStatus_PRECHARGE = 1,
    TsStatus_ON = 2,
    TsStatus_FATAL = 3,
} primary_TsStatus;

typedef enum __CANLIB_PACKED {
    Map_R = 0,
    Map_D20 = 1,
    Map_D40 = 2,
    Map_D60 = 3,
    Map_D80 = 4,
    Map_D100 = 5,
} primary_Map;

typedef enum __CANLIB_PACKED {
    SetCarStatus_IDLE = 0,
    SetCarStatus_RUN = 1,
} primary_SetCarStatus;

typedef enum __CANLIB_PACKED {
    Bound_SET_MAX = 0,
    Bound_SET_MIN = 1,
} primary_Bound;

typedef enum __CANLIB_PACKED {
    Pedal_ACCELERATOR = 0,
    Pedal_BRAKE = 1,
} primary_Pedal;


// Structs


typedef struct __CANLIB_PACKED {
    primary_uint8 component_version;
    primary_uint8 cancicd_version;
} primary_message_STEER_VERSION;

typedef struct __CANLIB_PACKED {
    primary_uint8 component_version;
    primary_uint8 cancicd_version;
} primary_message_DAS_VERSION;

typedef struct __CANLIB_PACKED {
    primary_uint8 component_version;
    primary_uint8 cancicd_version;
} primary_message_HV_VERSION;

typedef struct __CANLIB_PACKED {
    primary_uint8 component_version;
    primary_uint8 cancicd_version;
} primary_message_LV_VERSION;

typedef struct __CANLIB_PACKED {
    primary_uint8 component_version;
    primary_uint8 cancicd_version;
} primary_message_TLM_VERSION;

typedef struct __CANLIB_PACKED {
    primary_uint32 timestamp;
} primary_message_TIMESTAMP;

typedef struct __CANLIB_PACKED {
    primary_uint8 driver;
    primary_uint8 circuit;
    primary_RaceType race_type;
    primary_Toggle tlm_status;
} primary_message_SET_TLM_STATUS;

typedef struct __CANLIB_PACKED {
    primary_uint8 driver;
    primary_uint8 circuit;
    primary_RaceType race_type;
    primary_Toggle tlm_status;
} primary_message_TLM_STATUS;

typedef struct __CANLIB_PACKED {
    primary_uint8 soc_temp;
} primary_message_STEER_SYSTEM_STATUS;

typedef struct __CANLIB_PACKED {
    primary_uint16 pack_voltage;
    primary_uint16 bus_voltage;
    primary_uint16 max_cell_voltage;
    primary_uint16 min_cell_voltage;
} primary_message_HV_VOLTAGE;

typedef struct __CANLIB_PACKED {
    primary_uint16 current;
    primary_int16 power;
} primary_message_HV_CURRENT;

typedef struct __CANLIB_PACKED {
    primary_uint16 average_temp;
    primary_uint16 max_temp;
    primary_uint16 min_temp;
} primary_message_HV_TEMP;

typedef struct __CANLIB_PACKED {
    primary_HvErrors warnings;
    primary_HvErrors errors;
} primary_message_HV_ERRORS;

typedef struct __CANLIB_PACKED {
    primary_TsStatus ts_status;
} primary_message_TS_STATUS;

typedef struct __CANLIB_PACKED {
    primary_Toggle ts_status_set;
} primary_message_SET_TS_STATUS;

typedef struct __CANLIB_PACKED {
    primary_Map map;
    primary_TractionControl traction_control;
} primary_message_STEER_STATUS;

typedef struct __CANLIB_PACKED {
    primary_SetCarStatus car_status_set;
} primary_message_SET_CAR_STATUS;

typedef struct __CANLIB_PACKED {
    primary_Bound bound;
    primary_Pedal pedal;
} primary_message_SET_PEDALS_RANGE;

typedef struct __CANLIB_PACKED {
    primary_InverterStatus inverter_l;
    primary_InverterStatus inverter_r;
    primary_CarStatus car_status;
} primary_message_CAR_STATUS;

typedef struct __CANLIB_PACKED {
    primary_DasErrors das_error;
} primary_message_DAS_ERRORS;

typedef struct __CANLIB_PACKED {
    primary_uint8 current;
} primary_message_LV_CURRENT;

typedef struct __CANLIB_PACKED {
    primary_uint16 total_voltage;
    primary_uint8 voltage_1;
    primary_uint8 voltage_2;
    primary_uint8 voltage_3;
    primary_uint8 voltage_4;
} primary_message_LV_VOLTAGE;

typedef struct __CANLIB_PACKED {
    primary_uint8 bp_temperature;
    primary_uint8 dcdc_temperature;
} primary_message_LV_TEMPERATURE;

typedef struct __CANLIB_PACKED {
    primary_uint8 hv_fan_speed;
    primary_uint8 lv_fan_speed;
    primary_uint8 pump_speed;
} primary_message_COOLING_STATUS;

typedef struct __CANLIB_PACKED {
} primary_message_MARKER;

typedef struct __CANLIB_PACKED {
    primary_uint16 voltage_0;
    primary_uint16 voltage_1;
    primary_uint16 voltage_2;
    primary_uint8 cell_index;
} primary_message_HV_CELLS_VOLTAGE;

typedef struct __CANLIB_PACKED {
    primary_uint8 cell_index;
    primary_uint8 temp_0;
    primary_uint8 temp_1;
    primary_uint8 temp_2;
    primary_uint8 temp_3;
    primary_uint8 temp_4;
    primary_uint8 temp_5;
    primary_uint8 temp_6;
} primary_message_HV_CELLS_TEMP;

typedef struct __CANLIB_PACKED {
    primary_Toggle balancing_status;
} primary_message_HV_CELL_BALANCING_STATUS;

typedef struct __CANLIB_PACKED {
    primary_Toggle set_balancing_status;
} primary_message_SET_CELL_BALANCING_STATUS;

typedef struct __CANLIB_PACKED {
    primary_bool connected;
} primary_message_HANDCART_STATUS;

typedef struct __CANLIB_PACKED {
    primary_uint16 encoder_r;
    primary_uint16 encoder_l;
    primary_uint16 inverter_r;
    primary_uint16 inverter_l;
} primary_message_SPEED;

typedef struct __CANLIB_PACKED {
    primary_uint8 regid;
    primary_uint8 lsb;
    primary_uint8 msb;
} primary_message_INV_L_SET_TORQUE;

typedef struct __CANLIB_PACKED {
    primary_RegVal reg_val;
    primary_uint8 reg_id;
} primary_message_INV_L_RESPONSE;


// Serialize and Deserialize


void primary_serialize_STEER_VERSION(
    uint8_t* data,
    primary_uint8 component_version,
    primary_uint8 cancicd_version
) {
    data[0] = component_version;
    data[1] = cancicd_version;
}

void primary_deserialize_STEER_VERSION(primary_message_STEER_VERSION* message, uint8_t* data) {
    message->component_version = data[0];
    message->cancicd_version = data[1];
}

void primary_serialize_DAS_VERSION(
    uint8_t* data,
    primary_uint8 component_version,
    primary_uint8 cancicd_version
) {
    data[0] = component_version;
    data[1] = cancicd_version;
}

void primary_deserialize_DAS_VERSION(primary_message_DAS_VERSION* message, uint8_t* data) {
    message->component_version = data[0];
    message->cancicd_version = data[1];
}

void primary_serialize_HV_VERSION(
    uint8_t* data,
    primary_uint8 component_version,
    primary_uint8 cancicd_version
) {
    data[0] = component_version;
    data[1] = cancicd_version;
}

void primary_deserialize_HV_VERSION(primary_message_HV_VERSION* message, uint8_t* data) {
    message->component_version = data[0];
    message->cancicd_version = data[1];
}

void primary_serialize_LV_VERSION(
    uint8_t* data,
    primary_uint8 component_version,
    primary_uint8 cancicd_version
) {
    data[0] = component_version;
    data[1] = cancicd_version;
}

void primary_deserialize_LV_VERSION(primary_message_LV_VERSION* message, uint8_t* data) {
    message->component_version = data[0];
    message->cancicd_version = data[1];
}

void primary_serialize_TLM_VERSION(
    uint8_t* data,
    primary_uint8 component_version,
    primary_uint8 cancicd_version
) {
    data[0] = component_version;
    data[1] = cancicd_version;
}

void primary_deserialize_TLM_VERSION(primary_message_TLM_VERSION* message, uint8_t* data) {
    message->component_version = data[0];
    message->cancicd_version = data[1];
}

void primary_serialize_TIMESTAMP(
    uint8_t* data,
    primary_uint32 timestamp
) {
    data[0] = timestamp & 255;
    data[1] = (timestamp >> 8) & 255;
    data[2] = (timestamp >> 16) & 255;
    data[3] = (timestamp >> 24) & 255;
}

void primary_deserialize_TIMESTAMP(primary_message_TIMESTAMP* message, uint8_t* data) {
    message->timestamp = data[0] | (data[1] << 8) | (data[2] << 16) | (data[3] << 24);
}

void primary_serialize_SET_TLM_STATUS(
    uint8_t* data,
    primary_uint8 driver,
    primary_uint8 circuit,
    primary_RaceType race_type,
    primary_Toggle tlm_status
) {
    data[0] = driver;
    data[1] = circuit;
    data[2] = race_type << 6 | tlm_status << 5;
}

void primary_deserialize_SET_TLM_STATUS(primary_message_SET_TLM_STATUS* message, uint8_t* data) {
    message->driver = data[0];
    message->circuit = data[1];
    message->race_type = (primary_RaceType) ((data[2] & 192) >> 6);
    message->tlm_status = (primary_Toggle) ((data[2] & 32) >> 5);
}

void primary_serialize_TLM_STATUS(
    uint8_t* data,
    primary_uint8 driver,
    primary_uint8 circuit,
    primary_RaceType race_type,
    primary_Toggle tlm_status
) {
    data[0] = driver;
    data[1] = circuit;
    data[2] = race_type << 6 | tlm_status << 5;
}

void primary_deserialize_TLM_STATUS(primary_message_TLM_STATUS* message, uint8_t* data) {
    message->driver = data[0];
    message->circuit = data[1];
    message->race_type = (primary_RaceType) ((data[2] & 192) >> 6);
    message->tlm_status = (primary_Toggle) ((data[2] & 32) >> 5);
}

void primary_serialize_STEER_SYSTEM_STATUS(
    uint8_t* data,
    primary_uint8 soc_temp
) {
    data[0] = soc_temp;
}

void primary_deserialize_STEER_SYSTEM_STATUS(primary_message_STEER_SYSTEM_STATUS* message, uint8_t* data) {
    message->soc_temp = data[0];
}

void primary_serialize_HV_VOLTAGE(
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
}

void primary_deserialize_HV_VOLTAGE(primary_message_HV_VOLTAGE* message, uint8_t* data) {
    message->pack_voltage = data[0] | (data[1] << 8);
    message->bus_voltage = data[2] | (data[3] << 8);
    message->max_cell_voltage = data[4] | (data[5] << 8);
    message->min_cell_voltage = data[6] | (data[7] << 8);
}

void primary_serialize_HV_CURRENT(
    uint8_t* data,
    primary_uint16 current,
    primary_int16 power
) {
    data[0] = current & 255;
    data[1] = (current >> 8) & 255;
    data[2] = power & 255;
    data[3] = (power >> 8) & 255;
}

void primary_deserialize_HV_CURRENT(primary_message_HV_CURRENT* message, uint8_t* data) {
    message->current = data[0] | (data[1] << 8);
    message->power = data[2] | (data[3] << 8);
}

void primary_serialize_HV_TEMP(
    uint8_t* data,
    primary_uint16 average_temp,
    primary_uint16 max_temp,
    primary_uint16 min_temp
) {
    data[0] = average_temp & 255;
    data[1] = (average_temp >> 8) & 255;
    data[2] = max_temp & 255;
    data[3] = (max_temp >> 8) & 255;
    data[4] = min_temp & 255;
    data[5] = (min_temp >> 8) & 255;
}

void primary_deserialize_HV_TEMP(primary_message_HV_TEMP* message, uint8_t* data) {
    message->average_temp = data[0] | (data[1] << 8);
    message->max_temp = data[2] | (data[3] << 8);
    message->min_temp = data[4] | (data[5] << 8);
}

void primary_serialize_HV_ERRORS(
    uint8_t* data,
    primary_HvErrors warnings,
    primary_HvErrors errors
) {
    data[0] = warnings & 255;
    data[1] = (warnings >> 8) & 255;
    data[2] = errors & 255;
    data[3] = (errors >> 8) & 255;
}

void primary_deserialize_HV_ERRORS(primary_message_HV_ERRORS* message, uint8_t* data) {
    message->warnings = data[0] | (data[1] << 8);
    message->errors = data[2] | (data[3] << 8);
}

void primary_serialize_TS_STATUS(
    uint8_t* data,
    primary_TsStatus ts_status
) {
    data[0] = ts_status << 6;
}

void primary_deserialize_TS_STATUS(primary_message_TS_STATUS* message, uint8_t* data) {
    message->ts_status = (primary_TsStatus) ((data[0] & 192) >> 6);
}

void primary_serialize_SET_TS_STATUS(
    uint8_t* data,
    primary_Toggle ts_status_set
) {
    data[0] = ts_status_set << 7;
}

void primary_deserialize_SET_TS_STATUS(primary_message_SET_TS_STATUS* message, uint8_t* data) {
    message->ts_status_set = (primary_Toggle) ((data[0] & 128) >> 7);
}

void primary_serialize_STEER_STATUS(
    uint8_t* data,
    primary_Map map,
    primary_TractionControl traction_control
) {
    data[0] = map << 5 | traction_control << 3;
}

void primary_deserialize_STEER_STATUS(primary_message_STEER_STATUS* message, uint8_t* data) {
    message->map = (primary_Map) ((data[0] & 224) >> 5);
    message->traction_control = (primary_TractionControl) ((data[0] & 24) >> 3);
}

void primary_serialize_SET_CAR_STATUS(
    uint8_t* data,
    primary_SetCarStatus car_status_set
) {
    data[0] = car_status_set << 7;
}

void primary_deserialize_SET_CAR_STATUS(primary_message_SET_CAR_STATUS* message, uint8_t* data) {
    message->car_status_set = (primary_SetCarStatus) ((data[0] & 128) >> 7);
}

void primary_serialize_SET_PEDALS_RANGE(
    uint8_t* data,
    primary_Bound bound,
    primary_Pedal pedal
) {
    data[0] = bound << 7 | pedal << 6;
}

void primary_deserialize_SET_PEDALS_RANGE(primary_message_SET_PEDALS_RANGE* message, uint8_t* data) {
    message->bound = (primary_Bound) ((data[0] & 128) >> 7);
    message->pedal = (primary_Pedal) ((data[0] & 64) >> 6);
}

void primary_serialize_CAR_STATUS(
    uint8_t* data,
    primary_InverterStatus inverter_l,
    primary_InverterStatus inverter_r,
    primary_CarStatus car_status
) {
    data[0] = inverter_l << 6 | inverter_r << 4 | car_status << 2;
}

void primary_deserialize_CAR_STATUS(primary_message_CAR_STATUS* message, uint8_t* data) {
    message->inverter_l = (primary_InverterStatus) ((data[0] & 192) >> 6);
    message->inverter_r = (primary_InverterStatus) ((data[0] & 48) >> 4);
    message->car_status = (primary_CarStatus) ((data[0] & 12) >> 2);
}

void primary_serialize_DAS_ERRORS(
    uint8_t* data,
    primary_DasErrors das_error
) {
    data[0] = das_error;
}

void primary_deserialize_DAS_ERRORS(primary_message_DAS_ERRORS* message, uint8_t* data) {
    message->das_error = data[0];
}

void primary_serialize_LV_CURRENT(
    uint8_t* data,
    primary_uint8 current
) {
    data[0] = current;
}

void primary_deserialize_LV_CURRENT(primary_message_LV_CURRENT* message, uint8_t* data) {
    message->current = data[0];
}

void primary_serialize_LV_VOLTAGE(
    uint8_t* data,
    primary_uint16 total_voltage,
    primary_uint8 voltage_1,
    primary_uint8 voltage_2,
    primary_uint8 voltage_3,
    primary_uint8 voltage_4
) {
    data[0] = total_voltage & 255;
    data[1] = (total_voltage >> 8) & 255;
    data[2] = voltage_1;
    data[3] = voltage_2;
    data[4] = voltage_3;
    data[5] = voltage_4;
}

void primary_deserialize_LV_VOLTAGE(primary_message_LV_VOLTAGE* message, uint8_t* data) {
    message->total_voltage = data[0] | (data[1] << 8);
    message->voltage_1 = data[2];
    message->voltage_2 = data[3];
    message->voltage_3 = data[4];
    message->voltage_4 = data[5];
}

void primary_serialize_LV_TEMPERATURE(
    uint8_t* data,
    primary_uint8 bp_temperature,
    primary_uint8 dcdc_temperature
) {
    data[0] = bp_temperature;
    data[1] = dcdc_temperature;
}

void primary_deserialize_LV_TEMPERATURE(primary_message_LV_TEMPERATURE* message, uint8_t* data) {
    message->bp_temperature = data[0];
    message->dcdc_temperature = data[1];
}

void primary_serialize_COOLING_STATUS(
    uint8_t* data,
    primary_uint8 hv_fan_speed,
    primary_uint8 lv_fan_speed,
    primary_uint8 pump_speed
) {
    data[0] = hv_fan_speed;
    data[1] = lv_fan_speed;
    data[2] = pump_speed;
}

void primary_deserialize_COOLING_STATUS(primary_message_COOLING_STATUS* message, uint8_t* data) {
    message->hv_fan_speed = data[0];
    message->lv_fan_speed = data[1];
    message->pump_speed = data[2];
}

void primary_serialize_MARKER(
    uint8_t* data
) {
}

void primary_deserialize_MARKER(primary_message_MARKER* message, uint8_t* data) {
}

void primary_serialize_HV_CELLS_VOLTAGE(
    uint8_t* data,
    primary_uint16 voltage_0,
    primary_uint16 voltage_1,
    primary_uint16 voltage_2,
    primary_uint8 cell_index
) {
    data[0] = voltage_0 & 255;
    data[1] = (voltage_0 >> 8) & 255;
    data[2] = voltage_1 & 255;
    data[3] = (voltage_1 >> 8) & 255;
    data[4] = voltage_2 & 255;
    data[5] = (voltage_2 >> 8) & 255;
    data[6] = cell_index;
}

void primary_deserialize_HV_CELLS_VOLTAGE(primary_message_HV_CELLS_VOLTAGE* message, uint8_t* data) {
    message->voltage_0 = data[0] | (data[1] << 8);
    message->voltage_1 = data[2] | (data[3] << 8);
    message->voltage_2 = data[4] | (data[5] << 8);
    message->cell_index = data[6];
}

void primary_serialize_HV_CELLS_TEMP(
    uint8_t* data,
    primary_uint8 cell_index,
    primary_uint8 temp_0,
    primary_uint8 temp_1,
    primary_uint8 temp_2,
    primary_uint8 temp_3,
    primary_uint8 temp_4,
    primary_uint8 temp_5,
    primary_uint8 temp_6
) {
    data[0] = cell_index;
    data[1] = temp_0;
    data[2] = temp_1;
    data[3] = temp_2;
    data[4] = temp_3;
    data[5] = temp_4;
    data[6] = temp_5;
    data[7] = temp_6;
}

void primary_deserialize_HV_CELLS_TEMP(primary_message_HV_CELLS_TEMP* message, uint8_t* data) {
    message->cell_index = data[0];
    message->temp_0 = data[1];
    message->temp_1 = data[2];
    message->temp_2 = data[3];
    message->temp_3 = data[4];
    message->temp_4 = data[5];
    message->temp_5 = data[6];
    message->temp_6 = data[7];
}

void primary_serialize_HV_CELL_BALANCING_STATUS(
    uint8_t* data,
    primary_Toggle balancing_status
) {
    data[0] = balancing_status << 7;
}

void primary_deserialize_HV_CELL_BALANCING_STATUS(primary_message_HV_CELL_BALANCING_STATUS* message, uint8_t* data) {
    message->balancing_status = (primary_Toggle) ((data[0] & 128) >> 7);
}

void primary_serialize_SET_CELL_BALANCING_STATUS(
    uint8_t* data,
    primary_Toggle set_balancing_status
) {
    data[0] = set_balancing_status << 7;
}

void primary_deserialize_SET_CELL_BALANCING_STATUS(primary_message_SET_CELL_BALANCING_STATUS* message, uint8_t* data) {
    message->set_balancing_status = (primary_Toggle) ((data[0] & 128) >> 7);
}

void primary_serialize_HANDCART_STATUS(
    uint8_t* data,
    primary_bool connected
) {
    data[0] = connected << 7;
}

void primary_deserialize_HANDCART_STATUS(primary_message_HANDCART_STATUS* message, uint8_t* data) {
    message->connected = (data[0] & 128) >> 7;
}

void primary_serialize_SPEED(
    uint8_t* data,
    primary_uint16 encoder_r,
    primary_uint16 encoder_l,
    primary_uint16 inverter_r,
    primary_uint16 inverter_l
) {
    data[0] = encoder_r & 255;
    data[1] = (encoder_r >> 8) & 255;
    data[2] = encoder_l & 255;
    data[3] = (encoder_l >> 8) & 255;
    data[4] = inverter_r & 255;
    data[5] = (inverter_r >> 8) & 255;
    data[6] = inverter_l & 255;
    data[7] = (inverter_l >> 8) & 255;
}

void primary_deserialize_SPEED(primary_message_SPEED* message, uint8_t* data) {
    message->encoder_r = data[0] | (data[1] << 8);
    message->encoder_l = data[2] | (data[3] << 8);
    message->inverter_r = data[4] | (data[5] << 8);
    message->inverter_l = data[6] | (data[7] << 8);
}

void primary_serialize_INV_L_SET_TORQUE(
    uint8_t* data,
    primary_uint8 regid,
    primary_uint8 lsb,
    primary_uint8 msb
) {
    data[0] = regid;
    data[1] = lsb;
    data[2] = msb;
}

void primary_deserialize_INV_L_SET_TORQUE(primary_message_INV_L_SET_TORQUE* message, uint8_t* data) {
    message->regid = data[0];
    message->lsb = data[1];
    message->msb = data[2];
}

void primary_serialize_INV_L_RESPONSE(
    uint8_t* data,
    primary_RegVal reg_val,
    primary_uint8 reg_id
) {
    data[0] = reg_val & 255;
    data[1] = (reg_val >> 8) & 255;
    data[2] = (reg_val >> 16) & 255;
    data[3] = (reg_val >> 24) & 255;
    data[4] = reg_id;
}

void primary_deserialize_INV_L_RESPONSE(primary_message_INV_L_RESPONSE* message, uint8_t* data) {
    message->reg_val = data[0] | (data[1] << 8) | (data[2] << 16) | (data[3] << 24);
    message->reg_id = data[4];
}


// Strings


void primary_to_string_STEER_VERSION(primary_message_STEER_VERSION* message, char* buffer) {
    sprintf(
        buffer,
        "%hhd" CANLIB_SEPARATOR 
        "%hhd",
        message->component_version,
        message->cancicd_version
    );
}

void primary_fields_STEER_VERSION(char* buffer) {
    sprintf(
        buffer,
        "component_version" CANLIB_SEPARATOR 
        "cancicd_version"
    );
}

void primary_to_string_file_STEER_VERSION(primary_message_STEER_VERSION* message, FILE* buffer) {
    fprintf(
        buffer,
        "%hhd" CANLIB_SEPARATOR 
        "%hhd",
        message->component_version,
        message->cancicd_version
    );
}

void primary_fields_file_STEER_VERSION(FILE* buffer) {
    fprintf(
        buffer,
        "component_version" CANLIB_SEPARATOR 
        "cancicd_version"
    );
}

void primary_to_string_DAS_VERSION(primary_message_DAS_VERSION* message, char* buffer) {
    sprintf(
        buffer,
        "%hhd" CANLIB_SEPARATOR 
        "%hhd",
        message->component_version,
        message->cancicd_version
    );
}

void primary_fields_DAS_VERSION(char* buffer) {
    sprintf(
        buffer,
        "component_version" CANLIB_SEPARATOR 
        "cancicd_version"
    );
}

void primary_to_string_file_DAS_VERSION(primary_message_DAS_VERSION* message, FILE* buffer) {
    fprintf(
        buffer,
        "%hhd" CANLIB_SEPARATOR 
        "%hhd",
        message->component_version,
        message->cancicd_version
    );
}

void primary_fields_file_DAS_VERSION(FILE* buffer) {
    fprintf(
        buffer,
        "component_version" CANLIB_SEPARATOR 
        "cancicd_version"
    );
}

void primary_to_string_HV_VERSION(primary_message_HV_VERSION* message, char* buffer) {
    sprintf(
        buffer,
        "%hhd" CANLIB_SEPARATOR 
        "%hhd",
        message->component_version,
        message->cancicd_version
    );
}

void primary_fields_HV_VERSION(char* buffer) {
    sprintf(
        buffer,
        "component_version" CANLIB_SEPARATOR 
        "cancicd_version"
    );
}

void primary_to_string_file_HV_VERSION(primary_message_HV_VERSION* message, FILE* buffer) {
    fprintf(
        buffer,
        "%hhd" CANLIB_SEPARATOR 
        "%hhd",
        message->component_version,
        message->cancicd_version
    );
}

void primary_fields_file_HV_VERSION(FILE* buffer) {
    fprintf(
        buffer,
        "component_version" CANLIB_SEPARATOR 
        "cancicd_version"
    );
}

void primary_to_string_LV_VERSION(primary_message_LV_VERSION* message, char* buffer) {
    sprintf(
        buffer,
        "%hhd" CANLIB_SEPARATOR 
        "%hhd",
        message->component_version,
        message->cancicd_version
    );
}

void primary_fields_LV_VERSION(char* buffer) {
    sprintf(
        buffer,
        "component_version" CANLIB_SEPARATOR 
        "cancicd_version"
    );
}

void primary_to_string_file_LV_VERSION(primary_message_LV_VERSION* message, FILE* buffer) {
    fprintf(
        buffer,
        "%hhd" CANLIB_SEPARATOR 
        "%hhd",
        message->component_version,
        message->cancicd_version
    );
}

void primary_fields_file_LV_VERSION(FILE* buffer) {
    fprintf(
        buffer,
        "component_version" CANLIB_SEPARATOR 
        "cancicd_version"
    );
}

void primary_to_string_TLM_VERSION(primary_message_TLM_VERSION* message, char* buffer) {
    sprintf(
        buffer,
        "%hhd" CANLIB_SEPARATOR 
        "%hhd",
        message->component_version,
        message->cancicd_version
    );
}

void primary_fields_TLM_VERSION(char* buffer) {
    sprintf(
        buffer,
        "component_version" CANLIB_SEPARATOR 
        "cancicd_version"
    );
}

void primary_to_string_file_TLM_VERSION(primary_message_TLM_VERSION* message, FILE* buffer) {
    fprintf(
        buffer,
        "%hhd" CANLIB_SEPARATOR 
        "%hhd",
        message->component_version,
        message->cancicd_version
    );
}

void primary_fields_file_TLM_VERSION(FILE* buffer) {
    fprintf(
        buffer,
        "component_version" CANLIB_SEPARATOR 
        "cancicd_version"
    );
}

void primary_to_string_TIMESTAMP(primary_message_TIMESTAMP* message, char* buffer) {
    sprintf(
        buffer,
        "%hhu",
        message->timestamp
    );
}

void primary_fields_TIMESTAMP(char* buffer) {
    sprintf(
        buffer,
        "timestamp"
    );
}

void primary_to_string_file_TIMESTAMP(primary_message_TIMESTAMP* message, FILE* buffer) {
    fprintf(
        buffer,
        "%hhu",
        message->timestamp
    );
}

void primary_fields_file_TIMESTAMP(FILE* buffer) {
    fprintf(
        buffer,
        "timestamp"
    );
}

void primary_to_string_SET_TLM_STATUS(primary_message_SET_TLM_STATUS* message, char* buffer) {
    sprintf(
        buffer,
        "%hhd" CANLIB_SEPARATOR 
        "%hhd" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d",
        message->driver,
        message->circuit,
        message->race_type,
        message->tlm_status
    );
}

void primary_fields_SET_TLM_STATUS(char* buffer) {
    sprintf(
        buffer,
        "driver" CANLIB_SEPARATOR 
        "circuit" CANLIB_SEPARATOR 
        "race_type" CANLIB_SEPARATOR 
        "tlm_status"
    );
}

void primary_to_string_file_SET_TLM_STATUS(primary_message_SET_TLM_STATUS* message, FILE* buffer) {
    fprintf(
        buffer,
        "%hhd" CANLIB_SEPARATOR 
        "%hhd" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d",
        message->driver,
        message->circuit,
        message->race_type,
        message->tlm_status
    );
}

void primary_fields_file_SET_TLM_STATUS(FILE* buffer) {
    fprintf(
        buffer,
        "driver" CANLIB_SEPARATOR 
        "circuit" CANLIB_SEPARATOR 
        "race_type" CANLIB_SEPARATOR 
        "tlm_status"
    );
}

void primary_to_string_TLM_STATUS(primary_message_TLM_STATUS* message, char* buffer) {
    sprintf(
        buffer,
        "%hhd" CANLIB_SEPARATOR 
        "%hhd" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d",
        message->driver,
        message->circuit,
        message->race_type,
        message->tlm_status
    );
}

void primary_fields_TLM_STATUS(char* buffer) {
    sprintf(
        buffer,
        "driver" CANLIB_SEPARATOR 
        "circuit" CANLIB_SEPARATOR 
        "race_type" CANLIB_SEPARATOR 
        "tlm_status"
    );
}

void primary_to_string_file_TLM_STATUS(primary_message_TLM_STATUS* message, FILE* buffer) {
    fprintf(
        buffer,
        "%hhd" CANLIB_SEPARATOR 
        "%hhd" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d",
        message->driver,
        message->circuit,
        message->race_type,
        message->tlm_status
    );
}

void primary_fields_file_TLM_STATUS(FILE* buffer) {
    fprintf(
        buffer,
        "driver" CANLIB_SEPARATOR 
        "circuit" CANLIB_SEPARATOR 
        "race_type" CANLIB_SEPARATOR 
        "tlm_status"
    );
}

void primary_to_string_STEER_SYSTEM_STATUS(primary_message_STEER_SYSTEM_STATUS* message, char* buffer) {
    sprintf(
        buffer,
        "%hhd",
        message->soc_temp
    );
}

void primary_fields_STEER_SYSTEM_STATUS(char* buffer) {
    sprintf(
        buffer,
        "soc_temp"
    );
}

void primary_to_string_file_STEER_SYSTEM_STATUS(primary_message_STEER_SYSTEM_STATUS* message, FILE* buffer) {
    fprintf(
        buffer,
        "%hhd",
        message->soc_temp
    );
}

void primary_fields_file_STEER_SYSTEM_STATUS(FILE* buffer) {
    fprintf(
        buffer,
        "soc_temp"
    );
}

void primary_to_string_HV_VOLTAGE(primary_message_HV_VOLTAGE* message, char* buffer) {
    sprintf(
        buffer,
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d",
        message->pack_voltage,
        message->bus_voltage,
        message->max_cell_voltage,
        message->min_cell_voltage
    );
}

void primary_fields_HV_VOLTAGE(char* buffer) {
    sprintf(
        buffer,
        "pack_voltage" CANLIB_SEPARATOR 
        "bus_voltage" CANLIB_SEPARATOR 
        "max_cell_voltage" CANLIB_SEPARATOR 
        "min_cell_voltage"
    );
}

void primary_to_string_file_HV_VOLTAGE(primary_message_HV_VOLTAGE* message, FILE* buffer) {
    fprintf(
        buffer,
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d",
        message->pack_voltage,
        message->bus_voltage,
        message->max_cell_voltage,
        message->min_cell_voltage
    );
}

void primary_fields_file_HV_VOLTAGE(FILE* buffer) {
    fprintf(
        buffer,
        "pack_voltage" CANLIB_SEPARATOR 
        "bus_voltage" CANLIB_SEPARATOR 
        "max_cell_voltage" CANLIB_SEPARATOR 
        "min_cell_voltage"
    );
}

void primary_to_string_HV_CURRENT(primary_message_HV_CURRENT* message, char* buffer) {
    sprintf(
        buffer,
        "%d" CANLIB_SEPARATOR 
        "%hd",
        message->current,
        message->power
    );
}

void primary_fields_HV_CURRENT(char* buffer) {
    sprintf(
        buffer,
        "current" CANLIB_SEPARATOR 
        "power"
    );
}

void primary_to_string_file_HV_CURRENT(primary_message_HV_CURRENT* message, FILE* buffer) {
    fprintf(
        buffer,
        "%d" CANLIB_SEPARATOR 
        "%hd",
        message->current,
        message->power
    );
}

void primary_fields_file_HV_CURRENT(FILE* buffer) {
    fprintf(
        buffer,
        "current" CANLIB_SEPARATOR 
        "power"
    );
}

void primary_to_string_HV_TEMP(primary_message_HV_TEMP* message, char* buffer) {
    sprintf(
        buffer,
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d",
        message->average_temp,
        message->max_temp,
        message->min_temp
    );
}

void primary_fields_HV_TEMP(char* buffer) {
    sprintf(
        buffer,
        "average_temp" CANLIB_SEPARATOR 
        "max_temp" CANLIB_SEPARATOR 
        "min_temp"
    );
}

void primary_to_string_file_HV_TEMP(primary_message_HV_TEMP* message, FILE* buffer) {
    fprintf(
        buffer,
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d",
        message->average_temp,
        message->max_temp,
        message->min_temp
    );
}

void primary_fields_file_HV_TEMP(FILE* buffer) {
    fprintf(
        buffer,
        "average_temp" CANLIB_SEPARATOR 
        "max_temp" CANLIB_SEPARATOR 
        "min_temp"
    );
}

void primary_to_string_HV_ERRORS(primary_message_HV_ERRORS* message, char* buffer) {
    sprintf(
        buffer,
        "%d" CANLIB_SEPARATOR 
        "%d",
        message->warnings,
        message->errors
    );
}

void primary_fields_HV_ERRORS(char* buffer) {
    sprintf(
        buffer,
        "warnings" CANLIB_SEPARATOR 
        "errors"
    );
}

void primary_to_string_file_HV_ERRORS(primary_message_HV_ERRORS* message, FILE* buffer) {
    fprintf(
        buffer,
        "%d" CANLIB_SEPARATOR 
        "%d",
        message->warnings,
        message->errors
    );
}

void primary_fields_file_HV_ERRORS(FILE* buffer) {
    fprintf(
        buffer,
        "warnings" CANLIB_SEPARATOR 
        "errors"
    );
}

void primary_to_string_TS_STATUS(primary_message_TS_STATUS* message, char* buffer) {
    sprintf(
        buffer,
        "%d",
        message->ts_status
    );
}

void primary_fields_TS_STATUS(char* buffer) {
    sprintf(
        buffer,
        "ts_status"
    );
}

void primary_to_string_file_TS_STATUS(primary_message_TS_STATUS* message, FILE* buffer) {
    fprintf(
        buffer,
        "%d",
        message->ts_status
    );
}

void primary_fields_file_TS_STATUS(FILE* buffer) {
    fprintf(
        buffer,
        "ts_status"
    );
}

void primary_to_string_SET_TS_STATUS(primary_message_SET_TS_STATUS* message, char* buffer) {
    sprintf(
        buffer,
        "%d",
        message->ts_status_set
    );
}

void primary_fields_SET_TS_STATUS(char* buffer) {
    sprintf(
        buffer,
        "ts_status_set"
    );
}

void primary_to_string_file_SET_TS_STATUS(primary_message_SET_TS_STATUS* message, FILE* buffer) {
    fprintf(
        buffer,
        "%d",
        message->ts_status_set
    );
}

void primary_fields_file_SET_TS_STATUS(FILE* buffer) {
    fprintf(
        buffer,
        "ts_status_set"
    );
}

void primary_to_string_STEER_STATUS(primary_message_STEER_STATUS* message, char* buffer) {
    sprintf(
        buffer,
        "%d" CANLIB_SEPARATOR 
        "%d",
        message->map,
        message->traction_control
    );
}

void primary_fields_STEER_STATUS(char* buffer) {
    sprintf(
        buffer,
        "map" CANLIB_SEPARATOR 
        "traction_control"
    );
}

void primary_to_string_file_STEER_STATUS(primary_message_STEER_STATUS* message, FILE* buffer) {
    fprintf(
        buffer,
        "%d" CANLIB_SEPARATOR 
        "%d",
        message->map,
        message->traction_control
    );
}

void primary_fields_file_STEER_STATUS(FILE* buffer) {
    fprintf(
        buffer,
        "map" CANLIB_SEPARATOR 
        "traction_control"
    );
}

void primary_to_string_SET_CAR_STATUS(primary_message_SET_CAR_STATUS* message, char* buffer) {
    sprintf(
        buffer,
        "%d",
        message->car_status_set
    );
}

void primary_fields_SET_CAR_STATUS(char* buffer) {
    sprintf(
        buffer,
        "car_status_set"
    );
}

void primary_to_string_file_SET_CAR_STATUS(primary_message_SET_CAR_STATUS* message, FILE* buffer) {
    fprintf(
        buffer,
        "%d",
        message->car_status_set
    );
}

void primary_fields_file_SET_CAR_STATUS(FILE* buffer) {
    fprintf(
        buffer,
        "car_status_set"
    );
}

void primary_to_string_SET_PEDALS_RANGE(primary_message_SET_PEDALS_RANGE* message, char* buffer) {
    sprintf(
        buffer,
        "%d" CANLIB_SEPARATOR 
        "%d",
        message->bound,
        message->pedal
    );
}

void primary_fields_SET_PEDALS_RANGE(char* buffer) {
    sprintf(
        buffer,
        "bound" CANLIB_SEPARATOR 
        "pedal"
    );
}

void primary_to_string_file_SET_PEDALS_RANGE(primary_message_SET_PEDALS_RANGE* message, FILE* buffer) {
    fprintf(
        buffer,
        "%d" CANLIB_SEPARATOR 
        "%d",
        message->bound,
        message->pedal
    );
}

void primary_fields_file_SET_PEDALS_RANGE(FILE* buffer) {
    fprintf(
        buffer,
        "bound" CANLIB_SEPARATOR 
        "pedal"
    );
}

void primary_to_string_CAR_STATUS(primary_message_CAR_STATUS* message, char* buffer) {
    sprintf(
        buffer,
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d",
        message->inverter_l,
        message->inverter_r,
        message->car_status
    );
}

void primary_fields_CAR_STATUS(char* buffer) {
    sprintf(
        buffer,
        "inverter_l" CANLIB_SEPARATOR 
        "inverter_r" CANLIB_SEPARATOR 
        "car_status"
    );
}

void primary_to_string_file_CAR_STATUS(primary_message_CAR_STATUS* message, FILE* buffer) {
    fprintf(
        buffer,
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d",
        message->inverter_l,
        message->inverter_r,
        message->car_status
    );
}

void primary_fields_file_CAR_STATUS(FILE* buffer) {
    fprintf(
        buffer,
        "inverter_l" CANLIB_SEPARATOR 
        "inverter_r" CANLIB_SEPARATOR 
        "car_status"
    );
}

void primary_to_string_DAS_ERRORS(primary_message_DAS_ERRORS* message, char* buffer) {
    sprintf(
        buffer,
        "%hhd",
        message->das_error
    );
}

void primary_fields_DAS_ERRORS(char* buffer) {
    sprintf(
        buffer,
        "das_error"
    );
}

void primary_to_string_file_DAS_ERRORS(primary_message_DAS_ERRORS* message, FILE* buffer) {
    fprintf(
        buffer,
        "%hhd",
        message->das_error
    );
}

void primary_fields_file_DAS_ERRORS(FILE* buffer) {
    fprintf(
        buffer,
        "das_error"
    );
}

void primary_to_string_LV_CURRENT(primary_message_LV_CURRENT* message, char* buffer) {
    sprintf(
        buffer,
        "%hhd",
        message->current
    );
}

void primary_fields_LV_CURRENT(char* buffer) {
    sprintf(
        buffer,
        "current"
    );
}

void primary_to_string_file_LV_CURRENT(primary_message_LV_CURRENT* message, FILE* buffer) {
    fprintf(
        buffer,
        "%hhd",
        message->current
    );
}

void primary_fields_file_LV_CURRENT(FILE* buffer) {
    fprintf(
        buffer,
        "current"
    );
}

void primary_to_string_LV_VOLTAGE(primary_message_LV_VOLTAGE* message, char* buffer) {
    sprintf(
        buffer,
        "%d" CANLIB_SEPARATOR 
        "%hhd" CANLIB_SEPARATOR 
        "%hhd" CANLIB_SEPARATOR 
        "%hhd" CANLIB_SEPARATOR 
        "%hhd",
        message->total_voltage,
        message->voltage_1,
        message->voltage_2,
        message->voltage_3,
        message->voltage_4
    );
}

void primary_fields_LV_VOLTAGE(char* buffer) {
    sprintf(
        buffer,
        "total_voltage" CANLIB_SEPARATOR 
        "voltage_1" CANLIB_SEPARATOR 
        "voltage_2" CANLIB_SEPARATOR 
        "voltage_3" CANLIB_SEPARATOR 
        "voltage_4"
    );
}

void primary_to_string_file_LV_VOLTAGE(primary_message_LV_VOLTAGE* message, FILE* buffer) {
    fprintf(
        buffer,
        "%d" CANLIB_SEPARATOR 
        "%hhd" CANLIB_SEPARATOR 
        "%hhd" CANLIB_SEPARATOR 
        "%hhd" CANLIB_SEPARATOR 
        "%hhd",
        message->total_voltage,
        message->voltage_1,
        message->voltage_2,
        message->voltage_3,
        message->voltage_4
    );
}

void primary_fields_file_LV_VOLTAGE(FILE* buffer) {
    fprintf(
        buffer,
        "total_voltage" CANLIB_SEPARATOR 
        "voltage_1" CANLIB_SEPARATOR 
        "voltage_2" CANLIB_SEPARATOR 
        "voltage_3" CANLIB_SEPARATOR 
        "voltage_4"
    );
}

void primary_to_string_LV_TEMPERATURE(primary_message_LV_TEMPERATURE* message, char* buffer) {
    sprintf(
        buffer,
        "%hhd" CANLIB_SEPARATOR 
        "%hhd",
        message->bp_temperature,
        message->dcdc_temperature
    );
}

void primary_fields_LV_TEMPERATURE(char* buffer) {
    sprintf(
        buffer,
        "bp_temperature" CANLIB_SEPARATOR 
        "dcdc_temperature"
    );
}

void primary_to_string_file_LV_TEMPERATURE(primary_message_LV_TEMPERATURE* message, FILE* buffer) {
    fprintf(
        buffer,
        "%hhd" CANLIB_SEPARATOR 
        "%hhd",
        message->bp_temperature,
        message->dcdc_temperature
    );
}

void primary_fields_file_LV_TEMPERATURE(FILE* buffer) {
    fprintf(
        buffer,
        "bp_temperature" CANLIB_SEPARATOR 
        "dcdc_temperature"
    );
}

void primary_to_string_COOLING_STATUS(primary_message_COOLING_STATUS* message, char* buffer) {
    sprintf(
        buffer,
        "%hhd" CANLIB_SEPARATOR 
        "%hhd" CANLIB_SEPARATOR 
        "%hhd",
        message->hv_fan_speed,
        message->lv_fan_speed,
        message->pump_speed
    );
}

void primary_fields_COOLING_STATUS(char* buffer) {
    sprintf(
        buffer,
        "hv_fan_speed" CANLIB_SEPARATOR 
        "lv_fan_speed" CANLIB_SEPARATOR 
        "pump_speed"
    );
}

void primary_to_string_file_COOLING_STATUS(primary_message_COOLING_STATUS* message, FILE* buffer) {
    fprintf(
        buffer,
        "%hhd" CANLIB_SEPARATOR 
        "%hhd" CANLIB_SEPARATOR 
        "%hhd",
        message->hv_fan_speed,
        message->lv_fan_speed,
        message->pump_speed
    );
}

void primary_fields_file_COOLING_STATUS(FILE* buffer) {
    fprintf(
        buffer,
        "hv_fan_speed" CANLIB_SEPARATOR 
        "lv_fan_speed" CANLIB_SEPARATOR 
        "pump_speed"
    );
}

void primary_to_string_MARKER(primary_message_MARKER* message, char* buffer) {}

void primary_fields_MARKER(char* buffer) {}

void primary_to_string_file_MARKER(primary_message_MARKER* message, FILE* buffer) {}

void primary_fields_file_MARKER(FILE* buffer) {}

void primary_to_string_HV_CELLS_VOLTAGE(primary_message_HV_CELLS_VOLTAGE* message, char* buffer) {
    sprintf(
        buffer,
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%hhd",
        message->voltage_0,
        message->voltage_1,
        message->voltage_2,
        message->cell_index
    );
}

void primary_fields_HV_CELLS_VOLTAGE(char* buffer) {
    sprintf(
        buffer,
        "voltage_0" CANLIB_SEPARATOR 
        "voltage_1" CANLIB_SEPARATOR 
        "voltage_2" CANLIB_SEPARATOR 
        "cell_index"
    );
}

void primary_to_string_file_HV_CELLS_VOLTAGE(primary_message_HV_CELLS_VOLTAGE* message, FILE* buffer) {
    fprintf(
        buffer,
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%hhd",
        message->voltage_0,
        message->voltage_1,
        message->voltage_2,
        message->cell_index
    );
}

void primary_fields_file_HV_CELLS_VOLTAGE(FILE* buffer) {
    fprintf(
        buffer,
        "voltage_0" CANLIB_SEPARATOR 
        "voltage_1" CANLIB_SEPARATOR 
        "voltage_2" CANLIB_SEPARATOR 
        "cell_index"
    );
}

void primary_to_string_HV_CELLS_TEMP(primary_message_HV_CELLS_TEMP* message, char* buffer) {
    sprintf(
        buffer,
        "%hhd" CANLIB_SEPARATOR 
        "%hhd" CANLIB_SEPARATOR 
        "%hhd" CANLIB_SEPARATOR 
        "%hhd" CANLIB_SEPARATOR 
        "%hhd" CANLIB_SEPARATOR 
        "%hhd" CANLIB_SEPARATOR 
        "%hhd" CANLIB_SEPARATOR 
        "%hhd",
        message->cell_index,
        message->temp_0,
        message->temp_1,
        message->temp_2,
        message->temp_3,
        message->temp_4,
        message->temp_5,
        message->temp_6
    );
}

void primary_fields_HV_CELLS_TEMP(char* buffer) {
    sprintf(
        buffer,
        "cell_index" CANLIB_SEPARATOR 
        "temp_0" CANLIB_SEPARATOR 
        "temp_1" CANLIB_SEPARATOR 
        "temp_2" CANLIB_SEPARATOR 
        "temp_3" CANLIB_SEPARATOR 
        "temp_4" CANLIB_SEPARATOR 
        "temp_5" CANLIB_SEPARATOR 
        "temp_6"
    );
}

void primary_to_string_file_HV_CELLS_TEMP(primary_message_HV_CELLS_TEMP* message, FILE* buffer) {
    fprintf(
        buffer,
        "%hhd" CANLIB_SEPARATOR 
        "%hhd" CANLIB_SEPARATOR 
        "%hhd" CANLIB_SEPARATOR 
        "%hhd" CANLIB_SEPARATOR 
        "%hhd" CANLIB_SEPARATOR 
        "%hhd" CANLIB_SEPARATOR 
        "%hhd" CANLIB_SEPARATOR 
        "%hhd",
        message->cell_index,
        message->temp_0,
        message->temp_1,
        message->temp_2,
        message->temp_3,
        message->temp_4,
        message->temp_5,
        message->temp_6
    );
}

void primary_fields_file_HV_CELLS_TEMP(FILE* buffer) {
    fprintf(
        buffer,
        "cell_index" CANLIB_SEPARATOR 
        "temp_0" CANLIB_SEPARATOR 
        "temp_1" CANLIB_SEPARATOR 
        "temp_2" CANLIB_SEPARATOR 
        "temp_3" CANLIB_SEPARATOR 
        "temp_4" CANLIB_SEPARATOR 
        "temp_5" CANLIB_SEPARATOR 
        "temp_6"
    );
}

void primary_to_string_HV_CELL_BALANCING_STATUS(primary_message_HV_CELL_BALANCING_STATUS* message, char* buffer) {
    sprintf(
        buffer,
        "%d",
        message->balancing_status
    );
}

void primary_fields_HV_CELL_BALANCING_STATUS(char* buffer) {
    sprintf(
        buffer,
        "balancing_status"
    );
}

void primary_to_string_file_HV_CELL_BALANCING_STATUS(primary_message_HV_CELL_BALANCING_STATUS* message, FILE* buffer) {
    fprintf(
        buffer,
        "%d",
        message->balancing_status
    );
}

void primary_fields_file_HV_CELL_BALANCING_STATUS(FILE* buffer) {
    fprintf(
        buffer,
        "balancing_status"
    );
}

void primary_to_string_SET_CELL_BALANCING_STATUS(primary_message_SET_CELL_BALANCING_STATUS* message, char* buffer) {
    sprintf(
        buffer,
        "%d",
        message->set_balancing_status
    );
}

void primary_fields_SET_CELL_BALANCING_STATUS(char* buffer) {
    sprintf(
        buffer,
        "set_balancing_status"
    );
}

void primary_to_string_file_SET_CELL_BALANCING_STATUS(primary_message_SET_CELL_BALANCING_STATUS* message, FILE* buffer) {
    fprintf(
        buffer,
        "%d",
        message->set_balancing_status
    );
}

void primary_fields_file_SET_CELL_BALANCING_STATUS(FILE* buffer) {
    fprintf(
        buffer,
        "set_balancing_status"
    );
}

void primary_to_string_HANDCART_STATUS(primary_message_HANDCART_STATUS* message, char* buffer) {
    sprintf(
        buffer,
        "%f",
        message->connected
    );
}

void primary_fields_HANDCART_STATUS(char* buffer) {
    sprintf(
        buffer,
        "connected"
    );
}

void primary_to_string_file_HANDCART_STATUS(primary_message_HANDCART_STATUS* message, FILE* buffer) {
    fprintf(
        buffer,
        "%f",
        message->connected
    );
}

void primary_fields_file_HANDCART_STATUS(FILE* buffer) {
    fprintf(
        buffer,
        "connected"
    );
}

void primary_to_string_SPEED(primary_message_SPEED* message, char* buffer) {
    sprintf(
        buffer,
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d",
        message->encoder_r,
        message->encoder_l,
        message->inverter_r,
        message->inverter_l
    );
}

void primary_fields_SPEED(char* buffer) {
    sprintf(
        buffer,
        "encoder_r" CANLIB_SEPARATOR 
        "encoder_l" CANLIB_SEPARATOR 
        "inverter_r" CANLIB_SEPARATOR 
        "inverter_l"
    );
}

void primary_to_string_file_SPEED(primary_message_SPEED* message, FILE* buffer) {
    fprintf(
        buffer,
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d",
        message->encoder_r,
        message->encoder_l,
        message->inverter_r,
        message->inverter_l
    );
}

void primary_fields_file_SPEED(FILE* buffer) {
    fprintf(
        buffer,
        "encoder_r" CANLIB_SEPARATOR 
        "encoder_l" CANLIB_SEPARATOR 
        "inverter_r" CANLIB_SEPARATOR 
        "inverter_l"
    );
}

void primary_to_string_INV_L_SET_TORQUE(primary_message_INV_L_SET_TORQUE* message, char* buffer) {
    sprintf(
        buffer,
        "%hhd" CANLIB_SEPARATOR 
        "%hhd" CANLIB_SEPARATOR 
        "%hhd",
        message->regid,
        message->lsb,
        message->msb
    );
}

void primary_fields_INV_L_SET_TORQUE(char* buffer) {
    sprintf(
        buffer,
        "regid" CANLIB_SEPARATOR 
        "lsb" CANLIB_SEPARATOR 
        "msb"
    );
}

void primary_to_string_file_INV_L_SET_TORQUE(primary_message_INV_L_SET_TORQUE* message, FILE* buffer) {
    fprintf(
        buffer,
        "%hhd" CANLIB_SEPARATOR 
        "%hhd" CANLIB_SEPARATOR 
        "%hhd",
        message->regid,
        message->lsb,
        message->msb
    );
}

void primary_fields_file_INV_L_SET_TORQUE(FILE* buffer) {
    fprintf(
        buffer,
        "regid" CANLIB_SEPARATOR 
        "lsb" CANLIB_SEPARATOR 
        "msb"
    );
}

void primary_to_string_INV_L_RESPONSE(primary_message_INV_L_RESPONSE* message, char* buffer) {
    sprintf(
        buffer,
        "%hhu" CANLIB_SEPARATOR 
        "%hhd",
        message->reg_val,
        message->reg_id
    );
}

void primary_fields_INV_L_RESPONSE(char* buffer) {
    sprintf(
        buffer,
        "reg_val" CANLIB_SEPARATOR 
        "reg_id"
    );
}

void primary_to_string_file_INV_L_RESPONSE(primary_message_INV_L_RESPONSE* message, FILE* buffer) {
    fprintf(
        buffer,
        "%hhu" CANLIB_SEPARATOR 
        "%hhd",
        message->reg_val,
        message->reg_id
    );
}

void primary_fields_file_INV_L_RESPONSE(FILE* buffer) {
    fprintf(
        buffer,
        "reg_val" CANLIB_SEPARATOR 
        "reg_id"
    );
}


#endif // primary_NETWORK_H