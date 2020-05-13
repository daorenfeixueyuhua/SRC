# -*- coding: utf-8 -*-
import scrapy

from tools.redisTool import RedisTool


class CompleteSpiderSpider(scrapy.Spider):
    name = 'complete_spider'
    allowed_domains = ['hjd.niao2048.biz']
    page_id = '275'
    # 要爬取的页面ID
    next_base_url = 'https://hjd.niao2048.biz/2048/thread.php?fid-{0}-page-{1}.html'
    complete_urls = []
    complete_key = 'hjd:complete:urls'
    fail_urls = []
    page_index = 1
    page_max = 141
    # 爬取的图片数量
    img_num = 0
    img_base_url = 'https://hjd.niao2048.biz/2048/'
    start_urls = [next_base_url.format(page_id, str(page_index))]
    cilent = None

    def __init__(self, name=None, **kwargs):
        self.cilent = RedisTool('localhost', 6379)
        if 'thread' in self.start_urls[0]:
            self.next_base_url = self.next_base_url.format(self.page_id, '{0}')
        # 工作目录在tool中
        self.complete_urls = self.cilent.smembers(self.complete_key)
        super().__init__(name, **kwargs)

    def close(spider, reason):
        spider.logger.info('保存已经爬取过的url')
        spider.cilent.sadd(spider.complete_key, spider.complete_urls)

    def parse(self, response):
        if 'thread' in response.url:
            img_urls = response.xpath('//td[@class="tal"]/a//@href').extract()
            for img_url in img_urls:
                # Filtered offsite request to 报错，解决方案：设置 dont_filter=True
                self.complete_urls.append(img_url)
            # 不加限制一直死循环
            self.page_index += 1
            if self.page_index <= self.page_max:
                self.logger.info(msg='访问url: {0}'.format(self.next_base_url.format(str(self.page_index))))
                yield scrapy.Request(self.next_base_url.format(str(self.page_index)), callback=self.parse)
