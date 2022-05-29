from enum import IntEnum, IntFlag
from struct import pack, unpack
from typing import Any

def int8(value: Any) -> int:
    return int(value)

def uint8(value: Any) -> int:
    return int(value)

def int16(value: Any) -> int:
    return int(value)

def uint16(value: Any) -> int:
    return int(value)

def int32(value: Any) -> int:
    return int(value)

def uint32(value: Any) -> int:
    return int(value)

def int64(value: Any) -> int:
    return int(value)

def uint64(value: Any) -> int:
    return int(value)

def float32(value: Any) -> float:
    return float(value)

def float64(value: Any) -> float:
    return float(value)

def bool(value: Any) -> bool:
    return bool(value)


# Bitsets

# Enums

# Messages


class message_IMU_ANGULAR_RATE:
    def __init__(
        self,
        ang_rate_x = None,
        ang_rate_y = None,
        ang_rate_z = None
    ):
        self.ang_rate_x = uint16(ang_rate_x) if ang_rate_x is not None else None
        self.ang_rate_y = uint16(ang_rate_y) if ang_rate_y is not None else None
        self.ang_rate_z = uint16(ang_rate_z) if ang_rate_z is not None else None
        self.size = 6

    def __eq__(self, other):
        if not isinstance(other, message_IMU_ANGULAR_RATE):
            return False
        if self.ang_rate_x != other.ang_rate_x:
            return False
        if self.ang_rate_y != other.ang_rate_y:
            return False
        if self.ang_rate_z != other.ang_rate_z:
            return False
        return True



def serialize_IMU_ANGULAR_RATE(message: message_IMU_ANGULAR_RATE) -> bytearray:
    data = bytearray()
    data.extend(pack("<HHH", message.ang_rate_x, message.ang_rate_y, message.ang_rate_z))
    return data

def deserialize_IMU_ANGULAR_RATE(data: bytearray) -> message_IMU_ANGULAR_RATE:
    message = message_IMU_ANGULAR_RATE()
    message.ang_rate_x = uint16(unpack("<H", data[0:2])[0])
    message.ang_rate_y = uint16(unpack("<xxH", data[0:4])[0])
    message.ang_rate_z = uint16(unpack("<xxxxH", data[0:6])[0])
    return message


class message_IMU_ACCELERATION:
    def __init__(
        self,
        accel_x = None,
        accel_y = None,
        accel_z = None
    ):
        self.accel_x = uint16(accel_x) if accel_x is not None else None
        self.accel_y = uint16(accel_y) if accel_y is not None else None
        self.accel_z = uint16(accel_z) if accel_z is not None else None
        self.size = 6

    def __eq__(self, other):
        if not isinstance(other, message_IMU_ACCELERATION):
            return False
        if self.accel_x != other.accel_x:
            return False
        if self.accel_y != other.accel_y:
            return False
        if self.accel_z != other.accel_z:
            return False
        return True



def serialize_IMU_ACCELERATION(message: message_IMU_ACCELERATION) -> bytearray:
    data = bytearray()
    data.extend(pack("<HHH", message.accel_x, message.accel_y, message.accel_z))
    return data

def deserialize_IMU_ACCELERATION(data: bytearray) -> message_IMU_ACCELERATION:
    message = message_IMU_ACCELERATION()
    message.accel_x = uint16(unpack("<H", data[0:2])[0])
    message.accel_y = uint16(unpack("<xxH", data[0:4])[0])
    message.accel_z = uint16(unpack("<xxxxH", data[0:6])[0])
    return message


class message_IRTS_FL_0:
    def __init__(
        self,
        channel1 = None,
        channel2 = None,
        channel3 = None,
        channel4 = None
    ):
        self.channel1 = uint16(channel1) if channel1 is not None else None
        self.channel2 = uint16(channel2) if channel2 is not None else None
        self.channel3 = uint16(channel3) if channel3 is not None else None
        self.channel4 = uint16(channel4) if channel4 is not None else None
        self.size = 8

    def __eq__(self, other):
        if not isinstance(other, message_IRTS_FL_0):
            return False
        if self.channel1 != other.channel1:
            return False
        if self.channel2 != other.channel2:
            return False
        if self.channel3 != other.channel3:
            return False
        if self.channel4 != other.channel4:
            return False
        return True



def serialize_IRTS_FL_0(message: message_IRTS_FL_0) -> bytearray:
    data = bytearray()
    data.extend(pack("<HHHH", message.channel1, message.channel2, message.channel3, message.channel4))
    return data

def deserialize_IRTS_FL_0(data: bytearray) -> message_IRTS_FL_0:
    message = message_IRTS_FL_0()
    message.channel1 = uint16(unpack("<H", data[0:2])[0])
    message.channel2 = uint16(unpack("<xxH", data[0:4])[0])
    message.channel3 = uint16(unpack("<xxxxH", data[0:6])[0])
    message.channel4 = uint16(unpack("<xxxxxxH", data[0:8])[0])
    return message


class message_IRTS_FL_1:
    def __init__(
        self,
        channel5 = None,
        channel6 = None,
        channel7 = None,
        channel8 = None
    ):
        self.channel5 = uint16(channel5) if channel5 is not None else None
        self.channel6 = uint16(channel6) if channel6 is not None else None
        self.channel7 = uint16(channel7) if channel7 is not None else None
        self.channel8 = uint16(channel8) if channel8 is not None else None
        self.size = 8

    def __eq__(self, other):
        if not isinstance(other, message_IRTS_FL_1):
            return False
        if self.channel5 != other.channel5:
            return False
        if self.channel6 != other.channel6:
            return False
        if self.channel7 != other.channel7:
            return False
        if self.channel8 != other.channel8:
            return False
        return True



def serialize_IRTS_FL_1(message: message_IRTS_FL_1) -> bytearray:
    data = bytearray()
    data.extend(pack("<HHHH", message.channel5, message.channel6, message.channel7, message.channel8))
    return data

def deserialize_IRTS_FL_1(data: bytearray) -> message_IRTS_FL_1:
    message = message_IRTS_FL_1()
    message.channel5 = uint16(unpack("<H", data[0:2])[0])
    message.channel6 = uint16(unpack("<xxH", data[0:4])[0])
    message.channel7 = uint16(unpack("<xxxxH", data[0:6])[0])
    message.channel8 = uint16(unpack("<xxxxxxH", data[0:8])[0])
    return message


class message_IRTS_FL_2:
    def __init__(
        self,
        channel9 = None,
        channel10 = None,
        channel11 = None,
        channel12 = None
    ):
        self.channel9 = uint16(channel9) if channel9 is not None else None
        self.channel10 = uint16(channel10) if channel10 is not None else None
        self.channel11 = uint16(channel11) if channel11 is not None else None
        self.channel12 = uint16(channel12) if channel12 is not None else None
        self.size = 8

    def __eq__(self, other):
        if not isinstance(other, message_IRTS_FL_2):
            return False
        if self.channel9 != other.channel9:
            return False
        if self.channel10 != other.channel10:
            return False
        if self.channel11 != other.channel11:
            return False
        if self.channel12 != other.channel12:
            return False
        return True



def serialize_IRTS_FL_2(message: message_IRTS_FL_2) -> bytearray:
    data = bytearray()
    data.extend(pack("<HHHH", message.channel9, message.channel10, message.channel11, message.channel12))
    return data

def deserialize_IRTS_FL_2(data: bytearray) -> message_IRTS_FL_2:
    message = message_IRTS_FL_2()
    message.channel9 = uint16(unpack("<H", data[0:2])[0])
    message.channel10 = uint16(unpack("<xxH", data[0:4])[0])
    message.channel11 = uint16(unpack("<xxxxH", data[0:6])[0])
    message.channel12 = uint16(unpack("<xxxxxxH", data[0:8])[0])
    return message


class message_IRTS_FL_3:
    def __init__(
        self,
        channel13 = None,
        channel14 = None,
        channel15 = None,
        channel16 = None
    ):
        self.channel13 = uint16(channel13) if channel13 is not None else None
        self.channel14 = uint16(channel14) if channel14 is not None else None
        self.channel15 = uint16(channel15) if channel15 is not None else None
        self.channel16 = uint16(channel16) if channel16 is not None else None
        self.size = 8

    def __eq__(self, other):
        if not isinstance(other, message_IRTS_FL_3):
            return False
        if self.channel13 != other.channel13:
            return False
        if self.channel14 != other.channel14:
            return False
        if self.channel15 != other.channel15:
            return False
        if self.channel16 != other.channel16:
            return False
        return True



def serialize_IRTS_FL_3(message: message_IRTS_FL_3) -> bytearray:
    data = bytearray()
    data.extend(pack("<HHHH", message.channel13, message.channel14, message.channel15, message.channel16))
    return data

def deserialize_IRTS_FL_3(data: bytearray) -> message_IRTS_FL_3:
    message = message_IRTS_FL_3()
    message.channel13 = uint16(unpack("<H", data[0:2])[0])
    message.channel14 = uint16(unpack("<xxH", data[0:4])[0])
    message.channel15 = uint16(unpack("<xxxxH", data[0:6])[0])
    message.channel16 = uint16(unpack("<xxxxxxH", data[0:8])[0])
    return message


class message_IRTS_FR_0:
    def __init__(
        self,
        channel1 = None,
        channel2 = None,
        channel3 = None,
        channel4 = None
    ):
        self.channel1 = uint16(channel1) if channel1 is not None else None
        self.channel2 = uint16(channel2) if channel2 is not None else None
        self.channel3 = uint16(channel3) if channel3 is not None else None
        self.channel4 = uint16(channel4) if channel4 is not None else None
        self.size = 8

    def __eq__(self, other):
        if not isinstance(other, message_IRTS_FR_0):
            return False
        if self.channel1 != other.channel1:
            return False
        if self.channel2 != other.channel2:
            return False
        if self.channel3 != other.channel3:
            return False
        if self.channel4 != other.channel4:
            return False
        return True



def serialize_IRTS_FR_0(message: message_IRTS_FR_0) -> bytearray:
    data = bytearray()
    data.extend(pack("<HHHH", message.channel1, message.channel2, message.channel3, message.channel4))
    return data

def deserialize_IRTS_FR_0(data: bytearray) -> message_IRTS_FR_0:
    message = message_IRTS_FR_0()
    message.channel1 = uint16(unpack("<H", data[0:2])[0])
    message.channel2 = uint16(unpack("<xxH", data[0:4])[0])
    message.channel3 = uint16(unpack("<xxxxH", data[0:6])[0])
    message.channel4 = uint16(unpack("<xxxxxxH", data[0:8])[0])
    return message


class message_IRTS_FR_1:
    def __init__(
        self,
        channel5 = None,
        channel6 = None,
        channel7 = None,
        channel8 = None
    ):
        self.channel5 = uint16(channel5) if channel5 is not None else None
        self.channel6 = uint16(channel6) if channel6 is not None else None
        self.channel7 = uint16(channel7) if channel7 is not None else None
        self.channel8 = uint16(channel8) if channel8 is not None else None
        self.size = 8

    def __eq__(self, other):
        if not isinstance(other, message_IRTS_FR_1):
            return False
        if self.channel5 != other.channel5:
            return False
        if self.channel6 != other.channel6:
            return False
        if self.channel7 != other.channel7:
            return False
        if self.channel8 != other.channel8:
            return False
        return True



def serialize_IRTS_FR_1(message: message_IRTS_FR_1) -> bytearray:
    data = bytearray()
    data.extend(pack("<HHHH", message.channel5, message.channel6, message.channel7, message.channel8))
    return data

def deserialize_IRTS_FR_1(data: bytearray) -> message_IRTS_FR_1:
    message = message_IRTS_FR_1()
    message.channel5 = uint16(unpack("<H", data[0:2])[0])
    message.channel6 = uint16(unpack("<xxH", data[0:4])[0])
    message.channel7 = uint16(unpack("<xxxxH", data[0:6])[0])
    message.channel8 = uint16(unpack("<xxxxxxH", data[0:8])[0])
    return message


class message_IRTS_FR_2:
    def __init__(
        self,
        channel9 = None,
        channel10 = None,
        channel11 = None,
        channel12 = None
    ):
        self.channel9 = uint16(channel9) if channel9 is not None else None
        self.channel10 = uint16(channel10) if channel10 is not None else None
        self.channel11 = uint16(channel11) if channel11 is not None else None
        self.channel12 = uint16(channel12) if channel12 is not None else None
        self.size = 8

    def __eq__(self, other):
        if not isinstance(other, message_IRTS_FR_2):
            return False
        if self.channel9 != other.channel9:
            return False
        if self.channel10 != other.channel10:
            return False
        if self.channel11 != other.channel11:
            return False
        if self.channel12 != other.channel12:
            return False
        return True



def serialize_IRTS_FR_2(message: message_IRTS_FR_2) -> bytearray:
    data = bytearray()
    data.extend(pack("<HHHH", message.channel9, message.channel10, message.channel11, message.channel12))
    return data

def deserialize_IRTS_FR_2(data: bytearray) -> message_IRTS_FR_2:
    message = message_IRTS_FR_2()
    message.channel9 = uint16(unpack("<H", data[0:2])[0])
    message.channel10 = uint16(unpack("<xxH", data[0:4])[0])
    message.channel11 = uint16(unpack("<xxxxH", data[0:6])[0])
    message.channel12 = uint16(unpack("<xxxxxxH", data[0:8])[0])
    return message


class message_IRTS_FR_3:
    def __init__(
        self,
        channel13 = None,
        channel14 = None,
        channel15 = None,
        channel16 = None
    ):
        self.channel13 = uint16(channel13) if channel13 is not None else None
        self.channel14 = uint16(channel14) if channel14 is not None else None
        self.channel15 = uint16(channel15) if channel15 is not None else None
        self.channel16 = uint16(channel16) if channel16 is not None else None
        self.size = 8

    def __eq__(self, other):
        if not isinstance(other, message_IRTS_FR_3):
            return False
        if self.channel13 != other.channel13:
            return False
        if self.channel14 != other.channel14:
            return False
        if self.channel15 != other.channel15:
            return False
        if self.channel16 != other.channel16:
            return False
        return True



def serialize_IRTS_FR_3(message: message_IRTS_FR_3) -> bytearray:
    data = bytearray()
    data.extend(pack("<HHHH", message.channel13, message.channel14, message.channel15, message.channel16))
    return data

def deserialize_IRTS_FR_3(data: bytearray) -> message_IRTS_FR_3:
    message = message_IRTS_FR_3()
    message.channel13 = uint16(unpack("<H", data[0:2])[0])
    message.channel14 = uint16(unpack("<xxH", data[0:4])[0])
    message.channel15 = uint16(unpack("<xxxxH", data[0:6])[0])
    message.channel16 = uint16(unpack("<xxxxxxH", data[0:8])[0])
    return message


class message_IRTS_RL_0:
    def __init__(
        self,
        channel1 = None,
        channel2 = None,
        channel3 = None,
        channel4 = None
    ):
        self.channel1 = uint16(channel1) if channel1 is not None else None
        self.channel2 = uint16(channel2) if channel2 is not None else None
        self.channel3 = uint16(channel3) if channel3 is not None else None
        self.channel4 = uint16(channel4) if channel4 is not None else None
        self.size = 8

    def __eq__(self, other):
        if not isinstance(other, message_IRTS_RL_0):
            return False
        if self.channel1 != other.channel1:
            return False
        if self.channel2 != other.channel2:
            return False
        if self.channel3 != other.channel3:
            return False
        if self.channel4 != other.channel4:
            return False
        return True



def serialize_IRTS_RL_0(message: message_IRTS_RL_0) -> bytearray:
    data = bytearray()
    data.extend(pack("<HHHH", message.channel1, message.channel2, message.channel3, message.channel4))
    return data

def deserialize_IRTS_RL_0(data: bytearray) -> message_IRTS_RL_0:
    message = message_IRTS_RL_0()
    message.channel1 = uint16(unpack("<H", data[0:2])[0])
    message.channel2 = uint16(unpack("<xxH", data[0:4])[0])
    message.channel3 = uint16(unpack("<xxxxH", data[0:6])[0])
    message.channel4 = uint16(unpack("<xxxxxxH", data[0:8])[0])
    return message


class message_IRTS_RL_1:
    def __init__(
        self,
        channel5 = None,
        channel6 = None,
        channel7 = None,
        channel8 = None
    ):
        self.channel5 = uint16(channel5) if channel5 is not None else None
        self.channel6 = uint16(channel6) if channel6 is not None else None
        self.channel7 = uint16(channel7) if channel7 is not None else None
        self.channel8 = uint16(channel8) if channel8 is not None else None
        self.size = 8

    def __eq__(self, other):
        if not isinstance(other, message_IRTS_RL_1):
            return False
        if self.channel5 != other.channel5:
            return False
        if self.channel6 != other.channel6:
            return False
        if self.channel7 != other.channel7:
            return False
        if self.channel8 != other.channel8:
            return False
        return True



def serialize_IRTS_RL_1(message: message_IRTS_RL_1) -> bytearray:
    data = bytearray()
    data.extend(pack("<HHHH", message.channel5, message.channel6, message.channel7, message.channel8))
    return data

def deserialize_IRTS_RL_1(data: bytearray) -> message_IRTS_RL_1:
    message = message_IRTS_RL_1()
    message.channel5 = uint16(unpack("<H", data[0:2])[0])
    message.channel6 = uint16(unpack("<xxH", data[0:4])[0])
    message.channel7 = uint16(unpack("<xxxxH", data[0:6])[0])
    message.channel8 = uint16(unpack("<xxxxxxH", data[0:8])[0])
    return message


class message_IRTS_RL_2:
    def __init__(
        self,
        channel9 = None,
        channel10 = None,
        channel11 = None,
        channel12 = None
    ):
        self.channel9 = uint16(channel9) if channel9 is not None else None
        self.channel10 = uint16(channel10) if channel10 is not None else None
        self.channel11 = uint16(channel11) if channel11 is not None else None
        self.channel12 = uint16(channel12) if channel12 is not None else None
        self.size = 8

    def __eq__(self, other):
        if not isinstance(other, message_IRTS_RL_2):
            return False
        if self.channel9 != other.channel9:
            return False
        if self.channel10 != other.channel10:
            return False
        if self.channel11 != other.channel11:
            return False
        if self.channel12 != other.channel12:
            return False
        return True



def serialize_IRTS_RL_2(message: message_IRTS_RL_2) -> bytearray:
    data = bytearray()
    data.extend(pack("<HHHH", message.channel9, message.channel10, message.channel11, message.channel12))
    return data

def deserialize_IRTS_RL_2(data: bytearray) -> message_IRTS_RL_2:
    message = message_IRTS_RL_2()
    message.channel9 = uint16(unpack("<H", data[0:2])[0])
    message.channel10 = uint16(unpack("<xxH", data[0:4])[0])
    message.channel11 = uint16(unpack("<xxxxH", data[0:6])[0])
    message.channel12 = uint16(unpack("<xxxxxxH", data[0:8])[0])
    return message


class message_IRTS_RL_3:
    def __init__(
        self,
        channel13 = None,
        channel14 = None,
        channel15 = None,
        channel16 = None
    ):
        self.channel13 = uint16(channel13) if channel13 is not None else None
        self.channel14 = uint16(channel14) if channel14 is not None else None
        self.channel15 = uint16(channel15) if channel15 is not None else None
        self.channel16 = uint16(channel16) if channel16 is not None else None
        self.size = 8

    def __eq__(self, other):
        if not isinstance(other, message_IRTS_RL_3):
            return False
        if self.channel13 != other.channel13:
            return False
        if self.channel14 != other.channel14:
            return False
        if self.channel15 != other.channel15:
            return False
        if self.channel16 != other.channel16:
            return False
        return True



def serialize_IRTS_RL_3(message: message_IRTS_RL_3) -> bytearray:
    data = bytearray()
    data.extend(pack("<HHHH", message.channel13, message.channel14, message.channel15, message.channel16))
    return data

def deserialize_IRTS_RL_3(data: bytearray) -> message_IRTS_RL_3:
    message = message_IRTS_RL_3()
    message.channel13 = uint16(unpack("<H", data[0:2])[0])
    message.channel14 = uint16(unpack("<xxH", data[0:4])[0])
    message.channel15 = uint16(unpack("<xxxxH", data[0:6])[0])
    message.channel16 = uint16(unpack("<xxxxxxH", data[0:8])[0])
    return message


class message_IRTS_RR_0:
    def __init__(
        self,
        channel1 = None,
        channel2 = None,
        channel3 = None,
        channel4 = None
    ):
        self.channel1 = uint16(channel1) if channel1 is not None else None
        self.channel2 = uint16(channel2) if channel2 is not None else None
        self.channel3 = uint16(channel3) if channel3 is not None else None
        self.channel4 = uint16(channel4) if channel4 is not None else None
        self.size = 8

    def __eq__(self, other):
        if not isinstance(other, message_IRTS_RR_0):
            return False
        if self.channel1 != other.channel1:
            return False
        if self.channel2 != other.channel2:
            return False
        if self.channel3 != other.channel3:
            return False
        if self.channel4 != other.channel4:
            return False
        return True



def serialize_IRTS_RR_0(message: message_IRTS_RR_0) -> bytearray:
    data = bytearray()
    data.extend(pack("<HHHH", message.channel1, message.channel2, message.channel3, message.channel4))
    return data

def deserialize_IRTS_RR_0(data: bytearray) -> message_IRTS_RR_0:
    message = message_IRTS_RR_0()
    message.channel1 = uint16(unpack("<H", data[0:2])[0])
    message.channel2 = uint16(unpack("<xxH", data[0:4])[0])
    message.channel3 = uint16(unpack("<xxxxH", data[0:6])[0])
    message.channel4 = uint16(unpack("<xxxxxxH", data[0:8])[0])
    return message


class message_IRTS_RR_1:
    def __init__(
        self,
        channel5 = None,
        channel6 = None,
        channel7 = None,
        channel8 = None
    ):
        self.channel5 = uint16(channel5) if channel5 is not None else None
        self.channel6 = uint16(channel6) if channel6 is not None else None
        self.channel7 = uint16(channel7) if channel7 is not None else None
        self.channel8 = uint16(channel8) if channel8 is not None else None
        self.size = 8

    def __eq__(self, other):
        if not isinstance(other, message_IRTS_RR_1):
            return False
        if self.channel5 != other.channel5:
            return False
        if self.channel6 != other.channel6:
            return False
        if self.channel7 != other.channel7:
            return False
        if self.channel8 != other.channel8:
            return False
        return True



def serialize_IRTS_RR_1(message: message_IRTS_RR_1) -> bytearray:
    data = bytearray()
    data.extend(pack("<HHHH", message.channel5, message.channel6, message.channel7, message.channel8))
    return data

def deserialize_IRTS_RR_1(data: bytearray) -> message_IRTS_RR_1:
    message = message_IRTS_RR_1()
    message.channel5 = uint16(unpack("<H", data[0:2])[0])
    message.channel6 = uint16(unpack("<xxH", data[0:4])[0])
    message.channel7 = uint16(unpack("<xxxxH", data[0:6])[0])
    message.channel8 = uint16(unpack("<xxxxxxH", data[0:8])[0])
    return message


class message_IRTS_RR_2:
    def __init__(
        self,
        channel9 = None,
        channel10 = None,
        channel11 = None,
        channel12 = None
    ):
        self.channel9 = uint16(channel9) if channel9 is not None else None
        self.channel10 = uint16(channel10) if channel10 is not None else None
        self.channel11 = uint16(channel11) if channel11 is not None else None
        self.channel12 = uint16(channel12) if channel12 is not None else None
        self.size = 8

    def __eq__(self, other):
        if not isinstance(other, message_IRTS_RR_2):
            return False
        if self.channel9 != other.channel9:
            return False
        if self.channel10 != other.channel10:
            return False
        if self.channel11 != other.channel11:
            return False
        if self.channel12 != other.channel12:
            return False
        return True



def serialize_IRTS_RR_2(message: message_IRTS_RR_2) -> bytearray:
    data = bytearray()
    data.extend(pack("<HHHH", message.channel9, message.channel10, message.channel11, message.channel12))
    return data

def deserialize_IRTS_RR_2(data: bytearray) -> message_IRTS_RR_2:
    message = message_IRTS_RR_2()
    message.channel9 = uint16(unpack("<H", data[0:2])[0])
    message.channel10 = uint16(unpack("<xxH", data[0:4])[0])
    message.channel11 = uint16(unpack("<xxxxH", data[0:6])[0])
    message.channel12 = uint16(unpack("<xxxxxxH", data[0:8])[0])
    return message


class message_IRTS_RR_3:
    def __init__(
        self,
        channel13 = None,
        channel14 = None,
        channel15 = None,
        channel16 = None
    ):
        self.channel13 = uint16(channel13) if channel13 is not None else None
        self.channel14 = uint16(channel14) if channel14 is not None else None
        self.channel15 = uint16(channel15) if channel15 is not None else None
        self.channel16 = uint16(channel16) if channel16 is not None else None
        self.size = 8

    def __eq__(self, other):
        if not isinstance(other, message_IRTS_RR_3):
            return False
        if self.channel13 != other.channel13:
            return False
        if self.channel14 != other.channel14:
            return False
        if self.channel15 != other.channel15:
            return False
        if self.channel16 != other.channel16:
            return False
        return True



def serialize_IRTS_RR_3(message: message_IRTS_RR_3) -> bytearray:
    data = bytearray()
    data.extend(pack("<HHHH", message.channel13, message.channel14, message.channel15, message.channel16))
    return data

def deserialize_IRTS_RR_3(data: bytearray) -> message_IRTS_RR_3:
    message = message_IRTS_RR_3()
    message.channel13 = uint16(unpack("<H", data[0:2])[0])
    message.channel14 = uint16(unpack("<xxH", data[0:4])[0])
    message.channel15 = uint16(unpack("<xxxxH", data[0:6])[0])
    message.channel16 = uint16(unpack("<xxxxxxH", data[0:8])[0])
    return message


class message_GPS_COORDS:
    def __init__(
        self,
        latitude = None,
        longitude = None
    ):
        self.latitude = float32(latitude) if latitude is not None else None
        self.longitude = float32(longitude) if longitude is not None else None
        self.size = 8

    def __eq__(self, other):
        if not isinstance(other, message_GPS_COORDS):
            return False
        if self.latitude != other.latitude:
            return False
        if self.longitude != other.longitude:
            return False
        return True



def serialize_GPS_COORDS(message: message_GPS_COORDS) -> bytearray:
    data = bytearray()
    data.extend(pack("<ff", message.latitude, message.longitude))
    return data

def deserialize_GPS_COORDS(data: bytearray) -> message_GPS_COORDS:
    message = message_GPS_COORDS()
    message.latitude = float32(unpack("<f", data[0:4])[0])
    message.longitude = float32(unpack("<xxxxf", data[0:8])[0])
    return message


class message_GPS_SPEED:
    def __init__(
        self,
        speed = None
    ):
        self.speed = uint16(speed) if speed is not None else None
        self.size = 2

    def __eq__(self, other):
        if not isinstance(other, message_GPS_SPEED):
            return False
        if self.speed != other.speed:
            return False
        return True



def serialize_GPS_SPEED(message: message_GPS_SPEED) -> bytearray:
    data = bytearray()
    data.extend(pack("<H", message.speed))
    return data

def deserialize_GPS_SPEED(data: bytearray) -> message_GPS_SPEED:
    message = message_GPS_SPEED()
    message.speed = uint16(unpack("<H", data[0:2])[0])
    return message


class message_LAP_COUNT:
    def __init__(
        self,
        timestamp = None,
        lap_count = None
    ):
        self.timestamp = uint32(timestamp) if timestamp is not None else None
        self.lap_count = uint8(lap_count) if lap_count is not None else None
        self.size = 5

    def __eq__(self, other):
        if not isinstance(other, message_LAP_COUNT):
            return False
        if self.timestamp != other.timestamp:
            return False
        if self.lap_count != other.lap_count:
            return False
        return True



def serialize_LAP_COUNT(message: message_LAP_COUNT) -> bytearray:
    data = bytearray()
    data.extend(pack("<IB", message.timestamp, message.lap_count))
    return data

def deserialize_LAP_COUNT(data: bytearray) -> message_LAP_COUNT:
    message = message_LAP_COUNT()
    message.timestamp = uint32(unpack("<I", data[0:4])[0])
    message.lap_count = uint8(unpack("<xxxxB", data[0:5])[0])
    return message

