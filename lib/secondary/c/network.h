#ifndef secondary_NETWORK_H
#define secondary_NETWORK_H

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
#define CANLIB_BUILD
#define CANLIB_BUILD_TIME 1670347587
#define CANLIB_BUILD_HASH 0xffd7fb04
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

#ifndef CANLIB_PARKING
/* We know it's PACKING but PARKING sounds a bit better ;) */
#if defined(__MINGW32__)
#define CANLIB_PARKING __attribute__((__gcc_struct__, __packed__)) // , __aligned__(1)))
#else
#define CANLIB_PARKING __attribute__((__packed__)) // , __aligned__(1)))
#endif // defined(__MINGW32__)
#endif // CANLIB_PARKING

#define PRIf32 "f"
#define PRIf64 "f"

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

#define secondary_MESSAGE_COUNT 25

// Custom types

#define secondary_int8 int8_t
#define secondary_uint8 uint8_t
#define secondary_int16 int16_t
#define secondary_uint16 uint16_t
#define secondary_int32 int32_t
#define secondary_uint32 uint32_t
#define secondary_int64 int64_t
#define secondary_uint64 uint64_t
#define secondary_float32 float
#define secondary_float64 double
#define secondary_bool bool
#define secondary_byte_size uint32_t

typedef union {
    secondary_uint8 bytes[4];
    secondary_float32 value;
} secondary_float32_helper;

typedef union {
    secondary_uint8 bytes[8];
    secondary_float64 value;
} secondary_float64_helper;

#ifdef __cplusplus
#define secondary_float32_to_bytes(float, index) (reinterpret_cast<secondary_uint8*>(&((float)))[(index)])
#define secondary_float64_to_bytes(float, index) (reinterpret_cast<secondary_uint8*>(&((float)))[(index)])
#else
#define secondary_float32_to_bytes(float, index) (((secondary_float32_helper) (float)).bytes[(index)])
#define secondary_float64_to_bytes(float, index) (((secondary_float64_helper) (float)).bytes[(index)])
#endif

typedef struct {
    uint16_t id;
    void* message_raw;
    void* message_conversion;
} secondary_devices_t;
typedef secondary_devices_t secondary_devices[secondary_MESSAGE_COUNT];


// ============== INDEXES ============ //


#define secondary_INDEX_IMU_ANGULAR_RATE 0
#define secondary_INDEX_IMU_ACCELERATION 1
#define secondary_INDEX_IRTS_FL_0 2
#define secondary_INDEX_IRTS_FL_1 3
#define secondary_INDEX_IRTS_FL_2 4
#define secondary_INDEX_IRTS_FL_3 5
#define secondary_INDEX_IRTS_FR_0 6
#define secondary_INDEX_IRTS_FR_1 7
#define secondary_INDEX_IRTS_FR_2 8
#define secondary_INDEX_IRTS_FR_3 9
#define secondary_INDEX_IRTS_RL_0 10
#define secondary_INDEX_IRTS_RL_1 11
#define secondary_INDEX_IRTS_RL_2 12
#define secondary_INDEX_IRTS_RL_3 13
#define secondary_INDEX_IRTS_RR_0 14
#define secondary_INDEX_IRTS_RR_1 15
#define secondary_INDEX_IRTS_RR_2 16
#define secondary_INDEX_IRTS_RR_3 17
#define secondary_INDEX_GPS_COORDS 18
#define secondary_INDEX_GPS_SPEED 19
#define secondary_INDEX_LAP_COUNT 20
#define secondary_INDEX_PEDALS_OUTPUT 21
#define secondary_INDEX_CONTROL_OUTPUT 22
#define secondary_INDEX_STEERING_ANGLE 23
#define secondary_INDEX_TPMS 24

// ============== SIZES ============== //


#define secondary_SIZE_IMU_ANGULAR_RATE 6
#define secondary_SIZE_IMU_ACCELERATION 8
#define secondary_SIZE_IRTS_FL_0 8
#define secondary_SIZE_IRTS_FL_1 8
#define secondary_SIZE_IRTS_FL_2 8
#define secondary_SIZE_IRTS_FL_3 8
#define secondary_SIZE_IRTS_FR_0 8
#define secondary_SIZE_IRTS_FR_1 8
#define secondary_SIZE_IRTS_FR_2 8
#define secondary_SIZE_IRTS_FR_3 8
#define secondary_SIZE_IRTS_RL_0 8
#define secondary_SIZE_IRTS_RL_1 8
#define secondary_SIZE_IRTS_RL_2 8
#define secondary_SIZE_IRTS_RL_3 8
#define secondary_SIZE_IRTS_RR_0 8
#define secondary_SIZE_IRTS_RR_1 8
#define secondary_SIZE_IRTS_RR_2 8
#define secondary_SIZE_IRTS_RR_3 8
#define secondary_SIZE_GPS_COORDS 8
#define secondary_SIZE_GPS_SPEED 2
#define secondary_SIZE_LAP_COUNT 5
#define secondary_SIZE_PEDALS_OUTPUT 5
#define secondary_SIZE_CONTROL_OUTPUT 8
#define secondary_SIZE_STEERING_ANGLE 4
#define secondary_SIZE_TPMS 8

// ============== BIT SETS =========== //



// ============== ENUMS ============== //



// Structs


typedef struct CANLIB_PARKING {
    secondary_int16 ang_rate_x;
    secondary_int16 ang_rate_y;
    secondary_int16 ang_rate_z;
#ifdef CANLIB_TIMESTAMP
    secondary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} secondary_message_IMU_ANGULAR_RATE;

typedef struct CANLIB_PARKING {
    secondary_float32 ang_rate_x;
    secondary_float32 ang_rate_y;
    secondary_float32 ang_rate_z;
#ifdef CANLIB_TIMESTAMP
    secondary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} secondary_message_IMU_ANGULAR_RATE_conversion;

typedef struct CANLIB_PARKING {
    secondary_int16 accel_x;
    secondary_int16 accel_y;
    secondary_int16 accel_z;
    secondary_int16 temperature;
#ifdef CANLIB_TIMESTAMP
    secondary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} secondary_message_IMU_ACCELERATION;

typedef struct CANLIB_PARKING {
    secondary_float32 accel_x;
    secondary_float32 accel_y;
    secondary_float32 accel_z;
    secondary_int16 temperature;
#ifdef CANLIB_TIMESTAMP
    secondary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} secondary_message_IMU_ACCELERATION_conversion;

typedef struct CANLIB_PARKING {
    secondary_uint16 channel1;
    secondary_uint16 channel2;
    secondary_uint16 channel3;
    secondary_uint16 channel4;
#ifdef CANLIB_TIMESTAMP
    secondary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} secondary_message_IRTS_FL_0;

typedef struct CANLIB_PARKING {
    secondary_uint16 channel5;
    secondary_uint16 channel6;
    secondary_uint16 channel7;
    secondary_uint16 channel8;
#ifdef CANLIB_TIMESTAMP
    secondary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} secondary_message_IRTS_FL_1;

typedef struct CANLIB_PARKING {
    secondary_uint16 channel9;
    secondary_uint16 channel10;
    secondary_uint16 channel11;
    secondary_uint16 channel12;
#ifdef CANLIB_TIMESTAMP
    secondary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} secondary_message_IRTS_FL_2;

typedef struct CANLIB_PARKING {
    secondary_uint16 channel13;
    secondary_uint16 channel14;
    secondary_uint16 channel15;
    secondary_uint16 channel16;
#ifdef CANLIB_TIMESTAMP
    secondary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} secondary_message_IRTS_FL_3;

typedef struct CANLIB_PARKING {
    secondary_uint16 channel1;
    secondary_uint16 channel2;
    secondary_uint16 channel3;
    secondary_uint16 channel4;
#ifdef CANLIB_TIMESTAMP
    secondary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} secondary_message_IRTS_FR_0;

typedef struct CANLIB_PARKING {
    secondary_uint16 channel5;
    secondary_uint16 channel6;
    secondary_uint16 channel7;
    secondary_uint16 channel8;
#ifdef CANLIB_TIMESTAMP
    secondary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} secondary_message_IRTS_FR_1;

typedef struct CANLIB_PARKING {
    secondary_uint16 channel9;
    secondary_uint16 channel10;
    secondary_uint16 channel11;
    secondary_uint16 channel12;
#ifdef CANLIB_TIMESTAMP
    secondary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} secondary_message_IRTS_FR_2;

typedef struct CANLIB_PARKING {
    secondary_uint16 channel13;
    secondary_uint16 channel14;
    secondary_uint16 channel15;
    secondary_uint16 channel16;
#ifdef CANLIB_TIMESTAMP
    secondary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} secondary_message_IRTS_FR_3;

typedef struct CANLIB_PARKING {
    secondary_uint16 channel1;
    secondary_uint16 channel2;
    secondary_uint16 channel3;
    secondary_uint16 channel4;
#ifdef CANLIB_TIMESTAMP
    secondary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} secondary_message_IRTS_RL_0;

typedef struct CANLIB_PARKING {
    secondary_uint16 channel5;
    secondary_uint16 channel6;
    secondary_uint16 channel7;
    secondary_uint16 channel8;
#ifdef CANLIB_TIMESTAMP
    secondary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} secondary_message_IRTS_RL_1;

typedef struct CANLIB_PARKING {
    secondary_uint16 channel9;
    secondary_uint16 channel10;
    secondary_uint16 channel11;
    secondary_uint16 channel12;
#ifdef CANLIB_TIMESTAMP
    secondary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} secondary_message_IRTS_RL_2;

typedef struct CANLIB_PARKING {
    secondary_uint16 channel13;
    secondary_uint16 channel14;
    secondary_uint16 channel15;
    secondary_uint16 channel16;
#ifdef CANLIB_TIMESTAMP
    secondary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} secondary_message_IRTS_RL_3;

typedef struct CANLIB_PARKING {
    secondary_uint16 channel1;
    secondary_uint16 channel2;
    secondary_uint16 channel3;
    secondary_uint16 channel4;
#ifdef CANLIB_TIMESTAMP
    secondary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} secondary_message_IRTS_RR_0;

typedef struct CANLIB_PARKING {
    secondary_uint16 channel5;
    secondary_uint16 channel6;
    secondary_uint16 channel7;
    secondary_uint16 channel8;
#ifdef CANLIB_TIMESTAMP
    secondary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} secondary_message_IRTS_RR_1;

typedef struct CANLIB_PARKING {
    secondary_uint16 channel9;
    secondary_uint16 channel10;
    secondary_uint16 channel11;
    secondary_uint16 channel12;
#ifdef CANLIB_TIMESTAMP
    secondary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} secondary_message_IRTS_RR_2;

typedef struct CANLIB_PARKING {
    secondary_uint16 channel13;
    secondary_uint16 channel14;
    secondary_uint16 channel15;
    secondary_uint16 channel16;
#ifdef CANLIB_TIMESTAMP
    secondary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} secondary_message_IRTS_RR_3;

typedef struct CANLIB_PARKING {
    secondary_float32 latitude;
    secondary_float32 longitude;
#ifdef CANLIB_TIMESTAMP
    secondary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} secondary_message_GPS_COORDS;

typedef struct CANLIB_PARKING {
    secondary_uint16 speed;
#ifdef CANLIB_TIMESTAMP
    secondary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} secondary_message_GPS_SPEED;

typedef struct CANLIB_PARKING {
    secondary_uint8 lap_count;
    secondary_uint32 lap_time;
#ifdef CANLIB_TIMESTAMP
    secondary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} secondary_message_LAP_COUNT;

typedef struct CANLIB_PARKING {
    secondary_uint8 apps;
    secondary_uint16 bse_front;
    secondary_uint16 bse_rear;
#ifdef CANLIB_TIMESTAMP
    secondary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} secondary_message_PEDALS_OUTPUT;

typedef struct CANLIB_PARKING {
    secondary_uint8 apps;
    secondary_float32 bse_front;
    secondary_float32 bse_rear;
#ifdef CANLIB_TIMESTAMP
    secondary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} secondary_message_PEDALS_OUTPUT_conversion;

typedef struct CANLIB_PARKING {
    secondary_uint16 estimated_velocity;
    secondary_uint8 tmax_r;
    secondary_uint8 tmax_l;
    secondary_uint16 torque_l;
    secondary_uint16 torque_r;
#ifdef CANLIB_TIMESTAMP
    secondary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} secondary_message_CONTROL_OUTPUT;

typedef struct CANLIB_PARKING {
    secondary_float32 estimated_velocity;
    secondary_float32 tmax_r;
    secondary_float32 tmax_l;
    secondary_float32 torque_l;
    secondary_float32 torque_r;
#ifdef CANLIB_TIMESTAMP
    secondary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} secondary_message_CONTROL_OUTPUT_conversion;

typedef struct CANLIB_PARKING {
    secondary_float32 angle;
#ifdef CANLIB_TIMESTAMP
    secondary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} secondary_message_STEERING_ANGLE;

typedef struct CANLIB_PARKING {
    secondary_uint8 fl_pressure;
    secondary_uint8 fl_temperature;
    secondary_uint8 fr_pressure;
    secondary_uint8 fr_temperature;
    secondary_uint8 rl_pressure;
    secondary_uint8 rl_temperature;
    secondary_uint8 rr_pressure;
    secondary_uint8 rr_temperature;
#ifdef CANLIB_TIMESTAMP
    secondary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} secondary_message_TPMS;


typedef union CANLIB_PARKING {
    secondary_message_IMU_ANGULAR_RATE _IMU_ANGULAR_RATE;
    secondary_message_IMU_ACCELERATION _IMU_ACCELERATION;
    secondary_message_IRTS_FL_0 _IRTS_FL_0;
    secondary_message_IRTS_FL_1 _IRTS_FL_1;
    secondary_message_IRTS_FL_2 _IRTS_FL_2;
    secondary_message_IRTS_FL_3 _IRTS_FL_3;
    secondary_message_IRTS_FR_0 _IRTS_FR_0;
    secondary_message_IRTS_FR_1 _IRTS_FR_1;
    secondary_message_IRTS_FR_2 _IRTS_FR_2;
    secondary_message_IRTS_FR_3 _IRTS_FR_3;
    secondary_message_IRTS_RL_0 _IRTS_RL_0;
    secondary_message_IRTS_RL_1 _IRTS_RL_1;
    secondary_message_IRTS_RL_2 _IRTS_RL_2;
    secondary_message_IRTS_RL_3 _IRTS_RL_3;
    secondary_message_IRTS_RR_0 _IRTS_RR_0;
    secondary_message_IRTS_RR_1 _IRTS_RR_1;
    secondary_message_IRTS_RR_2 _IRTS_RR_2;
    secondary_message_IRTS_RR_3 _IRTS_RR_3;
    secondary_message_GPS_COORDS _GPS_COORDS;
    secondary_message_GPS_SPEED _GPS_SPEED;
    secondary_message_LAP_COUNT _LAP_COUNT;
    secondary_message_PEDALS_OUTPUT _PEDALS_OUTPUT;
    secondary_message_CONTROL_OUTPUT _CONTROL_OUTPUT;
    secondary_message_STEERING_ANGLE _STEERING_ANGLE;
    secondary_message_TPMS _TPMS;
} _secondary_all_structs_raw;

typedef union CANLIB_PARKING {
    secondary_message_IMU_ANGULAR_RATE_conversion _IMU_ANGULAR_RATE;
    secondary_message_IMU_ACCELERATION_conversion _IMU_ACCELERATION;
    secondary_message_PEDALS_OUTPUT_conversion _PEDALS_OUTPUT;
    secondary_message_CONTROL_OUTPUT_conversion _CONTROL_OUTPUT;
} _secondary_all_structs_conversion;

typedef union CANLIB_PARKING {
    _secondary_all_structs_raw raw;
    _secondary_all_structs_conversion conversion;
} _secondary_all_structs;

#define secondary_MAX_STRUCT_SIZE_RAW sizeof(_secondary_all_structs_raw)
#define secondary_MAX_STRUCT_SIZE_CONVERSION sizeof(_secondary_all_structs_conversion)
#define secondary_MAX_STRUCT_SIZE sizeof(_secondary_all_structs)


// ============== IMU_ANGULAR_RATE ============== //

secondary_byte_size secondary_serialize_IMU_ANGULAR_RATE(
    uint8_t* data,
    secondary_int16 ang_rate_x,
    secondary_int16 ang_rate_y,
    secondary_int16 ang_rate_z
);
secondary_byte_size secondary_serialize_struct_IMU_ANGULAR_RATE(
    uint8_t* data,
    secondary_message_IMU_ANGULAR_RATE* message
);
void secondary_deserialize_IMU_ANGULAR_RATE(
    secondary_message_IMU_ANGULAR_RATE* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
void secondary_raw_to_conversion_struct_IMU_ANGULAR_RATE(
    secondary_message_IMU_ANGULAR_RATE_conversion* conversion,
    secondary_message_IMU_ANGULAR_RATE* raw
);

void secondary_conversion_to_raw_struct_IMU_ANGULAR_RATE(
    secondary_message_IMU_ANGULAR_RATE* raw,
    secondary_message_IMU_ANGULAR_RATE_conversion* conversion
);

void secondary_conversion_to_raw_IMU_ANGULAR_RATE(
    secondary_message_IMU_ANGULAR_RATE* raw,
    secondary_float32 ang_rate_x,
    secondary_float32 ang_rate_y,
    secondary_float32 ang_rate_z
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
);

void secondary_raw_to_conversion_IMU_ANGULAR_RATE(
    secondary_message_IMU_ANGULAR_RATE_conversion* conversion,
    secondary_int16 ang_rate_x,
    secondary_int16 ang_rate_y,
    secondary_int16 ang_rate_z
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
);
int secondary_to_string_IMU_ANGULAR_RATE(secondary_message_IMU_ANGULAR_RATE_conversion* message, char* buffer);
int secondary_fields_IMU_ANGULAR_RATE(char* buffer);
int secondary_to_string_file_IMU_ANGULAR_RATE(secondary_message_IMU_ANGULAR_RATE_conversion* message, FILE* buffer);
int secondary_fields_file_IMU_ANGULAR_RATE(FILE* buffer);


// ============== IMU_ACCELERATION ============== //

secondary_byte_size secondary_serialize_IMU_ACCELERATION(
    uint8_t* data,
    secondary_int16 accel_x,
    secondary_int16 accel_y,
    secondary_int16 accel_z,
    secondary_int16 temperature
);
secondary_byte_size secondary_serialize_struct_IMU_ACCELERATION(
    uint8_t* data,
    secondary_message_IMU_ACCELERATION* message
);
void secondary_deserialize_IMU_ACCELERATION(
    secondary_message_IMU_ACCELERATION* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
void secondary_raw_to_conversion_struct_IMU_ACCELERATION(
    secondary_message_IMU_ACCELERATION_conversion* conversion,
    secondary_message_IMU_ACCELERATION* raw
);

void secondary_conversion_to_raw_struct_IMU_ACCELERATION(
    secondary_message_IMU_ACCELERATION* raw,
    secondary_message_IMU_ACCELERATION_conversion* conversion
);

void secondary_conversion_to_raw_IMU_ACCELERATION(
    secondary_message_IMU_ACCELERATION* raw,
    secondary_float32 accel_x,
    secondary_float32 accel_y,
    secondary_float32 accel_z,
    secondary_int16 temperature
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
);

void secondary_raw_to_conversion_IMU_ACCELERATION(
    secondary_message_IMU_ACCELERATION_conversion* conversion,
    secondary_int16 accel_x,
    secondary_int16 accel_y,
    secondary_int16 accel_z,
    secondary_int16 temperature
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
);
int secondary_to_string_IMU_ACCELERATION(secondary_message_IMU_ACCELERATION_conversion* message, char* buffer);
int secondary_fields_IMU_ACCELERATION(char* buffer);
int secondary_to_string_file_IMU_ACCELERATION(secondary_message_IMU_ACCELERATION_conversion* message, FILE* buffer);
int secondary_fields_file_IMU_ACCELERATION(FILE* buffer);


// ============== IRTS_FL_0 ============== //

secondary_byte_size secondary_serialize_IRTS_FL_0(
    uint8_t* data,
    secondary_uint16 channel1,
    secondary_uint16 channel2,
    secondary_uint16 channel3,
    secondary_uint16 channel4
);
secondary_byte_size secondary_serialize_struct_IRTS_FL_0(
    uint8_t* data,
    secondary_message_IRTS_FL_0* message
);
void secondary_deserialize_IRTS_FL_0(
    secondary_message_IRTS_FL_0* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int secondary_to_string_IRTS_FL_0(secondary_message_IRTS_FL_0* message, char* buffer);
int secondary_fields_IRTS_FL_0(char* buffer);
int secondary_to_string_file_IRTS_FL_0(secondary_message_IRTS_FL_0* message, FILE* buffer);
int secondary_fields_file_IRTS_FL_0(FILE* buffer);


// ============== IRTS_FL_1 ============== //

secondary_byte_size secondary_serialize_IRTS_FL_1(
    uint8_t* data,
    secondary_uint16 channel5,
    secondary_uint16 channel6,
    secondary_uint16 channel7,
    secondary_uint16 channel8
);
secondary_byte_size secondary_serialize_struct_IRTS_FL_1(
    uint8_t* data,
    secondary_message_IRTS_FL_1* message
);
void secondary_deserialize_IRTS_FL_1(
    secondary_message_IRTS_FL_1* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int secondary_to_string_IRTS_FL_1(secondary_message_IRTS_FL_1* message, char* buffer);
int secondary_fields_IRTS_FL_1(char* buffer);
int secondary_to_string_file_IRTS_FL_1(secondary_message_IRTS_FL_1* message, FILE* buffer);
int secondary_fields_file_IRTS_FL_1(FILE* buffer);


// ============== IRTS_FL_2 ============== //

secondary_byte_size secondary_serialize_IRTS_FL_2(
    uint8_t* data,
    secondary_uint16 channel9,
    secondary_uint16 channel10,
    secondary_uint16 channel11,
    secondary_uint16 channel12
);
secondary_byte_size secondary_serialize_struct_IRTS_FL_2(
    uint8_t* data,
    secondary_message_IRTS_FL_2* message
);
void secondary_deserialize_IRTS_FL_2(
    secondary_message_IRTS_FL_2* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int secondary_to_string_IRTS_FL_2(secondary_message_IRTS_FL_2* message, char* buffer);
int secondary_fields_IRTS_FL_2(char* buffer);
int secondary_to_string_file_IRTS_FL_2(secondary_message_IRTS_FL_2* message, FILE* buffer);
int secondary_fields_file_IRTS_FL_2(FILE* buffer);


// ============== IRTS_FL_3 ============== //

secondary_byte_size secondary_serialize_IRTS_FL_3(
    uint8_t* data,
    secondary_uint16 channel13,
    secondary_uint16 channel14,
    secondary_uint16 channel15,
    secondary_uint16 channel16
);
secondary_byte_size secondary_serialize_struct_IRTS_FL_3(
    uint8_t* data,
    secondary_message_IRTS_FL_3* message
);
void secondary_deserialize_IRTS_FL_3(
    secondary_message_IRTS_FL_3* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int secondary_to_string_IRTS_FL_3(secondary_message_IRTS_FL_3* message, char* buffer);
int secondary_fields_IRTS_FL_3(char* buffer);
int secondary_to_string_file_IRTS_FL_3(secondary_message_IRTS_FL_3* message, FILE* buffer);
int secondary_fields_file_IRTS_FL_3(FILE* buffer);


// ============== IRTS_FR_0 ============== //

secondary_byte_size secondary_serialize_IRTS_FR_0(
    uint8_t* data,
    secondary_uint16 channel1,
    secondary_uint16 channel2,
    secondary_uint16 channel3,
    secondary_uint16 channel4
);
secondary_byte_size secondary_serialize_struct_IRTS_FR_0(
    uint8_t* data,
    secondary_message_IRTS_FR_0* message
);
void secondary_deserialize_IRTS_FR_0(
    secondary_message_IRTS_FR_0* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int secondary_to_string_IRTS_FR_0(secondary_message_IRTS_FR_0* message, char* buffer);
int secondary_fields_IRTS_FR_0(char* buffer);
int secondary_to_string_file_IRTS_FR_0(secondary_message_IRTS_FR_0* message, FILE* buffer);
int secondary_fields_file_IRTS_FR_0(FILE* buffer);


// ============== IRTS_FR_1 ============== //

secondary_byte_size secondary_serialize_IRTS_FR_1(
    uint8_t* data,
    secondary_uint16 channel5,
    secondary_uint16 channel6,
    secondary_uint16 channel7,
    secondary_uint16 channel8
);
secondary_byte_size secondary_serialize_struct_IRTS_FR_1(
    uint8_t* data,
    secondary_message_IRTS_FR_1* message
);
void secondary_deserialize_IRTS_FR_1(
    secondary_message_IRTS_FR_1* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int secondary_to_string_IRTS_FR_1(secondary_message_IRTS_FR_1* message, char* buffer);
int secondary_fields_IRTS_FR_1(char* buffer);
int secondary_to_string_file_IRTS_FR_1(secondary_message_IRTS_FR_1* message, FILE* buffer);
int secondary_fields_file_IRTS_FR_1(FILE* buffer);


// ============== IRTS_FR_2 ============== //

secondary_byte_size secondary_serialize_IRTS_FR_2(
    uint8_t* data,
    secondary_uint16 channel9,
    secondary_uint16 channel10,
    secondary_uint16 channel11,
    secondary_uint16 channel12
);
secondary_byte_size secondary_serialize_struct_IRTS_FR_2(
    uint8_t* data,
    secondary_message_IRTS_FR_2* message
);
void secondary_deserialize_IRTS_FR_2(
    secondary_message_IRTS_FR_2* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int secondary_to_string_IRTS_FR_2(secondary_message_IRTS_FR_2* message, char* buffer);
int secondary_fields_IRTS_FR_2(char* buffer);
int secondary_to_string_file_IRTS_FR_2(secondary_message_IRTS_FR_2* message, FILE* buffer);
int secondary_fields_file_IRTS_FR_2(FILE* buffer);


// ============== IRTS_FR_3 ============== //

secondary_byte_size secondary_serialize_IRTS_FR_3(
    uint8_t* data,
    secondary_uint16 channel13,
    secondary_uint16 channel14,
    secondary_uint16 channel15,
    secondary_uint16 channel16
);
secondary_byte_size secondary_serialize_struct_IRTS_FR_3(
    uint8_t* data,
    secondary_message_IRTS_FR_3* message
);
void secondary_deserialize_IRTS_FR_3(
    secondary_message_IRTS_FR_3* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int secondary_to_string_IRTS_FR_3(secondary_message_IRTS_FR_3* message, char* buffer);
int secondary_fields_IRTS_FR_3(char* buffer);
int secondary_to_string_file_IRTS_FR_3(secondary_message_IRTS_FR_3* message, FILE* buffer);
int secondary_fields_file_IRTS_FR_3(FILE* buffer);


// ============== IRTS_RL_0 ============== //

secondary_byte_size secondary_serialize_IRTS_RL_0(
    uint8_t* data,
    secondary_uint16 channel1,
    secondary_uint16 channel2,
    secondary_uint16 channel3,
    secondary_uint16 channel4
);
secondary_byte_size secondary_serialize_struct_IRTS_RL_0(
    uint8_t* data,
    secondary_message_IRTS_RL_0* message
);
void secondary_deserialize_IRTS_RL_0(
    secondary_message_IRTS_RL_0* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int secondary_to_string_IRTS_RL_0(secondary_message_IRTS_RL_0* message, char* buffer);
int secondary_fields_IRTS_RL_0(char* buffer);
int secondary_to_string_file_IRTS_RL_0(secondary_message_IRTS_RL_0* message, FILE* buffer);
int secondary_fields_file_IRTS_RL_0(FILE* buffer);


// ============== IRTS_RL_1 ============== //

secondary_byte_size secondary_serialize_IRTS_RL_1(
    uint8_t* data,
    secondary_uint16 channel5,
    secondary_uint16 channel6,
    secondary_uint16 channel7,
    secondary_uint16 channel8
);
secondary_byte_size secondary_serialize_struct_IRTS_RL_1(
    uint8_t* data,
    secondary_message_IRTS_RL_1* message
);
void secondary_deserialize_IRTS_RL_1(
    secondary_message_IRTS_RL_1* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int secondary_to_string_IRTS_RL_1(secondary_message_IRTS_RL_1* message, char* buffer);
int secondary_fields_IRTS_RL_1(char* buffer);
int secondary_to_string_file_IRTS_RL_1(secondary_message_IRTS_RL_1* message, FILE* buffer);
int secondary_fields_file_IRTS_RL_1(FILE* buffer);


// ============== IRTS_RL_2 ============== //

secondary_byte_size secondary_serialize_IRTS_RL_2(
    uint8_t* data,
    secondary_uint16 channel9,
    secondary_uint16 channel10,
    secondary_uint16 channel11,
    secondary_uint16 channel12
);
secondary_byte_size secondary_serialize_struct_IRTS_RL_2(
    uint8_t* data,
    secondary_message_IRTS_RL_2* message
);
void secondary_deserialize_IRTS_RL_2(
    secondary_message_IRTS_RL_2* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int secondary_to_string_IRTS_RL_2(secondary_message_IRTS_RL_2* message, char* buffer);
int secondary_fields_IRTS_RL_2(char* buffer);
int secondary_to_string_file_IRTS_RL_2(secondary_message_IRTS_RL_2* message, FILE* buffer);
int secondary_fields_file_IRTS_RL_2(FILE* buffer);


// ============== IRTS_RL_3 ============== //

secondary_byte_size secondary_serialize_IRTS_RL_3(
    uint8_t* data,
    secondary_uint16 channel13,
    secondary_uint16 channel14,
    secondary_uint16 channel15,
    secondary_uint16 channel16
);
secondary_byte_size secondary_serialize_struct_IRTS_RL_3(
    uint8_t* data,
    secondary_message_IRTS_RL_3* message
);
void secondary_deserialize_IRTS_RL_3(
    secondary_message_IRTS_RL_3* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int secondary_to_string_IRTS_RL_3(secondary_message_IRTS_RL_3* message, char* buffer);
int secondary_fields_IRTS_RL_3(char* buffer);
int secondary_to_string_file_IRTS_RL_3(secondary_message_IRTS_RL_3* message, FILE* buffer);
int secondary_fields_file_IRTS_RL_3(FILE* buffer);


// ============== IRTS_RR_0 ============== //

secondary_byte_size secondary_serialize_IRTS_RR_0(
    uint8_t* data,
    secondary_uint16 channel1,
    secondary_uint16 channel2,
    secondary_uint16 channel3,
    secondary_uint16 channel4
);
secondary_byte_size secondary_serialize_struct_IRTS_RR_0(
    uint8_t* data,
    secondary_message_IRTS_RR_0* message
);
void secondary_deserialize_IRTS_RR_0(
    secondary_message_IRTS_RR_0* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int secondary_to_string_IRTS_RR_0(secondary_message_IRTS_RR_0* message, char* buffer);
int secondary_fields_IRTS_RR_0(char* buffer);
int secondary_to_string_file_IRTS_RR_0(secondary_message_IRTS_RR_0* message, FILE* buffer);
int secondary_fields_file_IRTS_RR_0(FILE* buffer);


// ============== IRTS_RR_1 ============== //

secondary_byte_size secondary_serialize_IRTS_RR_1(
    uint8_t* data,
    secondary_uint16 channel5,
    secondary_uint16 channel6,
    secondary_uint16 channel7,
    secondary_uint16 channel8
);
secondary_byte_size secondary_serialize_struct_IRTS_RR_1(
    uint8_t* data,
    secondary_message_IRTS_RR_1* message
);
void secondary_deserialize_IRTS_RR_1(
    secondary_message_IRTS_RR_1* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int secondary_to_string_IRTS_RR_1(secondary_message_IRTS_RR_1* message, char* buffer);
int secondary_fields_IRTS_RR_1(char* buffer);
int secondary_to_string_file_IRTS_RR_1(secondary_message_IRTS_RR_1* message, FILE* buffer);
int secondary_fields_file_IRTS_RR_1(FILE* buffer);


// ============== IRTS_RR_2 ============== //

secondary_byte_size secondary_serialize_IRTS_RR_2(
    uint8_t* data,
    secondary_uint16 channel9,
    secondary_uint16 channel10,
    secondary_uint16 channel11,
    secondary_uint16 channel12
);
secondary_byte_size secondary_serialize_struct_IRTS_RR_2(
    uint8_t* data,
    secondary_message_IRTS_RR_2* message
);
void secondary_deserialize_IRTS_RR_2(
    secondary_message_IRTS_RR_2* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int secondary_to_string_IRTS_RR_2(secondary_message_IRTS_RR_2* message, char* buffer);
int secondary_fields_IRTS_RR_2(char* buffer);
int secondary_to_string_file_IRTS_RR_2(secondary_message_IRTS_RR_2* message, FILE* buffer);
int secondary_fields_file_IRTS_RR_2(FILE* buffer);


// ============== IRTS_RR_3 ============== //

secondary_byte_size secondary_serialize_IRTS_RR_3(
    uint8_t* data,
    secondary_uint16 channel13,
    secondary_uint16 channel14,
    secondary_uint16 channel15,
    secondary_uint16 channel16
);
secondary_byte_size secondary_serialize_struct_IRTS_RR_3(
    uint8_t* data,
    secondary_message_IRTS_RR_3* message
);
void secondary_deserialize_IRTS_RR_3(
    secondary_message_IRTS_RR_3* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int secondary_to_string_IRTS_RR_3(secondary_message_IRTS_RR_3* message, char* buffer);
int secondary_fields_IRTS_RR_3(char* buffer);
int secondary_to_string_file_IRTS_RR_3(secondary_message_IRTS_RR_3* message, FILE* buffer);
int secondary_fields_file_IRTS_RR_3(FILE* buffer);


// ============== GPS_COORDS ============== //

secondary_byte_size secondary_serialize_GPS_COORDS(
    uint8_t* data,
    secondary_float32 latitude,
    secondary_float32 longitude
);
secondary_byte_size secondary_serialize_struct_GPS_COORDS(
    uint8_t* data,
    secondary_message_GPS_COORDS* message
);
void secondary_deserialize_GPS_COORDS(
    secondary_message_GPS_COORDS* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int secondary_to_string_GPS_COORDS(secondary_message_GPS_COORDS* message, char* buffer);
int secondary_fields_GPS_COORDS(char* buffer);
int secondary_to_string_file_GPS_COORDS(secondary_message_GPS_COORDS* message, FILE* buffer);
int secondary_fields_file_GPS_COORDS(FILE* buffer);


// ============== GPS_SPEED ============== //

secondary_byte_size secondary_serialize_GPS_SPEED(
    uint8_t* data,
    secondary_uint16 speed
);
secondary_byte_size secondary_serialize_struct_GPS_SPEED(
    uint8_t* data,
    secondary_message_GPS_SPEED* message
);
void secondary_deserialize_GPS_SPEED(
    secondary_message_GPS_SPEED* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int secondary_to_string_GPS_SPEED(secondary_message_GPS_SPEED* message, char* buffer);
int secondary_fields_GPS_SPEED(char* buffer);
int secondary_to_string_file_GPS_SPEED(secondary_message_GPS_SPEED* message, FILE* buffer);
int secondary_fields_file_GPS_SPEED(FILE* buffer);


// ============== LAP_COUNT ============== //

secondary_byte_size secondary_serialize_LAP_COUNT(
    uint8_t* data,
    secondary_uint8 lap_count,
    secondary_uint32 lap_time
);
secondary_byte_size secondary_serialize_struct_LAP_COUNT(
    uint8_t* data,
    secondary_message_LAP_COUNT* message
);
void secondary_deserialize_LAP_COUNT(
    secondary_message_LAP_COUNT* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int secondary_to_string_LAP_COUNT(secondary_message_LAP_COUNT* message, char* buffer);
int secondary_fields_LAP_COUNT(char* buffer);
int secondary_to_string_file_LAP_COUNT(secondary_message_LAP_COUNT* message, FILE* buffer);
int secondary_fields_file_LAP_COUNT(FILE* buffer);


// ============== PEDALS_OUTPUT ============== //

secondary_byte_size secondary_serialize_PEDALS_OUTPUT(
    uint8_t* data,
    secondary_uint8 apps,
    secondary_uint16 bse_front,
    secondary_uint16 bse_rear
);
secondary_byte_size secondary_serialize_struct_PEDALS_OUTPUT(
    uint8_t* data,
    secondary_message_PEDALS_OUTPUT* message
);
void secondary_deserialize_PEDALS_OUTPUT(
    secondary_message_PEDALS_OUTPUT* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
void secondary_raw_to_conversion_struct_PEDALS_OUTPUT(
    secondary_message_PEDALS_OUTPUT_conversion* conversion,
    secondary_message_PEDALS_OUTPUT* raw
);

void secondary_conversion_to_raw_struct_PEDALS_OUTPUT(
    secondary_message_PEDALS_OUTPUT* raw,
    secondary_message_PEDALS_OUTPUT_conversion* conversion
);

void secondary_conversion_to_raw_PEDALS_OUTPUT(
    secondary_message_PEDALS_OUTPUT* raw,
    secondary_uint8 apps,
    secondary_float32 bse_front,
    secondary_float32 bse_rear
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
);

void secondary_raw_to_conversion_PEDALS_OUTPUT(
    secondary_message_PEDALS_OUTPUT_conversion* conversion,
    secondary_uint8 apps,
    secondary_uint16 bse_front,
    secondary_uint16 bse_rear
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
);
int secondary_to_string_PEDALS_OUTPUT(secondary_message_PEDALS_OUTPUT_conversion* message, char* buffer);
int secondary_fields_PEDALS_OUTPUT(char* buffer);
int secondary_to_string_file_PEDALS_OUTPUT(secondary_message_PEDALS_OUTPUT_conversion* message, FILE* buffer);
int secondary_fields_file_PEDALS_OUTPUT(FILE* buffer);


// ============== CONTROL_OUTPUT ============== //

secondary_byte_size secondary_serialize_CONTROL_OUTPUT(
    uint8_t* data,
    secondary_uint16 estimated_velocity,
    secondary_uint8 tmax_r,
    secondary_uint8 tmax_l,
    secondary_uint16 torque_l,
    secondary_uint16 torque_r
);
secondary_byte_size secondary_serialize_struct_CONTROL_OUTPUT(
    uint8_t* data,
    secondary_message_CONTROL_OUTPUT* message
);
void secondary_deserialize_CONTROL_OUTPUT(
    secondary_message_CONTROL_OUTPUT* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
void secondary_raw_to_conversion_struct_CONTROL_OUTPUT(
    secondary_message_CONTROL_OUTPUT_conversion* conversion,
    secondary_message_CONTROL_OUTPUT* raw
);

void secondary_conversion_to_raw_struct_CONTROL_OUTPUT(
    secondary_message_CONTROL_OUTPUT* raw,
    secondary_message_CONTROL_OUTPUT_conversion* conversion
);

void secondary_conversion_to_raw_CONTROL_OUTPUT(
    secondary_message_CONTROL_OUTPUT* raw,
    secondary_float32 estimated_velocity,
    secondary_float32 tmax_r,
    secondary_float32 tmax_l,
    secondary_float32 torque_l,
    secondary_float32 torque_r
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
);

void secondary_raw_to_conversion_CONTROL_OUTPUT(
    secondary_message_CONTROL_OUTPUT_conversion* conversion,
    secondary_uint16 estimated_velocity,
    secondary_uint8 tmax_r,
    secondary_uint8 tmax_l,
    secondary_uint16 torque_l,
    secondary_uint16 torque_r
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
);
int secondary_to_string_CONTROL_OUTPUT(secondary_message_CONTROL_OUTPUT_conversion* message, char* buffer);
int secondary_fields_CONTROL_OUTPUT(char* buffer);
int secondary_to_string_file_CONTROL_OUTPUT(secondary_message_CONTROL_OUTPUT_conversion* message, FILE* buffer);
int secondary_fields_file_CONTROL_OUTPUT(FILE* buffer);


// ============== STEERING_ANGLE ============== //

secondary_byte_size secondary_serialize_STEERING_ANGLE(
    uint8_t* data,
    secondary_float32 angle
);
secondary_byte_size secondary_serialize_struct_STEERING_ANGLE(
    uint8_t* data,
    secondary_message_STEERING_ANGLE* message
);
void secondary_deserialize_STEERING_ANGLE(
    secondary_message_STEERING_ANGLE* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int secondary_to_string_STEERING_ANGLE(secondary_message_STEERING_ANGLE* message, char* buffer);
int secondary_fields_STEERING_ANGLE(char* buffer);
int secondary_to_string_file_STEERING_ANGLE(secondary_message_STEERING_ANGLE* message, FILE* buffer);
int secondary_fields_file_STEERING_ANGLE(FILE* buffer);


// ============== TPMS ============== //

secondary_byte_size secondary_serialize_TPMS(
    uint8_t* data,
    secondary_uint8 fl_pressure,
    secondary_uint8 fl_temperature,
    secondary_uint8 fr_pressure,
    secondary_uint8 fr_temperature,
    secondary_uint8 rl_pressure,
    secondary_uint8 rl_temperature,
    secondary_uint8 rr_pressure,
    secondary_uint8 rr_temperature
);
secondary_byte_size secondary_serialize_struct_TPMS(
    uint8_t* data,
    secondary_message_TPMS* message
);
void secondary_deserialize_TPMS(
    secondary_message_TPMS* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int secondary_to_string_TPMS(secondary_message_TPMS* message, char* buffer);
int secondary_fields_TPMS(char* buffer);
int secondary_to_string_file_TPMS(secondary_message_TPMS* message, FILE* buffer);
int secondary_fields_file_TPMS(FILE* buffer);



// ============== UTILS ============== //

static inline int secondary_index_from_id(canlib_message_id id) {
    switch (id) {
        case 1260: return secondary_INDEX_IMU_ANGULAR_RATE;
        case 1261: return secondary_INDEX_IMU_ACCELERATION;
        case 1460: return secondary_INDEX_IRTS_FL_0;
        case 1461: return secondary_INDEX_IRTS_FL_1;
        case 1462: return secondary_INDEX_IRTS_FL_2;
        case 1463: return secondary_INDEX_IRTS_FL_3;
        case 1464: return secondary_INDEX_IRTS_FR_0;
        case 1465: return secondary_INDEX_IRTS_FR_1;
        case 1466: return secondary_INDEX_IRTS_FR_2;
        case 1467: return secondary_INDEX_IRTS_FR_3;
        case 1468: return secondary_INDEX_IRTS_RL_0;
        case 1469: return secondary_INDEX_IRTS_RL_1;
        case 1470: return secondary_INDEX_IRTS_RL_2;
        case 1471: return secondary_INDEX_IRTS_RL_3;
        case 1472: return secondary_INDEX_IRTS_RR_0;
        case 1473: return secondary_INDEX_IRTS_RR_1;
        case 1474: return secondary_INDEX_IRTS_RR_2;
        case 1475: return secondary_INDEX_IRTS_RR_3;
        case 1025: return secondary_INDEX_GPS_COORDS;
        case 1057: return secondary_INDEX_GPS_SPEED;
        case 1089: return secondary_INDEX_LAP_COUNT;
        case 769: return secondary_INDEX_PEDALS_OUTPUT;
        case 801: return secondary_INDEX_CONTROL_OUTPUT;
        case 258: return secondary_INDEX_STEERING_ANGLE;
        case 1: return secondary_INDEX_TPMS;
    }
    return -1; // invalid
}

static inline int secondary_id_from_index(int index) {
    switch (index) {
        case secondary_INDEX_IMU_ANGULAR_RATE: return 1260;
        case secondary_INDEX_IMU_ACCELERATION: return 1261;
        case secondary_INDEX_IRTS_FL_0: return 1460;
        case secondary_INDEX_IRTS_FL_1: return 1461;
        case secondary_INDEX_IRTS_FL_2: return 1462;
        case secondary_INDEX_IRTS_FL_3: return 1463;
        case secondary_INDEX_IRTS_FR_0: return 1464;
        case secondary_INDEX_IRTS_FR_1: return 1465;
        case secondary_INDEX_IRTS_FR_2: return 1466;
        case secondary_INDEX_IRTS_FR_3: return 1467;
        case secondary_INDEX_IRTS_RL_0: return 1468;
        case secondary_INDEX_IRTS_RL_1: return 1469;
        case secondary_INDEX_IRTS_RL_2: return 1470;
        case secondary_INDEX_IRTS_RL_3: return 1471;
        case secondary_INDEX_IRTS_RR_0: return 1472;
        case secondary_INDEX_IRTS_RR_1: return 1473;
        case secondary_INDEX_IRTS_RR_2: return 1474;
        case secondary_INDEX_IRTS_RR_3: return 1475;
        case secondary_INDEX_GPS_COORDS: return 1025;
        case secondary_INDEX_GPS_SPEED: return 1057;
        case secondary_INDEX_LAP_COUNT: return 1089;
        case secondary_INDEX_PEDALS_OUTPUT: return 769;
        case secondary_INDEX_CONTROL_OUTPUT: return 801;
        case secondary_INDEX_STEERING_ANGLE: return 258;
        case secondary_INDEX_TPMS: return 1;
    }
    return -1; // invalid
}

int secondary_fields_from_id(canlib_message_id message_id, char *buffer);
int secondary_to_string_from_id(canlib_message_id message_id, void* message, char *buffer);
int secondary_fields_file_from_id(canlib_message_id message_id, FILE *buffer);
int secondary_to_string_file_from_id(canlib_message_id message_id, void* message, FILE *buffer);
void* secondary_deserialize_from_id(
    canlib_message_id message_id,
    uint8_t* data,
    void* message_raw,
    void* message_conversion
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
secondary_devices* secondary_devices_new();
void secondary_devices_free(secondary_devices* devices);
void secondary_devices_deserialize_from_id(
    secondary_devices* devices,
    canlib_message_id message_id,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);

#ifdef secondary_NETWORK_IMPLEMENTATION




// ============== SERIALIZE ============== //

secondary_byte_size secondary_serialize_IMU_ANGULAR_RATE(
    uint8_t* data,
    secondary_int16 ang_rate_x,
    secondary_int16 ang_rate_y,
    secondary_int16 ang_rate_z
) {
    data[0] = (ang_rate_x >> 8) & 255;
    data[1] = ang_rate_x & 255;
    data[2] = (ang_rate_y >> 8) & 255;
    data[3] = ang_rate_y & 255;
    data[4] = (ang_rate_z >> 8) & 255;
    data[5] = ang_rate_z & 255;
    return 6;
}

secondary_byte_size secondary_serialize_struct_IMU_ANGULAR_RATE(
    uint8_t* data,
    secondary_message_IMU_ANGULAR_RATE* message
) {
    data[0] = (message->ang_rate_x >> 8) & 255;
    data[1] = message->ang_rate_x & 255;
    data[2] = (message->ang_rate_y >> 8) & 255;
    data[3] = message->ang_rate_y & 255;
    data[4] = (message->ang_rate_z >> 8) & 255;
    data[5] = message->ang_rate_z & 255;
    return 6;
}

// ============== DESERIALIZE ============== //

void secondary_deserialize_IMU_ANGULAR_RATE(
    secondary_message_IMU_ANGULAR_RATE* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->ang_rate_x = data[1] | (data[0] << 8);
    message->ang_rate_y = data[3] | (data[2] << 8);
    message->ang_rate_z = data[5] | (data[4] << 8);
}// ============== CONVERSION ============== //

void secondary_raw_to_conversion_IMU_ANGULAR_RATE(
    secondary_message_IMU_ANGULAR_RATE_conversion* conversion,
    secondary_int16 ang_rate_x,
    secondary_int16 ang_rate_y,
    secondary_int16 ang_rate_z
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
){
#ifdef CANLIB_TIMESTAMP
    conversion->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    conversion->ang_rate_x = (((secondary_float32)ang_rate_x) / 10.0) + 0;
    conversion->ang_rate_y = (((secondary_float32)ang_rate_y) / 10.0) + 0;
    conversion->ang_rate_z = (((secondary_float32)ang_rate_z) / 10.0) + 0;
}

void secondary_raw_to_conversion_struct_IMU_ANGULAR_RATE(
    secondary_message_IMU_ANGULAR_RATE_conversion* conversion,
    secondary_message_IMU_ANGULAR_RATE* raw
){
#ifdef CANLIB_TIMESTAMP
    conversion->_timestamp = raw->_timestamp;
#endif // CANLIB_TIMESTAMP
    conversion->ang_rate_x = (((secondary_float32)raw->ang_rate_x) / 10.0) + 0;
    conversion->ang_rate_y = (((secondary_float32)raw->ang_rate_y) / 10.0) + 0;
    conversion->ang_rate_z = (((secondary_float32)raw->ang_rate_z) / 10.0) + 0;
}

void secondary_conversion_to_raw_IMU_ANGULAR_RATE(
    secondary_message_IMU_ANGULAR_RATE* raw,
    secondary_float32 ang_rate_x,
    secondary_float32 ang_rate_y,
    secondary_float32 ang_rate_z
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
){
#ifdef CANLIB_TIMESTAMP
    raw->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    raw->ang_rate_x = (secondary_int16)((ang_rate_x + 0) * 10.0);
    raw->ang_rate_y = (secondary_int16)((ang_rate_y + 0) * 10.0);
    raw->ang_rate_z = (secondary_int16)((ang_rate_z + 0) * 10.0);
}

void secondary_conversion_to_raw_struct_IMU_ANGULAR_RATE(
    secondary_message_IMU_ANGULAR_RATE* raw,
    secondary_message_IMU_ANGULAR_RATE_conversion* conversion
){
#ifdef CANLIB_TIMESTAMP
    raw->_timestamp = conversion->_timestamp;
#endif // CANLIB_TIMESTAMP
    raw->ang_rate_x = (secondary_int16)((conversion->ang_rate_x + 0) * 10.0);
    raw->ang_rate_y = (secondary_int16)((conversion->ang_rate_y + 0) * 10.0);
    raw->ang_rate_z = (secondary_int16)((conversion->ang_rate_z + 0) * 10.0);
}

// ============== STRING ============== //
int secondary_to_string_IMU_ANGULAR_RATE(secondary_message_IMU_ANGULAR_RATE_conversion* message, char* buffer) {
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
        message->ang_rate_x,
        message->ang_rate_y,
        message->ang_rate_z
    );
}

int secondary_fields_IMU_ANGULAR_RATE(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "ang_rate_x" CANLIB_SEPARATOR 
        "ang_rate_y" CANLIB_SEPARATOR 
        "ang_rate_z"
    );
}

int secondary_to_string_file_IMU_ANGULAR_RATE(secondary_message_IMU_ANGULAR_RATE_conversion* message, FILE* buffer) {
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
        message->ang_rate_x,
        message->ang_rate_y,
        message->ang_rate_z
    );
}

int secondary_fields_file_IMU_ANGULAR_RATE(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "ang_rate_x" CANLIB_SEPARATOR 
        "ang_rate_y" CANLIB_SEPARATOR 
        "ang_rate_z"
    );
}

// ============== SERIALIZE ============== //

secondary_byte_size secondary_serialize_IMU_ACCELERATION(
    uint8_t* data,
    secondary_int16 accel_x,
    secondary_int16 accel_y,
    secondary_int16 accel_z,
    secondary_int16 temperature
) {
    data[0] = (accel_x >> 8) & 255;
    data[1] = accel_x & 255;
    data[2] = (accel_y >> 8) & 255;
    data[3] = accel_y & 255;
    data[4] = (accel_z >> 8) & 255;
    data[5] = accel_z & 255;
    data[6] = (temperature >> 8) & 255;
    data[7] = temperature & 255;
    return 8;
}

secondary_byte_size secondary_serialize_struct_IMU_ACCELERATION(
    uint8_t* data,
    secondary_message_IMU_ACCELERATION* message
) {
    data[0] = (message->accel_x >> 8) & 255;
    data[1] = message->accel_x & 255;
    data[2] = (message->accel_y >> 8) & 255;
    data[3] = message->accel_y & 255;
    data[4] = (message->accel_z >> 8) & 255;
    data[5] = message->accel_z & 255;
    data[6] = (message->temperature >> 8) & 255;
    data[7] = message->temperature & 255;
    return 8;
}

// ============== DESERIALIZE ============== //

void secondary_deserialize_IMU_ACCELERATION(
    secondary_message_IMU_ACCELERATION* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->accel_x = data[1] | (data[0] << 8);
    message->accel_y = data[3] | (data[2] << 8);
    message->accel_z = data[5] | (data[4] << 8);
    message->temperature = data[7] | (data[6] << 8);
}// ============== CONVERSION ============== //

void secondary_raw_to_conversion_IMU_ACCELERATION(
    secondary_message_IMU_ACCELERATION_conversion* conversion,
    secondary_int16 accel_x,
    secondary_int16 accel_y,
    secondary_int16 accel_z,
    secondary_int16 temperature
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
){
#ifdef CANLIB_TIMESTAMP
    conversion->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    conversion->accel_x = (((secondary_float32)accel_x) / 100.0) + 0;
    conversion->accel_y = (((secondary_float32)accel_y) / 100.0) + 0;
    conversion->accel_z = (((secondary_float32)accel_z) / 100.0) + 0;
    conversion->temperature = temperature;
}

void secondary_raw_to_conversion_struct_IMU_ACCELERATION(
    secondary_message_IMU_ACCELERATION_conversion* conversion,
    secondary_message_IMU_ACCELERATION* raw
){
#ifdef CANLIB_TIMESTAMP
    conversion->_timestamp = raw->_timestamp;
#endif // CANLIB_TIMESTAMP
    conversion->accel_x = (((secondary_float32)raw->accel_x) / 100.0) + 0;
    conversion->accel_y = (((secondary_float32)raw->accel_y) / 100.0) + 0;
    conversion->accel_z = (((secondary_float32)raw->accel_z) / 100.0) + 0;
    conversion->temperature = raw->temperature;
}

void secondary_conversion_to_raw_IMU_ACCELERATION(
    secondary_message_IMU_ACCELERATION* raw,
    secondary_float32 accel_x,
    secondary_float32 accel_y,
    secondary_float32 accel_z,
    secondary_int16 temperature
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
){
#ifdef CANLIB_TIMESTAMP
    raw->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    raw->accel_x = (secondary_int16)((accel_x + 0) * 100.0);
    raw->accel_y = (secondary_int16)((accel_y + 0) * 100.0);
    raw->accel_z = (secondary_int16)((accel_z + 0) * 100.0);
    raw->temperature = temperature;
}

void secondary_conversion_to_raw_struct_IMU_ACCELERATION(
    secondary_message_IMU_ACCELERATION* raw,
    secondary_message_IMU_ACCELERATION_conversion* conversion
){
#ifdef CANLIB_TIMESTAMP
    raw->_timestamp = conversion->_timestamp;
#endif // CANLIB_TIMESTAMP
    raw->accel_x = (secondary_int16)((conversion->accel_x + 0) * 100.0);
    raw->accel_y = (secondary_int16)((conversion->accel_y + 0) * 100.0);
    raw->accel_z = (secondary_int16)((conversion->accel_z + 0) * 100.0);
    raw->temperature = conversion->temperature;
}

// ============== STRING ============== //
int secondary_to_string_IMU_ACCELERATION(secondary_message_IMU_ACCELERATION_conversion* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIi16,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->accel_x,
        message->accel_y,
        message->accel_z,
        message->temperature
    );
}

int secondary_fields_IMU_ACCELERATION(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "accel_x" CANLIB_SEPARATOR 
        "accel_y" CANLIB_SEPARATOR 
        "accel_z" CANLIB_SEPARATOR 
        "temperature"
    );
}

int secondary_to_string_file_IMU_ACCELERATION(secondary_message_IMU_ACCELERATION_conversion* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIi16,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->accel_x,
        message->accel_y,
        message->accel_z,
        message->temperature
    );
}

int secondary_fields_file_IMU_ACCELERATION(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "accel_x" CANLIB_SEPARATOR 
        "accel_y" CANLIB_SEPARATOR 
        "accel_z" CANLIB_SEPARATOR 
        "temperature"
    );
}

// ============== SERIALIZE ============== //

secondary_byte_size secondary_serialize_IRTS_FL_0(
    uint8_t* data,
    secondary_uint16 channel1,
    secondary_uint16 channel2,
    secondary_uint16 channel3,
    secondary_uint16 channel4
) {
    data[0] = channel1 & 255;
    data[1] = (channel1 >> 8) & 255;
    data[2] = channel2 & 255;
    data[3] = (channel2 >> 8) & 255;
    data[4] = channel3 & 255;
    data[5] = (channel3 >> 8) & 255;
    data[6] = channel4 & 255;
    data[7] = (channel4 >> 8) & 255;
    return 8;
}

secondary_byte_size secondary_serialize_struct_IRTS_FL_0(
    uint8_t* data,
    secondary_message_IRTS_FL_0* message
) {
    data[0] = message->channel1 & 255;
    data[1] = (message->channel1 >> 8) & 255;
    data[2] = message->channel2 & 255;
    data[3] = (message->channel2 >> 8) & 255;
    data[4] = message->channel3 & 255;
    data[5] = (message->channel3 >> 8) & 255;
    data[6] = message->channel4 & 255;
    data[7] = (message->channel4 >> 8) & 255;
    return 8;
}

// ============== DESERIALIZE ============== //

void secondary_deserialize_IRTS_FL_0(
    secondary_message_IRTS_FL_0* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->channel1 = data[0] | (data[1] << 8);
    message->channel2 = data[2] | (data[3] << 8);
    message->channel3 = data[4] | (data[5] << 8);
    message->channel4 = data[6] | (data[7] << 8);
}

// ============== STRING ============== //

int secondary_to_string_IRTS_FL_0(secondary_message_IRTS_FL_0* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->channel1,
        message->channel2,
        message->channel3,
        message->channel4
    );
}

int secondary_fields_IRTS_FL_0(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "channel1" CANLIB_SEPARATOR 
        "channel2" CANLIB_SEPARATOR 
        "channel3" CANLIB_SEPARATOR 
        "channel4"
    );
}

int secondary_to_string_file_IRTS_FL_0(secondary_message_IRTS_FL_0* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->channel1,
        message->channel2,
        message->channel3,
        message->channel4
    );
}

int secondary_fields_file_IRTS_FL_0(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "channel1" CANLIB_SEPARATOR 
        "channel2" CANLIB_SEPARATOR 
        "channel3" CANLIB_SEPARATOR 
        "channel4"
    );
}

// ============== SERIALIZE ============== //

secondary_byte_size secondary_serialize_IRTS_FL_1(
    uint8_t* data,
    secondary_uint16 channel5,
    secondary_uint16 channel6,
    secondary_uint16 channel7,
    secondary_uint16 channel8
) {
    data[0] = channel5 & 255;
    data[1] = (channel5 >> 8) & 255;
    data[2] = channel6 & 255;
    data[3] = (channel6 >> 8) & 255;
    data[4] = channel7 & 255;
    data[5] = (channel7 >> 8) & 255;
    data[6] = channel8 & 255;
    data[7] = (channel8 >> 8) & 255;
    return 8;
}

secondary_byte_size secondary_serialize_struct_IRTS_FL_1(
    uint8_t* data,
    secondary_message_IRTS_FL_1* message
) {
    data[0] = message->channel5 & 255;
    data[1] = (message->channel5 >> 8) & 255;
    data[2] = message->channel6 & 255;
    data[3] = (message->channel6 >> 8) & 255;
    data[4] = message->channel7 & 255;
    data[5] = (message->channel7 >> 8) & 255;
    data[6] = message->channel8 & 255;
    data[7] = (message->channel8 >> 8) & 255;
    return 8;
}

// ============== DESERIALIZE ============== //

void secondary_deserialize_IRTS_FL_1(
    secondary_message_IRTS_FL_1* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->channel5 = data[0] | (data[1] << 8);
    message->channel6 = data[2] | (data[3] << 8);
    message->channel7 = data[4] | (data[5] << 8);
    message->channel8 = data[6] | (data[7] << 8);
}

// ============== STRING ============== //

int secondary_to_string_IRTS_FL_1(secondary_message_IRTS_FL_1* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->channel5,
        message->channel6,
        message->channel7,
        message->channel8
    );
}

int secondary_fields_IRTS_FL_1(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "channel5" CANLIB_SEPARATOR 
        "channel6" CANLIB_SEPARATOR 
        "channel7" CANLIB_SEPARATOR 
        "channel8"
    );
}

int secondary_to_string_file_IRTS_FL_1(secondary_message_IRTS_FL_1* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->channel5,
        message->channel6,
        message->channel7,
        message->channel8
    );
}

int secondary_fields_file_IRTS_FL_1(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "channel5" CANLIB_SEPARATOR 
        "channel6" CANLIB_SEPARATOR 
        "channel7" CANLIB_SEPARATOR 
        "channel8"
    );
}

// ============== SERIALIZE ============== //

secondary_byte_size secondary_serialize_IRTS_FL_2(
    uint8_t* data,
    secondary_uint16 channel9,
    secondary_uint16 channel10,
    secondary_uint16 channel11,
    secondary_uint16 channel12
) {
    data[0] = channel9 & 255;
    data[1] = (channel9 >> 8) & 255;
    data[2] = channel10 & 255;
    data[3] = (channel10 >> 8) & 255;
    data[4] = channel11 & 255;
    data[5] = (channel11 >> 8) & 255;
    data[6] = channel12 & 255;
    data[7] = (channel12 >> 8) & 255;
    return 8;
}

secondary_byte_size secondary_serialize_struct_IRTS_FL_2(
    uint8_t* data,
    secondary_message_IRTS_FL_2* message
) {
    data[0] = message->channel9 & 255;
    data[1] = (message->channel9 >> 8) & 255;
    data[2] = message->channel10 & 255;
    data[3] = (message->channel10 >> 8) & 255;
    data[4] = message->channel11 & 255;
    data[5] = (message->channel11 >> 8) & 255;
    data[6] = message->channel12 & 255;
    data[7] = (message->channel12 >> 8) & 255;
    return 8;
}

// ============== DESERIALIZE ============== //

void secondary_deserialize_IRTS_FL_2(
    secondary_message_IRTS_FL_2* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->channel9 = data[0] | (data[1] << 8);
    message->channel10 = data[2] | (data[3] << 8);
    message->channel11 = data[4] | (data[5] << 8);
    message->channel12 = data[6] | (data[7] << 8);
}

// ============== STRING ============== //

int secondary_to_string_IRTS_FL_2(secondary_message_IRTS_FL_2* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->channel9,
        message->channel10,
        message->channel11,
        message->channel12
    );
}

int secondary_fields_IRTS_FL_2(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "channel9" CANLIB_SEPARATOR 
        "channel10" CANLIB_SEPARATOR 
        "channel11" CANLIB_SEPARATOR 
        "channel12"
    );
}

int secondary_to_string_file_IRTS_FL_2(secondary_message_IRTS_FL_2* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->channel9,
        message->channel10,
        message->channel11,
        message->channel12
    );
}

int secondary_fields_file_IRTS_FL_2(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "channel9" CANLIB_SEPARATOR 
        "channel10" CANLIB_SEPARATOR 
        "channel11" CANLIB_SEPARATOR 
        "channel12"
    );
}

// ============== SERIALIZE ============== //

secondary_byte_size secondary_serialize_IRTS_FL_3(
    uint8_t* data,
    secondary_uint16 channel13,
    secondary_uint16 channel14,
    secondary_uint16 channel15,
    secondary_uint16 channel16
) {
    data[0] = channel13 & 255;
    data[1] = (channel13 >> 8) & 255;
    data[2] = channel14 & 255;
    data[3] = (channel14 >> 8) & 255;
    data[4] = channel15 & 255;
    data[5] = (channel15 >> 8) & 255;
    data[6] = channel16 & 255;
    data[7] = (channel16 >> 8) & 255;
    return 8;
}

secondary_byte_size secondary_serialize_struct_IRTS_FL_3(
    uint8_t* data,
    secondary_message_IRTS_FL_3* message
) {
    data[0] = message->channel13 & 255;
    data[1] = (message->channel13 >> 8) & 255;
    data[2] = message->channel14 & 255;
    data[3] = (message->channel14 >> 8) & 255;
    data[4] = message->channel15 & 255;
    data[5] = (message->channel15 >> 8) & 255;
    data[6] = message->channel16 & 255;
    data[7] = (message->channel16 >> 8) & 255;
    return 8;
}

// ============== DESERIALIZE ============== //

void secondary_deserialize_IRTS_FL_3(
    secondary_message_IRTS_FL_3* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->channel13 = data[0] | (data[1] << 8);
    message->channel14 = data[2] | (data[3] << 8);
    message->channel15 = data[4] | (data[5] << 8);
    message->channel16 = data[6] | (data[7] << 8);
}

// ============== STRING ============== //

int secondary_to_string_IRTS_FL_3(secondary_message_IRTS_FL_3* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->channel13,
        message->channel14,
        message->channel15,
        message->channel16
    );
}

int secondary_fields_IRTS_FL_3(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "channel13" CANLIB_SEPARATOR 
        "channel14" CANLIB_SEPARATOR 
        "channel15" CANLIB_SEPARATOR 
        "channel16"
    );
}

int secondary_to_string_file_IRTS_FL_3(secondary_message_IRTS_FL_3* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->channel13,
        message->channel14,
        message->channel15,
        message->channel16
    );
}

int secondary_fields_file_IRTS_FL_3(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "channel13" CANLIB_SEPARATOR 
        "channel14" CANLIB_SEPARATOR 
        "channel15" CANLIB_SEPARATOR 
        "channel16"
    );
}

// ============== SERIALIZE ============== //

secondary_byte_size secondary_serialize_IRTS_FR_0(
    uint8_t* data,
    secondary_uint16 channel1,
    secondary_uint16 channel2,
    secondary_uint16 channel3,
    secondary_uint16 channel4
) {
    data[0] = channel1 & 255;
    data[1] = (channel1 >> 8) & 255;
    data[2] = channel2 & 255;
    data[3] = (channel2 >> 8) & 255;
    data[4] = channel3 & 255;
    data[5] = (channel3 >> 8) & 255;
    data[6] = channel4 & 255;
    data[7] = (channel4 >> 8) & 255;
    return 8;
}

secondary_byte_size secondary_serialize_struct_IRTS_FR_0(
    uint8_t* data,
    secondary_message_IRTS_FR_0* message
) {
    data[0] = message->channel1 & 255;
    data[1] = (message->channel1 >> 8) & 255;
    data[2] = message->channel2 & 255;
    data[3] = (message->channel2 >> 8) & 255;
    data[4] = message->channel3 & 255;
    data[5] = (message->channel3 >> 8) & 255;
    data[6] = message->channel4 & 255;
    data[7] = (message->channel4 >> 8) & 255;
    return 8;
}

// ============== DESERIALIZE ============== //

void secondary_deserialize_IRTS_FR_0(
    secondary_message_IRTS_FR_0* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->channel1 = data[0] | (data[1] << 8);
    message->channel2 = data[2] | (data[3] << 8);
    message->channel3 = data[4] | (data[5] << 8);
    message->channel4 = data[6] | (data[7] << 8);
}

// ============== STRING ============== //

int secondary_to_string_IRTS_FR_0(secondary_message_IRTS_FR_0* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->channel1,
        message->channel2,
        message->channel3,
        message->channel4
    );
}

int secondary_fields_IRTS_FR_0(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "channel1" CANLIB_SEPARATOR 
        "channel2" CANLIB_SEPARATOR 
        "channel3" CANLIB_SEPARATOR 
        "channel4"
    );
}

int secondary_to_string_file_IRTS_FR_0(secondary_message_IRTS_FR_0* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->channel1,
        message->channel2,
        message->channel3,
        message->channel4
    );
}

int secondary_fields_file_IRTS_FR_0(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "channel1" CANLIB_SEPARATOR 
        "channel2" CANLIB_SEPARATOR 
        "channel3" CANLIB_SEPARATOR 
        "channel4"
    );
}

// ============== SERIALIZE ============== //

secondary_byte_size secondary_serialize_IRTS_FR_1(
    uint8_t* data,
    secondary_uint16 channel5,
    secondary_uint16 channel6,
    secondary_uint16 channel7,
    secondary_uint16 channel8
) {
    data[0] = channel5 & 255;
    data[1] = (channel5 >> 8) & 255;
    data[2] = channel6 & 255;
    data[3] = (channel6 >> 8) & 255;
    data[4] = channel7 & 255;
    data[5] = (channel7 >> 8) & 255;
    data[6] = channel8 & 255;
    data[7] = (channel8 >> 8) & 255;
    return 8;
}

secondary_byte_size secondary_serialize_struct_IRTS_FR_1(
    uint8_t* data,
    secondary_message_IRTS_FR_1* message
) {
    data[0] = message->channel5 & 255;
    data[1] = (message->channel5 >> 8) & 255;
    data[2] = message->channel6 & 255;
    data[3] = (message->channel6 >> 8) & 255;
    data[4] = message->channel7 & 255;
    data[5] = (message->channel7 >> 8) & 255;
    data[6] = message->channel8 & 255;
    data[7] = (message->channel8 >> 8) & 255;
    return 8;
}

// ============== DESERIALIZE ============== //

void secondary_deserialize_IRTS_FR_1(
    secondary_message_IRTS_FR_1* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->channel5 = data[0] | (data[1] << 8);
    message->channel6 = data[2] | (data[3] << 8);
    message->channel7 = data[4] | (data[5] << 8);
    message->channel8 = data[6] | (data[7] << 8);
}

// ============== STRING ============== //

int secondary_to_string_IRTS_FR_1(secondary_message_IRTS_FR_1* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->channel5,
        message->channel6,
        message->channel7,
        message->channel8
    );
}

int secondary_fields_IRTS_FR_1(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "channel5" CANLIB_SEPARATOR 
        "channel6" CANLIB_SEPARATOR 
        "channel7" CANLIB_SEPARATOR 
        "channel8"
    );
}

int secondary_to_string_file_IRTS_FR_1(secondary_message_IRTS_FR_1* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->channel5,
        message->channel6,
        message->channel7,
        message->channel8
    );
}

int secondary_fields_file_IRTS_FR_1(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "channel5" CANLIB_SEPARATOR 
        "channel6" CANLIB_SEPARATOR 
        "channel7" CANLIB_SEPARATOR 
        "channel8"
    );
}

// ============== SERIALIZE ============== //

secondary_byte_size secondary_serialize_IRTS_FR_2(
    uint8_t* data,
    secondary_uint16 channel9,
    secondary_uint16 channel10,
    secondary_uint16 channel11,
    secondary_uint16 channel12
) {
    data[0] = channel9 & 255;
    data[1] = (channel9 >> 8) & 255;
    data[2] = channel10 & 255;
    data[3] = (channel10 >> 8) & 255;
    data[4] = channel11 & 255;
    data[5] = (channel11 >> 8) & 255;
    data[6] = channel12 & 255;
    data[7] = (channel12 >> 8) & 255;
    return 8;
}

secondary_byte_size secondary_serialize_struct_IRTS_FR_2(
    uint8_t* data,
    secondary_message_IRTS_FR_2* message
) {
    data[0] = message->channel9 & 255;
    data[1] = (message->channel9 >> 8) & 255;
    data[2] = message->channel10 & 255;
    data[3] = (message->channel10 >> 8) & 255;
    data[4] = message->channel11 & 255;
    data[5] = (message->channel11 >> 8) & 255;
    data[6] = message->channel12 & 255;
    data[7] = (message->channel12 >> 8) & 255;
    return 8;
}

// ============== DESERIALIZE ============== //

void secondary_deserialize_IRTS_FR_2(
    secondary_message_IRTS_FR_2* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->channel9 = data[0] | (data[1] << 8);
    message->channel10 = data[2] | (data[3] << 8);
    message->channel11 = data[4] | (data[5] << 8);
    message->channel12 = data[6] | (data[7] << 8);
}

// ============== STRING ============== //

int secondary_to_string_IRTS_FR_2(secondary_message_IRTS_FR_2* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->channel9,
        message->channel10,
        message->channel11,
        message->channel12
    );
}

int secondary_fields_IRTS_FR_2(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "channel9" CANLIB_SEPARATOR 
        "channel10" CANLIB_SEPARATOR 
        "channel11" CANLIB_SEPARATOR 
        "channel12"
    );
}

int secondary_to_string_file_IRTS_FR_2(secondary_message_IRTS_FR_2* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->channel9,
        message->channel10,
        message->channel11,
        message->channel12
    );
}

int secondary_fields_file_IRTS_FR_2(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "channel9" CANLIB_SEPARATOR 
        "channel10" CANLIB_SEPARATOR 
        "channel11" CANLIB_SEPARATOR 
        "channel12"
    );
}

// ============== SERIALIZE ============== //

secondary_byte_size secondary_serialize_IRTS_FR_3(
    uint8_t* data,
    secondary_uint16 channel13,
    secondary_uint16 channel14,
    secondary_uint16 channel15,
    secondary_uint16 channel16
) {
    data[0] = channel13 & 255;
    data[1] = (channel13 >> 8) & 255;
    data[2] = channel14 & 255;
    data[3] = (channel14 >> 8) & 255;
    data[4] = channel15 & 255;
    data[5] = (channel15 >> 8) & 255;
    data[6] = channel16 & 255;
    data[7] = (channel16 >> 8) & 255;
    return 8;
}

secondary_byte_size secondary_serialize_struct_IRTS_FR_3(
    uint8_t* data,
    secondary_message_IRTS_FR_3* message
) {
    data[0] = message->channel13 & 255;
    data[1] = (message->channel13 >> 8) & 255;
    data[2] = message->channel14 & 255;
    data[3] = (message->channel14 >> 8) & 255;
    data[4] = message->channel15 & 255;
    data[5] = (message->channel15 >> 8) & 255;
    data[6] = message->channel16 & 255;
    data[7] = (message->channel16 >> 8) & 255;
    return 8;
}

// ============== DESERIALIZE ============== //

void secondary_deserialize_IRTS_FR_3(
    secondary_message_IRTS_FR_3* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->channel13 = data[0] | (data[1] << 8);
    message->channel14 = data[2] | (data[3] << 8);
    message->channel15 = data[4] | (data[5] << 8);
    message->channel16 = data[6] | (data[7] << 8);
}

// ============== STRING ============== //

int secondary_to_string_IRTS_FR_3(secondary_message_IRTS_FR_3* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->channel13,
        message->channel14,
        message->channel15,
        message->channel16
    );
}

int secondary_fields_IRTS_FR_3(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "channel13" CANLIB_SEPARATOR 
        "channel14" CANLIB_SEPARATOR 
        "channel15" CANLIB_SEPARATOR 
        "channel16"
    );
}

int secondary_to_string_file_IRTS_FR_3(secondary_message_IRTS_FR_3* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->channel13,
        message->channel14,
        message->channel15,
        message->channel16
    );
}

int secondary_fields_file_IRTS_FR_3(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "channel13" CANLIB_SEPARATOR 
        "channel14" CANLIB_SEPARATOR 
        "channel15" CANLIB_SEPARATOR 
        "channel16"
    );
}

// ============== SERIALIZE ============== //

secondary_byte_size secondary_serialize_IRTS_RL_0(
    uint8_t* data,
    secondary_uint16 channel1,
    secondary_uint16 channel2,
    secondary_uint16 channel3,
    secondary_uint16 channel4
) {
    data[0] = channel1 & 255;
    data[1] = (channel1 >> 8) & 255;
    data[2] = channel2 & 255;
    data[3] = (channel2 >> 8) & 255;
    data[4] = channel3 & 255;
    data[5] = (channel3 >> 8) & 255;
    data[6] = channel4 & 255;
    data[7] = (channel4 >> 8) & 255;
    return 8;
}

secondary_byte_size secondary_serialize_struct_IRTS_RL_0(
    uint8_t* data,
    secondary_message_IRTS_RL_0* message
) {
    data[0] = message->channel1 & 255;
    data[1] = (message->channel1 >> 8) & 255;
    data[2] = message->channel2 & 255;
    data[3] = (message->channel2 >> 8) & 255;
    data[4] = message->channel3 & 255;
    data[5] = (message->channel3 >> 8) & 255;
    data[6] = message->channel4 & 255;
    data[7] = (message->channel4 >> 8) & 255;
    return 8;
}

// ============== DESERIALIZE ============== //

void secondary_deserialize_IRTS_RL_0(
    secondary_message_IRTS_RL_0* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->channel1 = data[0] | (data[1] << 8);
    message->channel2 = data[2] | (data[3] << 8);
    message->channel3 = data[4] | (data[5] << 8);
    message->channel4 = data[6] | (data[7] << 8);
}

// ============== STRING ============== //

int secondary_to_string_IRTS_RL_0(secondary_message_IRTS_RL_0* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->channel1,
        message->channel2,
        message->channel3,
        message->channel4
    );
}

int secondary_fields_IRTS_RL_0(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "channel1" CANLIB_SEPARATOR 
        "channel2" CANLIB_SEPARATOR 
        "channel3" CANLIB_SEPARATOR 
        "channel4"
    );
}

int secondary_to_string_file_IRTS_RL_0(secondary_message_IRTS_RL_0* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->channel1,
        message->channel2,
        message->channel3,
        message->channel4
    );
}

int secondary_fields_file_IRTS_RL_0(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "channel1" CANLIB_SEPARATOR 
        "channel2" CANLIB_SEPARATOR 
        "channel3" CANLIB_SEPARATOR 
        "channel4"
    );
}

// ============== SERIALIZE ============== //

secondary_byte_size secondary_serialize_IRTS_RL_1(
    uint8_t* data,
    secondary_uint16 channel5,
    secondary_uint16 channel6,
    secondary_uint16 channel7,
    secondary_uint16 channel8
) {
    data[0] = channel5 & 255;
    data[1] = (channel5 >> 8) & 255;
    data[2] = channel6 & 255;
    data[3] = (channel6 >> 8) & 255;
    data[4] = channel7 & 255;
    data[5] = (channel7 >> 8) & 255;
    data[6] = channel8 & 255;
    data[7] = (channel8 >> 8) & 255;
    return 8;
}

secondary_byte_size secondary_serialize_struct_IRTS_RL_1(
    uint8_t* data,
    secondary_message_IRTS_RL_1* message
) {
    data[0] = message->channel5 & 255;
    data[1] = (message->channel5 >> 8) & 255;
    data[2] = message->channel6 & 255;
    data[3] = (message->channel6 >> 8) & 255;
    data[4] = message->channel7 & 255;
    data[5] = (message->channel7 >> 8) & 255;
    data[6] = message->channel8 & 255;
    data[7] = (message->channel8 >> 8) & 255;
    return 8;
}

// ============== DESERIALIZE ============== //

void secondary_deserialize_IRTS_RL_1(
    secondary_message_IRTS_RL_1* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->channel5 = data[0] | (data[1] << 8);
    message->channel6 = data[2] | (data[3] << 8);
    message->channel7 = data[4] | (data[5] << 8);
    message->channel8 = data[6] | (data[7] << 8);
}

// ============== STRING ============== //

int secondary_to_string_IRTS_RL_1(secondary_message_IRTS_RL_1* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->channel5,
        message->channel6,
        message->channel7,
        message->channel8
    );
}

int secondary_fields_IRTS_RL_1(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "channel5" CANLIB_SEPARATOR 
        "channel6" CANLIB_SEPARATOR 
        "channel7" CANLIB_SEPARATOR 
        "channel8"
    );
}

int secondary_to_string_file_IRTS_RL_1(secondary_message_IRTS_RL_1* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->channel5,
        message->channel6,
        message->channel7,
        message->channel8
    );
}

int secondary_fields_file_IRTS_RL_1(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "channel5" CANLIB_SEPARATOR 
        "channel6" CANLIB_SEPARATOR 
        "channel7" CANLIB_SEPARATOR 
        "channel8"
    );
}

// ============== SERIALIZE ============== //

secondary_byte_size secondary_serialize_IRTS_RL_2(
    uint8_t* data,
    secondary_uint16 channel9,
    secondary_uint16 channel10,
    secondary_uint16 channel11,
    secondary_uint16 channel12
) {
    data[0] = channel9 & 255;
    data[1] = (channel9 >> 8) & 255;
    data[2] = channel10 & 255;
    data[3] = (channel10 >> 8) & 255;
    data[4] = channel11 & 255;
    data[5] = (channel11 >> 8) & 255;
    data[6] = channel12 & 255;
    data[7] = (channel12 >> 8) & 255;
    return 8;
}

secondary_byte_size secondary_serialize_struct_IRTS_RL_2(
    uint8_t* data,
    secondary_message_IRTS_RL_2* message
) {
    data[0] = message->channel9 & 255;
    data[1] = (message->channel9 >> 8) & 255;
    data[2] = message->channel10 & 255;
    data[3] = (message->channel10 >> 8) & 255;
    data[4] = message->channel11 & 255;
    data[5] = (message->channel11 >> 8) & 255;
    data[6] = message->channel12 & 255;
    data[7] = (message->channel12 >> 8) & 255;
    return 8;
}

// ============== DESERIALIZE ============== //

void secondary_deserialize_IRTS_RL_2(
    secondary_message_IRTS_RL_2* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->channel9 = data[0] | (data[1] << 8);
    message->channel10 = data[2] | (data[3] << 8);
    message->channel11 = data[4] | (data[5] << 8);
    message->channel12 = data[6] | (data[7] << 8);
}

// ============== STRING ============== //

int secondary_to_string_IRTS_RL_2(secondary_message_IRTS_RL_2* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->channel9,
        message->channel10,
        message->channel11,
        message->channel12
    );
}

int secondary_fields_IRTS_RL_2(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "channel9" CANLIB_SEPARATOR 
        "channel10" CANLIB_SEPARATOR 
        "channel11" CANLIB_SEPARATOR 
        "channel12"
    );
}

int secondary_to_string_file_IRTS_RL_2(secondary_message_IRTS_RL_2* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->channel9,
        message->channel10,
        message->channel11,
        message->channel12
    );
}

int secondary_fields_file_IRTS_RL_2(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "channel9" CANLIB_SEPARATOR 
        "channel10" CANLIB_SEPARATOR 
        "channel11" CANLIB_SEPARATOR 
        "channel12"
    );
}

// ============== SERIALIZE ============== //

secondary_byte_size secondary_serialize_IRTS_RL_3(
    uint8_t* data,
    secondary_uint16 channel13,
    secondary_uint16 channel14,
    secondary_uint16 channel15,
    secondary_uint16 channel16
) {
    data[0] = channel13 & 255;
    data[1] = (channel13 >> 8) & 255;
    data[2] = channel14 & 255;
    data[3] = (channel14 >> 8) & 255;
    data[4] = channel15 & 255;
    data[5] = (channel15 >> 8) & 255;
    data[6] = channel16 & 255;
    data[7] = (channel16 >> 8) & 255;
    return 8;
}

secondary_byte_size secondary_serialize_struct_IRTS_RL_3(
    uint8_t* data,
    secondary_message_IRTS_RL_3* message
) {
    data[0] = message->channel13 & 255;
    data[1] = (message->channel13 >> 8) & 255;
    data[2] = message->channel14 & 255;
    data[3] = (message->channel14 >> 8) & 255;
    data[4] = message->channel15 & 255;
    data[5] = (message->channel15 >> 8) & 255;
    data[6] = message->channel16 & 255;
    data[7] = (message->channel16 >> 8) & 255;
    return 8;
}

// ============== DESERIALIZE ============== //

void secondary_deserialize_IRTS_RL_3(
    secondary_message_IRTS_RL_3* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->channel13 = data[0] | (data[1] << 8);
    message->channel14 = data[2] | (data[3] << 8);
    message->channel15 = data[4] | (data[5] << 8);
    message->channel16 = data[6] | (data[7] << 8);
}

// ============== STRING ============== //

int secondary_to_string_IRTS_RL_3(secondary_message_IRTS_RL_3* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->channel13,
        message->channel14,
        message->channel15,
        message->channel16
    );
}

int secondary_fields_IRTS_RL_3(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "channel13" CANLIB_SEPARATOR 
        "channel14" CANLIB_SEPARATOR 
        "channel15" CANLIB_SEPARATOR 
        "channel16"
    );
}

int secondary_to_string_file_IRTS_RL_3(secondary_message_IRTS_RL_3* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->channel13,
        message->channel14,
        message->channel15,
        message->channel16
    );
}

int secondary_fields_file_IRTS_RL_3(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "channel13" CANLIB_SEPARATOR 
        "channel14" CANLIB_SEPARATOR 
        "channel15" CANLIB_SEPARATOR 
        "channel16"
    );
}

// ============== SERIALIZE ============== //

secondary_byte_size secondary_serialize_IRTS_RR_0(
    uint8_t* data,
    secondary_uint16 channel1,
    secondary_uint16 channel2,
    secondary_uint16 channel3,
    secondary_uint16 channel4
) {
    data[0] = channel1 & 255;
    data[1] = (channel1 >> 8) & 255;
    data[2] = channel2 & 255;
    data[3] = (channel2 >> 8) & 255;
    data[4] = channel3 & 255;
    data[5] = (channel3 >> 8) & 255;
    data[6] = channel4 & 255;
    data[7] = (channel4 >> 8) & 255;
    return 8;
}

secondary_byte_size secondary_serialize_struct_IRTS_RR_0(
    uint8_t* data,
    secondary_message_IRTS_RR_0* message
) {
    data[0] = message->channel1 & 255;
    data[1] = (message->channel1 >> 8) & 255;
    data[2] = message->channel2 & 255;
    data[3] = (message->channel2 >> 8) & 255;
    data[4] = message->channel3 & 255;
    data[5] = (message->channel3 >> 8) & 255;
    data[6] = message->channel4 & 255;
    data[7] = (message->channel4 >> 8) & 255;
    return 8;
}

// ============== DESERIALIZE ============== //

void secondary_deserialize_IRTS_RR_0(
    secondary_message_IRTS_RR_0* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->channel1 = data[0] | (data[1] << 8);
    message->channel2 = data[2] | (data[3] << 8);
    message->channel3 = data[4] | (data[5] << 8);
    message->channel4 = data[6] | (data[7] << 8);
}

// ============== STRING ============== //

int secondary_to_string_IRTS_RR_0(secondary_message_IRTS_RR_0* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->channel1,
        message->channel2,
        message->channel3,
        message->channel4
    );
}

int secondary_fields_IRTS_RR_0(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "channel1" CANLIB_SEPARATOR 
        "channel2" CANLIB_SEPARATOR 
        "channel3" CANLIB_SEPARATOR 
        "channel4"
    );
}

int secondary_to_string_file_IRTS_RR_0(secondary_message_IRTS_RR_0* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->channel1,
        message->channel2,
        message->channel3,
        message->channel4
    );
}

int secondary_fields_file_IRTS_RR_0(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "channel1" CANLIB_SEPARATOR 
        "channel2" CANLIB_SEPARATOR 
        "channel3" CANLIB_SEPARATOR 
        "channel4"
    );
}

// ============== SERIALIZE ============== //

secondary_byte_size secondary_serialize_IRTS_RR_1(
    uint8_t* data,
    secondary_uint16 channel5,
    secondary_uint16 channel6,
    secondary_uint16 channel7,
    secondary_uint16 channel8
) {
    data[0] = channel5 & 255;
    data[1] = (channel5 >> 8) & 255;
    data[2] = channel6 & 255;
    data[3] = (channel6 >> 8) & 255;
    data[4] = channel7 & 255;
    data[5] = (channel7 >> 8) & 255;
    data[6] = channel8 & 255;
    data[7] = (channel8 >> 8) & 255;
    return 8;
}

secondary_byte_size secondary_serialize_struct_IRTS_RR_1(
    uint8_t* data,
    secondary_message_IRTS_RR_1* message
) {
    data[0] = message->channel5 & 255;
    data[1] = (message->channel5 >> 8) & 255;
    data[2] = message->channel6 & 255;
    data[3] = (message->channel6 >> 8) & 255;
    data[4] = message->channel7 & 255;
    data[5] = (message->channel7 >> 8) & 255;
    data[6] = message->channel8 & 255;
    data[7] = (message->channel8 >> 8) & 255;
    return 8;
}

// ============== DESERIALIZE ============== //

void secondary_deserialize_IRTS_RR_1(
    secondary_message_IRTS_RR_1* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->channel5 = data[0] | (data[1] << 8);
    message->channel6 = data[2] | (data[3] << 8);
    message->channel7 = data[4] | (data[5] << 8);
    message->channel8 = data[6] | (data[7] << 8);
}

// ============== STRING ============== //

int secondary_to_string_IRTS_RR_1(secondary_message_IRTS_RR_1* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->channel5,
        message->channel6,
        message->channel7,
        message->channel8
    );
}

int secondary_fields_IRTS_RR_1(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "channel5" CANLIB_SEPARATOR 
        "channel6" CANLIB_SEPARATOR 
        "channel7" CANLIB_SEPARATOR 
        "channel8"
    );
}

int secondary_to_string_file_IRTS_RR_1(secondary_message_IRTS_RR_1* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->channel5,
        message->channel6,
        message->channel7,
        message->channel8
    );
}

int secondary_fields_file_IRTS_RR_1(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "channel5" CANLIB_SEPARATOR 
        "channel6" CANLIB_SEPARATOR 
        "channel7" CANLIB_SEPARATOR 
        "channel8"
    );
}

// ============== SERIALIZE ============== //

secondary_byte_size secondary_serialize_IRTS_RR_2(
    uint8_t* data,
    secondary_uint16 channel9,
    secondary_uint16 channel10,
    secondary_uint16 channel11,
    secondary_uint16 channel12
) {
    data[0] = channel9 & 255;
    data[1] = (channel9 >> 8) & 255;
    data[2] = channel10 & 255;
    data[3] = (channel10 >> 8) & 255;
    data[4] = channel11 & 255;
    data[5] = (channel11 >> 8) & 255;
    data[6] = channel12 & 255;
    data[7] = (channel12 >> 8) & 255;
    return 8;
}

secondary_byte_size secondary_serialize_struct_IRTS_RR_2(
    uint8_t* data,
    secondary_message_IRTS_RR_2* message
) {
    data[0] = message->channel9 & 255;
    data[1] = (message->channel9 >> 8) & 255;
    data[2] = message->channel10 & 255;
    data[3] = (message->channel10 >> 8) & 255;
    data[4] = message->channel11 & 255;
    data[5] = (message->channel11 >> 8) & 255;
    data[6] = message->channel12 & 255;
    data[7] = (message->channel12 >> 8) & 255;
    return 8;
}

// ============== DESERIALIZE ============== //

void secondary_deserialize_IRTS_RR_2(
    secondary_message_IRTS_RR_2* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->channel9 = data[0] | (data[1] << 8);
    message->channel10 = data[2] | (data[3] << 8);
    message->channel11 = data[4] | (data[5] << 8);
    message->channel12 = data[6] | (data[7] << 8);
}

// ============== STRING ============== //

int secondary_to_string_IRTS_RR_2(secondary_message_IRTS_RR_2* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->channel9,
        message->channel10,
        message->channel11,
        message->channel12
    );
}

int secondary_fields_IRTS_RR_2(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "channel9" CANLIB_SEPARATOR 
        "channel10" CANLIB_SEPARATOR 
        "channel11" CANLIB_SEPARATOR 
        "channel12"
    );
}

int secondary_to_string_file_IRTS_RR_2(secondary_message_IRTS_RR_2* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->channel9,
        message->channel10,
        message->channel11,
        message->channel12
    );
}

int secondary_fields_file_IRTS_RR_2(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "channel9" CANLIB_SEPARATOR 
        "channel10" CANLIB_SEPARATOR 
        "channel11" CANLIB_SEPARATOR 
        "channel12"
    );
}

// ============== SERIALIZE ============== //

secondary_byte_size secondary_serialize_IRTS_RR_3(
    uint8_t* data,
    secondary_uint16 channel13,
    secondary_uint16 channel14,
    secondary_uint16 channel15,
    secondary_uint16 channel16
) {
    data[0] = channel13 & 255;
    data[1] = (channel13 >> 8) & 255;
    data[2] = channel14 & 255;
    data[3] = (channel14 >> 8) & 255;
    data[4] = channel15 & 255;
    data[5] = (channel15 >> 8) & 255;
    data[6] = channel16 & 255;
    data[7] = (channel16 >> 8) & 255;
    return 8;
}

secondary_byte_size secondary_serialize_struct_IRTS_RR_3(
    uint8_t* data,
    secondary_message_IRTS_RR_3* message
) {
    data[0] = message->channel13 & 255;
    data[1] = (message->channel13 >> 8) & 255;
    data[2] = message->channel14 & 255;
    data[3] = (message->channel14 >> 8) & 255;
    data[4] = message->channel15 & 255;
    data[5] = (message->channel15 >> 8) & 255;
    data[6] = message->channel16 & 255;
    data[7] = (message->channel16 >> 8) & 255;
    return 8;
}

// ============== DESERIALIZE ============== //

void secondary_deserialize_IRTS_RR_3(
    secondary_message_IRTS_RR_3* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->channel13 = data[0] | (data[1] << 8);
    message->channel14 = data[2] | (data[3] << 8);
    message->channel15 = data[4] | (data[5] << 8);
    message->channel16 = data[6] | (data[7] << 8);
}

// ============== STRING ============== //

int secondary_to_string_IRTS_RR_3(secondary_message_IRTS_RR_3* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->channel13,
        message->channel14,
        message->channel15,
        message->channel16
    );
}

int secondary_fields_IRTS_RR_3(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "channel13" CANLIB_SEPARATOR 
        "channel14" CANLIB_SEPARATOR 
        "channel15" CANLIB_SEPARATOR 
        "channel16"
    );
}

int secondary_to_string_file_IRTS_RR_3(secondary_message_IRTS_RR_3* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu16,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->channel13,
        message->channel14,
        message->channel15,
        message->channel16
    );
}

int secondary_fields_file_IRTS_RR_3(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "channel13" CANLIB_SEPARATOR 
        "channel14" CANLIB_SEPARATOR 
        "channel15" CANLIB_SEPARATOR 
        "channel16"
    );
}

// ============== SERIALIZE ============== //

secondary_byte_size secondary_serialize_GPS_COORDS(
    uint8_t* data,
    secondary_float32 latitude,
    secondary_float32 longitude
) {
    data[0] = secondary_float32_to_bytes(latitude, 0);
    data[1] = secondary_float32_to_bytes(latitude, 1);
    data[2] = secondary_float32_to_bytes(latitude, 2);
    data[3] = secondary_float32_to_bytes(latitude, 3);
    data[4] = secondary_float32_to_bytes(longitude, 0);
    data[5] = secondary_float32_to_bytes(longitude, 1);
    data[6] = secondary_float32_to_bytes(longitude, 2);
    data[7] = secondary_float32_to_bytes(longitude, 3);
    return 8;
}

secondary_byte_size secondary_serialize_struct_GPS_COORDS(
    uint8_t* data,
    secondary_message_GPS_COORDS* message
) {
    data[0] = secondary_float32_to_bytes(message->latitude, 0);
    data[1] = secondary_float32_to_bytes(message->latitude, 1);
    data[2] = secondary_float32_to_bytes(message->latitude, 2);
    data[3] = secondary_float32_to_bytes(message->latitude, 3);
    data[4] = secondary_float32_to_bytes(message->longitude, 0);
    data[5] = secondary_float32_to_bytes(message->longitude, 1);
    data[6] = secondary_float32_to_bytes(message->longitude, 2);
    data[7] = secondary_float32_to_bytes(message->longitude, 3);
    return 8;
}

// ============== DESERIALIZE ============== //

void secondary_deserialize_GPS_COORDS(
    secondary_message_GPS_COORDS* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->latitude = ((secondary_float32_helper) {{data[0], data[1], data[2], data[3]}}).value;
    message->longitude = ((secondary_float32_helper) {{data[4], data[5], data[6], data[7]}}).value;
}

// ============== STRING ============== //

int secondary_to_string_GPS_COORDS(secondary_message_GPS_COORDS* message, char* buffer) {
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
        message->latitude,
        message->longitude
    );
}

int secondary_fields_GPS_COORDS(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "latitude" CANLIB_SEPARATOR 
        "longitude"
    );
}

int secondary_to_string_file_GPS_COORDS(secondary_message_GPS_COORDS* message, FILE* buffer) {
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
        message->latitude,
        message->longitude
    );
}

int secondary_fields_file_GPS_COORDS(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "latitude" CANLIB_SEPARATOR 
        "longitude"
    );
}

// ============== SERIALIZE ============== //

secondary_byte_size secondary_serialize_GPS_SPEED(
    uint8_t* data,
    secondary_uint16 speed
) {
    data[0] = speed & 255;
    data[1] = (speed >> 8) & 255;
    return 2;
}

secondary_byte_size secondary_serialize_struct_GPS_SPEED(
    uint8_t* data,
    secondary_message_GPS_SPEED* message
) {
    data[0] = message->speed & 255;
    data[1] = (message->speed >> 8) & 255;
    return 2;
}

// ============== DESERIALIZE ============== //

void secondary_deserialize_GPS_SPEED(
    secondary_message_GPS_SPEED* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->speed = data[0] | (data[1] << 8);
}

// ============== STRING ============== //

int secondary_to_string_GPS_SPEED(secondary_message_GPS_SPEED* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu16,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->speed
    );
}

int secondary_fields_GPS_SPEED(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "speed"
    );
}

int secondary_to_string_file_GPS_SPEED(secondary_message_GPS_SPEED* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu16,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->speed
    );
}

int secondary_fields_file_GPS_SPEED(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "speed"
    );
}

// ============== SERIALIZE ============== //

secondary_byte_size secondary_serialize_LAP_COUNT(
    uint8_t* data,
    secondary_uint8 lap_count,
    secondary_uint32 lap_time
) {
    data[0] = lap_time & 255;
    data[1] = (lap_time >> 8) & 255;
    data[2] = (lap_time >> 16) & 255;
    data[3] = (lap_time >> 24) & 255;
    data[4] = lap_count;
    return 5;
}

secondary_byte_size secondary_serialize_struct_LAP_COUNT(
    uint8_t* data,
    secondary_message_LAP_COUNT* message
) {
    data[0] = message->lap_time & 255;
    data[1] = (message->lap_time >> 8) & 255;
    data[2] = (message->lap_time >> 16) & 255;
    data[3] = (message->lap_time >> 24) & 255;
    data[4] = message->lap_count;
    return 5;
}

// ============== DESERIALIZE ============== //

void secondary_deserialize_LAP_COUNT(
    secondary_message_LAP_COUNT* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->lap_time = data[0] | (data[1] << 8) | (data[2] << 16) | (data[3] << 24);
    message->lap_count = data[4];
}

// ============== STRING ============== //

int secondary_to_string_LAP_COUNT(secondary_message_LAP_COUNT* message, char* buffer) {
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
        message->lap_count,
        message->lap_time
    );
}

int secondary_fields_LAP_COUNT(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "lap_count" CANLIB_SEPARATOR 
        "lap_time"
    );
}

int secondary_to_string_file_LAP_COUNT(secondary_message_LAP_COUNT* message, FILE* buffer) {
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
        message->lap_count,
        message->lap_time
    );
}

int secondary_fields_file_LAP_COUNT(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "lap_count" CANLIB_SEPARATOR 
        "lap_time"
    );
}

// ============== SERIALIZE ============== //

secondary_byte_size secondary_serialize_PEDALS_OUTPUT(
    uint8_t* data,
    secondary_uint8 apps,
    secondary_uint16 bse_front,
    secondary_uint16 bse_rear
) {
    data[0] = bse_front & 255;
    data[1] = (bse_front >> 8) & 255;
    data[2] = bse_rear & 255;
    data[3] = (bse_rear >> 8) & 255;
    data[4] = apps;
    return 5;
}

secondary_byte_size secondary_serialize_struct_PEDALS_OUTPUT(
    uint8_t* data,
    secondary_message_PEDALS_OUTPUT* message
) {
    data[0] = message->bse_front & 255;
    data[1] = (message->bse_front >> 8) & 255;
    data[2] = message->bse_rear & 255;
    data[3] = (message->bse_rear >> 8) & 255;
    data[4] = message->apps;
    return 5;
}

// ============== DESERIALIZE ============== //

void secondary_deserialize_PEDALS_OUTPUT(
    secondary_message_PEDALS_OUTPUT* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->bse_front = data[0] | (data[1] << 8);
    message->bse_rear = data[2] | (data[3] << 8);
    message->apps = data[4];
}// ============== CONVERSION ============== //

void secondary_raw_to_conversion_PEDALS_OUTPUT(
    secondary_message_PEDALS_OUTPUT_conversion* conversion,
    secondary_uint8 apps,
    secondary_uint16 bse_front,
    secondary_uint16 bse_rear
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
){
#ifdef CANLIB_TIMESTAMP
    conversion->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    conversion->apps = apps;
    conversion->bse_front = (((secondary_float32)bse_front) / 655.35) + 0;
    conversion->bse_rear = (((secondary_float32)bse_rear) / 655.35) + 0;
}

void secondary_raw_to_conversion_struct_PEDALS_OUTPUT(
    secondary_message_PEDALS_OUTPUT_conversion* conversion,
    secondary_message_PEDALS_OUTPUT* raw
){
#ifdef CANLIB_TIMESTAMP
    conversion->_timestamp = raw->_timestamp;
#endif // CANLIB_TIMESTAMP
    conversion->apps = raw->apps;
    conversion->bse_front = (((secondary_float32)raw->bse_front) / 655.35) + 0;
    conversion->bse_rear = (((secondary_float32)raw->bse_rear) / 655.35) + 0;
}

void secondary_conversion_to_raw_PEDALS_OUTPUT(
    secondary_message_PEDALS_OUTPUT* raw,
    secondary_uint8 apps,
    secondary_float32 bse_front,
    secondary_float32 bse_rear
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
){
#ifdef CANLIB_TIMESTAMP
    raw->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    raw->apps = apps;
    raw->bse_front = (secondary_uint16)((bse_front + 0) * 655.35);
    raw->bse_rear = (secondary_uint16)((bse_rear + 0) * 655.35);
}

void secondary_conversion_to_raw_struct_PEDALS_OUTPUT(
    secondary_message_PEDALS_OUTPUT* raw,
    secondary_message_PEDALS_OUTPUT_conversion* conversion
){
#ifdef CANLIB_TIMESTAMP
    raw->_timestamp = conversion->_timestamp;
#endif // CANLIB_TIMESTAMP
    raw->apps = conversion->apps;
    raw->bse_front = (secondary_uint16)((conversion->bse_front + 0) * 655.35);
    raw->bse_rear = (secondary_uint16)((conversion->bse_rear + 0) * 655.35);
}

// ============== STRING ============== //
int secondary_to_string_PEDALS_OUTPUT(secondary_message_PEDALS_OUTPUT_conversion* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->apps,
        message->bse_front,
        message->bse_rear
    );
}

int secondary_fields_PEDALS_OUTPUT(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "apps" CANLIB_SEPARATOR 
        "bse_front" CANLIB_SEPARATOR 
        "bse_rear"
    );
}

int secondary_to_string_file_PEDALS_OUTPUT(secondary_message_PEDALS_OUTPUT_conversion* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->apps,
        message->bse_front,
        message->bse_rear
    );
}

int secondary_fields_file_PEDALS_OUTPUT(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "apps" CANLIB_SEPARATOR 
        "bse_front" CANLIB_SEPARATOR 
        "bse_rear"
    );
}

// ============== SERIALIZE ============== //

secondary_byte_size secondary_serialize_CONTROL_OUTPUT(
    uint8_t* data,
    secondary_uint16 estimated_velocity,
    secondary_uint8 tmax_r,
    secondary_uint8 tmax_l,
    secondary_uint16 torque_l,
    secondary_uint16 torque_r
) {
    data[0] = estimated_velocity & 255;
    data[1] = (estimated_velocity >> 8) & 255;
    data[2] = torque_l & 255;
    data[3] = (torque_l >> 8) & 255;
    data[4] = torque_r & 255;
    data[5] = (torque_r >> 8) & 255;
    data[6] = tmax_r;
    data[7] = tmax_l;
    return 8;
}

secondary_byte_size secondary_serialize_struct_CONTROL_OUTPUT(
    uint8_t* data,
    secondary_message_CONTROL_OUTPUT* message
) {
    data[0] = message->estimated_velocity & 255;
    data[1] = (message->estimated_velocity >> 8) & 255;
    data[2] = message->torque_l & 255;
    data[3] = (message->torque_l >> 8) & 255;
    data[4] = message->torque_r & 255;
    data[5] = (message->torque_r >> 8) & 255;
    data[6] = message->tmax_r;
    data[7] = message->tmax_l;
    return 8;
}

// ============== DESERIALIZE ============== //

void secondary_deserialize_CONTROL_OUTPUT(
    secondary_message_CONTROL_OUTPUT* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->estimated_velocity = data[0] | (data[1] << 8);
    message->torque_l = data[2] | (data[3] << 8);
    message->torque_r = data[4] | (data[5] << 8);
    message->tmax_r = data[6];
    message->tmax_l = data[7];
}// ============== CONVERSION ============== //

void secondary_raw_to_conversion_CONTROL_OUTPUT(
    secondary_message_CONTROL_OUTPUT_conversion* conversion,
    secondary_uint16 estimated_velocity,
    secondary_uint8 tmax_r,
    secondary_uint8 tmax_l,
    secondary_uint16 torque_l,
    secondary_uint16 torque_r
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
){
#ifdef CANLIB_TIMESTAMP
    conversion->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    conversion->estimated_velocity = (((secondary_float32)estimated_velocity) / 1092.25) - 10;
    conversion->tmax_r = (((secondary_float32)tmax_r) / 3.1875) + 0;
    conversion->tmax_l = (((secondary_float32)tmax_l) / 3.1875) + 0;
    conversion->torque_l = (((secondary_float32)torque_l) / 819.1875) + 0;
    conversion->torque_r = (((secondary_float32)torque_r) / 819.1875) + 0;
}

void secondary_raw_to_conversion_struct_CONTROL_OUTPUT(
    secondary_message_CONTROL_OUTPUT_conversion* conversion,
    secondary_message_CONTROL_OUTPUT* raw
){
#ifdef CANLIB_TIMESTAMP
    conversion->_timestamp = raw->_timestamp;
#endif // CANLIB_TIMESTAMP
    conversion->estimated_velocity = (((secondary_float32)raw->estimated_velocity) / 1092.25) - 10;
    conversion->tmax_r = (((secondary_float32)raw->tmax_r) / 3.1875) + 0;
    conversion->tmax_l = (((secondary_float32)raw->tmax_l) / 3.1875) + 0;
    conversion->torque_l = (((secondary_float32)raw->torque_l) / 819.1875) + 0;
    conversion->torque_r = (((secondary_float32)raw->torque_r) / 819.1875) + 0;
}

void secondary_conversion_to_raw_CONTROL_OUTPUT(
    secondary_message_CONTROL_OUTPUT* raw,
    secondary_float32 estimated_velocity,
    secondary_float32 tmax_r,
    secondary_float32 tmax_l,
    secondary_float32 torque_l,
    secondary_float32 torque_r
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
){
#ifdef CANLIB_TIMESTAMP
    raw->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    raw->estimated_velocity = (secondary_uint16)((estimated_velocity + 10) * 1092.25);
    raw->tmax_r = (secondary_uint8)((tmax_r + 0) * 3.1875);
    raw->tmax_l = (secondary_uint8)((tmax_l + 0) * 3.1875);
    raw->torque_l = (secondary_uint16)((torque_l + 0) * 819.1875);
    raw->torque_r = (secondary_uint16)((torque_r + 0) * 819.1875);
}

void secondary_conversion_to_raw_struct_CONTROL_OUTPUT(
    secondary_message_CONTROL_OUTPUT* raw,
    secondary_message_CONTROL_OUTPUT_conversion* conversion
){
#ifdef CANLIB_TIMESTAMP
    raw->_timestamp = conversion->_timestamp;
#endif // CANLIB_TIMESTAMP
    raw->estimated_velocity = (secondary_uint16)((conversion->estimated_velocity + 10) * 1092.25);
    raw->tmax_r = (secondary_uint8)((conversion->tmax_r + 0) * 3.1875);
    raw->tmax_l = (secondary_uint8)((conversion->tmax_l + 0) * 3.1875);
    raw->torque_l = (secondary_uint16)((conversion->torque_l + 0) * 819.1875);
    raw->torque_r = (secondary_uint16)((conversion->torque_r + 0) * 819.1875);
}

// ============== STRING ============== //
int secondary_to_string_CONTROL_OUTPUT(secondary_message_CONTROL_OUTPUT_conversion* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->estimated_velocity,
        message->tmax_r,
        message->tmax_l,
        message->torque_l,
        message->torque_r
    );
}

int secondary_fields_CONTROL_OUTPUT(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "estimated_velocity" CANLIB_SEPARATOR 
        "tmax_r" CANLIB_SEPARATOR 
        "tmax_l" CANLIB_SEPARATOR 
        "torque_l" CANLIB_SEPARATOR 
        "torque_r"
    );
}

int secondary_to_string_file_CONTROL_OUTPUT(secondary_message_CONTROL_OUTPUT_conversion* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->estimated_velocity,
        message->tmax_r,
        message->tmax_l,
        message->torque_l,
        message->torque_r
    );
}

int secondary_fields_file_CONTROL_OUTPUT(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "estimated_velocity" CANLIB_SEPARATOR 
        "tmax_r" CANLIB_SEPARATOR 
        "tmax_l" CANLIB_SEPARATOR 
        "torque_l" CANLIB_SEPARATOR 
        "torque_r"
    );
}

// ============== SERIALIZE ============== //

secondary_byte_size secondary_serialize_STEERING_ANGLE(
    uint8_t* data,
    secondary_float32 angle
) {
    data[0] = secondary_float32_to_bytes(angle, 0);
    data[1] = secondary_float32_to_bytes(angle, 1);
    data[2] = secondary_float32_to_bytes(angle, 2);
    data[3] = secondary_float32_to_bytes(angle, 3);
    return 4;
}

secondary_byte_size secondary_serialize_struct_STEERING_ANGLE(
    uint8_t* data,
    secondary_message_STEERING_ANGLE* message
) {
    data[0] = secondary_float32_to_bytes(message->angle, 0);
    data[1] = secondary_float32_to_bytes(message->angle, 1);
    data[2] = secondary_float32_to_bytes(message->angle, 2);
    data[3] = secondary_float32_to_bytes(message->angle, 3);
    return 4;
}

// ============== DESERIALIZE ============== //

void secondary_deserialize_STEERING_ANGLE(
    secondary_message_STEERING_ANGLE* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->angle = ((secondary_float32_helper) {{data[0], data[1], data[2], data[3]}}).value;
}

// ============== STRING ============== //

int secondary_to_string_STEERING_ANGLE(secondary_message_STEERING_ANGLE* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIf32,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->angle
    );
}

int secondary_fields_STEERING_ANGLE(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "angle"
    );
}

int secondary_to_string_file_STEERING_ANGLE(secondary_message_STEERING_ANGLE* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIf32,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->angle
    );
}

int secondary_fields_file_STEERING_ANGLE(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "angle"
    );
}

// ============== SERIALIZE ============== //

secondary_byte_size secondary_serialize_TPMS(
    uint8_t* data,
    secondary_uint8 fl_pressure,
    secondary_uint8 fl_temperature,
    secondary_uint8 fr_pressure,
    secondary_uint8 fr_temperature,
    secondary_uint8 rl_pressure,
    secondary_uint8 rl_temperature,
    secondary_uint8 rr_pressure,
    secondary_uint8 rr_temperature
) {
    data[0] = fl_pressure;
    data[1] = fl_temperature;
    data[2] = fr_pressure;
    data[3] = fr_temperature;
    data[4] = rl_pressure;
    data[5] = rl_temperature;
    data[6] = rr_pressure;
    data[7] = rr_temperature;
    return 8;
}

secondary_byte_size secondary_serialize_struct_TPMS(
    uint8_t* data,
    secondary_message_TPMS* message
) {
    data[0] = message->fl_pressure;
    data[1] = message->fl_temperature;
    data[2] = message->fr_pressure;
    data[3] = message->fr_temperature;
    data[4] = message->rl_pressure;
    data[5] = message->rl_temperature;
    data[6] = message->rr_pressure;
    data[7] = message->rr_temperature;
    return 8;
}

// ============== DESERIALIZE ============== //

void secondary_deserialize_TPMS(
    secondary_message_TPMS* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->fl_pressure = data[0];
    message->fl_temperature = data[1];
    message->fr_pressure = data[2];
    message->fr_temperature = data[3];
    message->rl_pressure = data[4];
    message->rl_temperature = data[5];
    message->rr_pressure = data[6];
    message->rr_temperature = data[7];
}

// ============== STRING ============== //

int secondary_to_string_TPMS(secondary_message_TPMS* message, char* buffer) {
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
        message->fl_pressure,
        message->fl_temperature,
        message->fr_pressure,
        message->fr_temperature,
        message->rl_pressure,
        message->rl_temperature,
        message->rr_pressure,
        message->rr_temperature
    );
}

int secondary_fields_TPMS(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "fl_pressure" CANLIB_SEPARATOR 
        "fl_temperature" CANLIB_SEPARATOR 
        "fr_pressure" CANLIB_SEPARATOR 
        "fr_temperature" CANLIB_SEPARATOR 
        "rl_pressure" CANLIB_SEPARATOR 
        "rl_temperature" CANLIB_SEPARATOR 
        "rr_pressure" CANLIB_SEPARATOR 
        "rr_temperature"
    );
}

int secondary_to_string_file_TPMS(secondary_message_TPMS* message, FILE* buffer) {
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
        message->fl_pressure,
        message->fl_temperature,
        message->fr_pressure,
        message->fr_temperature,
        message->rl_pressure,
        message->rl_temperature,
        message->rr_pressure,
        message->rr_temperature
    );
}

int secondary_fields_file_TPMS(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "fl_pressure" CANLIB_SEPARATOR 
        "fl_temperature" CANLIB_SEPARATOR 
        "fr_pressure" CANLIB_SEPARATOR 
        "fr_temperature" CANLIB_SEPARATOR 
        "rl_pressure" CANLIB_SEPARATOR 
        "rl_temperature" CANLIB_SEPARATOR 
        "rr_pressure" CANLIB_SEPARATOR 
        "rr_temperature"
    );
}


// ============== UTILS ============== //

int secondary_fields_from_id(canlib_message_id message_id, char* buffer) {
    switch (message_id) {
        case 1260:
            return secondary_fields_IMU_ANGULAR_RATE(buffer);
        case 1261:
            return secondary_fields_IMU_ACCELERATION(buffer);
        case 1460:
            return secondary_fields_IRTS_FL_0(buffer);
        case 1461:
            return secondary_fields_IRTS_FL_1(buffer);
        case 1462:
            return secondary_fields_IRTS_FL_2(buffer);
        case 1463:
            return secondary_fields_IRTS_FL_3(buffer);
        case 1464:
            return secondary_fields_IRTS_FR_0(buffer);
        case 1465:
            return secondary_fields_IRTS_FR_1(buffer);
        case 1466:
            return secondary_fields_IRTS_FR_2(buffer);
        case 1467:
            return secondary_fields_IRTS_FR_3(buffer);
        case 1468:
            return secondary_fields_IRTS_RL_0(buffer);
        case 1469:
            return secondary_fields_IRTS_RL_1(buffer);
        case 1470:
            return secondary_fields_IRTS_RL_2(buffer);
        case 1471:
            return secondary_fields_IRTS_RL_3(buffer);
        case 1472:
            return secondary_fields_IRTS_RR_0(buffer);
        case 1473:
            return secondary_fields_IRTS_RR_1(buffer);
        case 1474:
            return secondary_fields_IRTS_RR_2(buffer);
        case 1475:
            return secondary_fields_IRTS_RR_3(buffer);
        case 1025:
            return secondary_fields_GPS_COORDS(buffer);
        case 1057:
            return secondary_fields_GPS_SPEED(buffer);
        case 1089:
            return secondary_fields_LAP_COUNT(buffer);
        case 769:
            return secondary_fields_PEDALS_OUTPUT(buffer);
        case 801:
            return secondary_fields_CONTROL_OUTPUT(buffer);
        case 258:
            return secondary_fields_STEERING_ANGLE(buffer);
        case 1:
            return secondary_fields_TPMS(buffer);
    }
    return 0;
}

int secondary_to_string_from_id(canlib_message_id message_id, void* message, char* buffer) {
    switch (message_id) {
        case 1260:
            return secondary_to_string_IMU_ANGULAR_RATE((secondary_message_IMU_ANGULAR_RATE_conversion*) message, buffer);
        case 1261:
            return secondary_to_string_IMU_ACCELERATION((secondary_message_IMU_ACCELERATION_conversion*) message, buffer);
        case 1460:
            return secondary_to_string_IRTS_FL_0((secondary_message_IRTS_FL_0*) message, buffer);
        case 1461:
            return secondary_to_string_IRTS_FL_1((secondary_message_IRTS_FL_1*) message, buffer);
        case 1462:
            return secondary_to_string_IRTS_FL_2((secondary_message_IRTS_FL_2*) message, buffer);
        case 1463:
            return secondary_to_string_IRTS_FL_3((secondary_message_IRTS_FL_3*) message, buffer);
        case 1464:
            return secondary_to_string_IRTS_FR_0((secondary_message_IRTS_FR_0*) message, buffer);
        case 1465:
            return secondary_to_string_IRTS_FR_1((secondary_message_IRTS_FR_1*) message, buffer);
        case 1466:
            return secondary_to_string_IRTS_FR_2((secondary_message_IRTS_FR_2*) message, buffer);
        case 1467:
            return secondary_to_string_IRTS_FR_3((secondary_message_IRTS_FR_3*) message, buffer);
        case 1468:
            return secondary_to_string_IRTS_RL_0((secondary_message_IRTS_RL_0*) message, buffer);
        case 1469:
            return secondary_to_string_IRTS_RL_1((secondary_message_IRTS_RL_1*) message, buffer);
        case 1470:
            return secondary_to_string_IRTS_RL_2((secondary_message_IRTS_RL_2*) message, buffer);
        case 1471:
            return secondary_to_string_IRTS_RL_3((secondary_message_IRTS_RL_3*) message, buffer);
        case 1472:
            return secondary_to_string_IRTS_RR_0((secondary_message_IRTS_RR_0*) message, buffer);
        case 1473:
            return secondary_to_string_IRTS_RR_1((secondary_message_IRTS_RR_1*) message, buffer);
        case 1474:
            return secondary_to_string_IRTS_RR_2((secondary_message_IRTS_RR_2*) message, buffer);
        case 1475:
            return secondary_to_string_IRTS_RR_3((secondary_message_IRTS_RR_3*) message, buffer);
        case 1025:
            return secondary_to_string_GPS_COORDS((secondary_message_GPS_COORDS*) message, buffer);
        case 1057:
            return secondary_to_string_GPS_SPEED((secondary_message_GPS_SPEED*) message, buffer);
        case 1089:
            return secondary_to_string_LAP_COUNT((secondary_message_LAP_COUNT*) message, buffer);
        case 769:
            return secondary_to_string_PEDALS_OUTPUT((secondary_message_PEDALS_OUTPUT_conversion*) message, buffer);
        case 801:
            return secondary_to_string_CONTROL_OUTPUT((secondary_message_CONTROL_OUTPUT_conversion*) message, buffer);
        case 258:
            return secondary_to_string_STEERING_ANGLE((secondary_message_STEERING_ANGLE*) message, buffer);
        case 1:
            return secondary_to_string_TPMS((secondary_message_TPMS*) message, buffer);
    }
    return 0;
}

int secondary_fields_file_from_id(canlib_message_id message_id, FILE *buffer) {
    switch (message_id) {
        case 1260:
            return secondary_fields_file_IMU_ANGULAR_RATE(buffer);
        case 1261:
            return secondary_fields_file_IMU_ACCELERATION(buffer);
        case 1460:
            return secondary_fields_file_IRTS_FL_0(buffer);
        case 1461:
            return secondary_fields_file_IRTS_FL_1(buffer);
        case 1462:
            return secondary_fields_file_IRTS_FL_2(buffer);
        case 1463:
            return secondary_fields_file_IRTS_FL_3(buffer);
        case 1464:
            return secondary_fields_file_IRTS_FR_0(buffer);
        case 1465:
            return secondary_fields_file_IRTS_FR_1(buffer);
        case 1466:
            return secondary_fields_file_IRTS_FR_2(buffer);
        case 1467:
            return secondary_fields_file_IRTS_FR_3(buffer);
        case 1468:
            return secondary_fields_file_IRTS_RL_0(buffer);
        case 1469:
            return secondary_fields_file_IRTS_RL_1(buffer);
        case 1470:
            return secondary_fields_file_IRTS_RL_2(buffer);
        case 1471:
            return secondary_fields_file_IRTS_RL_3(buffer);
        case 1472:
            return secondary_fields_file_IRTS_RR_0(buffer);
        case 1473:
            return secondary_fields_file_IRTS_RR_1(buffer);
        case 1474:
            return secondary_fields_file_IRTS_RR_2(buffer);
        case 1475:
            return secondary_fields_file_IRTS_RR_3(buffer);
        case 1025:
            return secondary_fields_file_GPS_COORDS(buffer);
        case 1057:
            return secondary_fields_file_GPS_SPEED(buffer);
        case 1089:
            return secondary_fields_file_LAP_COUNT(buffer);
        case 769:
            return secondary_fields_file_PEDALS_OUTPUT(buffer);
        case 801:
            return secondary_fields_file_CONTROL_OUTPUT(buffer);
        case 258:
            return secondary_fields_file_STEERING_ANGLE(buffer);
        case 1:
            return secondary_fields_file_TPMS(buffer);
    }
    return 0;
}

int secondary_to_string_file_from_id(canlib_message_id message_id, void* message, FILE *buffer) {
    switch (message_id) {
        case 1260:
            return secondary_to_string_file_IMU_ANGULAR_RATE((secondary_message_IMU_ANGULAR_RATE_conversion*) message, buffer);
        case 1261:
            return secondary_to_string_file_IMU_ACCELERATION((secondary_message_IMU_ACCELERATION_conversion*) message, buffer);
        case 1460:
            return secondary_to_string_file_IRTS_FL_0((secondary_message_IRTS_FL_0*) message, buffer);
        case 1461:
            return secondary_to_string_file_IRTS_FL_1((secondary_message_IRTS_FL_1*) message, buffer);
        case 1462:
            return secondary_to_string_file_IRTS_FL_2((secondary_message_IRTS_FL_2*) message, buffer);
        case 1463:
            return secondary_to_string_file_IRTS_FL_3((secondary_message_IRTS_FL_3*) message, buffer);
        case 1464:
            return secondary_to_string_file_IRTS_FR_0((secondary_message_IRTS_FR_0*) message, buffer);
        case 1465:
            return secondary_to_string_file_IRTS_FR_1((secondary_message_IRTS_FR_1*) message, buffer);
        case 1466:
            return secondary_to_string_file_IRTS_FR_2((secondary_message_IRTS_FR_2*) message, buffer);
        case 1467:
            return secondary_to_string_file_IRTS_FR_3((secondary_message_IRTS_FR_3*) message, buffer);
        case 1468:
            return secondary_to_string_file_IRTS_RL_0((secondary_message_IRTS_RL_0*) message, buffer);
        case 1469:
            return secondary_to_string_file_IRTS_RL_1((secondary_message_IRTS_RL_1*) message, buffer);
        case 1470:
            return secondary_to_string_file_IRTS_RL_2((secondary_message_IRTS_RL_2*) message, buffer);
        case 1471:
            return secondary_to_string_file_IRTS_RL_3((secondary_message_IRTS_RL_3*) message, buffer);
        case 1472:
            return secondary_to_string_file_IRTS_RR_0((secondary_message_IRTS_RR_0*) message, buffer);
        case 1473:
            return secondary_to_string_file_IRTS_RR_1((secondary_message_IRTS_RR_1*) message, buffer);
        case 1474:
            return secondary_to_string_file_IRTS_RR_2((secondary_message_IRTS_RR_2*) message, buffer);
        case 1475:
            return secondary_to_string_file_IRTS_RR_3((secondary_message_IRTS_RR_3*) message, buffer);
        case 1025:
            return secondary_to_string_file_GPS_COORDS((secondary_message_GPS_COORDS*) message, buffer);
        case 1057:
            return secondary_to_string_file_GPS_SPEED((secondary_message_GPS_SPEED*) message, buffer);
        case 1089:
            return secondary_to_string_file_LAP_COUNT((secondary_message_LAP_COUNT*) message, buffer);
        case 769:
            return secondary_to_string_file_PEDALS_OUTPUT((secondary_message_PEDALS_OUTPUT_conversion*) message, buffer);
        case 801:
            return secondary_to_string_file_CONTROL_OUTPUT((secondary_message_CONTROL_OUTPUT_conversion*) message, buffer);
        case 258:
            return secondary_to_string_file_STEERING_ANGLE((secondary_message_STEERING_ANGLE*) message, buffer);
        case 1:
            return secondary_to_string_file_TPMS((secondary_message_TPMS*) message, buffer);
    }
    return 0;
}

void* secondary_deserialize_from_id(
    canlib_message_id message_id,
    uint8_t* data,
    void* message_raw,
    void* message_conversion
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
) {
    switch (message_id) {
        case 1260: {
            secondary_deserialize_IMU_ANGULAR_RATE(
                (secondary_message_IMU_ANGULAR_RATE*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            secondary_raw_to_conversion_struct_IMU_ANGULAR_RATE(
                (secondary_message_IMU_ANGULAR_RATE_conversion*) message_conversion,
                (secondary_message_IMU_ANGULAR_RATE*) message_raw
            );
            return message_conversion;
        }
        case 1261: {
            secondary_deserialize_IMU_ACCELERATION(
                (secondary_message_IMU_ACCELERATION*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            secondary_raw_to_conversion_struct_IMU_ACCELERATION(
                (secondary_message_IMU_ACCELERATION_conversion*) message_conversion,
                (secondary_message_IMU_ACCELERATION*) message_raw
            );
            return message_conversion;
        }
        case 1460: {
            secondary_deserialize_IRTS_FL_0(
                (secondary_message_IRTS_FL_0*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 1461: {
            secondary_deserialize_IRTS_FL_1(
                (secondary_message_IRTS_FL_1*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 1462: {
            secondary_deserialize_IRTS_FL_2(
                (secondary_message_IRTS_FL_2*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 1463: {
            secondary_deserialize_IRTS_FL_3(
                (secondary_message_IRTS_FL_3*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 1464: {
            secondary_deserialize_IRTS_FR_0(
                (secondary_message_IRTS_FR_0*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 1465: {
            secondary_deserialize_IRTS_FR_1(
                (secondary_message_IRTS_FR_1*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 1466: {
            secondary_deserialize_IRTS_FR_2(
                (secondary_message_IRTS_FR_2*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 1467: {
            secondary_deserialize_IRTS_FR_3(
                (secondary_message_IRTS_FR_3*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 1468: {
            secondary_deserialize_IRTS_RL_0(
                (secondary_message_IRTS_RL_0*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 1469: {
            secondary_deserialize_IRTS_RL_1(
                (secondary_message_IRTS_RL_1*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 1470: {
            secondary_deserialize_IRTS_RL_2(
                (secondary_message_IRTS_RL_2*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 1471: {
            secondary_deserialize_IRTS_RL_3(
                (secondary_message_IRTS_RL_3*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 1472: {
            secondary_deserialize_IRTS_RR_0(
                (secondary_message_IRTS_RR_0*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 1473: {
            secondary_deserialize_IRTS_RR_1(
                (secondary_message_IRTS_RR_1*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 1474: {
            secondary_deserialize_IRTS_RR_2(
                (secondary_message_IRTS_RR_2*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 1475: {
            secondary_deserialize_IRTS_RR_3(
                (secondary_message_IRTS_RR_3*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 1025: {
            secondary_deserialize_GPS_COORDS(
                (secondary_message_GPS_COORDS*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 1057: {
            secondary_deserialize_GPS_SPEED(
                (secondary_message_GPS_SPEED*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 1089: {
            secondary_deserialize_LAP_COUNT(
                (secondary_message_LAP_COUNT*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 769: {
            secondary_deserialize_PEDALS_OUTPUT(
                (secondary_message_PEDALS_OUTPUT*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            secondary_raw_to_conversion_struct_PEDALS_OUTPUT(
                (secondary_message_PEDALS_OUTPUT_conversion*) message_conversion,
                (secondary_message_PEDALS_OUTPUT*) message_raw
            );
            return message_conversion;
        }
        case 801: {
            secondary_deserialize_CONTROL_OUTPUT(
                (secondary_message_CONTROL_OUTPUT*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            secondary_raw_to_conversion_struct_CONTROL_OUTPUT(
                (secondary_message_CONTROL_OUTPUT_conversion*) message_conversion,
                (secondary_message_CONTROL_OUTPUT*) message_raw
            );
            return message_conversion;
        }
        case 258: {
            secondary_deserialize_STEERING_ANGLE(
                (secondary_message_STEERING_ANGLE*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 1: {
            secondary_deserialize_TPMS(
                (secondary_message_TPMS*) message_raw,
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

secondary_devices* secondary_devices_new() {
    secondary_devices* devices = (secondary_devices*) malloc(sizeof(secondary_devices));
    (*devices)[secondary_INDEX_IMU_ANGULAR_RATE].id = 1260;
    (*devices)[secondary_INDEX_IMU_ANGULAR_RATE].message_raw = (void*) malloc(sizeof(secondary_message_IMU_ANGULAR_RATE));
    (*devices)[secondary_INDEX_IMU_ANGULAR_RATE].message_conversion = (void*) malloc(sizeof(secondary_message_IMU_ANGULAR_RATE_conversion));
    (*devices)[secondary_INDEX_IMU_ACCELERATION].id = 1261;
    (*devices)[secondary_INDEX_IMU_ACCELERATION].message_raw = (void*) malloc(sizeof(secondary_message_IMU_ACCELERATION));
    (*devices)[secondary_INDEX_IMU_ACCELERATION].message_conversion = (void*) malloc(sizeof(secondary_message_IMU_ACCELERATION_conversion));
    (*devices)[secondary_INDEX_IRTS_FL_0].id = 1460;
    (*devices)[secondary_INDEX_IRTS_FL_0].message_raw = (void*) malloc(sizeof(secondary_message_IRTS_FL_0));
    (*devices)[secondary_INDEX_IRTS_FL_0].message_conversion = NULL;
    (*devices)[secondary_INDEX_IRTS_FL_1].id = 1461;
    (*devices)[secondary_INDEX_IRTS_FL_1].message_raw = (void*) malloc(sizeof(secondary_message_IRTS_FL_1));
    (*devices)[secondary_INDEX_IRTS_FL_1].message_conversion = NULL;
    (*devices)[secondary_INDEX_IRTS_FL_2].id = 1462;
    (*devices)[secondary_INDEX_IRTS_FL_2].message_raw = (void*) malloc(sizeof(secondary_message_IRTS_FL_2));
    (*devices)[secondary_INDEX_IRTS_FL_2].message_conversion = NULL;
    (*devices)[secondary_INDEX_IRTS_FL_3].id = 1463;
    (*devices)[secondary_INDEX_IRTS_FL_3].message_raw = (void*) malloc(sizeof(secondary_message_IRTS_FL_3));
    (*devices)[secondary_INDEX_IRTS_FL_3].message_conversion = NULL;
    (*devices)[secondary_INDEX_IRTS_FR_0].id = 1464;
    (*devices)[secondary_INDEX_IRTS_FR_0].message_raw = (void*) malloc(sizeof(secondary_message_IRTS_FR_0));
    (*devices)[secondary_INDEX_IRTS_FR_0].message_conversion = NULL;
    (*devices)[secondary_INDEX_IRTS_FR_1].id = 1465;
    (*devices)[secondary_INDEX_IRTS_FR_1].message_raw = (void*) malloc(sizeof(secondary_message_IRTS_FR_1));
    (*devices)[secondary_INDEX_IRTS_FR_1].message_conversion = NULL;
    (*devices)[secondary_INDEX_IRTS_FR_2].id = 1466;
    (*devices)[secondary_INDEX_IRTS_FR_2].message_raw = (void*) malloc(sizeof(secondary_message_IRTS_FR_2));
    (*devices)[secondary_INDEX_IRTS_FR_2].message_conversion = NULL;
    (*devices)[secondary_INDEX_IRTS_FR_3].id = 1467;
    (*devices)[secondary_INDEX_IRTS_FR_3].message_raw = (void*) malloc(sizeof(secondary_message_IRTS_FR_3));
    (*devices)[secondary_INDEX_IRTS_FR_3].message_conversion = NULL;
    (*devices)[secondary_INDEX_IRTS_RL_0].id = 1468;
    (*devices)[secondary_INDEX_IRTS_RL_0].message_raw = (void*) malloc(sizeof(secondary_message_IRTS_RL_0));
    (*devices)[secondary_INDEX_IRTS_RL_0].message_conversion = NULL;
    (*devices)[secondary_INDEX_IRTS_RL_1].id = 1469;
    (*devices)[secondary_INDEX_IRTS_RL_1].message_raw = (void*) malloc(sizeof(secondary_message_IRTS_RL_1));
    (*devices)[secondary_INDEX_IRTS_RL_1].message_conversion = NULL;
    (*devices)[secondary_INDEX_IRTS_RL_2].id = 1470;
    (*devices)[secondary_INDEX_IRTS_RL_2].message_raw = (void*) malloc(sizeof(secondary_message_IRTS_RL_2));
    (*devices)[secondary_INDEX_IRTS_RL_2].message_conversion = NULL;
    (*devices)[secondary_INDEX_IRTS_RL_3].id = 1471;
    (*devices)[secondary_INDEX_IRTS_RL_3].message_raw = (void*) malloc(sizeof(secondary_message_IRTS_RL_3));
    (*devices)[secondary_INDEX_IRTS_RL_3].message_conversion = NULL;
    (*devices)[secondary_INDEX_IRTS_RR_0].id = 1472;
    (*devices)[secondary_INDEX_IRTS_RR_0].message_raw = (void*) malloc(sizeof(secondary_message_IRTS_RR_0));
    (*devices)[secondary_INDEX_IRTS_RR_0].message_conversion = NULL;
    (*devices)[secondary_INDEX_IRTS_RR_1].id = 1473;
    (*devices)[secondary_INDEX_IRTS_RR_1].message_raw = (void*) malloc(sizeof(secondary_message_IRTS_RR_1));
    (*devices)[secondary_INDEX_IRTS_RR_1].message_conversion = NULL;
    (*devices)[secondary_INDEX_IRTS_RR_2].id = 1474;
    (*devices)[secondary_INDEX_IRTS_RR_2].message_raw = (void*) malloc(sizeof(secondary_message_IRTS_RR_2));
    (*devices)[secondary_INDEX_IRTS_RR_2].message_conversion = NULL;
    (*devices)[secondary_INDEX_IRTS_RR_3].id = 1475;
    (*devices)[secondary_INDEX_IRTS_RR_3].message_raw = (void*) malloc(sizeof(secondary_message_IRTS_RR_3));
    (*devices)[secondary_INDEX_IRTS_RR_3].message_conversion = NULL;
    (*devices)[secondary_INDEX_GPS_COORDS].id = 1025;
    (*devices)[secondary_INDEX_GPS_COORDS].message_raw = (void*) malloc(sizeof(secondary_message_GPS_COORDS));
    (*devices)[secondary_INDEX_GPS_COORDS].message_conversion = NULL;
    (*devices)[secondary_INDEX_GPS_SPEED].id = 1057;
    (*devices)[secondary_INDEX_GPS_SPEED].message_raw = (void*) malloc(sizeof(secondary_message_GPS_SPEED));
    (*devices)[secondary_INDEX_GPS_SPEED].message_conversion = NULL;
    (*devices)[secondary_INDEX_LAP_COUNT].id = 1089;
    (*devices)[secondary_INDEX_LAP_COUNT].message_raw = (void*) malloc(sizeof(secondary_message_LAP_COUNT));
    (*devices)[secondary_INDEX_LAP_COUNT].message_conversion = NULL;
    (*devices)[secondary_INDEX_PEDALS_OUTPUT].id = 769;
    (*devices)[secondary_INDEX_PEDALS_OUTPUT].message_raw = (void*) malloc(sizeof(secondary_message_PEDALS_OUTPUT));
    (*devices)[secondary_INDEX_PEDALS_OUTPUT].message_conversion = (void*) malloc(sizeof(secondary_message_PEDALS_OUTPUT_conversion));
    (*devices)[secondary_INDEX_CONTROL_OUTPUT].id = 801;
    (*devices)[secondary_INDEX_CONTROL_OUTPUT].message_raw = (void*) malloc(sizeof(secondary_message_CONTROL_OUTPUT));
    (*devices)[secondary_INDEX_CONTROL_OUTPUT].message_conversion = (void*) malloc(sizeof(secondary_message_CONTROL_OUTPUT_conversion));
    (*devices)[secondary_INDEX_STEERING_ANGLE].id = 258;
    (*devices)[secondary_INDEX_STEERING_ANGLE].message_raw = (void*) malloc(sizeof(secondary_message_STEERING_ANGLE));
    (*devices)[secondary_INDEX_STEERING_ANGLE].message_conversion = NULL;
    (*devices)[secondary_INDEX_TPMS].id = 1;
    (*devices)[secondary_INDEX_TPMS].message_raw = (void*) malloc(sizeof(secondary_message_TPMS));
    (*devices)[secondary_INDEX_TPMS].message_conversion = NULL;
    return devices;
}

void secondary_devices_free(secondary_devices* devices) {
    free((*devices)[secondary_INDEX_IMU_ANGULAR_RATE].message_raw);
    free((*devices)[secondary_INDEX_IMU_ANGULAR_RATE].message_conversion);
    free((*devices)[secondary_INDEX_IMU_ACCELERATION].message_raw);
    free((*devices)[secondary_INDEX_IMU_ACCELERATION].message_conversion);
    free((*devices)[secondary_INDEX_IRTS_FL_0].message_raw);
    free((*devices)[secondary_INDEX_IRTS_FL_1].message_raw);
    free((*devices)[secondary_INDEX_IRTS_FL_2].message_raw);
    free((*devices)[secondary_INDEX_IRTS_FL_3].message_raw);
    free((*devices)[secondary_INDEX_IRTS_FR_0].message_raw);
    free((*devices)[secondary_INDEX_IRTS_FR_1].message_raw);
    free((*devices)[secondary_INDEX_IRTS_FR_2].message_raw);
    free((*devices)[secondary_INDEX_IRTS_FR_3].message_raw);
    free((*devices)[secondary_INDEX_IRTS_RL_0].message_raw);
    free((*devices)[secondary_INDEX_IRTS_RL_1].message_raw);
    free((*devices)[secondary_INDEX_IRTS_RL_2].message_raw);
    free((*devices)[secondary_INDEX_IRTS_RL_3].message_raw);
    free((*devices)[secondary_INDEX_IRTS_RR_0].message_raw);
    free((*devices)[secondary_INDEX_IRTS_RR_1].message_raw);
    free((*devices)[secondary_INDEX_IRTS_RR_2].message_raw);
    free((*devices)[secondary_INDEX_IRTS_RR_3].message_raw);
    free((*devices)[secondary_INDEX_GPS_COORDS].message_raw);
    free((*devices)[secondary_INDEX_GPS_SPEED].message_raw);
    free((*devices)[secondary_INDEX_LAP_COUNT].message_raw);
    free((*devices)[secondary_INDEX_PEDALS_OUTPUT].message_raw);
    free((*devices)[secondary_INDEX_PEDALS_OUTPUT].message_conversion);
    free((*devices)[secondary_INDEX_CONTROL_OUTPUT].message_raw);
    free((*devices)[secondary_INDEX_CONTROL_OUTPUT].message_conversion);
    free((*devices)[secondary_INDEX_STEERING_ANGLE].message_raw);
    free((*devices)[secondary_INDEX_TPMS].message_raw);
    free(devices);
}

void secondary_devices_deserialize_from_id(
    secondary_devices* devices,
    canlib_message_id message_id,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
) {
    switch (message_id) {
        case 1260: {
            secondary_deserialize_IMU_ANGULAR_RATE(
                (secondary_message_IMU_ANGULAR_RATE*) &(*devices)[secondary_INDEX_IMU_ANGULAR_RATE].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            secondary_raw_to_conversion_struct_IMU_ANGULAR_RATE(
                (secondary_message_IMU_ANGULAR_RATE_conversion*) &(*devices)[secondary_INDEX_IMU_ANGULAR_RATE].message_conversion,
                (secondary_message_IMU_ANGULAR_RATE*) &(*devices)[secondary_INDEX_IMU_ANGULAR_RATE].message_raw
            );
            return;
        }
        case 1261: {
            secondary_deserialize_IMU_ACCELERATION(
                (secondary_message_IMU_ACCELERATION*) &(*devices)[secondary_INDEX_IMU_ACCELERATION].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            secondary_raw_to_conversion_struct_IMU_ACCELERATION(
                (secondary_message_IMU_ACCELERATION_conversion*) &(*devices)[secondary_INDEX_IMU_ACCELERATION].message_conversion,
                (secondary_message_IMU_ACCELERATION*) &(*devices)[secondary_INDEX_IMU_ACCELERATION].message_raw
            );
            return;
        }
        case 1460: {
            secondary_deserialize_IRTS_FL_0(
                (secondary_message_IRTS_FL_0*) &(*devices)[secondary_INDEX_IRTS_FL_0].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 1461: {
            secondary_deserialize_IRTS_FL_1(
                (secondary_message_IRTS_FL_1*) &(*devices)[secondary_INDEX_IRTS_FL_1].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 1462: {
            secondary_deserialize_IRTS_FL_2(
                (secondary_message_IRTS_FL_2*) &(*devices)[secondary_INDEX_IRTS_FL_2].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 1463: {
            secondary_deserialize_IRTS_FL_3(
                (secondary_message_IRTS_FL_3*) &(*devices)[secondary_INDEX_IRTS_FL_3].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 1464: {
            secondary_deserialize_IRTS_FR_0(
                (secondary_message_IRTS_FR_0*) &(*devices)[secondary_INDEX_IRTS_FR_0].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 1465: {
            secondary_deserialize_IRTS_FR_1(
                (secondary_message_IRTS_FR_1*) &(*devices)[secondary_INDEX_IRTS_FR_1].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 1466: {
            secondary_deserialize_IRTS_FR_2(
                (secondary_message_IRTS_FR_2*) &(*devices)[secondary_INDEX_IRTS_FR_2].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 1467: {
            secondary_deserialize_IRTS_FR_3(
                (secondary_message_IRTS_FR_3*) &(*devices)[secondary_INDEX_IRTS_FR_3].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 1468: {
            secondary_deserialize_IRTS_RL_0(
                (secondary_message_IRTS_RL_0*) &(*devices)[secondary_INDEX_IRTS_RL_0].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 1469: {
            secondary_deserialize_IRTS_RL_1(
                (secondary_message_IRTS_RL_1*) &(*devices)[secondary_INDEX_IRTS_RL_1].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 1470: {
            secondary_deserialize_IRTS_RL_2(
                (secondary_message_IRTS_RL_2*) &(*devices)[secondary_INDEX_IRTS_RL_2].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 1471: {
            secondary_deserialize_IRTS_RL_3(
                (secondary_message_IRTS_RL_3*) &(*devices)[secondary_INDEX_IRTS_RL_3].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 1472: {
            secondary_deserialize_IRTS_RR_0(
                (secondary_message_IRTS_RR_0*) &(*devices)[secondary_INDEX_IRTS_RR_0].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 1473: {
            secondary_deserialize_IRTS_RR_1(
                (secondary_message_IRTS_RR_1*) &(*devices)[secondary_INDEX_IRTS_RR_1].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 1474: {
            secondary_deserialize_IRTS_RR_2(
                (secondary_message_IRTS_RR_2*) &(*devices)[secondary_INDEX_IRTS_RR_2].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 1475: {
            secondary_deserialize_IRTS_RR_3(
                (secondary_message_IRTS_RR_3*) &(*devices)[secondary_INDEX_IRTS_RR_3].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 1025: {
            secondary_deserialize_GPS_COORDS(
                (secondary_message_GPS_COORDS*) &(*devices)[secondary_INDEX_GPS_COORDS].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 1057: {
            secondary_deserialize_GPS_SPEED(
                (secondary_message_GPS_SPEED*) &(*devices)[secondary_INDEX_GPS_SPEED].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 1089: {
            secondary_deserialize_LAP_COUNT(
                (secondary_message_LAP_COUNT*) &(*devices)[secondary_INDEX_LAP_COUNT].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 769: {
            secondary_deserialize_PEDALS_OUTPUT(
                (secondary_message_PEDALS_OUTPUT*) &(*devices)[secondary_INDEX_PEDALS_OUTPUT].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            secondary_raw_to_conversion_struct_PEDALS_OUTPUT(
                (secondary_message_PEDALS_OUTPUT_conversion*) &(*devices)[secondary_INDEX_PEDALS_OUTPUT].message_conversion,
                (secondary_message_PEDALS_OUTPUT*) &(*devices)[secondary_INDEX_PEDALS_OUTPUT].message_raw
            );
            return;
        }
        case 801: {
            secondary_deserialize_CONTROL_OUTPUT(
                (secondary_message_CONTROL_OUTPUT*) &(*devices)[secondary_INDEX_CONTROL_OUTPUT].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            secondary_raw_to_conversion_struct_CONTROL_OUTPUT(
                (secondary_message_CONTROL_OUTPUT_conversion*) &(*devices)[secondary_INDEX_CONTROL_OUTPUT].message_conversion,
                (secondary_message_CONTROL_OUTPUT*) &(*devices)[secondary_INDEX_CONTROL_OUTPUT].message_raw
            );
            return;
        }
        case 258: {
            secondary_deserialize_STEERING_ANGLE(
                (secondary_message_STEERING_ANGLE*) &(*devices)[secondary_INDEX_STEERING_ANGLE].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 1: {
            secondary_deserialize_TPMS(
                (secondary_message_TPMS*) &(*devices)[secondary_INDEX_TPMS].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
    }
}

#endif // secondary_NETWORK_IMPLEMENTATION

#ifdef __cplusplus
}
#endif

#endif // secondary_NETWORK_H