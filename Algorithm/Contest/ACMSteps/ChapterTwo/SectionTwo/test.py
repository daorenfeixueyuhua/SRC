import math
# 去一个数的前4位
v = int(input())
temp = math.log10(v)
temp -= math.floor(temp)
temp = pow(10.0, temp)
while temp < 1000:
    temp *= 10
print(int(temp))
