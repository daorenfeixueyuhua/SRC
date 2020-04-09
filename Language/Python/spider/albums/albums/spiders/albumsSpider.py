# -*- coding: utf-8 -*-
import scrapy
import selectors

from albums.items import AlbumsItem


class AlbumsspiderSpider(scrapy.Spider):
    name = 'albumsSpider'
    allowed_domains = ['https://7.n15.info/']
    start_urls = ['https://7.n15.info/albums/']
    index = 1
    base_url = 'https://7.n15.info/albums'
    max_index = 2

    def parse(self, response):
        # 爬取图片菜单
        # response.xpath('//div[@class="photo-elem"]//a[@class="title text-sub-title mt-2 mb-3"]/text()').extract()
        imgList = response.xpath('//div[@class="photo-elem"]//a[@class="title text-sub-title mt-2 mb-3"]/@href').extract()
        for img in imgList:
            print(img)
            yield scrapy.Request('https://7.n15.info/' + img, dont_filter=True)


        # response.xpath('//div[@class="photo-elem"]//a[@class="title text-sub-title mt-2 mb-3"]/@href').extract()

        # response.xpath('//div[@class="photoList container-fluid"]//div[@class="img col-60"]/img').extract()

        # title
        # response.xpath('//div[@class="title color-black"]/text()').extract()
        # response.xpath('//img[@class="lazy"]/@data-original').extract()
        # https://img.slxstatic.com/photo/c9/c9-2IdAk91543644554/3.jpg

        img_url_list = response.xpath('//img[@class="lazy"]/@data-original').extract()
        for img_url in img_url_list:
            item = AlbumsItem()
            item['url'] = 'https:' + img_url
            item['title'] = response.xpath('//div[@class="title color-black"]/text()').extract()
            item['index'] = item['url'][:0:-1]
            print(item['url'], item['title'], item['index'])
            yield item


        # next page
        if self.max_index <= self.index:
            return

        self.index += 1

        yield scrapy.Request(self.base_url + '?page='
                             + str(self.index),
                             callback=self.parse)
