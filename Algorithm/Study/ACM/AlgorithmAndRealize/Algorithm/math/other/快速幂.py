# 给定a，i，n，求 a ^ b mod n


def R(): return list(map(int, input().split()))


def pow_mod(a: int, i: int, n: int) -> int:
    ans = 1
    while i > 0:
        if i & 1:
            ans = (ans*a) % n
        i = i >> 1
        a = (a*a) % n
    return ans


if __name__ == "__main__":
    a, b, n = R()
    print(pow_mod(a, b, n))
