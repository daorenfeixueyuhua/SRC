def f(): return map(int, input().split())


l1 = list(f())
l2 = list(f())

l3 = []

i = 0
j = 0
while i < len(l1) and j < len(l2):
    if l1[i] < l2[j]:
        l3.append(l1[i])
        i += 1
    else:
        l3.append(l2[j])
        j += 1
while i < len(l1):
    l3.append(l1[i])
    i += 1
while j < len(l2):
    l3.append(l2[j])
    j += 1

s = ""
for i in l3:
    s = s + str(i)  + " "
print(s)
