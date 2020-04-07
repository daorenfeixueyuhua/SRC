# 将正整数 N 拆分成若干个正整数之和，求有多少中不重复的方案
# 未完成
n = int(input())
n += 1

g = [[0 for _ in [0] * n] for _ in [0] * n]
# print(g)

for i in range(1, n):
    g[i][1] = i

for i in range(2, len(g)):
    for j in range(2, len(g[1])):
        g[i][j] = g[i][j - 1] + g[i - j][j]

n -= 1
print(g[n][n])
