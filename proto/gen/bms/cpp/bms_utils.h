#include <string>
#include "bms.pb.h"
extern "C" {
#include "../../../../naked_generator/bms/c/bms.h"
}
#define BITSET_VALUE(bitset, size) \
bitset_value=0; \
current_value=0; \
for(short i = 0; i < size*8; i++){ \
current_value += getBit(bitset, i); \
if(i%8 == 7){ \
short shift_amount = i/8; \
current_value <<= 8*shift_amount; \
bitset_value += current_value; \
current_value = 0; \
} \
}
std::string bms_naked2protobuf(uint32_t id, uint8_t* payload){
uint64_t bitset_value, current_value;
switch(id) {


case {'BOARD_STATUS_CELLBOARD0': 1536, 'BOARD_STATUS_CELLBOARD1': 1568, 'BOARD_STATUS_CELLBOARD2': 1600, 'BOARD_STATUS_CELLBOARD3': 1632, 'BOARD_STATUS_CELLBOARD4': 1664, 'BOARD_STATUS_CELLBOARD5': 1696}:
{
BmsBoardStatusMsg* bms_board_status_d = (BmsBoardStatusMsg*)malloc(BMS_BOARD_STATUS_SIZE);
deserialize_BmsBoardStatus(payload, bms_board_status_d);

bms::BoardStatus bms_board_status_p;
bms_board_status_p.set_errors(bms_board_status_d->);
bms_board_status_p.set_balancing_status(bms_board_status_d->);
bms_board_status_p.set_timestamp(bms_board_status_d->);
free(bms_board_status_d);
std::string serialized;
bms_board_status_p.SerializeToString(&serialized);
return serialized;
}


case {'TEMPERATURES_CELLBOARD0': 1281, 'TEMPERATURES_CELLBOARD1': 1313, 'TEMPERATURES_CELLBOARD2': 1345, 'TEMPERATURES_CELLBOARD3': 1377, 'TEMPERATURES_CELLBOARD4': 1409, 'TEMPERATURES_CELLBOARD5': 1441}:
{
BmsTemperaturesMsg* bms_temperatures_d = (BmsTemperaturesMsg*)malloc(BMS_TEMPERATURES_SIZE);
deserialize_BmsTemperatures(payload, bms_temperatures_d);

bms::Temperatures bms_temperatures_p;
bms_temperatures_p.set_start_index(bms_temperatures_d->);
bms_temperatures_p.set_temp0(bms_temperatures_d->);
bms_temperatures_p.set_temp1(bms_temperatures_d->);
bms_temperatures_p.set_temp2(bms_temperatures_d->);
bms_temperatures_p.set_temp3(bms_temperatures_d->);
bms_temperatures_p.set_temp4(bms_temperatures_d->);
bms_temperatures_p.set_temp5(bms_temperatures_d->);
bms_temperatures_p.set_timestamp(bms_temperatures_d->);
free(bms_temperatures_d);
std::string serialized;
bms_temperatures_p.SerializeToString(&serialized);
return serialized;
}


case {'VOLTAGES_CELLBOARD0': 514, 'VOLTAGES_CELLBOARD1': 546, 'VOLTAGES_CELLBOARD2': 578, 'VOLTAGES_CELLBOARD3': 610, 'VOLTAGES_CELLBOARD4': 642, 'VOLTAGES_CELLBOARD5': 674}:
{
BmsVoltagesMsg* bms_voltages_d = (BmsVoltagesMsg*)malloc(BMS_VOLTAGES_SIZE);
deserialize_BmsVoltages(payload, bms_voltages_d);

bms::Voltages bms_voltages_p;
bms_voltages_p.set_start_index(bms_voltages_d->);
bms_voltages_p.set_voltage0(bms_voltages_d->);
bms_voltages_p.set_voltage1(bms_voltages_d->);
bms_voltages_p.set_voltage2(bms_voltages_d->);
bms_voltages_p.set_timestamp(bms_voltages_d->);
free(bms_voltages_d);
std::string serialized;
bms_voltages_p.SerializeToString(&serialized);
return serialized;
}


case {'BALANCING': 515}:
{
BmsBalancingMsg* bms_balancing_d = (BmsBalancingMsg*)malloc(BMS_BALANCING_SIZE);
deserialize_BmsBalancing(payload, bms_balancing_d);

bms::Balancing bms_balancing_p;
bms_balancing_p.set_board_index(bms_balancing_d->);
bms_balancing_p.set_cells(bms_balancing_d->);
bms_balancing_p.set_timestamp(bms_balancing_d->);
free(bms_balancing_d);
std::string serialized;
bms_balancing_p.SerializeToString(&serialized);
return serialized;
}


case {'FW_UPDATE': 260}:
{
BmsFwUpdateMsg* bms_fw_update_d = (BmsFwUpdateMsg*)malloc(BMS_FW_UPDATE_SIZE);
deserialize_BmsFwUpdate(payload, bms_fw_update_d);

bms::FwUpdate bms_fw_update_p;
bms_fw_update_p.set_board_index(bms_fw_update_d->);
bms_fw_update_p.set_timestamp(bms_fw_update_d->);
free(bms_fw_update_d);
std::string serialized;
bms_fw_update_p.SerializeToString(&serialized);
return serialized;
}

}
throw std::runtime_error("Unknown message id");
}