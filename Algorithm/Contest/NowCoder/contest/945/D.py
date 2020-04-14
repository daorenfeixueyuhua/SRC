def f(): return map(int, input().split())

n, r = f()
G = [[0 for i in range(n)] for j in range(n)]

for k in range(r):
    i, j, d = f()
    G[i - 1][j - 1] = d
    
print(G)

