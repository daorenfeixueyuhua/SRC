
# 输入的骚操作
f = lambda: map(int, input().split())
n, k = f()
l = list(f())
print(sum(v >= max(1,l[k-1]) for v in l))
