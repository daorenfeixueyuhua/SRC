from scrapy import Request
import re
from tools.spiderTool import SpiderTool
from hjd_spider.items import HjdSpiderItem


def validateTitle(title):
    rstr = r"[\/\\\:\*\?\"\<\>\|]"  # '/ \ : * ? " < > |'
    new_title = re.sub(rstr, "_", title)  # 替换为下划线
    return new_title


class ParseHandler(object):
    rules = []
    spider = SpiderTool()

    def __init__(self, successor=None):
        self._successor = successor

    def setSuccessor(self, successor):
      self.__successor = successor

    def setRules(self, rules):
        self.rules = rules

    def handle(self, request):
        res = self._handle(request)
        if not res:
            self._successor.handle(request)

    def _handle(self, request):
        raise NotImplementedError('Must provide implementation in subclass.')


class ImgUrlParse(ParseHandler):
  def _handle(self, request):
      url = request.url
      for i in self.rules:
        if i in url:
          self.spider.logger.info(msg='获取{0}内的图片连接'.format(request.url))
          img_urls = request.xpath('//td[@class="tal"]/a//@href').extract()
          for img_url in img_urls:
                # Filtered offsite request to 报错，解决方案：设置 dont_filter=True
                yield Request(self.img_base_url + img_url, callback=self.parse, dont_filter=True)
          self.logger.info(msg='获取图片链接成功')
            # 不加限制一直死循环
          self.spider.page_index += 1
          if self.page_index <= self.page_max:
              self.logger.info(msg='访问url: {0}'.format(
                  self.next_base_url.format(str(self.page_index))))
              yield Request(self.next_base_url.format(str(self.page_index)), callback=self.parse)
      return super()._handle(request)


class ImgInfoParse(ParseHandler):
  def _handle(self, request):

    return super()._handle(request)


class ItemParse(ParseHandler):
  	def _handle(self, request):
		self.spider.logger.info('访问{0}'.format(request.url))
    	try:
        	if request.url in self.spider.complete_urls:
            	self.spider.logger.info('{0}已经被爬取过了'.format(request.url))
                	return
                self.spider.logger.info('获取{0}内的item信息'.format(request.url))
                # 获取图片信息
                titles = request.xpath(
                    '//div[@id="breadCrumb"]//a//text()').extract()
                # print("标题", titles)
                self.spider.logger.info('标题:【{0}】'.format(titles))
                first_title = titles[0]
                # // 缺值处理
                if first_title == None or first_title == '':
                    first_title = 'Defualt'
                second_title = titles[1]
                if second_title == None or second_title == '':
                    second_title = 'Defualt'
                third_title = titles[2]
                if third_title == None or third_title == '':
                    third_title = 'Defualt'
                time = request.xpath(
                    '//span[@class="fl gray"]//@title').extract_first()
                if time == None or time == '':
                    time = '2020-01-01 00:00:00'
                page = ''
                # 获取图片的链接
                title = titles[3]
                # 文件名清洗
                title = validateTitle(title)
                # title = request.xpath('//h1[@id="subject_tpc"]//text()').extract()[0]
                ptc_url_list = request.xpath(
                    '//div[@id="read_tpc"]/img/@src').extract()
                if len(ptc_url_list) == 0:
                    ptc_url_list = request.xpath(
                        '//div[@id="read_tpc"]//img/@src').extract()
                index = 1
                for url in ptc_url_list:
                    item = HjdSpiderItem()
                    item['first_title'] = first_title
                    item['second_title'] = second_title
                    item['third_title'] = third_title
                    item['time'] = time
                    item['page'] = str(self.page_index)
                    item['image_urls'] = url
                    item['title'] = title
                    item['index'] = str(index)
                    item['ref'] = request.url
                    index += 1
                    self.img_num += 1
                    yield item
                # 需要对redis中 hjd:276:complete:urls 进行清理
                self.complete_urls.append(request.url)
            except BaseException as e:
                self.fail_urls.append(request.url)
                self.logger.error('{0}出现问题：{1}'.format(request.url, e))

    return super()._handle(request)
