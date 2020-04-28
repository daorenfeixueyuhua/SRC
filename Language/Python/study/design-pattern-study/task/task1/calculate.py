from enum import *


def R(): return list(map(int, input().split()))


class Operator(Enum):
    ADD = 1
    SUB = 2
    MUL = 3
    DIV = 4


class Calculate:
    inf = 0xfffff
    op = Operator.ADD
    num1 = 0
    num2 = 0

    @staticmethod
    def menu():
        print("1. Addition")
        print("2. Subtraction")
        print("3. Multiplication")
        print("4. Division")
        print("5. Exit")

    def cal(self, op, num1, num2):
        if op == Operator.ADD:
            return self.__add(num1, num2)
        if op == Operator.SUB:
            return self.__sub(num1, num2)
        if op == Operator.MUL:
            return self.__mul(num1, num2)
        if op == Operator.DIV:
            return self.__div(num1, num2)
        else:
            print('操作符不正确')
            return self.inf

    def __add(self, num1, num2):
        return num1 + num2

    def __sub(self, num1, num2):
        return num1 - num2

    def __mul(self, num1: int, num2: int) -> int:
        return num1 * num2

    def __div(self, num1, num2):
        return num1 / num2


if __name__ == '__main__':
    calculate = Calculate()
    calculate.menu()
    op = int(input("Enter your choice: "))
    if 1 <= op <= 4:
        OP = Operator
        if op == 1: OP = Operator.ADD
        if op == 2: OP = Operator.SUB
        if op == 3: OP = Operator.MUL
        if op == 4: OP = Operator.DIV
        print("Enter two numbers: ")
        num1, num2 = R()
        ans = calculate.cal(OP, num1, num2)
        print('Result = ', ans)
        # claculate.menu()
        # op = int(input("Enter your choice: "))
    if op == 5:
        exit()
    else:
        print("Wrong input..!!")
