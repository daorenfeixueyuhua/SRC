class Graph():
    v = []
    e = []

def dfs_visit(g, s, v):
    v.append(s)
    for i in g.v:
        if i not in v and i != v and ((s, i) in g.e or (i, s) in g.e):
            dfs_visit(g, i, v)
    return v

def dfs(g):
    v = []
    for i in g.v:
        if i not in v:
            dfs_visit(g, i, v)
    return v
        

if __name__ == "__main__":

    g = Graph()
    g.v = [1, 2, 3, 4, 5, 6, 7, 8, 9]
    # 无向图
    g.e = [(1, 2), (1, 3), (2, 4), (3, 4), (5, 6), (5, 9), (7, 9), (9, 8)]
    # print(g.v, g.e)
    v = dfs(g)
    print(v)

