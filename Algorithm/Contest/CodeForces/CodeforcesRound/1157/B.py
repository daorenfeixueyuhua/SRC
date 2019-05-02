n = int(input())
s = input()
f = list(map(int, input().split()))
k = ''
for c in s:
    k += max(c, chr(f[ord(c) - ord('0')-1]+ord('0')))
print(k)
