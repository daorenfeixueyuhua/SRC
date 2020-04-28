# 给一个正整数N，判定N是否为素数


def pow_mod(a, d, n):
    ans = 1
    while d > 0:
        if d & 1:
            ans = ans*a % n
        d = d >> 1
        a = a*a % n
    return ans


def get_prime(n):
    maxn = 100000
    valid = [0 for _ in [0]*maxn]
    ans = [0 for _ in [0]*maxn]
    tot = 0
    for i in range(2, n+1):
        valid[i] = 1
    for i in range(2, n+1):
        if valid[i]:
            tot += 1
            ans[tot] = i
        j = 1
        while j <= tot and i * ans[j] <= n:
            valid[i*ans[j]] = 0
            if not (i * ans[j]):
                breakpoint
            j += 1
    return tot, ans


def test(n: int, a: int, d: int) -> int:
    if n == 2:
        return 1
    if n == a:
        return 1
    if not n & 1:
        return 0
    while not d & 1:
        d = d >> 1
    t = pow_mod(a, d, n)
    while d != n-1 and t != 1 and t != n-1:
        t = t*t % n
        d = d << 1
    return t == n-1 or (d & 1) == 1


def is_permie(n):
    if n < 2:
        return 0
    tot, a = get_prime(n*2)
    for i in range(tot):
        if not test(n, a[i], n - 1):
            return 0
    return 1


if __name__ == "__main__":
    K = int(input())
    print(is_permie(K))
