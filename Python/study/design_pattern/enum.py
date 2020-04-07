from enum import Enum


class ShapeEnum(Enum):
    RECTANGLE = 1
    CIRCLE = 2
    SQUARE = 3


class ColorEnum(Enum):
    RED = 1
    ORANGE = 2
    YELLOW = 3
    GREEN = 4
    CYAN = 5
    BLUE = 6
    PURPLE = 7


class FactoryEnum(Enum):
    SHAPE = 1
    COLOR = 2
