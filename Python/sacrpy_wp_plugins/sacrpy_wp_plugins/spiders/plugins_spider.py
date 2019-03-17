# -*- coding: utf-8 -*-
import scrapy
import json


class PluginsSpiderSpider(scrapy.Spider):
    name = 'plugins_spider'
    allowed_domains = ['wordpress.org']
    start_urls = ['http://wordpress.org/']

    def parse(self, response):
        pass
