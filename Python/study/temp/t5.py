# a b c d
# a + b = 8
# a + c = 13
# c + d = 6
# b + d = 8
ans = []

for a in range(1, 17):
    for b in range(1, 9):
        for c in range(1, 17):
            for d in range(1, 9):
                if a + b == 8 and a + c == 13 and c + d == 6 and b + d == 8:
                    ans = [a, b, c, d]

print(ans)
