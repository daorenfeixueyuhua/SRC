# -*- coding: utf-8 -*-
import scrapy
from bt7086.items import Bt7086Item


class BtSpiderSpider(scrapy.Spider):
    name = 'bt_spider'
    # allowed_domains accepts only domains, not URLs. Ignoring URL entry %s in allowed_domains
    allowed_domains = ['p3.csgfnmdb.xyz/pw/']
    start_urls = ['http://p3.csgfnmdb.xyz/pw/thread.php?fid=15']
    next_base_url = 'http://p3.csgfnmdb.xyz/pw/thread.php?fid=15&page='

    page_index = 2
    page_max = 3

    format = "%Y-%m-%d %H:%M"
    # start_time = datetime.datetime.now().strftime(format)
    start_time = '2020-03-04 00:00:00'
    end_time = '2020-03-05 00:00:00'

    # 无法获取 2020-03-04 的图片

    img_base_url = 'http://p3.csgfnmdb.xyz/pw/'

    def parse(self, response):
        # 获取图片链接
        # 通常无法获取时，需要
        # 1 scrapy shell xxxxx
        # 2 view(response)
        # 3 在查看代码，重修编写xpath
        img_urls = response.xpath(
            '//tr[@class="tr3 t_one"]//h3/a/@href').extract()
        for img_url in img_urls:
          # Filtered offsite request to 报错，解决方案：设置 dont_filter=True
            yield scrapy.Request(self.img_base_url + img_url, callback=self.parse, dont_filter=True)

        # 获取图片的链接
        title = response.xpath(
            '//span[@id="subject_tpc"]//text()').extract_first()

        # title = response.xpath('//h1[@id="subject_tpc"]//text()').extract()[0]
        # 这个地方获取时间有问题
        # '//span[@class="fl gray"]//text()').extract_first()[5::]
# TypeError: 'NoneType' object is not subscriptable
        cur_time = response.xpath(
            '//span[@class="fl gray"]//text()').extract_first()
        if cur_time is not None:
            cur_time = cur_time[5::]

        ptc_url_list = response.xpath(
            '//div[@id="read_tpc"]//img//@src').extract()
        index = 1
        for url in ptc_url_list:
            if cur_time >= self.end_time:
                continue
            item = Bt7086Item()
            item['image_urls'] = url
            item['title'] = title
            item['index'] = index
            item['cur_time'] = cur_time
            index += 1
            if cur_time < self.start_time:
                return
            yield item

        # 访问下一个页面
        if self.page_index <= self.page_max:
            self.log('访问page: ', self.page_index)
            yield scrapy.Request(self.next_base_url+str(self.page_index), callback=self.parse)
            self.page_index += 1
