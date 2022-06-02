from __future__ import annotations
from enum import IntEnum, IntFlag
from struct import pack, unpack
from typing import Any, Optional
from builtins import bool as Bool

def int8(value: Any) -> Optional[int]:
    return int(value) if value is not None else None

def uint8(value: Any) -> Optional[int]:
    return int(value) if value is not None else None

def int16(value: Any) -> Optional[int]:
    return int(value) if value is not None else None

def uint16(value: Any) -> Optional[int]:
    return int(value) if value is not None else None

def int32(value: Any) -> Optional[int]:
    return int(value) if value is not None else None

def uint32(value: Any) -> Optional[int]:
    return int(value) if value is not None else None

def int64(value: Any) -> Optional[int]:
    return int(value) if value is not None else None

def uint64(value: Any) -> Optional[int]:
    return int(value) if value is not None else None

def float32(value: Any) -> Optional[float]:
    return float(value) if value is not None else None

def float64(value: Any) -> Optional[float]:
    return float(value) if value is not None else None

def bool(value: Any) -> Optional[Bool]:
    return Bool(value) if value is not None else None


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
        self.ang_rate_x = uint16(ang_rate_x)
        self.ang_rate_y = uint16(ang_rate_y)
        self.ang_rate_z = uint16(ang_rate_z)
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

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<HHH", self.ang_rate_x, self.ang_rate_y, self.ang_rate_z))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
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
        self.accel_x = uint16(accel_x)
        self.accel_y = uint16(accel_y)
        self.accel_z = uint16(accel_z)
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

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<HHH", self.accel_x, self.accel_y, self.accel_z))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
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
        self.channel1 = uint16(channel1)
        self.channel2 = uint16(channel2)
        self.channel3 = uint16(channel3)
        self.channel4 = uint16(channel4)
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

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<HHHH", self.channel1, self.channel2, self.channel3, self.channel4))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
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
        self.channel5 = uint16(channel5)
        self.channel6 = uint16(channel6)
        self.channel7 = uint16(channel7)
        self.channel8 = uint16(channel8)
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

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<HHHH", self.channel5, self.channel6, self.channel7, self.channel8))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
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
        self.channel9 = uint16(channel9)
        self.channel10 = uint16(channel10)
        self.channel11 = uint16(channel11)
        self.channel12 = uint16(channel12)
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

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<HHHH", self.channel9, self.channel10, self.channel11, self.channel12))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
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
        self.channel13 = uint16(channel13)
        self.channel14 = uint16(channel14)
        self.channel15 = uint16(channel15)
        self.channel16 = uint16(channel16)
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

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<HHHH", self.channel13, self.channel14, self.channel15, self.channel16))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
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
        self.channel1 = uint16(channel1)
        self.channel2 = uint16(channel2)
        self.channel3 = uint16(channel3)
        self.channel4 = uint16(channel4)
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

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<HHHH", self.channel1, self.channel2, self.channel3, self.channel4))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
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
        self.channel5 = uint16(channel5)
        self.channel6 = uint16(channel6)
        self.channel7 = uint16(channel7)
        self.channel8 = uint16(channel8)
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

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<HHHH", self.channel5, self.channel6, self.channel7, self.channel8))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
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
        self.channel9 = uint16(channel9)
        self.channel10 = uint16(channel10)
        self.channel11 = uint16(channel11)
        self.channel12 = uint16(channel12)
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

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<HHHH", self.channel9, self.channel10, self.channel11, self.channel12))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
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
        self.channel13 = uint16(channel13)
        self.channel14 = uint16(channel14)
        self.channel15 = uint16(channel15)
        self.channel16 = uint16(channel16)
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

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<HHHH", self.channel13, self.channel14, self.channel15, self.channel16))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
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
        self.channel1 = uint16(channel1)
        self.channel2 = uint16(channel2)
        self.channel3 = uint16(channel3)
        self.channel4 = uint16(channel4)
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

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<HHHH", self.channel1, self.channel2, self.channel3, self.channel4))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
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
        self.channel5 = uint16(channel5)
        self.channel6 = uint16(channel6)
        self.channel7 = uint16(channel7)
        self.channel8 = uint16(channel8)
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

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<HHHH", self.channel5, self.channel6, self.channel7, self.channel8))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
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
        self.channel9 = uint16(channel9)
        self.channel10 = uint16(channel10)
        self.channel11 = uint16(channel11)
        self.channel12 = uint16(channel12)
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

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<HHHH", self.channel9, self.channel10, self.channel11, self.channel12))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
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
        self.channel13 = uint16(channel13)
        self.channel14 = uint16(channel14)
        self.channel15 = uint16(channel15)
        self.channel16 = uint16(channel16)
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

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<HHHH", self.channel13, self.channel14, self.channel15, self.channel16))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
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
        self.channel1 = uint16(channel1)
        self.channel2 = uint16(channel2)
        self.channel3 = uint16(channel3)
        self.channel4 = uint16(channel4)
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

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<HHHH", self.channel1, self.channel2, self.channel3, self.channel4))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
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
        self.channel5 = uint16(channel5)
        self.channel6 = uint16(channel6)
        self.channel7 = uint16(channel7)
        self.channel8 = uint16(channel8)
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

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<HHHH", self.channel5, self.channel6, self.channel7, self.channel8))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
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
        self.channel9 = uint16(channel9)
        self.channel10 = uint16(channel10)
        self.channel11 = uint16(channel11)
        self.channel12 = uint16(channel12)
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

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<HHHH", self.channel9, self.channel10, self.channel11, self.channel12))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
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
        self.channel13 = uint16(channel13)
        self.channel14 = uint16(channel14)
        self.channel15 = uint16(channel15)
        self.channel16 = uint16(channel16)
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

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<HHHH", self.channel13, self.channel14, self.channel15, self.channel16))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
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
        self.latitude = float32(latitude)
        self.longitude = float32(longitude)
        self.size = 8

    def __eq__(self, other):
        if not isinstance(other, message_GPS_COORDS):
            return False
        if self.latitude != other.latitude:
            return False
        if self.longitude != other.longitude:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<ff", self.latitude, self.longitude))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.latitude = float32(unpack("<f", data[0:4])[0])
        message.longitude = float32(unpack("<xxxxf", data[0:8])[0])
        return message


class message_GPS_SPEED:
    def __init__(
        self,
        speed = None
    ):
        self.speed = uint16(speed)
        self.size = 2

    def __eq__(self, other):
        if not isinstance(other, message_GPS_SPEED):
            return False
        if self.speed != other.speed:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<H", self.speed))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.speed = uint16(unpack("<H", data[0:2])[0])
        return message


class message_LAP_COUNT:
    def __init__(
        self,
        timestamp = None,
        lap_count = None
    ):
        self.timestamp = uint32(timestamp)
        self.lap_count = uint8(lap_count)
        self.size = 5

    def __eq__(self, other):
        if not isinstance(other, message_LAP_COUNT):
            return False
        if self.timestamp != other.timestamp:
            return False
        if self.lap_count != other.lap_count:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<IB", self.timestamp, self.lap_count))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.timestamp = uint32(unpack("<I", data[0:4])[0])
        message.lap_count = uint8(unpack("<xxxxB", data[0:5])[0])
        return message


class message_PEDALS_OUTPUT:
    def __init__(
        self,
        brake_front = None,
        brake_rear = None,
        apps = None
    ):
        self.brake_front = uint16(brake_front)
        self.brake_rear = uint16(brake_rear)
        self.apps = uint8(apps)
        self.size = 5
        self.interval = 100

    def __eq__(self, other):
        if not isinstance(other, message_PEDALS_OUTPUT):
            return False
        if self.brake_front != other.brake_front:
            return False
        if self.brake_rear != other.brake_rear:
            return False
        if self.apps != other.apps:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<HHB", self.brake_front, self.brake_rear, self.apps))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.brake_front = uint16(unpack("<H", data[0:2])[0])
        message.brake_rear = uint16(unpack("<xxH", data[0:4])[0])
        message.apps = uint8(unpack("<xxxxB", data[0:5])[0])
        return message


    def convert(self) -> message_PEDALS_OUTPUT_conversion:
        conversion = message_PEDALS_OUTPUT_conversion()
        conversion.brake_front = ((float32(self.brake_front)) / 655.36) + 0
        conversion.brake_rear = ((float32(self.brake_rear)) / 655.36) + 0
        conversion.apps = self.apps
        return conversion


class message_PEDALS_OUTPUT_conversion:
    def __init__(
        self,
        brake_front = None,
        brake_rear = None,
        apps = None
    ):
        self.brake_front = float32(brake_front)
        self.brake_rear = float32(brake_rear)
        self.apps = uint8(apps)
        self.size = 5
        self.interval = 100

    def __eq__(self, other):
        if not isinstance(other, message_PEDALS_OUTPUT):
            return False
        if self.brake_front != other.brake_front:
            return False
        if self.brake_rear != other.brake_rear:
            return False
        if self.apps != other.apps:
            return False
        return True

    def convert_to_raw(self) -> message_PEDALS_OUTPUT:
        raw = message_PEDALS_OUTPUT()
        raw.brake_front = uint16((self.brake_front + 0) * 655.36)
        raw.brake_rear = uint16((self.brake_rear + 0) * 655.36)
        raw.apps = self.apps
        return raw

class message_CONTROL_OUTPUT:
    def __init__(
        self,
        right = None,
        left = None
    ):
        self.right = float32(right)
        self.left = float32(left)
        self.size = 8
        self.interval = 100

    def __eq__(self, other):
        if not isinstance(other, message_CONTROL_OUTPUT):
            return False
        if self.right != other.right:
            return False
        if self.left != other.left:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<ff", self.right, self.left))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.right = float32(unpack("<f", data[0:4])[0])
        message.left = float32(unpack("<xxxxf", data[0:8])[0])
        return message


class message_STEERING_ANGLE:
    def __init__(
        self,
        brake_rear = None
    ):
        self.brake_rear = float32(brake_rear)
        self.size = 4
        self.interval = 200

    def __eq__(self, other):
        if not isinstance(other, message_STEERING_ANGLE):
            return False
        if self.brake_rear != other.brake_rear:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<f", self.brake_rear))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.brake_rear = float32(unpack("<f", data[0:4])[0])
        return message

