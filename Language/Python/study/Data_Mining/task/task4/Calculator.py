# 1、开闭原则（Open Close Principle）
#
# 开闭原则的意思是：对扩展开放，对修改关闭。在程序需要进行拓展的时候，不能去修改原有的代码，实现一个热插拔的效果。简言之，是为了使程序的扩展性好，易于维护和升级。想要达到这样的效果，我们需要使用接口和抽象类，后面的具体设计中我们会提到这点。
#
# 2、里氏代换原则（Liskov Substitution Principle）
#
#
# 3、依赖倒转原则（Dependence Inversion Principle）
#
# 这个原则是开闭原则的基础，具体内容：针对接口编程，依赖于抽象而不依赖于具体。
#
# 4、接口隔离原则（Interface Segregation Principle）
#
# 这个原则的意思是：使用多个隔离的接口，比使用单个接口要好。它还有另外一个意思是：降低类之间的耦合度。由此可见，其实设计模式就是从大型软件架构出发、便于升级和维护的软件设计思想，它强调降低依赖，降低耦合。
#
# 5、迪米特法则，又称最少知道原则（Demeter Principle）
#
# 最少知道原则是指：一个实体应当尽量少地与其他实体之间发生相互作用，使得系统功能模块相对独立。
#
# 6、合成复用原则（Composite Reuse Principle）
#
# 合成复用原则是指：尽量使用合成/聚合的方式，而不是使用继承。

# 1.	基于面向对象，实现圆形面积求解，如功能扩展，求解三角形、矩形…等图形面积需要一个通用的工具？


import math


class Figure:
    __name__ = ''

    def __calculate_area(self):
        pass


class Circle(Figure):
    __name__ = 'Circle'
    __radius__ = 0

    def __init__(self, radius):
        self.__radius__ = radius

    def __calculate_area(self):
        return math.pi * self.__radius__ ** 2

