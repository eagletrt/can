from __future__ import annotations
from enum import IntEnum, IntFlag
from struct import pack, unpack
from typing import Any, Optional
from builtins import bool as Bool

CANLIB_BUILD_TIME = 1685998146
CANLIB_BUILD_HASH = 0x414e6c6d

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
        self.ang_rate_x = int16(ang_rate_x)
        self.ang_rate_y = int16(ang_rate_y)
        self.ang_rate_z = int16(ang_rate_z)
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
        data.extend(pack(">hhh", self.ang_rate_x, self.ang_rate_y, self.ang_rate_z))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.ang_rate_x = int16(unpack(">h", data[0:2])[0])
        message.ang_rate_y = int16(unpack(">xxh", data[0:4])[0])
        message.ang_rate_z = int16(unpack(">xxxxh", data[0:6])[0])
        return message


    def convert(self) -> message_IMU_ANGULAR_RATE_conversion:
        conversion = message_IMU_ANGULAR_RATE_conversion()
        conversion.ang_rate_x = ((float32(self.ang_rate_x)) / 10.0) + 0
        conversion.ang_rate_y = ((float32(self.ang_rate_y)) / 10.0) + 0
        conversion.ang_rate_z = ((float32(self.ang_rate_z)) / 10.0) + 0
        return conversion


class message_IMU_ANGULAR_RATE_conversion:
    def __init__(
        self,
        ang_rate_x = None,
        ang_rate_y = None,
        ang_rate_z = None
    ):
        self.ang_rate_x = float32(ang_rate_x)
        self.ang_rate_y = float32(ang_rate_y)
        self.ang_rate_z = float32(ang_rate_z)
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

    def convert_to_raw(self) -> message_IMU_ANGULAR_RATE:
        raw = message_IMU_ANGULAR_RATE()
        raw.ang_rate_x = int16((self.ang_rate_x + 0) * 10.0)
        raw.ang_rate_y = int16((self.ang_rate_y + 0) * 10.0)
        raw.ang_rate_z = int16((self.ang_rate_z + 0) * 10.0)
        return raw

class message_IMU_ACCELERATION:
    def __init__(
        self,
        accel_x = None,
        accel_y = None,
        accel_z = None,
        temperature = None
    ):
        self.accel_x = int16(accel_x)
        self.accel_y = int16(accel_y)
        self.accel_z = int16(accel_z)
        self.temperature = int16(temperature)
        self.size = 8

    def __eq__(self, other):
        if not isinstance(other, message_IMU_ACCELERATION):
            return False
        if self.accel_x != other.accel_x:
            return False
        if self.accel_y != other.accel_y:
            return False
        if self.accel_z != other.accel_z:
            return False
        if self.temperature != other.temperature:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack(">hhhh", self.accel_x, self.accel_y, self.accel_z, self.temperature))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.accel_x = int16(unpack(">h", data[0:2])[0])
        message.accel_y = int16(unpack(">xxh", data[0:4])[0])
        message.accel_z = int16(unpack(">xxxxh", data[0:6])[0])
        message.temperature = int16(unpack(">xxxxxxh", data[0:8])[0])
        return message


    def convert(self) -> message_IMU_ACCELERATION_conversion:
        conversion = message_IMU_ACCELERATION_conversion()
        conversion.accel_x = ((float32(self.accel_x)) / 100.0) + 0
        conversion.accel_y = ((float32(self.accel_y)) / 100.0) + 0
        conversion.accel_z = ((float32(self.accel_z)) / 100.0) + 0
        conversion.temperature = self.temperature
        return conversion


class message_IMU_ACCELERATION_conversion:
    def __init__(
        self,
        accel_x = None,
        accel_y = None,
        accel_z = None,
        temperature = None
    ):
        self.accel_x = float32(accel_x)
        self.accel_y = float32(accel_y)
        self.accel_z = float32(accel_z)
        self.temperature = int16(temperature)
        self.size = 8

    def __eq__(self, other):
        if not isinstance(other, message_IMU_ACCELERATION):
            return False
        if self.accel_x != other.accel_x:
            return False
        if self.accel_y != other.accel_y:
            return False
        if self.accel_z != other.accel_z:
            return False
        if self.temperature != other.temperature:
            return False
        return True

    def convert_to_raw(self) -> message_IMU_ACCELERATION:
        raw = message_IMU_ACCELERATION()
        raw.accel_x = int16((self.accel_x + 0) * 100.0)
        raw.accel_y = int16((self.accel_y + 0) * 100.0)
        raw.accel_z = int16((self.accel_z + 0) * 100.0)
        raw.temperature = self.temperature
        return raw

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
        data.extend(pack(">HHHH", self.channel1, self.channel2, self.channel3, self.channel4))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.channel1 = uint16(unpack(">H", data[0:2])[0])
        message.channel2 = uint16(unpack(">xxH", data[0:4])[0])
        message.channel3 = uint16(unpack(">xxxxH", data[0:6])[0])
        message.channel4 = uint16(unpack(">xxxxxxH", data[0:8])[0])
        return message


    def convert(self) -> message_IRTS_FL_0_conversion:
        conversion = message_IRTS_FL_0_conversion()
        conversion.channel1 = ((float32(self.channel1)) / 10.0) - 100
        conversion.channel2 = ((float32(self.channel2)) / 10.0) - 100
        conversion.channel3 = ((float32(self.channel3)) / 10.0) - 100
        conversion.channel4 = ((float32(self.channel4)) / 10.0) - 100
        return conversion


class message_IRTS_FL_0_conversion:
    def __init__(
        self,
        channel1 = None,
        channel2 = None,
        channel3 = None,
        channel4 = None
    ):
        self.channel1 = float32(channel1)
        self.channel2 = float32(channel2)
        self.channel3 = float32(channel3)
        self.channel4 = float32(channel4)
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

    def convert_to_raw(self) -> message_IRTS_FL_0:
        raw = message_IRTS_FL_0()
        raw.channel1 = uint16((self.channel1 + 100) * 10.0)
        raw.channel2 = uint16((self.channel2 + 100) * 10.0)
        raw.channel3 = uint16((self.channel3 + 100) * 10.0)
        raw.channel4 = uint16((self.channel4 + 100) * 10.0)
        return raw

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
        data.extend(pack(">HHHH", self.channel5, self.channel6, self.channel7, self.channel8))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.channel5 = uint16(unpack(">H", data[0:2])[0])
        message.channel6 = uint16(unpack(">xxH", data[0:4])[0])
        message.channel7 = uint16(unpack(">xxxxH", data[0:6])[0])
        message.channel8 = uint16(unpack(">xxxxxxH", data[0:8])[0])
        return message


    def convert(self) -> message_IRTS_FL_1_conversion:
        conversion = message_IRTS_FL_1_conversion()
        conversion.channel5 = ((float32(self.channel5)) / 10.0) - 100
        conversion.channel6 = ((float32(self.channel6)) / 10.0) - 100
        conversion.channel7 = ((float32(self.channel7)) / 10.0) - 100
        conversion.channel8 = ((float32(self.channel8)) / 10.0) - 100
        return conversion


class message_IRTS_FL_1_conversion:
    def __init__(
        self,
        channel5 = None,
        channel6 = None,
        channel7 = None,
        channel8 = None
    ):
        self.channel5 = float32(channel5)
        self.channel6 = float32(channel6)
        self.channel7 = float32(channel7)
        self.channel8 = float32(channel8)
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

    def convert_to_raw(self) -> message_IRTS_FL_1:
        raw = message_IRTS_FL_1()
        raw.channel5 = uint16((self.channel5 + 100) * 10.0)
        raw.channel6 = uint16((self.channel6 + 100) * 10.0)
        raw.channel7 = uint16((self.channel7 + 100) * 10.0)
        raw.channel8 = uint16((self.channel8 + 100) * 10.0)
        return raw

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
        data.extend(pack(">HHHH", self.channel9, self.channel10, self.channel11, self.channel12))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.channel9 = uint16(unpack(">H", data[0:2])[0])
        message.channel10 = uint16(unpack(">xxH", data[0:4])[0])
        message.channel11 = uint16(unpack(">xxxxH", data[0:6])[0])
        message.channel12 = uint16(unpack(">xxxxxxH", data[0:8])[0])
        return message


    def convert(self) -> message_IRTS_FL_2_conversion:
        conversion = message_IRTS_FL_2_conversion()
        conversion.channel9 = ((float32(self.channel9)) / 10.0) - 100
        conversion.channel10 = ((float32(self.channel10)) / 10.0) - 100
        conversion.channel11 = ((float32(self.channel11)) / 10.0) - 100
        conversion.channel12 = ((float32(self.channel12)) / 10.0) - 100
        return conversion


class message_IRTS_FL_2_conversion:
    def __init__(
        self,
        channel9 = None,
        channel10 = None,
        channel11 = None,
        channel12 = None
    ):
        self.channel9 = float32(channel9)
        self.channel10 = float32(channel10)
        self.channel11 = float32(channel11)
        self.channel12 = float32(channel12)
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

    def convert_to_raw(self) -> message_IRTS_FL_2:
        raw = message_IRTS_FL_2()
        raw.channel9 = uint16((self.channel9 + 100) * 10.0)
        raw.channel10 = uint16((self.channel10 + 100) * 10.0)
        raw.channel11 = uint16((self.channel11 + 100) * 10.0)
        raw.channel12 = uint16((self.channel12 + 100) * 10.0)
        return raw

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
        data.extend(pack(">HHHH", self.channel13, self.channel14, self.channel15, self.channel16))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.channel13 = uint16(unpack(">H", data[0:2])[0])
        message.channel14 = uint16(unpack(">xxH", data[0:4])[0])
        message.channel15 = uint16(unpack(">xxxxH", data[0:6])[0])
        message.channel16 = uint16(unpack(">xxxxxxH", data[0:8])[0])
        return message


    def convert(self) -> message_IRTS_FL_3_conversion:
        conversion = message_IRTS_FL_3_conversion()
        conversion.channel13 = ((float32(self.channel13)) / 10.0) - 100
        conversion.channel14 = ((float32(self.channel14)) / 10.0) - 100
        conversion.channel15 = ((float32(self.channel15)) / 10.0) - 100
        conversion.channel16 = ((float32(self.channel16)) / 10.0) - 100
        return conversion


class message_IRTS_FL_3_conversion:
    def __init__(
        self,
        channel13 = None,
        channel14 = None,
        channel15 = None,
        channel16 = None
    ):
        self.channel13 = float32(channel13)
        self.channel14 = float32(channel14)
        self.channel15 = float32(channel15)
        self.channel16 = float32(channel16)
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

    def convert_to_raw(self) -> message_IRTS_FL_3:
        raw = message_IRTS_FL_3()
        raw.channel13 = uint16((self.channel13 + 100) * 10.0)
        raw.channel14 = uint16((self.channel14 + 100) * 10.0)
        raw.channel15 = uint16((self.channel15 + 100) * 10.0)
        raw.channel16 = uint16((self.channel16 + 100) * 10.0)
        return raw

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
        data.extend(pack(">HHHH", self.channel1, self.channel2, self.channel3, self.channel4))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.channel1 = uint16(unpack(">H", data[0:2])[0])
        message.channel2 = uint16(unpack(">xxH", data[0:4])[0])
        message.channel3 = uint16(unpack(">xxxxH", data[0:6])[0])
        message.channel4 = uint16(unpack(">xxxxxxH", data[0:8])[0])
        return message


    def convert(self) -> message_IRTS_FR_0_conversion:
        conversion = message_IRTS_FR_0_conversion()
        conversion.channel1 = ((float32(self.channel1)) / 10.0) - 100
        conversion.channel2 = ((float32(self.channel2)) / 10.0) - 100
        conversion.channel3 = ((float32(self.channel3)) / 10.0) - 100
        conversion.channel4 = ((float32(self.channel4)) / 10.0) - 100
        return conversion


class message_IRTS_FR_0_conversion:
    def __init__(
        self,
        channel1 = None,
        channel2 = None,
        channel3 = None,
        channel4 = None
    ):
        self.channel1 = float32(channel1)
        self.channel2 = float32(channel2)
        self.channel3 = float32(channel3)
        self.channel4 = float32(channel4)
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

    def convert_to_raw(self) -> message_IRTS_FR_0:
        raw = message_IRTS_FR_0()
        raw.channel1 = uint16((self.channel1 + 100) * 10.0)
        raw.channel2 = uint16((self.channel2 + 100) * 10.0)
        raw.channel3 = uint16((self.channel3 + 100) * 10.0)
        raw.channel4 = uint16((self.channel4 + 100) * 10.0)
        return raw

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
        data.extend(pack(">HHHH", self.channel5, self.channel6, self.channel7, self.channel8))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.channel5 = uint16(unpack(">H", data[0:2])[0])
        message.channel6 = uint16(unpack(">xxH", data[0:4])[0])
        message.channel7 = uint16(unpack(">xxxxH", data[0:6])[0])
        message.channel8 = uint16(unpack(">xxxxxxH", data[0:8])[0])
        return message


    def convert(self) -> message_IRTS_FR_1_conversion:
        conversion = message_IRTS_FR_1_conversion()
        conversion.channel5 = ((float32(self.channel5)) / 10.0) - 100
        conversion.channel6 = ((float32(self.channel6)) / 10.0) - 100
        conversion.channel7 = ((float32(self.channel7)) / 10.0) - 100
        conversion.channel8 = ((float32(self.channel8)) / 10.0) - 100
        return conversion


class message_IRTS_FR_1_conversion:
    def __init__(
        self,
        channel5 = None,
        channel6 = None,
        channel7 = None,
        channel8 = None
    ):
        self.channel5 = float32(channel5)
        self.channel6 = float32(channel6)
        self.channel7 = float32(channel7)
        self.channel8 = float32(channel8)
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

    def convert_to_raw(self) -> message_IRTS_FR_1:
        raw = message_IRTS_FR_1()
        raw.channel5 = uint16((self.channel5 + 100) * 10.0)
        raw.channel6 = uint16((self.channel6 + 100) * 10.0)
        raw.channel7 = uint16((self.channel7 + 100) * 10.0)
        raw.channel8 = uint16((self.channel8 + 100) * 10.0)
        return raw

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
        data.extend(pack(">HHHH", self.channel9, self.channel10, self.channel11, self.channel12))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.channel9 = uint16(unpack(">H", data[0:2])[0])
        message.channel10 = uint16(unpack(">xxH", data[0:4])[0])
        message.channel11 = uint16(unpack(">xxxxH", data[0:6])[0])
        message.channel12 = uint16(unpack(">xxxxxxH", data[0:8])[0])
        return message


    def convert(self) -> message_IRTS_FR_2_conversion:
        conversion = message_IRTS_FR_2_conversion()
        conversion.channel9 = ((float32(self.channel9)) / 10.0) - 100
        conversion.channel10 = ((float32(self.channel10)) / 10.0) - 100
        conversion.channel11 = ((float32(self.channel11)) / 10.0) - 100
        conversion.channel12 = ((float32(self.channel12)) / 10.0) - 100
        return conversion


class message_IRTS_FR_2_conversion:
    def __init__(
        self,
        channel9 = None,
        channel10 = None,
        channel11 = None,
        channel12 = None
    ):
        self.channel9 = float32(channel9)
        self.channel10 = float32(channel10)
        self.channel11 = float32(channel11)
        self.channel12 = float32(channel12)
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

    def convert_to_raw(self) -> message_IRTS_FR_2:
        raw = message_IRTS_FR_2()
        raw.channel9 = uint16((self.channel9 + 100) * 10.0)
        raw.channel10 = uint16((self.channel10 + 100) * 10.0)
        raw.channel11 = uint16((self.channel11 + 100) * 10.0)
        raw.channel12 = uint16((self.channel12 + 100) * 10.0)
        return raw

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
        data.extend(pack(">HHHH", self.channel13, self.channel14, self.channel15, self.channel16))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.channel13 = uint16(unpack(">H", data[0:2])[0])
        message.channel14 = uint16(unpack(">xxH", data[0:4])[0])
        message.channel15 = uint16(unpack(">xxxxH", data[0:6])[0])
        message.channel16 = uint16(unpack(">xxxxxxH", data[0:8])[0])
        return message


    def convert(self) -> message_IRTS_FR_3_conversion:
        conversion = message_IRTS_FR_3_conversion()
        conversion.channel13 = ((float32(self.channel13)) / 10.0) - 100
        conversion.channel14 = ((float32(self.channel14)) / 10.0) - 100
        conversion.channel15 = ((float32(self.channel15)) / 10.0) - 100
        conversion.channel16 = ((float32(self.channel16)) / 10.0) - 100
        return conversion


class message_IRTS_FR_3_conversion:
    def __init__(
        self,
        channel13 = None,
        channel14 = None,
        channel15 = None,
        channel16 = None
    ):
        self.channel13 = float32(channel13)
        self.channel14 = float32(channel14)
        self.channel15 = float32(channel15)
        self.channel16 = float32(channel16)
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

    def convert_to_raw(self) -> message_IRTS_FR_3:
        raw = message_IRTS_FR_3()
        raw.channel13 = uint16((self.channel13 + 100) * 10.0)
        raw.channel14 = uint16((self.channel14 + 100) * 10.0)
        raw.channel15 = uint16((self.channel15 + 100) * 10.0)
        raw.channel16 = uint16((self.channel16 + 100) * 10.0)
        return raw

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
        data.extend(pack(">HHHH", self.channel1, self.channel2, self.channel3, self.channel4))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.channel1 = uint16(unpack(">H", data[0:2])[0])
        message.channel2 = uint16(unpack(">xxH", data[0:4])[0])
        message.channel3 = uint16(unpack(">xxxxH", data[0:6])[0])
        message.channel4 = uint16(unpack(">xxxxxxH", data[0:8])[0])
        return message


    def convert(self) -> message_IRTS_RL_0_conversion:
        conversion = message_IRTS_RL_0_conversion()
        conversion.channel1 = ((float32(self.channel1)) / 10.0) - 100
        conversion.channel2 = ((float32(self.channel2)) / 10.0) - 100
        conversion.channel3 = ((float32(self.channel3)) / 10.0) - 100
        conversion.channel4 = ((float32(self.channel4)) / 10.0) - 100
        return conversion


class message_IRTS_RL_0_conversion:
    def __init__(
        self,
        channel1 = None,
        channel2 = None,
        channel3 = None,
        channel4 = None
    ):
        self.channel1 = float32(channel1)
        self.channel2 = float32(channel2)
        self.channel3 = float32(channel3)
        self.channel4 = float32(channel4)
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

    def convert_to_raw(self) -> message_IRTS_RL_0:
        raw = message_IRTS_RL_0()
        raw.channel1 = uint16((self.channel1 + 100) * 10.0)
        raw.channel2 = uint16((self.channel2 + 100) * 10.0)
        raw.channel3 = uint16((self.channel3 + 100) * 10.0)
        raw.channel4 = uint16((self.channel4 + 100) * 10.0)
        return raw

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
        data.extend(pack(">HHHH", self.channel5, self.channel6, self.channel7, self.channel8))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.channel5 = uint16(unpack(">H", data[0:2])[0])
        message.channel6 = uint16(unpack(">xxH", data[0:4])[0])
        message.channel7 = uint16(unpack(">xxxxH", data[0:6])[0])
        message.channel8 = uint16(unpack(">xxxxxxH", data[0:8])[0])
        return message


    def convert(self) -> message_IRTS_RL_1_conversion:
        conversion = message_IRTS_RL_1_conversion()
        conversion.channel5 = ((float32(self.channel5)) / 10.0) - 100
        conversion.channel6 = ((float32(self.channel6)) / 10.0) - 100
        conversion.channel7 = ((float32(self.channel7)) / 10.0) - 100
        conversion.channel8 = ((float32(self.channel8)) / 10.0) - 100
        return conversion


class message_IRTS_RL_1_conversion:
    def __init__(
        self,
        channel5 = None,
        channel6 = None,
        channel7 = None,
        channel8 = None
    ):
        self.channel5 = float32(channel5)
        self.channel6 = float32(channel6)
        self.channel7 = float32(channel7)
        self.channel8 = float32(channel8)
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

    def convert_to_raw(self) -> message_IRTS_RL_1:
        raw = message_IRTS_RL_1()
        raw.channel5 = uint16((self.channel5 + 100) * 10.0)
        raw.channel6 = uint16((self.channel6 + 100) * 10.0)
        raw.channel7 = uint16((self.channel7 + 100) * 10.0)
        raw.channel8 = uint16((self.channel8 + 100) * 10.0)
        return raw

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
        data.extend(pack(">HHHH", self.channel9, self.channel10, self.channel11, self.channel12))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.channel9 = uint16(unpack(">H", data[0:2])[0])
        message.channel10 = uint16(unpack(">xxH", data[0:4])[0])
        message.channel11 = uint16(unpack(">xxxxH", data[0:6])[0])
        message.channel12 = uint16(unpack(">xxxxxxH", data[0:8])[0])
        return message


    def convert(self) -> message_IRTS_RL_2_conversion:
        conversion = message_IRTS_RL_2_conversion()
        conversion.channel9 = ((float32(self.channel9)) / 10.0) - 100
        conversion.channel10 = ((float32(self.channel10)) / 10.0) - 100
        conversion.channel11 = ((float32(self.channel11)) / 10.0) - 100
        conversion.channel12 = ((float32(self.channel12)) / 10.0) - 100
        return conversion


class message_IRTS_RL_2_conversion:
    def __init__(
        self,
        channel9 = None,
        channel10 = None,
        channel11 = None,
        channel12 = None
    ):
        self.channel9 = float32(channel9)
        self.channel10 = float32(channel10)
        self.channel11 = float32(channel11)
        self.channel12 = float32(channel12)
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

    def convert_to_raw(self) -> message_IRTS_RL_2:
        raw = message_IRTS_RL_2()
        raw.channel9 = uint16((self.channel9 + 100) * 10.0)
        raw.channel10 = uint16((self.channel10 + 100) * 10.0)
        raw.channel11 = uint16((self.channel11 + 100) * 10.0)
        raw.channel12 = uint16((self.channel12 + 100) * 10.0)
        return raw

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
        data.extend(pack(">HHHH", self.channel13, self.channel14, self.channel15, self.channel16))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.channel13 = uint16(unpack(">H", data[0:2])[0])
        message.channel14 = uint16(unpack(">xxH", data[0:4])[0])
        message.channel15 = uint16(unpack(">xxxxH", data[0:6])[0])
        message.channel16 = uint16(unpack(">xxxxxxH", data[0:8])[0])
        return message


    def convert(self) -> message_IRTS_RL_3_conversion:
        conversion = message_IRTS_RL_3_conversion()
        conversion.channel13 = ((float32(self.channel13)) / 10.0) - 100
        conversion.channel14 = ((float32(self.channel14)) / 10.0) - 100
        conversion.channel15 = ((float32(self.channel15)) / 10.0) - 100
        conversion.channel16 = ((float32(self.channel16)) / 10.0) - 100
        return conversion


class message_IRTS_RL_3_conversion:
    def __init__(
        self,
        channel13 = None,
        channel14 = None,
        channel15 = None,
        channel16 = None
    ):
        self.channel13 = float32(channel13)
        self.channel14 = float32(channel14)
        self.channel15 = float32(channel15)
        self.channel16 = float32(channel16)
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

    def convert_to_raw(self) -> message_IRTS_RL_3:
        raw = message_IRTS_RL_3()
        raw.channel13 = uint16((self.channel13 + 100) * 10.0)
        raw.channel14 = uint16((self.channel14 + 100) * 10.0)
        raw.channel15 = uint16((self.channel15 + 100) * 10.0)
        raw.channel16 = uint16((self.channel16 + 100) * 10.0)
        return raw

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
        data.extend(pack(">HHHH", self.channel1, self.channel2, self.channel3, self.channel4))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.channel1 = uint16(unpack(">H", data[0:2])[0])
        message.channel2 = uint16(unpack(">xxH", data[0:4])[0])
        message.channel3 = uint16(unpack(">xxxxH", data[0:6])[0])
        message.channel4 = uint16(unpack(">xxxxxxH", data[0:8])[0])
        return message


    def convert(self) -> message_IRTS_RR_0_conversion:
        conversion = message_IRTS_RR_0_conversion()
        conversion.channel1 = ((float32(self.channel1)) / 10.0) - 100
        conversion.channel2 = ((float32(self.channel2)) / 10.0) - 100
        conversion.channel3 = ((float32(self.channel3)) / 10.0) - 100
        conversion.channel4 = ((float32(self.channel4)) / 10.0) - 100
        return conversion


class message_IRTS_RR_0_conversion:
    def __init__(
        self,
        channel1 = None,
        channel2 = None,
        channel3 = None,
        channel4 = None
    ):
        self.channel1 = float32(channel1)
        self.channel2 = float32(channel2)
        self.channel3 = float32(channel3)
        self.channel4 = float32(channel4)
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

    def convert_to_raw(self) -> message_IRTS_RR_0:
        raw = message_IRTS_RR_0()
        raw.channel1 = uint16((self.channel1 + 100) * 10.0)
        raw.channel2 = uint16((self.channel2 + 100) * 10.0)
        raw.channel3 = uint16((self.channel3 + 100) * 10.0)
        raw.channel4 = uint16((self.channel4 + 100) * 10.0)
        return raw

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
        data.extend(pack(">HHHH", self.channel5, self.channel6, self.channel7, self.channel8))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.channel5 = uint16(unpack(">H", data[0:2])[0])
        message.channel6 = uint16(unpack(">xxH", data[0:4])[0])
        message.channel7 = uint16(unpack(">xxxxH", data[0:6])[0])
        message.channel8 = uint16(unpack(">xxxxxxH", data[0:8])[0])
        return message


    def convert(self) -> message_IRTS_RR_1_conversion:
        conversion = message_IRTS_RR_1_conversion()
        conversion.channel5 = ((float32(self.channel5)) / 10.0) - 100
        conversion.channel6 = ((float32(self.channel6)) / 10.0) - 100
        conversion.channel7 = ((float32(self.channel7)) / 10.0) - 100
        conversion.channel8 = ((float32(self.channel8)) / 10.0) - 100
        return conversion


class message_IRTS_RR_1_conversion:
    def __init__(
        self,
        channel5 = None,
        channel6 = None,
        channel7 = None,
        channel8 = None
    ):
        self.channel5 = float32(channel5)
        self.channel6 = float32(channel6)
        self.channel7 = float32(channel7)
        self.channel8 = float32(channel8)
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

    def convert_to_raw(self) -> message_IRTS_RR_1:
        raw = message_IRTS_RR_1()
        raw.channel5 = uint16((self.channel5 + 100) * 10.0)
        raw.channel6 = uint16((self.channel6 + 100) * 10.0)
        raw.channel7 = uint16((self.channel7 + 100) * 10.0)
        raw.channel8 = uint16((self.channel8 + 100) * 10.0)
        return raw

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
        data.extend(pack(">HHHH", self.channel9, self.channel10, self.channel11, self.channel12))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.channel9 = uint16(unpack(">H", data[0:2])[0])
        message.channel10 = uint16(unpack(">xxH", data[0:4])[0])
        message.channel11 = uint16(unpack(">xxxxH", data[0:6])[0])
        message.channel12 = uint16(unpack(">xxxxxxH", data[0:8])[0])
        return message


    def convert(self) -> message_IRTS_RR_2_conversion:
        conversion = message_IRTS_RR_2_conversion()
        conversion.channel9 = ((float32(self.channel9)) / 10.0) - 100
        conversion.channel10 = ((float32(self.channel10)) / 10.0) - 100
        conversion.channel11 = ((float32(self.channel11)) / 10.0) - 100
        conversion.channel12 = ((float32(self.channel12)) / 10.0) - 100
        return conversion


class message_IRTS_RR_2_conversion:
    def __init__(
        self,
        channel9 = None,
        channel10 = None,
        channel11 = None,
        channel12 = None
    ):
        self.channel9 = float32(channel9)
        self.channel10 = float32(channel10)
        self.channel11 = float32(channel11)
        self.channel12 = float32(channel12)
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

    def convert_to_raw(self) -> message_IRTS_RR_2:
        raw = message_IRTS_RR_2()
        raw.channel9 = uint16((self.channel9 + 100) * 10.0)
        raw.channel10 = uint16((self.channel10 + 100) * 10.0)
        raw.channel11 = uint16((self.channel11 + 100) * 10.0)
        raw.channel12 = uint16((self.channel12 + 100) * 10.0)
        return raw

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
        data.extend(pack(">HHHH", self.channel13, self.channel14, self.channel15, self.channel16))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.channel13 = uint16(unpack(">H", data[0:2])[0])
        message.channel14 = uint16(unpack(">xxH", data[0:4])[0])
        message.channel15 = uint16(unpack(">xxxxH", data[0:6])[0])
        message.channel16 = uint16(unpack(">xxxxxxH", data[0:8])[0])
        return message


    def convert(self) -> message_IRTS_RR_3_conversion:
        conversion = message_IRTS_RR_3_conversion()
        conversion.channel13 = ((float32(self.channel13)) / 10.0) - 100
        conversion.channel14 = ((float32(self.channel14)) / 10.0) - 100
        conversion.channel15 = ((float32(self.channel15)) / 10.0) - 100
        conversion.channel16 = ((float32(self.channel16)) / 10.0) - 100
        return conversion


class message_IRTS_RR_3_conversion:
    def __init__(
        self,
        channel13 = None,
        channel14 = None,
        channel15 = None,
        channel16 = None
    ):
        self.channel13 = float32(channel13)
        self.channel14 = float32(channel14)
        self.channel15 = float32(channel15)
        self.channel16 = float32(channel16)
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

    def convert_to_raw(self) -> message_IRTS_RR_3:
        raw = message_IRTS_RR_3()
        raw.channel13 = uint16((self.channel13 + 100) * 10.0)
        raw.channel14 = uint16((self.channel14 + 100) * 10.0)
        raw.channel15 = uint16((self.channel15 + 100) * 10.0)
        raw.channel16 = uint16((self.channel16 + 100) * 10.0)
        return raw

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
        lap_count = None,
        lap_time = None
    ):
        self.lap_count = uint8(lap_count)
        self.lap_time = uint32(lap_time)
        self.size = 5

    def __eq__(self, other):
        if not isinstance(other, message_LAP_COUNT):
            return False
        if self.lap_count != other.lap_count:
            return False
        if self.lap_time != other.lap_time:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<IB", self.lap_time, self.lap_count))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.lap_count = uint8(unpack("<xxxxB", data[0:5])[0])
        message.lap_time = uint32(unpack("<I", data[0:4])[0])
        return message


class message_PEDALS_OUTPUT:
    def __init__(
        self,
        apps = None,
        bse_front = None,
        bse_rear = None
    ):
        self.apps = uint8(apps)
        self.bse_front = uint16(bse_front)
        self.bse_rear = uint16(bse_rear)
        self.size = 5
        self.interval = 10

    def __eq__(self, other):
        if not isinstance(other, message_PEDALS_OUTPUT):
            return False
        if self.apps != other.apps:
            return False
        if self.bse_front != other.bse_front:
            return False
        if self.bse_rear != other.bse_rear:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<HHB", self.bse_front, self.bse_rear, self.apps))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.apps = uint8(unpack("<xxxxB", data[0:5])[0])
        message.bse_front = uint16(unpack("<H", data[0:2])[0])
        message.bse_rear = uint16(unpack("<xxH", data[0:4])[0])
        return message


    def convert(self) -> message_PEDALS_OUTPUT_conversion:
        conversion = message_PEDALS_OUTPUT_conversion()
        conversion.apps = self.apps
        conversion.bse_front = ((float32(self.bse_front)) / 655.35) + 0
        conversion.bse_rear = ((float32(self.bse_rear)) / 655.35) + 0
        return conversion


class message_PEDALS_OUTPUT_conversion:
    def __init__(
        self,
        apps = None,
        bse_front = None,
        bse_rear = None
    ):
        self.apps = uint8(apps)
        self.bse_front = float32(bse_front)
        self.bse_rear = float32(bse_rear)
        self.size = 5
        self.interval = 10

    def __eq__(self, other):
        if not isinstance(other, message_PEDALS_OUTPUT):
            return False
        if self.apps != other.apps:
            return False
        if self.bse_front != other.bse_front:
            return False
        if self.bse_rear != other.bse_rear:
            return False
        return True

    def convert_to_raw(self) -> message_PEDALS_OUTPUT:
        raw = message_PEDALS_OUTPUT()
        raw.apps = self.apps
        raw.bse_front = uint16((self.bse_front + 0) * 655.35)
        raw.bse_rear = uint16((self.bse_rear + 0) * 655.35)
        return raw

class message_STEERING_ANGLE:
    def __init__(
        self,
        angle = None
    ):
        self.angle = float32(angle)
        self.size = 4
        self.interval = 10

    def __eq__(self, other):
        if not isinstance(other, message_STEERING_ANGLE):
            return False
        if self.angle != other.angle:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<f", self.angle))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.angle = float32(unpack("<f", data[0:4])[0])
        return message


class message_CONTROL_STATE:
    def __init__(
        self,
        map_pw = None,
        map_sc = None,
        map_tv = None
    ):
        self.map_pw = uint8(map_pw)
        self.map_sc = uint8(map_sc)
        self.map_tv = uint8(map_tv)
        self.size = 3
        self.interval = 100

    def __eq__(self, other):
        if not isinstance(other, message_CONTROL_STATE):
            return False
        if self.map_pw != other.map_pw:
            return False
        if self.map_sc != other.map_sc:
            return False
        if self.map_tv != other.map_tv:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<BBB", self.map_pw, self.map_sc, self.map_tv))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.map_pw = uint8(unpack("<B", data[0:1])[0])
        message.map_sc = uint8(unpack("<xB", data[0:2])[0])
        message.map_tv = uint8(unpack("<xxB", data[0:3])[0])
        return message


    def convert(self) -> message_CONTROL_STATE_conversion:
        conversion = message_CONTROL_STATE_conversion()
        conversion.map_pw = ((float32(self.map_pw)) / 10.0) - 0.5
        conversion.map_sc = ((float32(self.map_sc)) / 10.0) + 0
        conversion.map_tv = ((float32(self.map_tv)) / 10.0) + 0
        return conversion


class message_CONTROL_STATE_conversion:
    def __init__(
        self,
        map_pw = None,
        map_sc = None,
        map_tv = None
    ):
        self.map_pw = float32(map_pw)
        self.map_sc = float32(map_sc)
        self.map_tv = float32(map_tv)
        self.size = 3
        self.interval = 100

    def __eq__(self, other):
        if not isinstance(other, message_CONTROL_STATE):
            return False
        if self.map_pw != other.map_pw:
            return False
        if self.map_sc != other.map_sc:
            return False
        if self.map_tv != other.map_tv:
            return False
        return True

    def convert_to_raw(self) -> message_CONTROL_STATE:
        raw = message_CONTROL_STATE()
        raw.map_pw = uint8((self.map_pw + 0.5) * 10.0)
        raw.map_sc = uint8((self.map_sc + 0) * 10.0)
        raw.map_tv = uint8((self.map_tv + 0) * 10.0)
        return raw

class message_TPMS:
    def __init__(
        self,
        fl_pressure = None,
        fr_pressure = None,
        rl_pressure = None,
        rr_pressure = None,
        fl_temperature = None,
        fr_temperature = None,
        rl_temperature = None,
        rr_temperature = None
    ):
        self.fl_pressure = uint8(fl_pressure)
        self.fr_pressure = uint8(fr_pressure)
        self.rl_pressure = uint8(rl_pressure)
        self.rr_pressure = uint8(rr_pressure)
        self.fl_temperature = uint8(fl_temperature)
        self.fr_temperature = uint8(fr_temperature)
        self.rl_temperature = uint8(rl_temperature)
        self.rr_temperature = uint8(rr_temperature)
        self.size = 8

    def __eq__(self, other):
        if not isinstance(other, message_TPMS):
            return False
        if self.fl_pressure != other.fl_pressure:
            return False
        if self.fr_pressure != other.fr_pressure:
            return False
        if self.rl_pressure != other.rl_pressure:
            return False
        if self.rr_pressure != other.rr_pressure:
            return False
        if self.fl_temperature != other.fl_temperature:
            return False
        if self.fr_temperature != other.fr_temperature:
            return False
        if self.rl_temperature != other.rl_temperature:
            return False
        if self.rr_temperature != other.rr_temperature:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<BBBBBBBB", self.fl_pressure, self.fr_pressure, self.rl_pressure, self.rr_pressure, self.fl_temperature, self.fr_temperature, self.rl_temperature, self.rr_temperature))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.fl_pressure = uint8(unpack("<B", data[0:1])[0])
        message.fr_pressure = uint8(unpack("<xB", data[0:2])[0])
        message.rl_pressure = uint8(unpack("<xxB", data[0:3])[0])
        message.rr_pressure = uint8(unpack("<xxxB", data[0:4])[0])
        message.fl_temperature = uint8(unpack("<xxxxB", data[0:5])[0])
        message.fr_temperature = uint8(unpack("<xxxxxB", data[0:6])[0])
        message.rl_temperature = uint8(unpack("<xxxxxxB", data[0:7])[0])
        message.rr_temperature = uint8(unpack("<xxxxxxxB", data[0:8])[0])
        return message


    def convert(self) -> message_TPMS_conversion:
        conversion = message_TPMS_conversion()
        conversion.fl_pressure = ((float32(self.fl_pressure)) / 10.0) + 0
        conversion.fr_pressure = ((float32(self.fr_pressure)) / 10.0) + 0
        conversion.rl_pressure = ((float32(self.rl_pressure)) / 10.0) + 0
        conversion.rr_pressure = ((float32(self.rr_pressure)) / 10.0) + 0
        conversion.fl_temperature = self.fl_temperature
        conversion.fr_temperature = self.fr_temperature
        conversion.rl_temperature = self.rl_temperature
        conversion.rr_temperature = self.rr_temperature
        return conversion


class message_TPMS_conversion:
    def __init__(
        self,
        fl_pressure = None,
        fr_pressure = None,
        rl_pressure = None,
        rr_pressure = None,
        fl_temperature = None,
        fr_temperature = None,
        rl_temperature = None,
        rr_temperature = None
    ):
        self.fl_pressure = float32(fl_pressure)
        self.fr_pressure = float32(fr_pressure)
        self.rl_pressure = float32(rl_pressure)
        self.rr_pressure = float32(rr_pressure)
        self.fl_temperature = uint8(fl_temperature)
        self.fr_temperature = uint8(fr_temperature)
        self.rl_temperature = uint8(rl_temperature)
        self.rr_temperature = uint8(rr_temperature)
        self.size = 8

    def __eq__(self, other):
        if not isinstance(other, message_TPMS):
            return False
        if self.fl_pressure != other.fl_pressure:
            return False
        if self.fr_pressure != other.fr_pressure:
            return False
        if self.rl_pressure != other.rl_pressure:
            return False
        if self.rr_pressure != other.rr_pressure:
            return False
        if self.fl_temperature != other.fl_temperature:
            return False
        if self.fr_temperature != other.fr_temperature:
            return False
        if self.rl_temperature != other.rl_temperature:
            return False
        if self.rr_temperature != other.rr_temperature:
            return False
        return True

    def convert_to_raw(self) -> message_TPMS:
        raw = message_TPMS()
        raw.fl_pressure = uint8((self.fl_pressure + 0) * 10.0)
        raw.fr_pressure = uint8((self.fr_pressure + 0) * 10.0)
        raw.rl_pressure = uint8((self.rl_pressure + 0) * 10.0)
        raw.rr_pressure = uint8((self.rr_pressure + 0) * 10.0)
        raw.fl_temperature = self.fl_temperature
        raw.fr_temperature = self.fr_temperature
        raw.rl_temperature = self.rl_temperature
        raw.rr_temperature = self.rr_temperature
        return raw

class message_LC_STATUS:
    def __init__(
        self,
        last_time = None,
        lap_number = None
    ):
        self.last_time = uint32(last_time)
        self.lap_number = int16(lap_number)
        self.size = 6

    def __eq__(self, other):
        if not isinstance(other, message_LC_STATUS):
            return False
        if self.last_time != other.last_time:
            return False
        if self.lap_number != other.lap_number:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<Ih", self.last_time, self.lap_number))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.last_time = uint32(unpack("<I", data[0:4])[0])
        message.lap_number = int16(unpack("<xxxxh", data[0:6])[0])
        return message

