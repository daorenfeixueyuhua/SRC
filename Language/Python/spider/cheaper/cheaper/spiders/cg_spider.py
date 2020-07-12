# -*- coding: utf-8 -*-
import scrapy
from cheaper.items import CheaperItem


class CgSpiderSpider(scrapy.Spider):
    name = 'cg_spider'
    allowed_domains = ['18comic.fun', 'cdn-msp.cheaper.work']
    # 第一个为测试页面，好像如果从文件里面加载多个url，第一个url会得不到东西

    start_urls = ['https://18comic.fun']
    complete_urls = []
    fail_urls = []
    download = 'http://cdn-msp.cheaper.fun/media/photos/{0}/{1}.jpg'
    max_page = 0

    def __init__(self, name=None, **kwargs):
        super().__init__(name, **kwargs)
        with open('../resource/complete.txt', 'r') as file:
            for line in file.readlines():
                if 'http' in line or 'https' in line:
                    self.complete_urls.append(line)

        with open('../resource/start_urls.txt', 'r') as file:
            for line in file.readlines():
                if 'http' in line or 'https' in line:
                    if line not in self.complete_urls:
                        # 考虑去除'\n'
                        # line.replace('\n', '')
                        self.start_urls.append(line)
                    # else:
                    #     self.logger.info('{0}已被爬取'.format(line))
        self.logger.info('start_urls: {0}'.format(self.start_urls))

    def parse(self, response):
        try:
            img_id = response.url.split('/')[4]
            title = response.xpath('//span[@class="top-comname"]//text()').extract_first()
            if title is not None or title != '':
                title = title.split('|')[0].split('/')[0]
            else:
                self.logger.error(msg='{0} 该页面不可爬取'.format(response.url))
                return
            # title需要进行一次清洗，防止出现特殊字符
            max_page = response.xpath('//select[@id="pageselect"]//option[@value="0"]//text()').extract()
            if len(max_page) <= 0:
                return
            else:
                self.max_page = int(max_page[2])
            if self.max_page > 0:
                for i in range(1, self.max_page + 1):
                    item = CheaperItem()
                    item['title'] = title
                    item['index'] = str(i).zfill(5)
                    item['image_urls'] = self.download.format(img_id, item['index'])
                    yield item
            self.complete_urls.append(response.url)
        except BaseException as e:
            self.logger.error(msg='出现问题: {0}'.format(e))
            self.fail_urls.append(response.url)

    def close(spider, reason):
        super().close(spider, reason)
        spider.logger.info(msg='保存已经完成了的网页')
        with open('../resource/complete.txt', 'w') as file:
            for line in spider.complete_urls:
                file.write(line)
        spider.logger.info(msg='保存爬取失败的页面')
        with open('../resource/fail_urls.txt', 'a') as file:
            for line in spider.fail_urls:
                file.write(line + '\n')
        spider.logger.info('fail_urls: {0}'.format(spider.start_urls))

        spider.logger.info('清除start_urls.txt')
        with open('../resource/start_urls.txt', 'r+') as file:
            file.seek(0)
            # 清空文件
            file.truncate()
