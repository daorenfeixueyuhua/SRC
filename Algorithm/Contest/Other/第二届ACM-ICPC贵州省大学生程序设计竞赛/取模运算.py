mod = 2333
n = int(input())
while 0 <= n and n <= 1000:
    r = 1

    for i in range(1, n+1):
        r = (r*i) % mod

    print(r)
    n = int(input())
