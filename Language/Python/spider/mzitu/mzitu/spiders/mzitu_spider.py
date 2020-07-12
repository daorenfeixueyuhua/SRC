# -*- coding: utf-8 -*-
import scrapy
import re
from mzitu.tool.redisTool import RedisTool
from mzitu.items import *


def validateTitle(title):
    rstr = r"[\/\\\:\*\?\"\<\>\|]"  # '/ \ : * ? " < > |'
    new_title = re.sub(rstr, "_", title)  # 替换为下划线
    return new_title


class MzituSpiderSpider(scrapy.Spider):
    name = 'mzitu_spider'
    allowed_domains = ['www.mzitu.com']
    base_url = 'https://www.mzitu.com/page/{0}/'
    page_index = 1
    page_max = 246
    start_urls = [base_url.format(str(page_index))]
    # redis key and values
    complete_key = 'mzitu:mzitu:complete:urls'
    complete_values = []
    fail_key = 'mzitu:mzitu:fail:urls'
    fail_values = []
    # redis
    client = None
    host = 'localhost'
    port = 6379
    DEBUG = True

    def __init__(self):
        if self.DEBUG:
            self.page_max = 1
        self.client = RedisTool(self.host, self.port, '')
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
        if 'page' in response.url or response.url == 'https://www.mzitu.com/':
            img_urls = []
            img_urls = response.xpath('//div[@class="postlist"]/ul/li/a//@href').extract()
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
            img_id = response.url.split('/')[3]
            img_base = 'https://www.mzitu.com/{0}/{1}'.format(img_id, '{0}')
            main_meta = response.xpath('//div[@class="main-meta"]/span//text()').extract()
            category = main_meta[1]
            create_time = main_meta[2][4::]
            title = ''
            img_url = ''

            img_url = response.xpath('//div[@class="main-image"]//img//@src').extract()
            title = response.xpath('//h2[@class="main-title"]//text()').extract_first()
            title = validateTitle(title)
            if len(img_url) <= 1:
                # 会出下一定的问题
                index = 0
                index_max = 0
                try:
                    if response.url not in self.complete_values:
                        index = response.xpath('//div[@class="pagenavi"]/span//text()').extract_first()
                        if index == '…':
                            index = response.xpath('//div[@class="pagenavi"]/span//text()').extract()[1]
                        index = int(index)
                        index_max = int(response.xpath('//div[@class="pagenavi"]/a/span')[-2:-1:].get()[6:8:])
                        self.logger.info('当前img_index:{0}, 最大img_max:{1}'.format(index, str(index_max)))
                        self.logger.info('{0}有一张图片'.format(response.url))
                        for i in img_url:
                            item = MzituItem()
                            item['title'] = title
                            item['category'] = category
                            item['img_url'] = i
                            item['index'] = index
                            item['ref'] = response.url
                            item['create_time'] = create_time
                            yield item
                        self.complete_values.append(response.url)
                    else:
                        self.logger.info('{0}已经爬取过了'.format(response.url))
                    index += 1
                    if index <= index_max:
                        self.logger.info('访问{0}下一张图片from{1}'.format(img_base.format(str(index)), response.url))
                        yield scrapy.Request(img_base.format(str(index)),
                                             callback=self.parse)
                except BaseException as e:
                    self.logger.error('{0}错误：{1}'.format(response.url, e))
                    self.fail_values.append(response.url)
