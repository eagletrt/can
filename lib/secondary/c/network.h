#ifndef secondary_NETWORK_H
#define secondary_NETWORK_H

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
    uint8_t bytes[4];
    secondary_float32 value;
} secondary_float32_helper;

typedef union {
    uint8_t bytes[8];
    secondary_float64 value;
} secondary_float64_helper;

// Frequencies


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

// Sizes


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

// Bitsets



// Enums



// Structs


typedef struct __CANLIB_PACKED {
    secondary_uint16 ang_rate_x;
    secondary_uint16 ang_rate_y;
    secondary_uint16 ang_rate_z;
} secondary_message_IMU_ANGULAR_RATE;

typedef struct __CANLIB_PACKED {
    secondary_uint16 accel_x;
    secondary_uint16 accel_y;
    secondary_uint16 accel_z;
} secondary_message_IMU_ACCELERATION;

typedef struct __CANLIB_PACKED {
    secondary_uint16 channel1;
    secondary_uint16 channel2;
    secondary_uint16 channel3;
    secondary_uint16 channel4;
} secondary_message_IRTS_FL_0;

typedef struct __CANLIB_PACKED {
    secondary_uint16 channel5;
    secondary_uint16 channel6;
    secondary_uint16 channel7;
    secondary_uint16 channel8;
} secondary_message_IRTS_FL_1;

typedef struct __CANLIB_PACKED {
    secondary_uint16 channel9;
    secondary_uint16 channel10;
    secondary_uint16 channel11;
    secondary_uint16 channel12;
} secondary_message_IRTS_FL_2;

typedef struct __CANLIB_PACKED {
    secondary_uint16 channel13;
    secondary_uint16 channel14;
    secondary_uint16 channel15;
    secondary_uint16 channel16;
} secondary_message_IRTS_FL_3;

typedef struct __CANLIB_PACKED {
    secondary_uint16 channel1;
    secondary_uint16 channel2;
    secondary_uint16 channel3;
    secondary_uint16 channel4;
} secondary_message_IRTS_FR_0;

typedef struct __CANLIB_PACKED {
    secondary_uint16 channel5;
    secondary_uint16 channel6;
    secondary_uint16 channel7;
    secondary_uint16 channel8;
} secondary_message_IRTS_FR_1;

typedef struct __CANLIB_PACKED {
    secondary_uint16 channel9;
    secondary_uint16 channel10;
    secondary_uint16 channel11;
    secondary_uint16 channel12;
} secondary_message_IRTS_FR_2;

typedef struct __CANLIB_PACKED {
    secondary_uint16 channel13;
    secondary_uint16 channel14;
    secondary_uint16 channel15;
    secondary_uint16 channel16;
} secondary_message_IRTS_FR_3;

typedef struct __CANLIB_PACKED {
    secondary_uint16 channel1;
    secondary_uint16 channel2;
    secondary_uint16 channel3;
    secondary_uint16 channel4;
} secondary_message_IRTS_RL_0;

typedef struct __CANLIB_PACKED {
    secondary_uint16 channel5;
    secondary_uint16 channel6;
    secondary_uint16 channel7;
    secondary_uint16 channel8;
} secondary_message_IRTS_RL_1;

typedef struct __CANLIB_PACKED {
    secondary_uint16 channel9;
    secondary_uint16 channel10;
    secondary_uint16 channel11;
    secondary_uint16 channel12;
} secondary_message_IRTS_RL_2;

typedef struct __CANLIB_PACKED {
    secondary_uint16 channel13;
    secondary_uint16 channel14;
    secondary_uint16 channel15;
    secondary_uint16 channel16;
} secondary_message_IRTS_RL_3;

typedef struct __CANLIB_PACKED {
    secondary_uint16 channel1;
    secondary_uint16 channel2;
    secondary_uint16 channel3;
    secondary_uint16 channel4;
} secondary_message_IRTS_RR_0;

typedef struct __CANLIB_PACKED {
    secondary_uint16 channel5;
    secondary_uint16 channel6;
    secondary_uint16 channel7;
    secondary_uint16 channel8;
} secondary_message_IRTS_RR_1;

typedef struct __CANLIB_PACKED {
    secondary_uint16 channel9;
    secondary_uint16 channel10;
    secondary_uint16 channel11;
    secondary_uint16 channel12;
} secondary_message_IRTS_RR_2;

typedef struct __CANLIB_PACKED {
    secondary_uint16 channel13;
    secondary_uint16 channel14;
    secondary_uint16 channel15;
    secondary_uint16 channel16;
} secondary_message_IRTS_RR_3;

typedef struct __CANLIB_PACKED {
    secondary_float32 latitude;
    secondary_float32 longitude;
} secondary_message_GPS_COORDS;

typedef struct __CANLIB_PACKED {
    secondary_uint16 speed;
} secondary_message_GPS_SPEED;

typedef struct __CANLIB_PACKED {
    secondary_uint32 timestamp;
    secondary_uint8 lap_count;
} secondary_message_LAP_COUNT;


// Serialize and Deserialize


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

void secondary_deserialize_IMU_ANGULAR_RATE(secondary_message_IMU_ANGULAR_RATE* message, uint8_t* data) {
    message->ang_rate_x = data[0] | (data[1] << 8);
    message->ang_rate_y = data[2] | (data[3] << 8);
    message->ang_rate_z = data[4] | (data[5] << 8);
}

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

void secondary_deserialize_IMU_ACCELERATION(secondary_message_IMU_ACCELERATION* message, uint8_t* data) {
    message->accel_x = data[0] | (data[1] << 8);
    message->accel_y = data[2] | (data[3] << 8);
    message->accel_z = data[4] | (data[5] << 8);
}

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

void secondary_deserialize_IRTS_FL_0(secondary_message_IRTS_FL_0* message, uint8_t* data) {
    message->channel1 = data[0] | (data[1] << 8);
    message->channel2 = data[2] | (data[3] << 8);
    message->channel3 = data[4] | (data[5] << 8);
    message->channel4 = data[6] | (data[7] << 8);
}

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

void secondary_deserialize_IRTS_FL_1(secondary_message_IRTS_FL_1* message, uint8_t* data) {
    message->channel5 = data[0] | (data[1] << 8);
    message->channel6 = data[2] | (data[3] << 8);
    message->channel7 = data[4] | (data[5] << 8);
    message->channel8 = data[6] | (data[7] << 8);
}

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

void secondary_deserialize_IRTS_FL_2(secondary_message_IRTS_FL_2* message, uint8_t* data) {
    message->channel9 = data[0] | (data[1] << 8);
    message->channel10 = data[2] | (data[3] << 8);
    message->channel11 = data[4] | (data[5] << 8);
    message->channel12 = data[6] | (data[7] << 8);
}

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

void secondary_deserialize_IRTS_FL_3(secondary_message_IRTS_FL_3* message, uint8_t* data) {
    message->channel13 = data[0] | (data[1] << 8);
    message->channel14 = data[2] | (data[3] << 8);
    message->channel15 = data[4] | (data[5] << 8);
    message->channel16 = data[6] | (data[7] << 8);
}

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

void secondary_deserialize_IRTS_FR_0(secondary_message_IRTS_FR_0* message, uint8_t* data) {
    message->channel1 = data[0] | (data[1] << 8);
    message->channel2 = data[2] | (data[3] << 8);
    message->channel3 = data[4] | (data[5] << 8);
    message->channel4 = data[6] | (data[7] << 8);
}

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

void secondary_deserialize_IRTS_FR_1(secondary_message_IRTS_FR_1* message, uint8_t* data) {
    message->channel5 = data[0] | (data[1] << 8);
    message->channel6 = data[2] | (data[3] << 8);
    message->channel7 = data[4] | (data[5] << 8);
    message->channel8 = data[6] | (data[7] << 8);
}

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

void secondary_deserialize_IRTS_FR_2(secondary_message_IRTS_FR_2* message, uint8_t* data) {
    message->channel9 = data[0] | (data[1] << 8);
    message->channel10 = data[2] | (data[3] << 8);
    message->channel11 = data[4] | (data[5] << 8);
    message->channel12 = data[6] | (data[7] << 8);
}

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

void secondary_deserialize_IRTS_FR_3(secondary_message_IRTS_FR_3* message, uint8_t* data) {
    message->channel13 = data[0] | (data[1] << 8);
    message->channel14 = data[2] | (data[3] << 8);
    message->channel15 = data[4] | (data[5] << 8);
    message->channel16 = data[6] | (data[7] << 8);
}

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

void secondary_deserialize_IRTS_RL_0(secondary_message_IRTS_RL_0* message, uint8_t* data) {
    message->channel1 = data[0] | (data[1] << 8);
    message->channel2 = data[2] | (data[3] << 8);
    message->channel3 = data[4] | (data[5] << 8);
    message->channel4 = data[6] | (data[7] << 8);
}

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

void secondary_deserialize_IRTS_RL_1(secondary_message_IRTS_RL_1* message, uint8_t* data) {
    message->channel5 = data[0] | (data[1] << 8);
    message->channel6 = data[2] | (data[3] << 8);
    message->channel7 = data[4] | (data[5] << 8);
    message->channel8 = data[6] | (data[7] << 8);
}

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

void secondary_deserialize_IRTS_RL_2(secondary_message_IRTS_RL_2* message, uint8_t* data) {
    message->channel9 = data[0] | (data[1] << 8);
    message->channel10 = data[2] | (data[3] << 8);
    message->channel11 = data[4] | (data[5] << 8);
    message->channel12 = data[6] | (data[7] << 8);
}

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

void secondary_deserialize_IRTS_RL_3(secondary_message_IRTS_RL_3* message, uint8_t* data) {
    message->channel13 = data[0] | (data[1] << 8);
    message->channel14 = data[2] | (data[3] << 8);
    message->channel15 = data[4] | (data[5] << 8);
    message->channel16 = data[6] | (data[7] << 8);
}

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

void secondary_deserialize_IRTS_RR_0(secondary_message_IRTS_RR_0* message, uint8_t* data) {
    message->channel1 = data[0] | (data[1] << 8);
    message->channel2 = data[2] | (data[3] << 8);
    message->channel3 = data[4] | (data[5] << 8);
    message->channel4 = data[6] | (data[7] << 8);
}

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

void secondary_deserialize_IRTS_RR_1(secondary_message_IRTS_RR_1* message, uint8_t* data) {
    message->channel5 = data[0] | (data[1] << 8);
    message->channel6 = data[2] | (data[3] << 8);
    message->channel7 = data[4] | (data[5] << 8);
    message->channel8 = data[6] | (data[7] << 8);
}

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

void secondary_deserialize_IRTS_RR_2(secondary_message_IRTS_RR_2* message, uint8_t* data) {
    message->channel9 = data[0] | (data[1] << 8);
    message->channel10 = data[2] | (data[3] << 8);
    message->channel11 = data[4] | (data[5] << 8);
    message->channel12 = data[6] | (data[7] << 8);
}

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

void secondary_deserialize_IRTS_RR_3(secondary_message_IRTS_RR_3* message, uint8_t* data) {
    message->channel13 = data[0] | (data[1] << 8);
    message->channel14 = data[2] | (data[3] << 8);
    message->channel15 = data[4] | (data[5] << 8);
    message->channel16 = data[6] | (data[7] << 8);
}

void secondary_serialize_GPS_COORDS(
    uint8_t* data,
    secondary_float32 latitude,
    secondary_float32 longitude
) {
    data[0] = ((secondary_float32_helper) latitude).bytes[0];
    data[1] = ((secondary_float32_helper) latitude).bytes[1];
    data[2] = ((secondary_float32_helper) latitude).bytes[2];
    data[3] = ((secondary_float32_helper) latitude).bytes[3];
    data[4] = ((secondary_float32_helper) longitude).bytes[0];
    data[5] = ((secondary_float32_helper) longitude).bytes[1];
    data[6] = ((secondary_float32_helper) longitude).bytes[2];
    data[7] = ((secondary_float32_helper) longitude).bytes[3];
}

void secondary_deserialize_GPS_COORDS(secondary_message_GPS_COORDS* message, uint8_t* data) {
    message->latitude = ((secondary_float32_helper) {data[0] ,data[1] ,data[2] ,data[3]}).value;
    message->longitude = ((secondary_float32_helper) {data[4] ,data[5] ,data[6] ,data[7]}).value;
}

void secondary_serialize_GPS_SPEED(
    uint8_t* data,
    secondary_uint16 speed
) {
    data[0] = speed & 255;
    data[1] = (speed >> 8) & 255;
}

void secondary_deserialize_GPS_SPEED(secondary_message_GPS_SPEED* message, uint8_t* data) {
    message->speed = data[0] | (data[1] << 8);
}

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

void secondary_deserialize_LAP_COUNT(secondary_message_LAP_COUNT* message, uint8_t* data) {
    message->timestamp = data[0] | (data[1] << 8) | (data[2] << 16) | (data[3] << 24);
    message->lap_count = data[4];
}


// Strings


void secondary_to_string_IMU_ANGULAR_RATE(secondary_message_IMU_ANGULAR_RATE* message, char* buffer) {
    sprintf(
        buffer,
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d",
        message->ang_rate_x,
        message->ang_rate_y,
        message->ang_rate_z
    );
}

void secondary_fields_IMU_ANGULAR_RATE(char* buffer) {
    sprintf(
        buffer,
        "ang_rate_x" CANLIB_SEPARATOR 
        "ang_rate_y" CANLIB_SEPARATOR 
        "ang_rate_z"
    );
}

void secondary_to_string_file_IMU_ANGULAR_RATE(secondary_message_IMU_ANGULAR_RATE* message, FILE* buffer) {
    fprintf(
        buffer,
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d",
        message->ang_rate_x,
        message->ang_rate_y,
        message->ang_rate_z
    );
}

void secondary_fields_file_IMU_ANGULAR_RATE(FILE* buffer) {
    fprintf(
        buffer,
        "ang_rate_x" CANLIB_SEPARATOR 
        "ang_rate_y" CANLIB_SEPARATOR 
        "ang_rate_z"
    );
}

void secondary_to_string_IMU_ACCELERATION(secondary_message_IMU_ACCELERATION* message, char* buffer) {
    sprintf(
        buffer,
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d",
        message->accel_x,
        message->accel_y,
        message->accel_z
    );
}

void secondary_fields_IMU_ACCELERATION(char* buffer) {
    sprintf(
        buffer,
        "accel_x" CANLIB_SEPARATOR 
        "accel_y" CANLIB_SEPARATOR 
        "accel_z"
    );
}

void secondary_to_string_file_IMU_ACCELERATION(secondary_message_IMU_ACCELERATION* message, FILE* buffer) {
    fprintf(
        buffer,
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d",
        message->accel_x,
        message->accel_y,
        message->accel_z
    );
}

void secondary_fields_file_IMU_ACCELERATION(FILE* buffer) {
    fprintf(
        buffer,
        "accel_x" CANLIB_SEPARATOR 
        "accel_y" CANLIB_SEPARATOR 
        "accel_z"
    );
}

void secondary_to_string_IRTS_FL_0(secondary_message_IRTS_FL_0* message, char* buffer) {
    sprintf(
        buffer,
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d",
        message->channel1,
        message->channel2,
        message->channel3,
        message->channel4
    );
}

void secondary_fields_IRTS_FL_0(char* buffer) {
    sprintf(
        buffer,
        "channel1" CANLIB_SEPARATOR 
        "channel2" CANLIB_SEPARATOR 
        "channel3" CANLIB_SEPARATOR 
        "channel4"
    );
}

void secondary_to_string_file_IRTS_FL_0(secondary_message_IRTS_FL_0* message, FILE* buffer) {
    fprintf(
        buffer,
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d",
        message->channel1,
        message->channel2,
        message->channel3,
        message->channel4
    );
}

void secondary_fields_file_IRTS_FL_0(FILE* buffer) {
    fprintf(
        buffer,
        "channel1" CANLIB_SEPARATOR 
        "channel2" CANLIB_SEPARATOR 
        "channel3" CANLIB_SEPARATOR 
        "channel4"
    );
}

void secondary_to_string_IRTS_FL_1(secondary_message_IRTS_FL_1* message, char* buffer) {
    sprintf(
        buffer,
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d",
        message->channel5,
        message->channel6,
        message->channel7,
        message->channel8
    );
}

void secondary_fields_IRTS_FL_1(char* buffer) {
    sprintf(
        buffer,
        "channel5" CANLIB_SEPARATOR 
        "channel6" CANLIB_SEPARATOR 
        "channel7" CANLIB_SEPARATOR 
        "channel8"
    );
}

void secondary_to_string_file_IRTS_FL_1(secondary_message_IRTS_FL_1* message, FILE* buffer) {
    fprintf(
        buffer,
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d",
        message->channel5,
        message->channel6,
        message->channel7,
        message->channel8
    );
}

void secondary_fields_file_IRTS_FL_1(FILE* buffer) {
    fprintf(
        buffer,
        "channel5" CANLIB_SEPARATOR 
        "channel6" CANLIB_SEPARATOR 
        "channel7" CANLIB_SEPARATOR 
        "channel8"
    );
}

void secondary_to_string_IRTS_FL_2(secondary_message_IRTS_FL_2* message, char* buffer) {
    sprintf(
        buffer,
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d",
        message->channel9,
        message->channel10,
        message->channel11,
        message->channel12
    );
}

void secondary_fields_IRTS_FL_2(char* buffer) {
    sprintf(
        buffer,
        "channel9" CANLIB_SEPARATOR 
        "channel10" CANLIB_SEPARATOR 
        "channel11" CANLIB_SEPARATOR 
        "channel12"
    );
}

void secondary_to_string_file_IRTS_FL_2(secondary_message_IRTS_FL_2* message, FILE* buffer) {
    fprintf(
        buffer,
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d",
        message->channel9,
        message->channel10,
        message->channel11,
        message->channel12
    );
}

void secondary_fields_file_IRTS_FL_2(FILE* buffer) {
    fprintf(
        buffer,
        "channel9" CANLIB_SEPARATOR 
        "channel10" CANLIB_SEPARATOR 
        "channel11" CANLIB_SEPARATOR 
        "channel12"
    );
}

void secondary_to_string_IRTS_FL_3(secondary_message_IRTS_FL_3* message, char* buffer) {
    sprintf(
        buffer,
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d",
        message->channel13,
        message->channel14,
        message->channel15,
        message->channel16
    );
}

void secondary_fields_IRTS_FL_3(char* buffer) {
    sprintf(
        buffer,
        "channel13" CANLIB_SEPARATOR 
        "channel14" CANLIB_SEPARATOR 
        "channel15" CANLIB_SEPARATOR 
        "channel16"
    );
}

void secondary_to_string_file_IRTS_FL_3(secondary_message_IRTS_FL_3* message, FILE* buffer) {
    fprintf(
        buffer,
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d",
        message->channel13,
        message->channel14,
        message->channel15,
        message->channel16
    );
}

void secondary_fields_file_IRTS_FL_3(FILE* buffer) {
    fprintf(
        buffer,
        "channel13" CANLIB_SEPARATOR 
        "channel14" CANLIB_SEPARATOR 
        "channel15" CANLIB_SEPARATOR 
        "channel16"
    );
}

void secondary_to_string_IRTS_FR_0(secondary_message_IRTS_FR_0* message, char* buffer) {
    sprintf(
        buffer,
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d",
        message->channel1,
        message->channel2,
        message->channel3,
        message->channel4
    );
}

void secondary_fields_IRTS_FR_0(char* buffer) {
    sprintf(
        buffer,
        "channel1" CANLIB_SEPARATOR 
        "channel2" CANLIB_SEPARATOR 
        "channel3" CANLIB_SEPARATOR 
        "channel4"
    );
}

void secondary_to_string_file_IRTS_FR_0(secondary_message_IRTS_FR_0* message, FILE* buffer) {
    fprintf(
        buffer,
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d",
        message->channel1,
        message->channel2,
        message->channel3,
        message->channel4
    );
}

void secondary_fields_file_IRTS_FR_0(FILE* buffer) {
    fprintf(
        buffer,
        "channel1" CANLIB_SEPARATOR 
        "channel2" CANLIB_SEPARATOR 
        "channel3" CANLIB_SEPARATOR 
        "channel4"
    );
}

void secondary_to_string_IRTS_FR_1(secondary_message_IRTS_FR_1* message, char* buffer) {
    sprintf(
        buffer,
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d",
        message->channel5,
        message->channel6,
        message->channel7,
        message->channel8
    );
}

void secondary_fields_IRTS_FR_1(char* buffer) {
    sprintf(
        buffer,
        "channel5" CANLIB_SEPARATOR 
        "channel6" CANLIB_SEPARATOR 
        "channel7" CANLIB_SEPARATOR 
        "channel8"
    );
}

void secondary_to_string_file_IRTS_FR_1(secondary_message_IRTS_FR_1* message, FILE* buffer) {
    fprintf(
        buffer,
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d",
        message->channel5,
        message->channel6,
        message->channel7,
        message->channel8
    );
}

void secondary_fields_file_IRTS_FR_1(FILE* buffer) {
    fprintf(
        buffer,
        "channel5" CANLIB_SEPARATOR 
        "channel6" CANLIB_SEPARATOR 
        "channel7" CANLIB_SEPARATOR 
        "channel8"
    );
}

void secondary_to_string_IRTS_FR_2(secondary_message_IRTS_FR_2* message, char* buffer) {
    sprintf(
        buffer,
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d",
        message->channel9,
        message->channel10,
        message->channel11,
        message->channel12
    );
}

void secondary_fields_IRTS_FR_2(char* buffer) {
    sprintf(
        buffer,
        "channel9" CANLIB_SEPARATOR 
        "channel10" CANLIB_SEPARATOR 
        "channel11" CANLIB_SEPARATOR 
        "channel12"
    );
}

void secondary_to_string_file_IRTS_FR_2(secondary_message_IRTS_FR_2* message, FILE* buffer) {
    fprintf(
        buffer,
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d",
        message->channel9,
        message->channel10,
        message->channel11,
        message->channel12
    );
}

void secondary_fields_file_IRTS_FR_2(FILE* buffer) {
    fprintf(
        buffer,
        "channel9" CANLIB_SEPARATOR 
        "channel10" CANLIB_SEPARATOR 
        "channel11" CANLIB_SEPARATOR 
        "channel12"
    );
}

void secondary_to_string_IRTS_FR_3(secondary_message_IRTS_FR_3* message, char* buffer) {
    sprintf(
        buffer,
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d",
        message->channel13,
        message->channel14,
        message->channel15,
        message->channel16
    );
}

void secondary_fields_IRTS_FR_3(char* buffer) {
    sprintf(
        buffer,
        "channel13" CANLIB_SEPARATOR 
        "channel14" CANLIB_SEPARATOR 
        "channel15" CANLIB_SEPARATOR 
        "channel16"
    );
}

void secondary_to_string_file_IRTS_FR_3(secondary_message_IRTS_FR_3* message, FILE* buffer) {
    fprintf(
        buffer,
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d",
        message->channel13,
        message->channel14,
        message->channel15,
        message->channel16
    );
}

void secondary_fields_file_IRTS_FR_3(FILE* buffer) {
    fprintf(
        buffer,
        "channel13" CANLIB_SEPARATOR 
        "channel14" CANLIB_SEPARATOR 
        "channel15" CANLIB_SEPARATOR 
        "channel16"
    );
}

void secondary_to_string_IRTS_RL_0(secondary_message_IRTS_RL_0* message, char* buffer) {
    sprintf(
        buffer,
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d",
        message->channel1,
        message->channel2,
        message->channel3,
        message->channel4
    );
}

void secondary_fields_IRTS_RL_0(char* buffer) {
    sprintf(
        buffer,
        "channel1" CANLIB_SEPARATOR 
        "channel2" CANLIB_SEPARATOR 
        "channel3" CANLIB_SEPARATOR 
        "channel4"
    );
}

void secondary_to_string_file_IRTS_RL_0(secondary_message_IRTS_RL_0* message, FILE* buffer) {
    fprintf(
        buffer,
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d",
        message->channel1,
        message->channel2,
        message->channel3,
        message->channel4
    );
}

void secondary_fields_file_IRTS_RL_0(FILE* buffer) {
    fprintf(
        buffer,
        "channel1" CANLIB_SEPARATOR 
        "channel2" CANLIB_SEPARATOR 
        "channel3" CANLIB_SEPARATOR 
        "channel4"
    );
}

void secondary_to_string_IRTS_RL_1(secondary_message_IRTS_RL_1* message, char* buffer) {
    sprintf(
        buffer,
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d",
        message->channel5,
        message->channel6,
        message->channel7,
        message->channel8
    );
}

void secondary_fields_IRTS_RL_1(char* buffer) {
    sprintf(
        buffer,
        "channel5" CANLIB_SEPARATOR 
        "channel6" CANLIB_SEPARATOR 
        "channel7" CANLIB_SEPARATOR 
        "channel8"
    );
}

void secondary_to_string_file_IRTS_RL_1(secondary_message_IRTS_RL_1* message, FILE* buffer) {
    fprintf(
        buffer,
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d",
        message->channel5,
        message->channel6,
        message->channel7,
        message->channel8
    );
}

void secondary_fields_file_IRTS_RL_1(FILE* buffer) {
    fprintf(
        buffer,
        "channel5" CANLIB_SEPARATOR 
        "channel6" CANLIB_SEPARATOR 
        "channel7" CANLIB_SEPARATOR 
        "channel8"
    );
}

void secondary_to_string_IRTS_RL_2(secondary_message_IRTS_RL_2* message, char* buffer) {
    sprintf(
        buffer,
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d",
        message->channel9,
        message->channel10,
        message->channel11,
        message->channel12
    );
}

void secondary_fields_IRTS_RL_2(char* buffer) {
    sprintf(
        buffer,
        "channel9" CANLIB_SEPARATOR 
        "channel10" CANLIB_SEPARATOR 
        "channel11" CANLIB_SEPARATOR 
        "channel12"
    );
}

void secondary_to_string_file_IRTS_RL_2(secondary_message_IRTS_RL_2* message, FILE* buffer) {
    fprintf(
        buffer,
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d",
        message->channel9,
        message->channel10,
        message->channel11,
        message->channel12
    );
}

void secondary_fields_file_IRTS_RL_2(FILE* buffer) {
    fprintf(
        buffer,
        "channel9" CANLIB_SEPARATOR 
        "channel10" CANLIB_SEPARATOR 
        "channel11" CANLIB_SEPARATOR 
        "channel12"
    );
}

void secondary_to_string_IRTS_RL_3(secondary_message_IRTS_RL_3* message, char* buffer) {
    sprintf(
        buffer,
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d",
        message->channel13,
        message->channel14,
        message->channel15,
        message->channel16
    );
}

void secondary_fields_IRTS_RL_3(char* buffer) {
    sprintf(
        buffer,
        "channel13" CANLIB_SEPARATOR 
        "channel14" CANLIB_SEPARATOR 
        "channel15" CANLIB_SEPARATOR 
        "channel16"
    );
}

void secondary_to_string_file_IRTS_RL_3(secondary_message_IRTS_RL_3* message, FILE* buffer) {
    fprintf(
        buffer,
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d",
        message->channel13,
        message->channel14,
        message->channel15,
        message->channel16
    );
}

void secondary_fields_file_IRTS_RL_3(FILE* buffer) {
    fprintf(
        buffer,
        "channel13" CANLIB_SEPARATOR 
        "channel14" CANLIB_SEPARATOR 
        "channel15" CANLIB_SEPARATOR 
        "channel16"
    );
}

void secondary_to_string_IRTS_RR_0(secondary_message_IRTS_RR_0* message, char* buffer) {
    sprintf(
        buffer,
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d",
        message->channel1,
        message->channel2,
        message->channel3,
        message->channel4
    );
}

void secondary_fields_IRTS_RR_0(char* buffer) {
    sprintf(
        buffer,
        "channel1" CANLIB_SEPARATOR 
        "channel2" CANLIB_SEPARATOR 
        "channel3" CANLIB_SEPARATOR 
        "channel4"
    );
}

void secondary_to_string_file_IRTS_RR_0(secondary_message_IRTS_RR_0* message, FILE* buffer) {
    fprintf(
        buffer,
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d",
        message->channel1,
        message->channel2,
        message->channel3,
        message->channel4
    );
}

void secondary_fields_file_IRTS_RR_0(FILE* buffer) {
    fprintf(
        buffer,
        "channel1" CANLIB_SEPARATOR 
        "channel2" CANLIB_SEPARATOR 
        "channel3" CANLIB_SEPARATOR 
        "channel4"
    );
}

void secondary_to_string_IRTS_RR_1(secondary_message_IRTS_RR_1* message, char* buffer) {
    sprintf(
        buffer,
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d",
        message->channel5,
        message->channel6,
        message->channel7,
        message->channel8
    );
}

void secondary_fields_IRTS_RR_1(char* buffer) {
    sprintf(
        buffer,
        "channel5" CANLIB_SEPARATOR 
        "channel6" CANLIB_SEPARATOR 
        "channel7" CANLIB_SEPARATOR 
        "channel8"
    );
}

void secondary_to_string_file_IRTS_RR_1(secondary_message_IRTS_RR_1* message, FILE* buffer) {
    fprintf(
        buffer,
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d",
        message->channel5,
        message->channel6,
        message->channel7,
        message->channel8
    );
}

void secondary_fields_file_IRTS_RR_1(FILE* buffer) {
    fprintf(
        buffer,
        "channel5" CANLIB_SEPARATOR 
        "channel6" CANLIB_SEPARATOR 
        "channel7" CANLIB_SEPARATOR 
        "channel8"
    );
}

void secondary_to_string_IRTS_RR_2(secondary_message_IRTS_RR_2* message, char* buffer) {
    sprintf(
        buffer,
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d",
        message->channel9,
        message->channel10,
        message->channel11,
        message->channel12
    );
}

void secondary_fields_IRTS_RR_2(char* buffer) {
    sprintf(
        buffer,
        "channel9" CANLIB_SEPARATOR 
        "channel10" CANLIB_SEPARATOR 
        "channel11" CANLIB_SEPARATOR 
        "channel12"
    );
}

void secondary_to_string_file_IRTS_RR_2(secondary_message_IRTS_RR_2* message, FILE* buffer) {
    fprintf(
        buffer,
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d",
        message->channel9,
        message->channel10,
        message->channel11,
        message->channel12
    );
}

void secondary_fields_file_IRTS_RR_2(FILE* buffer) {
    fprintf(
        buffer,
        "channel9" CANLIB_SEPARATOR 
        "channel10" CANLIB_SEPARATOR 
        "channel11" CANLIB_SEPARATOR 
        "channel12"
    );
}

void secondary_to_string_IRTS_RR_3(secondary_message_IRTS_RR_3* message, char* buffer) {
    sprintf(
        buffer,
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d",
        message->channel13,
        message->channel14,
        message->channel15,
        message->channel16
    );
}

void secondary_fields_IRTS_RR_3(char* buffer) {
    sprintf(
        buffer,
        "channel13" CANLIB_SEPARATOR 
        "channel14" CANLIB_SEPARATOR 
        "channel15" CANLIB_SEPARATOR 
        "channel16"
    );
}

void secondary_to_string_file_IRTS_RR_3(secondary_message_IRTS_RR_3* message, FILE* buffer) {
    fprintf(
        buffer,
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d",
        message->channel13,
        message->channel14,
        message->channel15,
        message->channel16
    );
}

void secondary_fields_file_IRTS_RR_3(FILE* buffer) {
    fprintf(
        buffer,
        "channel13" CANLIB_SEPARATOR 
        "channel14" CANLIB_SEPARATOR 
        "channel15" CANLIB_SEPARATOR 
        "channel16"
    );
}

void secondary_to_string_GPS_COORDS(secondary_message_GPS_COORDS* message, char* buffer) {
    sprintf(
        buffer,
        "%lu" CANLIB_SEPARATOR 
        "%lu",
        message->latitude,
        message->longitude
    );
}

void secondary_fields_GPS_COORDS(char* buffer) {
    sprintf(
        buffer,
        "latitude" CANLIB_SEPARATOR 
        "longitude"
    );
}

void secondary_to_string_file_GPS_COORDS(secondary_message_GPS_COORDS* message, FILE* buffer) {
    fprintf(
        buffer,
        "%lu" CANLIB_SEPARATOR 
        "%lu",
        message->latitude,
        message->longitude
    );
}

void secondary_fields_file_GPS_COORDS(FILE* buffer) {
    fprintf(
        buffer,
        "latitude" CANLIB_SEPARATOR 
        "longitude"
    );
}

void secondary_to_string_GPS_SPEED(secondary_message_GPS_SPEED* message, char* buffer) {
    sprintf(
        buffer,
        "%d",
        message->speed
    );
}

void secondary_fields_GPS_SPEED(char* buffer) {
    sprintf(
        buffer,
        "speed"
    );
}

void secondary_to_string_file_GPS_SPEED(secondary_message_GPS_SPEED* message, FILE* buffer) {
    fprintf(
        buffer,
        "%d",
        message->speed
    );
}

void secondary_fields_file_GPS_SPEED(FILE* buffer) {
    fprintf(
        buffer,
        "speed"
    );
}

void secondary_to_string_LAP_COUNT(secondary_message_LAP_COUNT* message, char* buffer) {
    sprintf(
        buffer,
        "%hhu" CANLIB_SEPARATOR 
        "%hhd",
        message->timestamp,
        message->lap_count
    );
}

void secondary_fields_LAP_COUNT(char* buffer) {
    sprintf(
        buffer,
        "timestamp" CANLIB_SEPARATOR 
        "lap_count"
    );
}

void secondary_to_string_file_LAP_COUNT(secondary_message_LAP_COUNT* message, FILE* buffer) {
    fprintf(
        buffer,
        "%hhu" CANLIB_SEPARATOR 
        "%hhd",
        message->timestamp,
        message->lap_count
    );
}

void secondary_fields_file_LAP_COUNT(FILE* buffer) {
    fprintf(
        buffer,
        "timestamp" CANLIB_SEPARATOR 
        "lap_count"
    );
}


#endif // secondary_NETWORK_H