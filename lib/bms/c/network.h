#ifndef bms_NETWORK_H
#define bms_NETWORK_H

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

#define bms_int8 int8_t
#define bms_uint8 uint8_t
#define bms_int16 int16_t
#define bms_uint16 uint16_t
#define bms_int32 int32_t
#define bms_uint32 uint32_t
#define bms_int64 int64_t
#define bms_uint64 uint64_t
#define bms_float32 float
#define bms_float64 double
#define bms_bool bool

typedef union {
    uint8_t bytes[4];
    bms_float32 value;
} bms_float32_helper;

typedef union {
    uint8_t bytes[8];
    bms_float64 value;
} bms_float64_helper;

// Frequencies


#define bms_BOARD_STATUS_FREQUENCY -1
#define bms_TEMPERATURES_FREQUENCY -1
#define bms_VOLTAGES_FREQUENCY -1
#define bms_BALANCING_FREQUENCY -1
#define bms_FW_UPDATE_FREQUENCY -1

// Sizes


#define bms_BOARD_STATUS_SIZE 2
#define bms_TEMPERATURES_SIZE 7
#define bms_VOLTAGES_SIZE 7
#define bms_BALANCING_SIZE 5
#define bms_FW_UPDATE_SIZE 1

// Bitsets


typedef bms_uint8 bms_Errors;
#define bms_Errors_DEFAULT 0
#define bms_Errors_CAN_COMM 0
#define bms_Errors_LTC_COMM 1
#define bms_Errors_TEMP_COMM_0 2
#define bms_Errors_TEMP_COMM_1 3
#define bms_Errors_TEMP_COMM_2 4
#define bms_Errors_TEMP_COMM_3 5
#define bms_Errors_TEMP_COMM_4 6
#define bms_Errors_TEMP_COMM_5 7

typedef bms_uint32 bms_BalancingCells;
#define bms_BalancingCells_DEFAULT 0
#define bms_BalancingCells_CELL0 0
#define bms_BalancingCells_CELL1 1
#define bms_BalancingCells_CELL2 2
#define bms_BalancingCells_CELL3 3
#define bms_BalancingCells_CELL4 4
#define bms_BalancingCells_CELL5 5
#define bms_BalancingCells_CELL6 6
#define bms_BalancingCells_CELL7 7
#define bms_BalancingCells_CELL8 8
#define bms_BalancingCells_CELL9 9
#define bms_BalancingCells_CELL10 10
#define bms_BalancingCells_CELL11 11
#define bms_BalancingCells_CELL12 12
#define bms_BalancingCells_CELL13 13
#define bms_BalancingCells_CELL14 14
#define bms_BalancingCells_CELL15 15
#define bms_BalancingCells_CELL16 16
#define bms_BalancingCells_CELL17 17


// Enums


typedef enum __CANLIB_PACKED {
    BalancingStatus_OFF = 0,
    BalancingStatus_DISCHARGE = 1,
} bms_BalancingStatus;


// Structs


typedef struct __CANLIB_PACKED {
    bms_Errors errors;
    bms_BalancingStatus balancing_status;
} bms_message_BOARD_STATUS;

typedef struct __CANLIB_PACKED {
    bms_uint8 start_index;
    bms_uint8 temp0;
    bms_uint8 temp1;
    bms_uint8 temp2;
    bms_uint8 temp3;
    bms_uint8 temp4;
    bms_uint8 temp5;
} bms_message_TEMPERATURES;

typedef struct __CANLIB_PACKED {
    bms_uint16 voltage0;
    bms_uint16 voltage1;
    bms_uint16 voltage2;
    bms_uint8 start_index;
} bms_message_VOLTAGES;

typedef struct __CANLIB_PACKED {
    bms_BalancingCells cells;
    bms_uint8 board_index;
} bms_message_BALANCING;

typedef struct __CANLIB_PACKED {
    bms_uint8 board_index;
} bms_message_FW_UPDATE;


// Serialize and Deserialize


void bms_serialize_BOARD_STATUS(
    uint8_t* data,
    bms_Errors errors,
    bms_BalancingStatus balancing_status
) {
    data[0] = errors;
    data[1] = balancing_status << 7;
}

void bms_deserialize_BOARD_STATUS(bms_message_BOARD_STATUS* message, uint8_t* data) {
    message->errors = data[0];
    message->balancing_status = (bms_BalancingStatus) ((data[1] & 128) >> 7);
}

void bms_serialize_TEMPERATURES(
    uint8_t* data,
    bms_uint8 start_index,
    bms_uint8 temp0,
    bms_uint8 temp1,
    bms_uint8 temp2,
    bms_uint8 temp3,
    bms_uint8 temp4,
    bms_uint8 temp5
) {
    data[0] = start_index;
    data[1] = temp0;
    data[2] = temp1;
    data[3] = temp2;
    data[4] = temp3;
    data[5] = temp4;
    data[6] = temp5;
}

void bms_deserialize_TEMPERATURES(bms_message_TEMPERATURES* message, uint8_t* data) {
    message->start_index = data[0];
    message->temp0 = data[1];
    message->temp1 = data[2];
    message->temp2 = data[3];
    message->temp3 = data[4];
    message->temp4 = data[5];
    message->temp5 = data[6];
}

void bms_serialize_VOLTAGES(
    uint8_t* data,
    bms_uint16 voltage0,
    bms_uint16 voltage1,
    bms_uint16 voltage2,
    bms_uint8 start_index
) {
    data[0] = voltage0 & 255;
    data[1] = (voltage0 >> 8) & 255;
    data[2] = voltage1 & 255;
    data[3] = (voltage1 >> 8) & 255;
    data[4] = voltage2 & 255;
    data[5] = (voltage2 >> 8) & 255;
    data[6] = start_index;
}

void bms_deserialize_VOLTAGES(bms_message_VOLTAGES* message, uint8_t* data) {
    message->voltage0 = data[0] | (data[1] << 8);
    message->voltage1 = data[2] | (data[3] << 8);
    message->voltage2 = data[4] | (data[5] << 8);
    message->start_index = data[6];
}

void bms_serialize_BALANCING(
    uint8_t* data,
    bms_BalancingCells cells,
    bms_uint8 board_index
) {
    data[0] = cells & 255;
    data[1] = (cells >> 8) & 255;
    data[2] = (cells >> 16) & 255;
    data[3] = (cells >> 24) & 255;
    data[4] = board_index;
}

void bms_deserialize_BALANCING(bms_message_BALANCING* message, uint8_t* data) {
    message->cells = data[0] | (data[1] << 8) | (data[2] << 16) | (data[3] << 24);
    message->board_index = data[4];
}

void bms_serialize_FW_UPDATE(
    uint8_t* data,
    bms_uint8 board_index
) {
    data[0] = board_index;
}

void bms_deserialize_FW_UPDATE(bms_message_FW_UPDATE* message, uint8_t* data) {
    message->board_index = data[0];
}


// Strings


void bms_to_string_BOARD_STATUS(bms_message_BOARD_STATUS* message, char* buffer) {
    sprintf(
        buffer,
        "%hhd" CANLIB_SEPARATOR 
        "%d",
        message->errors,
        message->balancing_status
    );
}

void bms_fields_BOARD_STATUS(char* buffer) {
    sprintf(
        buffer,
        "errors" CANLIB_SEPARATOR 
        "balancing_status"
    );
}

void bms_to_string_file_BOARD_STATUS(bms_message_BOARD_STATUS* message, FILE* buffer) {
    fprintf(
        buffer,
        "%hhd" CANLIB_SEPARATOR 
        "%d",
        message->errors,
        message->balancing_status
    );
}

void bms_fields_file_BOARD_STATUS(FILE* buffer) {
    fprintf(
        buffer,
        "errors" CANLIB_SEPARATOR 
        "balancing_status"
    );
}

void bms_to_string_TEMPERATURES(bms_message_TEMPERATURES* message, char* buffer) {
    sprintf(
        buffer,
        "%hhd" CANLIB_SEPARATOR 
        "%hhd" CANLIB_SEPARATOR 
        "%hhd" CANLIB_SEPARATOR 
        "%hhd" CANLIB_SEPARATOR 
        "%hhd" CANLIB_SEPARATOR 
        "%hhd" CANLIB_SEPARATOR 
        "%hhd",
        message->start_index,
        message->temp0,
        message->temp1,
        message->temp2,
        message->temp3,
        message->temp4,
        message->temp5
    );
}

void bms_fields_TEMPERATURES(char* buffer) {
    sprintf(
        buffer,
        "start_index" CANLIB_SEPARATOR 
        "temp0" CANLIB_SEPARATOR 
        "temp1" CANLIB_SEPARATOR 
        "temp2" CANLIB_SEPARATOR 
        "temp3" CANLIB_SEPARATOR 
        "temp4" CANLIB_SEPARATOR 
        "temp5"
    );
}

void bms_to_string_file_TEMPERATURES(bms_message_TEMPERATURES* message, FILE* buffer) {
    fprintf(
        buffer,
        "%hhd" CANLIB_SEPARATOR 
        "%hhd" CANLIB_SEPARATOR 
        "%hhd" CANLIB_SEPARATOR 
        "%hhd" CANLIB_SEPARATOR 
        "%hhd" CANLIB_SEPARATOR 
        "%hhd" CANLIB_SEPARATOR 
        "%hhd",
        message->start_index,
        message->temp0,
        message->temp1,
        message->temp2,
        message->temp3,
        message->temp4,
        message->temp5
    );
}

void bms_fields_file_TEMPERATURES(FILE* buffer) {
    fprintf(
        buffer,
        "start_index" CANLIB_SEPARATOR 
        "temp0" CANLIB_SEPARATOR 
        "temp1" CANLIB_SEPARATOR 
        "temp2" CANLIB_SEPARATOR 
        "temp3" CANLIB_SEPARATOR 
        "temp4" CANLIB_SEPARATOR 
        "temp5"
    );
}

void bms_to_string_VOLTAGES(bms_message_VOLTAGES* message, char* buffer) {
    sprintf(
        buffer,
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%hhd",
        message->voltage0,
        message->voltage1,
        message->voltage2,
        message->start_index
    );
}

void bms_fields_VOLTAGES(char* buffer) {
    sprintf(
        buffer,
        "voltage0" CANLIB_SEPARATOR 
        "voltage1" CANLIB_SEPARATOR 
        "voltage2" CANLIB_SEPARATOR 
        "start_index"
    );
}

void bms_to_string_file_VOLTAGES(bms_message_VOLTAGES* message, FILE* buffer) {
    fprintf(
        buffer,
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%d" CANLIB_SEPARATOR 
        "%hhd",
        message->voltage0,
        message->voltage1,
        message->voltage2,
        message->start_index
    );
}

void bms_fields_file_VOLTAGES(FILE* buffer) {
    fprintf(
        buffer,
        "voltage0" CANLIB_SEPARATOR 
        "voltage1" CANLIB_SEPARATOR 
        "voltage2" CANLIB_SEPARATOR 
        "start_index"
    );
}

void bms_to_string_BALANCING(bms_message_BALANCING* message, char* buffer) {
    sprintf(
        buffer,
        "%hhu" CANLIB_SEPARATOR 
        "%hhd",
        message->cells,
        message->board_index
    );
}

void bms_fields_BALANCING(char* buffer) {
    sprintf(
        buffer,
        "cells" CANLIB_SEPARATOR 
        "board_index"
    );
}

void bms_to_string_file_BALANCING(bms_message_BALANCING* message, FILE* buffer) {
    fprintf(
        buffer,
        "%hhu" CANLIB_SEPARATOR 
        "%hhd",
        message->cells,
        message->board_index
    );
}

void bms_fields_file_BALANCING(FILE* buffer) {
    fprintf(
        buffer,
        "cells" CANLIB_SEPARATOR 
        "board_index"
    );
}

void bms_to_string_FW_UPDATE(bms_message_FW_UPDATE* message, char* buffer) {
    sprintf(
        buffer,
        "%hhd",
        message->board_index
    );
}

void bms_fields_FW_UPDATE(char* buffer) {
    sprintf(
        buffer,
        "board_index"
    );
}

void bms_to_string_file_FW_UPDATE(bms_message_FW_UPDATE* message, FILE* buffer) {
    fprintf(
        buffer,
        "%hhd",
        message->board_index
    );
}

void bms_fields_file_FW_UPDATE(FILE* buffer) {
    fprintf(
        buffer,
        "board_index"
    );
}


#endif // bms_NETWORK_H