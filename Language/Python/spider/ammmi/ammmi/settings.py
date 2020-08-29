# -*- coding: utf-8 -*-

<<<<<<< HEAD
# Scrapy settings for ammmi project
=======
# Scrapy settings for bt7086 project
>>>>>>> c58ecc4d435ea0785344b0f88d3f36ae3e078cfb
#
# For simplicity, this file contains only settings considered important or
# commonly used. You can find more settings consulting the documentation:
#
#     https://doc.scrapy.org/en/latest/topics/settings.html
#     https://doc.scrapy.org/en/latest/topics/downloader-middleware.html
#     https://doc.scrapy.org/en/latest/topics/spider-middleware.html

<<<<<<< HEAD
BOT_NAME = 'ammmi'

SPIDER_MODULES = ['ammmi.spiders']
NEWSPIDER_MODULE = 'ammmi.spiders'

# Crawl responsibly by identifying yourself (and your website) on the user-agent
# USER_AGENT = 'ammmi (+http://www.yourdomain.com)'
=======
BOT_NAME = 'bt7086'

IMAGES_STORE = 'C:\sources\\bt7086\img/'
ITEM_STORE = 'C:\sources\\bt7086/'

SPIDER_MODULES = ['bt7086.spiders']
NEWSPIDER_MODULE = 'bt7086.spiders'

DOWNLOAD_FAIL_ON_DATALOSS = False

# Crawl responsibly by identifying yourself (and your website) on the user-agent
#USER_AGENT = 'bt7086 (+http://www.yourdomain.com)'
>>>>>>> c58ecc4d435ea0785344b0f88d3f36ae3e078cfb

# Obey robots.txt rules
ROBOTSTXT_OBEY = False

# Configure maximum concurrent requests performed by Scrapy (default: 16)
<<<<<<< HEAD
CONCURRENT_REQUESTS = 64
=======
#CONCURRENT_REQUESTS = 32
>>>>>>> c58ecc4d435ea0785344b0f88d3f36ae3e078cfb

# Configure a delay for requests for the same website (default: 0)
# See https://doc.scrapy.org/en/latest/topics/settings.html#download-delay
# See also autothrottle settings and docs
<<<<<<< HEAD
DOWNLOAD_DELAY = 0.2
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
>>>>>>> c58ecc4d435ea0785344b0f88d3f36ae3e078cfb

# Enable or disable spider middlewares
# See https://doc.scrapy.org/en/latest/topics/spider-middleware.html
# SPIDER_MIDDLEWARES = {
<<<<<<< HEAD
#    'ammmi.middlewares.AmmmiSpiderMiddleware': 543,
=======
#    'bt7086.middlewares.Bt7086SpiderMiddleware': 543,
>>>>>>> c58ecc4d435ea0785344b0f88d3f36ae3e078cfb
# }

# Enable or disable downloader middlewares
# See https://doc.scrapy.org/en/latest/topics/downloader-middleware.html
# DOWNLOADER_MIDDLEWARES = {
<<<<<<< HEAD
#    'ammmi.middlewares.AmmmiDownloaderMiddleware': 543,
=======
#    'bt7086.middlewares.Bt7086DownloaderMiddleware': 543,
>>>>>>> c58ecc4d435ea0785344b0f88d3f36ae3e078cfb
# }

# Enable or disable extensions
# See https://doc.scrapy.org/en/latest/topics/extensions.html
# EXTENSIONS = {
#    'scrapy.extensions.telnet.TelnetConsole': None,
# }

# Configure item pipelines
# See https://doc.scrapy.org/en/latest/topics/item-pipeline.html
ITEM_PIPELINES = {
<<<<<<< HEAD
    # 'ammmi.pipelines.AmmmiPipeline': 300,
    # 'ammmi.pipelines.AmmmiImagesPipeline': 300,
    # 'ammmi.pipelines.ColplayImagePipeline': 300,
    'ammmi.pipelines.DongmantupianPipelines': 300,
}
IMAGES_STORE = "C:\\sources\\ammmi\\img\\"

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
    'bt7086.pipelines.Bt7086Pipeline': 300,
    # 测试失败，还是无法进行保存
    # 'bt7086.pipelines.Bt7086JSONPipeline': 400,
}

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
