import math

q = int(input())
while q:
    l = list(map(int, input().split()))
    l = sorted(l)
    a = l[0]
    b = l[1]
    c = l[2]
    r = 0
    # if a == b and b <= c:
    #     r = a + int(c / 2)
    # if a < b and b == c:
    #     r = c + int(a / 2)
    # if a < b and b < c:
    #     if (b-a) < (c-b):
    #         r = b + int((c - b + a) / 2)
    #     else:
    #         r = c + int((a - c + b) / 2)
    # print(a, b, c, r)
    r = (a + b + c) // 2

    print(r)
    q -= 1