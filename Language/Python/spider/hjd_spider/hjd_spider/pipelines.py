# -*- coding: utf-8 -*-

# Define your item pipelines here
#
# Don't forget to add your pipeline to the ITEM_PIPELINES setting
# See: https://doc.scrapy.org/en/latest/topics/item-pipeline.html
import scrapy
from scrapy.pipelines.images import ImagesPipeline
from scrapy.exceptions import DropItem
import os
from .settings import IMAGES_STORE


class HjdSpiderPipeline(ImagesPipeline):
    def get_media_requests(self, item, info):
        # for image_url in item['image_urls']:
        yield scrapy.Request(item['image_urls'])

    def item_completed(self, results, item, info):
        image_paths = [x['path'] for ok, x in results if ok]
        if not image_paths:
            raise DropItem("Item contains no images")
        # 重命名
        dir = ''
        first_title = item['first_title']
        second_title = item['second_title']
        third_title = item['third_title']
        page = item['page']
        time = item['time']
        title = item['title']

        path = IMAGES_STORE + first_title + '/'
        if first_title != '' and os.path.exists(path) == False:
            os.mkdir(path)
        path = path + second_title + '/'
        if second_title != '' and os.path.exists(path) == False:
            os.mkdir(path)
        path = path + third_title + '/'
        if third_title != '' and os.path.exists(path) == False:
            os.mkdir(path)
        path = path + page + '/'
        if page != '' and os.path.exists(path) == False:
            os.mkdir(path)
        path = path + time + '/'
        if time != '' and os.path.exists(path) == False:
            os.mkdir(path)
        path = path + title + '/'
        if title != '' and os.path.exists(path) == False:
            os.mkdir(path)
        dir = path
        os.rename(IMAGES_STORE+image_paths[0],
                  dir + item['index'] + '.jpg')
        item['image_paths'] = dir + item['index'] + '.jpg'
        return item

    def create_mult_dir(self, item):

        return path
