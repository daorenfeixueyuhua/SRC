# -*- coding: utf-8 -*-

<<<<<<< HEAD
# Scrapy settings for hjd_spider project
=======
# Scrapy settings for weibo project
>>>>>>> c58ecc4d435ea0785344b0f88d3f36ae3e078cfb
#
# For simplicity, this file contains only settings considered important or
# commonly used. You can find more settings consulting the documentation:
#
#     https://doc.scrapy.org/en/latest/topics/settings.html
#     https://doc.scrapy.org/en/latest/topics/downloader-middleware.html
#     https://doc.scrapy.org/en/latest/topics/spider-middleware.html

<<<<<<< HEAD
BOT_NAME = 'hjd_spider'

=======
BOT_NAME = 'weibo'

<<<<<<< HEAD:Language/Python/spider/weibo/weibo/settings.py
SPIDER_MODULES = ['weibo.spiders']
NEWSPIDER_MODULE = 'weibo.spiders'
=======
>>>>>>> c58ecc4d435ea0785344b0f88d3f36ae3e078cfb
IMAGES_STORE = 'C:\sources\hjd\img/'

SPIDER_MODULES = ['hjd_spider.spiders']
NEWSPIDER_MODULE = 'hjd_spider.spiders'
<<<<<<< HEAD

# Crawl responsibly by identifying yourself (and your website) on the user-agent
# USER_AGENT = 'hjd_spider (+http://www.yourdomain.com)'
=======
>>>>>>> c58ecc4d435ea0785344b0f88d3f36ae3e078cfb:Language/Python/spider/hjd_spider/hjd_spider/settings.py


# Crawl responsibly by identifying yourself (and your website) on the user-agent
#USER_AGENT = 'weibo (+http://www.yourdomain.com)'
>>>>>>> c58ecc4d435ea0785344b0f88d3f36ae3e078cfb

# Obey robots.txt rules
ROBOTSTXT_OBEY = False

# Configure maximum concurrent requests performed by Scrapy (default: 16)
<<<<<<< HEAD
CONCURRENT_REQUESTS = 32
=======
#CONCURRENT_REQUESTS = 32
>>>>>>> c58ecc4d435ea0785344b0f88d3f36ae3e078cfb

# Configure a delay for requests for the same website (default: 0)
# See https://doc.scrapy.org/en/latest/topics/settings.html#download-delay
# See also autothrottle settings and docs
<<<<<<< HEAD
""" 启用限速设置 """
AUTOTHROTTLE_ENABLED = False
DOWNLOAD_DELAY = 0  # 每次请求间隔时间
# The download delay setting will honor only one of:
# CONCURRENT_REQUESTS_PER_DOMAIN = 16
# CONCURRENT_REQUESTS_PER_IP = 16


# Disable cookies (enabled by default)
# COOKIES_ENABLED = False

# Disable Telnet Console (enabled by default)
# TELNETCONSOLE_ENABLED = False

# Override the default request headers:
DEFAULT_REQUEST_HEADERS = {
    'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8',
    'Accept-Language': 'en',
}

# Enable or disable spider middlewares
# See https://doc.scrapy.org/en/latest/topics/spider-middleware.html
=======
#DOWNLOAD_DELAY = 3
# The download delay setting will honor only one of:
#CONCURRENT_REQUESTS_PER_DOMAIN = 16
#CONCURRENT_REQUESTS_PER_IP = 16

# Disable cookies (enabled by default)
#COOKIES_ENABLED = False

# Disable Telnet Console (enabled by default)
#TELNETCONSOLE_ENABLED = False

# Override the default request headers:
# DEFAULT_REQUEST_HEADERS = {
#   'Accept': 'text/html,application/xhtml+xml,application/xml;q=0.9,*/*;q=0.8',
#   'Accept-Language': 'en',
# }

# Enable or disable spider middlewares
# See https://doc.scrapy.org/en/latest/topics/spider-middleware.html
<<<<<<< HEAD:Language/Python/spider/weibo/weibo/settings.py
#SPIDER_MIDDLEWARES = {
#    'weibo.middlewares.WeiboSpiderMiddleware': 543,
#}

# Enable or disable downloader middlewares
# See https://doc.scrapy.org/en/latest/topics/downloader-middleware.html
#DOWNLOADER_MIDDLEWARES = {
#    'weibo.middlewares.WeiboDownloaderMiddleware': 543,
#}
=======
>>>>>>> c58ecc4d435ea0785344b0f88d3f36ae3e078cfb
# SPIDER_MIDDLEWARES = {
#     'hjd_spider.middlewares.HjdSpiderSpiderMiddleware': 543,
# }

# Enable or disable downloader middlewares
# See https://doc.scrapy.org/en/latest/topics/downloader-middleware.html
<<<<<<< HEAD
DOWNLOADER_MIDDLEWARES = {
    # 'hjd_spider.middlewares.HjdSpiderDownloaderMiddleware': 543,
    # 'hjd_spider.middlewares.ProxyMiddleware': 200,
}
=======
# DOWNLOADER_MIDDLEWARES = {
#    'hjd_spider.middlewares.HjdSpiderDownloaderMiddleware': 543,
# }
>>>>>>> c58ecc4d435ea0785344b0f88d3f36ae3e078cfb:Language/Python/spider/hjd_spider/hjd_spider/settings.py

>>>>>>> c58ecc4d435ea0785344b0f88d3f36ae3e078cfb
# Enable or disable extensions
# See https://doc.scrapy.org/en/latest/topics/extensions.html
# EXTENSIONS = {
#    'scrapy.extensions.telnet.TelnetConsole': None,
# }

# Configure item pipelines
# See https://doc.scrapy.org/en/latest/topics/item-pipeline.html
<<<<<<< HEAD
ITEM_PIPELINES = {
    # 'hjd_spider.pipelines.HjdSpiderPipeline': 300,
    'hjd_spider.pipelines.NetMeiNvPipeline': 301
}
#
# FEED_FORMAT = 'json'  # 输出格式
# FEED_EXPORTERS_BASE = {
#     'json': 'scrapy.exporters.JsonItemExporter',
#     'jsonlines': 'scrapy.exporters.JsonLinesItemExporter',
# }

# Enable and configure the AutoThrottle extension (disabled by default)
# See https://doc.scrapy.org/en/latest/topics/autothrottle.html
# AUTOTHROTTLE_ENABLED = True
# The initial download delay
# AUTOTHROTTLE_START_DELAY = 5
# The maximum download delay to be set in case of high latencies
# AUTOTHROTTLE_MAX_DELAY = 60
# The average number of requests Scrapy should be sending in parallel to
# each remote server
# AUTOTHROTTLE_TARGET_CONCURRENCY = 1.0
# Enable showing throttling stats for every response received:
# AUTOTHROTTLE_DEBUG = False

# Enable and configure HTTP caching (disabled by default)
# See https://doc.scrapy.org/en/latest/topics/downloader-middleware.html#httpcache-middleware-settings
# HTTPCACHE_ENABLED = True
# HTTPCACHE_EXPIRATION_SECS = 0
# HTTPCACHE_DIR = 'httpcache'
# HTTPCACHE_IGNORE_HTTP_CODES = []
# HTTPCACHE_STORAGE = 'scrapy.extensions.httpcache.FilesystemCacheStorage'
=======
<<<<<<< HEAD:Language/Python/spider/weibo/weibo/settings.py
#ITEM_PIPELINES = {
#    'weibo.pipelines.WeiboPipeline': 300,
#}
=======
ITEM_PIPELINES = {
    'hjd_spider.pipelines.HjdSpiderPipeline': 300,
}
>>>>>>> c58ecc4d435ea0785344b0f88d3f36ae3e078cfb:Language/Python/spider/hjd_spider/hjd_spider/settings.py

# Enable and configure the AutoThrottle extension (disabled by default)
# See https://doc.scrapy.org/en/latest/topics/autothrottle.html
#AUTOTHROTTLE_ENABLED = True
# The initial download delay
#AUTOTHROTTLE_START_DELAY = 5
# The maximum download delay to be set in case of high latencies
#AUTOTHROTTLE_MAX_DELAY = 60
# The average number of requests Scrapy should be sending in parallel to
# each remote server
#AUTOTHROTTLE_TARGET_CONCURRENCY = 1.0
# Enable showing throttling stats for every response received:
#AUTOTHROTTLE_DEBUG = False

# Enable and configure HTTP caching (disabled by default)
# See https://doc.scrapy.org/en/latest/topics/downloader-middleware.html#httpcache-middleware-settings
#HTTPCACHE_ENABLED = True
#HTTPCACHE_EXPIRATION_SECS = 0
#HTTPCACHE_DIR = 'httpcache'
#HTTPCACHE_IGNORE_HTTP_CODES = []
#HTTPCACHE_STORAGE = 'scrapy.extensions.httpcache.FilesystemCacheStorage'
>>>>>>> c58ecc4d435ea0785344b0f88d3f36ae3e078cfb
