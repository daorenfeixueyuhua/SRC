def f(): return map(int, input().split())


# n, m = f()
# a = list(f())
# b = list(f())

a = []
b = []
for i in range(1, 1000):
    a.append(i)
    b.append(i)

k = []

for i in a:
    for j in b:
        k.append(i * j)
print(k)
