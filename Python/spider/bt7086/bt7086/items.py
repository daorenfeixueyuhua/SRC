# -*- coding: utf-8 -*-

# Define here the models for your scraped items
#
# See documentation in:
# https://doc.scrapy.org/en/latest/topics/items.html

import scrapy


class Bt7086Item(scrapy.Item):
    # define the fields for your item here like:
    # name = scrapy.Field()
    title = scrapy.Field()
    image_urls = scrapy.Field()
    image_paths = scrapy.Field()
    cur_time = scrapy.Field()
    index = scrapy.Field()
    pass
