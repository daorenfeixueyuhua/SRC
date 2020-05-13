# -*- coding: utf-8 -*-
import scrapy
from tools.redisTool import RedisTool
from ammmi.items import *
import re


def validateTitle(title):
    rstr = r"[\/\\\:\*\?\"\<\>\|]"  # '/ \ : * ? " < > |'
    new_title = re.sub(rstr, "_", title)  # 替换为下划线
    return new_title


class CosplaySpiderSpider(scrapy.Spider):
    name = 'cosplay_spider'
    base_url = 'https://www.ammmi.com/category/cosplay/page/{0}'
    allowed_domains = ['www.ammmi.com']
    page_index = 1
    page_max = 136
    start_urls = [base_url.format(str(page_index))]
    # redis key and values
    complete_key = 'ammmi:cosplay:complete:urls'
    complete_values = []
    fail_key = 'ammmi:cosplay:fail:urls'
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
            if self.page_index <= self.page_max:
                self.page_index += 1
                yield scrapy.Request(self.base_url.format(str(self.page_index)),
                                     callback=self.parse)
        else:
            img_title = 'cosplay'
            title = ''
            img_url = ''
            img_url = response.xpath('//div[@class="yp_context"]//img//@src').extract_first()
            title = response.xpath('//div[@class="yp_context"]//img//@alt').extract_first()
            title = validateTitle(title)
            item = CosplayItem()
            item['img_title'] = img_title
            item['title'] = title
            item['img_url'] = img_url
            yield item
