#ifndef bms_NETWORK_H
#define bms_NETWORK_H

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

#define CANLIB_BITMASK(b) (1 << (b))
#define CANLIB_BITSET(a, b) ((a) |= CANLIB_BITMASK(b))
#define CANLIB_BITCLEAR(a, b) ((a) &= ~CANLIB_BITMASK(b))
#define CANLIB_BITTEST(a, b) ((a) & CANLIB_BITMASK(b))

#endif // CANLIB_SHARED

#ifndef CANLIB_SEPARATOR
#define CANLIB_SEPARATOR ","
#endif // CANLIB_SEPARATOR

// Info

#define bms_NUMBER_OF_MESSAGES 20

// Custom types

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
    bms_uint8 bytes[4];
    bms_float32 value;
} bms_float32_helper;

typedef union {
    bms_uint8 bytes[8];
    bms_float64 value;
} bms_float64_helper;

#ifdef __cplusplus
#define bms_float32_to_bytes(float, index) (reinterpret_cast<bms_uint8*>(&((float)))[(index)])
#else
#define bms_float32_to_bytes(float, index) ({(bms_float32_helper)bms_float32_helper.value = (f)}.bytes[(index)])
#endif

typedef struct {
    uint16_t id;
    void* raw_message;
    void* message;
} bms_devices[bms_NUMBER_OF_MESSAGES];

// ============== FREQUENCIES ============== //


#define bms_BOARD_STATUS_FREQUENCY -1
#define bms_TEMPERATURES_FREQUENCY -1
#define bms_VOLTAGES_FREQUENCY -1
#define bms_BALANCING_FREQUENCY -1
#define bms_FW_UPDATE_FREQUENCY -1

// ============== SIZES ============== //


#define bms_BOARD_STATUS_SIZE 2
#define bms_TEMPERATURES_SIZE 7
#define bms_VOLTAGES_SIZE 7
#define bms_BALANCING_SIZE 5
#define bms_FW_UPDATE_SIZE 1

// ============== BIT SETS ============== //


typedef bms_uint8 bms_Errors;
#define bms_Errors_DEFAULT 0
#define bms_Errors_CAN_COMM 1
#define bms_Errors_LTC_COMM 2
#define bms_Errors_TEMP_COMM_0 4
#define bms_Errors_TEMP_COMM_1 8
#define bms_Errors_TEMP_COMM_2 16
#define bms_Errors_TEMP_COMM_3 32
#define bms_Errors_TEMP_COMM_4 64
#define bms_Errors_TEMP_COMM_5 128

typedef bms_uint64 bms_BalancingCells;
#define bms_BalancingCells_DEFAULT 0
#define bms_BalancingCells_CELL0 1
#define bms_BalancingCells_CELL1 2
#define bms_BalancingCells_CELL2 4
#define bms_BalancingCells_CELL3 8
#define bms_BalancingCells_CELL4 16
#define bms_BalancingCells_CELL5 32
#define bms_BalancingCells_CELL6 64
#define bms_BalancingCells_CELL7 128
#define bms_BalancingCells_CELL8 256
#define bms_BalancingCells_CELL9 512
#define bms_BalancingCells_CELL10 1024
#define bms_BalancingCells_CELL11 2048
#define bms_BalancingCells_CELL12 4096
#define bms_BalancingCells_CELL13 8192
#define bms_BalancingCells_CELL14 16384
#define bms_BalancingCells_CELL15 32768
#define bms_BalancingCells_CELL16 65536
#define bms_BalancingCells_CELL17 131072


// ============== ENUMS ============== //


typedef enum __CANLIB_PACKED {
    bms_BalancingStatus_OFF = 0,
    bms_BalancingStatus_DISCHARGE = 1,
} bms_BalancingStatus;


// Structs



typedef struct __CANLIB_PACKED {
    bms_Errors errors;
    bms_BalancingStatus balancing_status;
#ifdef CANLIB_TIMESTAMP
    bms_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} bms_message_BOARD_STATUS;


typedef struct __CANLIB_PACKED {
    bms_uint8 start_index;
    bms_uint8 temp0;
    bms_uint8 temp1;
    bms_uint8 temp2;
    bms_uint8 temp3;
    bms_uint8 temp4;
    bms_uint8 temp5;
#ifdef CANLIB_TIMESTAMP
    bms_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} bms_message_TEMPERATURES;


typedef struct __CANLIB_PACKED {
    bms_uint16 voltage0;
    bms_uint16 voltage1;
    bms_uint16 voltage2;
    bms_uint8 start_index;
#ifdef CANLIB_TIMESTAMP
    bms_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} bms_message_VOLTAGES;


typedef struct __CANLIB_PACKED {
    bms_BalancingCells cells;
    bms_uint8 board_index;
#ifdef CANLIB_TIMESTAMP
    bms_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} bms_message_BALANCING;


typedef struct __CANLIB_PACKED {
    bms_uint8 board_index;
#ifdef CANLIB_TIMESTAMP
    bms_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} bms_message_FW_UPDATE;



// ============== BOARD_STATUS ============== //

void bms_serialize_BOARD_STATUS(
    uint8_t* data,
    bms_Errors errors,
    bms_BalancingStatus balancing_status
);
void bms_serialize_struct_BOARD_STATUS(
    uint8_t* data,
    bms_message_BOARD_STATUS* message
);
void bms_deserialize_BOARD_STATUS(
    bms_message_BOARD_STATUS* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , bms_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
void bms_to_string_BOARD_STATUS(bms_message_BOARD_STATUS* message, char* buffer);
void bms_fields_BOARD_STATUS(char* buffer);
void bms_to_string_file_BOARD_STATUS(bms_message_BOARD_STATUS* message, FILE* buffer);
void bms_fields_file_BOARD_STATUS(FILE* buffer);


// ============== TEMPERATURES ============== //

void bms_serialize_TEMPERATURES(
    uint8_t* data,
    bms_uint8 start_index,
    bms_uint8 temp0,
    bms_uint8 temp1,
    bms_uint8 temp2,
    bms_uint8 temp3,
    bms_uint8 temp4,
    bms_uint8 temp5
);
void bms_serialize_struct_TEMPERATURES(
    uint8_t* data,
    bms_message_TEMPERATURES* message
);
void bms_deserialize_TEMPERATURES(
    bms_message_TEMPERATURES* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , bms_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
void bms_to_string_TEMPERATURES(bms_message_TEMPERATURES* message, char* buffer);
void bms_fields_TEMPERATURES(char* buffer);
void bms_to_string_file_TEMPERATURES(bms_message_TEMPERATURES* message, FILE* buffer);
void bms_fields_file_TEMPERATURES(FILE* buffer);


// ============== VOLTAGES ============== //

void bms_serialize_VOLTAGES(
    uint8_t* data,
    bms_uint16 voltage0,
    bms_uint16 voltage1,
    bms_uint16 voltage2,
    bms_uint8 start_index
);
void bms_serialize_struct_VOLTAGES(
    uint8_t* data,
    bms_message_VOLTAGES* message
);
void bms_deserialize_VOLTAGES(
    bms_message_VOLTAGES* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , bms_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
void bms_to_string_VOLTAGES(bms_message_VOLTAGES* message, char* buffer);
void bms_fields_VOLTAGES(char* buffer);
void bms_to_string_file_VOLTAGES(bms_message_VOLTAGES* message, FILE* buffer);
void bms_fields_file_VOLTAGES(FILE* buffer);


// ============== BALANCING ============== //

void bms_serialize_BALANCING(
    uint8_t* data,
    bms_BalancingCells cells,
    bms_uint8 board_index
);
void bms_serialize_struct_BALANCING(
    uint8_t* data,
    bms_message_BALANCING* message
);
void bms_deserialize_BALANCING(
    bms_message_BALANCING* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , bms_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
void bms_to_string_BALANCING(bms_message_BALANCING* message, char* buffer);
void bms_fields_BALANCING(char* buffer);
void bms_to_string_file_BALANCING(bms_message_BALANCING* message, FILE* buffer);
void bms_fields_file_BALANCING(FILE* buffer);


// ============== FW_UPDATE ============== //

void bms_serialize_FW_UPDATE(
    uint8_t* data,
    bms_uint8 board_index
);
void bms_serialize_struct_FW_UPDATE(
    uint8_t* data,
    bms_message_FW_UPDATE* message
);
void bms_deserialize_FW_UPDATE(
    bms_message_FW_UPDATE* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , bms_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
void bms_to_string_FW_UPDATE(bms_message_FW_UPDATE* message, char* buffer);
void bms_fields_FW_UPDATE(char* buffer);
void bms_to_string_file_FW_UPDATE(bms_message_FW_UPDATE* message, FILE* buffer);
void bms_fields_file_FW_UPDATE(FILE* buffer);




// ============== UTILS ============== //

bool bms_is_message_id(uint16_t message_id);
void bms_devices_new(bms_devices* map);
int bms_devices_index_from_id(uint16_t message_id, bms_devices* map);
void bms_fields_from_id(uint16_t message_id, FILE *buffer);
void bms_string_from_id(uint16_t message_id, void* message, FILE *buffer);
void bms_deserialize_from_id(
    uint16_t message_id,
    uint8_t* data,
    void* raw_message,
    void* message
#ifdef CANLIB_TIMESTAMP
    , bms_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);


#ifdef bms_IMPLEMENTATION
// ============== SERIALIZE ============== //

void bms_serialize_BOARD_STATUS(
    uint8_t* data,
    bms_Errors errors,
    bms_BalancingStatus balancing_status
) {
    data[0] = errors;
    data[1] = balancing_status << 7;
}
void bms_serialize_struct_BOARD_STATUS(
    uint8_t* data,
    bms_message_BOARD_STATUS* message
) {
    data[0] = message->errors;
    data[1] = message->balancing_status << 7;
}

// ============== DESERIALIZE ============== //

void bms_deserialize_BOARD_STATUS(
    bms_message_BOARD_STATUS* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , bms_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->errors = data[0];
    message->balancing_status = (bms_BalancingStatus) ((data[1] & 128) >> 7);
}

// ============== STRING ============== //

void bms_to_string_BOARD_STATUS(bms_message_BOARD_STATUS* message, char* buffer) {
    sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%ju" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%u" CANLIB_SEPARATOR 
        "%u",
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->errors,
        message->balancing_status
    );
}
void bms_fields_BOARD_STATUS(char* buffer) {
    sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "errors" CANLIB_SEPARATOR 
        "balancing_status"
    );
}
void bms_to_string_file_BOARD_STATUS(bms_message_BOARD_STATUS* message, FILE* buffer) {
    fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%ju" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%u" CANLIB_SEPARATOR 
        "%u",
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->errors,
        message->balancing_status
    );
}
void bms_fields_file_BOARD_STATUS(FILE* buffer) {
    fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "errors" CANLIB_SEPARATOR 
        "balancing_status"
    );
}

// ============== SERIALIZE ============== //

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
void bms_serialize_struct_TEMPERATURES(
    uint8_t* data,
    bms_message_TEMPERATURES* message
) {
    data[0] = message->start_index;
    data[1] = message->temp0;
    data[2] = message->temp1;
    data[3] = message->temp2;
    data[4] = message->temp3;
    data[5] = message->temp4;
    data[6] = message->temp5;
}

// ============== DESERIALIZE ============== //

void bms_deserialize_TEMPERATURES(
    bms_message_TEMPERATURES* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , bms_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->start_index = data[0];
    message->temp0 = data[1];
    message->temp1 = data[2];
    message->temp2 = data[3];
    message->temp3 = data[4];
    message->temp4 = data[5];
    message->temp5 = data[6];
}

// ============== STRING ============== //

void bms_to_string_TEMPERATURES(bms_message_TEMPERATURES* message, char* buffer) {
    sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%ju" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u",
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
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
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
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
#ifdef CANLIB_TIMESTAMP
        "%ju" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u" CANLIB_SEPARATOR 
        "%u",
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
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
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "start_index" CANLIB_SEPARATOR 
        "temp0" CANLIB_SEPARATOR 
        "temp1" CANLIB_SEPARATOR 
        "temp2" CANLIB_SEPARATOR 
        "temp3" CANLIB_SEPARATOR 
        "temp4" CANLIB_SEPARATOR 
        "temp5"
    );
}

// ============== SERIALIZE ============== //

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
void bms_serialize_struct_VOLTAGES(
    uint8_t* data,
    bms_message_VOLTAGES* message
) {
    data[0] = message->voltage0 & 255;
    data[1] = (message->voltage0 >> 8) & 255;
    data[2] = message->voltage1 & 255;
    data[3] = (message->voltage1 >> 8) & 255;
    data[4] = message->voltage2 & 255;
    data[5] = (message->voltage2 >> 8) & 255;
    data[6] = message->start_index;
}

// ============== DESERIALIZE ============== //

void bms_deserialize_VOLTAGES(
    bms_message_VOLTAGES* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , bms_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->voltage0 = data[0] | (data[1] << 8);
    message->voltage1 = data[2] | (data[3] << 8);
    message->voltage2 = data[4] | (data[5] << 8);
    message->start_index = data[6];
}

// ============== STRING ============== //

void bms_to_string_VOLTAGES(bms_message_VOLTAGES* message, char* buffer) {
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
        message->voltage0,
        message->voltage1,
        message->voltage2,
        message->start_index
    );
}
void bms_fields_VOLTAGES(char* buffer) {
    sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "voltage0" CANLIB_SEPARATOR 
        "voltage1" CANLIB_SEPARATOR 
        "voltage2" CANLIB_SEPARATOR 
        "start_index"
    );
}
void bms_to_string_file_VOLTAGES(bms_message_VOLTAGES* message, FILE* buffer) {
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
        message->voltage0,
        message->voltage1,
        message->voltage2,
        message->start_index
    );
}
void bms_fields_file_VOLTAGES(FILE* buffer) {
    fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "voltage0" CANLIB_SEPARATOR 
        "voltage1" CANLIB_SEPARATOR 
        "voltage2" CANLIB_SEPARATOR 
        "start_index"
    );
}

// ============== SERIALIZE ============== //

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
void bms_serialize_struct_BALANCING(
    uint8_t* data,
    bms_message_BALANCING* message
) {
    data[0] = message->cells & 255;
    data[1] = (message->cells >> 8) & 255;
    data[2] = (message->cells >> 16) & 255;
    data[3] = (message->cells >> 24) & 255;
    data[4] = message->board_index;
}

// ============== DESERIALIZE ============== //

void bms_deserialize_BALANCING(
    bms_message_BALANCING* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , bms_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->cells = data[0] | (data[1] << 8) | (data[2] << 16) | (data[3] << 24);
    message->board_index = data[4];
}

// ============== STRING ============== //

void bms_to_string_BALANCING(bms_message_BALANCING* message, char* buffer) {
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
        message->cells,
        message->board_index
    );
}
void bms_fields_BALANCING(char* buffer) {
    sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "cells" CANLIB_SEPARATOR 
        "board_index"
    );
}
void bms_to_string_file_BALANCING(bms_message_BALANCING* message, FILE* buffer) {
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
        message->cells,
        message->board_index
    );
}
void bms_fields_file_BALANCING(FILE* buffer) {
    fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "cells" CANLIB_SEPARATOR 
        "board_index"
    );
}

// ============== SERIALIZE ============== //

void bms_serialize_FW_UPDATE(
    uint8_t* data,
    bms_uint8 board_index
) {
    data[0] = board_index;
}
void bms_serialize_struct_FW_UPDATE(
    uint8_t* data,
    bms_message_FW_UPDATE* message
) {
    data[0] = message->board_index;
}

// ============== DESERIALIZE ============== //

void bms_deserialize_FW_UPDATE(
    bms_message_FW_UPDATE* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , bms_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
) {
#ifdef CANLIB_TIMESTAMP
    message->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    message->board_index = data[0];
}

// ============== STRING ============== //

void bms_to_string_FW_UPDATE(bms_message_FW_UPDATE* message, char* buffer) {
    sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%ju" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%u",
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->board_index
    );
}
void bms_fields_FW_UPDATE(char* buffer) {
    sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "board_index"
    );
}
void bms_to_string_file_FW_UPDATE(bms_message_FW_UPDATE* message, FILE* buffer) {
    fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%ju" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%u",
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->board_index
    );
}
void bms_fields_file_FW_UPDATE(FILE* buffer) {
    fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "board_index"
    );
}


// ============== UTILS ============== //

void bms_fields_from_id(uint16_t message_id, FILE *buffer) {
    switch (message_id) {
    case 1536:
        bms_fields_file_BOARD_STATUS(buffer);
        break;
    case 1568:
        bms_fields_file_BOARD_STATUS(buffer);
        break;
    case 1600:
        bms_fields_file_BOARD_STATUS(buffer);
        break;
    case 1632:
        bms_fields_file_BOARD_STATUS(buffer);
        break;
    case 1664:
        bms_fields_file_BOARD_STATUS(buffer);
        break;
    case 1696:
        bms_fields_file_BOARD_STATUS(buffer);
        break;
    case 1281:
        bms_fields_file_TEMPERATURES(buffer);
        break;
    case 1313:
        bms_fields_file_TEMPERATURES(buffer);
        break;
    case 1345:
        bms_fields_file_TEMPERATURES(buffer);
        break;
    case 1377:
        bms_fields_file_TEMPERATURES(buffer);
        break;
    case 1409:
        bms_fields_file_TEMPERATURES(buffer);
        break;
    case 1441:
        bms_fields_file_TEMPERATURES(buffer);
        break;
    case 514:
        bms_fields_file_VOLTAGES(buffer);
        break;
    case 546:
        bms_fields_file_VOLTAGES(buffer);
        break;
    case 578:
        bms_fields_file_VOLTAGES(buffer);
        break;
    case 610:
        bms_fields_file_VOLTAGES(buffer);
        break;
    case 642:
        bms_fields_file_VOLTAGES(buffer);
        break;
    case 674:
        bms_fields_file_VOLTAGES(buffer);
        break;
    case 515:
        bms_fields_file_BALANCING(buffer);
        break;
    case 260:
        bms_fields_file_FW_UPDATE(buffer);
        break;
    }
}

void bms_string_from_id(uint16_t message_id, void* message, FILE *buffer) {
    switch (message_id) {
        case 1536:
            bms_to_string_file_BOARD_STATUS((bms_message_BOARD_STATUS*) message, buffer);
        break;
        case 1568:
            bms_to_string_file_BOARD_STATUS((bms_message_BOARD_STATUS*) message, buffer);
        break;
        case 1600:
            bms_to_string_file_BOARD_STATUS((bms_message_BOARD_STATUS*) message, buffer);
        break;
        case 1632:
            bms_to_string_file_BOARD_STATUS((bms_message_BOARD_STATUS*) message, buffer);
        break;
        case 1664:
            bms_to_string_file_BOARD_STATUS((bms_message_BOARD_STATUS*) message, buffer);
        break;
        case 1696:
            bms_to_string_file_BOARD_STATUS((bms_message_BOARD_STATUS*) message, buffer);
        break;
        case 1281:
            bms_to_string_file_TEMPERATURES((bms_message_TEMPERATURES*) message, buffer);
        break;
        case 1313:
            bms_to_string_file_TEMPERATURES((bms_message_TEMPERATURES*) message, buffer);
        break;
        case 1345:
            bms_to_string_file_TEMPERATURES((bms_message_TEMPERATURES*) message, buffer);
        break;
        case 1377:
            bms_to_string_file_TEMPERATURES((bms_message_TEMPERATURES*) message, buffer);
        break;
        case 1409:
            bms_to_string_file_TEMPERATURES((bms_message_TEMPERATURES*) message, buffer);
        break;
        case 1441:
            bms_to_string_file_TEMPERATURES((bms_message_TEMPERATURES*) message, buffer);
        break;
        case 514:
            bms_to_string_file_VOLTAGES((bms_message_VOLTAGES*) message, buffer);
        break;
        case 546:
            bms_to_string_file_VOLTAGES((bms_message_VOLTAGES*) message, buffer);
        break;
        case 578:
            bms_to_string_file_VOLTAGES((bms_message_VOLTAGES*) message, buffer);
        break;
        case 610:
            bms_to_string_file_VOLTAGES((bms_message_VOLTAGES*) message, buffer);
        break;
        case 642:
            bms_to_string_file_VOLTAGES((bms_message_VOLTAGES*) message, buffer);
        break;
        case 674:
            bms_to_string_file_VOLTAGES((bms_message_VOLTAGES*) message, buffer);
        break;
        case 515:
            bms_to_string_file_BALANCING((bms_message_BALANCING*) message, buffer);
        break;
        case 260:
            bms_to_string_file_FW_UPDATE((bms_message_FW_UPDATE*) message, buffer);
        break;
    }
}

void bms_deserialize_from_id(
    uint16_t message_id,
    uint8_t* data,
    void* raw_message,
    void* message
#ifdef CANLIB_TIMESTAMP
    , bms_uint64 timestamp
#endif // CANLIB_TIMESTAMP
) {
    switch (message_id) {
        case 1536:
            bms_deserialize_BOARD_STATUS(
                (bms_message_BOARD_STATUS*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 1568:
            bms_deserialize_BOARD_STATUS(
                (bms_message_BOARD_STATUS*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 1600:
            bms_deserialize_BOARD_STATUS(
                (bms_message_BOARD_STATUS*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 1632:
            bms_deserialize_BOARD_STATUS(
                (bms_message_BOARD_STATUS*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 1664:
            bms_deserialize_BOARD_STATUS(
                (bms_message_BOARD_STATUS*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 1696:
            bms_deserialize_BOARD_STATUS(
                (bms_message_BOARD_STATUS*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 1281:
            bms_deserialize_TEMPERATURES(
                (bms_message_TEMPERATURES*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 1313:
            bms_deserialize_TEMPERATURES(
                (bms_message_TEMPERATURES*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 1345:
            bms_deserialize_TEMPERATURES(
                (bms_message_TEMPERATURES*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 1377:
            bms_deserialize_TEMPERATURES(
                (bms_message_TEMPERATURES*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 1409:
            bms_deserialize_TEMPERATURES(
                (bms_message_TEMPERATURES*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 1441:
            bms_deserialize_TEMPERATURES(
                (bms_message_TEMPERATURES*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 514:
            bms_deserialize_VOLTAGES(
                (bms_message_VOLTAGES*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 546:
            bms_deserialize_VOLTAGES(
                (bms_message_VOLTAGES*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 578:
            bms_deserialize_VOLTAGES(
                (bms_message_VOLTAGES*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 610:
            bms_deserialize_VOLTAGES(
                (bms_message_VOLTAGES*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 642:
            bms_deserialize_VOLTAGES(
                (bms_message_VOLTAGES*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 674:
            bms_deserialize_VOLTAGES(
                (bms_message_VOLTAGES*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 515:
            bms_deserialize_BALANCING(
                (bms_message_BALANCING*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
        case 260:
            bms_deserialize_FW_UPDATE(
                (bms_message_FW_UPDATE*) raw_message,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
        break;
    }
}

bool bms_is_message_id(uint16_t message_id) {
    switch (message_id) {
        case 1536: return true; break;
        case 1568: return true; break;
        case 1600: return true; break;
        case 1632: return true; break;
        case 1664: return true; break;
        case 1696: return true; break;
        case 1281: return true; break;
        case 1313: return true; break;
        case 1345: return true; break;
        case 1377: return true; break;
        case 1409: return true; break;
        case 1441: return true; break;
        case 514: return true; break;
        case 546: return true; break;
        case 578: return true; break;
        case 610: return true; break;
        case 642: return true; break;
        case 674: return true; break;
        case 515: return true; break;
        case 260: return true; break;
    }
    return false;
}

void bms_devices_new(bms_devices* map) {
    (*map)[0].id = 1536;
    (*map)[0].raw_message = (void*) malloc(sizeof(bms_message_BOARD_STATUS));
    (*map)[0].message = NULL;

    (*map)[1].id = 1568;
    (*map)[1].raw_message = (void*) malloc(sizeof(bms_message_BOARD_STATUS));
    (*map)[1].message = NULL;

    (*map)[2].id = 1600;
    (*map)[2].raw_message = (void*) malloc(sizeof(bms_message_BOARD_STATUS));
    (*map)[2].message = NULL;

    (*map)[3].id = 1632;
    (*map)[3].raw_message = (void*) malloc(sizeof(bms_message_BOARD_STATUS));
    (*map)[3].message = NULL;

    (*map)[4].id = 1664;
    (*map)[4].raw_message = (void*) malloc(sizeof(bms_message_BOARD_STATUS));
    (*map)[4].message = NULL;

    (*map)[5].id = 1696;
    (*map)[5].raw_message = (void*) malloc(sizeof(bms_message_BOARD_STATUS));
    (*map)[5].message = NULL;

    (*map)[6].id = 1281;
    (*map)[6].raw_message = (void*) malloc(sizeof(bms_message_TEMPERATURES));
    (*map)[6].message = NULL;

    (*map)[6].id = 1313;
    (*map)[6].raw_message = (void*) malloc(sizeof(bms_message_TEMPERATURES));
    (*map)[6].message = NULL;

    (*map)[6].id = 1345;
    (*map)[6].raw_message = (void*) malloc(sizeof(bms_message_TEMPERATURES));
    (*map)[6].message = NULL;

    (*map)[6].id = 1377;
    (*map)[6].raw_message = (void*) malloc(sizeof(bms_message_TEMPERATURES));
    (*map)[6].message = NULL;

    (*map)[6].id = 1409;
    (*map)[6].raw_message = (void*) malloc(sizeof(bms_message_TEMPERATURES));
    (*map)[6].message = NULL;

    (*map)[6].id = 1441;
    (*map)[6].raw_message = (void*) malloc(sizeof(bms_message_TEMPERATURES));
    (*map)[6].message = NULL;

    (*map)[7].id = 514;
    (*map)[7].raw_message = (void*) malloc(sizeof(bms_message_VOLTAGES));
    (*map)[7].message = NULL;

    (*map)[7].id = 546;
    (*map)[7].raw_message = (void*) malloc(sizeof(bms_message_VOLTAGES));
    (*map)[7].message = NULL;

    (*map)[7].id = 578;
    (*map)[7].raw_message = (void*) malloc(sizeof(bms_message_VOLTAGES));
    (*map)[7].message = NULL;

    (*map)[7].id = 610;
    (*map)[7].raw_message = (void*) malloc(sizeof(bms_message_VOLTAGES));
    (*map)[7].message = NULL;

    (*map)[7].id = 642;
    (*map)[7].raw_message = (void*) malloc(sizeof(bms_message_VOLTAGES));
    (*map)[7].message = NULL;

    (*map)[7].id = 674;
    (*map)[7].raw_message = (void*) malloc(sizeof(bms_message_VOLTAGES));
    (*map)[7].message = NULL;

    (*map)[8].id = 515;
    (*map)[8].raw_message = (void*) malloc(sizeof(bms_message_BALANCING));
    (*map)[8].message = NULL;

    (*map)[9].id = 260;
    (*map)[9].raw_message = (void*) malloc(sizeof(bms_message_FW_UPDATE));
    (*map)[9].message = NULL;

}

int bms_devices_index_from_id(uint16_t message_id, bms_devices* map) {
    for (int index = 0; index < bms_NUMBER_OF_MESSAGES; index++) {
        if ((*map)[index].id == message_id)
            return index;
    }
    return -1;
}

#endif

#ifdef __cplusplus
}
#endif

#endif // bms_NETWORK_H