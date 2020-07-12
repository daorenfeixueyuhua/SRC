from tools.stateTool import *
from datetime import date
from tools.argsTool import Args
from tools.singleton import Singleton
from tools.redisTool import RedisTool


# 
class SpiderTool(Singleton):
    spider_name = None
    shell_url = None
    time = None
    state = None
    args_list = []
    cmd = []
    page_id = None
    __host = ''
    __port = None
    page_index = 1
    page_max = 1
    client = None
    complate_key = 'hjd:{0}:complete:urls'
    fail_key = 'hjd:{0}:fail:urls'

    def loadRedis(self):
        self.__host = 'localhost'
        self.__port = 6379
        self.client = RedisTool(self.__host, self.__port)

    def __int__(self, spider_name: str = None,
                shell_url: str = None, ) -> None:
        self.spider_name = spider_name
        self.shell_url = shell_url
        self.time = date.today().isoformat()
        self.state = None
        self.page_index = 1
        self.page_id = ''
        self.setPageMax()
        self.loadRedis()

    def setstate(self, state: State):
        self.state = state

    def getstate(self) -> State:
        return self.state

    def set_spider_name(self, spider_name: str):
        self.spider_name = spider_name

    def get_spider_name(self) -> str:
        return self.spider_name

    def set_shellUrl(self, url: str):
        self.shell_url = url

    def get_shellUrl(self) -> str:
        return self.shell_url

    def set_time(self, time: str = None):
        if time is None:
            time = date.today().isoformat()

    def setArgsList(self, args_list: list):
        self.args_list = args_list

    def getArgsList(self):
        return self.args_list

    def addArgs(self, args: Args):
        self.args_list.append(args)

    def setPageIndex(self, page_index):
        self.page_index = page_index

    def getPageIndex(self):
        return self.page_index

    def setPageMax(self,):
        self.page_max = self.getstate().page_max

    def getPageMax(self,):
        return self.page_max

    def setPageId(self, page_id):
        self.page_id = page_id

    def getPageId(self,):
        return self.page_id
