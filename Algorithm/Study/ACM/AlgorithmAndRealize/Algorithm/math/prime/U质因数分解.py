# 给一个正整数N，将N分解质因数
# 方案：
# N的质因数要么是N本身，要么一定小于等于sqrt(N)。
# 可以用小于等于sqrt(N)的数对N进行使除，一直到不能除为止。
# 这时候剩下的数如果不是1，那就是N最大的质因数。

import math


def R(): return map(int, input().split())


maxn = 10000


def factor(n, a: list, b: list):
    # n 待分解的数
    # a a[i]表示第i个质因数的值
    # b b[i]表示第i个质因数的指数
    temp = int(math.sqrt(n)+1)
    tot = 0
    now = n
    for i in range(2, temp+1):
        if n % i:
            tot += 1
            a[tot] = i
            b[tot] = 0
            while not now % i:
                b[tot] += 1
                now /= i
    if now != 1:
        tot += 1
        a[tot] = now
        b[tot] = 1
    return tot


if __name__ == "__main__":
    a = [0 for _ in [0]*maxn]
    b = [0 for _ in [0]*maxn]
    N, = R()
    ans = factor(N, a, b)
    print(a[1:10:])
    print(b[1:10:])
