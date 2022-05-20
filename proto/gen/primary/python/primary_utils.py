import primary_pb2
def protobuf2dict(id, payload):
match id:
case {'STEER_VERSION': 1024}
:

message = primary_pb2.SteerVersion()
message.ParseFromString(payload)
return {field.name: getattr(message, field.name) for field in message.DESCRIPTOR.fields}

case {'DAS_VERSION': 1056}
:

message = primary_pb2.DasVersion()
message.ParseFromString(payload)
return {field.name: getattr(message, field.name) for field in message.DESCRIPTOR.fields}

case {'HV_VERSION': 1088}
:

message = primary_pb2.HvVersion()
message.ParseFromString(payload)
return {field.name: getattr(message, field.name) for field in message.DESCRIPTOR.fields}

case {'LV_VERSION': 1120}
:

message = primary_pb2.LvVersion()
message.ParseFromString(payload)
return {field.name: getattr(message, field.name) for field in message.DESCRIPTOR.fields}

case {'TLM_VERSION': 1152}
:

message = primary_pb2.TlmVersion()
message.ParseFromString(payload)
return {field.name: getattr(message, field.name) for field in message.DESCRIPTOR.fields}

case {'TIMESTAMP': 256}
:

message = primary_pb2.Timestamp()
message.ParseFromString(payload)
return {field.name: getattr(message, field.name) for field in message.DESCRIPTOR.fields}

case {'SET_TLM_STATUS': 257}
:

message = primary_pb2.SetTlmStatus()
message.ParseFromString(payload)
return {field.name: getattr(message, field.name) for field in message.DESCRIPTOR.fields}

case {'TLM_STATUS': 258}
:

message = primary_pb2.TlmStatus()
message.ParseFromString(payload)
return {field.name: getattr(message, field.name) for field in message.DESCRIPTOR.fields}

case {'STEER_SYSTEM_STATUS': 1793}
:

message = primary_pb2.SteerSystemStatus()
message.ParseFromString(payload)
return {field.name: getattr(message, field.name) for field in message.DESCRIPTOR.fields}

case {'HV_VOLTAGE': 771}
:

message = primary_pb2.HvVoltage()
message.ParseFromString(payload)
return {field.name: getattr(message, field.name) for field in message.DESCRIPTOR.fields}

case {'HV_CURRENT': 803}
:

message = primary_pb2.HvCurrent()
message.ParseFromString(payload)
return {field.name: getattr(message, field.name) for field in message.DESCRIPTOR.fields}

case {'HV_TEMP': 835}
:

message = primary_pb2.HvTemp()
message.ParseFromString(payload)
return {field.name: getattr(message, field.name) for field in message.DESCRIPTOR.fields}

case {'HV_ERRORS': 3}
:

message = primary_pb2.HvErrors()
message.ParseFromString(payload)
return {field.name: getattr(message, field.name) for field in message.DESCRIPTOR.fields}

case {'TS_STATUS': 35}
:

message = primary_pb2.TsStatus()
message.ParseFromString(payload)
return {field.name: getattr(message, field.name) for field in message.DESCRIPTOR.fields}

case {'SET_TS_STATUS_DAS': 4, 'SET_TS_STATUS_HANDCART': 36}
:

message = primary_pb2.SetTsStatus()
message.ParseFromString(payload)
return {field.name: getattr(message, field.name) for field in message.DESCRIPTOR.fields}

case {'STEER_STATUS': 261}
:

message = primary_pb2.SteerStatus()
message.ParseFromString(payload)
return {field.name: getattr(message, field.name) for field in message.DESCRIPTOR.fields}

case {'SET_CAR_STATUS': 773}
:

message = primary_pb2.SetCarStatus()
message.ParseFromString(payload)
return {field.name: getattr(message, field.name) for field in message.DESCRIPTOR.fields}

case {'SET_PEDALS_RANGE': 1029}
:

message = primary_pb2.SetPedalsRange()
message.ParseFromString(payload)
return {field.name: getattr(message, field.name) for field in message.DESCRIPTOR.fields}

case {'CAR_STATUS': 514}
:

message = primary_pb2.CarStatus()
message.ParseFromString(payload)
return {field.name: getattr(message, field.name) for field in message.DESCRIPTOR.fields}

case {'DAS_ERRORS': 2}
:

message = primary_pb2.DasErrors()
message.ParseFromString(payload)
return {field.name: getattr(message, field.name) for field in message.DESCRIPTOR.fields}

case {'LV_CURRENT': 774}
:

message = primary_pb2.LvCurrent()
message.ParseFromString(payload)
return {field.name: getattr(message, field.name) for field in message.DESCRIPTOR.fields}

case {'LV_VOLTAGE': 806}
:

message = primary_pb2.LvVoltage()
message.ParseFromString(payload)
return {field.name: getattr(message, field.name) for field in message.DESCRIPTOR.fields}

case {'LV_TEMPERATURE': 838}
:

message = primary_pb2.LvTemperature()
message.ParseFromString(payload)
return {field.name: getattr(message, field.name) for field in message.DESCRIPTOR.fields}

case {'COOLING_STATUS': 870}
:

message = primary_pb2.CoolingStatus()
message.ParseFromString(payload)
return {field.name: getattr(message, field.name) for field in message.DESCRIPTOR.fields}

case {'MARKER': 1}
:

message = primary_pb2.Marker()
message.ParseFromString(payload)
return {field.name: getattr(message, field.name) for field in message.DESCRIPTOR.fields}

case {'HV_CELLS_VOLTAGE': 519}
:

message = primary_pb2.HvCellsVoltage()
message.ParseFromString(payload)
return {field.name: getattr(message, field.name) for field in message.DESCRIPTOR.fields}

case {'HV_CELLS_TEMP': 551}
:

message = primary_pb2.HvCellsTemp()
message.ParseFromString(payload)
return {field.name: getattr(message, field.name) for field in message.DESCRIPTOR.fields}

case {'HV_CELL_BALANCING_STATUS': 583}
:

message = primary_pb2.HvCellBalancingStatus()
message.ParseFromString(payload)
return {field.name: getattr(message, field.name) for field in message.DESCRIPTOR.fields}

case {'SET_CELL_BALANCING_STATUS': 516}
:

message = primary_pb2.SetCellBalancingStatus()
message.ParseFromString(payload)
return {field.name: getattr(message, field.name) for field in message.DESCRIPTOR.fields}

case {'HANDCART_STATUS': 772}
:

message = primary_pb2.HandcartStatus()
message.ParseFromString(payload)
return {field.name: getattr(message, field.name) for field in message.DESCRIPTOR.fields}

case {'SPEED': 546}
:

message = primary_pb2.Speed()
message.ParseFromString(payload)
return {field.name: getattr(message, field.name) for field in message.DESCRIPTOR.fields}

case {'INV_L_SET_TORQUE': 513}
:

message = primary_pb2.InvLSetTorque()
message.ParseFromString(payload)
return {field.name: getattr(message, field.name) for field in message.DESCRIPTOR.fields}

case {'INV_L_RESPONSE': 385}
:

message = primary_pb2.InvLResponse()
message.ParseFromString(payload)
return {field.name: getattr(message, field.name) for field in message.DESCRIPTOR.fields}

raise Exception("Unknown message id")