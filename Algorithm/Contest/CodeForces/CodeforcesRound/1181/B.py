# import math
# import random

# # n = int(input())
# # s = input()
# r = random.Random()
# n = 100000
# s = ''
# for i in range(0, n):
#     s += str(r.randint(0, 9))


# def run1(s):
#     l = []
#     for i in range(1, len(s)):
#         s1 = s[0:i:1]
#         s2 = s[i:len(s):1]
#         if s2[0] == '0':
#             continue
#         l.append(int(s1) + int(s2))
#     return l


# def run2(s, n):
#     l = []
#     i = math.floor(len(s)/2)
#     j = i
#     cnt = 0
#     c1 = n // 2 -2 if n // 2 - 2 > 0 else 0 
#     c2 = n // 2 + 2 if n // 2 + 2 < n else n
#     # print(c1, c2)
#     while i > c1 and i > 0:
#         s1 = s[0:i:]
#         s2 = s[i:n:]
#         if s2[0] == '0':
#             i -= 1
#             continue
#         l.append(int(s1) + int(s2))
#         # print(l)
#         i -= 1
#         cnt += 1

#     while j < c2:
#         s1 = s[0:j:]
#         s2 = s[j:n:]
#         if s2[0] == '0':
#             j += 1
#             continue
#         l.append(int(s1) + int(s2))
#         # print(l)
#         j += 1
#         cnt += 1
#     # print(cnt)
#     return l


# print(sorted(run2(s, n))[0])
n = int(input())
s = input()

nm = 9999999

for i in range(n//2, 0, -1):
    if s[i] != '0':
        nm = int(s[:i]) + int(s[i:])
        break
    
for i in range(n//2 +1, n):
    if s[i] != '0':
        nm = min(nm, int(s[:i]) + int(s[i:]))
        break

print(nm)