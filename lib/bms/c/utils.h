#ifndef bms_UTILS_H
#define bms_UTILS_H

#define bms_MAX_MESSAGE_LENGTH 24

void bms_message_name_from_id(uint16_t id, char *buffer) {
    switch (id) {
        case 1536: strcpy(buffer, "BOARD_STATUS_CELLBOARD0"); break;
        case 1568: strcpy(buffer, "BOARD_STATUS_CELLBOARD1"); break;
        case 1600: strcpy(buffer, "BOARD_STATUS_CELLBOARD2"); break;
        case 1632: strcpy(buffer, "BOARD_STATUS_CELLBOARD3"); break;
        case 1664: strcpy(buffer, "BOARD_STATUS_CELLBOARD4"); break;
        case 1696: strcpy(buffer, "BOARD_STATUS_CELLBOARD5"); break;
        case 1281: strcpy(buffer, "TEMPERATURES_CELLBOARD0"); break;
        case 1313: strcpy(buffer, "TEMPERATURES_CELLBOARD1"); break;
        case 1345: strcpy(buffer, "TEMPERATURES_CELLBOARD2"); break;
        case 1377: strcpy(buffer, "TEMPERATURES_CELLBOARD3"); break;
        case 1409: strcpy(buffer, "TEMPERATURES_CELLBOARD4"); break;
        case 1441: strcpy(buffer, "TEMPERATURES_CELLBOARD5"); break;
        case 514: strcpy(buffer, "VOLTAGES_CELLBOARD0"); break;
        case 546: strcpy(buffer, "VOLTAGES_CELLBOARD1"); break;
        case 578: strcpy(buffer, "VOLTAGES_CELLBOARD2"); break;
        case 610: strcpy(buffer, "VOLTAGES_CELLBOARD3"); break;
        case 642: strcpy(buffer, "VOLTAGES_CELLBOARD4"); break;
        case 674: strcpy(buffer, "VOLTAGES_CELLBOARD5"); break;
        case 515: strcpy(buffer, "BALANCING"); break;
        case 260: strcpy(buffer, "FW_UPDATE"); break;
        default: strcpy(buffer, ""); // Unknown message
    }
}

#endif // bms_UTILS_H