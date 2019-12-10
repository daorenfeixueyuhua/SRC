from math import *


inf = 0xfffff
ans = inf
n = 0
m = 0
r = [0 for i in range(25)]
h = [0 for i in range(25)]
min_v_sum = [0 for i in range(25)]
min_s_sum = [0 for i in range(25)]


def dfs(deep, s, v):
    if not deep:
        if v == n:
            ans = min(ans, s)
            return
    r[deep] = min(int(sqrt(n-v)), r[deep+1]-1)
    while r[deep] >= deep:
        h[deep] = min(int(float(n-v)/r[deep]/r[deep]), h[deep+1]-1)+1
        while h[deep] > deep:
            h[deep] -= 1
            if v + min_v_sum[deep] > n:
                continue
            if s + min_s_sum[deep] > ans:
                continue

            if s + 2.0 * (n - v)/r[deep] > ans:
                continue
            if deep == m:
                s = r[deep]*r[deep]
            dfs(deep - 1, s+2*r[deep]*r[deep], v+r[deep]*r[deep]*r[deep])
            if deep == m:
                s = 0
        r[deep] -= 1


def scan():
    return list(map(int, input().split()))




n, m = scan()
for i in range(1, m+1):
    min_s_sum[i] = min_s_sum[i-1]+2*i*i
    min_v_sum[i] = min_v_sum[i-1] + i*i*i

h[m+1] = r[m+1] = inf

dfs(m, 0, 0)
if ans == inf:
    ans = 0
print(ans)
