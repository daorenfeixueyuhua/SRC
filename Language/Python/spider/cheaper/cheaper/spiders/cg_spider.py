# -*- coding: utf-8 -*-
import scrapy
from cheaper.items import CheaperItem


class CgSpiderSpider(scrapy.Spider):
    name = 'cg_spider'
    allowed_domains = ['http://cheaper.work/']
    start_urls = []
    download = 'http://cdn-msp.cheaper.work/media/photos/{0}/{1}.jpg'
    max_page = 0

    def __init__(self, name=None, **kwargs):
        super().__init__(name, **kwargs)
        with open('../resource/start_urls.txt', 'r') as file:
            for line in file.readlines():
                if 'http' in line or 'https' in line:
                    self.start_urls.append(line)

    def parse(self, response):
        img_id = response.url.split('/')[4]
        title = response.xpath('//span[@class="top-comname"]//text()').extract_first().split('|')[0]
        self.max_page = int(response.xpath('//select[@id="pageselect"]//option[@value="0"]//text()').extract()[2])

        for i in range(self.max_page + 1):
            item = CheaperItem()
            item['title'] = title
            item['index'] = str(i).zfill(5)
            item['image_urls'] = self.download.format(img_id, item['index'])
            yield item
