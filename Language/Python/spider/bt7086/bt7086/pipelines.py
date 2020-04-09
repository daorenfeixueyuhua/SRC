# -*- coding: utf-8 -*-

# Define your item pipelines here
#
# Don't forget to add your pipeline to the ITEM_PIPELINES setting
# See: https://doc.scrapy.org/en/latest/topics/item-pipeline.html
import scrapy
from scrapy.pipelines.images import ImagesPipeline
from scrapy.exceptions import DropItem
import os
import codecs
import json
from .settings import IMAGES_STORE, ITEM_STORE


class Bt7086Pipeline(ImagesPipeline):
    def get_media_requests(self, item, info):
        # for image_url in item['image_urls']:
        yield scrapy.Request(item['image_urls'])

    def item_completed(self, results, item, info):
        image_paths = [x['path'] for ok, x in results if ok]
        if not image_paths:
            raise DropItem("Item contains no images")
        # 重命名
        dir = IMAGES_STORE + item['cur_time'][0:10:] + '/'
        if os.path.exists(dir) == False:
            os.mkdir(dir)
        dir = dir + item['title'] + '/'
        if os.path.exists(dir) == False:
            os.mkdir(dir)
        os.rename(IMAGES_STORE+image_paths[0],
                  dir + str(item['index']) + '.jpg')
        item['image_paths'] = dir + str(item['index']) + '.jpg'
        # 此处需要考虑，将item信息进行保存
        return item


# class Bt7086JSONPipeline(object):
#     def process_item(self, item, spider):
#         filename = ITEM_STORE + 'file/'
#         if os.path.exists(filename) is False:
#             os.mkdir(filename)
#             # 打开json文件，向里面以dumps的方式吸入数据
#             # 注意需要有一个参数ensure_ascii=False ，不然数据会直接为utf编码的方式存入比如
#             # :“/xe15”
#         filename = filename + item['cur_time'][0:10:] + '.json'
#         with codecs.open(filename, 'a+') as f:
#             line = json.dumps(dict(item), ensure_ascii=False) + '\n'
#             f.write(line)
#             f.write(',')
#         yield item
