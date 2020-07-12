from scrapy.cmdline import execute
import datetime

date = datetime.date.today().isoformat()
item_name = 'dongmantupian'
spider_name = item_name + '_spider'
execute(['scrapy',
         'crawl',
         spider_name,
         '-o',
         '{0}-{1}.json'.format(item_name, date),
         '--logfile={0}-{1}.log'.format(item_name, date)])

# 设计模式对scrapy爬虫模板的构建
