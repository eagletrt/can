# -*- coding: utf-8 -*-
# Generated by the protocol buffer compiler.  DO NOT EDIT!
# source: bms.proto
"""Generated protocol buffer code."""
from google.protobuf.internal import builder as _builder
from google.protobuf import descriptor as _descriptor
from google.protobuf import descriptor_pool as _descriptor_pool
from google.protobuf import symbol_database as _symbol_database
# @@protoc_insertion_point(imports)

_sym_db = _symbol_database.Default()




DESCRIPTOR = _descriptor_pool.Default().AddSerializedFile(b'\n\tbms.proto\x12\x03\x62ms\"e\n\x0b\x42oardStatus\x12\x0e\n\x06\x65rrors\x18\x01 \x01(\r\x12\x32\n\x10\x62\x61lancing_status\x18\x02 \x01(\x0e\x32\x18.bms.BalancingstatusType\x12\x12\n\n_timestamp\x18\x03 \x01(\x04\"\x91\x01\n\x0cTemperatures\x12\x13\n\x0bstart_index\x18\x01 \x01(\r\x12\r\n\x05temp0\x18\x02 \x01(\r\x12\r\n\x05temp1\x18\x03 \x01(\r\x12\r\n\x05temp2\x18\x04 \x01(\r\x12\r\n\x05temp3\x18\x05 \x01(\r\x12\r\n\x05temp4\x18\x06 \x01(\r\x12\r\n\x05temp5\x18\x07 \x01(\r\x12\x12\n\n_timestamp\x18\x08 \x01(\x04\"i\n\x08Voltages\x12\x13\n\x0bstart_index\x18\x01 \x01(\r\x12\x10\n\x08voltage0\x18\x02 \x01(\r\x12\x10\n\x08voltage1\x18\x03 \x01(\r\x12\x10\n\x08voltage2\x18\x04 \x01(\r\x12\x12\n\n_timestamp\x18\x05 \x01(\x04\"C\n\tBalancing\x12\x13\n\x0b\x62oard_index\x18\x01 \x01(\r\x12\r\n\x05\x63\x65lls\x18\x02 \x01(\r\x12\x12\n\n_timestamp\x18\x03 \x01(\x04\"3\n\x08\x46wUpdate\x12\x13\n\x0b\x62oard_index\x18\x01 \x01(\r\x12\x12\n\n_timestamp\x18\x02 \x01(\x04\"\xc2\x01\n\tBmsFenice\x12&\n\x0c\x62oard_status\x18\x01 \x03(\x0b\x32\x10.bms.BoardStatus\x12\'\n\x0ctemperatures\x18\x02 \x03(\x0b\x32\x11.bms.Temperatures\x12\x1f\n\x08voltages\x18\x03 \x03(\x0b\x32\r.bms.Voltages\x12!\n\tbalancing\x18\x04 \x03(\x0b\x32\x0e.bms.Balancing\x12 \n\tfw_update\x18\x05 \x03(\x0b\x32\r.bms.FwUpdate*M\n\x13\x42\x61lancingstatusType\x12\x17\n\x13\x42\x41LANCINGSTATUS_OFF\x10\x00\x12\x1d\n\x19\x42\x41LANCINGSTATUS_DISCHARGE\x10\x01\x62\x06proto3')

_builder.BuildMessageAndEnumDescriptors(DESCRIPTOR, globals())
_builder.BuildTopDescriptorsAndMessages(DESCRIPTOR, 'bms_pb2', globals())
if _descriptor._USE_C_DESCRIPTORS == False:

  DESCRIPTOR._options = None
  _BALANCINGSTATUSTYPE._serialized_start=695
  _BALANCINGSTATUSTYPE._serialized_end=772
  _BOARDSTATUS._serialized_start=18
  _BOARDSTATUS._serialized_end=119
  _TEMPERATURES._serialized_start=122
  _TEMPERATURES._serialized_end=267
  _VOLTAGES._serialized_start=269
  _VOLTAGES._serialized_end=374
  _BALANCING._serialized_start=376
  _BALANCING._serialized_end=443
  _FWUPDATE._serialized_start=445
  _FWUPDATE._serialized_end=496
  _BMSFENICE._serialized_start=499
  _BMSFENICE._serialized_end=693
# @@protoc_insertion_point(module_scope)
