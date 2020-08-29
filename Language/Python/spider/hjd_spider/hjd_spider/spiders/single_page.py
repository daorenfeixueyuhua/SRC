# -*- coding: utf-8 -*-
import scrapy
from hjd_spider.items import HjdSpiderItem


class SinglePageSpider(scrapy.Spider):
    name = 'single_page'
    allowed_domains = ['http://hjd.niao2048.biz/']
<<<<<<< HEAD
    page_index = 0
    page_max = 100
    start_urls = [
        'https://hjd.niao2048.biz/2048/read.php?tid-2081822-fpage-3.html','https://hjd.niao2048.biz/2048/read.php?tid-2038902-fpage-5.html']

    def parse(self, response):
        # 获取图片信息
        titles = response.xpath(
            '//div[@id="breadCrumb"]//a//text()').extract()
        print("标题", titles)
        first_title = titles[0]
        # // 缺值处理
        if first_title == None or first_title == '':
            first_title = 'Defualt'
        second_title = titles[1]
        if second_title == None or second_title == '':
            second_title = 'Defualt'
        third_title = titles[2]
        if third_title == None or third_title == '':
            third_title = 'Defualt'
        time = response.xpath(
            '//span[@class="fl gray"]//@title').extract_first()
        time = time[:10:]
        if time == None or time == '':
            time = '2020-01-01'
        page = ''
        # 获取图片的链接
        title = titles[3]
=======
    start_urls = [
        'http://hjd.niao2048.biz/2048/read.php?tid-1865766-keyword-%E5%94%AF%E7%BE%8E.html']

    def parse(self, response):
        # 获取图片的链接
        title = response.xpath('//title//text()').extract()[0].split(',')[0]
>>>>>>> c58ecc4d435ea0785344b0f88d3f36ae3e078cfb
        # title = response.xpath('//h1[@id="subject_tpc"]//text()').extract()[0]
        ptc_url_list = response.xpath(
            '//div[@id="read_tpc"]/img/@src').extract()
        if len(ptc_url_list) == 0:
            ptc_url_list = response.xpath(
                '//div[@id="read_tpc"]//img/@src').extract()
<<<<<<< HEAD
        #   图片标号
        index = 1
        for url in ptc_url_list:
            item = HjdSpiderItem()
            item['first_title'] = first_title
            item['second_title'] = second_title
            item['third_title'] = third_title
            item['time'] = time
            item['page'] = str(self.page_index)
            item['image_urls'] = url
            item['title'] = title
            item['index'] = str(index)
            index += 1
            yield item
=======
        index = 1
        for url in ptc_url_list:
            item = HjdSpiderItem()
            item['image_urls'] = url
            item['title'] = title
            item['index'] = index
            index += 1
            yield item
        pass
>>>>>>> c58ecc4d435ea0785344b0f88d3f36ae3e078cfb
