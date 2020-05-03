# -*- coding: utf-8 -*-

# Define your item pipelines here
#
# Don't forget to add your pipeline to the ITEM_PIPELINES setting
# See: https://doc.scrapy.org/en/latest/topics/item-pipeline.html
from scrapy.pipelines.images import ImagesPipeline, DropItem
import os
from .settings import IMAGES_STORE
import scrapy

class CheaperPipeline(ImagesPipeline):
    def get_media_requests(self, item, info):
        # for image_url in item['image_urls']:
        yield scrapy.Request(item['image_urls'])

    def item_completed(self, results, item, info):
        image_paths = [x['path'] for ok, x in results if ok]
        if not image_paths:
            raise DropItem("Item contains no images")
        # 重命名
        title = item['title']

        path = IMAGES_STORE + title + '/'
        if title != '' and os.path.exists(path) == False:
            os.mkdir(path)
        dir = path
        os.rename(IMAGES_STORE+image_paths[0],
                  dir + item['index'] + '.jpg')
        item['image_paths'] = dir + item['index'] + '.jpg'
        return item
