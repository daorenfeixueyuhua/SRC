# -*- coding: utf-8 -*-
import scrapy
import re
import redis
import os
from buxiuse.tool.redis_tool import RedisTool
from scrapy.selector import Selector
import re
from buxiuse.items import *


def validateTitle(title):
    rstr = r"[\/\\\:\*\?\"\<\>\|]"  # '/ \ : * ? " < > |'
    new_title = re.sub(rstr, "_", title)  # 替换为下划线
    return new_title


class BuxiuseSpiderSpider(scrapy.Spider):
    name = 'buxiuse_spider'
    allowed_domains = ['www.buxiuse.com']
    base_url = 'https://www.buxiuse.com/?page={0}'
    page_index = 1
    # 5039
    page_max = 5039
    start_urls = [base_url.format(str(page_index))]
    complete_key = 'buxiuse:complete:urls'
    complete_values = []
    fail_key = 'buxiuse:fail:urls'
    fail_values = []
    redis_host = 'localhost'
    redis_port = 6379
    client = None
    DEBUG = False
    title_set = {}

    def __init__(self, name=None, **kwargs):
        if self.DEBUG:
            self.page_max = 1
        self.client = RedisTool(self.redis_host, self.redis_port, '')
        self.complete_values = self.client.sremenber(self.complete_key)
        super().__init__(name, **kwargs)

    def close(spider, reason):
        spider.client.sadd(spider.complete_key, spider.complete_values)
        spider.client.close()

    def parse(self, response):
        url = response.url
        self.logger.info('访问：{0}'.format(response.url))
        if 'page' in url:
            self.logger.info('获取页面{0}中的图片链接'.format(url))
            img_selector = response.xpath('//img[@class="height_min"]')
            title = ''
            img_url = ''
            for selector in img_selector:
                try:
                    tmp = selector.get().split(' ')[3::2]
                    img_url = tmp[1].split('"')[1]
                    title = tmp[0].split('"')[1]
                    if img_url in self.complete_values:
                        self.logger.info('{0}已完成'.format(img_url))
                        continue
                    if not title or not img_url:
                        continue
                    if '#' in title:
                        title = title.split('#')[1]
                    title = validateTitle(title)
                    title_value = self.title_set.get(title)
                    if title_value == None:
                        title_value = 0
                    self.title_set[title] = title_value + 1
                    title = title + str(self.title_set.get(title))
                    ref = response.url
                    item = BuxiuseItem()
                    item['title'] = title
                    item['img_url'] = img_url
                    item['ref'] = ref
                    self.complete_values.append(item['img_url'])
                    yield item
                except BaseException as e:
                    self.logger.error('{0}:出现问题:{1}'.format(selector.get(),
                                                            e))
                    self.fail_values.append(img_url)

        # 访问下一页
        self.page_index += 1
        if self.page_index < self.page_max:
            yield scrapy.Request(url=self.base_url.format(str(self.page_index)),
                                 callback=self.parse)
