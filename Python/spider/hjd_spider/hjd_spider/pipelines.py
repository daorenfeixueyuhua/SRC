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
        dir = IMAGES_STORE + item['title'] + '/'
        if os.path.exists(dir) == False:
            os.mkdir(dir)
        os.rename(IMAGES_STORE+image_paths[0],
                  dir + str(item['index']) + '.jpg')
        item['image_paths'] = image_paths[0]
        return item
