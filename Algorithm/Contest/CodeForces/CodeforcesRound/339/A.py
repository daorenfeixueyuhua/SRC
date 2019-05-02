# s = list(map(int, input().split('+')))
# s.sort()
# k = str(s[0])
# for i in range(1, len(s)):
#     k += '+'
#     k += str(s[i])
#
# print(k)
# 我的版本

# 其他版本
# [::2] 这是切片的使用，从 0 n 提取2的倍数
# '.'.join(['ab', 'pq', 'rs']) -> 'ab.pq.rs': the string whose method is called is inserted in between each given string
# sorted(): Return a new list containing all items form the iterable in ascending order.
print('+'.join(sorted(input()[::2])))

