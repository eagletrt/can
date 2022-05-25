#ifndef secondary_IDS_H
#define secondary_IDS_H

#include <stdint.h>
#include <string.h>

#define secondary_IDS_VERSION 1.0

/* TOPIC FIXED_IDS */
#define secondary_topic_mask_FIXED_IDS 0b00000011111

#define secondary_id_IMU_ANGULAR_RATE 0b10011101100
#define secondary_id_IMU_ACCELERATION 0b10011101101
#define secondary_id_IRTS_FL_0 0b10110110100
#define secondary_id_IRTS_FL_1 0b10110110101
#define secondary_id_IRTS_FL_2 0b10110110110
#define secondary_id_IRTS_FL_3 0b10110110111
#define secondary_id_IRTS_FR_0 0b10110111000
#define secondary_id_IRTS_FR_1 0b10110111001
#define secondary_id_IRTS_FR_2 0b10110111010
#define secondary_id_IRTS_FR_3 0b10110111011
#define secondary_id_IRTS_RL_0 0b10110111100
#define secondary_id_IRTS_RL_1 0b10110111101
#define secondary_id_IRTS_RL_2 0b10110111110
#define secondary_id_IRTS_RL_3 0b10110111111
#define secondary_id_IRTS_RR_0 0b10111000000
#define secondary_id_IRTS_RR_1 0b10111000001
#define secondary_id_IRTS_RR_2 0b10111000010
#define secondary_id_IRTS_RR_3 0b10111000011

/* TOPIC STEER */
#define secondary_topic_mask_STEER 0b00000011111
#define secondary_topic_filter_STEER 0b00000000001

#define secondary_id_GPS_COORDS 0b10000000001
#define secondary_id_GPS_SPEED 0b10000100001
#define secondary_id_LAP_COUNT 0b10001000001


// ============== UTILS ============== //

#define secondary_MAX_MESSAGE_LENGTH 17

#ifdef secondary_IDS_IMPLEMENTATION

int secondary_message_name_from_id(uint16_t id, char *buffer) {
    switch (id) {
        case secondary_id_IMU_ANGULAR_RATE:
            strcpy(buffer, "IMU_ANGULAR_RATE");
            return 0;
        case secondary_id_IMU_ACCELERATION:
            strcpy(buffer, "IMU_ACCELERATION");
            return 0;
        case secondary_id_IRTS_FL_0:
            strcpy(buffer, "IRTS_FL_0");
            return 0;
        case secondary_id_IRTS_FL_1:
            strcpy(buffer, "IRTS_FL_1");
            return 0;
        case secondary_id_IRTS_FL_2:
            strcpy(buffer, "IRTS_FL_2");
            return 0;
        case secondary_id_IRTS_FL_3:
            strcpy(buffer, "IRTS_FL_3");
            return 0;
        case secondary_id_IRTS_FR_0:
            strcpy(buffer, "IRTS_FR_0");
            return 0;
        case secondary_id_IRTS_FR_1:
            strcpy(buffer, "IRTS_FR_1");
            return 0;
        case secondary_id_IRTS_FR_2:
            strcpy(buffer, "IRTS_FR_2");
            return 0;
        case secondary_id_IRTS_FR_3:
            strcpy(buffer, "IRTS_FR_3");
            return 0;
        case secondary_id_IRTS_RL_0:
            strcpy(buffer, "IRTS_RL_0");
            return 0;
        case secondary_id_IRTS_RL_1:
            strcpy(buffer, "IRTS_RL_1");
            return 0;
        case secondary_id_IRTS_RL_2:
            strcpy(buffer, "IRTS_RL_2");
            return 0;
        case secondary_id_IRTS_RL_3:
            strcpy(buffer, "IRTS_RL_3");
            return 0;
        case secondary_id_IRTS_RR_0:
            strcpy(buffer, "IRTS_RR_0");
            return 0;
        case secondary_id_IRTS_RR_1:
            strcpy(buffer, "IRTS_RR_1");
            return 0;
        case secondary_id_IRTS_RR_2:
            strcpy(buffer, "IRTS_RR_2");
            return 0;
        case secondary_id_IRTS_RR_3:
            strcpy(buffer, "IRTS_RR_3");
            return 0;
        case secondary_id_GPS_COORDS:
            strcpy(buffer, "GPS_COORDS");
            return 0;
        case secondary_id_GPS_SPEED:
            strcpy(buffer, "GPS_SPEED");
            return 0;
        case secondary_id_LAP_COUNT:
            strcpy(buffer, "LAP_COUNT");
            return 0;
        default:
            strcpy(buffer, ""); // Unknown message
    }
    return 1;
}

#endif // secondary_IDS_IMPLEMENTATION

#endif // secondary_IDS_H