# -*- coding: utf-8 -*-

# Define your item pipelines here
#
# Don't forget to add your pipeline to the ITEM_PIPELINES setting
# See: https://doc.scrapy.org/en/latest/topics/item-pipeline.html
import scrapy
from scrapy.exceptions import DropItem
import os
from scrapy.utils.project import get_project_settings
from scrapy.pipelines.images import ImagesPipeline
from .settings import *


class BuxiusePipeline(ImagesPipeline):
    def get_media_requests(self, item, info):
        yield scrapy.Request(item['img_url'])

    def item_completed(self, results, item, info):
        image_paths = [x['path'] for ok, x in results if ok]
        if not image_paths:
            raise DropItem("Item contains no images")
        # rename
        dir = ''
        title = item['title']
        path = IMAGES_STORE + title
        suffix = os.path.splitext(IMAGES_STORE + image_paths[0])[1]
        os.rename(os.path.join(IMAGES_STORE, image_paths[0]), path + suffix)
        item['img_path'] = path + suffix
        return item
