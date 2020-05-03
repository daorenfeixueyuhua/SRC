from scrapy.cmdline import execute

if __name__ == '__main__':
    execute(['scrapy',
             'crawl',
             'cg_spider',
             '-o',
             '../resource/{0}.json'.format('2020-05-03')
             ])
