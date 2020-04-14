text = 'NowCoder'
src  = '​NoowCoder'

for i in range(len(src)):
    for j in range(len(text)):
        if src[i] == text[j]:
            print(i, j)
            i += 1
            

