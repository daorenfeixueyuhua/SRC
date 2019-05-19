# 深度优先搜索
def dfs(g, s, v):
    # 递归结束条件
    if s in v:
        return v
    v.append(s)
    for i in range(len(g)):
        if i not in v and g[s][i]:
            v = dfs(g, i, v)
    return v


# 广度优先搜索
def bfs(g, s):
    v = []
    q = []
    q.append(s)
    while q:
        s = q[0]
        q.remove(s)
        for i in range(len(g)):
            if i not in v and i not in q and g[s][i]:
                q.append(i)
        v.append(s)
    return v


# 手动输入点和边数据
# # 定义输入匿名函数
# def f(): return map(int, input().split())


# # 输入点数和边数
# n, m = f()
# # 初始化二维列表作为图邻阶矩阵
# g = [[0] * n for i in range(n)]

# # 输入边集合
# for k in range(m):
#     i, j = f()
#     g[i][j] = 1
#     g[j][i] = 1

# 手动输入的测试用例：
# 8 10
# 0 1
# 0 4
# 1 5
# 2 3
# 2 5
# 2 6
# 3 6
# 3 7
# 5 6
# 6 7


# 手动输入后g的数据

g = [[0, 1, 0, 0, 1, 0, 0, 0],
     [1, 0, 0, 0, 0, 1, 0, 0],
     [0, 0, 0, 1, 0, 1, 1, 0],
     [0, 0, 1, 0, 0, 0, 1, 1],
     [1, 0, 0, 0, 0, 0, 0, 0],
     [0, 0, 1, 1, 0, 1, 0, 1],
     [0, 1, 1, 0, 0, 0, 1, 0],
     [0, 0, 0, 1, 0, 0, 1, 0]]


print(dfs(g, 1, []))
print(bfs(g, 1))
