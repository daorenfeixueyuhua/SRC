# -*- coding: utf-8 -*-
import scrapy
import urllib.parse, urllib.request
import os
from zzhlyx.settings import *
from zzhlyx.items import *


class SinglePageSpider(scrapy.Spider):
    name = 'single_page'
    allowed_domains = ['zzhlyx.com']
    start_urls = []
    m3u8_base_url = 'https://lbbf9.com'

    def __init__(self, name=None, **kwargs):
        print()
        with open(os.getcwd() + '\start_urls.txt', 'rb') as f:
            for line in f.readlines():
                self.start_urls.append(line.decode('UTF-8'))
        super().__init__(name, **kwargs)

    def parse(self, response):
        # item = self.get_item(response)
        # yield item

        for item in self.get_item(response):
            yield item

    def get_item(self, response):
        items = []
        # try:
        self.logger.info(msg='获取真实m3u8TS下载地址')
        title = response.xpath('//h2[@class="sitetitle"]//text()').extract_first()
        m3ud8_url = response.xpath('//div[@id="player"]/script//text()').extract_first()
        m3ud8_url = m3ud8_url.split(',')[6].split("('")[1].split("')")[0]

        m3ud8_url = urllib.parse.unquote(m3ud8_url).split('$')[1]
        base_m3u8 = m3ud8_url.split('index')[0]
        data = urllib.request.urlopen(m3ud8_url)
        # self.logger.debug('第一层m3u8文件内容 {0}'.format(data.read().decode('UTF-8').split('\n')))
        m3ud8_url = data.read().decode('UTF-8').split('\n')[2]
        if base_m3u8.split('/')[3] in m3ud8_url:
            m3ud8_url = self.m3u8_base_url + m3ud8_url
        else:
            m3ud8_url = base_m3u8 + m3ud8_url
        self.logger.info(msg='真实地址：{0}'.format(m3ud8_url))
        data = urllib.request.urlopen(m3ud8_url)
        ts_urls = data.read().decode('UTF-8').split('\n')
        for i in range(len(ts_urls)):
            if '#' not in ts_urls[i] and ts_urls[i] != '':
                if 'hls/' not in ts_urls[i]:
                    ts_urls[i] = '1000k/hls/' + ts_urls[i]
                item = ZzhlyxItem()
                item['title'] = title
                item['m3u8_url'] = m3ud8_url
                item['index'] = str(i).zfill(6)
                # todo 得不到正确的ts地址
                # https://qq.com-ixx-qq.com/20200427/8960_112045cf/s
                print(base_m3u8, ts_urls[i])
                # 避免出现m3u8中提取的ts文件url，base_m3u8 中已经存在
                if base_m3u8.split('/')[3] in ts_urls[i]:
                    item['ts_urls'] = self.m3u8_base_url + ts_urls[i]
                else:
                    item['ts_urls'] = base_m3u8 + ts_urls[i]
                # ts_urls[i] = self.m3u8_base_url + ts_urls[i]
                items.append(item)
        self.logger.debug(msg=ts_urls[:2:])

        # except BaseException as e:
        #     self.logger.debug(msg='出现错误 {0}'.format(e))
        # else:
        #     self.logger.debug(msg=ts_urls[:2:])
        return items
