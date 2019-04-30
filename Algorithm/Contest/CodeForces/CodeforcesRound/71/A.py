n = int(input())
for i in range(0, n):
    s = input()
    if len(s) > 10:
        print(s[0]+str(len(s)-2)+s[len(s)-1])
    else:
        print(s)
