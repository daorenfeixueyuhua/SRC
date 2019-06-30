import math


def f(): return map(int, input().split())


x, y, z = f()

# print(a, b)
coconut = x // z + y // z
x %= z
y %= z

# print(x, y, coconut)


exchange = 0
if x + y < z:
    exchange = 0
else:
    coconut += (x + y) // z
    exchange = min(abs(x-z), abs(y-z))

print(coconut, exchange)

# 999999999999999999 999999999999999999 1000000000000000000
