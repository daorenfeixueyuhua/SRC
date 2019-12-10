def scan(): return list(map(int, input().split()))


def mode(a, b, p):
    ans = 0
    while b:
        if b & 1:
            ans = (ans + a) % p
        a = (a * 2) % p
        b >>= 1
    return ans % p


if __name__ == "__main__":
    a, b, p = scan()
    print(mode(a, b, p))
