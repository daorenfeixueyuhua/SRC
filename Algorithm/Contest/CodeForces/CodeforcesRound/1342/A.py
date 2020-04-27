def R(): return map(int, input().split())


t, = R()
for _ in range(t):
    x, y = sorted(R())
    a, b = R()
    print(min(2*a, b)*x + a*(y-x))
