G = [[0, 6, 5, 2, 2],
     [6, 0, 0.5, 5, 7],
     [5, 0.5, 0, 1, 5],
     [2, 5, 1, 0, 4],
     [2, 7, 5, 3, 0]]

print(G)
dp = [0 for i in range(len(G))]

for i in range(len(G)):
    for j in range(len(G)):
        dp[i] = min(G[i][j - 1] + dp[j - 1], G[i][j] + dp[j])

print(dp)
