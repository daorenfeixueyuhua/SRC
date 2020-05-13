# -*- coding: utf-8 -*-

# Define here the models for your scraped items
#
# See documentation in:
# https://doc.scrapy.org/en/latest/topics/items.html

import scrapy


class ZzhlyxItem(scrapy.Item):
    # define the fields for your item here like:
    # name = scrapy.Field()
    title = scrapy.Field()
    m3u8_url = scrapy.Field()
    ts_urls = scrapy.Field()
    index = scrapy.Field()
    path = scrapy.Field()
    pass
