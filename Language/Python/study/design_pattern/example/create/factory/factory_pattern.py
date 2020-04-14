from study.design_pattern.factory import Factory
from study.design_pattern.enum import ShapeEnum


class Shape:
    def draw(self):
        pass


class Rectangle(Shape):
    def draw(self):
        print('Inside Rectangle::draw() method')


class Square(Shape):
    def draw(self):
        print('Inside Square::draw() method')


class Circle(Shape):
    def draw(self):
        print('Inside Circle::draw() method')


class ShapeFactory(Factory):
    def get_bean(self, obj):
        if obj == ShapeEnum.CIRCLE:
            return Circle()
        elif obj == ShapeEnum.RECTANGLE:
            return Rectangle()
        elif obj == ShapeEnum.SQUARE:
            return Square()
        else:
            return None


if __name__ == '__main__':
    factory = ShapeFactory()
    rectangle = factory.get_bean(ShapeEnum.RECTANGLE)
    circle = factory.get_bean(ShapeEnum.CIRCLE)
    square = factory.get_bean(ShapeEnum.SQUARE)

    rectangle.draw()
    circle.draw()
    square.draw()
