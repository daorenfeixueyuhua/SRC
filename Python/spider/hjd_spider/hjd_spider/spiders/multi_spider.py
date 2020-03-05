# -*- coding: utf-8 -*-
import scrapy
from hjd_spider.items import HjdSpiderItem


class MultiSpiderSpider(scrapy.Spider):
    name = 'multi_spider'
    allowed_domains = ['https://hjd.niao2048.biz/']
    start_urls = [
        'https://hjd.niao2048.biz/2048/thread.php?fid-23.html/']
    next_base_url = 'https://hjd.niao2048.biz/2048/thread.php?fid-23s-page-'
    
    page_index = 2
    page_max = 2

    img_base_url = 'https://hjd.niao2048.biz/2048/'

    def parse(self, response):

        # 获取图片链接
        # 通常无法获取时，需要
        # 1 scrapy shell xxxxx
        # 2 view(response)
        # 3 在查看代码，重修编写xpath
        img_urls = response.xpath('//td[@class="tal"]/a//@href').extract()
        for img_url in img_urls:
          # Filtered offsite request to 报错，解决方案：设置 dont_filter=True
            yield scrapy.Request(self.img_base_url + img_url, callback=self.parse, dont_filter=True)

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

        # 访问下一个页面
        if self.page_index <= self.page_max:
            self.log('访问page: ', self.page_index)
            yield scrapy.Request(self.next_base_url+str(self.page_index) +
                                 '.html', callback=self.parse)
            self.page_index += 1
