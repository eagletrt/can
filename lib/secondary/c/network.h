#ifndef secondary_NETWORK_H
#define secondary_NETWORK_H

#ifdef __cplusplus
extern "C" {
#endif

#include <stdbool.h>
#include <assert.h>
#include <stdint.h>
#include <string.h>
#include <stdlib.h>
#include <memory.h>
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

#endif // CANLIB_SHARED

#ifndef CANLIB_SEPARATOR
#define CANLIB_SEPARATOR ","
#endif // CANLIB_SEPARATOR

// Info

#define secondary_NUMBER_OF_MESSAGES 21

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
#else
#define secondary_float32_to_bytes(float, index) ({(secondary_float32_helper)secondary_float32_helper.value = (f)}.bytes[(index)])
#endif

typedef struct {
    uint16_t id;
    void* raw_message;
    void* message;
} secondary_devices[secondary_NUMBER_OF_MESSAGES];

// ============== FREQUENCIES ============== //


#define secondary_IMU_ANGULAR_RATE_FREQUENCY -1
#define secondary_IMU_ACCELERATION_FREQUENCY -1
#define secondary_IRTS_FL_0_FREQUENCY -1
#define secondary_IRTS_FL_1_FREQUENCY -1
#define secondary_IRTS_FL_2_FREQUENCY -1
#define secondary_IRTS_FL_3_FREQUENCY -1
#define secondary_IRTS_FR_0_FREQUENCY -1
#define secondary_IRTS_FR_1_FREQUENCY -1
#define secondary_IRTS_FR_2_FREQUENCY -1
#define secondary_IRTS_FR_3_FREQUENCY -1
#define secondary_IRTS_RL_0_FREQUENCY -1
#define secondary_IRTS_RL_1_FREQUENCY -1
#define secondary_IRTS_RL_2_FREQUENCY -1
#define secondary_IRTS_RL_3_FREQUENCY -1
#define secondary_IRTS_RR_0_FREQUENCY -1
#define secondary_IRTS_RR_1_FREQUENCY -1
#define secondary_IRTS_RR_2_FREQUENCY -1
#define secondary_IRTS_RR_3_FREQUENCY -1
#define secondary_GPS_COORDS_FREQUENCY -1
#define secondary_GPS_SPEED_FREQUENCY -1
#define secondary_LAP_COUNT_FREQUENCY -1

// ============== SIZES ============== //


#define secondary_IMU_ANGULAR_RATE_SIZE 6
#define secondary_IMU_ACCELERATION_SIZE 6
#define secondary_IRTS_FL_0_SIZE 8
#define secondary_IRTS_FL_1_SIZE 8
#define secondary_IRTS_FL_2_SIZE 8
#define secondary_IRTS_FL_3_SIZE 8
#define secondary_IRTS_FR_0_SIZE 8
#define secondary_IRTS_FR_1_SIZE 8
#define secondary_IRTS_FR_2_SIZE 8
#define secondary_IRTS_FR_3_SIZE 8
#define secondary_IRTS_RL_0_SIZE 8
#define secondary_IRTS_RL_1_SIZE 8
#define secondary_IRTS_RL_2_SIZE 8
#define secondary_IRTS_RL_3_SIZE 8
#define secondary_IRTS_RR_0_SIZE 8
#define secondary_IRTS_RR_1_SIZE 8
#define secondary_IRTS_RR_2_SIZE 8
#define secondary_IRTS_RR_3_SIZE 8
#define secondary_GPS_COORDS_SIZE 8
#define secondary_GPS_SPEED_SIZE 2
#define secondary_LAP_COUNT_SIZE 5

// ============== BIT SETS ============== //



// ============== ENUMS ============== //



// Structs



typedef struct __CANLIB_PACKED {
    secondary_uint16 ang_rate_x;
    secondary_uint16 ang_rate_y;
    secondary_uint16 ang_rate_z;
#ifdef CANLIB_TIMESTAMP
    secondary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} secondary_message_IMU_ANGULAR_RATE;


typedef struct __CANLIB_PACKED {
    secondary_uint16 accel_x;
    secondary_uint16 accel_y;
    secondary_uint16 accel_z;
#ifdef CANLIB_TIMESTAMP
    secondary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} secondary_message_IMU_ACCELERATION;


typedef struct __CANLIB_PACKED {
    secondary_uint16 channel1;
    secondary_uint16 channel2;
    secondary_uint16 channel3;
    secondary_uint16 channel4;
#ifdef CANLIB_TIMESTAMP
    secondary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} secondary_message_IRTS_FL_0;


typedef struct __CANLIB_PACKED {
    secondary_uint16 channel5;
    secondary_uint16 channel6;
    secondary_uint16 channel7;
    secondary_uint16 channel8;
#ifdef CANLIB_TIMESTAMP
    secondary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} secondary_message_IRTS_FL_1;


typedef struct __CANLIB_PACKED {
    secondary_uint16 channel9;
    secondary_uint16 channel10;
    secondary_uint16 channel11;
    secondary_uint16 channel12;
#ifdef CANLIB_TIMESTAMP
    secondary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} secondary_message_IRTS_FL_2;


typedef struct __CANLIB_PACKED {
    secondary_uint16 channel13;
    secondary_uint16 channel14;
    secondary_uint16 channel15;
    secondary_uint16 channel16;
#ifdef CANLIB_TIMESTAMP
    secondary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} secondary_message_IRTS_FL_3;


typedef struct __CANLIB_PACKED {
    secondary_uint16 channel1;
    secondary_uint16 channel2;
    secondary_uint16 channel3;
    secondary_uint16 channel4;
#ifdef CANLIB_TIMESTAMP
    secondary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} secondary_message_IRTS_FR_0;


typedef struct __CANLIB_PACKED {
    secondary_uint16 channel5;
    secondary_uint16 channel6;
    secondary_uint16 channel7;
    secondary_uint16 channel8;
#ifdef CANLIB_TIMESTAMP
    secondary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} secondary_message_IRTS_FR_1;


typedef struct __CANLIB_PACKED {
    secondary_uint16 channel9;
    secondary_uint16 channel10;
    secondary_uint16 channel11;
    secondary_uint16 channel12;
#ifdef CANLIB_TIMESTAMP
    secondary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} secondary_message_IRTS_FR_2;


typedef struct __CANLIB_PACKED {
    secondary_uint16 channel13;
    secondary_uint16 channel14;
    secondary_uint16 channel15;
    secondary_uint16 channel16;
#ifdef CANLIB_TIMESTAMP
    secondary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} secondary_message_IRTS_FR_3;


typedef struct __CANLIB_PACKED {
    secondary_uint16 channel1;
    secondary_uint16 channel2;
    secondary_uint16 channel3;
    secondary_uint16 channel4;
#ifdef CANLIB_TIMESTAMP
    secondary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} secondary_message_IRTS_RL_0;


typedef struct __CANLIB_PACKED {
    secondary_uint16 channel5;
    secondary_uint16 channel6;
    secondary_uint16 channel7;
    secondary_uint16 channel8;
#ifdef CANLIB_TIMESTAMP
    secondary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} secondary_message_IRTS_RL_1;


typedef struct __CANLIB_PACKED {
    secondary_uint16 channel9;
    secondary_uint16 channel10;
    secondary_uint16 channel11;
    secondary_uint16 channel12;
#ifdef CANLIB_TIMESTAMP
    secondary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} secondary_message_IRTS_RL_2;


typedef struct __CANLIB_PACKED {
    secondary_uint16 channel13;
    secondary_uint16 channel14;
    secondary_uint16 channel15;
    secondary_uint16 channel16;
#ifdef CANLIB_TIMESTAMP
    secondary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} secondary_message_IRTS_RL_3;


typedef struct __CANLIB_PACKED {
    secondary_uint16 channel1;
    secondary_uint16 channel2;
    secondary_uint16 channel3;
    secondary_uint16 channel4;
#ifdef CANLIB_TIMESTAMP
    secondary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} secondary_message_IRTS_RR_0;


typedef struct __CANLIB_PACKED {
    secondary_uint16 channel5;
    secondary_uint16 channel6;
    secondary_uint16 channel7;
    secondary_uint16 channel8;
#ifdef CANLIB_TIMESTAMP
    secondary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} secondary_message_IRTS_RR_1;


typedef struct __CANLIB_PACKED {
    secondary_uint16 channel9;
    secondary_uint16 channel10;
    secondary_uint16 channel11;
    secondary_uint16 channel12;
#ifdef CANLIB_TIMESTAMP
    secondary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} secondary_message_IRTS_RR_2;


typedef struct __CANLIB_PACKED {
    secondary_uint16 channel13;
    secondary_uint16 channel14;
    secondary_uint16 channel15;
    secondary_uint16 channel16;
#ifdef CANLIB_TIMESTAMP
    secondary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} secondary_message_IRTS_RR_3;


typedef struct __CANLIB_PACKED {
    secondary_float32 latitude;
    secondary_float32 longitude;
#ifdef CANLIB_TIMESTAMP
    secondary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} secondary_message_GPS_COORDS;


typedef struct __CANLIB_PACKED {
    secondary_uint16 speed;
#ifdef CANLIB_TIMESTAMP
    secondary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} secondary_message_GPS_SPEED;


typedef struct __CANLIB_PACKED {
    secondary_uint32 timestamp;
    secondary_uint8 lap_count;
#ifdef CANLIB_TIMESTAMP
    secondary_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} secondary_message_LAP_COUNT;



// ============== IMU_ANGULAR_RATE ============== //

void secondary_serialize_IMU_ANGULAR_RATE(
    uint8_t* data,
    secondary_uint16 ang_rate_x,
    secondary_uint16 ang_rate_y,
    secondary_uint16 ang_rate_z
);
void secondary_serialize_struct_IMU_ANGULAR_RATE(
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
void secondary_to_string_IMU_ANGULAR_RATE(secondary_message_IMU_ANGULAR_RATE* message, char* buffer);
void secondary_fields_IMU_ANGULAR_RATE(char* buffer);
void secondary_to_string_file_IMU_ANGULAR_RATE(secondary_message_IMU_ANGULAR_RATE* message, FILE* buffer);
void secondary_fields_file_IMU_ANGULAR_RATE(FILE* buffer);


// ============== IMU_ACCELERATION ============== //

void secondary_serialize_IMU_ACCELERATION(
    uint8_t* data,
    secondary_uint16 accel_x,
    secondary_uint16 accel_y,
    secondary_uint16 accel_z
);
void secondary_serialize_struct_IMU_ACCELERATION(
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
void secondary_to_string_IMU_ACCELERATION(secondary_message_IMU_ACCELERATION* message, char* buffer);
void secondary_fields_IMU_ACCELERATION(char* buffer);
void secondary_to_string_file_IMU_ACCELERATION(secondary_message_IMU_ACCELERATION* message, FILE* buffer);
void secondary_fields_file_IMU_ACCELERATION(FILE* buffer);


// ============== IRTS_FL_0 ============== //

void secondary_serialize_IRTS_FL_0(
    uint8_t* data,
    secondary_uint16 channel1,
    secondary_uint16 channel2,
    secondary_uint16 channel3,
    secondary_uint16 channel4
);
void secondary_serialize_struct_IRTS_FL_0(
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
void secondary_to_string_IRTS_FL_0(secondary_message_IRTS_FL_0* message, char* buffer);
void secondary_fields_IRTS_FL_0(char* buffer);
void secondary_to_string_file_IRTS_FL_0(secondary_message_IRTS_FL_0* message, FILE* buffer);
void secondary_fields_file_IRTS_FL_0(FILE* buffer);


// ============== IRTS_FL_1 ============== //

void secondary_serialize_IRTS_FL_1(
    uint8_t* data,
    secondary_uint16 channel5,
    secondary_uint16 channel6,
    secondary_uint16 channel7,
    secondary_uint16 channel8
);
void secondary_serialize_struct_IRTS_FL_1(
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
void secondary_to_string_IRTS_FL_1(secondary_message_IRTS_FL_1* message, char* buffer);
void secondary_fields_IRTS_FL_1(char* buffer);
void secondary_to_string_file_IRTS_FL_1(secondary_message_IRTS_FL_1* message, FILE* buffer);
void secondary_fields_file_IRTS_FL_1(FILE* buffer);


// ============== IRTS_FL_2 ============== //

void secondary_serialize_IRTS_FL_2(
    uint8_t* data,
    secondary_uint16 channel9,
    secondary_uint16 channel10,
    secondary_uint16 channel11,
    secondary_uint16 channel12
);
void secondary_serialize_struct_IRTS_FL_2(
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
void secondary_to_string_IRTS_FL_2(secondary_message_IRTS_FL_2* message, char* buffer);
void secondary_fields_IRTS_FL_2(char* buffer);
void secondary_to_string_file_IRTS_FL_2(secondary_message_IRTS_FL_2* message, FILE* buffer);
void secondary_fields_file_IRTS_FL_2(FILE* buffer);


// ============== IRTS_FL_3 ============== //

void secondary_serialize_IRTS_FL_3(
    uint8_t* data,
    secondary_uint16 channel13,
    secondary_uint16 channel14,
    secondary_uint16 channel15,
    secondary_uint16 channel16
);
void secondary_serialize_struct_IRTS_FL_3(
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
void secondary_to_string_IRTS_FL_3(secondary_message_IRTS_FL_3* message, char* buffer);
void secondary_fields_IRTS_FL_3(char* buffer);
void secondary_to_string_file_IRTS_FL_3(secondary_message_IRTS_FL_3* message, FILE* buffer);
void secondary_fields_file_IRTS_FL_3(FILE* buffer);


// ============== IRTS_FR_0 ============== //

void secondary_serialize_IRTS_FR_0(
    uint8_t* data,
    secondary_uint16 channel1,
    secondary_uint16 channel2,
    secondary_uint16 channel3,
    secondary_uint16 channel4
);
void secondary_serialize_struct_IRTS_FR_0(
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
void secondary_to_string_IRTS_FR_0(secondary_message_IRTS_FR_0* message, char* buffer);
void secondary_fields_IRTS_FR_0(char* buffer);
void secondary_to_string_file_IRTS_FR_0(secondary_message_IRTS_FR_0* message, FILE* buffer);
void secondary_fields_file_IRTS_FR_0(FILE* buffer);


// ============== IRTS_FR_1 ============== //

void secondary_serialize_IRTS_FR_1(
    uint8_t* data,
    secondary_uint16 channel5,
    secondary_uint16 channel6,
    secondary_uint16 channel7,
    secondary_uint16 channel8
);
void secondary_serialize_struct_IRTS_FR_1(
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
void secondary_to_string_IRTS_FR_1(secondary_message_IRTS_FR_1* message, char* buffer);
void secondary_fields_IRTS_FR_1(char* buffer);
void secondary_to_string_file_IRTS_FR_1(secondary_message_IRTS_FR_1* message, FILE* buffer);
void secondary_fields_file_IRTS_FR_1(FILE* buffer);


// ============== IRTS_FR_2 ============== //

void secondary_serialize_IRTS_FR_2(
    uint8_t* data,
    secondary_uint16 channel9,
    secondary_uint16 channel10,
    secondary_uint16 channel11,
    secondary_uint16 channel12
);
void secondary_serialize_struct_IRTS_FR_2(
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
void secondary_to_string_IRTS_FR_2(secondary_message_IRTS_FR_2* message, char* buffer);
void secondary_fields_IRTS_FR_2(char* buffer);
void secondary_to_string_file_IRTS_FR_2(secondary_message_IRTS_FR_2* message, FILE* buffer);
void secondary_fields_file_IRTS_FR_2(FILE* buffer);


// ============== IRTS_FR_3 ============== //

void secondary_serialize_IRTS_FR_3(
    uint8_t* data,
    secondary_uint16 channel13,
    secondary_uint16 channel14,
    secondary_uint16 channel15,
    secondary_uint16 channel16
);
void secondary_serialize_struct_IRTS_FR_3(
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
void secondary_to_string_IRTS_FR_3(secondary_message_IRTS_FR_3* message, char* buffer);
void secondary_fields_IRTS_FR_3(char* buffer);
void secondary_to_string_file_IRTS_FR_3(secondary_message_IRTS_FR_3* message, FILE* buffer);
void secondary_fields_file_IRTS_FR_3(FILE* buffer);


// ============== IRTS_RL_0 ============== //

void secondary_serialize_IRTS_RL_0(
    uint8_t* data,
    secondary_uint16 channel1,
    secondary_uint16 channel2,
    secondary_uint16 channel3,
    secondary_uint16 channel4
);
void secondary_serialize_struct_IRTS_RL_0(
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
void secondary_to_string_IRTS_RL_0(secondary_message_IRTS_RL_0* message, char* buffer);
void secondary_fields_IRTS_RL_0(char* buffer);
void secondary_to_string_file_IRTS_RL_0(secondary_message_IRTS_RL_0* message, FILE* buffer);
void secondary_fields_file_IRTS_RL_0(FILE* buffer);


// ============== IRTS_RL_1 ============== //

void secondary_serialize_IRTS_RL_1(
    uint8_t* data,
    secondary_uint16 channel5,
    secondary_uint16 channel6,
    secondary_uint16 channel7,
    secondary_uint16 channel8
);
void secondary_serialize_struct_IRTS_RL_1(
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
void secondary_to_string_IRTS_RL_1(secondary_message_IRTS_RL_1* message, char* buffer);
void secondary_fields_IRTS_RL_1(char* buffer);
void secondary_to_string_file_IRTS_RL_1(secondary_message_IRTS_RL_1* message, FILE* buffer);
void secondary_fields_file_IRTS_RL_1(FILE* buffer);


// ============== IRTS_RL_2 ============== //

void secondary_serialize_IRTS_RL_2(
    uint8_t* data,
    secondary_uint16 channel9,
    secondary_uint16 channel10,
    secondary_uint16 channel11,
    secondary_uint16 channel12
);
void secondary_serialize_struct_IRTS_RL_2(
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
void secondary_to_string_IRTS_RL_2(secondary_message_IRTS_RL_2* message, char* buffer);
void secondary_fields_IRTS_RL_2(char* buffer);
void secondary_to_string_file_IRTS_RL_2(secondary_message_IRTS_RL_2* message, FILE* buffer);
void secondary_fields_file_IRTS_RL_2(FILE* buffer);


// ============== IRTS_RL_3 ============== //

void secondary_serialize_IRTS_RL_3(
    uint8_t* data,
    secondary_uint16 channel13,
    secondary_uint16 channel14,
    secondary_uint16 channel15,
    secondary_uint16 channel16
);
void secondary_serialize_struct_IRTS_RL_3(
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
void secondary_to_string_IRTS_RL_3(secondary_message_IRTS_RL_3* message, char* buffer);
void secondary_fields_IRTS_RL_3(char* buffer);
void secondary_to_string_file_IRTS_RL_3(secondary_message_IRTS_RL_3* message, FILE* buffer);
void secondary_fields_file_IRTS_RL_3(FILE* buffer);


// ============== IRTS_RR_0 ============== //

void secondary_serialize_IRTS_RR_0(
    uint8_t* data,
    secondary_uint16 channel1,
    secondary_uint16 channel2,
    secondary_uint16 channel3,
    secondary_uint16 channel4
);
void secondary_serialize_struct_IRTS_RR_0(
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
void secondary_to_string_IRTS_RR_0(secondary_message_IRTS_RR_0* message, char* buffer);
void secondary_fields_IRTS_RR_0(char* buffer);
void secondary_to_string_file_IRTS_RR_0(secondary_message_IRTS_RR_0* message, FILE* buffer);
void secondary_fields_file_IRTS_RR_0(FILE* buffer);


// ============== IRTS_RR_1 ============== //

void secondary_serialize_IRTS_RR_1(
    uint8_t* data,
    secondary_uint16 channel5,
    secondary_uint16 channel6,
    secondary_uint16 channel7,
    secondary_uint16 channel8
);
void secondary_serialize_struct_IRTS_RR_1(
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
void secondary_to_string_IRTS_RR_1(secondary_message_IRTS_RR_1* message, char* buffer);
void secondary_fields_IRTS_RR_1(char* buffer);
void secondary_to_string_file_IRTS_RR_1(secondary_message_IRTS_RR_1* message, FILE* buffer);
void secondary_fields_file_IRTS_RR_1(FILE* buffer);


// ============== IRTS_RR_2 ============== //

void secondary_serialize_IRTS_RR_2(
    uint8_t* data,
    secondary_uint16 channel9,
    secondary_uint16 channel10,
    secondary_uint16 channel11,
    secondary_uint16 channel12
);
void secondary_serialize_struct_IRTS_RR_2(
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
void secondary_to_string_IRTS_RR_2(secondary_message_IRTS_RR_2* message, char* buffer);
void secondary_fields_IRTS_RR_2(char* buffer);
void secondary_to_string_file_IRTS_RR_2(secondary_message_IRTS_RR_2* message, FILE* buffer);
void secondary_fields_file_IRTS_RR_2(FILE* buffer);


// ============== IRTS_RR_3 ============== //

void secondary_serialize_IRTS_RR_3(
    uint8_t* data,
    secondary_uint16 channel13,
    secondary_uint16 channel14,
    secondary_uint16 channel15,
    secondary_uint16 channel16
);
void secondary_serialize_struct_IRTS_RR_3(
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
void secondary_to_string_IRTS_RR_3(secondary_message_IRTS_RR_3* message, char* buffer);
void secondary_fields_IRTS_RR_3(char* buffer);
void secondary_to_string_file_IRTS_RR_3(secondary_message_IRTS_RR_3* message, FILE* buffer);
void secondary_fields_file_IRTS_RR_3(FILE* buffer);


// ============== GPS_COORDS ============== //

void secondary_serialize_GPS_COORDS(
    uint8_t* data,
    secondary_float32 latitude,
    secondary_float32 longitude
);
void secondary_serialize_struct_GPS_COORDS(
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
void secondary_to_string_GPS_COORDS(secondary_message_GPS_COORDS* message, char* buffer);
void secondary_fields_GPS_COORDS(char* buffer);
void secondary_to_string_file_GPS_COORDS(secondary_message_GPS_COORDS* message, FILE* buffer);
void secondary_fields_file_GPS_COORDS(FILE* buffer);


// ============== GPS_SPEED ============== //

void secondary_serialize_GPS_SPEED(
    uint8_t* data,
    secondary_uint16 speed
);
void secondary_serialize_struct_GPS_SPEED(
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
void secondary_to_string_GPS_SPEED(secondary_message_GPS_SPEED* message, char* buffer);
void secondary_fields_GPS_SPEED(char* buffer);
void secondary_to_string_file_GPS_SPEED(secondary_message_GPS_SPEED* message, FILE* buffer);
void secondary_fields_file_GPS_SPEED(FILE* buffer);


// ============== LAP_COUNT ============== //

void secondary_serialize_LAP_COUNT(
    uint8_t* data,
    secondary_uint32 timestamp,
    secondary_uint8 lap_count
);
void secondary_serialize_struct_LAP_COUNT(
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
void secondary_to_string_LAP_COUNT(secondary_message_LAP_COUNT* message, char* buffer);
void secondary_fields_LAP_COUNT(char* buffer);
void secondary_to_string_file_LAP_COUNT(secondary_message_LAP_COUNT* message, FILE* buffer);
void secondary_fields_file_LAP_COUNT(FILE* buffer);




// ============== UTILS ============== //

bool secondary_is_message_id(uint16_t message_id);
void secondary_devices_new(secondary_devices* map);
int secondary_devices_index_from_id(uint16_t message_id, secondary_devices* map);
void secondary_fields_from_id(uint16_t message_id, FILE *buffer);
void secondary_string_from_id(uint16_t message_id, void* message, FILE *buffer);
void secondary_deserialize_from_id(
    uint16_t message_id,
    uint8_t* data,
    void* raw_message,
    void* message
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);


#ifdef secondary_IMPLEMENTATION
// ============== SERIALIZE ============== //

void secondary_serialize_IMU_ANGULAR_RATE(
    uint8_t* data,
    secondary_uint16 ang_rate_x,
    secondary_uint16 ang_rate_y,
    secondary_uint16 ang_rate_z
) {
    data[0] = ang_rate_x & 255;
    data[1] = (ang_rate_x >> 8) & 255;
    data[2] = ang_rate_y & 255;
    data[3] = (ang_rate_y >> 8) & 255;
    data[4] = ang_rate_z & 255;
    data[5] = (ang_rate_z >> 8) & 255;
}
void secondary_serialize_struct_IMU_ANGULAR_RATE(
    uint8_t* data,
    secondary_message_IMU_ANGULAR_RATE* message
) {
    data[0] = message->ang_rate_x & 255;
    data[1] = (message->ang_rate_x >> 8) & 255;
    data[2] = message->ang_rate_y & 255;
    data[3] = (message->ang_rate_y >> 8) & 255;
    data[4] = message->ang_rate_z & 255;
    data[5] = (message->ang_rate_z >> 8) & 255;
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
    message->ang_rate_x = data[0] | (data[1] << 8);
    message->ang_rate_y = data[2] | (data[3] << 8);
    message->ang_rate_z = data[4] | (data[5] << 8);
}

// ============== STRING ============== //

void secondary_to_string_IMU_ANGULAR_RATE(secondary_message_IMU_ANGULAR_RATE* message, char* buffer) {
    sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%ju" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u",
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->ang_rate_x,
        message->ang_rate_y,
        message->ang_rate_z
    );
}
void secondary_fields_IMU_ANGULAR_RATE(char* buffer) {
    sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "ang_rate_x" CANLIB_SEPARATOR 
        "ang_rate_y" CANLIB_SEPARATOR 
        "ang_rate_z"
    );
}
void secondary_to_string_file_IMU_ANGULAR_RATE(secondary_message_IMU_ANGULAR_RATE* message, FILE* buffer) {
    fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%ju" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u",
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->ang_rate_x,
        message->ang_rate_y,
        message->ang_rate_z
    );
}
void secondary_fields_file_IMU_ANGULAR_RATE(FILE* buffer) {
    fprintf(
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

void secondary_serialize_IMU_ACCELERATION(
    uint8_t* data,
    secondary_uint16 accel_x,
    secondary_uint16 accel_y,
    secondary_uint16 accel_z
) {
    data[0] = accel_x & 255;
    data[1] = (accel_x >> 8) & 255;
    data[2] = accel_y & 255;
    data[3] = (accel_y >> 8) & 255;
    data[4] = accel_z & 255;
    data[5] = (accel_z >> 8) & 255;
}
void secondary_serialize_struct_IMU_ACCELERATION(
    uint8_t* data,
    secondary_message_IMU_ACCELERATION* message
) {
    data[0] = message->accel_x & 255;
    data[1] = (message->accel_x >> 8) & 255;
    data[2] = message->accel_y & 255;
    data[3] = (message->accel_y >> 8) & 255;
    data[4] = message->accel_z & 255;
    data[5] = (message->accel_z >> 8) & 255;
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
    message->accel_x = data[0] | (data[1] << 8);
    message->accel_y = data[2] | (data[3] << 8);
    message->accel_z = data[4] | (data[5] << 8);
}

// ============== STRING ============== //

void secondary_to_string_IMU_ACCELERATION(secondary_message_IMU_ACCELERATION* message, char* buffer) {
    sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%ju" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u",
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->accel_x,
        message->accel_y,
        message->accel_z
    );
}
void secondary_fields_IMU_ACCELERATION(char* buffer) {
    sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "accel_x" CANLIB_SEPARATOR 
        "accel_y" CANLIB_SEPARATOR 
        "accel_z"
    );
}
void secondary_to_string_file_IMU_ACCELERATION(secondary_message_IMU_ACCELERATION* message, FILE* buffer) {
    fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%ju" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u",
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->accel_x,
        message->accel_y,
        message->accel_z
    );
}
void secondary_fields_file_IMU_ACCELERATION(FILE* buffer) {
    fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "accel_x" CANLIB_SEPARATOR 
        "accel_y" CANLIB_SEPARATOR 
        "accel_z"
    );
}

// ============== SERIALIZE ============== //

void secondary_serialize_IRTS_FL_0(
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
}
void secondary_serialize_struct_IRTS_FL_0(
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

void secondary_to_string_IRTS_FL_0(secondary_message_IRTS_FL_0* message, char* buffer) {
    sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%ju" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u",
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->channel1,
        message->channel2,
        message->channel3,
        message->channel4
    );
}
void secondary_fields_IRTS_FL_0(char* buffer) {
    sprintf(
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
void secondary_to_string_file_IRTS_FL_0(secondary_message_IRTS_FL_0* message, FILE* buffer) {
    fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%ju" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u",
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->channel1,
        message->channel2,
        message->channel3,
        message->channel4
    );
}
void secondary_fields_file_IRTS_FL_0(FILE* buffer) {
    fprintf(
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

void secondary_serialize_IRTS_FL_1(
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
}
void secondary_serialize_struct_IRTS_FL_1(
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

void secondary_to_string_IRTS_FL_1(secondary_message_IRTS_FL_1* message, char* buffer) {
    sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%ju" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u",
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->channel5,
        message->channel6,
        message->channel7,
        message->channel8
    );
}
void secondary_fields_IRTS_FL_1(char* buffer) {
    sprintf(
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
void secondary_to_string_file_IRTS_FL_1(secondary_message_IRTS_FL_1* message, FILE* buffer) {
    fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%ju" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u",
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->channel5,
        message->channel6,
        message->channel7,
        message->channel8
    );
}
void secondary_fields_file_IRTS_FL_1(FILE* buffer) {
    fprintf(
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

void secondary_serialize_IRTS_FL_2(
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
}
void secondary_serialize_struct_IRTS_FL_2(
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

void secondary_to_string_IRTS_FL_2(secondary_message_IRTS_FL_2* message, char* buffer) {
    sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%ju" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u",
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->channel9,
        message->channel10,
        message->channel11,
        message->channel12
    );
}
void secondary_fields_IRTS_FL_2(char* buffer) {
    sprintf(
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
void secondary_to_string_file_IRTS_FL_2(secondary_message_IRTS_FL_2* message, FILE* buffer) {
    fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%ju" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u",
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->channel9,
        message->channel10,
        message->channel11,
        message->channel12
    );
}
void secondary_fields_file_IRTS_FL_2(FILE* buffer) {
    fprintf(
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

void secondary_serialize_IRTS_FL_3(
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
}
void secondary_serialize_struct_IRTS_FL_3(
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

void secondary_to_string_IRTS_FL_3(secondary_message_IRTS_FL_3* message, char* buffer) {
    sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%ju" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u",
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->channel13,
        message->channel14,
        message->channel15,
        message->channel16
    );
}
void secondary_fields_IRTS_FL_3(char* buffer) {
    sprintf(
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
void secondary_to_string_file_IRTS_FL_3(secondary_message_IRTS_FL_3* message, FILE* buffer) {
    fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%ju" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u",
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->channel13,
        message->channel14,
        message->channel15,
        message->channel16
    );
}
void secondary_fields_file_IRTS_FL_3(FILE* buffer) {
    fprintf(
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

void secondary_serialize_IRTS_FR_0(
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
}
void secondary_serialize_struct_IRTS_FR_0(
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

void secondary_to_string_IRTS_FR_0(secondary_message_IRTS_FR_0* message, char* buffer) {
    sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%ju" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u",
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->channel1,
        message->channel2,
        message->channel3,
        message->channel4
    );
}
void secondary_fields_IRTS_FR_0(char* buffer) {
    sprintf(
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
void secondary_to_string_file_IRTS_FR_0(secondary_message_IRTS_FR_0* message, FILE* buffer) {
    fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%ju" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u",
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->channel1,
        message->channel2,
        message->channel3,
        message->channel4
    );
}
void secondary_fields_file_IRTS_FR_0(FILE* buffer) {
    fprintf(
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

void secondary_serialize_IRTS_FR_1(
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
}
void secondary_serialize_struct_IRTS_FR_1(
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

void secondary_to_string_IRTS_FR_1(secondary_message_IRTS_FR_1* message, char* buffer) {
    sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%ju" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u",
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->channel5,
        message->channel6,
        message->channel7,
        message->channel8
    );
}
void secondary_fields_IRTS_FR_1(char* buffer) {
    sprintf(
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
void secondary_to_string_file_IRTS_FR_1(secondary_message_IRTS_FR_1* message, FILE* buffer) {
    fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%ju" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u",
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->channel5,
        message->channel6,
        message->channel7,
        message->channel8
    );
}
void secondary_fields_file_IRTS_FR_1(FILE* buffer) {
    fprintf(
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

void secondary_serialize_IRTS_FR_2(
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
}
void secondary_serialize_struct_IRTS_FR_2(
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

void secondary_to_string_IRTS_FR_2(secondary_message_IRTS_FR_2* message, char* buffer) {
    sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%ju" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u",
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->channel9,
        message->channel10,
        message->channel11,
        message->channel12
    );
}
void secondary_fields_IRTS_FR_2(char* buffer) {
    sprintf(
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
void secondary_to_string_file_IRTS_FR_2(secondary_message_IRTS_FR_2* message, FILE* buffer) {
    fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%ju" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u",
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->channel9,
        message->channel10,
        message->channel11,
        message->channel12
    );
}
void secondary_fields_file_IRTS_FR_2(FILE* buffer) {
    fprintf(
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

void secondary_serialize_IRTS_FR_3(
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
}
void secondary_serialize_struct_IRTS_FR_3(
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

void secondary_to_string_IRTS_FR_3(secondary_message_IRTS_FR_3* message, char* buffer) {
    sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%ju" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u",
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->channel13,
        message->channel14,
        message->channel15,
        message->channel16
    );
}
void secondary_fields_IRTS_FR_3(char* buffer) {
    sprintf(
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
void secondary_to_string_file_IRTS_FR_3(secondary_message_IRTS_FR_3* message, FILE* buffer) {
    fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%ju" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u",
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->channel13,
        message->channel14,
        message->channel15,
        message->channel16
    );
}
void secondary_fields_file_IRTS_FR_3(FILE* buffer) {
    fprintf(
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

void secondary_serialize_IRTS_RL_0(
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
}
void secondary_serialize_struct_IRTS_RL_0(
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

void secondary_to_string_IRTS_RL_0(secondary_message_IRTS_RL_0* message, char* buffer) {
    sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%ju" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u",
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->channel1,
        message->channel2,
        message->channel3,
        message->channel4
    );
}
void secondary_fields_IRTS_RL_0(char* buffer) {
    sprintf(
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
void secondary_to_string_file_IRTS_RL_0(secondary_message_IRTS_RL_0* message, FILE* buffer) {
    fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%ju" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u",
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->channel1,
        message->channel2,
        message->channel3,
        message->channel4
    );
}
void secondary_fields_file_IRTS_RL_0(FILE* buffer) {
    fprintf(
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

void secondary_serialize_IRTS_RL_1(
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
}
void secondary_serialize_struct_IRTS_RL_1(
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

void secondary_to_string_IRTS_RL_1(secondary_message_IRTS_RL_1* message, char* buffer) {
    sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%ju" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u",
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->channel5,
        message->channel6,
        message->channel7,
        message->channel8
    );
}
void secondary_fields_IRTS_RL_1(char* buffer) {
    sprintf(
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
void secondary_to_string_file_IRTS_RL_1(secondary_message_IRTS_RL_1* message, FILE* buffer) {
    fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%ju" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u",
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->channel5,
        message->channel6,
        message->channel7,
        message->channel8
    );
}
void secondary_fields_file_IRTS_RL_1(FILE* buffer) {
    fprintf(
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

void secondary_serialize_IRTS_RL_2(
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
}
void secondary_serialize_struct_IRTS_RL_2(
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

void secondary_to_string_IRTS_RL_2(secondary_message_IRTS_RL_2* message, char* buffer) {
    sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%ju" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u",
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->channel9,
        message->channel10,
        message->channel11,
        message->channel12
    );
}
void secondary_fields_IRTS_RL_2(char* buffer) {
    sprintf(
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
void secondary_to_string_file_IRTS_RL_2(secondary_message_IRTS_RL_2* message, FILE* buffer) {
    fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%ju" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u",
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->channel9,
        message->channel10,
        message->channel11,
        message->channel12
    );
}
void secondary_fields_file_IRTS_RL_2(FILE* buffer) {
    fprintf(
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

void secondary_serialize_IRTS_RL_3(
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
}
void secondary_serialize_struct_IRTS_RL_3(
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

void secondary_to_string_IRTS_RL_3(secondary_message_IRTS_RL_3* message, char* buffer) {
    sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%ju" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u",
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->channel13,
        message->channel14,
        message->channel15,
        message->channel16
    );
}
void secondary_fields_IRTS_RL_3(char* buffer) {
    sprintf(
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
void secondary_to_string_file_IRTS_RL_3(secondary_message_IRTS_RL_3* message, FILE* buffer) {
    fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%ju" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u",
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->channel13,
        message->channel14,
        message->channel15,
        message->channel16
    );
}
void secondary_fields_file_IRTS_RL_3(FILE* buffer) {
    fprintf(
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

void secondary_serialize_IRTS_RR_0(
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
}
void secondary_serialize_struct_IRTS_RR_0(
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

void secondary_to_string_IRTS_RR_0(secondary_message_IRTS_RR_0* message, char* buffer) {
    sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%ju" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u",
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->channel1,
        message->channel2,
        message->channel3,
        message->channel4
    );
}
void secondary_fields_IRTS_RR_0(char* buffer) {
    sprintf(
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
void secondary_to_string_file_IRTS_RR_0(secondary_message_IRTS_RR_0* message, FILE* buffer) {
    fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%ju" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u",
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->channel1,
        message->channel2,
        message->channel3,
        message->channel4
    );
}
void secondary_fields_file_IRTS_RR_0(FILE* buffer) {
    fprintf(
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

void secondary_serialize_IRTS_RR_1(
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
}
void secondary_serialize_struct_IRTS_RR_1(
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

void secondary_to_string_IRTS_RR_1(secondary_message_IRTS_RR_1* message, char* buffer) {
    sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%ju" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u",
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->channel5,
        message->channel6,
        message->channel7,
        message->channel8
    );
}
void secondary_fields_IRTS_RR_1(char* buffer) {
    sprintf(
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
void secondary_to_string_file_IRTS_RR_1(secondary_message_IRTS_RR_1* message, FILE* buffer) {
    fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%ju" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u",
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->channel5,
        message->channel6,
        message->channel7,
        message->channel8
    );
}
void secondary_fields_file_IRTS_RR_1(FILE* buffer) {
    fprintf(
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

void secondary_serialize_IRTS_RR_2(
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
}
void secondary_serialize_struct_IRTS_RR_2(
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

void secondary_to_string_IRTS_RR_2(secondary_message_IRTS_RR_2* message, char* buffer) {
    sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%ju" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u",
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->channel9,
        message->channel10,
        message->channel11,
        message->channel12
    );
}
void secondary_fields_IRTS_RR_2(char* buffer) {
    sprintf(
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
void secondary_to_string_file_IRTS_RR_2(secondary_message_IRTS_RR_2* message, FILE* buffer) {
    fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%ju" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u",
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->channel9,
        message->channel10,
        message->channel11,
        message->channel12
    );
}
void secondary_fields_file_IRTS_RR_2(FILE* buffer) {
    fprintf(
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

void secondary_serialize_IRTS_RR_3(
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
}
void secondary_serialize_struct_IRTS_RR_3(
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

void secondary_to_string_IRTS_RR_3(secondary_message_IRTS_RR_3* message, char* buffer) {
    sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%ju" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u",
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->channel13,
        message->channel14,
        message->channel15,
        message->channel16
    );
}
void secondary_fields_IRTS_RR_3(char* buffer) {
    sprintf(
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
void secondary_to_string_file_IRTS_RR_3(secondary_message_IRTS_RR_3* message, FILE* buffer) {
    fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%ju" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u",
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->channel13,
        message->channel14,
        message->channel15,
        message->channel16
    );
}
void secondary_fields_file_IRTS_RR_3(FILE* buffer) {
    fprintf(
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

void secondary_serialize_GPS_COORDS(
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
}
void secondary_serialize_struct_GPS_COORDS(
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
    message->latitude = ((secondary_float32_helper) {data[0] ,data[1] ,data[2] ,data[3]}).value;
    message->longitude = ((secondary_float32_helper) {data[4] ,data[5] ,data[6] ,data[7]}).value;
}

// ============== STRING ============== //

void secondary_to_string_GPS_COORDS(secondary_message_GPS_COORDS* message, char* buffer) {
    sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%ju" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%f" CANLIB_SEPARATOR 
        "%f",
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->latitude,
        message->longitude
    );
}
void secondary_fields_GPS_COORDS(char* buffer) {
    sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "latitude" CANLIB_SEPARATOR 
        "longitude"
    );
}
void secondary_to_string_file_GPS_COORDS(secondary_message_GPS_COORDS* message, FILE* buffer) {
    fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%ju" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%f" CANLIB_SEPARATOR 
        "%f",
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->latitude,
        message->longitude
    );
}
void secondary_fields_file_GPS_COORDS(FILE* buffer) {
    fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "latitude" CANLIB_SEPARATOR 
        "longitude"
    );
}

// ============== SERIALIZE ============== //

void secondary_serialize_GPS_SPEED(
    uint8_t* data,
    secondary_uint16 speed
) {
    data[0] = speed & 255;
    data[1] = (speed >> 8) & 255;
}
void secondary_serialize_struct_GPS_SPEED(
    uint8_t* data,
    secondary_message_GPS_SPEED* message
) {
    data[0] = message->speed & 255;
    data[1] = (message->speed >> 8) & 255;
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

void secondary_to_string_GPS_SPEED(secondary_message_GPS_SPEED* message, char* buffer) {
    sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%ju" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%u",
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->speed
    );
}
void secondary_fields_GPS_SPEED(char* buffer) {
    sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "speed"
    );
}
void secondary_to_string_file_GPS_SPEED(secondary_message_GPS_SPEED* message, FILE* buffer) {
    fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%ju" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%u",
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->speed
    );
}
void secondary_fields_file_GPS_SPEED(FILE* buffer) {
    fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "speed"
    );
}

// ============== SERIALIZE ============== //

void secondary_serialize_LAP_COUNT(
    uint8_t* data,
    secondary_uint32 timestamp,
    secondary_uint8 lap_count
) {
    data[0] = timestamp & 255;
    data[1] = (timestamp >> 8) & 255;
    data[2] = (timestamp >> 16) & 255;
    data[3] = (timestamp >> 24) & 255;
    data[4] = lap_count;
}
void secondary_serialize_struct_LAP_COUNT(
    uint8_t* data,
    secondary_message_LAP_COUNT* message
) {
    data[0] = message->timestamp & 255;
    data[1] = (message->timestamp >> 8) & 255;
    data[2] = (message->timestamp >> 16) & 255;
    data[3] = (message->timestamp >> 24) & 255;
    data[4] = message->lap_count;
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
    message->timestamp = data[0] | (data[1] << 8) | (data[2] << 16) | (data[3] << 24);
    message->lap_count = data[4];
}

// ============== STRING ============== //

void secondary_to_string_LAP_COUNT(secondary_message_LAP_COUNT* message, char* buffer) {
    sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%ju" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%lu" CANLIB_SEPARATOR 
        "%u",
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->timestamp,
        message->lap_count
    );
}
void secondary_fields_LAP_COUNT(char* buffer) {
    sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "timestamp" CANLIB_SEPARATOR 
        "lap_count"
    );
}
void secondary_to_string_file_LAP_COUNT(secondary_message_LAP_COUNT* message, FILE* buffer) {
    fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%ju" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%lu" CANLIB_SEPARATOR 
        "%u",
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->timestamp,
        message->lap_count
    );
}
void secondary_fields_file_LAP_COUNT(FILE* buffer) {
    fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "timestamp" CANLIB_SEPARATOR 
        "lap_count"
    );
}


// ============== UTILS ============== //

void secondary_fields_from_id(uint16_t message_id, FILE *buffer) {
    switch (message_id) {
    case 1260:
        secondary_fields_file_IMU_ANGULAR_RATE(buffer);
        break;
    case 1261:
        secondary_fields_file_IMU_ACCELERATION(buffer);
        break;
    case 1460:
        secondary_fields_file_IRTS_FL_0(buffer);
        break;
    case 1461:
        secondary_fields_file_IRTS_FL_1(buffer);
        break;
    case 1462:
        secondary_fields_file_IRTS_FL_2(buffer);
        break;
    case 1463:
        secondary_fields_file_IRTS_FL_3(buffer);
        break;
    case 1464:
        secondary_fields_file_IRTS_FR_0(buffer);
        break;
    case 1465:
        secondary_fields_file_IRTS_FR_1(buffer);
        break;
    case 1466:
        secondary_fields_file_IRTS_FR_2(buffer);
        break;
    case 1467:
        secondary_fields_file_IRTS_FR_3(buffer);
        break;
    case 1468:
        secondary_fields_file_IRTS_RL_0(buffer);
        break;
    case 1469:
        secondary_fields_file_IRTS_RL_1(buffer);
        break;
    case 1470:
        secondary_fields_file_IRTS_RL_2(buffer);
        break;
    case 1471:
        secondary_fields_file_IRTS_RL_3(buffer);
        break;
    case 1472:
        secondary_fields_file_IRTS_RR_0(buffer);
        break;
    case 1473:
        secondary_fields_file_IRTS_RR_1(buffer);
        break;
    case 1474:
        secondary_fields_file_IRTS_RR_2(buffer);
        break;
    case 1475:
        secondary_fields_file_IRTS_RR_3(buffer);
        break;
    case 1025:
        secondary_fields_file_GPS_COORDS(buffer);
        break;
    case 1057:
        secondary_fields_file_GPS_SPEED(buffer);
        break;
    case 1089:
        secondary_fields_file_LAP_COUNT(buffer);
        break;
    }
}

void secondary_string_from_id(uint16_t message_id, void* message, FILE *buffer) {
    switch (message_id) {
        case 1260:
            secondary_to_string_file_IMU_ANGULAR_RATE((secondary_message_IMU_ANGULAR_RATE*) message, buffer);
        break;
        case 1261:
            secondary_to_string_file_IMU_ACCELERATION((secondary_message_IMU_ACCELERATION*) message, buffer);
        break;
        case 1460:
            secondary_to_string_file_IRTS_FL_0((secondary_message_IRTS_FL_0*) message, buffer);
        break;
        case 1461:
            secondary_to_string_file_IRTS_FL_1((secondary_message_IRTS_FL_1*) message, buffer);
        break;
        case 1462:
            secondary_to_string_file_IRTS_FL_2((secondary_message_IRTS_FL_2*) message, buffer);
        break;
        case 1463:
            secondary_to_string_file_IRTS_FL_3((secondary_message_IRTS_FL_3*) message, buffer);
        break;
        case 1464:
            secondary_to_string_file_IRTS_FR_0((secondary_message_IRTS_FR_0*) message, buffer);
        break;
        case 1465:
            secondary_to_string_file_IRTS_FR_1((secondary_message_IRTS_FR_1*) message, buffer);
        break;
        case 1466:
            secondary_to_string_file_IRTS_FR_2((secondary_message_IRTS_FR_2*) message, buffer);
        break;
        case 1467:
            secondary_to_string_file_IRTS_FR_3((secondary_message_IRTS_FR_3*) message, buffer);
        break;
        case 1468:
            secondary_to_string_file_IRTS_RL_0((secondary_message_IRTS_RL_0*) message, buffer);
        break;
        case 1469:
            secondary_to_string_file_IRTS_RL_1((secondary_message_IRTS_RL_1*) message, buffer);
        break;
        case 1470:
            secondary_to_string_file_IRTS_RL_2((secondary_message_IRTS_RL_2*) message, buffer);
        break;
        case 1471:
            secondary_to_string_file_IRTS_RL_3((secondary_message_IRTS_RL_3*) message, buffer);
        break;
        case 1472:
            secondary_to_string_file_IRTS_RR_0((secondary_message_IRTS_RR_0*) message, buffer);
        break;
        case 1473:
            secondary_to_string_file_IRTS_RR_1((secondary_message_IRTS_RR_1*) message, buffer);
        break;
        case 1474:
            secondary_to_string_file_IRTS_RR_2((secondary_message_IRTS_RR_2*) message, buffer);
        break;
        case 1475:
            secondary_to_string_file_IRTS_RR_3((secondary_message_IRTS_RR_3*) message, buffer);
        break;
        case 1025:
            secondary_to_string_file_GPS_COORDS((secondary_message_GPS_COORDS*) message, buffer);
        break;
        case 1057:
            secondary_to_string_file_GPS_SPEED((secondary_message_GPS_SPEED*) message, buffer);
        break;
        case 1089:
            secondary_to_string_file_LAP_COUNT((secondary_message_LAP_COUNT*) message, buffer);
        break;
    }
}

void secondary_deserialize_from_id(
    uint16_t message_id,
    uint8_t* data,
    void* raw_message,
    void* message
#ifdef CANLIB_TIMESTAMP
    , secondary_uint64 timestamp
#endif // CANLIB_TIMESTAMP
) {
    switch (message_id) {
        case 1260:
            secondary_deserialize_IMU_ANGULAR_RATE(
                (secondary_message_IMU_ANGULAR_RATE*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 1261:
            secondary_deserialize_IMU_ACCELERATION(
                (secondary_message_IMU_ACCELERATION*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 1460:
            secondary_deserialize_IRTS_FL_0(
                (secondary_message_IRTS_FL_0*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 1461:
            secondary_deserialize_IRTS_FL_1(
                (secondary_message_IRTS_FL_1*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 1462:
            secondary_deserialize_IRTS_FL_2(
                (secondary_message_IRTS_FL_2*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 1463:
            secondary_deserialize_IRTS_FL_3(
                (secondary_message_IRTS_FL_3*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 1464:
            secondary_deserialize_IRTS_FR_0(
                (secondary_message_IRTS_FR_0*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 1465:
            secondary_deserialize_IRTS_FR_1(
                (secondary_message_IRTS_FR_1*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 1466:
            secondary_deserialize_IRTS_FR_2(
                (secondary_message_IRTS_FR_2*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 1467:
            secondary_deserialize_IRTS_FR_3(
                (secondary_message_IRTS_FR_3*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 1468:
            secondary_deserialize_IRTS_RL_0(
                (secondary_message_IRTS_RL_0*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 1469:
            secondary_deserialize_IRTS_RL_1(
                (secondary_message_IRTS_RL_1*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 1470:
            secondary_deserialize_IRTS_RL_2(
                (secondary_message_IRTS_RL_2*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 1471:
            secondary_deserialize_IRTS_RL_3(
                (secondary_message_IRTS_RL_3*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 1472:
            secondary_deserialize_IRTS_RR_0(
                (secondary_message_IRTS_RR_0*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 1473:
            secondary_deserialize_IRTS_RR_1(
                (secondary_message_IRTS_RR_1*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 1474:
            secondary_deserialize_IRTS_RR_2(
                (secondary_message_IRTS_RR_2*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 1475:
            secondary_deserialize_IRTS_RR_3(
                (secondary_message_IRTS_RR_3*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 1025:
            secondary_deserialize_GPS_COORDS(
                (secondary_message_GPS_COORDS*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 1057:
            secondary_deserialize_GPS_SPEED(
                (secondary_message_GPS_SPEED*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 1089:
            secondary_deserialize_LAP_COUNT(
                (secondary_message_LAP_COUNT*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
    }
}

bool secondary_is_message_id(uint16_t message_id) {
    switch (message_id) {
        case 1260: return true; break;
        case 1261: return true; break;
        case 1460: return true; break;
        case 1461: return true; break;
        case 1462: return true; break;
        case 1463: return true; break;
        case 1464: return true; break;
        case 1465: return true; break;
        case 1466: return true; break;
        case 1467: return true; break;
        case 1468: return true; break;
        case 1469: return true; break;
        case 1470: return true; break;
        case 1471: return true; break;
        case 1472: return true; break;
        case 1473: return true; break;
        case 1474: return true; break;
        case 1475: return true; break;
        case 1025: return true; break;
        case 1057: return true; break;
        case 1089: return true; break;
    }
    return false;
}

void secondary_devices_new(secondary_devices* map) {
    (*map)[0].id = 1260;
    (*map)[0].raw_message = (void*) malloc(sizeof(secondary_message_IMU_ANGULAR_RATE));
    (*map)[0].message = NULL;

    (*map)[1].id = 1261;
    (*map)[1].raw_message = (void*) malloc(sizeof(secondary_message_IMU_ACCELERATION));
    (*map)[1].message = NULL;

    (*map)[2].id = 1460;
    (*map)[2].raw_message = (void*) malloc(sizeof(secondary_message_IRTS_FL_0));
    (*map)[2].message = NULL;

    (*map)[3].id = 1461;
    (*map)[3].raw_message = (void*) malloc(sizeof(secondary_message_IRTS_FL_1));
    (*map)[3].message = NULL;

    (*map)[4].id = 1462;
    (*map)[4].raw_message = (void*) malloc(sizeof(secondary_message_IRTS_FL_2));
    (*map)[4].message = NULL;

    (*map)[5].id = 1463;
    (*map)[5].raw_message = (void*) malloc(sizeof(secondary_message_IRTS_FL_3));
    (*map)[5].message = NULL;

    (*map)[6].id = 1464;
    (*map)[6].raw_message = (void*) malloc(sizeof(secondary_message_IRTS_FR_0));
    (*map)[6].message = NULL;

    (*map)[7].id = 1465;
    (*map)[7].raw_message = (void*) malloc(sizeof(secondary_message_IRTS_FR_1));
    (*map)[7].message = NULL;

    (*map)[8].id = 1466;
    (*map)[8].raw_message = (void*) malloc(sizeof(secondary_message_IRTS_FR_2));
    (*map)[8].message = NULL;

    (*map)[9].id = 1467;
    (*map)[9].raw_message = (void*) malloc(sizeof(secondary_message_IRTS_FR_3));
    (*map)[9].message = NULL;

    (*map)[10].id = 1468;
    (*map)[10].raw_message = (void*) malloc(sizeof(secondary_message_IRTS_RL_0));
    (*map)[10].message = NULL;

    (*map)[11].id = 1469;
    (*map)[11].raw_message = (void*) malloc(sizeof(secondary_message_IRTS_RL_1));
    (*map)[11].message = NULL;

    (*map)[12].id = 1470;
    (*map)[12].raw_message = (void*) malloc(sizeof(secondary_message_IRTS_RL_2));
    (*map)[12].message = NULL;

    (*map)[13].id = 1471;
    (*map)[13].raw_message = (void*) malloc(sizeof(secondary_message_IRTS_RL_3));
    (*map)[13].message = NULL;

    (*map)[14].id = 1472;
    (*map)[14].raw_message = (void*) malloc(sizeof(secondary_message_IRTS_RR_0));
    (*map)[14].message = NULL;

    (*map)[15].id = 1473;
    (*map)[15].raw_message = (void*) malloc(sizeof(secondary_message_IRTS_RR_1));
    (*map)[15].message = NULL;

    (*map)[16].id = 1474;
    (*map)[16].raw_message = (void*) malloc(sizeof(secondary_message_IRTS_RR_2));
    (*map)[16].message = NULL;

    (*map)[17].id = 1475;
    (*map)[17].raw_message = (void*) malloc(sizeof(secondary_message_IRTS_RR_3));
    (*map)[17].message = NULL;

    (*map)[18].id = 1025;
    (*map)[18].raw_message = (void*) malloc(sizeof(secondary_message_GPS_COORDS));
    (*map)[18].message = NULL;

    (*map)[19].id = 1057;
    (*map)[19].raw_message = (void*) malloc(sizeof(secondary_message_GPS_SPEED));
    (*map)[19].message = NULL;

    (*map)[20].id = 1089;
    (*map)[20].raw_message = (void*) malloc(sizeof(secondary_message_LAP_COUNT));
    (*map)[20].message = NULL;

}

int secondary_devices_index_from_id(uint16_t message_id, secondary_devices* map) {
    for (int index = 0; index < secondary_NUMBER_OF_MESSAGES; index++) {
        if ((*map)[index].id == message_id)
            return index;
    }
    return -1;
}

#endif

#ifdef __cplusplus
}
#endif

#endif // secondary_NETWORK_H