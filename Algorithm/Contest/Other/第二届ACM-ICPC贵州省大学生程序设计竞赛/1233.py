import os
import random
file = open('./data2.txt', 'w')

N = 20000

file.write(str(N)+'\n')

for i in range(N):
    file.write(str(random.randint(0, 1e8))+' ')

file.write('\n')
file.close()
