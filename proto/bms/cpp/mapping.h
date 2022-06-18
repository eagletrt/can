#ifndef bms_MAPPING_H
#define bms_MAPPING_H

#include <string>
#include <vector>

#include "bms.pb.h"

#ifdef bms_IMPLEMENTATION
#undef bms_IMPLEMENTATION
#define __bms_IMPLEMENTATION
#endif

#include "../../../lib/bms/c/network.h"

#ifdef __bms_IMPLEMENTATION
#undef __bms_IMPLEMENTATION
#define bms_IMPLEMENTATION
#endif

#ifndef CANLIB_MESSAGE_ID_TYPE
#define CANLIB_MESSAGE_ID_TYPE
typedef uint16_t canlib_message_id;
#endif // CANLIB_MESSAGE_ID_TYPE

typedef struct {
    std::vector<bms_message_BOARD_STATUS> BOARD_STATUS_CELLBOARD0;
    std::vector<bms_message_BOARD_STATUS> BOARD_STATUS_CELLBOARD1;
    std::vector<bms_message_BOARD_STATUS> BOARD_STATUS_CELLBOARD2;
    std::vector<bms_message_BOARD_STATUS> BOARD_STATUS_CELLBOARD3;
    std::vector<bms_message_BOARD_STATUS> BOARD_STATUS_CELLBOARD4;
    std::vector<bms_message_BOARD_STATUS> BOARD_STATUS_CELLBOARD5;
    std::vector<bms_message_TEMPERATURES_conversion> TEMPERATURES_CELLBOARD0;
    std::vector<bms_message_TEMPERATURES_conversion> TEMPERATURES_CELLBOARD1;
    std::vector<bms_message_TEMPERATURES_conversion> TEMPERATURES_CELLBOARD2;
    std::vector<bms_message_TEMPERATURES_conversion> TEMPERATURES_CELLBOARD3;
    std::vector<bms_message_TEMPERATURES_conversion> TEMPERATURES_CELLBOARD4;
    std::vector<bms_message_TEMPERATURES_conversion> TEMPERATURES_CELLBOARD5;
    std::vector<bms_message_VOLTAGES_conversion> VOLTAGES_CELLBOARD0;
    std::vector<bms_message_VOLTAGES_conversion> VOLTAGES_CELLBOARD1;
    std::vector<bms_message_VOLTAGES_conversion> VOLTAGES_CELLBOARD2;
    std::vector<bms_message_VOLTAGES_conversion> VOLTAGES_CELLBOARD3;
    std::vector<bms_message_VOLTAGES_conversion> VOLTAGES_CELLBOARD4;
    std::vector<bms_message_VOLTAGES_conversion> VOLTAGES_CELLBOARD5;
    std::vector<bms_message_BALANCING> BALANCING;
    std::vector<bms_message_FW_UPDATE> FW_UPDATE;
    std::vector<bms_message_FLASH_CELLBOARD_0_TX> FLASH_CELLBOARD_0_TX;
    std::vector<bms_message_FLASH_CELLBOARD_0_RX> FLASH_CELLBOARD_0_RX;
    std::vector<bms_message_FLASH_CELLBOARD_1_TX> FLASH_CELLBOARD_1_TX;
    std::vector<bms_message_FLASH_CELLBOARD_1_RX> FLASH_CELLBOARD_1_RX;
    std::vector<bms_message_FLASH_CELLBOARD_2_TX> FLASH_CELLBOARD_2_TX;
    std::vector<bms_message_FLASH_CELLBOARD_2_RX> FLASH_CELLBOARD_2_RX;
    std::vector<bms_message_FLASH_CELLBOARD_3_TX> FLASH_CELLBOARD_3_TX;
    std::vector<bms_message_FLASH_CELLBOARD_3_RX> FLASH_CELLBOARD_3_RX;
    std::vector<bms_message_FLASH_CELLBOARD_4_TX> FLASH_CELLBOARD_4_TX;
    std::vector<bms_message_FLASH_CELLBOARD_4_RX> FLASH_CELLBOARD_4_RX;
    std::vector<bms_message_FLASH_CELLBOARD_5_TX> FLASH_CELLBOARD_5_TX;
    std::vector<bms_message_FLASH_CELLBOARD_5_RX> FLASH_CELLBOARD_5_RX;
} bms_proto_pack;

void bms_proto_serialize_from_id(canlib_message_id id, bms::Pack* pack, bms_devices* map);
void bms_proto_deserialize(bms::Pack* pack, bms_proto_pack* map);

#ifdef bms_MAPPING_IMPLEMENTATION

void bms_proto_serialize_from_id(canlib_message_id id, bms::Pack* pack, bms_devices* map) {
    int index = bms_index_from_id(id);

    if (index == -1) return;

    switch(id) {
        case 1536: {
            bms_message_BOARD_STATUS* msg = (bms_message_BOARD_STATUS*) (*map)[index].message_raw;
            bms::BOARD_STATUS_CELLBOARD0* proto_msg = pack->add_board_status_cellboard0();
            proto_msg->set_errors(msg->errors);
            proto_msg->set_balancing_status((bms::BalancingStatus)msg->balancing_status);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1568: {
            bms_message_BOARD_STATUS* msg = (bms_message_BOARD_STATUS*) (*map)[index].message_raw;
            bms::BOARD_STATUS_CELLBOARD1* proto_msg = pack->add_board_status_cellboard1();
            proto_msg->set_errors(msg->errors);
            proto_msg->set_balancing_status((bms::BalancingStatus)msg->balancing_status);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1600: {
            bms_message_BOARD_STATUS* msg = (bms_message_BOARD_STATUS*) (*map)[index].message_raw;
            bms::BOARD_STATUS_CELLBOARD2* proto_msg = pack->add_board_status_cellboard2();
            proto_msg->set_errors(msg->errors);
            proto_msg->set_balancing_status((bms::BalancingStatus)msg->balancing_status);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1632: {
            bms_message_BOARD_STATUS* msg = (bms_message_BOARD_STATUS*) (*map)[index].message_raw;
            bms::BOARD_STATUS_CELLBOARD3* proto_msg = pack->add_board_status_cellboard3();
            proto_msg->set_errors(msg->errors);
            proto_msg->set_balancing_status((bms::BalancingStatus)msg->balancing_status);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1664: {
            bms_message_BOARD_STATUS* msg = (bms_message_BOARD_STATUS*) (*map)[index].message_raw;
            bms::BOARD_STATUS_CELLBOARD4* proto_msg = pack->add_board_status_cellboard4();
            proto_msg->set_errors(msg->errors);
            proto_msg->set_balancing_status((bms::BalancingStatus)msg->balancing_status);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1696: {
            bms_message_BOARD_STATUS* msg = (bms_message_BOARD_STATUS*) (*map)[index].message_raw;
            bms::BOARD_STATUS_CELLBOARD5* proto_msg = pack->add_board_status_cellboard5();
            proto_msg->set_errors(msg->errors);
            proto_msg->set_balancing_status((bms::BalancingStatus)msg->balancing_status);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1281: {
            bms_message_TEMPERATURES_conversion* msg = (bms_message_TEMPERATURES_conversion*) (*map)[index].message_conversion;
            bms::TEMPERATURES_CELLBOARD0* proto_msg = pack->add_temperatures_cellboard0();
            proto_msg->set_start_index(msg->start_index);
            proto_msg->set_temp0(msg->temp0);
            proto_msg->set_temp1(msg->temp1);
            proto_msg->set_temp2(msg->temp2);
            proto_msg->set_temp3(msg->temp3);
            proto_msg->set_temp4(msg->temp4);
            proto_msg->set_temp5(msg->temp5);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1313: {
            bms_message_TEMPERATURES_conversion* msg = (bms_message_TEMPERATURES_conversion*) (*map)[index].message_conversion;
            bms::TEMPERATURES_CELLBOARD1* proto_msg = pack->add_temperatures_cellboard1();
            proto_msg->set_start_index(msg->start_index);
            proto_msg->set_temp0(msg->temp0);
            proto_msg->set_temp1(msg->temp1);
            proto_msg->set_temp2(msg->temp2);
            proto_msg->set_temp3(msg->temp3);
            proto_msg->set_temp4(msg->temp4);
            proto_msg->set_temp5(msg->temp5);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1345: {
            bms_message_TEMPERATURES_conversion* msg = (bms_message_TEMPERATURES_conversion*) (*map)[index].message_conversion;
            bms::TEMPERATURES_CELLBOARD2* proto_msg = pack->add_temperatures_cellboard2();
            proto_msg->set_start_index(msg->start_index);
            proto_msg->set_temp0(msg->temp0);
            proto_msg->set_temp1(msg->temp1);
            proto_msg->set_temp2(msg->temp2);
            proto_msg->set_temp3(msg->temp3);
            proto_msg->set_temp4(msg->temp4);
            proto_msg->set_temp5(msg->temp5);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1377: {
            bms_message_TEMPERATURES_conversion* msg = (bms_message_TEMPERATURES_conversion*) (*map)[index].message_conversion;
            bms::TEMPERATURES_CELLBOARD3* proto_msg = pack->add_temperatures_cellboard3();
            proto_msg->set_start_index(msg->start_index);
            proto_msg->set_temp0(msg->temp0);
            proto_msg->set_temp1(msg->temp1);
            proto_msg->set_temp2(msg->temp2);
            proto_msg->set_temp3(msg->temp3);
            proto_msg->set_temp4(msg->temp4);
            proto_msg->set_temp5(msg->temp5);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1409: {
            bms_message_TEMPERATURES_conversion* msg = (bms_message_TEMPERATURES_conversion*) (*map)[index].message_conversion;
            bms::TEMPERATURES_CELLBOARD4* proto_msg = pack->add_temperatures_cellboard4();
            proto_msg->set_start_index(msg->start_index);
            proto_msg->set_temp0(msg->temp0);
            proto_msg->set_temp1(msg->temp1);
            proto_msg->set_temp2(msg->temp2);
            proto_msg->set_temp3(msg->temp3);
            proto_msg->set_temp4(msg->temp4);
            proto_msg->set_temp5(msg->temp5);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 1441: {
            bms_message_TEMPERATURES_conversion* msg = (bms_message_TEMPERATURES_conversion*) (*map)[index].message_conversion;
            bms::TEMPERATURES_CELLBOARD5* proto_msg = pack->add_temperatures_cellboard5();
            proto_msg->set_start_index(msg->start_index);
            proto_msg->set_temp0(msg->temp0);
            proto_msg->set_temp1(msg->temp1);
            proto_msg->set_temp2(msg->temp2);
            proto_msg->set_temp3(msg->temp3);
            proto_msg->set_temp4(msg->temp4);
            proto_msg->set_temp5(msg->temp5);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 514: {
            bms_message_VOLTAGES_conversion* msg = (bms_message_VOLTAGES_conversion*) (*map)[index].message_conversion;
            bms::VOLTAGES_CELLBOARD0* proto_msg = pack->add_voltages_cellboard0();
            proto_msg->set_voltage0(msg->voltage0);
            proto_msg->set_voltage1(msg->voltage1);
            proto_msg->set_voltage2(msg->voltage2);
            proto_msg->set_start_index(msg->start_index);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 546: {
            bms_message_VOLTAGES_conversion* msg = (bms_message_VOLTAGES_conversion*) (*map)[index].message_conversion;
            bms::VOLTAGES_CELLBOARD1* proto_msg = pack->add_voltages_cellboard1();
            proto_msg->set_voltage0(msg->voltage0);
            proto_msg->set_voltage1(msg->voltage1);
            proto_msg->set_voltage2(msg->voltage2);
            proto_msg->set_start_index(msg->start_index);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 578: {
            bms_message_VOLTAGES_conversion* msg = (bms_message_VOLTAGES_conversion*) (*map)[index].message_conversion;
            bms::VOLTAGES_CELLBOARD2* proto_msg = pack->add_voltages_cellboard2();
            proto_msg->set_voltage0(msg->voltage0);
            proto_msg->set_voltage1(msg->voltage1);
            proto_msg->set_voltage2(msg->voltage2);
            proto_msg->set_start_index(msg->start_index);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 610: {
            bms_message_VOLTAGES_conversion* msg = (bms_message_VOLTAGES_conversion*) (*map)[index].message_conversion;
            bms::VOLTAGES_CELLBOARD3* proto_msg = pack->add_voltages_cellboard3();
            proto_msg->set_voltage0(msg->voltage0);
            proto_msg->set_voltage1(msg->voltage1);
            proto_msg->set_voltage2(msg->voltage2);
            proto_msg->set_start_index(msg->start_index);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 642: {
            bms_message_VOLTAGES_conversion* msg = (bms_message_VOLTAGES_conversion*) (*map)[index].message_conversion;
            bms::VOLTAGES_CELLBOARD4* proto_msg = pack->add_voltages_cellboard4();
            proto_msg->set_voltage0(msg->voltage0);
            proto_msg->set_voltage1(msg->voltage1);
            proto_msg->set_voltage2(msg->voltage2);
            proto_msg->set_start_index(msg->start_index);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 674: {
            bms_message_VOLTAGES_conversion* msg = (bms_message_VOLTAGES_conversion*) (*map)[index].message_conversion;
            bms::VOLTAGES_CELLBOARD5* proto_msg = pack->add_voltages_cellboard5();
            proto_msg->set_voltage0(msg->voltage0);
            proto_msg->set_voltage1(msg->voltage1);
            proto_msg->set_voltage2(msg->voltage2);
            proto_msg->set_start_index(msg->start_index);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 515: {
            bms_message_BALANCING* msg = (bms_message_BALANCING*) (*map)[index].message_raw;
            bms::BALANCING* proto_msg = pack->add_balancing();
            proto_msg->set_cells(msg->cells);
            proto_msg->set_board_index(msg->board_index);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 10: {
            bms_message_FW_UPDATE* msg = (bms_message_FW_UPDATE*) (*map)[index].message_raw;
            bms::FW_UPDATE* proto_msg = pack->add_fw_update();
            proto_msg->set_board_index(msg->board_index);
#ifdef CANLIB_TIMESTAMP
            proto_msg->set__inner_timestamp(msg->_timestamp);
#endif // CANLIB_TIMESTAMP
            break;
        }

        case 16: {
            bms_message_FLASH_CELLBOARD_0_TX* msg = (bms_message_FLASH_CELLBOARD_0_TX*) (*map)[index].message_raw;
            bms::FLASH_CELLBOARD_0_TX* proto_msg = pack->add_flash_cellboard_0_tx();
            break;
        }

        case 17: {
            bms_message_FLASH_CELLBOARD_0_RX* msg = (bms_message_FLASH_CELLBOARD_0_RX*) (*map)[index].message_raw;
            bms::FLASH_CELLBOARD_0_RX* proto_msg = pack->add_flash_cellboard_0_rx();
            break;
        }

        case 18: {
            bms_message_FLASH_CELLBOARD_1_TX* msg = (bms_message_FLASH_CELLBOARD_1_TX*) (*map)[index].message_raw;
            bms::FLASH_CELLBOARD_1_TX* proto_msg = pack->add_flash_cellboard_1_tx();
            break;
        }

        case 19: {
            bms_message_FLASH_CELLBOARD_1_RX* msg = (bms_message_FLASH_CELLBOARD_1_RX*) (*map)[index].message_raw;
            bms::FLASH_CELLBOARD_1_RX* proto_msg = pack->add_flash_cellboard_1_rx();
            break;
        }

        case 20: {
            bms_message_FLASH_CELLBOARD_2_TX* msg = (bms_message_FLASH_CELLBOARD_2_TX*) (*map)[index].message_raw;
            bms::FLASH_CELLBOARD_2_TX* proto_msg = pack->add_flash_cellboard_2_tx();
            break;
        }

        case 21: {
            bms_message_FLASH_CELLBOARD_2_RX* msg = (bms_message_FLASH_CELLBOARD_2_RX*) (*map)[index].message_raw;
            bms::FLASH_CELLBOARD_2_RX* proto_msg = pack->add_flash_cellboard_2_rx();
            break;
        }

        case 22: {
            bms_message_FLASH_CELLBOARD_3_TX* msg = (bms_message_FLASH_CELLBOARD_3_TX*) (*map)[index].message_raw;
            bms::FLASH_CELLBOARD_3_TX* proto_msg = pack->add_flash_cellboard_3_tx();
            break;
        }

        case 23: {
            bms_message_FLASH_CELLBOARD_3_RX* msg = (bms_message_FLASH_CELLBOARD_3_RX*) (*map)[index].message_raw;
            bms::FLASH_CELLBOARD_3_RX* proto_msg = pack->add_flash_cellboard_3_rx();
            break;
        }

        case 24: {
            bms_message_FLASH_CELLBOARD_4_TX* msg = (bms_message_FLASH_CELLBOARD_4_TX*) (*map)[index].message_raw;
            bms::FLASH_CELLBOARD_4_TX* proto_msg = pack->add_flash_cellboard_4_tx();
            break;
        }

        case 25: {
            bms_message_FLASH_CELLBOARD_4_RX* msg = (bms_message_FLASH_CELLBOARD_4_RX*) (*map)[index].message_raw;
            bms::FLASH_CELLBOARD_4_RX* proto_msg = pack->add_flash_cellboard_4_rx();
            break;
        }

        case 26: {
            bms_message_FLASH_CELLBOARD_5_TX* msg = (bms_message_FLASH_CELLBOARD_5_TX*) (*map)[index].message_raw;
            bms::FLASH_CELLBOARD_5_TX* proto_msg = pack->add_flash_cellboard_5_tx();
            break;
        }

        case 27: {
            bms_message_FLASH_CELLBOARD_5_RX* msg = (bms_message_FLASH_CELLBOARD_5_RX*) (*map)[index].message_raw;
            bms::FLASH_CELLBOARD_5_RX* proto_msg = pack->add_flash_cellboard_5_rx();
            break;
        }

    }
}

void bms_proto_deserialize(bms::Pack* pack, bms_proto_pack* map) {
    map->BOARD_STATUS_CELLBOARD0.resize(pack->board_status_cellboard0_size());
    for(int i = 0; i < pack->board_status_cellboard0_size(); i++){
        map->BOARD_STATUS_CELLBOARD0[i].errors =pack->board_status_cellboard0(i).errors();
        map->BOARD_STATUS_CELLBOARD0[i].balancing_status =(bms_BalancingStatus)pack->board_status_cellboard0(i).balancing_status();
#ifdef CANLIB_TIMESTAMP
        map->BOARD_STATUS_CELLBOARD0[i]._timestamp = pack->board_status_cellboard0(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->BOARD_STATUS_CELLBOARD1.resize(pack->board_status_cellboard1_size());
    for(int i = 0; i < pack->board_status_cellboard1_size(); i++){
        map->BOARD_STATUS_CELLBOARD1[i].errors =pack->board_status_cellboard1(i).errors();
        map->BOARD_STATUS_CELLBOARD1[i].balancing_status =(bms_BalancingStatus)pack->board_status_cellboard1(i).balancing_status();
#ifdef CANLIB_TIMESTAMP
        map->BOARD_STATUS_CELLBOARD1[i]._timestamp = pack->board_status_cellboard1(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->BOARD_STATUS_CELLBOARD2.resize(pack->board_status_cellboard2_size());
    for(int i = 0; i < pack->board_status_cellboard2_size(); i++){
        map->BOARD_STATUS_CELLBOARD2[i].errors =pack->board_status_cellboard2(i).errors();
        map->BOARD_STATUS_CELLBOARD2[i].balancing_status =(bms_BalancingStatus)pack->board_status_cellboard2(i).balancing_status();
#ifdef CANLIB_TIMESTAMP
        map->BOARD_STATUS_CELLBOARD2[i]._timestamp = pack->board_status_cellboard2(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->BOARD_STATUS_CELLBOARD3.resize(pack->board_status_cellboard3_size());
    for(int i = 0; i < pack->board_status_cellboard3_size(); i++){
        map->BOARD_STATUS_CELLBOARD3[i].errors =pack->board_status_cellboard3(i).errors();
        map->BOARD_STATUS_CELLBOARD3[i].balancing_status =(bms_BalancingStatus)pack->board_status_cellboard3(i).balancing_status();
#ifdef CANLIB_TIMESTAMP
        map->BOARD_STATUS_CELLBOARD3[i]._timestamp = pack->board_status_cellboard3(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->BOARD_STATUS_CELLBOARD4.resize(pack->board_status_cellboard4_size());
    for(int i = 0; i < pack->board_status_cellboard4_size(); i++){
        map->BOARD_STATUS_CELLBOARD4[i].errors =pack->board_status_cellboard4(i).errors();
        map->BOARD_STATUS_CELLBOARD4[i].balancing_status =(bms_BalancingStatus)pack->board_status_cellboard4(i).balancing_status();
#ifdef CANLIB_TIMESTAMP
        map->BOARD_STATUS_CELLBOARD4[i]._timestamp = pack->board_status_cellboard4(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->BOARD_STATUS_CELLBOARD5.resize(pack->board_status_cellboard5_size());
    for(int i = 0; i < pack->board_status_cellboard5_size(); i++){
        map->BOARD_STATUS_CELLBOARD5[i].errors =pack->board_status_cellboard5(i).errors();
        map->BOARD_STATUS_CELLBOARD5[i].balancing_status =(bms_BalancingStatus)pack->board_status_cellboard5(i).balancing_status();
#ifdef CANLIB_TIMESTAMP
        map->BOARD_STATUS_CELLBOARD5[i]._timestamp = pack->board_status_cellboard5(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->TEMPERATURES_CELLBOARD0.resize(pack->temperatures_cellboard0_size());
    for(int i = 0; i < pack->temperatures_cellboard0_size(); i++){
        map->TEMPERATURES_CELLBOARD0[i].start_index =pack->temperatures_cellboard0(i).start_index();
        map->TEMPERATURES_CELLBOARD0[i].temp0 =pack->temperatures_cellboard0(i).temp0();
        map->TEMPERATURES_CELLBOARD0[i].temp1 =pack->temperatures_cellboard0(i).temp1();
        map->TEMPERATURES_CELLBOARD0[i].temp2 =pack->temperatures_cellboard0(i).temp2();
        map->TEMPERATURES_CELLBOARD0[i].temp3 =pack->temperatures_cellboard0(i).temp3();
        map->TEMPERATURES_CELLBOARD0[i].temp4 =pack->temperatures_cellboard0(i).temp4();
        map->TEMPERATURES_CELLBOARD0[i].temp5 =pack->temperatures_cellboard0(i).temp5();
#ifdef CANLIB_TIMESTAMP
        map->TEMPERATURES_CELLBOARD0[i]._timestamp = pack->temperatures_cellboard0(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->TEMPERATURES_CELLBOARD1.resize(pack->temperatures_cellboard1_size());
    for(int i = 0; i < pack->temperatures_cellboard1_size(); i++){
        map->TEMPERATURES_CELLBOARD1[i].start_index =pack->temperatures_cellboard1(i).start_index();
        map->TEMPERATURES_CELLBOARD1[i].temp0 =pack->temperatures_cellboard1(i).temp0();
        map->TEMPERATURES_CELLBOARD1[i].temp1 =pack->temperatures_cellboard1(i).temp1();
        map->TEMPERATURES_CELLBOARD1[i].temp2 =pack->temperatures_cellboard1(i).temp2();
        map->TEMPERATURES_CELLBOARD1[i].temp3 =pack->temperatures_cellboard1(i).temp3();
        map->TEMPERATURES_CELLBOARD1[i].temp4 =pack->temperatures_cellboard1(i).temp4();
        map->TEMPERATURES_CELLBOARD1[i].temp5 =pack->temperatures_cellboard1(i).temp5();
#ifdef CANLIB_TIMESTAMP
        map->TEMPERATURES_CELLBOARD1[i]._timestamp = pack->temperatures_cellboard1(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->TEMPERATURES_CELLBOARD2.resize(pack->temperatures_cellboard2_size());
    for(int i = 0; i < pack->temperatures_cellboard2_size(); i++){
        map->TEMPERATURES_CELLBOARD2[i].start_index =pack->temperatures_cellboard2(i).start_index();
        map->TEMPERATURES_CELLBOARD2[i].temp0 =pack->temperatures_cellboard2(i).temp0();
        map->TEMPERATURES_CELLBOARD2[i].temp1 =pack->temperatures_cellboard2(i).temp1();
        map->TEMPERATURES_CELLBOARD2[i].temp2 =pack->temperatures_cellboard2(i).temp2();
        map->TEMPERATURES_CELLBOARD2[i].temp3 =pack->temperatures_cellboard2(i).temp3();
        map->TEMPERATURES_CELLBOARD2[i].temp4 =pack->temperatures_cellboard2(i).temp4();
        map->TEMPERATURES_CELLBOARD2[i].temp5 =pack->temperatures_cellboard2(i).temp5();
#ifdef CANLIB_TIMESTAMP
        map->TEMPERATURES_CELLBOARD2[i]._timestamp = pack->temperatures_cellboard2(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->TEMPERATURES_CELLBOARD3.resize(pack->temperatures_cellboard3_size());
    for(int i = 0; i < pack->temperatures_cellboard3_size(); i++){
        map->TEMPERATURES_CELLBOARD3[i].start_index =pack->temperatures_cellboard3(i).start_index();
        map->TEMPERATURES_CELLBOARD3[i].temp0 =pack->temperatures_cellboard3(i).temp0();
        map->TEMPERATURES_CELLBOARD3[i].temp1 =pack->temperatures_cellboard3(i).temp1();
        map->TEMPERATURES_CELLBOARD3[i].temp2 =pack->temperatures_cellboard3(i).temp2();
        map->TEMPERATURES_CELLBOARD3[i].temp3 =pack->temperatures_cellboard3(i).temp3();
        map->TEMPERATURES_CELLBOARD3[i].temp4 =pack->temperatures_cellboard3(i).temp4();
        map->TEMPERATURES_CELLBOARD3[i].temp5 =pack->temperatures_cellboard3(i).temp5();
#ifdef CANLIB_TIMESTAMP
        map->TEMPERATURES_CELLBOARD3[i]._timestamp = pack->temperatures_cellboard3(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->TEMPERATURES_CELLBOARD4.resize(pack->temperatures_cellboard4_size());
    for(int i = 0; i < pack->temperatures_cellboard4_size(); i++){
        map->TEMPERATURES_CELLBOARD4[i].start_index =pack->temperatures_cellboard4(i).start_index();
        map->TEMPERATURES_CELLBOARD4[i].temp0 =pack->temperatures_cellboard4(i).temp0();
        map->TEMPERATURES_CELLBOARD4[i].temp1 =pack->temperatures_cellboard4(i).temp1();
        map->TEMPERATURES_CELLBOARD4[i].temp2 =pack->temperatures_cellboard4(i).temp2();
        map->TEMPERATURES_CELLBOARD4[i].temp3 =pack->temperatures_cellboard4(i).temp3();
        map->TEMPERATURES_CELLBOARD4[i].temp4 =pack->temperatures_cellboard4(i).temp4();
        map->TEMPERATURES_CELLBOARD4[i].temp5 =pack->temperatures_cellboard4(i).temp5();
#ifdef CANLIB_TIMESTAMP
        map->TEMPERATURES_CELLBOARD4[i]._timestamp = pack->temperatures_cellboard4(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->TEMPERATURES_CELLBOARD5.resize(pack->temperatures_cellboard5_size());
    for(int i = 0; i < pack->temperatures_cellboard5_size(); i++){
        map->TEMPERATURES_CELLBOARD5[i].start_index =pack->temperatures_cellboard5(i).start_index();
        map->TEMPERATURES_CELLBOARD5[i].temp0 =pack->temperatures_cellboard5(i).temp0();
        map->TEMPERATURES_CELLBOARD5[i].temp1 =pack->temperatures_cellboard5(i).temp1();
        map->TEMPERATURES_CELLBOARD5[i].temp2 =pack->temperatures_cellboard5(i).temp2();
        map->TEMPERATURES_CELLBOARD5[i].temp3 =pack->temperatures_cellboard5(i).temp3();
        map->TEMPERATURES_CELLBOARD5[i].temp4 =pack->temperatures_cellboard5(i).temp4();
        map->TEMPERATURES_CELLBOARD5[i].temp5 =pack->temperatures_cellboard5(i).temp5();
#ifdef CANLIB_TIMESTAMP
        map->TEMPERATURES_CELLBOARD5[i]._timestamp = pack->temperatures_cellboard5(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->VOLTAGES_CELLBOARD0.resize(pack->voltages_cellboard0_size());
    for(int i = 0; i < pack->voltages_cellboard0_size(); i++){
        map->VOLTAGES_CELLBOARD0[i].voltage0 =pack->voltages_cellboard0(i).voltage0();
        map->VOLTAGES_CELLBOARD0[i].voltage1 =pack->voltages_cellboard0(i).voltage1();
        map->VOLTAGES_CELLBOARD0[i].voltage2 =pack->voltages_cellboard0(i).voltage2();
        map->VOLTAGES_CELLBOARD0[i].start_index =pack->voltages_cellboard0(i).start_index();
#ifdef CANLIB_TIMESTAMP
        map->VOLTAGES_CELLBOARD0[i]._timestamp = pack->voltages_cellboard0(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->VOLTAGES_CELLBOARD1.resize(pack->voltages_cellboard1_size());
    for(int i = 0; i < pack->voltages_cellboard1_size(); i++){
        map->VOLTAGES_CELLBOARD1[i].voltage0 =pack->voltages_cellboard1(i).voltage0();
        map->VOLTAGES_CELLBOARD1[i].voltage1 =pack->voltages_cellboard1(i).voltage1();
        map->VOLTAGES_CELLBOARD1[i].voltage2 =pack->voltages_cellboard1(i).voltage2();
        map->VOLTAGES_CELLBOARD1[i].start_index =pack->voltages_cellboard1(i).start_index();
#ifdef CANLIB_TIMESTAMP
        map->VOLTAGES_CELLBOARD1[i]._timestamp = pack->voltages_cellboard1(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->VOLTAGES_CELLBOARD2.resize(pack->voltages_cellboard2_size());
    for(int i = 0; i < pack->voltages_cellboard2_size(); i++){
        map->VOLTAGES_CELLBOARD2[i].voltage0 =pack->voltages_cellboard2(i).voltage0();
        map->VOLTAGES_CELLBOARD2[i].voltage1 =pack->voltages_cellboard2(i).voltage1();
        map->VOLTAGES_CELLBOARD2[i].voltage2 =pack->voltages_cellboard2(i).voltage2();
        map->VOLTAGES_CELLBOARD2[i].start_index =pack->voltages_cellboard2(i).start_index();
#ifdef CANLIB_TIMESTAMP
        map->VOLTAGES_CELLBOARD2[i]._timestamp = pack->voltages_cellboard2(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->VOLTAGES_CELLBOARD3.resize(pack->voltages_cellboard3_size());
    for(int i = 0; i < pack->voltages_cellboard3_size(); i++){
        map->VOLTAGES_CELLBOARD3[i].voltage0 =pack->voltages_cellboard3(i).voltage0();
        map->VOLTAGES_CELLBOARD3[i].voltage1 =pack->voltages_cellboard3(i).voltage1();
        map->VOLTAGES_CELLBOARD3[i].voltage2 =pack->voltages_cellboard3(i).voltage2();
        map->VOLTAGES_CELLBOARD3[i].start_index =pack->voltages_cellboard3(i).start_index();
#ifdef CANLIB_TIMESTAMP
        map->VOLTAGES_CELLBOARD3[i]._timestamp = pack->voltages_cellboard3(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->VOLTAGES_CELLBOARD4.resize(pack->voltages_cellboard4_size());
    for(int i = 0; i < pack->voltages_cellboard4_size(); i++){
        map->VOLTAGES_CELLBOARD4[i].voltage0 =pack->voltages_cellboard4(i).voltage0();
        map->VOLTAGES_CELLBOARD4[i].voltage1 =pack->voltages_cellboard4(i).voltage1();
        map->VOLTAGES_CELLBOARD4[i].voltage2 =pack->voltages_cellboard4(i).voltage2();
        map->VOLTAGES_CELLBOARD4[i].start_index =pack->voltages_cellboard4(i).start_index();
#ifdef CANLIB_TIMESTAMP
        map->VOLTAGES_CELLBOARD4[i]._timestamp = pack->voltages_cellboard4(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->VOLTAGES_CELLBOARD5.resize(pack->voltages_cellboard5_size());
    for(int i = 0; i < pack->voltages_cellboard5_size(); i++){
        map->VOLTAGES_CELLBOARD5[i].voltage0 =pack->voltages_cellboard5(i).voltage0();
        map->VOLTAGES_CELLBOARD5[i].voltage1 =pack->voltages_cellboard5(i).voltage1();
        map->VOLTAGES_CELLBOARD5[i].voltage2 =pack->voltages_cellboard5(i).voltage2();
        map->VOLTAGES_CELLBOARD5[i].start_index =pack->voltages_cellboard5(i).start_index();
#ifdef CANLIB_TIMESTAMP
        map->VOLTAGES_CELLBOARD5[i]._timestamp = pack->voltages_cellboard5(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->BALANCING.resize(pack->balancing_size());
    for(int i = 0; i < pack->balancing_size(); i++){
        map->BALANCING[i].cells =pack->balancing(i).cells();
        map->BALANCING[i].board_index =pack->balancing(i).board_index();
#ifdef CANLIB_TIMESTAMP
        map->BALANCING[i]._timestamp = pack->balancing(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->FW_UPDATE.resize(pack->fw_update_size());
    for(int i = 0; i < pack->fw_update_size(); i++){
        map->FW_UPDATE[i].board_index =pack->fw_update(i).board_index();
#ifdef CANLIB_TIMESTAMP
        map->FW_UPDATE[i]._timestamp = pack->fw_update(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->FLASH_CELLBOARD_0_TX.resize(pack->flash_cellboard_0_tx_size());
    for(int i = 0; i < pack->flash_cellboard_0_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        map->FLASH_CELLBOARD_0_TX[i]._timestamp = pack->flash_cellboard_0_tx(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->FLASH_CELLBOARD_0_RX.resize(pack->flash_cellboard_0_rx_size());
    for(int i = 0; i < pack->flash_cellboard_0_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        map->FLASH_CELLBOARD_0_RX[i]._timestamp = pack->flash_cellboard_0_rx(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->FLASH_CELLBOARD_1_TX.resize(pack->flash_cellboard_1_tx_size());
    for(int i = 0; i < pack->flash_cellboard_1_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        map->FLASH_CELLBOARD_1_TX[i]._timestamp = pack->flash_cellboard_1_tx(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->FLASH_CELLBOARD_1_RX.resize(pack->flash_cellboard_1_rx_size());
    for(int i = 0; i < pack->flash_cellboard_1_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        map->FLASH_CELLBOARD_1_RX[i]._timestamp = pack->flash_cellboard_1_rx(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->FLASH_CELLBOARD_2_TX.resize(pack->flash_cellboard_2_tx_size());
    for(int i = 0; i < pack->flash_cellboard_2_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        map->FLASH_CELLBOARD_2_TX[i]._timestamp = pack->flash_cellboard_2_tx(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->FLASH_CELLBOARD_2_RX.resize(pack->flash_cellboard_2_rx_size());
    for(int i = 0; i < pack->flash_cellboard_2_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        map->FLASH_CELLBOARD_2_RX[i]._timestamp = pack->flash_cellboard_2_rx(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->FLASH_CELLBOARD_3_TX.resize(pack->flash_cellboard_3_tx_size());
    for(int i = 0; i < pack->flash_cellboard_3_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        map->FLASH_CELLBOARD_3_TX[i]._timestamp = pack->flash_cellboard_3_tx(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->FLASH_CELLBOARD_3_RX.resize(pack->flash_cellboard_3_rx_size());
    for(int i = 0; i < pack->flash_cellboard_3_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        map->FLASH_CELLBOARD_3_RX[i]._timestamp = pack->flash_cellboard_3_rx(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->FLASH_CELLBOARD_4_TX.resize(pack->flash_cellboard_4_tx_size());
    for(int i = 0; i < pack->flash_cellboard_4_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        map->FLASH_CELLBOARD_4_TX[i]._timestamp = pack->flash_cellboard_4_tx(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->FLASH_CELLBOARD_4_RX.resize(pack->flash_cellboard_4_rx_size());
    for(int i = 0; i < pack->flash_cellboard_4_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        map->FLASH_CELLBOARD_4_RX[i]._timestamp = pack->flash_cellboard_4_rx(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->FLASH_CELLBOARD_5_TX.resize(pack->flash_cellboard_5_tx_size());
    for(int i = 0; i < pack->flash_cellboard_5_tx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        map->FLASH_CELLBOARD_5_TX[i]._timestamp = pack->flash_cellboard_5_tx(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
    map->FLASH_CELLBOARD_5_RX.resize(pack->flash_cellboard_5_rx_size());
    for(int i = 0; i < pack->flash_cellboard_5_rx_size(); i++){
#ifdef CANLIB_TIMESTAMP
        map->FLASH_CELLBOARD_5_RX[i]._timestamp = pack->flash_cellboard_5_rx(i)._inner_timestamp();
#endif // CANLIB_TIMESTAMP
    }
}

#endif // bms_MAPPING_IMPLEMENTATION

#endif // bms_MAPPING_H