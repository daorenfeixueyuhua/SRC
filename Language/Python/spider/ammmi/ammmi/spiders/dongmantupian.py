# -*- coding: utf-8 -*-
import scrapy
import re
from tools.redisTool import RedisTool
from ammmi.items import *


def validateTitle(title):
    rstr = r"[\/\\\:\*\?\"\<\>\|]"  # '/ \ : * ? " < > |'
    new_title = re.sub(rstr, "_", title)  # 替换为下划线
    return new_title


class DongmantupianSpider(scrapy.Spider):
    name = 'dongmantupian_spider'
    base_url = 'https://www.ammmi.com/category/dongmantupian/page/{0}/'
    allowed_domains = ['www.ammmi.com']
    page_index = 3
    page_max = 86
    start_urls = [base_url.format(str(page_index))]
    # redis key and values
    complete_key = 'ammmi:dongmantupian:complete:urls'
    complete_values = []
    fail_key = 'ammmi:dongmantupian:fail:urls'
    fail_values = []
    # redis
    client = None
    host = 'localhost'
    port = 6379
    DEBUG = False

    def __init__(self):
        if self.DEBUG:
            self.page_max = 1
        RedisTool.setHost(self.host, self.port)
        self.client = RedisTool()
        self.complete_values = self.client.smembers(self.complete_key)
        self.fail_values = self.client.smembers(self.fail_key)
        self.logger.info('加载{0}:{1} {2}:{3}'.format(self.complete_key,
                                                    self.complete_values[:10:],
                                                    self.fail_key,
                                                    self.fail_values[:10:]))
        super().__init__()

    def close(self, reason):
        # todo 无法写入redis
        self.client.sadd(self.complete_key,
                         self.complete_values)
        self.client.sadd(self.fail_key,
                         self.fail_values)
        self.logger.info('保存{0}\n{1}'.format(self.complete_key, self.fail_key))
        super().close(self, reason)

    def parse(self, response):
        if 'category' in response.url:
            img_urls = []
            img_urls = response.xpath('//div[@class="bt_img mi_ne_kd mrb"]/ul/li/a//@href').extract()
            for url in img_urls:
                yield scrapy.Request(url, callback=self.parse)
            # next page
            self.page_index += 1
            if self.page_index <= self.page_max:
                self.logger.info('访问:{0}'.format(self.base_url.format(str(self.page_index))))
                yield scrapy.Request(self.base_url.format(str(self.page_index)),
                                     callback=self.parse)
        else:
            self.logger.info('读取{0}中item信息'.format(response.url))
            img_id = response.url.split('/')[4]
            img_base = 'https://www.ammmi.com/dongmantupian/{0}/{1}'.format(img_id, '{0}')
            img_title = 'dongmantupian'
            title = ''
            img_url = ''

            img_url = response.xpath('//div[@class="yp_context"]//img//@src').extract()
            title = response.xpath('//h2[@class="titletips"]//text()').extract_first()
            title = validateTitle(title)
            if len(img_url) <= 1:
                index = int(response.xpath('//span[@class="post-page-numbers current"]//text()').extract_first())
                index_max = len(response.xpath('//div[@class="fenye"]//a//span//text()').extract()
                                )
                self.logger.info('当前img_index:{0}, 最大img_max:{1}'.format(index, str(index_max)))
                self.logger.info('{0}有一张图片'.format(response.url))
                for i in img_url:
                    item = Dongmantupian()
                    item['img_title'] = img_title
                    item['title'] = title
                    item['img_url'] = i
                    item['index'] = str(index)
                    item['img_id'] = img_id
                    yield item
                if index <= index_max:
                    index += 1
                    self.logger.info('访问{0}下一张图片from{1}'.format(img_base.format(str(index)), response.url))
                    yield scrapy.Request(img_base.format(str(index)),
                                         callback=self.parse)
            else:
                self.logger.info('{0}有多张图片'.format(response.url))

                for i in range(len(img_url)):
                    item = Dongmantupian()
                    item['img_title'] = img_title
                    item['title'] = title
                    item['img_url'] = img_url[i]
                    item['index'] = str(i)
                    item['img_id'] = img_id
                    yield item
