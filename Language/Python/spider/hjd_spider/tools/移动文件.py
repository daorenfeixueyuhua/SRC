# --*-- coding:gbk --*--

import os

path = 'C:\\Users\\Lenovo\\Downloads\\kkk\\2020-05-03-���ļ���Դ\\Sakimi Chan �ϼ�\\'
os.chdir(path)
print(os.getcwd())
min = 18
max = 114
for i in range(min, max):
    dir = str(i).zfill(3)
    file = path + dir + '\\'
    if os.path.exists(file):
        print('{0}����'.format(dir))
        print('cd {0}'.format(dir))
        # os.system('cd {0}'.format(dir))
        os.chdir(path)
        os.chdir(dir)
        os.system('move /Y * ../')
        print('{0}�ƶ�ɾ���ɹ�'.format(file))
    else:
        print('{0}������'.format(file))
os.chdir(path)
os.system('del *.psd')