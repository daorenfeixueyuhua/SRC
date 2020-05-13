# --*-- coding:gbk --*--

import os

path = 'C:\\Users\\Lenovo\\Downloads\\kkk\\2020-05-03-大文件资源\\Sakimi Chan 合集\\'
os.chdir(path)
print(os.getcwd())
min = 18
max = 114
for i in range(min, max):
    dir = str(i).zfill(3)
    file = path + dir + '\\'
    if os.path.exists(file):
        print('{0}存在'.format(dir))
        print('cd {0}'.format(dir))
        # os.system('cd {0}'.format(dir))
        os.chdir(path)
        os.chdir(dir)
        os.system('move /Y * ../')
        print('{0}移动删除成功'.format(file))
    else:
        print('{0}不存在'.format(file))
os.chdir(path)
os.system('del *.psd')