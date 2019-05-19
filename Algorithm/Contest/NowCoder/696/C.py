def factorial(n, mod):
    ans = 1
    for i in range(1, n + 1):
        ans = (ans * i) % mod
    return ans


def pow(n, k, mod):
    ans = 1
    for i in range(k):
        ans = (ans * n) % mod
    return ans


mod = int(1e9 + 7)
n = int(input())
print(((pow(26, n, mod) - factorial(n, mod))))
