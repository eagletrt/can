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




DESCRIPTOR = _descriptor_pool.Default().AddSerializedFile(b'\n\rnetwork.proto\x12\tsecondary\"k\n\x10IMU_ANGULAR_RATE\x12\x12\n\nang_rate_x\x18\x01 \x01(\r\x12\x12\n\nang_rate_y\x18\x02 \x01(\r\x12\x12\n\nang_rate_z\x18\x03 \x01(\r\x12\x1b\n\x13_internal_timestamp\x18\x04 \x01(\x04\"b\n\x10IMU_ACCELERATION\x12\x0f\n\x07\x61\x63\x63\x65l_x\x18\x01 \x01(\r\x12\x0f\n\x07\x61\x63\x63\x65l_y\x18\x02 \x01(\r\x12\x0f\n\x07\x61\x63\x63\x65l_z\x18\x03 \x01(\r\x12\x1b\n\x13_internal_timestamp\x18\x04 \x01(\x04\"p\n\tIRTS_FL_0\x12\x10\n\x08\x63hannel1\x18\x01 \x01(\r\x12\x10\n\x08\x63hannel2\x18\x02 \x01(\r\x12\x10\n\x08\x63hannel3\x18\x03 \x01(\r\x12\x10\n\x08\x63hannel4\x18\x04 \x01(\r\x12\x1b\n\x13_internal_timestamp\x18\x05 \x01(\x04\"p\n\tIRTS_FL_1\x12\x10\n\x08\x63hannel5\x18\x01 \x01(\r\x12\x10\n\x08\x63hannel6\x18\x02 \x01(\r\x12\x10\n\x08\x63hannel7\x18\x03 \x01(\r\x12\x10\n\x08\x63hannel8\x18\x04 \x01(\r\x12\x1b\n\x13_internal_timestamp\x18\x05 \x01(\x04\"s\n\tIRTS_FL_2\x12\x10\n\x08\x63hannel9\x18\x01 \x01(\r\x12\x11\n\tchannel10\x18\x02 \x01(\r\x12\x11\n\tchannel11\x18\x03 \x01(\r\x12\x11\n\tchannel12\x18\x04 \x01(\r\x12\x1b\n\x13_internal_timestamp\x18\x05 \x01(\x04\"t\n\tIRTS_FL_3\x12\x11\n\tchannel13\x18\x01 \x01(\r\x12\x11\n\tchannel14\x18\x02 \x01(\r\x12\x11\n\tchannel15\x18\x03 \x01(\r\x12\x11\n\tchannel16\x18\x04 \x01(\r\x12\x1b\n\x13_internal_timestamp\x18\x05 \x01(\x04\"p\n\tIRTS_FR_0\x12\x10\n\x08\x63hannel1\x18\x01 \x01(\r\x12\x10\n\x08\x63hannel2\x18\x02 \x01(\r\x12\x10\n\x08\x63hannel3\x18\x03 \x01(\r\x12\x10\n\x08\x63hannel4\x18\x04 \x01(\r\x12\x1b\n\x13_internal_timestamp\x18\x05 \x01(\x04\"p\n\tIRTS_FR_1\x12\x10\n\x08\x63hannel5\x18\x01 \x01(\r\x12\x10\n\x08\x63hannel6\x18\x02 \x01(\r\x12\x10\n\x08\x63hannel7\x18\x03 \x01(\r\x12\x10\n\x08\x63hannel8\x18\x04 \x01(\r\x12\x1b\n\x13_internal_timestamp\x18\x05 \x01(\x04\"s\n\tIRTS_FR_2\x12\x10\n\x08\x63hannel9\x18\x01 \x01(\r\x12\x11\n\tchannel10\x18\x02 \x01(\r\x12\x11\n\tchannel11\x18\x03 \x01(\r\x12\x11\n\tchannel12\x18\x04 \x01(\r\x12\x1b\n\x13_internal_timestamp\x18\x05 \x01(\x04\"t\n\tIRTS_FR_3\x12\x11\n\tchannel13\x18\x01 \x01(\r\x12\x11\n\tchannel14\x18\x02 \x01(\r\x12\x11\n\tchannel15\x18\x03 \x01(\r\x12\x11\n\tchannel16\x18\x04 \x01(\r\x12\x1b\n\x13_internal_timestamp\x18\x05 \x01(\x04\"p\n\tIRTS_RL_0\x12\x10\n\x08\x63hannel1\x18\x01 \x01(\r\x12\x10\n\x08\x63hannel2\x18\x02 \x01(\r\x12\x10\n\x08\x63hannel3\x18\x03 \x01(\r\x12\x10\n\x08\x63hannel4\x18\x04 \x01(\r\x12\x1b\n\x13_internal_timestamp\x18\x05 \x01(\x04\"p\n\tIRTS_RL_1\x12\x10\n\x08\x63hannel5\x18\x01 \x01(\r\x12\x10\n\x08\x63hannel6\x18\x02 \x01(\r\x12\x10\n\x08\x63hannel7\x18\x03 \x01(\r\x12\x10\n\x08\x63hannel8\x18\x04 \x01(\r\x12\x1b\n\x13_internal_timestamp\x18\x05 \x01(\x04\"s\n\tIRTS_RL_2\x12\x10\n\x08\x63hannel9\x18\x01 \x01(\r\x12\x11\n\tchannel10\x18\x02 \x01(\r\x12\x11\n\tchannel11\x18\x03 \x01(\r\x12\x11\n\tchannel12\x18\x04 \x01(\r\x12\x1b\n\x13_internal_timestamp\x18\x05 \x01(\x04\"t\n\tIRTS_RL_3\x12\x11\n\tchannel13\x18\x01 \x01(\r\x12\x11\n\tchannel14\x18\x02 \x01(\r\x12\x11\n\tchannel15\x18\x03 \x01(\r\x12\x11\n\tchannel16\x18\x04 \x01(\r\x12\x1b\n\x13_internal_timestamp\x18\x05 \x01(\x04\"p\n\tIRTS_RR_0\x12\x10\n\x08\x63hannel1\x18\x01 \x01(\r\x12\x10\n\x08\x63hannel2\x18\x02 \x01(\r\x12\x10\n\x08\x63hannel3\x18\x03 \x01(\r\x12\x10\n\x08\x63hannel4\x18\x04 \x01(\r\x12\x1b\n\x13_internal_timestamp\x18\x05 \x01(\x04\"p\n\tIRTS_RR_1\x12\x10\n\x08\x63hannel5\x18\x01 \x01(\r\x12\x10\n\x08\x63hannel6\x18\x02 \x01(\r\x12\x10\n\x08\x63hannel7\x18\x03 \x01(\r\x12\x10\n\x08\x63hannel8\x18\x04 \x01(\r\x12\x1b\n\x13_internal_timestamp\x18\x05 \x01(\x04\"s\n\tIRTS_RR_2\x12\x10\n\x08\x63hannel9\x18\x01 \x01(\r\x12\x11\n\tchannel10\x18\x02 \x01(\r\x12\x11\n\tchannel11\x18\x03 \x01(\r\x12\x11\n\tchannel12\x18\x04 \x01(\r\x12\x1b\n\x13_internal_timestamp\x18\x05 \x01(\x04\"t\n\tIRTS_RR_3\x12\x11\n\tchannel13\x18\x01 \x01(\r\x12\x11\n\tchannel14\x18\x02 \x01(\r\x12\x11\n\tchannel15\x18\x03 \x01(\r\x12\x11\n\tchannel16\x18\x04 \x01(\r\x12\x1b\n\x13_internal_timestamp\x18\x05 \x01(\x04\"N\n\nGPS_COORDS\x12\x10\n\x08latitude\x18\x01 \x01(\x02\x12\x11\n\tlongitude\x18\x02 \x01(\x02\x12\x1b\n\x13_internal_timestamp\x18\x03 \x01(\x04\"7\n\tGPS_SPEED\x12\r\n\x05speed\x18\x01 \x01(\r\x12\x1b\n\x13_internal_timestamp\x18\x02 \x01(\x04\"N\n\tLAP_COUNT\x12\x11\n\ttimestamp\x18\x01 \x01(\r\x12\x11\n\tlap_count\x18\x02 \x01(\r\x12\x1b\n\x13_internal_timestamp\x18\x03 \x01(\x04\"\x81\x07\n\x04Pack\x12\x35\n\x10IMU_ANGULAR_RATE\x18\x01 \x03(\x0b\x32\x1b.secondary.IMU_ANGULAR_RATE\x12\x35\n\x10IMU_ACCELERATION\x18\x02 \x03(\x0b\x32\x1b.secondary.IMU_ACCELERATION\x12\'\n\tIRTS_FL_0\x18\x03 \x03(\x0b\x32\x14.secondary.IRTS_FL_0\x12\'\n\tIRTS_FL_1\x18\x04 \x03(\x0b\x32\x14.secondary.IRTS_FL_1\x12\'\n\tIRTS_FL_2\x18\x05 \x03(\x0b\x32\x14.secondary.IRTS_FL_2\x12\'\n\tIRTS_FL_3\x18\x06 \x03(\x0b\x32\x14.secondary.IRTS_FL_3\x12\'\n\tIRTS_FR_0\x18\x07 \x03(\x0b\x32\x14.secondary.IRTS_FR_0\x12\'\n\tIRTS_FR_1\x18\x08 \x03(\x0b\x32\x14.secondary.IRTS_FR_1\x12\'\n\tIRTS_FR_2\x18\t \x03(\x0b\x32\x14.secondary.IRTS_FR_2\x12\'\n\tIRTS_FR_3\x18\n \x03(\x0b\x32\x14.secondary.IRTS_FR_3\x12\'\n\tIRTS_RL_0\x18\x0b \x03(\x0b\x32\x14.secondary.IRTS_RL_0\x12\'\n\tIRTS_RL_1\x18\x0c \x03(\x0b\x32\x14.secondary.IRTS_RL_1\x12\'\n\tIRTS_RL_2\x18\r \x03(\x0b\x32\x14.secondary.IRTS_RL_2\x12\'\n\tIRTS_RL_3\x18\x0e \x03(\x0b\x32\x14.secondary.IRTS_RL_3\x12\'\n\tIRTS_RR_0\x18\x0f \x03(\x0b\x32\x14.secondary.IRTS_RR_0\x12\'\n\tIRTS_RR_1\x18\x10 \x03(\x0b\x32\x14.secondary.IRTS_RR_1\x12\'\n\tIRTS_RR_2\x18\x11 \x03(\x0b\x32\x14.secondary.IRTS_RR_2\x12\'\n\tIRTS_RR_3\x18\x12 \x03(\x0b\x32\x14.secondary.IRTS_RR_3\x12)\n\nGPS_COORDS\x18\x13 \x03(\x0b\x32\x15.secondary.GPS_COORDS\x12\'\n\tGPS_SPEED\x18\x14 \x03(\x0b\x32\x14.secondary.GPS_SPEED\x12\'\n\tLAP_COUNT\x18\x15 \x03(\x0b\x32\x14.secondary.LAP_COUNTb\x06proto3')

_builder.BuildMessageAndEnumDescriptors(DESCRIPTOR, globals())
_builder.BuildTopDescriptorsAndMessages(DESCRIPTOR, 'network_pb2', globals())
if _descriptor._USE_C_DESCRIPTORS == False:

  DESCRIPTOR._options = None
  _IMU_ANGULAR_RATE._serialized_start=28
  _IMU_ANGULAR_RATE._serialized_end=135
  _IMU_ACCELERATION._serialized_start=137
  _IMU_ACCELERATION._serialized_end=235
  _IRTS_FL_0._serialized_start=237
  _IRTS_FL_0._serialized_end=349
  _IRTS_FL_1._serialized_start=351
  _IRTS_FL_1._serialized_end=463
  _IRTS_FL_2._serialized_start=465
  _IRTS_FL_2._serialized_end=580
  _IRTS_FL_3._serialized_start=582
  _IRTS_FL_3._serialized_end=698
  _IRTS_FR_0._serialized_start=700
  _IRTS_FR_0._serialized_end=812
  _IRTS_FR_1._serialized_start=814
  _IRTS_FR_1._serialized_end=926
  _IRTS_FR_2._serialized_start=928
  _IRTS_FR_2._serialized_end=1043
  _IRTS_FR_3._serialized_start=1045
  _IRTS_FR_3._serialized_end=1161
  _IRTS_RL_0._serialized_start=1163
  _IRTS_RL_0._serialized_end=1275
  _IRTS_RL_1._serialized_start=1277
  _IRTS_RL_1._serialized_end=1389
  _IRTS_RL_2._serialized_start=1391
  _IRTS_RL_2._serialized_end=1506
  _IRTS_RL_3._serialized_start=1508
  _IRTS_RL_3._serialized_end=1624
  _IRTS_RR_0._serialized_start=1626
  _IRTS_RR_0._serialized_end=1738
  _IRTS_RR_1._serialized_start=1740
  _IRTS_RR_1._serialized_end=1852
  _IRTS_RR_2._serialized_start=1854
  _IRTS_RR_2._serialized_end=1969
  _IRTS_RR_3._serialized_start=1971
  _IRTS_RR_3._serialized_end=2087
  _GPS_COORDS._serialized_start=2089
  _GPS_COORDS._serialized_end=2167
  _GPS_SPEED._serialized_start=2169
  _GPS_SPEED._serialized_end=2224
  _LAP_COUNT._serialized_start=2226
  _LAP_COUNT._serialized_end=2304
  _PACK._serialized_start=2307
  _PACK._serialized_end=3204
# @@protoc_insertion_point(module_scope)
