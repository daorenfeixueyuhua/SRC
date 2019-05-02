# print(sum(ord(c) for c in str.upper(input()))-sum(ord(c) for c in str.upper(input())))
a = input().upper()
b = input().upper()
print((a > b) - (a < b))
