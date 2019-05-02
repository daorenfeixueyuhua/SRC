
# 输入的骚操作
# 输入一行多个数时才能使用
f = lambda: map(int, input().split())
n, k = f()
l = list(f())
print(sum(v >= max(1, l[k-1]) for v in l))
