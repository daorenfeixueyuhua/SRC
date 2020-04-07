from study.design_pattern.create.factory.factory_pattern import *
from study.design_pattern.enum import *
from study.design_pattern.factory import *


class Color:
    def fill(self):
        pass


class Red(Color):
    def fill(self):
        print('Inside Red::fill() method')


class Blue(Color):
    def fill(self):
        print('Inside Blue::fill() method')


class Green(Color):
    def fill(self):
        print('Inside Green::fill() method')


class ShapeColorAbstractFactory(Factory):
    def get_color(self, obj):
        pass

    def get_shape(self, obj):
        pass


class ShapeFactory(ShapeColorAbstractFactory):
    def get_shape(self, obj):
        return self.get_bean(obj)

    def get_bean(self, obj):
        if obj == ShapeEnum.SQUARE:
            return Square()
        elif obj == ShapeEnum.RECTANGLE:
            return Rectangle()
        elif obj == ShapeEnum.CIRCLE:
            return Circle()
        else:
            return None


class ColorFactory(ShapeColorAbstractFactory):

    def get_color(self, obj):
        return self.get_bean(obj)

    def get_bean(self, obj):
        if obj == ColorEnum.RED:
            return Red()
        elif obj == ColorEnum.BLUE:
            return Blue()
        elif obj == ColorEnum.GREEN:
            return Green()
        else:
            return None


class ProduceFactory(Factory):
    def get_bean(self, obj):
        if obj == FactoryEnum.SHAPE:
            return ShapeFactory()
        elif obj == FactoryEnum.COLOR:
            return ColorFactory()

if __name__ == '__main__':
    produceFactory = ProduceFactory()
    shapeFactory = produceFactory.get_bean(FactoryEnum.SHAPE)
    colorFactory = produceFactory.get_bean(FactoryEnum.COLOR)

    circle = shapeFactory.get_shape(ShapeEnum.CIRCLE)
    rectangle = shapeFactory.get_shape(ShapeEnum.RECTANGLE)
    square = shapeFactory.get_shape(ShapeEnum.SQUARE)

    red = colorFactory.get_color(ColorEnum.RED)
    green = colorFactory.get_color(ColorEnum.GREEN)
    blue = colorFactory.get_color(ColorEnum.BLUE)


    circle.draw()
    rectangle.draw()
    square.draw()

    red.fill()
    green.fill()
    blue.fill()