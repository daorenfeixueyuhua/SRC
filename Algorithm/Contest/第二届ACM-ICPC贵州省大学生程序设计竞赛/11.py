# coding=utf-8
def f(): return map(int, input().split())


def dfs(G, i, j):
    if i < 0 or j < 0 or i == H or j == W or G[i][j] == '#' or (i, j) in V:
        return INF
    if G[i][j] == 'E':
        V.append((i, j))
        return 1
    if G[i][j] == '*' or G[i][j] == 'S':
        f = 1
        if G[i][j] == 'S':
            f = 0
        V.append((i, j))
        # print((i, j))
        return min(dfs(G, i-1, j), dfs(G, i, j-1), dfs(G, i+1, j), dfs(G, i, j+1))+f

# H = 3
# W = 3
# G = ['S*#',
#      '**#',
#      '#*E']


INF = 0xFFFFFFF
H, W = f()
while H != 0 and W != 0:
    G = []
    for i in range(W):
        G.append(input())
    V = []
    for i in range(H):
        for j in range(W):
            if G[i][j] == 'S':
                value = dfs(G, i, j)
    print(value if value < INF else -1)
    H, W = f()
