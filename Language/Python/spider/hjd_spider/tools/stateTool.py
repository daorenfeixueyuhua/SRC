import enum
from scrapy.cmdline import execute


class Mode(enum.Enum):
    DEBUG = 'DEBUG'
    SHELL = 'SHELL'
    RELEASE = 'RELEASE'


class State:

    def do_action(self, context):
        pass


class DebugState(State):

    def do_action(self, context):
        if context.spider_name is None or context.spider_name is '':
            raise BaseException('spider_name is None')
        mode = Mode.DEBUG.value
        file = '-'.join([mode, context.spider_name, context.time])
        execute(['scrapy',
                 'crawl',
                 context.spider_name,
                 '-o',
                 '../resources/{0}.json'.format(file),
                 '--logfile=../resources/{0}.log'.format(file)])


class ShellState(State):
    def do_action(self, context):
        execute(['scrapy', 'shell', context.shell_url])


class ReleaseState(State):
    def do_action(self, context):
        pass
