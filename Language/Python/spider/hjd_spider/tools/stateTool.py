import enum
from scrapy.cmdline import execute
from tools.singleton import Singleton
class Mode(enum.Enum):
    DEBUG = 'DEBUG'
    SHELL = 'SHELL'
    RELEASE = 'RELEASE'
class State:
    page_max = 0
    def do_action(self, context):
        pass
class DebugState(State):
    def do_action(self, context):
        if context.spider_name is None or context.spider_name is '':
            raise BaseException('spider_name is None')
        mode = Mode.DEBUG.value
        file = '-'.join([mode, context.spider_name, context.time])
        args_list = list(context.getArgsList())
        print(args_list[0])
        execute(['scrapy',
                 'crawl',
                 context.spider_name,

                 '-o',
                 '../resources/{0}.json'.format(file),
                 '--logfile=../resources/{0}.log'.format(file), ])
    def setPageMax(self, page_max):
        self.page_max = page_max
class ShellState(State):
    def do_action(self, context):
        execute(['scrapy', 'shell', context.shell_url])
class ReleaseState(State):
    def do_action(self, context):
        pass
# 工厂模式
class StateFactory(Singleton):
    def getState(self, stateName: Mode):
        if stateName == Mode.DEBUG:
            return DebugState()
        if stateName == Mode.SHELL:
            return ShellState()
        if stateName == Mode.RELEASE:
            return ReleaseState()
# 状态模式
