# 给定一个正整数N，求出[2, N]中所有的素数
# 解决方案：
# 数组valid[i]记录i是否为素数。初始所有的valid[i]都为1。从2开始从小到大枚举i，
# 若valid[i]==1，则把从i^2开始每一个i的倍数的valid赋为0.
# 结束后valid[i]==1就是输数

maxn = 1000000

valid = [0 for _ in [0]*maxn]


def get_prime1(n: int, ans: list) -> int:
    # O(n log(n))
    tot = 0
    # 初始将valid全部设置为1
    for i in range(2, n+1):
        valid[i] = 1
    for i in range(2, n+1):
        if valid[i]:
            if n/i < i:
                break
            for j in range(i*i, n+1, i):
                valid[j] = 0
    for i in range(2, n+1):
        if valid[i]:
            ans[tot] = i
            tot += 1
    return tot


def get_prime2(n: int, ans: list) -> int:
  # O(N)
    tot = 0
    # 初始将valid全部设置为1
    for i in range(2, n+1):
        valid[i] = 1
    for i in range(2, n+1):
        if valid[i]:
            tot += 1
            ans[tot] = i
        j = 1
        while j <= tot and i*ans[j] <= n:
            valid[i*ans[j]] = 0
            if i * ans[j] == 0:
                break
            j += 1

    return tot


# N = int(input())
N = 100
tot = 0
ans = [0 for _ in [0]*maxn]

tot = get_prime2(N, ans)

print(N, '以内的素数大小为', tot, '前20为', ans[:20:])
