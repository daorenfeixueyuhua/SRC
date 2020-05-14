from tools.stateTool import *
from datetime import date


class SpiderTool:
    spider_name = None
    shell_url = None
    time = None
    state = None

    def __int__(self, spider_name: str = None,
                shell_url: str = None, ) -> None:
        self.spider_name = spider_name
        self.shell_url = shell_url
        self.time = date.today().isoformat()
        self.state = None

    def __init__(self):
        self.time = date.today().isoformat()

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
