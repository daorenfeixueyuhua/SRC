n = int(input())

for i in range(n):
    s = input()
    score = [0] * (len(s)+1)

    for j in range(len(s)):
        if s[j] == 'O':
            score[j + 1] = score[j] + 1
    print(sum(score))
