def f(): return map(int, input().split())


T = int(input())
for i in range(T):
    n = int(input())
    N = list(f())
    Q = int(input())
    N.insert(0, 0)

    def F(l, r, N):
        # // 应该排序下
        N = sorted(N[l:r:1])
        # print(N)
        s = N[0]
        # 过于复杂，需要简化算法
        for k in range(1, len(N)):
            s += N[k] if N[k] != N[k - 1] else 0
        return s
    # O(Q*N*lgN)
    for j in range(Q):
        l, r = f()
        print(F(l, r+1, N))
