from scrapy.cmdline import execute
import datetime


class Demo:
    @classmethod
    def crawl(self, spider_name):
        date = datetime.date.today().isoformat()
        max_item = 10
        execute(['scrapy',
                 'crawl',
                 spider_name,
                 '-o',
                 '{0}.json'.format(date),
                 '--logfile={0}.log'.format(date)])

        # Stored json feed (614 items) in: 2020-05-03.json
        # 一页大概50
        # 已经被封IP了，换用代理试下。

    @classmethod
    def shell(self, url: str):
        execute(['scrapy', 'shell', url])
        pass


if __name__ == '__main__':
    spier_name = 'net_meinv'
    Demo.crawl(spier_name)
