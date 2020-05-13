from scrapy.cmdline import execute

if __name__ == '__main__':
    file_name = '2020-05-04-正式爬取'
    execute(['scrapy',
             'crawl',
             'cg_spider',
             '-o',
             '../resource/{0}.json'.format(file_name),
             '-s',
             'LOG_FILE = ../logs/{0}.json'.format(file_name)
             ])
