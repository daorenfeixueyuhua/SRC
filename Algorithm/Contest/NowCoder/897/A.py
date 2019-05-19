n = int(input())
for i in range(n):
    l = list(map(int, input().split()))
    k = [0] * 101
    for j in l:
        k[j] += 1
    for j in range(len(k)):
        if k[j] == 1:
            print(j)
