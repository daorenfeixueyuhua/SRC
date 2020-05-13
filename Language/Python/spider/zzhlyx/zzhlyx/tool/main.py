from scrapy.cmdline import execute
from zzhlyx.settings import *
import os

# 功能添加，在命令行参数中添加要下载的url

execute(['scrapy', 'crawl', 'single_page', '-o', 'item.json'])

for dir in os.listdir(FILES_STORE):
    if dir != 'full':
        os.chdir(FILES_STORE + dir + '/')
        # print(os.getcwd())
        os.system('copy /b *.ts {}.mp4 && del *.ts'.format(dir))
