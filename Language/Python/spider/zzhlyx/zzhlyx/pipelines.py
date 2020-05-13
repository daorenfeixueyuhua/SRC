# -*- coding: utf-8 -*-

# Define your item pipelines here
#
# Don't forget to add your pipeline to the ITEM_PIPELINES setting
# See: https://doc.scrapy.org/en/latest/topics/item-pipeline.html
import logging
from scrapy.pipelines.media import *
from scrapy.pipelines.images import *
from scrapy.pipelines.files import *
from zzhlyx.settings import *


class ZzhlyxPipeline(FilesPipeline):

    def item_completed(self, results, item, info):
        # logger.info('results:', results)
        # logging.info(msg='pipelines------------------')
        # logging.info(msg=item)
        title = item['title']
        path = ''
        if title != '':
            path = FILES_STORE + title + '/'
            if not os.path.exists(path):
                os.mkdir(path)

        hash_path = results[0][1]['path']
        os.rename(FILES_STORE + hash_path, path + item['index'] + '.ts')
        item['path'] = path + item['index'] + '.ts'
        return item
