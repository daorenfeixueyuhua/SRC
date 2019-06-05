def f(): return map(int, input().split())


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
    d = 0

    # 待修改
    def bfs(i, j, V):
        Q = [(i, j)]
        while Q:
            i, j = Q[0]
            V.append((i, j))
            if G[i][j] == 'E':
                return
            Q.remove((i, j))
        

    # 递归层度太深了
    def dfs(i, j, V):
        if i < 0 or j < 0 or i == H or j == W or G[i][j] == '#' or (i, j) in V:
            # print(i, j, V)
            return INF
        if G[i][j] == 'E':
            # V.append((i, j))
            # print(V, len(V)
            return len(V)
        if G[i][j] == '*' or G[i][j] == 'S':
            V.append((i, j))
            VN = [V.copy() for i in range(4)]
            k = [INF for i in range(4)]
            k[0] = dfs(i - 1, j, VN[0])
            k[1] = dfs(i, j - 1, VN[1])
            k[2] = dfs(i + 1, j, VN[2])
            k[3] = dfs(i, j + 1, VN[3])
            # print(VN)
            return min(k)

    V = []
    for i in range(H):
        for j in range(W):
            if G[i][j] == 'S':
                # value = dfs(i, j, V)
                bfs(i, j, V)
    # print(value if value < INF else - 1)
    print(V)
    H, W = f()
