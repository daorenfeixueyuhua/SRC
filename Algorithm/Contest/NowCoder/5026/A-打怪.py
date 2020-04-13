def scanf():
    return list(map(int, input().split()))


t = int(input())
for _ in range(t):
    h, a, H, A = scanf()
    # print(h, a, H, A)
    # 一刀就没了，或者 毛怪没伤害
    if a >= H or A == 0:
        print(-1)
        continue
    # 你是战力0渣
    if a == 0:
        print(0)
        continue
    ans = 0
    while h > 0:
        temp_H = H
        while temp_H > 0:
            if h > 0:# 毛怪被宰
                temp_H -= A
            else:
                break
            if temp_H > 0:# 你被宰
                h -= a
            else:
                break
        if h > 0 and temp_H <= 0:
            ans += 1
    print(ans)

# 5 1 2 1
# #1 1 4
# #2 0 4
# #3 1 3
# #4 0 3
# #5 1 2
# #6 0 2
# #7 1 1
# #8 0 1
# #9 1 0
