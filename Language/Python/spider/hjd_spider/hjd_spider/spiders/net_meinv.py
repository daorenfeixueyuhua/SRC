# -*- coding: utf-8 -*-
import scrapy
import os
import mysql
import re
from tools.redisTool import RedisTool

from hjd_spider.items import *


def validateTitle(title):
    rstr = r"[\/\\\:\*\?\"\<\>\|]"  # '/ \ : * ? " < > |'
    new_title = re.sub(rstr, "_", title)  # 替换为下划线
    return new_title



class NetMeinvSpider(scrapy.Spider):
    name = 'net_meinv'
    allowed_domains = ['hjd.niao2048.biz']
    # 要爬取的页面ID
    page_id = '277'
    host = 'localhost'
    port = 6379
    next_base_url = 'https://hjd.niao2048.biz/2048/thread.php?fid-{0}-page-{1}.html'
    complete_urls = []
    complete_key = 'hjd:{0}:complete:urls'.format(page_id)
    fail_urls = []
    fail_key = 'hjd:{0}:fail:urls'.format(page_id)
    page_index = 1
    page_max = 1
    # 277 测试 [1: 1]
    # 276 完成 [1: 70]
    # 126
    # redis
    cilent = None
    # 爬取的图片数量
    img_num = 0
    img_base_url = 'https://hjd.niao2048.biz/2048/'
    start_urls = [next_base_url.format(page_id, str(page_index))]

    def __init__(self, name=None, **kwargs):
        self.cilent = RedisTool(self.host, self.port)
        if 'thread' in self.start_urls[0]:
            self.next_base_url = self.next_base_url.format(self.page_id, '{0}')
        self.complete_urls = self.cilent.smembers(self.complete_key)
        super().__init__(name, **kwargs)

    def close(spider, reason):
        spider.logger.info('保存已经爬取过的url')
        spider.cilent.sadd(spider.complete_key, spider.complete_urls)
        spider.cilent.sadd(spider.fail_key, spider.fail_urls)

    def parse(self, response):
        if 'fid' in response.url:
            self.logger.info(msg='获取{0}内的图片连接'.format(response.url))
            img_urls = response.xpath('//td[@class="tal"]/a//@href').extract()
            for img_url in img_urls:
                # Filtered offsite request to 报错，解决方案：设置 dont_filter=True
                yield scrapy.Request(self.img_base_url + img_url, callback=self.parse, dont_filter=True)
            self.logger.info(msg='获取图片链接成功')
            # 不加限制一直死循环
            self.page_index += 1
            if self.page_index <= self.page_max:
                self.logger.info(msg='访问url: {0}'.format(self.next_base_url.format(str(self.page_index))))
                yield scrapy.Request(self.next_base_url.format(str(self.page_index)), callback=self.parse)

        if 'tid' in response.url:
            self.logger.info('访问{0}'.format(response.url))
            try:
                if response.url in self.complete_urls:
                    self.logger.info('{0}已经被爬取过了'.format(response.url))
                    return
                self.logger.info('获取{0}内的item信息'.format(response.url))
                # 获取图片信息
                titles = response.xpath(
                    '//div[@id="breadCrumb"]//a//text()').extract()
                # print("标题", titles)
                self.logger.info('标题:【{0}】'.format(titles))
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
                if time == None or time == '':
                    time = '2020-01-01 00:00:00'
                page = ''
                # 获取图片的链接
                title = titles[3]
                # 文件名清洗
                title = validateTitle(title)
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
                    item['ref'] = response.url
                    index += 1
                    self.img_num += 1
                    yield item
                # 需要对redis中 hjd:276:complete:urls 进行清理
                self.complete_urls.append(response.url)
            except BaseException as e:
                self.fail_urls.append(response.url)
                self.logger.error('{0}出现问题：{1}'.format(response.url, e))
