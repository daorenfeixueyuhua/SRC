from tools.spiderTool import *

if __name__ == '__main__':
    spider_name = 'net_meinv'
    debug = DebugState()
    shell = ShellState()
    spiderTool = SpiderTool()
    # debug mode
    # spiderTool.setstate(state=debug)
    # spiderTool.set_spider_name(spider_name)
    # debug.do_action(spiderTool)

    # shell mode
    # spiderTool.set_shellUrl('https://hjd.niao2048.biz/2048/read.php?tid-2127862.html')
    # spiderTool.setstate(shell)
    # shell.do_action(spiderTool)
