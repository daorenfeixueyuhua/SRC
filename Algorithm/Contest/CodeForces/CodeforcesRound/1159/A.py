n = int(input())
s = input()
count = 0
for c in s:
    if c == '+':
        count += 1
    elif c == '-' and count == 0:
        continue
    else:
        count -= 1
print(count)


