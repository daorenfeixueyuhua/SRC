# -*- coding: utf-8 -*-
import scrapy
from hjd_spider.items import HjdSpiderItem


class MultiSpiderSpider(scrapy.Spider):
    name = 'multi_spider'
    allowed_domains = ['hjd.niao2048.biz/']
    start_urls = [
        'https://hjd.niao2048.biz/2048/thread.php?fid-275.html']
    next_base_url = 'https://hjd.niao2048.biz/2048/thread.php?fid-275-page-'

    page_index = 1
    page_max = 100
    # 爬取的图片数量
    img_num = 0

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
        # title = response.xpath('//h1[@id="subject_tpc"]//text()').extract()[0]
        ptc_url_list = response.xpath(
            '//div[@id="read_tpc"]/img/@src').extract()
        if len(ptc_url_list) == 0:
            ptc_url_list = response.xpath(
                '//div[@id="read_tpc"]//img/@src').extract()
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
            self.img_num += 1
            yield item

            # 测试使用的，上线要注释掉
            # if self.img_num >= 3:
            #     exit(1)

            # 访问下一个页面

        self.log('访问page: ', self.page_index)
        yield scrapy.Request(self.next_base_url + str(self.page_index) +
                             '.html', callback=self.parse)
        self.page_index += 1
