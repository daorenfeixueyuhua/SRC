# -*- coding: utf-8 -*-

# Define here the models for your scraped items
#
# See documentation in:
# https://doc.scrapy.org/en/latest/topics/items.html

import scrapy


class HjdSpiderItem(scrapy.Item):
    # define the fields for your item here like:
    # name = scrapy.Field()
    # 第一级标题
    first_title = scrapy.Field()
    # 第二级标题
    second_title = scrapy.Field()
    # 第三级标题
    third_title = scrapy.Field()
    # 图片标题
    title = scrapy.Field()
    # picture dowmload path
    image_urls = scrapy.Field()
    # pitcure dir
    image_paths = scrapy.Field()
    # picture index
    index = scrapy.Field()
    # picture update time
    time = scrapy.Field()
    # page index
    page = scrapy.Field()
    ref = scrapy.Field()
