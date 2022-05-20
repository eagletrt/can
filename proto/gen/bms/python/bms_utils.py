import bms_pb2
def protobuf2dict(id, payload):
match id:
case {'BOARD_STATUS_CELLBOARD0': 1536, 'BOARD_STATUS_CELLBOARD1': 1568, 'BOARD_STATUS_CELLBOARD2': 1600, 'BOARD_STATUS_CELLBOARD3': 1632, 'BOARD_STATUS_CELLBOARD4': 1664, 'BOARD_STATUS_CELLBOARD5': 1696}
:

message = bms_pb2.BoardStatus()
message.ParseFromString(payload)
return {field.name: getattr(message, field.name) for field in message.DESCRIPTOR.fields}

case {'TEMPERATURES_CELLBOARD0': 1281, 'TEMPERATURES_CELLBOARD1': 1313, 'TEMPERATURES_CELLBOARD2': 1345, 'TEMPERATURES_CELLBOARD3': 1377, 'TEMPERATURES_CELLBOARD4': 1409, 'TEMPERATURES_CELLBOARD5': 1441}
:

message = bms_pb2.Temperatures()
message.ParseFromString(payload)
return {field.name: getattr(message, field.name) for field in message.DESCRIPTOR.fields}

case {'VOLTAGES_CELLBOARD0': 514, 'VOLTAGES_CELLBOARD1': 546, 'VOLTAGES_CELLBOARD2': 578, 'VOLTAGES_CELLBOARD3': 610, 'VOLTAGES_CELLBOARD4': 642, 'VOLTAGES_CELLBOARD5': 674}
:

message = bms_pb2.Voltages()
message.ParseFromString(payload)
return {field.name: getattr(message, field.name) for field in message.DESCRIPTOR.fields}

case {'BALANCING': 515}
:

message = bms_pb2.Balancing()
message.ParseFromString(payload)
return {field.name: getattr(message, field.name) for field in message.DESCRIPTOR.fields}

case {'FW_UPDATE': 260}
:

message = bms_pb2.FwUpdate()
message.ParseFromString(payload)
return {field.name: getattr(message, field.name) for field in message.DESCRIPTOR.fields}

raise Exception("Unknown message id")