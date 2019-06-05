import os
G = []
for i in range(100):
    g = ''
    for j in range(100):
        if i == 0 and j == 0:
            # g.append('S')
            g += 'S'
        elif i == 99 and j == 0:
            # g.append('E')
            print('kk')
            g += 'E'
        # elif i == 0 or j == 99 or i == 99:
        elif i != 99 or j != 0:
            # g.append('*')
            g += '*'
        # else:
        # g.append('#')
        # g += '#'
    G.append(g)

f = open('./data.txt', 'w')
f.write('100 100\n')

for i in range(100):
    f.write(G[i]+'\n')
    print(G[i])
f.close()
