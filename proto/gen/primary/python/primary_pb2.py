# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: primary.proto
"""Generated protocol buffer code."""
from google.protobuf.internal import builder as _builder
from google.protobuf import descriptor as _descriptor
from google.protobuf import descriptor_pool as _descriptor_pool
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()




DESCRIPTOR = _descriptor_pool.Default().AddSerializedFile(b'\n\rprimary.proto\x12\x07primary\"U\n\x0cSteerVersion\x12\x19\n\x11\x63omponent_version\x18\x01 \x01(\r\x12\x17\n\x0f\x63\x61ncicd_version\x18\x02 \x01(\r\x12\x11\n\ttimestamp\x18\x03 \x01(\r\"S\n\nDasVersion\x12\x19\n\x11\x63omponent_version\x18\x01 \x01(\r\x12\x17\n\x0f\x63\x61ncicd_version\x18\x02 \x01(\r\x12\x11\n\ttimestamp\x18\x03 \x01(\r\"R\n\tHvVersion\x12\x19\n\x11\x63omponent_version\x18\x01 \x01(\r\x12\x17\n\x0f\x63\x61ncicd_version\x18\x02 \x01(\r\x12\x11\n\ttimestamp\x18\x03 \x01(\r\"R\n\tLvVersion\x12\x19\n\x11\x63omponent_version\x18\x01 \x01(\r\x12\x17\n\x0f\x63\x61ncicd_version\x18\x02 \x01(\r\x12\x11\n\ttimestamp\x18\x03 \x01(\r\"S\n\nTlmVersion\x12\x19\n\x11\x63omponent_version\x18\x01 \x01(\r\x12\x17\n\x0f\x63\x61ncicd_version\x18\x02 \x01(\r\x12\x11\n\ttimestamp\x18\x03 \x01(\r\"\x1e\n\tTimestamp\x12\x11\n\ttimestamp\x18\x01 \x01(\r\"\x95\x01\n\x0cSetTlmStatus\x12\'\n\ntlm_status\x18\x01 \x01(\x0e\x32\x13.primary.ToggleType\x12(\n\trace_type\x18\x02 \x01(\x0e\x32\x15.primary.RacetypeType\x12\x0e\n\x06\x64river\x18\x03 \x01(\r\x12\x0f\n\x07\x63ircuit\x18\x04 \x01(\r\x12\x11\n\ttimestamp\x18\x05 \x01(\r\"8\n\x11SteerSystemStatus\x12\x10\n\x08soc_temp\x18\x01 \x01(\r\x12\x11\n\ttimestamp\x18\x02 \x01(\r\"\x1b\n\x06Marker\x12\x11\n\ttimestamp\x18\x01 \x01(\r\"\x92\x01\n\tTlmStatus\x12\'\n\ntlm_status\x18\x01 \x01(\x0e\x32\x13.primary.ToggleType\x12(\n\trace_type\x18\x02 \x01(\x0e\x32\x15.primary.RacetypeType\x12\x0e\n\x06\x64river\x18\x03 \x01(\r\x12\x0f\n\x07\x63ircuit\x18\x04 \x01(\r\x12\x11\n\ttimestamp\x18\x05 \x01(\r\"\xac\x01\n\tCarStatus\x12/\n\ninverter_l\x18\x01 \x01(\x0e\x32\x1b.primary.InverterstatusType\x12/\n\ninverter_r\x18\x02 \x01(\x0e\x32\x1b.primary.InverterstatusType\x12*\n\ncar_status\x18\x03 \x01(\x0e\x32\x16.primary.CarstatusType\x12\x11\n\ttimestamp\x18\x04 \x01(\r\"1\n\tDasErrors\x12\x11\n\tdas_error\x18\x01 \x01(\r\x12\x11\n\ttimestamp\x18\x02 \x01(\r\"h\n\x05Speed\x12\x11\n\tencoder_r\x18\x01 \x01(\r\x12\x11\n\tencoder_l\x18\x02 \x01(\r\x12\x12\n\ninverter_r\x18\x03 \x01(\r\x12\x12\n\ninverter_l\x18\x04 \x01(\r\x12\x11\n\ttimestamp\x18\x05 \x01(\r\"}\n\tHvVoltage\x12\x14\n\x0cpack_voltage\x18\x01 \x01(\r\x12\x13\n\x0b\x62us_voltage\x18\x02 \x01(\r\x12\x18\n\x10max_cell_voltage\x18\x03 \x01(\r\x12\x18\n\x10min_cell_voltage\x18\x04 \x01(\r\x12\x11\n\ttimestamp\x18\x05 \x01(\r\">\n\tHvCurrent\x12\x0f\n\x07\x63urrent\x18\x01 \x01(\r\x12\r\n\x05power\x18\x02 \x01(\x05\x12\x11\n\ttimestamp\x18\x03 \x01(\r\"U\n\x06HvTemp\x12\x14\n\x0c\x61verage_temp\x18\x01 \x01(\r\x12\x10\n\x08max_temp\x18\x02 \x01(\r\x12\x10\n\x08min_temp\x18\x03 \x01(\r\x12\x11\n\ttimestamp\x18\x04 \x01(\r\"?\n\x08HvErrors\x12\x10\n\x08warnings\x18\x01 \x01(\r\x12\x0e\n\x06\x65rrors\x18\x02 \x01(\r\x12\x11\n\ttimestamp\x18\x03 \x01(\r\"G\n\x08TsStatus\x12(\n\tts_status\x18\x01 \x01(\x0e\x32\x15.primary.TsstatusType\x12\x11\n\ttimestamp\x18\x02 \x01(\r\"L\n\x0bSetTsStatus\x12*\n\rts_status_set\x18\x01 \x01(\x0e\x32\x13.primary.ToggleType\x12\x11\n\ttimestamp\x18\x02 \x01(\r\"^\n\x16SetCellBalancingStatus\x12\x31\n\x14set_balancing_status\x18\x01 \x01(\x0e\x32\x13.primary.ToggleType\x12\x11\n\ttimestamp\x18\x02 \x01(\r\"6\n\x0eHandcartStatus\x12\x11\n\tconnected\x18\x01 \x01(\x08\x12\x11\n\ttimestamp\x18\x02 \x01(\r\"w\n\x0bSteerStatus\x12\x36\n\x10traction_control\x18\x01 \x01(\x0e\x32\x1c.primary.TractioncontrolType\x12\x1d\n\x03map\x18\x02 \x01(\x0e\x32\x10.primary.MapType\x12\x11\n\ttimestamp\x18\x03 \x01(\r\"T\n\x0cSetCarStatus\x12\x31\n\x0e\x63\x61r_status_set\x18\x01 \x01(\x0e\x32\x19.primary.SetcarstatusType\x12\x11\n\ttimestamp\x18\x02 \x01(\r\"i\n\x0eSetPedalsRange\x12!\n\x05\x62ound\x18\x01 \x01(\x0e\x32\x12.primary.BoundType\x12!\n\x05pedal\x18\x02 \x01(\x0e\x32\x12.primary.PedalType\x12\x11\n\ttimestamp\x18\x03 \x01(\r\"/\n\tLvCurrent\x12\x0f\n\x07\x63urrent\x18\x01 \x01(\r\x12\x11\n\ttimestamp\x18\x02 \x01(\r\"j\n\tLvVoltage\x12\x11\n\tvoltage_1\x18\x01 \x01(\r\x12\x11\n\tvoltage_2\x18\x02 \x01(\r\x12\x11\n\tvoltage_3\x18\x03 \x01(\r\x12\x11\n\tvoltage_4\x18\x04 \x01(\r\x12\x11\n\ttimestamp\x18\x05 \x01(\r\":\n\x0eLvTotalVoltage\x12\x15\n\rtotal_voltage\x18\x01 \x01(\r\x12\x11\n\ttimestamp\x18\x02 \x01(\r\"T\n\rLvTemperature\x12\x16\n\x0e\x62p_temperature\x18\x01 \x01(\r\x12\x18\n\x10\x64\x63\x64\x63_temperature\x18\x02 \x01(\r\x12\x11\n\ttimestamp\x18\x03 \x01(\r\"b\n\rCoolingStatus\x12\x14\n\x0chv_fan_speed\x18\x01 \x01(\r\x12\x14\n\x0clv_fan_speed\x18\x02 \x01(\r\x12\x12\n\npump_speed\x18\x03 \x01(\r\x12\x11\n\ttimestamp\x18\x04 \x01(\r\"p\n\x0eHvCellsVoltage\x12\x12\n\ncell_index\x18\x01 \x01(\r\x12\x11\n\tvoltage_0\x18\x02 \x01(\r\x12\x11\n\tvoltage_1\x18\x03 \x01(\r\x12\x11\n\tvoltage_2\x18\x04 \x01(\r\x12\x11\n\ttimestamp\x18\x05 \x01(\r\"\xa4\x01\n\x0bHvCellsTemp\x12\x12\n\ncell_index\x18\x01 \x01(\r\x12\x0e\n\x06temp_0\x18\x02 \x01(\r\x12\x0e\n\x06temp_1\x18\x03 \x01(\r\x12\x0e\n\x06temp_2\x18\x04 \x01(\r\x12\x0e\n\x06temp_3\x18\x05 \x01(\r\x12\x0e\n\x06temp_4\x18\x06 \x01(\r\x12\x0e\n\x06temp_5\x18\x07 \x01(\r\x12\x0e\n\x06temp_6\x18\x08 \x01(\r\x12\x11\n\ttimestamp\x18\t \x01(\r\"Y\n\x15HvCellBalancingStatus\x12-\n\x10\x62\x61lancing_status\x18\x01 \x01(\x0e\x32\x13.primary.ToggleType\x12\x11\n\ttimestamp\x18\x02 \x01(\r\"L\n\rInvLSetTorque\x12\x0e\n\x06reg_id\x18\x01 \x01(\r\x12\x0b\n\x03lsb\x18\x02 \x01(\r\x12\x0b\n\x03msb\x18\x03 \x01(\r\x12\x11\n\ttimestamp\x18\x04 \x01(\r\"\xa1\x01\n\x0cInvLResponse\x12\x0e\n\x06reg_id\x18\x01 \x01(\r\x12\x0e\n\x06\x64\x61ta_0\x18\x02 \x01(\r\x12\x0e\n\x06\x64\x61ta_1\x18\x03 \x01(\r\x12\x0e\n\x06\x64\x61ta_2\x18\x04 \x01(\r\x12\x0e\n\x06\x64\x61ta_3\x18\x05 \x01(\r\x12\x0e\n\x06\x64\x61ta_4\x18\x06 \x01(\r\x12\x0e\n\x06\x64\x61ta_5\x18\x07 \x01(\r\x12\x0e\n\x06\x64\x61ta_6\x18\x08 \x01(\r\x12\x11\n\ttimestamp\x18\t \x01(\r\"\xfd\x0b\n\rPrimaryFenice\x12,\n\rsteer_version\x18\x01 \x03(\x0b\x32\x15.primary.SteerVersion\x12(\n\x0b\x64\x61s_version\x18\x02 \x03(\x0b\x32\x13.primary.DasVersion\x12&\n\nhv_version\x18\x03 \x03(\x0b\x32\x12.primary.HvVersion\x12&\n\nlv_version\x18\x04 \x03(\x0b\x32\x12.primary.LvVersion\x12(\n\x0btlm_version\x18\x05 \x03(\x0b\x32\x13.primary.TlmVersion\x12%\n\ttimestamp\x18\x06 \x03(\x0b\x32\x12.primary.Timestamp\x12-\n\x0eset_tlm_status\x18\x07 \x03(\x0b\x32\x15.primary.SetTlmStatus\x12\x37\n\x13steer_system_status\x18\x08 \x03(\x0b\x32\x1a.primary.SteerSystemStatus\x12\x1f\n\x06marker\x18\t \x03(\x0b\x32\x0f.primary.Marker\x12&\n\ntlm_status\x18\n \x03(\x0b\x32\x12.primary.TlmStatus\x12&\n\ncar_status\x18\x0b \x03(\x0b\x32\x12.primary.CarStatus\x12&\n\ndas_errors\x18\x0c \x03(\x0b\x32\x12.primary.DasErrors\x12\x1d\n\x05speed\x18\r \x03(\x0b\x32\x0e.primary.Speed\x12&\n\nhv_voltage\x18\x0e \x03(\x0b\x32\x12.primary.HvVoltage\x12&\n\nhv_current\x18\x0f \x03(\x0b\x32\x12.primary.HvCurrent\x12 \n\x07hv_temp\x18\x10 \x03(\x0b\x32\x0f.primary.HvTemp\x12$\n\thv_errors\x18\x11 \x03(\x0b\x32\x11.primary.HvErrors\x12$\n\tts_status\x18\x12 \x03(\x0b\x32\x11.primary.TsStatus\x12+\n\rset_ts_status\x18\x13 \x03(\x0b\x32\x14.primary.SetTsStatus\x12\x42\n\x19set_cell_balancing_status\x18\x14 \x03(\x0b\x32\x1f.primary.SetCellBalancingStatus\x12\x30\n\x0fhandcart_status\x18\x15 \x03(\x0b\x32\x17.primary.HandcartStatus\x12*\n\x0csteer_status\x18\x16 \x03(\x0b\x32\x14.primary.SteerStatus\x12-\n\x0eset_car_status\x18\x17 \x03(\x0b\x32\x15.primary.SetCarStatus\x12\x31\n\x10set_pedals_range\x18\x18 \x03(\x0b\x32\x17.primary.SetPedalsRange\x12&\n\nlv_current\x18\x19 \x03(\x0b\x32\x12.primary.LvCurrent\x12&\n\nlv_voltage\x18\x1a \x03(\x0b\x32\x12.primary.LvVoltage\x12\x31\n\x10lv_total_voltage\x18\x1b \x03(\x0b\x32\x17.primary.LvTotalVoltage\x12.\n\x0elv_temperature\x18\x1c \x03(\x0b\x32\x16.primary.LvTemperature\x12.\n\x0e\x63ooling_status\x18\x1d \x03(\x0b\x32\x16.primary.CoolingStatus\x12\x31\n\x10hv_cells_voltage\x18\x1e \x03(\x0b\x32\x17.primary.HvCellsVoltage\x12+\n\rhv_cells_temp\x18\x1f \x03(\x0b\x32\x14.primary.HvCellsTemp\x12@\n\x18hv_cell_balancing_status\x18  \x03(\x0b\x32\x1e.primary.HvCellBalancingStatus\x12\x30\n\x10inv_l_set_torque\x18! \x03(\x0b\x32\x16.primary.InvLSetTorque\x12-\n\x0einv_l_response\x18\" \x03(\x0b\x32\x15.primary.InvLResponse*o\n\x0cRacetypeType\x12\x19\n\x15RACETYPE_ACCELERATION\x10\x00\x12\x14\n\x10RACETYPE_SKIDPAD\x10\x01\x12\x16\n\x12RACETYPE_AUTOCROSS\x10\x02\x12\x16\n\x12RACETYPE_ENDURANCE\x10\x03*\\\n\x12InverterstatusType\x12\x16\n\x12INVERTERSTATUS_OFF\x10\x00\x12\x17\n\x13INVERTERSTATUS_IDLE\x10\x01\x12\x15\n\x11INVERTERSTATUS_ON\x10\x02*K\n\rCarstatusType\x12\x12\n\x0e\x43\x41RSTATUS_IDLE\x10\x00\x12\x13\n\x0f\x43\x41RSTATUS_SETUP\x10\x01\x12\x11\n\rCARSTATUS_RUN\x10\x02*+\n\nToggleType\x12\r\n\tTOGGLE_ON\x10\x00\x12\x0e\n\nTOGGLE_OFF\x10\x01*\x94\x01\n\x13TractioncontrolType\x12\x17\n\x13TRACTIONCONTROL_OFF\x10\x00\x12 \n\x1cTRACTIONCONTROL_SLIP_CONTROL\x10\x01\x12$\n TRACTIONCONTROL_TORQUE_VECTORING\x10\x02\x12\x1c\n\x18TRACTIONCONTROL_COMPLETE\x10\x03*]\n\x0cTsstatusType\x12\x10\n\x0cTSSTATUS_OFF\x10\x00\x12\x16\n\x12TSSTATUS_PRECHARGE\x10\x01\x12\x0f\n\x0bTSSTATUS_ON\x10\x02\x12\x12\n\x0eTSSTATUS_FATAL\x10\x03*V\n\x07MapType\x12\t\n\x05MAP_R\x10\x00\x12\x0b\n\x07MAP_D20\x10\x01\x12\x0b\n\x07MAP_D40\x10\x02\x12\x0b\n\x07MAP_D60\x10\x03\x12\x0b\n\x07MAP_D80\x10\x04\x12\x0c\n\x08MAP_D100\x10\x05*?\n\x10SetcarstatusType\x12\x15\n\x11SETCARSTATUS_IDLE\x10\x00\x12\x14\n\x10SETCARSTATUS_RUN\x10\x01*1\n\tBoundType\x12\x11\n\rBOUND_SET_MAX\x10\x00\x12\x11\n\rBOUND_SET_MIN\x10\x01*3\n\tPedalType\x12\x15\n\x11PEDAL_ACCELERATOR\x10\x00\x12\x0f\n\x0bPEDAL_BRAKE\x10\x01\x62\x06proto3')

_builder.BuildMessageAndEnumDescriptors(DESCRIPTOR, globals())
_builder.BuildTopDescriptorsAndMessages(DESCRIPTOR, 'primary_pb2', globals())
if _descriptor._USE_C_DESCRIPTORS == False:

  DESCRIPTOR._options = None
  _RACETYPETYPE._serialized_start=4716
  _RACETYPETYPE._serialized_end=4827
  _INVERTERSTATUSTYPE._serialized_start=4829
  _INVERTERSTATUSTYPE._serialized_end=4921
  _CARSTATUSTYPE._serialized_start=4923
  _CARSTATUSTYPE._serialized_end=4998
  _TOGGLETYPE._serialized_start=5000
  _TOGGLETYPE._serialized_end=5043
  _TRACTIONCONTROLTYPE._serialized_start=5046
  _TRACTIONCONTROLTYPE._serialized_end=5194
  _TSSTATUSTYPE._serialized_start=5196
  _TSSTATUSTYPE._serialized_end=5289
  _MAPTYPE._serialized_start=5291
  _MAPTYPE._serialized_end=5377
  _SETCARSTATUSTYPE._serialized_start=5379
  _SETCARSTATUSTYPE._serialized_end=5442
  _BOUNDTYPE._serialized_start=5444
  _BOUNDTYPE._serialized_end=5493
  _PEDALTYPE._serialized_start=5495
  _PEDALTYPE._serialized_end=5546
  _STEERVERSION._serialized_start=26
  _STEERVERSION._serialized_end=111
  _DASVERSION._serialized_start=113
  _DASVERSION._serialized_end=196
  _HVVERSION._serialized_start=198
  _HVVERSION._serialized_end=280
  _LVVERSION._serialized_start=282
  _LVVERSION._serialized_end=364
  _TLMVERSION._serialized_start=366
  _TLMVERSION._serialized_end=449
  _TIMESTAMP._serialized_start=451
  _TIMESTAMP._serialized_end=481
  _SETTLMSTATUS._serialized_start=484
  _SETTLMSTATUS._serialized_end=633
  _STEERSYSTEMSTATUS._serialized_start=635
  _STEERSYSTEMSTATUS._serialized_end=691
  _MARKER._serialized_start=693
  _MARKER._serialized_end=720
  _TLMSTATUS._serialized_start=723
  _TLMSTATUS._serialized_end=869
  _CARSTATUS._serialized_start=872
  _CARSTATUS._serialized_end=1044
  _DASERRORS._serialized_start=1046
  _DASERRORS._serialized_end=1095
  _SPEED._serialized_start=1097
  _SPEED._serialized_end=1201
  _HVVOLTAGE._serialized_start=1203
  _HVVOLTAGE._serialized_end=1328
  _HVCURRENT._serialized_start=1330
  _HVCURRENT._serialized_end=1392
  _HVTEMP._serialized_start=1394
  _HVTEMP._serialized_end=1479
  _HVERRORS._serialized_start=1481
  _HVERRORS._serialized_end=1544
  _TSSTATUS._serialized_start=1546
  _TSSTATUS._serialized_end=1617
  _SETTSSTATUS._serialized_start=1619
  _SETTSSTATUS._serialized_end=1695
  _SETCELLBALANCINGSTATUS._serialized_start=1697
  _SETCELLBALANCINGSTATUS._serialized_end=1791
  _HANDCARTSTATUS._serialized_start=1793
  _HANDCARTSTATUS._serialized_end=1847
  _STEERSTATUS._serialized_start=1849
  _STEERSTATUS._serialized_end=1968
  _SETCARSTATUS._serialized_start=1970
  _SETCARSTATUS._serialized_end=2054
  _SETPEDALSRANGE._serialized_start=2056
  _SETPEDALSRANGE._serialized_end=2161
  _LVCURRENT._serialized_start=2163
  _LVCURRENT._serialized_end=2210
  _LVVOLTAGE._serialized_start=2212
  _LVVOLTAGE._serialized_end=2318
  _LVTOTALVOLTAGE._serialized_start=2320
  _LVTOTALVOLTAGE._serialized_end=2378
  _LVTEMPERATURE._serialized_start=2380
  _LVTEMPERATURE._serialized_end=2464
  _COOLINGSTATUS._serialized_start=2466
  _COOLINGSTATUS._serialized_end=2564
  _HVCELLSVOLTAGE._serialized_start=2566
  _HVCELLSVOLTAGE._serialized_end=2678
  _HVCELLSTEMP._serialized_start=2681
  _HVCELLSTEMP._serialized_end=2845
  _HVCELLBALANCINGSTATUS._serialized_start=2847
  _HVCELLBALANCINGSTATUS._serialized_end=2936
  _INVLSETTORQUE._serialized_start=2938
  _INVLSETTORQUE._serialized_end=3014
  _INVLRESPONSE._serialized_start=3017
  _INVLRESPONSE._serialized_end=3178
  _PRIMARYFENICE._serialized_start=3181
  _PRIMARYFENICE._serialized_end=4714
# @@protoc_insertion_point(module_scope)