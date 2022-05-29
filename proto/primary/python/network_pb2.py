# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: network.proto
"""Generated protocol buffer code."""
from google.protobuf.internal import builder as _builder
from google.protobuf import descriptor as _descriptor
from google.protobuf import descriptor_pool as _descriptor_pool
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()




DESCRIPTOR = _descriptor_pool.Default().AddSerializedFile(b'\n\rnetwork.proto\x12\x07primary\"`\n\rSTEER_VERSION\x12\x19\n\x11\x63omponent_version\x18\x01 \x01(\r\x12\x17\n\x0f\x63\x61ncicd_version\x18\x02 \x01(\r\x12\x1b\n\x13_internal_timestamp\x18\x03 \x01(\x04\"^\n\x0b\x44\x41S_VERSION\x12\x19\n\x11\x63omponent_version\x18\x01 \x01(\r\x12\x17\n\x0f\x63\x61ncicd_version\x18\x02 \x01(\r\x12\x1b\n\x13_internal_timestamp\x18\x03 \x01(\x04\"]\n\nHV_VERSION\x12\x19\n\x11\x63omponent_version\x18\x01 \x01(\r\x12\x17\n\x0f\x63\x61ncicd_version\x18\x02 \x01(\r\x12\x1b\n\x13_internal_timestamp\x18\x03 \x01(\x04\"]\n\nLV_VERSION\x12\x19\n\x11\x63omponent_version\x18\x01 \x01(\r\x12\x17\n\x0f\x63\x61ncicd_version\x18\x02 \x01(\r\x12\x1b\n\x13_internal_timestamp\x18\x03 \x01(\x04\"^\n\x0bTLM_VERSION\x12\x19\n\x11\x63omponent_version\x18\x01 \x01(\r\x12\x17\n\x0f\x63\x61ncicd_version\x18\x02 \x01(\r\x12\x1b\n\x13_internal_timestamp\x18\x03 \x01(\x04\";\n\tTIMESTAMP\x12\x11\n\ttimestamp\x18\x01 \x01(\r\x12\x1b\n\x13_internal_timestamp\x18\x02 \x01(\x04\"\x99\x01\n\x0eSET_TLM_STATUS\x12\x0e\n\x06\x64river\x18\x01 \x01(\r\x12\x0f\n\x07\x63ircuit\x18\x02 \x01(\r\x12$\n\trace_type\x18\x03 \x01(\x0e\x32\x11.primary.RaceType\x12#\n\ntlm_status\x18\x04 \x01(\x0e\x32\x0f.primary.Toggle\x12\x1b\n\x13_internal_timestamp\x18\x05 \x01(\x04\"\x95\x01\n\nTLM_STATUS\x12\x0e\n\x06\x64river\x18\x01 \x01(\r\x12\x0f\n\x07\x63ircuit\x18\x02 \x01(\r\x12$\n\trace_type\x18\x03 \x01(\x0e\x32\x11.primary.RaceType\x12#\n\ntlm_status\x18\x04 \x01(\x0e\x32\x0f.primary.Toggle\x12\x1b\n\x13_internal_timestamp\x18\x05 \x01(\x04\"D\n\x13STEER_SYSTEM_STATUS\x12\x10\n\x08soc_temp\x18\x01 \x01(\r\x12\x1b\n\x13_internal_timestamp\x18\x02 \x01(\x04\"\x88\x01\n\nHV_VOLTAGE\x12\x14\n\x0cpack_voltage\x18\x01 \x01(\r\x12\x13\n\x0b\x62us_voltage\x18\x02 \x01(\r\x12\x18\n\x10max_cell_voltage\x18\x03 \x01(\r\x12\x18\n\x10min_cell_voltage\x18\x04 \x01(\r\x12\x1b\n\x13_internal_timestamp\x18\x05 \x01(\x04\"I\n\nHV_CURRENT\x12\x0f\n\x07\x63urrent\x18\x01 \x01(\r\x12\r\n\x05power\x18\x02 \x01(\x11\x12\x1b\n\x13_internal_timestamp\x18\x03 \x01(\x04\"`\n\x07HV_TEMP\x12\x14\n\x0c\x61verage_temp\x18\x01 \x01(\r\x12\x10\n\x08max_temp\x18\x02 \x01(\r\x12\x10\n\x08min_temp\x18\x03 \x01(\r\x12\x1b\n\x13_internal_timestamp\x18\x04 \x01(\x04\"J\n\tHV_ERRORS\x12\x10\n\x08warnings\x18\x01 \x01(\r\x12\x0e\n\x06\x65rrors\x18\x02 \x01(\r\x12\x1b\n\x13_internal_timestamp\x18\x03 \x01(\x04\"N\n\tTS_STATUS\x12$\n\tts_status\x18\x01 \x01(\x0e\x32\x11.primary.TsStatus\x12\x1b\n\x13_internal_timestamp\x18\x02 \x01(\x04\"X\n\x11SET_TS_STATUS_DAS\x12&\n\rts_status_set\x18\x01 \x01(\x0e\x32\x0f.primary.Toggle\x12\x1b\n\x13_internal_timestamp\x18\x02 \x01(\x04\"]\n\x16SET_TS_STATUS_HANDCART\x12&\n\rts_status_set\x18\x01 \x01(\x0e\x32\x0f.primary.Toggle\x12\x1b\n\x13_internal_timestamp\x18\x02 \x01(\x04\"z\n\x0cSTEER_STATUS\x12\x19\n\x03map\x18\x01 \x01(\x0e\x32\x0c.primary.Map\x12\x32\n\x10traction_control\x18\x02 \x01(\x0e\x32\x18.primary.TractionControl\x12\x1b\n\x13_internal_timestamp\x18\x03 \x01(\x04\"\\\n\x0eSET_CAR_STATUS\x12-\n\x0e\x63\x61r_status_set\x18\x01 \x01(\x0e\x32\x15.primary.SetCarStatus\x12\x1b\n\x13_internal_timestamp\x18\x02 \x01(\x04\"m\n\x10SET_PEDALS_RANGE\x12\x1d\n\x05\x62ound\x18\x01 \x01(\x0e\x32\x0e.primary.Bound\x12\x1d\n\x05pedal\x18\x02 \x01(\x0e\x32\x0e.primary.Pedal\x12\x1b\n\x13_internal_timestamp\x18\x03 \x01(\x04\"\xab\x01\n\nCAR_STATUS\x12+\n\ninverter_l\x18\x01 \x01(\x0e\x32\x17.primary.InverterStatus\x12+\n\ninverter_r\x18\x02 \x01(\x0e\x32\x17.primary.InverterStatus\x12&\n\ncar_status\x18\x03 \x01(\x0e\x32\x12.primary.CarStatus\x12\x1b\n\x13_internal_timestamp\x18\x04 \x01(\x04\"<\n\nDAS_ERRORS\x12\x11\n\tdas_error\x18\x01 \x01(\r\x12\x1b\n\x13_internal_timestamp\x18\x02 \x01(\x04\":\n\nLV_CURRENT\x12\x0f\n\x07\x63urrent\x18\x01 \x01(\r\x12\x1b\n\x13_internal_timestamp\x18\x02 \x01(\x04\"u\n\nLV_VOLTAGE\x12\x11\n\tvoltage_1\x18\x01 \x01(\r\x12\x11\n\tvoltage_2\x18\x02 \x01(\r\x12\x11\n\tvoltage_3\x18\x03 \x01(\r\x12\x11\n\tvoltage_4\x18\x04 \x01(\r\x12\x1b\n\x13_internal_timestamp\x18\x05 \x01(\x04\"F\n\x10LV_TOTAL_VOLTAGE\x12\x15\n\rtotal_voltage\x18\x01 \x01(\r\x12\x1b\n\x13_internal_timestamp\x18\x02 \x01(\x04\"_\n\x0eLV_TEMPERATURE\x12\x16\n\x0e\x62p_temperature\x18\x01 \x01(\r\x12\x18\n\x10\x64\x63\x64\x63_temperature\x18\x02 \x01(\r\x12\x1b\n\x13_internal_timestamp\x18\x03 \x01(\x04\"m\n\x0e\x43OOLING_STATUS\x12\x14\n\x0chv_fan_speed\x18\x01 \x01(\r\x12\x14\n\x0clv_fan_speed\x18\x02 \x01(\r\x12\x12\n\npump_speed\x18\x03 \x01(\r\x12\x1b\n\x13_internal_timestamp\x18\x04 \x01(\x04\"%\n\x06MARKER\x12\x1b\n\x13_internal_timestamp\x18\x01 \x01(\x04\"|\n\x10HV_CELLS_VOLTAGE\x12\x11\n\tvoltage_0\x18\x01 \x01(\r\x12\x11\n\tvoltage_1\x18\x02 \x01(\r\x12\x11\n\tvoltage_2\x18\x03 \x01(\r\x12\x12\n\ncell_index\x18\x04 \x01(\r\x12\x1b\n\x13_internal_timestamp\x18\x05 \x01(\x04\"\xb0\x01\n\rHV_CELLS_TEMP\x12\x12\n\ncell_index\x18\x01 \x01(\r\x12\x0e\n\x06temp_0\x18\x02 \x01(\r\x12\x0e\n\x06temp_1\x18\x03 \x01(\r\x12\x0e\n\x06temp_2\x18\x04 \x01(\r\x12\x0e\n\x06temp_3\x18\x05 \x01(\r\x12\x0e\n\x06temp_4\x18\x06 \x01(\r\x12\x0e\n\x06temp_5\x18\x07 \x01(\r\x12\x0e\n\x06temp_6\x18\x08 \x01(\r\x12\x1b\n\x13_internal_timestamp\x18\t \x01(\x04\"b\n\x18HV_CELL_BALANCING_STATUS\x12)\n\x10\x62\x61lancing_status\x18\x01 \x01(\x0e\x32\x0f.primary.Toggle\x12\x1b\n\x13_internal_timestamp\x18\x02 \x01(\x04\"g\n\x19SET_CELL_BALANCING_STATUS\x12-\n\x14set_balancing_status\x18\x01 \x01(\x0e\x32\x0f.primary.Toggle\x12\x1b\n\x13_internal_timestamp\x18\x02 \x01(\x04\"A\n\x0fHANDCART_STATUS\x12\x11\n\tconnected\x18\x01 \x01(\x08\x12\x1b\n\x13_internal_timestamp\x18\x02 \x01(\x04\"r\n\x05SPEED\x12\x11\n\tencoder_r\x18\x01 \x01(\r\x12\x11\n\tencoder_l\x18\x02 \x01(\r\x12\x12\n\ninverter_r\x18\x03 \x01(\r\x12\x12\n\ninverter_l\x18\x04 \x01(\r\x12\x1b\n\x13_internal_timestamp\x18\x05 \x01(\x04\"Y\n\x10INV_L_SET_TORQUE\x12\x0e\n\x06reg_id\x18\x01 \x01(\r\x12\x0b\n\x03lsb\x18\x02 \x01(\r\x12\x0b\n\x03msb\x18\x03 \x01(\r\x12\x1b\n\x13_internal_timestamp\x18\x04 \x01(\x04\"\xad\x01\n\x0eINV_L_RESPONSE\x12\x0e\n\x06reg_id\x18\x01 \x01(\r\x12\x0e\n\x06\x64\x61ta_0\x18\x02 \x01(\r\x12\x0e\n\x06\x64\x61ta_1\x18\x03 \x01(\r\x12\x0e\n\x06\x64\x61ta_2\x18\x04 \x01(\r\x12\x0e\n\x06\x64\x61ta_3\x18\x05 \x01(\r\x12\x0e\n\x06\x64\x61ta_4\x18\x06 \x01(\r\x12\x0e\n\x06\x64\x61ta_5\x18\x07 \x01(\r\x12\x0e\n\x06\x64\x61ta_6\x18\x08 \x01(\r\x12\x1b\n\x13_internal_timestamp\x18\t \x01(\x04\"\xeb\x0c\n\x04Pack\x12-\n\rSTEER_VERSION\x18\x01 \x03(\x0b\x32\x16.primary.STEER_VERSION\x12)\n\x0b\x44\x41S_VERSION\x18\x02 \x03(\x0b\x32\x14.primary.DAS_VERSION\x12\'\n\nHV_VERSION\x18\x03 \x03(\x0b\x32\x13.primary.HV_VERSION\x12\'\n\nLV_VERSION\x18\x04 \x03(\x0b\x32\x13.primary.LV_VERSION\x12)\n\x0bTLM_VERSION\x18\x05 \x03(\x0b\x32\x14.primary.TLM_VERSION\x12%\n\tTIMESTAMP\x18\x06 \x03(\x0b\x32\x12.primary.TIMESTAMP\x12/\n\x0eSET_TLM_STATUS\x18\x07 \x03(\x0b\x32\x17.primary.SET_TLM_STATUS\x12\'\n\nTLM_STATUS\x18\x08 \x03(\x0b\x32\x13.primary.TLM_STATUS\x12\x39\n\x13STEER_SYSTEM_STATUS\x18\t \x03(\x0b\x32\x1c.primary.STEER_SYSTEM_STATUS\x12\'\n\nHV_VOLTAGE\x18\n \x03(\x0b\x32\x13.primary.HV_VOLTAGE\x12\'\n\nHV_CURRENT\x18\x0b \x03(\x0b\x32\x13.primary.HV_CURRENT\x12!\n\x07HV_TEMP\x18\x0c \x03(\x0b\x32\x10.primary.HV_TEMP\x12%\n\tHV_ERRORS\x18\r \x03(\x0b\x32\x12.primary.HV_ERRORS\x12%\n\tTS_STATUS\x18\x0e \x03(\x0b\x32\x12.primary.TS_STATUS\x12\x35\n\x11SET_TS_STATUS_DAS\x18\x0f \x03(\x0b\x32\x1a.primary.SET_TS_STATUS_DAS\x12?\n\x16SET_TS_STATUS_HANDCART\x18\x10 \x03(\x0b\x32\x1f.primary.SET_TS_STATUS_HANDCART\x12+\n\x0cSTEER_STATUS\x18\x11 \x03(\x0b\x32\x15.primary.STEER_STATUS\x12/\n\x0eSET_CAR_STATUS\x18\x12 \x03(\x0b\x32\x17.primary.SET_CAR_STATUS\x12\x33\n\x10SET_PEDALS_RANGE\x18\x13 \x03(\x0b\x32\x19.primary.SET_PEDALS_RANGE\x12\'\n\nCAR_STATUS\x18\x14 \x03(\x0b\x32\x13.primary.CAR_STATUS\x12\'\n\nDAS_ERRORS\x18\x15 \x03(\x0b\x32\x13.primary.DAS_ERRORS\x12\'\n\nLV_CURRENT\x18\x16 \x03(\x0b\x32\x13.primary.LV_CURRENT\x12\'\n\nLV_VOLTAGE\x18\x17 \x03(\x0b\x32\x13.primary.LV_VOLTAGE\x12\x33\n\x10LV_TOTAL_VOLTAGE\x18\x18 \x03(\x0b\x32\x19.primary.LV_TOTAL_VOLTAGE\x12/\n\x0eLV_TEMPERATURE\x18\x19 \x03(\x0b\x32\x17.primary.LV_TEMPERATURE\x12/\n\x0e\x43OOLING_STATUS\x18\x1a \x03(\x0b\x32\x17.primary.COOLING_STATUS\x12\x1f\n\x06MARKER\x18\x1b \x03(\x0b\x32\x0f.primary.MARKER\x12\x33\n\x10HV_CELLS_VOLTAGE\x18\x1c \x03(\x0b\x32\x19.primary.HV_CELLS_VOLTAGE\x12-\n\rHV_CELLS_TEMP\x18\x1d \x03(\x0b\x32\x16.primary.HV_CELLS_TEMP\x12\x43\n\x18HV_CELL_BALANCING_STATUS\x18\x1e \x03(\x0b\x32!.primary.HV_CELL_BALANCING_STATUS\x12\x45\n\x19SET_CELL_BALANCING_STATUS\x18\x1f \x03(\x0b\x32\".primary.SET_CELL_BALANCING_STATUS\x12\x31\n\x0fHANDCART_STATUS\x18  \x03(\x0b\x32\x18.primary.HANDCART_STATUS\x12\x1d\n\x05SPEED\x18! \x03(\x0b\x32\x0e.primary.SPEED\x12\x33\n\x10INV_L_SET_TORQUE\x18\" \x03(\x0b\x32\x19.primary.INV_L_SET_TORQUE\x12/\n\x0eINV_L_RESPONSE\x18# \x03(\x0b\x32\x17.primary.INV_L_RESPONSE*k\n\x08RaceType\x12\x19\n\x15RaceType_ACCELERATION\x10\x00\x12\x14\n\x10RaceType_SKIDPAD\x10\x01\x12\x16\n\x12RaceType_AUTOCROSS\x10\x02\x12\x16\n\x12RaceType_ENDURANCE\x10\x03*X\n\x0eInverterStatus\x12\x16\n\x12InverterStatus_OFF\x10\x00\x12\x17\n\x13InverterStatus_IDLE\x10\x01\x12\x15\n\x11InverterStatus_ON\x10\x02*G\n\tCarStatus\x12\x12\n\x0e\x43\x61rStatus_IDLE\x10\x00\x12\x13\n\x0f\x43\x61rStatus_SETUP\x10\x01\x12\x11\n\rCarStatus_RUN\x10\x02*\'\n\x06Toggle\x12\r\n\tToggle_ON\x10\x00\x12\x0e\n\nToggle_OFF\x10\x01*\x90\x01\n\x0fTractionControl\x12\x17\n\x13TractionControl_OFF\x10\x00\x12 \n\x1cTractionControl_SLIP_CONTROL\x10\x01\x12$\n TractionControl_TORQUE_VECTORING\x10\x02\x12\x1c\n\x18TractionControl_COMPLETE\x10\x03*Y\n\x08TsStatus\x12\x10\n\x0cTsStatus_OFF\x10\x00\x12\x16\n\x12TsStatus_PRECHARGE\x10\x01\x12\x0f\n\x0bTsStatus_ON\x10\x02\x12\x12\n\x0eTsStatus_FATAL\x10\x03*R\n\x03Map\x12\t\n\x05Map_R\x10\x00\x12\x0b\n\x07Map_D20\x10\x01\x12\x0b\n\x07Map_D40\x10\x02\x12\x0b\n\x07Map_D60\x10\x03\x12\x0b\n\x07Map_D80\x10\x04\x12\x0c\n\x08Map_D100\x10\x05*;\n\x0cSetCarStatus\x12\x15\n\x11SetCarStatus_IDLE\x10\x00\x12\x14\n\x10SetCarStatus_RUN\x10\x01*-\n\x05\x42ound\x12\x11\n\rBound_SET_MAX\x10\x00\x12\x11\n\rBound_SET_MIN\x10\x01*/\n\x05Pedal\x12\x15\n\x11Pedal_ACCELERATOR\x10\x00\x12\x0f\n\x0bPedal_BRAKE\x10\x01\x62\x06proto3')

_builder.BuildMessageAndEnumDescriptors(DESCRIPTOR, globals())
_builder.BuildTopDescriptorsAndMessages(DESCRIPTOR, 'network_pb2', globals())
if _descriptor._USE_C_DESCRIPTORS == False:

  DESCRIPTOR._options = None
  _RACETYPE._serialized_start=5267
  _RACETYPE._serialized_end=5374
  _INVERTERSTATUS._serialized_start=5376
  _INVERTERSTATUS._serialized_end=5464
  _CARSTATUS._serialized_start=5466
  _CARSTATUS._serialized_end=5537
  _TOGGLE._serialized_start=5539
  _TOGGLE._serialized_end=5578
  _TRACTIONCONTROL._serialized_start=5581
  _TRACTIONCONTROL._serialized_end=5725
  _TSSTATUS._serialized_start=5727
  _TSSTATUS._serialized_end=5816
  _MAP._serialized_start=5818
  _MAP._serialized_end=5900
  _SETCARSTATUS._serialized_start=5902
  _SETCARSTATUS._serialized_end=5961
  _BOUND._serialized_start=5963
  _BOUND._serialized_end=6008
  _PEDAL._serialized_start=6010
  _PEDAL._serialized_end=6057
  _STEER_VERSION._serialized_start=26
  _STEER_VERSION._serialized_end=122
  _DAS_VERSION._serialized_start=124
  _DAS_VERSION._serialized_end=218
  _HV_VERSION._serialized_start=220
  _HV_VERSION._serialized_end=313
  _LV_VERSION._serialized_start=315
  _LV_VERSION._serialized_end=408
  _TLM_VERSION._serialized_start=410
  _TLM_VERSION._serialized_end=504
  _TIMESTAMP._serialized_start=506
  _TIMESTAMP._serialized_end=565
  _SET_TLM_STATUS._serialized_start=568
  _SET_TLM_STATUS._serialized_end=721
  _TLM_STATUS._serialized_start=724
  _TLM_STATUS._serialized_end=873
  _STEER_SYSTEM_STATUS._serialized_start=875
  _STEER_SYSTEM_STATUS._serialized_end=943
  _HV_VOLTAGE._serialized_start=946
  _HV_VOLTAGE._serialized_end=1082
  _HV_CURRENT._serialized_start=1084
  _HV_CURRENT._serialized_end=1157
  _HV_TEMP._serialized_start=1159
  _HV_TEMP._serialized_end=1255
  _HV_ERRORS._serialized_start=1257
  _HV_ERRORS._serialized_end=1331
  _TS_STATUS._serialized_start=1333
  _TS_STATUS._serialized_end=1411
  _SET_TS_STATUS_DAS._serialized_start=1413
  _SET_TS_STATUS_DAS._serialized_end=1501
  _SET_TS_STATUS_HANDCART._serialized_start=1503
  _SET_TS_STATUS_HANDCART._serialized_end=1596
  _STEER_STATUS._serialized_start=1598
  _STEER_STATUS._serialized_end=1720
  _SET_CAR_STATUS._serialized_start=1722
  _SET_CAR_STATUS._serialized_end=1814
  _SET_PEDALS_RANGE._serialized_start=1816
  _SET_PEDALS_RANGE._serialized_end=1925
  _CAR_STATUS._serialized_start=1928
  _CAR_STATUS._serialized_end=2099
  _DAS_ERRORS._serialized_start=2101
  _DAS_ERRORS._serialized_end=2161
  _LV_CURRENT._serialized_start=2163
  _LV_CURRENT._serialized_end=2221
  _LV_VOLTAGE._serialized_start=2223
  _LV_VOLTAGE._serialized_end=2340
  _LV_TOTAL_VOLTAGE._serialized_start=2342
  _LV_TOTAL_VOLTAGE._serialized_end=2412
  _LV_TEMPERATURE._serialized_start=2414
  _LV_TEMPERATURE._serialized_end=2509
  _COOLING_STATUS._serialized_start=2511
  _COOLING_STATUS._serialized_end=2620
  _MARKER._serialized_start=2622
  _MARKER._serialized_end=2659
  _HV_CELLS_VOLTAGE._serialized_start=2661
  _HV_CELLS_VOLTAGE._serialized_end=2785
  _HV_CELLS_TEMP._serialized_start=2788
  _HV_CELLS_TEMP._serialized_end=2964
  _HV_CELL_BALANCING_STATUS._serialized_start=2966
  _HV_CELL_BALANCING_STATUS._serialized_end=3064
  _SET_CELL_BALANCING_STATUS._serialized_start=3066
  _SET_CELL_BALANCING_STATUS._serialized_end=3169
  _HANDCART_STATUS._serialized_start=3171
  _HANDCART_STATUS._serialized_end=3236
  _SPEED._serialized_start=3238
  _SPEED._serialized_end=3352
  _INV_L_SET_TORQUE._serialized_start=3354
  _INV_L_SET_TORQUE._serialized_end=3443
  _INV_L_RESPONSE._serialized_start=3446
  _INV_L_RESPONSE._serialized_end=3619
  _PACK._serialized_start=3622
  _PACK._serialized_end=5265
# @@protoc_insertion_point(module_scope)