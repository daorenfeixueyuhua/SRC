from scrapy.cmdline import execute

from datetime import date

spider_name = 'buxiuse_spider'
_date = date.today().isoformat()
mode = 'Release'

execute(['scrapy', 'crawl', spider_name,
         '-o', '../resources/{0}-{1}.json'.format(mode, _date),
         '--logfile=../resources/{0}{1}.log'.format(mode, _date)])
