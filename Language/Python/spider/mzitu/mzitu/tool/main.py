from datetime import date
from scrapy.cmdline import execute

item_name = 'mzitu'
spider_name = item_name + '_spider'
mode = 'Debug'
data = date.today().isoformat()

file_name = mode + '-' + item_name + data

# IP被封

execute(['scrapy',
         'crawl',
         spider_name,
         '-o',
         '../resources/{0}.json'.format(file_name),
         '--logfile=../resources/{0}.log'.format(file_name)])
