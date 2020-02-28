# -*- coding: utf-8 -*-
import scrapy
from hjd_spider.items import HjdSpiderItem


class SinglePageSpider(scrapy.Spider):
    name = 'single_page'
    allowed_domains = ['http://hjd.niao2048.biz/']
    start_urls = ['http://hjd.niao2048.biz/2048/read.php?tid-1838675.html/']

    def parse(self, response):
        ptc_url_list = response.xpath(
            '//div[@id="read_tpc"]/img/@src').extract()
        for url in ptc_url_list:
          item = HjdSpiderItem()
          item['url'] = url
          yield item

        pass
