def getValue(n):
    s = bin(abs(n))
    o = 0
    z = 0
    for c in s[1::]:
        if c == '1':
            o += 1
        elif c == '0':
            z += 1
    return 1 if o > z else -1


n = int(input())
print(sum(getValue(i) for i in list(map(int, input().split()))))
