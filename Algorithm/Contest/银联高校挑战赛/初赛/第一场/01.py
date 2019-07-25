t = int(input())


while t:
    n, k, m = map(int, input().split())
    s = input()
    win = sum(i == '1' for i in s)
    fail = len(s) - win
    f = fail - k
    if f <= 0:
        f = 0
    r = m * (win - f)
    if r <= 0:
        r = 0
    print(r)
    t -= 1
