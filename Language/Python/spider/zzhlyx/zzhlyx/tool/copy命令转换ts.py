import os
from zzhlyx.settings import *

# print(os.listdir(FILES_STORE))
for dir in os.listdir(FILES_STORE):
    if dir != 'full':
        os.chdir(FILES_STORE + dir + '/')
        # print(os.getcwd())
        os.system('copy /b *.ts {}.mp4 && del *.ts'.format(dir))
