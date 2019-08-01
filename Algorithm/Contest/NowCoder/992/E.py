T = int(input())
while T:
    n = int(input())
    # 空瓶
    k = n
    # 瓶盖
    l = n
    r = 0
    while k >=3 or l >= 4:
        r += k // 3
        k %= 3
        r += l // 4
        l %= 4
        n += r
        l += r
        k += r
        r = 0
        # print(k, l)
    print(n)
    T -= 1
    