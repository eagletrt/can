#ifndef bms_NETWORK_H
#define bms_NETWORK_H

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
#define CANLIB_BUILD_TIME 1685998146
#define CANLIB_BUILD_HASH 0x414e6c6d
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

#define bms_MESSAGE_COUNT 17

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
#define bms_byte_size uint32_t

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
#define bms_float64_to_bytes(float, index) (reinterpret_cast<bms_uint8*>(&((float)))[(index)])
#else
#define bms_float32_to_bytes(float, index) (((bms_float32_helper) (float)).bytes[(index)])
#define bms_float64_to_bytes(float, index) (((bms_float64_helper) (float)).bytes[(index)])
#endif

typedef struct {
    uint16_t id;
    void* message_raw;
    void* message_conversion;
} bms_devices_t;
typedef bms_devices_t bms_devices[bms_MESSAGE_COUNT];


// ============== INDEXES ============ //


#define bms_INDEX_BOARD_STATUS 0
#define bms_INDEX_TEMPERATURES 1
#define bms_INDEX_VOLTAGES 2
#define bms_INDEX_BALANCING 3
#define bms_INDEX_FW_UPDATE 4
#define bms_INDEX_FLASH_CELLBOARD_0_TX 5
#define bms_INDEX_FLASH_CELLBOARD_0_RX 6
#define bms_INDEX_FLASH_CELLBOARD_1_TX 7
#define bms_INDEX_FLASH_CELLBOARD_1_RX 8
#define bms_INDEX_FLASH_CELLBOARD_2_TX 9
#define bms_INDEX_FLASH_CELLBOARD_2_RX 10
#define bms_INDEX_FLASH_CELLBOARD_3_TX 11
#define bms_INDEX_FLASH_CELLBOARD_3_RX 12
#define bms_INDEX_FLASH_CELLBOARD_4_TX 13
#define bms_INDEX_FLASH_CELLBOARD_4_RX 14
#define bms_INDEX_FLASH_CELLBOARD_5_TX 15
#define bms_INDEX_FLASH_CELLBOARD_5_RX 16

// ============== SIZES ============== //


#define bms_SIZE_BOARD_STATUS 3
#define bms_SIZE_TEMPERATURES 6
#define bms_SIZE_VOLTAGES 8
#define bms_SIZE_BALANCING 5
#define bms_SIZE_FW_UPDATE 2
#define bms_SIZE_FLASH_CELLBOARD_0_TX 0
#define bms_SIZE_FLASH_CELLBOARD_0_RX 0
#define bms_SIZE_FLASH_CELLBOARD_1_TX 0
#define bms_SIZE_FLASH_CELLBOARD_1_RX 0
#define bms_SIZE_FLASH_CELLBOARD_2_TX 0
#define bms_SIZE_FLASH_CELLBOARD_2_RX 0
#define bms_SIZE_FLASH_CELLBOARD_3_TX 0
#define bms_SIZE_FLASH_CELLBOARD_3_RX 0
#define bms_SIZE_FLASH_CELLBOARD_4_TX 0
#define bms_SIZE_FLASH_CELLBOARD_4_RX 0
#define bms_SIZE_FLASH_CELLBOARD_5_TX 0
#define bms_SIZE_FLASH_CELLBOARD_5_RX 0

// ============== BIT SETS =========== //


typedef bms_uint16 bms_Errors;
#define bms_Errors_DEFAULT 0
#define bms_Errors_CAN_COMM 1
#define bms_Errors_LTC_COMM 2
#define bms_Errors_TEMP_COMM_0 4
#define bms_Errors_TEMP_COMM_1 8
#define bms_Errors_TEMP_COMM_2 16
#define bms_Errors_TEMP_COMM_3 32
#define bms_Errors_TEMP_COMM_4 64
#define bms_Errors_TEMP_COMM_5 128
#define bms_Errors_OPEN_WIRE 256

#define bms_MAX_STRING_LENGTH_Errors 100
int bms_to_string_Errors(bms_Errors value, char* buffer);

typedef bms_uint32 bms_BalancingCells;
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

#define bms_MAX_STRING_LENGTH_BalancingCells 116
int bms_to_string_BalancingCells(bms_BalancingCells value, char* buffer);


// ============== ENUMS ============== //


typedef enum CANLIB_PARKING {
    bms_Cellboard_CELLBOARD_0 = 0,
    bms_Cellboard_CELLBOARD_1 = 1,
    bms_Cellboard_CELLBOARD_2 = 2,
    bms_Cellboard_CELLBOARD_3 = 3,
    bms_Cellboard_CELLBOARD_4 = 4,
    bms_Cellboard_CELLBOARD_5 = 5,
} bms_Cellboard;

#define bms_MAX_STRING_LENGTH_Cellboard 12
int bms_to_string_Cellboard(bms_Cellboard value, char* buffer);

typedef enum CANLIB_PARKING {
    bms_BalancingStatus_OFF = 0,
    bms_BalancingStatus_DISCHARGE = 1,
} bms_BalancingStatus;

#define bms_MAX_STRING_LENGTH_BalancingStatus 10
int bms_to_string_BalancingStatus(bms_BalancingStatus value, char* buffer);


// Structs


typedef struct CANLIB_PARKING {
    bms_Cellboard cellboard_id;
    bms_Errors errors;
    bms_BalancingStatus balancing_status;
#ifdef CANLIB_TIMESTAMP
    bms_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} bms_message_BOARD_STATUS;

typedef struct CANLIB_PARKING {
    bms_Cellboard cellboard_id;
    bms_uint8 start_index;
    bms_uint8 temp0;
    bms_uint8 temp1;
    bms_uint8 temp2;
    bms_uint8 temp3;
#ifdef CANLIB_TIMESTAMP
    bms_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} bms_message_TEMPERATURES;

typedef struct CANLIB_PARKING {
    bms_Cellboard cellboard_id;
    bms_uint8 start_index;
    bms_float32 temp0;
    bms_float32 temp1;
    bms_float32 temp2;
    bms_float32 temp3;
#ifdef CANLIB_TIMESTAMP
    bms_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} bms_message_TEMPERATURES_conversion;

typedef struct CANLIB_PARKING {
    bms_Cellboard cellboard_id;
    bms_uint8 start_index;
    bms_uint16 voltage0;
    bms_uint16 voltage1;
    bms_uint16 voltage2;
#ifdef CANLIB_TIMESTAMP
    bms_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} bms_message_VOLTAGES;

typedef struct CANLIB_PARKING {
    bms_Cellboard cellboard_id;
    bms_uint8 start_index;
    bms_float32 voltage0;
    bms_float32 voltage1;
    bms_float32 voltage2;
#ifdef CANLIB_TIMESTAMP
    bms_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} bms_message_VOLTAGES_conversion;

typedef struct CANLIB_PARKING {
    bms_Cellboard cellboard_id;
    bms_uint8 board_index;
    bms_BalancingCells cells;
#ifdef CANLIB_TIMESTAMP
    bms_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} bms_message_BALANCING;

typedef struct CANLIB_PARKING {
    bms_Cellboard cellboard_id;
    bms_uint8 board_index;
#ifdef CANLIB_TIMESTAMP
    bms_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} bms_message_FW_UPDATE;

typedef struct CANLIB_PARKING {
    bms_uint8 _placeholder; // C++ doesn't like empty structs
#ifdef CANLIB_TIMESTAMP
    bms_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} bms_message_FLASH_CELLBOARD_0_TX;

typedef struct CANLIB_PARKING {
    bms_uint8 _placeholder; // C++ doesn't like empty structs
#ifdef CANLIB_TIMESTAMP
    bms_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} bms_message_FLASH_CELLBOARD_0_RX;

typedef struct CANLIB_PARKING {
    bms_uint8 _placeholder; // C++ doesn't like empty structs
#ifdef CANLIB_TIMESTAMP
    bms_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} bms_message_FLASH_CELLBOARD_1_TX;

typedef struct CANLIB_PARKING {
    bms_uint8 _placeholder; // C++ doesn't like empty structs
#ifdef CANLIB_TIMESTAMP
    bms_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} bms_message_FLASH_CELLBOARD_1_RX;

typedef struct CANLIB_PARKING {
    bms_uint8 _placeholder; // C++ doesn't like empty structs
#ifdef CANLIB_TIMESTAMP
    bms_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} bms_message_FLASH_CELLBOARD_2_TX;

typedef struct CANLIB_PARKING {
    bms_uint8 _placeholder; // C++ doesn't like empty structs
#ifdef CANLIB_TIMESTAMP
    bms_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} bms_message_FLASH_CELLBOARD_2_RX;

typedef struct CANLIB_PARKING {
    bms_uint8 _placeholder; // C++ doesn't like empty structs
#ifdef CANLIB_TIMESTAMP
    bms_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} bms_message_FLASH_CELLBOARD_3_TX;

typedef struct CANLIB_PARKING {
    bms_uint8 _placeholder; // C++ doesn't like empty structs
#ifdef CANLIB_TIMESTAMP
    bms_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} bms_message_FLASH_CELLBOARD_3_RX;

typedef struct CANLIB_PARKING {
    bms_uint8 _placeholder; // C++ doesn't like empty structs
#ifdef CANLIB_TIMESTAMP
    bms_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} bms_message_FLASH_CELLBOARD_4_TX;

typedef struct CANLIB_PARKING {
    bms_uint8 _placeholder; // C++ doesn't like empty structs
#ifdef CANLIB_TIMESTAMP
    bms_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} bms_message_FLASH_CELLBOARD_4_RX;

typedef struct CANLIB_PARKING {
    bms_uint8 _placeholder; // C++ doesn't like empty structs
#ifdef CANLIB_TIMESTAMP
    bms_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} bms_message_FLASH_CELLBOARD_5_TX;

typedef struct CANLIB_PARKING {
    bms_uint8 _placeholder; // C++ doesn't like empty structs
#ifdef CANLIB_TIMESTAMP
    bms_uint64 _timestamp;
#endif // CANLIB_TIMESTAMP
} bms_message_FLASH_CELLBOARD_5_RX;


typedef union CANLIB_PARKING {
    bms_message_BOARD_STATUS _BOARD_STATUS;
    bms_message_TEMPERATURES _TEMPERATURES;
    bms_message_VOLTAGES _VOLTAGES;
    bms_message_BALANCING _BALANCING;
    bms_message_FW_UPDATE _FW_UPDATE;
    bms_message_FLASH_CELLBOARD_0_TX _FLASH_CELLBOARD_0_TX;
    bms_message_FLASH_CELLBOARD_0_RX _FLASH_CELLBOARD_0_RX;
    bms_message_FLASH_CELLBOARD_1_TX _FLASH_CELLBOARD_1_TX;
    bms_message_FLASH_CELLBOARD_1_RX _FLASH_CELLBOARD_1_RX;
    bms_message_FLASH_CELLBOARD_2_TX _FLASH_CELLBOARD_2_TX;
    bms_message_FLASH_CELLBOARD_2_RX _FLASH_CELLBOARD_2_RX;
    bms_message_FLASH_CELLBOARD_3_TX _FLASH_CELLBOARD_3_TX;
    bms_message_FLASH_CELLBOARD_3_RX _FLASH_CELLBOARD_3_RX;
    bms_message_FLASH_CELLBOARD_4_TX _FLASH_CELLBOARD_4_TX;
    bms_message_FLASH_CELLBOARD_4_RX _FLASH_CELLBOARD_4_RX;
    bms_message_FLASH_CELLBOARD_5_TX _FLASH_CELLBOARD_5_TX;
    bms_message_FLASH_CELLBOARD_5_RX _FLASH_CELLBOARD_5_RX;
} _bms_all_structs_raw;

typedef union CANLIB_PARKING {
    bms_message_TEMPERATURES_conversion _TEMPERATURES;
    bms_message_VOLTAGES_conversion _VOLTAGES;
} _bms_all_structs_conversion;

typedef union CANLIB_PARKING {
    _bms_all_structs_raw raw;
    _bms_all_structs_conversion conversion;
} _bms_all_structs;

#define bms_MAX_STRUCT_SIZE_RAW sizeof(_bms_all_structs_raw)
#define bms_MAX_STRUCT_SIZE_CONVERSION sizeof(_bms_all_structs_conversion)
#define bms_MAX_STRUCT_SIZE sizeof(_bms_all_structs)


// ============== BOARD_STATUS ============== //

bms_byte_size bms_serialize_BOARD_STATUS(
    uint8_t* data,
    bms_Cellboard cellboard_id,
    bms_Errors errors,
    bms_BalancingStatus balancing_status
);
bms_byte_size bms_serialize_struct_BOARD_STATUS(
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
int bms_to_string_BOARD_STATUS(bms_message_BOARD_STATUS* message, char* buffer);
int bms_fields_BOARD_STATUS(char* buffer);
int bms_to_string_file_BOARD_STATUS(bms_message_BOARD_STATUS* message, FILE* buffer);
int bms_fields_file_BOARD_STATUS(FILE* buffer);


// ============== TEMPERATURES ============== //

bms_byte_size bms_serialize_TEMPERATURES(
    uint8_t* data,
    bms_Cellboard cellboard_id,
    bms_uint8 start_index,
    bms_uint8 temp0,
    bms_uint8 temp1,
    bms_uint8 temp2,
    bms_uint8 temp3
);
bms_byte_size bms_serialize_struct_TEMPERATURES(
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
void bms_raw_to_conversion_struct_TEMPERATURES(
    bms_message_TEMPERATURES_conversion* conversion,
    bms_message_TEMPERATURES* raw
);

void bms_conversion_to_raw_struct_TEMPERATURES(
    bms_message_TEMPERATURES* raw,
    bms_message_TEMPERATURES_conversion* conversion
);

void bms_conversion_to_raw_TEMPERATURES(
    bms_message_TEMPERATURES* raw,
    bms_Cellboard cellboard_id,
    bms_uint8 start_index,
    bms_float32 temp0,
    bms_float32 temp1,
    bms_float32 temp2,
    bms_float32 temp3
#ifdef CANLIB_TIMESTAMP
    , bms_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
);

void bms_raw_to_conversion_TEMPERATURES(
    bms_message_TEMPERATURES_conversion* conversion,
    bms_Cellboard cellboard_id,
    bms_uint8 start_index,
    bms_uint8 temp0,
    bms_uint8 temp1,
    bms_uint8 temp2,
    bms_uint8 temp3
#ifdef CANLIB_TIMESTAMP
    , bms_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
);
int bms_to_string_TEMPERATURES(bms_message_TEMPERATURES_conversion* message, char* buffer);
int bms_fields_TEMPERATURES(char* buffer);
int bms_to_string_file_TEMPERATURES(bms_message_TEMPERATURES_conversion* message, FILE* buffer);
int bms_fields_file_TEMPERATURES(FILE* buffer);


// ============== VOLTAGES ============== //

bms_byte_size bms_serialize_VOLTAGES(
    uint8_t* data,
    bms_Cellboard cellboard_id,
    bms_uint8 start_index,
    bms_uint16 voltage0,
    bms_uint16 voltage1,
    bms_uint16 voltage2
);
bms_byte_size bms_serialize_struct_VOLTAGES(
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
void bms_raw_to_conversion_struct_VOLTAGES(
    bms_message_VOLTAGES_conversion* conversion,
    bms_message_VOLTAGES* raw
);

void bms_conversion_to_raw_struct_VOLTAGES(
    bms_message_VOLTAGES* raw,
    bms_message_VOLTAGES_conversion* conversion
);

void bms_conversion_to_raw_VOLTAGES(
    bms_message_VOLTAGES* raw,
    bms_Cellboard cellboard_id,
    bms_uint8 start_index,
    bms_float32 voltage0,
    bms_float32 voltage1,
    bms_float32 voltage2
#ifdef CANLIB_TIMESTAMP
    , bms_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
);

void bms_raw_to_conversion_VOLTAGES(
    bms_message_VOLTAGES_conversion* conversion,
    bms_Cellboard cellboard_id,
    bms_uint8 start_index,
    bms_uint16 voltage0,
    bms_uint16 voltage1,
    bms_uint16 voltage2
#ifdef CANLIB_TIMESTAMP
    , bms_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
);
int bms_to_string_VOLTAGES(bms_message_VOLTAGES_conversion* message, char* buffer);
int bms_fields_VOLTAGES(char* buffer);
int bms_to_string_file_VOLTAGES(bms_message_VOLTAGES_conversion* message, FILE* buffer);
int bms_fields_file_VOLTAGES(FILE* buffer);


// ============== BALANCING ============== //

bms_byte_size bms_serialize_BALANCING(
    uint8_t* data,
    bms_Cellboard cellboard_id,
    bms_uint8 board_index,
    bms_BalancingCells cells
);
bms_byte_size bms_serialize_struct_BALANCING(
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
int bms_to_string_BALANCING(bms_message_BALANCING* message, char* buffer);
int bms_fields_BALANCING(char* buffer);
int bms_to_string_file_BALANCING(bms_message_BALANCING* message, FILE* buffer);
int bms_fields_file_BALANCING(FILE* buffer);


// ============== FW_UPDATE ============== //

bms_byte_size bms_serialize_FW_UPDATE(
    uint8_t* data,
    bms_Cellboard cellboard_id,
    bms_uint8 board_index
);
bms_byte_size bms_serialize_struct_FW_UPDATE(
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
int bms_to_string_FW_UPDATE(bms_message_FW_UPDATE* message, char* buffer);
int bms_fields_FW_UPDATE(char* buffer);
int bms_to_string_file_FW_UPDATE(bms_message_FW_UPDATE* message, FILE* buffer);
int bms_fields_file_FW_UPDATE(FILE* buffer);


// ============== FLASH_CELLBOARD_0_TX ============== //

bms_byte_size bms_serialize_FLASH_CELLBOARD_0_TX(
    uint8_t* data
);
bms_byte_size bms_serialize_struct_FLASH_CELLBOARD_0_TX(
    uint8_t* data,
    bms_message_FLASH_CELLBOARD_0_TX* message
);
void bms_deserialize_FLASH_CELLBOARD_0_TX(
    bms_message_FLASH_CELLBOARD_0_TX* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , bms_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int bms_to_string_FLASH_CELLBOARD_0_TX(bms_message_FLASH_CELLBOARD_0_TX* message, char* buffer);
int bms_fields_FLASH_CELLBOARD_0_TX(char* buffer);
int bms_to_string_file_FLASH_CELLBOARD_0_TX(bms_message_FLASH_CELLBOARD_0_TX* message, FILE* buffer);
int bms_fields_file_FLASH_CELLBOARD_0_TX(FILE* buffer);


// ============== FLASH_CELLBOARD_0_RX ============== //

bms_byte_size bms_serialize_FLASH_CELLBOARD_0_RX(
    uint8_t* data
);
bms_byte_size bms_serialize_struct_FLASH_CELLBOARD_0_RX(
    uint8_t* data,
    bms_message_FLASH_CELLBOARD_0_RX* message
);
void bms_deserialize_FLASH_CELLBOARD_0_RX(
    bms_message_FLASH_CELLBOARD_0_RX* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , bms_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int bms_to_string_FLASH_CELLBOARD_0_RX(bms_message_FLASH_CELLBOARD_0_RX* message, char* buffer);
int bms_fields_FLASH_CELLBOARD_0_RX(char* buffer);
int bms_to_string_file_FLASH_CELLBOARD_0_RX(bms_message_FLASH_CELLBOARD_0_RX* message, FILE* buffer);
int bms_fields_file_FLASH_CELLBOARD_0_RX(FILE* buffer);


// ============== FLASH_CELLBOARD_1_TX ============== //

bms_byte_size bms_serialize_FLASH_CELLBOARD_1_TX(
    uint8_t* data
);
bms_byte_size bms_serialize_struct_FLASH_CELLBOARD_1_TX(
    uint8_t* data,
    bms_message_FLASH_CELLBOARD_1_TX* message
);
void bms_deserialize_FLASH_CELLBOARD_1_TX(
    bms_message_FLASH_CELLBOARD_1_TX* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , bms_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int bms_to_string_FLASH_CELLBOARD_1_TX(bms_message_FLASH_CELLBOARD_1_TX* message, char* buffer);
int bms_fields_FLASH_CELLBOARD_1_TX(char* buffer);
int bms_to_string_file_FLASH_CELLBOARD_1_TX(bms_message_FLASH_CELLBOARD_1_TX* message, FILE* buffer);
int bms_fields_file_FLASH_CELLBOARD_1_TX(FILE* buffer);


// ============== FLASH_CELLBOARD_1_RX ============== //

bms_byte_size bms_serialize_FLASH_CELLBOARD_1_RX(
    uint8_t* data
);
bms_byte_size bms_serialize_struct_FLASH_CELLBOARD_1_RX(
    uint8_t* data,
    bms_message_FLASH_CELLBOARD_1_RX* message
);
void bms_deserialize_FLASH_CELLBOARD_1_RX(
    bms_message_FLASH_CELLBOARD_1_RX* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , bms_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int bms_to_string_FLASH_CELLBOARD_1_RX(bms_message_FLASH_CELLBOARD_1_RX* message, char* buffer);
int bms_fields_FLASH_CELLBOARD_1_RX(char* buffer);
int bms_to_string_file_FLASH_CELLBOARD_1_RX(bms_message_FLASH_CELLBOARD_1_RX* message, FILE* buffer);
int bms_fields_file_FLASH_CELLBOARD_1_RX(FILE* buffer);


// ============== FLASH_CELLBOARD_2_TX ============== //

bms_byte_size bms_serialize_FLASH_CELLBOARD_2_TX(
    uint8_t* data
);
bms_byte_size bms_serialize_struct_FLASH_CELLBOARD_2_TX(
    uint8_t* data,
    bms_message_FLASH_CELLBOARD_2_TX* message
);
void bms_deserialize_FLASH_CELLBOARD_2_TX(
    bms_message_FLASH_CELLBOARD_2_TX* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , bms_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int bms_to_string_FLASH_CELLBOARD_2_TX(bms_message_FLASH_CELLBOARD_2_TX* message, char* buffer);
int bms_fields_FLASH_CELLBOARD_2_TX(char* buffer);
int bms_to_string_file_FLASH_CELLBOARD_2_TX(bms_message_FLASH_CELLBOARD_2_TX* message, FILE* buffer);
int bms_fields_file_FLASH_CELLBOARD_2_TX(FILE* buffer);


// ============== FLASH_CELLBOARD_2_RX ============== //

bms_byte_size bms_serialize_FLASH_CELLBOARD_2_RX(
    uint8_t* data
);
bms_byte_size bms_serialize_struct_FLASH_CELLBOARD_2_RX(
    uint8_t* data,
    bms_message_FLASH_CELLBOARD_2_RX* message
);
void bms_deserialize_FLASH_CELLBOARD_2_RX(
    bms_message_FLASH_CELLBOARD_2_RX* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , bms_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int bms_to_string_FLASH_CELLBOARD_2_RX(bms_message_FLASH_CELLBOARD_2_RX* message, char* buffer);
int bms_fields_FLASH_CELLBOARD_2_RX(char* buffer);
int bms_to_string_file_FLASH_CELLBOARD_2_RX(bms_message_FLASH_CELLBOARD_2_RX* message, FILE* buffer);
int bms_fields_file_FLASH_CELLBOARD_2_RX(FILE* buffer);


// ============== FLASH_CELLBOARD_3_TX ============== //

bms_byte_size bms_serialize_FLASH_CELLBOARD_3_TX(
    uint8_t* data
);
bms_byte_size bms_serialize_struct_FLASH_CELLBOARD_3_TX(
    uint8_t* data,
    bms_message_FLASH_CELLBOARD_3_TX* message
);
void bms_deserialize_FLASH_CELLBOARD_3_TX(
    bms_message_FLASH_CELLBOARD_3_TX* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , bms_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int bms_to_string_FLASH_CELLBOARD_3_TX(bms_message_FLASH_CELLBOARD_3_TX* message, char* buffer);
int bms_fields_FLASH_CELLBOARD_3_TX(char* buffer);
int bms_to_string_file_FLASH_CELLBOARD_3_TX(bms_message_FLASH_CELLBOARD_3_TX* message, FILE* buffer);
int bms_fields_file_FLASH_CELLBOARD_3_TX(FILE* buffer);


// ============== FLASH_CELLBOARD_3_RX ============== //

bms_byte_size bms_serialize_FLASH_CELLBOARD_3_RX(
    uint8_t* data
);
bms_byte_size bms_serialize_struct_FLASH_CELLBOARD_3_RX(
    uint8_t* data,
    bms_message_FLASH_CELLBOARD_3_RX* message
);
void bms_deserialize_FLASH_CELLBOARD_3_RX(
    bms_message_FLASH_CELLBOARD_3_RX* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , bms_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int bms_to_string_FLASH_CELLBOARD_3_RX(bms_message_FLASH_CELLBOARD_3_RX* message, char* buffer);
int bms_fields_FLASH_CELLBOARD_3_RX(char* buffer);
int bms_to_string_file_FLASH_CELLBOARD_3_RX(bms_message_FLASH_CELLBOARD_3_RX* message, FILE* buffer);
int bms_fields_file_FLASH_CELLBOARD_3_RX(FILE* buffer);


// ============== FLASH_CELLBOARD_4_TX ============== //

bms_byte_size bms_serialize_FLASH_CELLBOARD_4_TX(
    uint8_t* data
);
bms_byte_size bms_serialize_struct_FLASH_CELLBOARD_4_TX(
    uint8_t* data,
    bms_message_FLASH_CELLBOARD_4_TX* message
);
void bms_deserialize_FLASH_CELLBOARD_4_TX(
    bms_message_FLASH_CELLBOARD_4_TX* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , bms_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int bms_to_string_FLASH_CELLBOARD_4_TX(bms_message_FLASH_CELLBOARD_4_TX* message, char* buffer);
int bms_fields_FLASH_CELLBOARD_4_TX(char* buffer);
int bms_to_string_file_FLASH_CELLBOARD_4_TX(bms_message_FLASH_CELLBOARD_4_TX* message, FILE* buffer);
int bms_fields_file_FLASH_CELLBOARD_4_TX(FILE* buffer);


// ============== FLASH_CELLBOARD_4_RX ============== //

bms_byte_size bms_serialize_FLASH_CELLBOARD_4_RX(
    uint8_t* data
);
bms_byte_size bms_serialize_struct_FLASH_CELLBOARD_4_RX(
    uint8_t* data,
    bms_message_FLASH_CELLBOARD_4_RX* message
);
void bms_deserialize_FLASH_CELLBOARD_4_RX(
    bms_message_FLASH_CELLBOARD_4_RX* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , bms_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int bms_to_string_FLASH_CELLBOARD_4_RX(bms_message_FLASH_CELLBOARD_4_RX* message, char* buffer);
int bms_fields_FLASH_CELLBOARD_4_RX(char* buffer);
int bms_to_string_file_FLASH_CELLBOARD_4_RX(bms_message_FLASH_CELLBOARD_4_RX* message, FILE* buffer);
int bms_fields_file_FLASH_CELLBOARD_4_RX(FILE* buffer);


// ============== FLASH_CELLBOARD_5_TX ============== //

bms_byte_size bms_serialize_FLASH_CELLBOARD_5_TX(
    uint8_t* data
);
bms_byte_size bms_serialize_struct_FLASH_CELLBOARD_5_TX(
    uint8_t* data,
    bms_message_FLASH_CELLBOARD_5_TX* message
);
void bms_deserialize_FLASH_CELLBOARD_5_TX(
    bms_message_FLASH_CELLBOARD_5_TX* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , bms_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int bms_to_string_FLASH_CELLBOARD_5_TX(bms_message_FLASH_CELLBOARD_5_TX* message, char* buffer);
int bms_fields_FLASH_CELLBOARD_5_TX(char* buffer);
int bms_to_string_file_FLASH_CELLBOARD_5_TX(bms_message_FLASH_CELLBOARD_5_TX* message, FILE* buffer);
int bms_fields_file_FLASH_CELLBOARD_5_TX(FILE* buffer);


// ============== FLASH_CELLBOARD_5_RX ============== //

bms_byte_size bms_serialize_FLASH_CELLBOARD_5_RX(
    uint8_t* data
);
bms_byte_size bms_serialize_struct_FLASH_CELLBOARD_5_RX(
    uint8_t* data,
    bms_message_FLASH_CELLBOARD_5_RX* message
);
void bms_deserialize_FLASH_CELLBOARD_5_RX(
    bms_message_FLASH_CELLBOARD_5_RX* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , bms_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
int bms_to_string_FLASH_CELLBOARD_5_RX(bms_message_FLASH_CELLBOARD_5_RX* message, char* buffer);
int bms_fields_FLASH_CELLBOARD_5_RX(char* buffer);
int bms_to_string_file_FLASH_CELLBOARD_5_RX(bms_message_FLASH_CELLBOARD_5_RX* message, FILE* buffer);
int bms_fields_file_FLASH_CELLBOARD_5_RX(FILE* buffer);



// ============== UTILS ============== //

static inline int bms_index_from_id(canlib_message_id id) {
    switch (id) {
        case 1536: return bms_INDEX_BOARD_STATUS;
        case 1281: return bms_INDEX_TEMPERATURES;
        case 514: return bms_INDEX_VOLTAGES;
        case 515: return bms_INDEX_BALANCING;
        case 10: return bms_INDEX_FW_UPDATE;
        case 16: return bms_INDEX_FLASH_CELLBOARD_0_TX;
        case 17: return bms_INDEX_FLASH_CELLBOARD_0_RX;
        case 18: return bms_INDEX_FLASH_CELLBOARD_1_TX;
        case 19: return bms_INDEX_FLASH_CELLBOARD_1_RX;
        case 20: return bms_INDEX_FLASH_CELLBOARD_2_TX;
        case 21: return bms_INDEX_FLASH_CELLBOARD_2_RX;
        case 22: return bms_INDEX_FLASH_CELLBOARD_3_TX;
        case 23: return bms_INDEX_FLASH_CELLBOARD_3_RX;
        case 24: return bms_INDEX_FLASH_CELLBOARD_4_TX;
        case 25: return bms_INDEX_FLASH_CELLBOARD_4_RX;
        case 26: return bms_INDEX_FLASH_CELLBOARD_5_TX;
        case 27: return bms_INDEX_FLASH_CELLBOARD_5_RX;
    }
    return -1; // invalid
}

static inline int bms_id_from_index(int index) {
    switch (index) {
        case bms_INDEX_BOARD_STATUS: return 1536;
        case bms_INDEX_TEMPERATURES: return 1281;
        case bms_INDEX_VOLTAGES: return 514;
        case bms_INDEX_BALANCING: return 515;
        case bms_INDEX_FW_UPDATE: return 10;
        case bms_INDEX_FLASH_CELLBOARD_0_TX: return 16;
        case bms_INDEX_FLASH_CELLBOARD_0_RX: return 17;
        case bms_INDEX_FLASH_CELLBOARD_1_TX: return 18;
        case bms_INDEX_FLASH_CELLBOARD_1_RX: return 19;
        case bms_INDEX_FLASH_CELLBOARD_2_TX: return 20;
        case bms_INDEX_FLASH_CELLBOARD_2_RX: return 21;
        case bms_INDEX_FLASH_CELLBOARD_3_TX: return 22;
        case bms_INDEX_FLASH_CELLBOARD_3_RX: return 23;
        case bms_INDEX_FLASH_CELLBOARD_4_TX: return 24;
        case bms_INDEX_FLASH_CELLBOARD_4_RX: return 25;
        case bms_INDEX_FLASH_CELLBOARD_5_TX: return 26;
        case bms_INDEX_FLASH_CELLBOARD_5_RX: return 27;
    }
    return -1; // invalid
}

int bms_fields_from_id(canlib_message_id message_id, char *buffer);
int bms_to_string_from_id(canlib_message_id message_id, void* message, char *buffer);
int bms_fields_file_from_id(canlib_message_id message_id, FILE *buffer);
int bms_to_string_file_from_id(canlib_message_id message_id, void* message, FILE *buffer);
void* bms_deserialize_from_id(
    canlib_message_id message_id,
    uint8_t* data,
    void* message_raw,
    void* message_conversion
#ifdef CANLIB_TIMESTAMP
    , bms_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);
bms_devices* bms_devices_new();
void bms_devices_free(bms_devices* devices);
void bms_devices_deserialize_from_id(
    bms_devices* devices,
    canlib_message_id message_id,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , bms_uint64 timestamp
#endif // CANLIB_TIMESTAMP
);

#ifdef bms_NETWORK_IMPLEMENTATION


int bms_to_string_Errors(bms_Errors value, char* buffer) {
    int offset = 0;
    if (CANLIB_BITTEST_BITMASK(value, 1)) offset += sprintf(buffer + offset, "CAN_COMM ");
    if (CANLIB_BITTEST_BITMASK(value, 2)) offset += sprintf(buffer + offset, "LTC_COMM ");
    if (CANLIB_BITTEST_BITMASK(value, 4)) offset += sprintf(buffer + offset, "TEMP_COMM_0 ");
    if (CANLIB_BITTEST_BITMASK(value, 8)) offset += sprintf(buffer + offset, "TEMP_COMM_1 ");
    if (CANLIB_BITTEST_BITMASK(value, 16)) offset += sprintf(buffer + offset, "TEMP_COMM_2 ");
    if (CANLIB_BITTEST_BITMASK(value, 32)) offset += sprintf(buffer + offset, "TEMP_COMM_3 ");
    if (CANLIB_BITTEST_BITMASK(value, 64)) offset += sprintf(buffer + offset, "TEMP_COMM_4 ");
    if (CANLIB_BITTEST_BITMASK(value, 128)) offset += sprintf(buffer + offset, "TEMP_COMM_5 ");
    if (CANLIB_BITTEST_BITMASK(value, 256)) offset += sprintf(buffer + offset, "OPEN_WIRE ");
    buffer[offset] = '\0';
    return offset;
}

int bms_to_string_BalancingCells(bms_BalancingCells value, char* buffer) {
    int offset = 0;
    if (CANLIB_BITTEST_BITMASK(value, 1)) offset += sprintf(buffer + offset, "CELL0 ");
    if (CANLIB_BITTEST_BITMASK(value, 2)) offset += sprintf(buffer + offset, "CELL1 ");
    if (CANLIB_BITTEST_BITMASK(value, 4)) offset += sprintf(buffer + offset, "CELL2 ");
    if (CANLIB_BITTEST_BITMASK(value, 8)) offset += sprintf(buffer + offset, "CELL3 ");
    if (CANLIB_BITTEST_BITMASK(value, 16)) offset += sprintf(buffer + offset, "CELL4 ");
    if (CANLIB_BITTEST_BITMASK(value, 32)) offset += sprintf(buffer + offset, "CELL5 ");
    if (CANLIB_BITTEST_BITMASK(value, 64)) offset += sprintf(buffer + offset, "CELL6 ");
    if (CANLIB_BITTEST_BITMASK(value, 128)) offset += sprintf(buffer + offset, "CELL7 ");
    if (CANLIB_BITTEST_BITMASK(value, 256)) offset += sprintf(buffer + offset, "CELL8 ");
    if (CANLIB_BITTEST_BITMASK(value, 512)) offset += sprintf(buffer + offset, "CELL9 ");
    if (CANLIB_BITTEST_BITMASK(value, 1024)) offset += sprintf(buffer + offset, "CELL10 ");
    if (CANLIB_BITTEST_BITMASK(value, 2048)) offset += sprintf(buffer + offset, "CELL11 ");
    if (CANLIB_BITTEST_BITMASK(value, 4096)) offset += sprintf(buffer + offset, "CELL12 ");
    if (CANLIB_BITTEST_BITMASK(value, 8192)) offset += sprintf(buffer + offset, "CELL13 ");
    if (CANLIB_BITTEST_BITMASK(value, 16384)) offset += sprintf(buffer + offset, "CELL14 ");
    if (CANLIB_BITTEST_BITMASK(value, 32768)) offset += sprintf(buffer + offset, "CELL15 ");
    if (CANLIB_BITTEST_BITMASK(value, 65536)) offset += sprintf(buffer + offset, "CELL16 ");
    if (CANLIB_BITTEST_BITMASK(value, 131072)) offset += sprintf(buffer + offset, "CELL17 ");
    buffer[offset] = '\0';
    return offset;
}



int bms_to_string_Cellboard(bms_Cellboard value, char* buffer) {
    switch (value) {
        case 0: return sprintf(buffer, "CELLBOARD_0");
        case 1: return sprintf(buffer, "CELLBOARD_1");
        case 2: return sprintf(buffer, "CELLBOARD_2");
        case 3: return sprintf(buffer, "CELLBOARD_3");
        case 4: return sprintf(buffer, "CELLBOARD_4");
        case 5: return sprintf(buffer, "CELLBOARD_5");
    }
    return 0;
}

int bms_to_string_BalancingStatus(bms_BalancingStatus value, char* buffer) {
    switch (value) {
        case 0: return sprintf(buffer, "OFF");
        case 1: return sprintf(buffer, "DISCHARGE");
    }
    return 0;
}

// ============== SERIALIZE ============== //

bms_byte_size bms_serialize_BOARD_STATUS(
    uint8_t* data,
    bms_Cellboard cellboard_id,
    bms_Errors errors,
    bms_BalancingStatus balancing_status
) {
    data[0] = errors & 255;
    data[1] = (errors >> 8) & 255;
    data[2] = cellboard_id << 5 | balancing_status << 4;
    return 3;
}

bms_byte_size bms_serialize_struct_BOARD_STATUS(
    uint8_t* data,
    bms_message_BOARD_STATUS* message
) {
    data[0] = message->errors & 255;
    data[1] = (message->errors >> 8) & 255;
    data[2] = message->cellboard_id << 5 | message->balancing_status << 4;
    return 3;
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
    message->errors = data[0] | (data[1] << 8);
    message->cellboard_id = (bms_Cellboard) ((data[2] & 224) >> 5);
    message->balancing_status = (bms_BalancingStatus) ((data[2] & 16) >> 4);
}

// ============== STRING ============== //

int bms_to_string_BOARD_STATUS(bms_message_BOARD_STATUS* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu8,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->cellboard_id,
        message->errors,
        message->balancing_status
    );
}

int bms_fields_BOARD_STATUS(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "cellboard_id" CANLIB_SEPARATOR 
        "errors" CANLIB_SEPARATOR 
        "balancing_status"
    );
}

int bms_to_string_file_BOARD_STATUS(bms_message_BOARD_STATUS* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu16 CANLIB_SEPARATOR 
        "%" PRIu8,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->cellboard_id,
        message->errors,
        message->balancing_status
    );
}

int bms_fields_file_BOARD_STATUS(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "cellboard_id" CANLIB_SEPARATOR 
        "errors" CANLIB_SEPARATOR 
        "balancing_status"
    );
}

// ============== SERIALIZE ============== //

bms_byte_size bms_serialize_TEMPERATURES(
    uint8_t* data,
    bms_Cellboard cellboard_id,
    bms_uint8 start_index,
    bms_uint8 temp0,
    bms_uint8 temp1,
    bms_uint8 temp2,
    bms_uint8 temp3
) {
    data[0] = start_index;
    data[1] = temp0;
    data[2] = temp1;
    data[3] = temp2;
    data[4] = temp3;
    data[5] = cellboard_id << 5;
    return 6;
}

bms_byte_size bms_serialize_struct_TEMPERATURES(
    uint8_t* data,
    bms_message_TEMPERATURES* message
) {
    data[0] = message->start_index;
    data[1] = message->temp0;
    data[2] = message->temp1;
    data[3] = message->temp2;
    data[4] = message->temp3;
    data[5] = message->cellboard_id << 5;
    return 6;
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
    message->cellboard_id = (bms_Cellboard) ((data[5] & 224) >> 5);
}// ============== CONVERSION ============== //

void bms_raw_to_conversion_TEMPERATURES(
    bms_message_TEMPERATURES_conversion* conversion,
    bms_Cellboard cellboard_id,
    bms_uint8 start_index,
    bms_uint8 temp0,
    bms_uint8 temp1,
    bms_uint8 temp2,
    bms_uint8 temp3
#ifdef CANLIB_TIMESTAMP
    , bms_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
){
#ifdef CANLIB_TIMESTAMP
    conversion->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    conversion->cellboard_id = cellboard_id;
    conversion->start_index = start_index;
    conversion->temp0 = (((bms_float32)temp0) / 2.55) - 20;
    conversion->temp1 = (((bms_float32)temp1) / 2.55) - 20;
    conversion->temp2 = (((bms_float32)temp2) / 2.55) - 20;
    conversion->temp3 = (((bms_float32)temp3) / 2.55) - 20;
}

void bms_raw_to_conversion_struct_TEMPERATURES(
    bms_message_TEMPERATURES_conversion* conversion,
    bms_message_TEMPERATURES* raw
){
#ifdef CANLIB_TIMESTAMP
    conversion->_timestamp = raw->_timestamp;
#endif // CANLIB_TIMESTAMP
    conversion->cellboard_id = raw->cellboard_id;
    conversion->start_index = raw->start_index;
    conversion->temp0 = (((bms_float32)raw->temp0) / 2.55) - 20;
    conversion->temp1 = (((bms_float32)raw->temp1) / 2.55) - 20;
    conversion->temp2 = (((bms_float32)raw->temp2) / 2.55) - 20;
    conversion->temp3 = (((bms_float32)raw->temp3) / 2.55) - 20;
}

void bms_conversion_to_raw_TEMPERATURES(
    bms_message_TEMPERATURES* raw,
    bms_Cellboard cellboard_id,
    bms_uint8 start_index,
    bms_float32 temp0,
    bms_float32 temp1,
    bms_float32 temp2,
    bms_float32 temp3
#ifdef CANLIB_TIMESTAMP
    , bms_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
){
#ifdef CANLIB_TIMESTAMP
    raw->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    raw->cellboard_id = cellboard_id;
    raw->start_index = start_index;
    raw->temp0 = (bms_uint8)((temp0 + 20) * 2.55);
    raw->temp1 = (bms_uint8)((temp1 + 20) * 2.55);
    raw->temp2 = (bms_uint8)((temp2 + 20) * 2.55);
    raw->temp3 = (bms_uint8)((temp3 + 20) * 2.55);
}

void bms_conversion_to_raw_struct_TEMPERATURES(
    bms_message_TEMPERATURES* raw,
    bms_message_TEMPERATURES_conversion* conversion
){
#ifdef CANLIB_TIMESTAMP
    raw->_timestamp = conversion->_timestamp;
#endif // CANLIB_TIMESTAMP
    raw->cellboard_id = conversion->cellboard_id;
    raw->start_index = conversion->start_index;
    raw->temp0 = (bms_uint8)((conversion->temp0 + 20) * 2.55);
    raw->temp1 = (bms_uint8)((conversion->temp1 + 20) * 2.55);
    raw->temp2 = (bms_uint8)((conversion->temp2 + 20) * 2.55);
    raw->temp3 = (bms_uint8)((conversion->temp3 + 20) * 2.55);
}

// ============== STRING ============== //
int bms_to_string_TEMPERATURES(bms_message_TEMPERATURES_conversion* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->cellboard_id,
        message->start_index,
        message->temp0,
        message->temp1,
        message->temp2,
        message->temp3
    );
}

int bms_fields_TEMPERATURES(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "cellboard_id" CANLIB_SEPARATOR 
        "start_index" CANLIB_SEPARATOR 
        "temp0" CANLIB_SEPARATOR 
        "temp1" CANLIB_SEPARATOR 
        "temp2" CANLIB_SEPARATOR 
        "temp3"
    );
}

int bms_to_string_file_TEMPERATURES(bms_message_TEMPERATURES_conversion* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->cellboard_id,
        message->start_index,
        message->temp0,
        message->temp1,
        message->temp2,
        message->temp3
    );
}

int bms_fields_file_TEMPERATURES(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "cellboard_id" CANLIB_SEPARATOR 
        "start_index" CANLIB_SEPARATOR 
        "temp0" CANLIB_SEPARATOR 
        "temp1" CANLIB_SEPARATOR 
        "temp2" CANLIB_SEPARATOR 
        "temp3"
    );
}

// ============== SERIALIZE ============== //

bms_byte_size bms_serialize_VOLTAGES(
    uint8_t* data,
    bms_Cellboard cellboard_id,
    bms_uint8 start_index,
    bms_uint16 voltage0,
    bms_uint16 voltage1,
    bms_uint16 voltage2
) {
    data[0] = voltage0 & 255;
    data[1] = (voltage0 >> 8) & 255;
    data[2] = voltage1 & 255;
    data[3] = (voltage1 >> 8) & 255;
    data[4] = voltage2 & 255;
    data[5] = (voltage2 >> 8) & 255;
    data[6] = start_index;
    data[7] = cellboard_id << 5;
    return 8;
}

bms_byte_size bms_serialize_struct_VOLTAGES(
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
    data[7] = message->cellboard_id << 5;
    return 8;
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
    message->cellboard_id = (bms_Cellboard) ((data[7] & 224) >> 5);
}// ============== CONVERSION ============== //

void bms_raw_to_conversion_VOLTAGES(
    bms_message_VOLTAGES_conversion* conversion,
    bms_Cellboard cellboard_id,
    bms_uint8 start_index,
    bms_uint16 voltage0,
    bms_uint16 voltage1,
    bms_uint16 voltage2
#ifdef CANLIB_TIMESTAMP
    , bms_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
){
#ifdef CANLIB_TIMESTAMP
    conversion->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    conversion->cellboard_id = cellboard_id;
    conversion->start_index = start_index;
    conversion->voltage0 = (((bms_float32)voltage0) / 10000.0) + 0;
    conversion->voltage1 = (((bms_float32)voltage1) / 10000.0) + 0;
    conversion->voltage2 = (((bms_float32)voltage2) / 10000.0) + 0;
}

void bms_raw_to_conversion_struct_VOLTAGES(
    bms_message_VOLTAGES_conversion* conversion,
    bms_message_VOLTAGES* raw
){
#ifdef CANLIB_TIMESTAMP
    conversion->_timestamp = raw->_timestamp;
#endif // CANLIB_TIMESTAMP
    conversion->cellboard_id = raw->cellboard_id;
    conversion->start_index = raw->start_index;
    conversion->voltage0 = (((bms_float32)raw->voltage0) / 10000.0) + 0;
    conversion->voltage1 = (((bms_float32)raw->voltage1) / 10000.0) + 0;
    conversion->voltage2 = (((bms_float32)raw->voltage2) / 10000.0) + 0;
}

void bms_conversion_to_raw_VOLTAGES(
    bms_message_VOLTAGES* raw,
    bms_Cellboard cellboard_id,
    bms_uint8 start_index,
    bms_float32 voltage0,
    bms_float32 voltage1,
    bms_float32 voltage2
#ifdef CANLIB_TIMESTAMP
    , bms_uint64 _timestamp
#endif // CANLIB_TIMESTAMP
){
#ifdef CANLIB_TIMESTAMP
    raw->_timestamp = _timestamp;
#endif // CANLIB_TIMESTAMP
    raw->cellboard_id = cellboard_id;
    raw->start_index = start_index;
    raw->voltage0 = (bms_uint16)((voltage0 + 0) * 10000.0);
    raw->voltage1 = (bms_uint16)((voltage1 + 0) * 10000.0);
    raw->voltage2 = (bms_uint16)((voltage2 + 0) * 10000.0);
}

void bms_conversion_to_raw_struct_VOLTAGES(
    bms_message_VOLTAGES* raw,
    bms_message_VOLTAGES_conversion* conversion
){
#ifdef CANLIB_TIMESTAMP
    raw->_timestamp = conversion->_timestamp;
#endif // CANLIB_TIMESTAMP
    raw->cellboard_id = conversion->cellboard_id;
    raw->start_index = conversion->start_index;
    raw->voltage0 = (bms_uint16)((conversion->voltage0 + 0) * 10000.0);
    raw->voltage1 = (bms_uint16)((conversion->voltage1 + 0) * 10000.0);
    raw->voltage2 = (bms_uint16)((conversion->voltage2 + 0) * 10000.0);
}

// ============== STRING ============== //
int bms_to_string_VOLTAGES(bms_message_VOLTAGES_conversion* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->cellboard_id,
        message->start_index,
        message->voltage0,
        message->voltage1,
        message->voltage2
    );
}

int bms_fields_VOLTAGES(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "cellboard_id" CANLIB_SEPARATOR 
        "start_index" CANLIB_SEPARATOR 
        "voltage0" CANLIB_SEPARATOR 
        "voltage1" CANLIB_SEPARATOR 
        "voltage2"
    );
}

int bms_to_string_file_VOLTAGES(bms_message_VOLTAGES_conversion* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32 CANLIB_SEPARATOR 
        "%" PRIf32,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->cellboard_id,
        message->start_index,
        message->voltage0,
        message->voltage1,
        message->voltage2
    );
}

int bms_fields_file_VOLTAGES(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "cellboard_id" CANLIB_SEPARATOR 
        "start_index" CANLIB_SEPARATOR 
        "voltage0" CANLIB_SEPARATOR 
        "voltage1" CANLIB_SEPARATOR 
        "voltage2"
    );
}

// ============== SERIALIZE ============== //

bms_byte_size bms_serialize_BALANCING(
    uint8_t* data,
    bms_Cellboard cellboard_id,
    bms_uint8 board_index,
    bms_BalancingCells cells
) {
    data[0] = cells & 255;
    data[1] = (cells >> 8) & 255;
    data[2] = (cells >> 16) & 255;
    data[3] = board_index;
    data[4] = cellboard_id << 5;
    return 5;
}

bms_byte_size bms_serialize_struct_BALANCING(
    uint8_t* data,
    bms_message_BALANCING* message
) {
    data[0] = message->cells & 255;
    data[1] = (message->cells >> 8) & 255;
    data[2] = (message->cells >> 16) & 255;
    data[3] = message->board_index;
    data[4] = message->cellboard_id << 5;
    return 5;
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
    message->cells = data[0] | (data[1] << 8) | (data[2] << 16);
    message->board_index = data[3];
    message->cellboard_id = (bms_Cellboard) ((data[4] & 224) >> 5);
}

// ============== STRING ============== //

int bms_to_string_BALANCING(bms_message_BALANCING* message, char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu32,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->cellboard_id,
        message->board_index,
        message->cells
    );
}

int bms_fields_BALANCING(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "cellboard_id" CANLIB_SEPARATOR 
        "board_index" CANLIB_SEPARATOR 
        "cells"
    );
}

int bms_to_string_file_BALANCING(bms_message_BALANCING* message, FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "%" PRIu64 CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu8 CANLIB_SEPARATOR 
        "%" PRIu32,
#ifdef CANLIB_TIMESTAMP
        message->_timestamp,
#endif // CANLIB_TIMESTAMP
        message->cellboard_id,
        message->board_index,
        message->cells
    );
}

int bms_fields_file_BALANCING(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "cellboard_id" CANLIB_SEPARATOR 
        "board_index" CANLIB_SEPARATOR 
        "cells"
    );
}

// ============== SERIALIZE ============== //

bms_byte_size bms_serialize_FW_UPDATE(
    uint8_t* data,
    bms_Cellboard cellboard_id,
    bms_uint8 board_index
) {
    data[0] = board_index;
    data[1] = cellboard_id << 5;
    return 2;
}

bms_byte_size bms_serialize_struct_FW_UPDATE(
    uint8_t* data,
    bms_message_FW_UPDATE* message
) {
    data[0] = message->board_index;
    data[1] = message->cellboard_id << 5;
    return 2;
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
    message->cellboard_id = (bms_Cellboard) ((data[1] & 224) >> 5);
}

// ============== STRING ============== //

int bms_to_string_FW_UPDATE(bms_message_FW_UPDATE* message, char* buffer) {
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
        message->cellboard_id,
        message->board_index
    );
}

int bms_fields_FW_UPDATE(char* buffer) {
    return sprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "cellboard_id" CANLIB_SEPARATOR 
        "board_index"
    );
}

int bms_to_string_file_FW_UPDATE(bms_message_FW_UPDATE* message, FILE* buffer) {
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
        message->cellboard_id,
        message->board_index
    );
}

int bms_fields_file_FW_UPDATE(FILE* buffer) {
    return fprintf(
        buffer,
#ifdef CANLIB_TIMESTAMP
        "_timestamp" CANLIB_SEPARATOR
#endif // CANLIB_TIMESTAMP
        "cellboard_id" CANLIB_SEPARATOR 
        "board_index"
    );
}

// ============== SERIALIZE ============== //

bms_byte_size bms_serialize_FLASH_CELLBOARD_0_TX(
    uint8_t* data
) {
    CANLIB_UNUSED(data);
    return 0;
}

bms_byte_size bms_serialize_struct_FLASH_CELLBOARD_0_TX(
    uint8_t* data,
    bms_message_FLASH_CELLBOARD_0_TX* message
) {
    CANLIB_UNUSED(data);
    CANLIB_UNUSED(message);
    return 0;
}

// ============== DESERIALIZE ============== //

void bms_deserialize_FLASH_CELLBOARD_0_TX(
    bms_message_FLASH_CELLBOARD_0_TX* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , bms_uint64 _timestamp
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

int bms_to_string_FLASH_CELLBOARD_0_TX(bms_message_FLASH_CELLBOARD_0_TX* message, char* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int bms_fields_FLASH_CELLBOARD_0_TX(char* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

int bms_to_string_file_FLASH_CELLBOARD_0_TX(bms_message_FLASH_CELLBOARD_0_TX* message, FILE* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int bms_fields_file_FLASH_CELLBOARD_0_TX(FILE* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

// ============== SERIALIZE ============== //

bms_byte_size bms_serialize_FLASH_CELLBOARD_0_RX(
    uint8_t* data
) {
    CANLIB_UNUSED(data);
    return 0;
}

bms_byte_size bms_serialize_struct_FLASH_CELLBOARD_0_RX(
    uint8_t* data,
    bms_message_FLASH_CELLBOARD_0_RX* message
) {
    CANLIB_UNUSED(data);
    CANLIB_UNUSED(message);
    return 0;
}

// ============== DESERIALIZE ============== //

void bms_deserialize_FLASH_CELLBOARD_0_RX(
    bms_message_FLASH_CELLBOARD_0_RX* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , bms_uint64 _timestamp
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

int bms_to_string_FLASH_CELLBOARD_0_RX(bms_message_FLASH_CELLBOARD_0_RX* message, char* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int bms_fields_FLASH_CELLBOARD_0_RX(char* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

int bms_to_string_file_FLASH_CELLBOARD_0_RX(bms_message_FLASH_CELLBOARD_0_RX* message, FILE* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int bms_fields_file_FLASH_CELLBOARD_0_RX(FILE* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

// ============== SERIALIZE ============== //

bms_byte_size bms_serialize_FLASH_CELLBOARD_1_TX(
    uint8_t* data
) {
    CANLIB_UNUSED(data);
    return 0;
}

bms_byte_size bms_serialize_struct_FLASH_CELLBOARD_1_TX(
    uint8_t* data,
    bms_message_FLASH_CELLBOARD_1_TX* message
) {
    CANLIB_UNUSED(data);
    CANLIB_UNUSED(message);
    return 0;
}

// ============== DESERIALIZE ============== //

void bms_deserialize_FLASH_CELLBOARD_1_TX(
    bms_message_FLASH_CELLBOARD_1_TX* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , bms_uint64 _timestamp
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

int bms_to_string_FLASH_CELLBOARD_1_TX(bms_message_FLASH_CELLBOARD_1_TX* message, char* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int bms_fields_FLASH_CELLBOARD_1_TX(char* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

int bms_to_string_file_FLASH_CELLBOARD_1_TX(bms_message_FLASH_CELLBOARD_1_TX* message, FILE* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int bms_fields_file_FLASH_CELLBOARD_1_TX(FILE* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

// ============== SERIALIZE ============== //

bms_byte_size bms_serialize_FLASH_CELLBOARD_1_RX(
    uint8_t* data
) {
    CANLIB_UNUSED(data);
    return 0;
}

bms_byte_size bms_serialize_struct_FLASH_CELLBOARD_1_RX(
    uint8_t* data,
    bms_message_FLASH_CELLBOARD_1_RX* message
) {
    CANLIB_UNUSED(data);
    CANLIB_UNUSED(message);
    return 0;
}

// ============== DESERIALIZE ============== //

void bms_deserialize_FLASH_CELLBOARD_1_RX(
    bms_message_FLASH_CELLBOARD_1_RX* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , bms_uint64 _timestamp
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

int bms_to_string_FLASH_CELLBOARD_1_RX(bms_message_FLASH_CELLBOARD_1_RX* message, char* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int bms_fields_FLASH_CELLBOARD_1_RX(char* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

int bms_to_string_file_FLASH_CELLBOARD_1_RX(bms_message_FLASH_CELLBOARD_1_RX* message, FILE* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int bms_fields_file_FLASH_CELLBOARD_1_RX(FILE* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

// ============== SERIALIZE ============== //

bms_byte_size bms_serialize_FLASH_CELLBOARD_2_TX(
    uint8_t* data
) {
    CANLIB_UNUSED(data);
    return 0;
}

bms_byte_size bms_serialize_struct_FLASH_CELLBOARD_2_TX(
    uint8_t* data,
    bms_message_FLASH_CELLBOARD_2_TX* message
) {
    CANLIB_UNUSED(data);
    CANLIB_UNUSED(message);
    return 0;
}

// ============== DESERIALIZE ============== //

void bms_deserialize_FLASH_CELLBOARD_2_TX(
    bms_message_FLASH_CELLBOARD_2_TX* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , bms_uint64 _timestamp
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

int bms_to_string_FLASH_CELLBOARD_2_TX(bms_message_FLASH_CELLBOARD_2_TX* message, char* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int bms_fields_FLASH_CELLBOARD_2_TX(char* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

int bms_to_string_file_FLASH_CELLBOARD_2_TX(bms_message_FLASH_CELLBOARD_2_TX* message, FILE* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int bms_fields_file_FLASH_CELLBOARD_2_TX(FILE* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

// ============== SERIALIZE ============== //

bms_byte_size bms_serialize_FLASH_CELLBOARD_2_RX(
    uint8_t* data
) {
    CANLIB_UNUSED(data);
    return 0;
}

bms_byte_size bms_serialize_struct_FLASH_CELLBOARD_2_RX(
    uint8_t* data,
    bms_message_FLASH_CELLBOARD_2_RX* message
) {
    CANLIB_UNUSED(data);
    CANLIB_UNUSED(message);
    return 0;
}

// ============== DESERIALIZE ============== //

void bms_deserialize_FLASH_CELLBOARD_2_RX(
    bms_message_FLASH_CELLBOARD_2_RX* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , bms_uint64 _timestamp
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

int bms_to_string_FLASH_CELLBOARD_2_RX(bms_message_FLASH_CELLBOARD_2_RX* message, char* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int bms_fields_FLASH_CELLBOARD_2_RX(char* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

int bms_to_string_file_FLASH_CELLBOARD_2_RX(bms_message_FLASH_CELLBOARD_2_RX* message, FILE* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int bms_fields_file_FLASH_CELLBOARD_2_RX(FILE* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

// ============== SERIALIZE ============== //

bms_byte_size bms_serialize_FLASH_CELLBOARD_3_TX(
    uint8_t* data
) {
    CANLIB_UNUSED(data);
    return 0;
}

bms_byte_size bms_serialize_struct_FLASH_CELLBOARD_3_TX(
    uint8_t* data,
    bms_message_FLASH_CELLBOARD_3_TX* message
) {
    CANLIB_UNUSED(data);
    CANLIB_UNUSED(message);
    return 0;
}

// ============== DESERIALIZE ============== //

void bms_deserialize_FLASH_CELLBOARD_3_TX(
    bms_message_FLASH_CELLBOARD_3_TX* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , bms_uint64 _timestamp
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

int bms_to_string_FLASH_CELLBOARD_3_TX(bms_message_FLASH_CELLBOARD_3_TX* message, char* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int bms_fields_FLASH_CELLBOARD_3_TX(char* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

int bms_to_string_file_FLASH_CELLBOARD_3_TX(bms_message_FLASH_CELLBOARD_3_TX* message, FILE* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int bms_fields_file_FLASH_CELLBOARD_3_TX(FILE* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

// ============== SERIALIZE ============== //

bms_byte_size bms_serialize_FLASH_CELLBOARD_3_RX(
    uint8_t* data
) {
    CANLIB_UNUSED(data);
    return 0;
}

bms_byte_size bms_serialize_struct_FLASH_CELLBOARD_3_RX(
    uint8_t* data,
    bms_message_FLASH_CELLBOARD_3_RX* message
) {
    CANLIB_UNUSED(data);
    CANLIB_UNUSED(message);
    return 0;
}

// ============== DESERIALIZE ============== //

void bms_deserialize_FLASH_CELLBOARD_3_RX(
    bms_message_FLASH_CELLBOARD_3_RX* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , bms_uint64 _timestamp
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

int bms_to_string_FLASH_CELLBOARD_3_RX(bms_message_FLASH_CELLBOARD_3_RX* message, char* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int bms_fields_FLASH_CELLBOARD_3_RX(char* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

int bms_to_string_file_FLASH_CELLBOARD_3_RX(bms_message_FLASH_CELLBOARD_3_RX* message, FILE* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int bms_fields_file_FLASH_CELLBOARD_3_RX(FILE* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

// ============== SERIALIZE ============== //

bms_byte_size bms_serialize_FLASH_CELLBOARD_4_TX(
    uint8_t* data
) {
    CANLIB_UNUSED(data);
    return 0;
}

bms_byte_size bms_serialize_struct_FLASH_CELLBOARD_4_TX(
    uint8_t* data,
    bms_message_FLASH_CELLBOARD_4_TX* message
) {
    CANLIB_UNUSED(data);
    CANLIB_UNUSED(message);
    return 0;
}

// ============== DESERIALIZE ============== //

void bms_deserialize_FLASH_CELLBOARD_4_TX(
    bms_message_FLASH_CELLBOARD_4_TX* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , bms_uint64 _timestamp
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

int bms_to_string_FLASH_CELLBOARD_4_TX(bms_message_FLASH_CELLBOARD_4_TX* message, char* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int bms_fields_FLASH_CELLBOARD_4_TX(char* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

int bms_to_string_file_FLASH_CELLBOARD_4_TX(bms_message_FLASH_CELLBOARD_4_TX* message, FILE* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int bms_fields_file_FLASH_CELLBOARD_4_TX(FILE* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

// ============== SERIALIZE ============== //

bms_byte_size bms_serialize_FLASH_CELLBOARD_4_RX(
    uint8_t* data
) {
    CANLIB_UNUSED(data);
    return 0;
}

bms_byte_size bms_serialize_struct_FLASH_CELLBOARD_4_RX(
    uint8_t* data,
    bms_message_FLASH_CELLBOARD_4_RX* message
) {
    CANLIB_UNUSED(data);
    CANLIB_UNUSED(message);
    return 0;
}

// ============== DESERIALIZE ============== //

void bms_deserialize_FLASH_CELLBOARD_4_RX(
    bms_message_FLASH_CELLBOARD_4_RX* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , bms_uint64 _timestamp
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

int bms_to_string_FLASH_CELLBOARD_4_RX(bms_message_FLASH_CELLBOARD_4_RX* message, char* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int bms_fields_FLASH_CELLBOARD_4_RX(char* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

int bms_to_string_file_FLASH_CELLBOARD_4_RX(bms_message_FLASH_CELLBOARD_4_RX* message, FILE* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int bms_fields_file_FLASH_CELLBOARD_4_RX(FILE* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

// ============== SERIALIZE ============== //

bms_byte_size bms_serialize_FLASH_CELLBOARD_5_TX(
    uint8_t* data
) {
    CANLIB_UNUSED(data);
    return 0;
}

bms_byte_size bms_serialize_struct_FLASH_CELLBOARD_5_TX(
    uint8_t* data,
    bms_message_FLASH_CELLBOARD_5_TX* message
) {
    CANLIB_UNUSED(data);
    CANLIB_UNUSED(message);
    return 0;
}

// ============== DESERIALIZE ============== //

void bms_deserialize_FLASH_CELLBOARD_5_TX(
    bms_message_FLASH_CELLBOARD_5_TX* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , bms_uint64 _timestamp
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

int bms_to_string_FLASH_CELLBOARD_5_TX(bms_message_FLASH_CELLBOARD_5_TX* message, char* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int bms_fields_FLASH_CELLBOARD_5_TX(char* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

int bms_to_string_file_FLASH_CELLBOARD_5_TX(bms_message_FLASH_CELLBOARD_5_TX* message, FILE* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int bms_fields_file_FLASH_CELLBOARD_5_TX(FILE* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

// ============== SERIALIZE ============== //

bms_byte_size bms_serialize_FLASH_CELLBOARD_5_RX(
    uint8_t* data
) {
    CANLIB_UNUSED(data);
    return 0;
}

bms_byte_size bms_serialize_struct_FLASH_CELLBOARD_5_RX(
    uint8_t* data,
    bms_message_FLASH_CELLBOARD_5_RX* message
) {
    CANLIB_UNUSED(data);
    CANLIB_UNUSED(message);
    return 0;
}

// ============== DESERIALIZE ============== //

void bms_deserialize_FLASH_CELLBOARD_5_RX(
    bms_message_FLASH_CELLBOARD_5_RX* message,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , bms_uint64 _timestamp
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

int bms_to_string_FLASH_CELLBOARD_5_RX(bms_message_FLASH_CELLBOARD_5_RX* message, char* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int bms_fields_FLASH_CELLBOARD_5_RX(char* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}

int bms_to_string_file_FLASH_CELLBOARD_5_RX(bms_message_FLASH_CELLBOARD_5_RX* message, FILE* buffer) {
    CANLIB_UNUSED(message);
    CANLIB_UNUSED(buffer);
    return 0;
}

int bms_fields_file_FLASH_CELLBOARD_5_RX(FILE* buffer) {
    CANLIB_UNUSED(buffer);
    return 0;
}


// ============== UTILS ============== //

int bms_fields_from_id(canlib_message_id message_id, char* buffer) {
    switch (message_id) {
        case 1536:
            return bms_fields_BOARD_STATUS(buffer);
        case 1281:
            return bms_fields_TEMPERATURES(buffer);
        case 514:
            return bms_fields_VOLTAGES(buffer);
        case 515:
            return bms_fields_BALANCING(buffer);
        case 10:
            return bms_fields_FW_UPDATE(buffer);
        case 16:
            return bms_fields_FLASH_CELLBOARD_0_TX(buffer);
        case 17:
            return bms_fields_FLASH_CELLBOARD_0_RX(buffer);
        case 18:
            return bms_fields_FLASH_CELLBOARD_1_TX(buffer);
        case 19:
            return bms_fields_FLASH_CELLBOARD_1_RX(buffer);
        case 20:
            return bms_fields_FLASH_CELLBOARD_2_TX(buffer);
        case 21:
            return bms_fields_FLASH_CELLBOARD_2_RX(buffer);
        case 22:
            return bms_fields_FLASH_CELLBOARD_3_TX(buffer);
        case 23:
            return bms_fields_FLASH_CELLBOARD_3_RX(buffer);
        case 24:
            return bms_fields_FLASH_CELLBOARD_4_TX(buffer);
        case 25:
            return bms_fields_FLASH_CELLBOARD_4_RX(buffer);
        case 26:
            return bms_fields_FLASH_CELLBOARD_5_TX(buffer);
        case 27:
            return bms_fields_FLASH_CELLBOARD_5_RX(buffer);
    }
    return 0;
}

int bms_to_string_from_id(canlib_message_id message_id, void* message, char* buffer) {
    switch (message_id) {
        case 1536:
            return bms_to_string_BOARD_STATUS((bms_message_BOARD_STATUS*) message, buffer);
        case 1281:
            return bms_to_string_TEMPERATURES((bms_message_TEMPERATURES_conversion*) message, buffer);
        case 514:
            return bms_to_string_VOLTAGES((bms_message_VOLTAGES_conversion*) message, buffer);
        case 515:
            return bms_to_string_BALANCING((bms_message_BALANCING*) message, buffer);
        case 10:
            return bms_to_string_FW_UPDATE((bms_message_FW_UPDATE*) message, buffer);
        case 16:
            return bms_to_string_FLASH_CELLBOARD_0_TX((bms_message_FLASH_CELLBOARD_0_TX*) message, buffer);
        case 17:
            return bms_to_string_FLASH_CELLBOARD_0_RX((bms_message_FLASH_CELLBOARD_0_RX*) message, buffer);
        case 18:
            return bms_to_string_FLASH_CELLBOARD_1_TX((bms_message_FLASH_CELLBOARD_1_TX*) message, buffer);
        case 19:
            return bms_to_string_FLASH_CELLBOARD_1_RX((bms_message_FLASH_CELLBOARD_1_RX*) message, buffer);
        case 20:
            return bms_to_string_FLASH_CELLBOARD_2_TX((bms_message_FLASH_CELLBOARD_2_TX*) message, buffer);
        case 21:
            return bms_to_string_FLASH_CELLBOARD_2_RX((bms_message_FLASH_CELLBOARD_2_RX*) message, buffer);
        case 22:
            return bms_to_string_FLASH_CELLBOARD_3_TX((bms_message_FLASH_CELLBOARD_3_TX*) message, buffer);
        case 23:
            return bms_to_string_FLASH_CELLBOARD_3_RX((bms_message_FLASH_CELLBOARD_3_RX*) message, buffer);
        case 24:
            return bms_to_string_FLASH_CELLBOARD_4_TX((bms_message_FLASH_CELLBOARD_4_TX*) message, buffer);
        case 25:
            return bms_to_string_FLASH_CELLBOARD_4_RX((bms_message_FLASH_CELLBOARD_4_RX*) message, buffer);
        case 26:
            return bms_to_string_FLASH_CELLBOARD_5_TX((bms_message_FLASH_CELLBOARD_5_TX*) message, buffer);
        case 27:
            return bms_to_string_FLASH_CELLBOARD_5_RX((bms_message_FLASH_CELLBOARD_5_RX*) message, buffer);
    }
    return 0;
}

int bms_fields_file_from_id(canlib_message_id message_id, FILE *buffer) {
    switch (message_id) {
        case 1536:
            return bms_fields_file_BOARD_STATUS(buffer);
        case 1281:
            return bms_fields_file_TEMPERATURES(buffer);
        case 514:
            return bms_fields_file_VOLTAGES(buffer);
        case 515:
            return bms_fields_file_BALANCING(buffer);
        case 10:
            return bms_fields_file_FW_UPDATE(buffer);
        case 16:
            return bms_fields_file_FLASH_CELLBOARD_0_TX(buffer);
        case 17:
            return bms_fields_file_FLASH_CELLBOARD_0_RX(buffer);
        case 18:
            return bms_fields_file_FLASH_CELLBOARD_1_TX(buffer);
        case 19:
            return bms_fields_file_FLASH_CELLBOARD_1_RX(buffer);
        case 20:
            return bms_fields_file_FLASH_CELLBOARD_2_TX(buffer);
        case 21:
            return bms_fields_file_FLASH_CELLBOARD_2_RX(buffer);
        case 22:
            return bms_fields_file_FLASH_CELLBOARD_3_TX(buffer);
        case 23:
            return bms_fields_file_FLASH_CELLBOARD_3_RX(buffer);
        case 24:
            return bms_fields_file_FLASH_CELLBOARD_4_TX(buffer);
        case 25:
            return bms_fields_file_FLASH_CELLBOARD_4_RX(buffer);
        case 26:
            return bms_fields_file_FLASH_CELLBOARD_5_TX(buffer);
        case 27:
            return bms_fields_file_FLASH_CELLBOARD_5_RX(buffer);
    }
    return 0;
}

int bms_to_string_file_from_id(canlib_message_id message_id, void* message, FILE *buffer) {
    switch (message_id) {
        case 1536:
            return bms_to_string_file_BOARD_STATUS((bms_message_BOARD_STATUS*) message, buffer);
        case 1281:
            return bms_to_string_file_TEMPERATURES((bms_message_TEMPERATURES_conversion*) message, buffer);
        case 514:
            return bms_to_string_file_VOLTAGES((bms_message_VOLTAGES_conversion*) message, buffer);
        case 515:
            return bms_to_string_file_BALANCING((bms_message_BALANCING*) message, buffer);
        case 10:
            return bms_to_string_file_FW_UPDATE((bms_message_FW_UPDATE*) message, buffer);
        case 16:
            return bms_to_string_file_FLASH_CELLBOARD_0_TX((bms_message_FLASH_CELLBOARD_0_TX*) message, buffer);
        case 17:
            return bms_to_string_file_FLASH_CELLBOARD_0_RX((bms_message_FLASH_CELLBOARD_0_RX*) message, buffer);
        case 18:
            return bms_to_string_file_FLASH_CELLBOARD_1_TX((bms_message_FLASH_CELLBOARD_1_TX*) message, buffer);
        case 19:
            return bms_to_string_file_FLASH_CELLBOARD_1_RX((bms_message_FLASH_CELLBOARD_1_RX*) message, buffer);
        case 20:
            return bms_to_string_file_FLASH_CELLBOARD_2_TX((bms_message_FLASH_CELLBOARD_2_TX*) message, buffer);
        case 21:
            return bms_to_string_file_FLASH_CELLBOARD_2_RX((bms_message_FLASH_CELLBOARD_2_RX*) message, buffer);
        case 22:
            return bms_to_string_file_FLASH_CELLBOARD_3_TX((bms_message_FLASH_CELLBOARD_3_TX*) message, buffer);
        case 23:
            return bms_to_string_file_FLASH_CELLBOARD_3_RX((bms_message_FLASH_CELLBOARD_3_RX*) message, buffer);
        case 24:
            return bms_to_string_file_FLASH_CELLBOARD_4_TX((bms_message_FLASH_CELLBOARD_4_TX*) message, buffer);
        case 25:
            return bms_to_string_file_FLASH_CELLBOARD_4_RX((bms_message_FLASH_CELLBOARD_4_RX*) message, buffer);
        case 26:
            return bms_to_string_file_FLASH_CELLBOARD_5_TX((bms_message_FLASH_CELLBOARD_5_TX*) message, buffer);
        case 27:
            return bms_to_string_file_FLASH_CELLBOARD_5_RX((bms_message_FLASH_CELLBOARD_5_RX*) message, buffer);
    }
    return 0;
}

void* bms_deserialize_from_id(
    canlib_message_id message_id,
    uint8_t* data,
    void* message_raw,
    void* message_conversion
#ifdef CANLIB_TIMESTAMP
    , bms_uint64 timestamp
#endif // CANLIB_TIMESTAMP
) {
    switch (message_id) {
        case 1536: {
            bms_deserialize_BOARD_STATUS(
                (bms_message_BOARD_STATUS*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 1281: {
            bms_deserialize_TEMPERATURES(
                (bms_message_TEMPERATURES*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            bms_raw_to_conversion_struct_TEMPERATURES(
                (bms_message_TEMPERATURES_conversion*) message_conversion,
                (bms_message_TEMPERATURES*) message_raw
            );
            return message_conversion;
        }
        case 514: {
            bms_deserialize_VOLTAGES(
                (bms_message_VOLTAGES*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            bms_raw_to_conversion_struct_VOLTAGES(
                (bms_message_VOLTAGES_conversion*) message_conversion,
                (bms_message_VOLTAGES*) message_raw
            );
            return message_conversion;
        }
        case 515: {
            bms_deserialize_BALANCING(
                (bms_message_BALANCING*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 10: {
            bms_deserialize_FW_UPDATE(
                (bms_message_FW_UPDATE*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 16: {
            bms_deserialize_FLASH_CELLBOARD_0_TX(
                (bms_message_FLASH_CELLBOARD_0_TX*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 17: {
            bms_deserialize_FLASH_CELLBOARD_0_RX(
                (bms_message_FLASH_CELLBOARD_0_RX*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 18: {
            bms_deserialize_FLASH_CELLBOARD_1_TX(
                (bms_message_FLASH_CELLBOARD_1_TX*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 19: {
            bms_deserialize_FLASH_CELLBOARD_1_RX(
                (bms_message_FLASH_CELLBOARD_1_RX*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 20: {
            bms_deserialize_FLASH_CELLBOARD_2_TX(
                (bms_message_FLASH_CELLBOARD_2_TX*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 21: {
            bms_deserialize_FLASH_CELLBOARD_2_RX(
                (bms_message_FLASH_CELLBOARD_2_RX*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 22: {
            bms_deserialize_FLASH_CELLBOARD_3_TX(
                (bms_message_FLASH_CELLBOARD_3_TX*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 23: {
            bms_deserialize_FLASH_CELLBOARD_3_RX(
                (bms_message_FLASH_CELLBOARD_3_RX*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 24: {
            bms_deserialize_FLASH_CELLBOARD_4_TX(
                (bms_message_FLASH_CELLBOARD_4_TX*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 25: {
            bms_deserialize_FLASH_CELLBOARD_4_RX(
                (bms_message_FLASH_CELLBOARD_4_RX*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 26: {
            bms_deserialize_FLASH_CELLBOARD_5_TX(
                (bms_message_FLASH_CELLBOARD_5_TX*) message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return message_raw;
        }
        case 27: {
            bms_deserialize_FLASH_CELLBOARD_5_RX(
                (bms_message_FLASH_CELLBOARD_5_RX*) message_raw,
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

bms_devices* bms_devices_new() {
    bms_devices* devices = (bms_devices*) malloc(sizeof(bms_devices));
    (*devices)[bms_INDEX_BOARD_STATUS].id = 1536;
    (*devices)[bms_INDEX_BOARD_STATUS].message_raw = (void*) malloc(sizeof(bms_message_BOARD_STATUS));
    (*devices)[bms_INDEX_BOARD_STATUS].message_conversion = NULL;
    (*devices)[bms_INDEX_TEMPERATURES].id = 1281;
    (*devices)[bms_INDEX_TEMPERATURES].message_raw = (void*) malloc(sizeof(bms_message_TEMPERATURES));
    (*devices)[bms_INDEX_TEMPERATURES].message_conversion = (void*) malloc(sizeof(bms_message_TEMPERATURES_conversion));
    (*devices)[bms_INDEX_VOLTAGES].id = 514;
    (*devices)[bms_INDEX_VOLTAGES].message_raw = (void*) malloc(sizeof(bms_message_VOLTAGES));
    (*devices)[bms_INDEX_VOLTAGES].message_conversion = (void*) malloc(sizeof(bms_message_VOLTAGES_conversion));
    (*devices)[bms_INDEX_BALANCING].id = 515;
    (*devices)[bms_INDEX_BALANCING].message_raw = (void*) malloc(sizeof(bms_message_BALANCING));
    (*devices)[bms_INDEX_BALANCING].message_conversion = NULL;
    (*devices)[bms_INDEX_FW_UPDATE].id = 10;
    (*devices)[bms_INDEX_FW_UPDATE].message_raw = (void*) malloc(sizeof(bms_message_FW_UPDATE));
    (*devices)[bms_INDEX_FW_UPDATE].message_conversion = NULL;
    (*devices)[bms_INDEX_FLASH_CELLBOARD_0_TX].id = 16;
    (*devices)[bms_INDEX_FLASH_CELLBOARD_0_TX].message_raw = (void*) malloc(sizeof(bms_message_FLASH_CELLBOARD_0_TX));
    (*devices)[bms_INDEX_FLASH_CELLBOARD_0_TX].message_conversion = NULL;
    (*devices)[bms_INDEX_FLASH_CELLBOARD_0_RX].id = 17;
    (*devices)[bms_INDEX_FLASH_CELLBOARD_0_RX].message_raw = (void*) malloc(sizeof(bms_message_FLASH_CELLBOARD_0_RX));
    (*devices)[bms_INDEX_FLASH_CELLBOARD_0_RX].message_conversion = NULL;
    (*devices)[bms_INDEX_FLASH_CELLBOARD_1_TX].id = 18;
    (*devices)[bms_INDEX_FLASH_CELLBOARD_1_TX].message_raw = (void*) malloc(sizeof(bms_message_FLASH_CELLBOARD_1_TX));
    (*devices)[bms_INDEX_FLASH_CELLBOARD_1_TX].message_conversion = NULL;
    (*devices)[bms_INDEX_FLASH_CELLBOARD_1_RX].id = 19;
    (*devices)[bms_INDEX_FLASH_CELLBOARD_1_RX].message_raw = (void*) malloc(sizeof(bms_message_FLASH_CELLBOARD_1_RX));
    (*devices)[bms_INDEX_FLASH_CELLBOARD_1_RX].message_conversion = NULL;
    (*devices)[bms_INDEX_FLASH_CELLBOARD_2_TX].id = 20;
    (*devices)[bms_INDEX_FLASH_CELLBOARD_2_TX].message_raw = (void*) malloc(sizeof(bms_message_FLASH_CELLBOARD_2_TX));
    (*devices)[bms_INDEX_FLASH_CELLBOARD_2_TX].message_conversion = NULL;
    (*devices)[bms_INDEX_FLASH_CELLBOARD_2_RX].id = 21;
    (*devices)[bms_INDEX_FLASH_CELLBOARD_2_RX].message_raw = (void*) malloc(sizeof(bms_message_FLASH_CELLBOARD_2_RX));
    (*devices)[bms_INDEX_FLASH_CELLBOARD_2_RX].message_conversion = NULL;
    (*devices)[bms_INDEX_FLASH_CELLBOARD_3_TX].id = 22;
    (*devices)[bms_INDEX_FLASH_CELLBOARD_3_TX].message_raw = (void*) malloc(sizeof(bms_message_FLASH_CELLBOARD_3_TX));
    (*devices)[bms_INDEX_FLASH_CELLBOARD_3_TX].message_conversion = NULL;
    (*devices)[bms_INDEX_FLASH_CELLBOARD_3_RX].id = 23;
    (*devices)[bms_INDEX_FLASH_CELLBOARD_3_RX].message_raw = (void*) malloc(sizeof(bms_message_FLASH_CELLBOARD_3_RX));
    (*devices)[bms_INDEX_FLASH_CELLBOARD_3_RX].message_conversion = NULL;
    (*devices)[bms_INDEX_FLASH_CELLBOARD_4_TX].id = 24;
    (*devices)[bms_INDEX_FLASH_CELLBOARD_4_TX].message_raw = (void*) malloc(sizeof(bms_message_FLASH_CELLBOARD_4_TX));
    (*devices)[bms_INDEX_FLASH_CELLBOARD_4_TX].message_conversion = NULL;
    (*devices)[bms_INDEX_FLASH_CELLBOARD_4_RX].id = 25;
    (*devices)[bms_INDEX_FLASH_CELLBOARD_4_RX].message_raw = (void*) malloc(sizeof(bms_message_FLASH_CELLBOARD_4_RX));
    (*devices)[bms_INDEX_FLASH_CELLBOARD_4_RX].message_conversion = NULL;
    (*devices)[bms_INDEX_FLASH_CELLBOARD_5_TX].id = 26;
    (*devices)[bms_INDEX_FLASH_CELLBOARD_5_TX].message_raw = (void*) malloc(sizeof(bms_message_FLASH_CELLBOARD_5_TX));
    (*devices)[bms_INDEX_FLASH_CELLBOARD_5_TX].message_conversion = NULL;
    (*devices)[bms_INDEX_FLASH_CELLBOARD_5_RX].id = 27;
    (*devices)[bms_INDEX_FLASH_CELLBOARD_5_RX].message_raw = (void*) malloc(sizeof(bms_message_FLASH_CELLBOARD_5_RX));
    (*devices)[bms_INDEX_FLASH_CELLBOARD_5_RX].message_conversion = NULL;
    return devices;
}

void bms_devices_free(bms_devices* devices) {
    free((*devices)[bms_INDEX_BOARD_STATUS].message_raw);
    free((*devices)[bms_INDEX_TEMPERATURES].message_raw);
    free((*devices)[bms_INDEX_TEMPERATURES].message_conversion);
    free((*devices)[bms_INDEX_VOLTAGES].message_raw);
    free((*devices)[bms_INDEX_VOLTAGES].message_conversion);
    free((*devices)[bms_INDEX_BALANCING].message_raw);
    free((*devices)[bms_INDEX_FW_UPDATE].message_raw);
    free((*devices)[bms_INDEX_FLASH_CELLBOARD_0_TX].message_raw);
    free((*devices)[bms_INDEX_FLASH_CELLBOARD_0_RX].message_raw);
    free((*devices)[bms_INDEX_FLASH_CELLBOARD_1_TX].message_raw);
    free((*devices)[bms_INDEX_FLASH_CELLBOARD_1_RX].message_raw);
    free((*devices)[bms_INDEX_FLASH_CELLBOARD_2_TX].message_raw);
    free((*devices)[bms_INDEX_FLASH_CELLBOARD_2_RX].message_raw);
    free((*devices)[bms_INDEX_FLASH_CELLBOARD_3_TX].message_raw);
    free((*devices)[bms_INDEX_FLASH_CELLBOARD_3_RX].message_raw);
    free((*devices)[bms_INDEX_FLASH_CELLBOARD_4_TX].message_raw);
    free((*devices)[bms_INDEX_FLASH_CELLBOARD_4_RX].message_raw);
    free((*devices)[bms_INDEX_FLASH_CELLBOARD_5_TX].message_raw);
    free((*devices)[bms_INDEX_FLASH_CELLBOARD_5_RX].message_raw);
    free(devices);
}

void bms_devices_deserialize_from_id(
    bms_devices* devices,
    canlib_message_id message_id,
    uint8_t* data
#ifdef CANLIB_TIMESTAMP
    , bms_uint64 timestamp
#endif // CANLIB_TIMESTAMP
) {
    switch (message_id) {
        case 1536: {
            bms_deserialize_BOARD_STATUS(
                (bms_message_BOARD_STATUS*) &(*devices)[bms_INDEX_BOARD_STATUS].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 1281: {
            bms_deserialize_TEMPERATURES(
                (bms_message_TEMPERATURES*) &(*devices)[bms_INDEX_TEMPERATURES].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            bms_raw_to_conversion_struct_TEMPERATURES(
                (bms_message_TEMPERATURES_conversion*) &(*devices)[bms_INDEX_TEMPERATURES].message_conversion,
                (bms_message_TEMPERATURES*) &(*devices)[bms_INDEX_TEMPERATURES].message_raw
            );
            return;
        }
        case 514: {
            bms_deserialize_VOLTAGES(
                (bms_message_VOLTAGES*) &(*devices)[bms_INDEX_VOLTAGES].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            bms_raw_to_conversion_struct_VOLTAGES(
                (bms_message_VOLTAGES_conversion*) &(*devices)[bms_INDEX_VOLTAGES].message_conversion,
                (bms_message_VOLTAGES*) &(*devices)[bms_INDEX_VOLTAGES].message_raw
            );
            return;
        }
        case 515: {
            bms_deserialize_BALANCING(
                (bms_message_BALANCING*) &(*devices)[bms_INDEX_BALANCING].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 10: {
            bms_deserialize_FW_UPDATE(
                (bms_message_FW_UPDATE*) &(*devices)[bms_INDEX_FW_UPDATE].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 16: {
            bms_deserialize_FLASH_CELLBOARD_0_TX(
                (bms_message_FLASH_CELLBOARD_0_TX*) &(*devices)[bms_INDEX_FLASH_CELLBOARD_0_TX].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 17: {
            bms_deserialize_FLASH_CELLBOARD_0_RX(
                (bms_message_FLASH_CELLBOARD_0_RX*) &(*devices)[bms_INDEX_FLASH_CELLBOARD_0_RX].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 18: {
            bms_deserialize_FLASH_CELLBOARD_1_TX(
                (bms_message_FLASH_CELLBOARD_1_TX*) &(*devices)[bms_INDEX_FLASH_CELLBOARD_1_TX].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 19: {
            bms_deserialize_FLASH_CELLBOARD_1_RX(
                (bms_message_FLASH_CELLBOARD_1_RX*) &(*devices)[bms_INDEX_FLASH_CELLBOARD_1_RX].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 20: {
            bms_deserialize_FLASH_CELLBOARD_2_TX(
                (bms_message_FLASH_CELLBOARD_2_TX*) &(*devices)[bms_INDEX_FLASH_CELLBOARD_2_TX].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 21: {
            bms_deserialize_FLASH_CELLBOARD_2_RX(
                (bms_message_FLASH_CELLBOARD_2_RX*) &(*devices)[bms_INDEX_FLASH_CELLBOARD_2_RX].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 22: {
            bms_deserialize_FLASH_CELLBOARD_3_TX(
                (bms_message_FLASH_CELLBOARD_3_TX*) &(*devices)[bms_INDEX_FLASH_CELLBOARD_3_TX].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 23: {
            bms_deserialize_FLASH_CELLBOARD_3_RX(
                (bms_message_FLASH_CELLBOARD_3_RX*) &(*devices)[bms_INDEX_FLASH_CELLBOARD_3_RX].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 24: {
            bms_deserialize_FLASH_CELLBOARD_4_TX(
                (bms_message_FLASH_CELLBOARD_4_TX*) &(*devices)[bms_INDEX_FLASH_CELLBOARD_4_TX].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 25: {
            bms_deserialize_FLASH_CELLBOARD_4_RX(
                (bms_message_FLASH_CELLBOARD_4_RX*) &(*devices)[bms_INDEX_FLASH_CELLBOARD_4_RX].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 26: {
            bms_deserialize_FLASH_CELLBOARD_5_TX(
                (bms_message_FLASH_CELLBOARD_5_TX*) &(*devices)[bms_INDEX_FLASH_CELLBOARD_5_TX].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
        case 27: {
            bms_deserialize_FLASH_CELLBOARD_5_RX(
                (bms_message_FLASH_CELLBOARD_5_RX*) &(*devices)[bms_INDEX_FLASH_CELLBOARD_5_RX].message_raw,
                data
                #ifdef CANLIB_TIMESTAMP
                , timestamp
                #endif
            );
            return;
        }
    }
}

#endif // bms_NETWORK_IMPLEMENTATION

#ifdef __cplusplus
}
#endif

#endif // bms_NETWORK_H