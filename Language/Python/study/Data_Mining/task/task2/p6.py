import math

t1 = (22, 1, 42, 10)
t2 = (20, 0, 36, 8)
print(t1, t1[0])
print(t2, t2[0])

l1 = (sum((t1[i] - t2[i]) ** 2) for i in range(4))
print(l1)
l2 = (sum(math.fabs(t1[i] - t2[i])) for i in range(4))
print(l2)
q = 3
l3 = (sum(math.fabs(t1[i] - t2[i]) ** q) for i in range(4))
print(l3)
max_length = (max(t1[i], t2[i]) for i in range(4))
print(max_length)
