# -*- coding: utf-8 -*-
import scrapy
from hjd_spider.items import HjdSpiderItem


class SinglePageSpider(scrapy.Spider):
    name = 'single_page'
    allowed_domains = ['http://hjd.niao2048.biz/']
    start_urls = [
        'http://hjd.niao2048.biz/2048/read.php?tid-1865766-keyword-%E5%94%AF%E7%BE%8E.html']

    def parse(self, response):
        # 获取图片的链接
        title = response.xpath('//title//text()').extract()[0].split(',')[0]
        # title = response.xpath('//h1[@id="subject_tpc"]//text()').extract()[0]
        ptc_url_list = response.xpath(
            '//div[@id="read_tpc"]/img/@src').extract()
        if len(ptc_url_list) == 0:
            ptc_url_list = response.xpath(
                '//div[@id="read_tpc"]//img/@src').extract()
        index = 1
        for url in ptc_url_list:
            item = HjdSpiderItem()
            item['image_urls'] = url
            item['title'] = title
            item['index'] = index
            index += 1
            yield item
        pass
