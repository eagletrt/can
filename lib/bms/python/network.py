from __future__ import annotations
from enum import IntEnum, IntFlag
from struct import pack, unpack
from typing import Any, Optional
from builtins import bool as Bool

CANLIB_BUILD_TIME = 1657221636
CANLIB_BUILD_HASH = 0xd031e1c5

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


class Errors(IntFlag):
    CAN_COMM = 1
    LTC_COMM = 2
    TEMP_COMM_0 = 4
    TEMP_COMM_1 = 8
    TEMP_COMM_2 = 16
    TEMP_COMM_3 = 32
    TEMP_COMM_4 = 64
    TEMP_COMM_5 = 128
    OPEN_WIRE = 256

    @classmethod
    def _missing_(cls, value):
        if value is None:
            return cls(0)
        return super(IntFlag, cls)._missing_(value)


class BalancingCells(IntFlag):
    CELL0 = 1
    CELL1 = 2
    CELL2 = 4
    CELL3 = 8
    CELL4 = 16
    CELL5 = 32
    CELL6 = 64
    CELL7 = 128
    CELL8 = 256
    CELL9 = 512
    CELL10 = 1024
    CELL11 = 2048
    CELL12 = 4096
    CELL13 = 8192
    CELL14 = 16384
    CELL15 = 32768
    CELL16 = 65536
    CELL17 = 131072

    @classmethod
    def _missing_(cls, value):
        if value is None:
            return cls(0)
        return super(IntFlag, cls)._missing_(value)

# Enums


class BalancingStatus(IntEnum):
    OFF = 0
    DISCHARGE = 1

    @classmethod
    def _missing_(cls, _):
        return cls(0)

# Messages


class message_BOARD_STATUS:
    def __init__(
        self,
        errors = None,
        balancing_status = None
    ):
        self.errors = Errors(errors)
        self.balancing_status = BalancingStatus(balancing_status)
        self.size = 3

    def __eq__(self, other):
        if not isinstance(other, message_BOARD_STATUS):
            return False
        if self.errors != other.errors:
            return False
        if self.balancing_status != other.balancing_status:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<BBB", (int(self.errors) >> 8) & 255, (int(self.errors) >> 0) & 255, self.balancing_status << 7 & 255))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.errors = Errors(int((unpack("<BB", data[0:2])[0] << 8) | (unpack("<BB", data[0:2])[1] << 0)))
        message.balancing_status = BalancingStatus((unpack("<xxB", data[0:3])[0] & 128) >> 7)
        return message


class message_TEMPERATURES:
    def __init__(
        self,
        start_index = None,
        temp0 = None,
        temp1 = None,
        temp2 = None,
        temp3 = None,
        temp4 = None,
        temp5 = None
    ):
        self.start_index = uint8(start_index)
        self.temp0 = uint8(temp0)
        self.temp1 = uint8(temp1)
        self.temp2 = uint8(temp2)
        self.temp3 = uint8(temp3)
        self.temp4 = uint8(temp4)
        self.temp5 = uint8(temp5)
        self.size = 7

    def __eq__(self, other):
        if not isinstance(other, message_TEMPERATURES):
            return False
        if self.start_index != other.start_index:
            return False
        if self.temp0 != other.temp0:
            return False
        if self.temp1 != other.temp1:
            return False
        if self.temp2 != other.temp2:
            return False
        if self.temp3 != other.temp3:
            return False
        if self.temp4 != other.temp4:
            return False
        if self.temp5 != other.temp5:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<BBBBBBB", self.start_index, self.temp0, self.temp1, self.temp2, self.temp3, self.temp4, self.temp5))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.start_index = uint8(unpack("<B", data[0:1])[0])
        message.temp0 = uint8(unpack("<xB", data[0:2])[0])
        message.temp1 = uint8(unpack("<xxB", data[0:3])[0])
        message.temp2 = uint8(unpack("<xxxB", data[0:4])[0])
        message.temp3 = uint8(unpack("<xxxxB", data[0:5])[0])
        message.temp4 = uint8(unpack("<xxxxxB", data[0:6])[0])
        message.temp5 = uint8(unpack("<xxxxxxB", data[0:7])[0])
        return message


    def convert(self) -> message_TEMPERATURES_conversion:
        conversion = message_TEMPERATURES_conversion()
        conversion.start_index = self.start_index
        conversion.temp0 = ((float32(self.temp0)) / 2.56) - 20
        conversion.temp1 = ((float32(self.temp1)) / 2.56) - 20
        conversion.temp2 = ((float32(self.temp2)) / 2.56) - 20
        conversion.temp3 = ((float32(self.temp3)) / 2.56) - 20
        conversion.temp4 = ((float32(self.temp4)) / 2.56) - 20
        conversion.temp5 = ((float32(self.temp5)) / 2.56) - 20
        return conversion


class message_TEMPERATURES_conversion:
    def __init__(
        self,
        start_index = None,
        temp0 = None,
        temp1 = None,
        temp2 = None,
        temp3 = None,
        temp4 = None,
        temp5 = None
    ):
        self.start_index = uint8(start_index)
        self.temp0 = float32(temp0)
        self.temp1 = float32(temp1)
        self.temp2 = float32(temp2)
        self.temp3 = float32(temp3)
        self.temp4 = float32(temp4)
        self.temp5 = float32(temp5)
        self.size = 7

    def __eq__(self, other):
        if not isinstance(other, message_TEMPERATURES):
            return False
        if self.start_index != other.start_index:
            return False
        if self.temp0 != other.temp0:
            return False
        if self.temp1 != other.temp1:
            return False
        if self.temp2 != other.temp2:
            return False
        if self.temp3 != other.temp3:
            return False
        if self.temp4 != other.temp4:
            return False
        if self.temp5 != other.temp5:
            return False
        return True

    def convert_to_raw(self) -> message_TEMPERATURES:
        raw = message_TEMPERATURES()
        raw.start_index = self.start_index
        raw.temp0 = uint8((self.temp0 + 20) * 2.56)
        raw.temp1 = uint8((self.temp1 + 20) * 2.56)
        raw.temp2 = uint8((self.temp2 + 20) * 2.56)
        raw.temp3 = uint8((self.temp3 + 20) * 2.56)
        raw.temp4 = uint8((self.temp4 + 20) * 2.56)
        raw.temp5 = uint8((self.temp5 + 20) * 2.56)
        return raw

class message_VOLTAGES:
    def __init__(
        self,
        start_index = None,
        voltage0 = None,
        voltage1 = None,
        voltage2 = None
    ):
        self.start_index = uint8(start_index)
        self.voltage0 = uint16(voltage0)
        self.voltage1 = uint16(voltage1)
        self.voltage2 = uint16(voltage2)
        self.size = 7

    def __eq__(self, other):
        if not isinstance(other, message_VOLTAGES):
            return False
        if self.start_index != other.start_index:
            return False
        if self.voltage0 != other.voltage0:
            return False
        if self.voltage1 != other.voltage1:
            return False
        if self.voltage2 != other.voltage2:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<HHHB", self.voltage0, self.voltage1, self.voltage2, self.start_index))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.start_index = uint8(unpack("<xxxxxxB", data[0:7])[0])
        message.voltage0 = uint16(unpack("<H", data[0:2])[0])
        message.voltage1 = uint16(unpack("<xxH", data[0:4])[0])
        message.voltage2 = uint16(unpack("<xxxxH", data[0:6])[0])
        return message


    def convert(self) -> message_VOLTAGES_conversion:
        conversion = message_VOLTAGES_conversion()
        conversion.start_index = self.start_index
        conversion.voltage0 = ((float32(self.voltage0)) / 10000.0) + 0
        conversion.voltage1 = ((float32(self.voltage1)) / 10000.0) + 0
        conversion.voltage2 = ((float32(self.voltage2)) / 10000.0) + 0
        return conversion


class message_VOLTAGES_conversion:
    def __init__(
        self,
        start_index = None,
        voltage0 = None,
        voltage1 = None,
        voltage2 = None
    ):
        self.start_index = uint8(start_index)
        self.voltage0 = float32(voltage0)
        self.voltage1 = float32(voltage1)
        self.voltage2 = float32(voltage2)
        self.size = 7

    def __eq__(self, other):
        if not isinstance(other, message_VOLTAGES):
            return False
        if self.start_index != other.start_index:
            return False
        if self.voltage0 != other.voltage0:
            return False
        if self.voltage1 != other.voltage1:
            return False
        if self.voltage2 != other.voltage2:
            return False
        return True

    def convert_to_raw(self) -> message_VOLTAGES:
        raw = message_VOLTAGES()
        raw.start_index = self.start_index
        raw.voltage0 = uint16((self.voltage0 + 0) * 10000.0)
        raw.voltage1 = uint16((self.voltage1 + 0) * 10000.0)
        raw.voltage2 = uint16((self.voltage2 + 0) * 10000.0)
        return raw

class message_BALANCING:
    def __init__(
        self,
        board_index = None,
        cells = None
    ):
        self.board_index = uint8(board_index)
        self.cells = BalancingCells(cells)
        self.size = 4

    def __eq__(self, other):
        if not isinstance(other, message_BALANCING):
            return False
        if self.board_index != other.board_index:
            return False
        if self.cells != other.cells:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<BBBB", (int(self.cells) >> 16) & 255, (int(self.cells) >> 8) & 255, (int(self.cells) >> 0) & 255, self.board_index))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.board_index = uint8(unpack("<xxxB", data[0:4])[0])
        message.cells = BalancingCells(int((unpack("<BBB", data[0:3])[0] << 16) | (unpack("<BBB", data[0:3])[1] << 8) | (unpack("<BBB", data[0:3])[2] << 0)))
        return message


class message_FW_UPDATE:
    def __init__(
        self,
        board_index = None
    ):
        self.board_index = uint8(board_index)
        self.size = 1

    def __eq__(self, other):
        if not isinstance(other, message_FW_UPDATE):
            return False
        if self.board_index != other.board_index:
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend(pack("<B", self.board_index))
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        message.board_index = uint8(unpack("<B", data[0:1])[0])
        return message


class message_FLASH_CELLBOARD_0_TX:
    def __init__(
        self
    ):
        self.size = 0

    def __eq__(self, other):
        if not isinstance(other, message_FLASH_CELLBOARD_0_TX):
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend()
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        return message


class message_FLASH_CELLBOARD_0_RX:
    def __init__(
        self
    ):
        self.size = 0

    def __eq__(self, other):
        if not isinstance(other, message_FLASH_CELLBOARD_0_RX):
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend()
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        return message


class message_FLASH_CELLBOARD_1_TX:
    def __init__(
        self
    ):
        self.size = 0

    def __eq__(self, other):
        if not isinstance(other, message_FLASH_CELLBOARD_1_TX):
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend()
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        return message


class message_FLASH_CELLBOARD_1_RX:
    def __init__(
        self
    ):
        self.size = 0

    def __eq__(self, other):
        if not isinstance(other, message_FLASH_CELLBOARD_1_RX):
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend()
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        return message


class message_FLASH_CELLBOARD_2_TX:
    def __init__(
        self
    ):
        self.size = 0

    def __eq__(self, other):
        if not isinstance(other, message_FLASH_CELLBOARD_2_TX):
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend()
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        return message


class message_FLASH_CELLBOARD_2_RX:
    def __init__(
        self
    ):
        self.size = 0

    def __eq__(self, other):
        if not isinstance(other, message_FLASH_CELLBOARD_2_RX):
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend()
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        return message


class message_FLASH_CELLBOARD_3_TX:
    def __init__(
        self
    ):
        self.size = 0

    def __eq__(self, other):
        if not isinstance(other, message_FLASH_CELLBOARD_3_TX):
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend()
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        return message


class message_FLASH_CELLBOARD_3_RX:
    def __init__(
        self
    ):
        self.size = 0

    def __eq__(self, other):
        if not isinstance(other, message_FLASH_CELLBOARD_3_RX):
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend()
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        return message


class message_FLASH_CELLBOARD_4_TX:
    def __init__(
        self
    ):
        self.size = 0

    def __eq__(self, other):
        if not isinstance(other, message_FLASH_CELLBOARD_4_TX):
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend()
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        return message


class message_FLASH_CELLBOARD_4_RX:
    def __init__(
        self
    ):
        self.size = 0

    def __eq__(self, other):
        if not isinstance(other, message_FLASH_CELLBOARD_4_RX):
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend()
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        return message


class message_FLASH_CELLBOARD_5_TX:
    def __init__(
        self
    ):
        self.size = 0

    def __eq__(self, other):
        if not isinstance(other, message_FLASH_CELLBOARD_5_TX):
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend()
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        return message


class message_FLASH_CELLBOARD_5_RX:
    def __init__(
        self
    ):
        self.size = 0

    def __eq__(self, other):
        if not isinstance(other, message_FLASH_CELLBOARD_5_RX):
            return False
        return True

    def serialize(self) -> bytearray:
        data = bytearray()
        data.extend()
        return data

    @classmethod
    def deserialize(cls, data: bytearray):
        message = cls()
        return message

