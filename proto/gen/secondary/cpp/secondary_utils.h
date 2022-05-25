#include <string>
#include "secondary.pb.h"
extern "C" {
#include "../../../../naked_generator/secondary/c/secondary.h"
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
std::string secondary_naked2protobuf(uint32_t id, uint8_t* payload){
uint64_t bitset_value, current_value;
switch(id) {


case {'IMU_ANGULAR_RATE': 1260}:
{
SecondaryImuAngularRateMsg* secondary_imu_angular_rate_d = (SecondaryImuAngularRateMsg*)malloc(SECONDARY_IMU_ANGULAR_RATE_SIZE);
deserialize_SecondaryImuAngularRate(payload, secondary_imu_angular_rate_d);

secondary::ImuAngularRate secondary_imu_angular_rate_p;
secondary_imu_angular_rate_p.set_ang_rate_x(secondary_imu_angular_rate_d->);
secondary_imu_angular_rate_p.set_ang_rate_y(secondary_imu_angular_rate_d->);
secondary_imu_angular_rate_p.set_ang_rate_z(secondary_imu_angular_rate_d->);
secondary_imu_angular_rate_p.set__timestamp(secondary_imu_angular_rate_d->);
free(secondary_imu_angular_rate_d);
std::string serialized;
secondary_imu_angular_rate_p.SerializeToString(&serialized);
return serialized;
}


case {'IMU_ACCELERATION': 1261}:
{
SecondaryImuAccelerationMsg* secondary_imu_acceleration_d = (SecondaryImuAccelerationMsg*)malloc(SECONDARY_IMU_ACCELERATION_SIZE);
deserialize_SecondaryImuAcceleration(payload, secondary_imu_acceleration_d);

secondary::ImuAcceleration secondary_imu_acceleration_p;
secondary_imu_acceleration_p.set_accel_x(secondary_imu_acceleration_d->);
secondary_imu_acceleration_p.set_accel_y(secondary_imu_acceleration_d->);
secondary_imu_acceleration_p.set_accel_z(secondary_imu_acceleration_d->);
secondary_imu_acceleration_p.set__timestamp(secondary_imu_acceleration_d->);
free(secondary_imu_acceleration_d);
std::string serialized;
secondary_imu_acceleration_p.SerializeToString(&serialized);
return serialized;
}


case {'IRTS_FL_0': 1460}:
{
SecondaryIrtsFl0Msg* secondary_irts_fl_0_d = (SecondaryIrtsFl0Msg*)malloc(SECONDARY_IRTS_FL_0_SIZE);
deserialize_SecondaryIrtsFl0(payload, secondary_irts_fl_0_d);

secondary::IrtsFl0 secondary_irts_fl_0_p;
secondary_irts_fl_0_p.set_channel1(secondary_irts_fl_0_d->);
secondary_irts_fl_0_p.set_channel2(secondary_irts_fl_0_d->);
secondary_irts_fl_0_p.set_channel3(secondary_irts_fl_0_d->);
secondary_irts_fl_0_p.set_channel4(secondary_irts_fl_0_d->);
secondary_irts_fl_0_p.set__timestamp(secondary_irts_fl_0_d->);
free(secondary_irts_fl_0_d);
std::string serialized;
secondary_irts_fl_0_p.SerializeToString(&serialized);
return serialized;
}


case {'IRTS_FL_1': 1461}:
{
SecondaryIrtsFl1Msg* secondary_irts_fl_1_d = (SecondaryIrtsFl1Msg*)malloc(SECONDARY_IRTS_FL_1_SIZE);
deserialize_SecondaryIrtsFl1(payload, secondary_irts_fl_1_d);

secondary::IrtsFl1 secondary_irts_fl_1_p;
secondary_irts_fl_1_p.set_channel5(secondary_irts_fl_1_d->);
secondary_irts_fl_1_p.set_channel6(secondary_irts_fl_1_d->);
secondary_irts_fl_1_p.set_channel7(secondary_irts_fl_1_d->);
secondary_irts_fl_1_p.set_channel8(secondary_irts_fl_1_d->);
secondary_irts_fl_1_p.set__timestamp(secondary_irts_fl_1_d->);
free(secondary_irts_fl_1_d);
std::string serialized;
secondary_irts_fl_1_p.SerializeToString(&serialized);
return serialized;
}


case {'IRTS_FL_2': 1462}:
{
SecondaryIrtsFl2Msg* secondary_irts_fl_2_d = (SecondaryIrtsFl2Msg*)malloc(SECONDARY_IRTS_FL_2_SIZE);
deserialize_SecondaryIrtsFl2(payload, secondary_irts_fl_2_d);

secondary::IrtsFl2 secondary_irts_fl_2_p;
secondary_irts_fl_2_p.set_channel9(secondary_irts_fl_2_d->);
secondary_irts_fl_2_p.set_channel10(secondary_irts_fl_2_d->);
secondary_irts_fl_2_p.set_channel11(secondary_irts_fl_2_d->);
secondary_irts_fl_2_p.set_channel12(secondary_irts_fl_2_d->);
secondary_irts_fl_2_p.set__timestamp(secondary_irts_fl_2_d->);
free(secondary_irts_fl_2_d);
std::string serialized;
secondary_irts_fl_2_p.SerializeToString(&serialized);
return serialized;
}


case {'IRTS_FL_3': 1463}:
{
SecondaryIrtsFl3Msg* secondary_irts_fl_3_d = (SecondaryIrtsFl3Msg*)malloc(SECONDARY_IRTS_FL_3_SIZE);
deserialize_SecondaryIrtsFl3(payload, secondary_irts_fl_3_d);

secondary::IrtsFl3 secondary_irts_fl_3_p;
secondary_irts_fl_3_p.set_channel13(secondary_irts_fl_3_d->);
secondary_irts_fl_3_p.set_channel14(secondary_irts_fl_3_d->);
secondary_irts_fl_3_p.set_channel15(secondary_irts_fl_3_d->);
secondary_irts_fl_3_p.set_channel16(secondary_irts_fl_3_d->);
secondary_irts_fl_3_p.set__timestamp(secondary_irts_fl_3_d->);
free(secondary_irts_fl_3_d);
std::string serialized;
secondary_irts_fl_3_p.SerializeToString(&serialized);
return serialized;
}


case {'IRTS_FR_0': 1464}:
{
SecondaryIrtsFr0Msg* secondary_irts_fr_0_d = (SecondaryIrtsFr0Msg*)malloc(SECONDARY_IRTS_FR_0_SIZE);
deserialize_SecondaryIrtsFr0(payload, secondary_irts_fr_0_d);

secondary::IrtsFr0 secondary_irts_fr_0_p;
secondary_irts_fr_0_p.set_channel1(secondary_irts_fr_0_d->);
secondary_irts_fr_0_p.set_channel2(secondary_irts_fr_0_d->);
secondary_irts_fr_0_p.set_channel3(secondary_irts_fr_0_d->);
secondary_irts_fr_0_p.set_channel4(secondary_irts_fr_0_d->);
secondary_irts_fr_0_p.set__timestamp(secondary_irts_fr_0_d->);
free(secondary_irts_fr_0_d);
std::string serialized;
secondary_irts_fr_0_p.SerializeToString(&serialized);
return serialized;
}


case {'IRTS_FR_1': 1465}:
{
SecondaryIrtsFr1Msg* secondary_irts_fr_1_d = (SecondaryIrtsFr1Msg*)malloc(SECONDARY_IRTS_FR_1_SIZE);
deserialize_SecondaryIrtsFr1(payload, secondary_irts_fr_1_d);

secondary::IrtsFr1 secondary_irts_fr_1_p;
secondary_irts_fr_1_p.set_channel5(secondary_irts_fr_1_d->);
secondary_irts_fr_1_p.set_channel6(secondary_irts_fr_1_d->);
secondary_irts_fr_1_p.set_channel7(secondary_irts_fr_1_d->);
secondary_irts_fr_1_p.set_channel8(secondary_irts_fr_1_d->);
secondary_irts_fr_1_p.set__timestamp(secondary_irts_fr_1_d->);
free(secondary_irts_fr_1_d);
std::string serialized;
secondary_irts_fr_1_p.SerializeToString(&serialized);
return serialized;
}


case {'IRTS_FR_2': 1466}:
{
SecondaryIrtsFr2Msg* secondary_irts_fr_2_d = (SecondaryIrtsFr2Msg*)malloc(SECONDARY_IRTS_FR_2_SIZE);
deserialize_SecondaryIrtsFr2(payload, secondary_irts_fr_2_d);

secondary::IrtsFr2 secondary_irts_fr_2_p;
secondary_irts_fr_2_p.set_channel9(secondary_irts_fr_2_d->);
secondary_irts_fr_2_p.set_channel10(secondary_irts_fr_2_d->);
secondary_irts_fr_2_p.set_channel11(secondary_irts_fr_2_d->);
secondary_irts_fr_2_p.set_channel12(secondary_irts_fr_2_d->);
secondary_irts_fr_2_p.set__timestamp(secondary_irts_fr_2_d->);
free(secondary_irts_fr_2_d);
std::string serialized;
secondary_irts_fr_2_p.SerializeToString(&serialized);
return serialized;
}


case {'IRTS_FR_3': 1467}:
{
SecondaryIrtsFr3Msg* secondary_irts_fr_3_d = (SecondaryIrtsFr3Msg*)malloc(SECONDARY_IRTS_FR_3_SIZE);
deserialize_SecondaryIrtsFr3(payload, secondary_irts_fr_3_d);

secondary::IrtsFr3 secondary_irts_fr_3_p;
secondary_irts_fr_3_p.set_channel13(secondary_irts_fr_3_d->);
secondary_irts_fr_3_p.set_channel14(secondary_irts_fr_3_d->);
secondary_irts_fr_3_p.set_channel15(secondary_irts_fr_3_d->);
secondary_irts_fr_3_p.set_channel16(secondary_irts_fr_3_d->);
secondary_irts_fr_3_p.set__timestamp(secondary_irts_fr_3_d->);
free(secondary_irts_fr_3_d);
std::string serialized;
secondary_irts_fr_3_p.SerializeToString(&serialized);
return serialized;
}


case {'IRTS_RL_0': 1468}:
{
SecondaryIrtsRl0Msg* secondary_irts_rl_0_d = (SecondaryIrtsRl0Msg*)malloc(SECONDARY_IRTS_RL_0_SIZE);
deserialize_SecondaryIrtsRl0(payload, secondary_irts_rl_0_d);

secondary::IrtsRl0 secondary_irts_rl_0_p;
secondary_irts_rl_0_p.set_channel1(secondary_irts_rl_0_d->);
secondary_irts_rl_0_p.set_channel2(secondary_irts_rl_0_d->);
secondary_irts_rl_0_p.set_channel3(secondary_irts_rl_0_d->);
secondary_irts_rl_0_p.set_channel4(secondary_irts_rl_0_d->);
secondary_irts_rl_0_p.set__timestamp(secondary_irts_rl_0_d->);
free(secondary_irts_rl_0_d);
std::string serialized;
secondary_irts_rl_0_p.SerializeToString(&serialized);
return serialized;
}


case {'IRTS_RL_1': 1469}:
{
SecondaryIrtsRl1Msg* secondary_irts_rl_1_d = (SecondaryIrtsRl1Msg*)malloc(SECONDARY_IRTS_RL_1_SIZE);
deserialize_SecondaryIrtsRl1(payload, secondary_irts_rl_1_d);

secondary::IrtsRl1 secondary_irts_rl_1_p;
secondary_irts_rl_1_p.set_channel5(secondary_irts_rl_1_d->);
secondary_irts_rl_1_p.set_channel6(secondary_irts_rl_1_d->);
secondary_irts_rl_1_p.set_channel7(secondary_irts_rl_1_d->);
secondary_irts_rl_1_p.set_channel8(secondary_irts_rl_1_d->);
secondary_irts_rl_1_p.set__timestamp(secondary_irts_rl_1_d->);
free(secondary_irts_rl_1_d);
std::string serialized;
secondary_irts_rl_1_p.SerializeToString(&serialized);
return serialized;
}


case {'IRTS_RL_2': 1470}:
{
SecondaryIrtsRl2Msg* secondary_irts_rl_2_d = (SecondaryIrtsRl2Msg*)malloc(SECONDARY_IRTS_RL_2_SIZE);
deserialize_SecondaryIrtsRl2(payload, secondary_irts_rl_2_d);

secondary::IrtsRl2 secondary_irts_rl_2_p;
secondary_irts_rl_2_p.set_channel9(secondary_irts_rl_2_d->);
secondary_irts_rl_2_p.set_channel10(secondary_irts_rl_2_d->);
secondary_irts_rl_2_p.set_channel11(secondary_irts_rl_2_d->);
secondary_irts_rl_2_p.set_channel12(secondary_irts_rl_2_d->);
secondary_irts_rl_2_p.set__timestamp(secondary_irts_rl_2_d->);
free(secondary_irts_rl_2_d);
std::string serialized;
secondary_irts_rl_2_p.SerializeToString(&serialized);
return serialized;
}


case {'IRTS_RL_3': 1471}:
{
SecondaryIrtsRl3Msg* secondary_irts_rl_3_d = (SecondaryIrtsRl3Msg*)malloc(SECONDARY_IRTS_RL_3_SIZE);
deserialize_SecondaryIrtsRl3(payload, secondary_irts_rl_3_d);

secondary::IrtsRl3 secondary_irts_rl_3_p;
secondary_irts_rl_3_p.set_channel13(secondary_irts_rl_3_d->);
secondary_irts_rl_3_p.set_channel14(secondary_irts_rl_3_d->);
secondary_irts_rl_3_p.set_channel15(secondary_irts_rl_3_d->);
secondary_irts_rl_3_p.set_channel16(secondary_irts_rl_3_d->);
secondary_irts_rl_3_p.set__timestamp(secondary_irts_rl_3_d->);
free(secondary_irts_rl_3_d);
std::string serialized;
secondary_irts_rl_3_p.SerializeToString(&serialized);
return serialized;
}


case {'IRTS_RR_0': 1472}:
{
SecondaryIrtsRr0Msg* secondary_irts_rr_0_d = (SecondaryIrtsRr0Msg*)malloc(SECONDARY_IRTS_RR_0_SIZE);
deserialize_SecondaryIrtsRr0(payload, secondary_irts_rr_0_d);

secondary::IrtsRr0 secondary_irts_rr_0_p;
secondary_irts_rr_0_p.set_channel1(secondary_irts_rr_0_d->);
secondary_irts_rr_0_p.set_channel2(secondary_irts_rr_0_d->);
secondary_irts_rr_0_p.set_channel3(secondary_irts_rr_0_d->);
secondary_irts_rr_0_p.set_channel4(secondary_irts_rr_0_d->);
secondary_irts_rr_0_p.set__timestamp(secondary_irts_rr_0_d->);
free(secondary_irts_rr_0_d);
std::string serialized;
secondary_irts_rr_0_p.SerializeToString(&serialized);
return serialized;
}


case {'IRTS_RR_1': 1473}:
{
SecondaryIrtsRr1Msg* secondary_irts_rr_1_d = (SecondaryIrtsRr1Msg*)malloc(SECONDARY_IRTS_RR_1_SIZE);
deserialize_SecondaryIrtsRr1(payload, secondary_irts_rr_1_d);

secondary::IrtsRr1 secondary_irts_rr_1_p;
secondary_irts_rr_1_p.set_channel5(secondary_irts_rr_1_d->);
secondary_irts_rr_1_p.set_channel6(secondary_irts_rr_1_d->);
secondary_irts_rr_1_p.set_channel7(secondary_irts_rr_1_d->);
secondary_irts_rr_1_p.set_channel8(secondary_irts_rr_1_d->);
secondary_irts_rr_1_p.set__timestamp(secondary_irts_rr_1_d->);
free(secondary_irts_rr_1_d);
std::string serialized;
secondary_irts_rr_1_p.SerializeToString(&serialized);
return serialized;
}


case {'IRTS_RR_2': 1474}:
{
SecondaryIrtsRr2Msg* secondary_irts_rr_2_d = (SecondaryIrtsRr2Msg*)malloc(SECONDARY_IRTS_RR_2_SIZE);
deserialize_SecondaryIrtsRr2(payload, secondary_irts_rr_2_d);

secondary::IrtsRr2 secondary_irts_rr_2_p;
secondary_irts_rr_2_p.set_channel9(secondary_irts_rr_2_d->);
secondary_irts_rr_2_p.set_channel10(secondary_irts_rr_2_d->);
secondary_irts_rr_2_p.set_channel11(secondary_irts_rr_2_d->);
secondary_irts_rr_2_p.set_channel12(secondary_irts_rr_2_d->);
secondary_irts_rr_2_p.set__timestamp(secondary_irts_rr_2_d->);
free(secondary_irts_rr_2_d);
std::string serialized;
secondary_irts_rr_2_p.SerializeToString(&serialized);
return serialized;
}


case {'IRTS_RR_3': 1475}:
{
SecondaryIrtsRr3Msg* secondary_irts_rr_3_d = (SecondaryIrtsRr3Msg*)malloc(SECONDARY_IRTS_RR_3_SIZE);
deserialize_SecondaryIrtsRr3(payload, secondary_irts_rr_3_d);

secondary::IrtsRr3 secondary_irts_rr_3_p;
secondary_irts_rr_3_p.set_channel13(secondary_irts_rr_3_d->);
secondary_irts_rr_3_p.set_channel14(secondary_irts_rr_3_d->);
secondary_irts_rr_3_p.set_channel15(secondary_irts_rr_3_d->);
secondary_irts_rr_3_p.set_channel16(secondary_irts_rr_3_d->);
secondary_irts_rr_3_p.set__timestamp(secondary_irts_rr_3_d->);
free(secondary_irts_rr_3_d);
std::string serialized;
secondary_irts_rr_3_p.SerializeToString(&serialized);
return serialized;
}


case {'GPS_COORDS': 1025}:
{
SecondaryGpsCoordsMsg* secondary_gps_coords_d = (SecondaryGpsCoordsMsg*)malloc(SECONDARY_GPS_COORDS_SIZE);
deserialize_SecondaryGpsCoords(payload, secondary_gps_coords_d);

secondary::GpsCoords secondary_gps_coords_p;
secondary_gps_coords_p.set_latitude(secondary_gps_coords_d->);
secondary_gps_coords_p.set_longitude(secondary_gps_coords_d->);
secondary_gps_coords_p.set__timestamp(secondary_gps_coords_d->);
free(secondary_gps_coords_d);
std::string serialized;
secondary_gps_coords_p.SerializeToString(&serialized);
return serialized;
}


case {'GPS_SPEED': 1057}:
{
SecondaryGpsSpeedMsg* secondary_gps_speed_d = (SecondaryGpsSpeedMsg*)malloc(SECONDARY_GPS_SPEED_SIZE);
deserialize_SecondaryGpsSpeed(payload, secondary_gps_speed_d);

secondary::GpsSpeed secondary_gps_speed_p;
secondary_gps_speed_p.set_speed(secondary_gps_speed_d->);
secondary_gps_speed_p.set__timestamp(secondary_gps_speed_d->);
free(secondary_gps_speed_d);
std::string serialized;
secondary_gps_speed_p.SerializeToString(&serialized);
return serialized;
}


case {'LAP_COUNT': 1089}:
{
SecondaryLapCountMsg* secondary_lap_count_d = (SecondaryLapCountMsg*)malloc(SECONDARY_LAP_COUNT_SIZE);
deserialize_SecondaryLapCount(payload, secondary_lap_count_d);

secondary::LapCount secondary_lap_count_p;
secondary_lap_count_p.set_lap_count(secondary_lap_count_d->);
secondary_lap_count_p.set_timestamp(secondary_lap_count_d->);
free(secondary_lap_count_d);
std::string serialized;
secondary_lap_count_p.SerializeToString(&serialized);
return serialized;
}

}
throw std::runtime_error("Unknown message id");
}