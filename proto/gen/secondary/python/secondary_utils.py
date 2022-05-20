import secondary_pb2
def protobuf2dict(id, payload):
match id:
case {'IMU_ANGULAR_RATE': 1260}
:

message = secondary_pb2.ImuAngularRate()
message.ParseFromString(payload)
return {field.name: getattr(message, field.name) for field in message.DESCRIPTOR.fields}

case {'IMU_ACCELERATION': 1261}
:

message = secondary_pb2.ImuAcceleration()
message.ParseFromString(payload)
return {field.name: getattr(message, field.name) for field in message.DESCRIPTOR.fields}

case {'IRTS_FL_0': 1460}
:

message = secondary_pb2.IrtsFl0()
message.ParseFromString(payload)
return {field.name: getattr(message, field.name) for field in message.DESCRIPTOR.fields}

case {'IRTS_FL_1': 1461}
:

message = secondary_pb2.IrtsFl1()
message.ParseFromString(payload)
return {field.name: getattr(message, field.name) for field in message.DESCRIPTOR.fields}

case {'IRTS_FL_2': 1462}
:

message = secondary_pb2.IrtsFl2()
message.ParseFromString(payload)
return {field.name: getattr(message, field.name) for field in message.DESCRIPTOR.fields}

case {'IRTS_FL_3': 1463}
:

message = secondary_pb2.IrtsFl3()
message.ParseFromString(payload)
return {field.name: getattr(message, field.name) for field in message.DESCRIPTOR.fields}

case {'IRTS_FR_0': 1464}
:

message = secondary_pb2.IrtsFr0()
message.ParseFromString(payload)
return {field.name: getattr(message, field.name) for field in message.DESCRIPTOR.fields}

case {'IRTS_FR_1': 1465}
:

message = secondary_pb2.IrtsFr1()
message.ParseFromString(payload)
return {field.name: getattr(message, field.name) for field in message.DESCRIPTOR.fields}

case {'IRTS_FR_2': 1466}
:

message = secondary_pb2.IrtsFr2()
message.ParseFromString(payload)
return {field.name: getattr(message, field.name) for field in message.DESCRIPTOR.fields}

case {'IRTS_FR_3': 1467}
:

message = secondary_pb2.IrtsFr3()
message.ParseFromString(payload)
return {field.name: getattr(message, field.name) for field in message.DESCRIPTOR.fields}

case {'IRTS_RL_0': 1468}
:

message = secondary_pb2.IrtsRl0()
message.ParseFromString(payload)
return {field.name: getattr(message, field.name) for field in message.DESCRIPTOR.fields}

case {'IRTS_RL_1': 1469}
:

message = secondary_pb2.IrtsRl1()
message.ParseFromString(payload)
return {field.name: getattr(message, field.name) for field in message.DESCRIPTOR.fields}

case {'IRTS_RL_2': 1470}
:

message = secondary_pb2.IrtsRl2()
message.ParseFromString(payload)
return {field.name: getattr(message, field.name) for field in message.DESCRIPTOR.fields}

case {'IRTS_RL_3': 1471}
:

message = secondary_pb2.IrtsRl3()
message.ParseFromString(payload)
return {field.name: getattr(message, field.name) for field in message.DESCRIPTOR.fields}

case {'IRTS_RR_0': 1472}
:

message = secondary_pb2.IrtsRr0()
message.ParseFromString(payload)
return {field.name: getattr(message, field.name) for field in message.DESCRIPTOR.fields}

case {'IRTS_RR_1': 1473}
:

message = secondary_pb2.IrtsRr1()
message.ParseFromString(payload)
return {field.name: getattr(message, field.name) for field in message.DESCRIPTOR.fields}

case {'IRTS_RR_2': 1474}
:

message = secondary_pb2.IrtsRr2()
message.ParseFromString(payload)
return {field.name: getattr(message, field.name) for field in message.DESCRIPTOR.fields}

case {'IRTS_RR_3': 1475}
:

message = secondary_pb2.IrtsRr3()
message.ParseFromString(payload)
return {field.name: getattr(message, field.name) for field in message.DESCRIPTOR.fields}

case {'GPS_COORDS': 1025}
:

message = secondary_pb2.GpsCoords()
message.ParseFromString(payload)
return {field.name: getattr(message, field.name) for field in message.DESCRIPTOR.fields}

case {'GPS_SPEED': 1057}
:

message = secondary_pb2.GpsSpeed()
message.ParseFromString(payload)
return {field.name: getattr(message, field.name) for field in message.DESCRIPTOR.fields}

case {'LAP_COUNT': 1089}
:

message = secondary_pb2.LapCount()
message.ParseFromString(payload)
return {field.name: getattr(message, field.name) for field in message.DESCRIPTOR.fields}

raise Exception("Unknown message id")