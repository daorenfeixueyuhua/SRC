def f(): return map(int, input().split())


n, m, k = f()
G = [[0]*(m+1)for i in [0]*(n+1)]
# G = [[0, 0, 0, 0, 0],
#      [0, 1, 0, 0, 0],
#      [0, 0, 1, 1, 0],
#      [0, 1, 1, 0, 0]]
K = []  # 被淹的格子

for l in [0] * k:
    i, j = f()
    K.append((i, j))
    G[i][j] = 1

V = []


def bfs(i, j):
    if (i, j) in V or i <= 0 or i > n or j <= 0 or j > m or G[i][j] == 0:
        return 0
    V.append((i, j))
    return bfs(i - 1, j) + bfs(i, j - 1) + bfs(i + 1, j) + bfs(i, j + 1) + 1


R = []

for i in range(len(K)):
    R.append(bfs(K[i][0], K[i][1]))

print(max(R))
# 未完成 pass 95%
