n = int(input())
a = list(map(int, input().split()))

s = []
v = []
s.append(['L', 'R'][a[0] > a[len(a) - 1]])
v.append([a[0], a[len(a) - 1]][a[0] > a[len(a) - 1]])
a.remove([a[0], a[len(a) - 1]][a[0] > a[len(a) - 1]])
while a:
    print(a)
    print(s)
    print(v)
    # 判断存在一定问题
    if v[len(v) - 1] >= min(a[0], a[len(a) - 1]):
        break
    if v[len(v) - 1] < a[0] and a[0] <= a[len(a)-1]:
        s.append('L')
        v.append(a[0])
        a.remove(a[0])
        continue
    if v[len(v) - 1] < a[len(a)-1] and a[len(a)-1] <= a[0]:
        s.append('R')
        v.append(a[len(a)-1])
        a.remove(a[len(a)-1])
        continue

print(len(v))
k = ''
for i in range(len(s)):
    k += s[i]
print(k)
