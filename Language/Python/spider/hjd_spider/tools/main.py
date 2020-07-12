from tools.spiderTool import *

if __name__ == '__main__':
    spider_name = 'net_meinv'
    args_list = []
    state = StateFactory.getState(Mode.DEBUG)
    spiderTool = SpiderTool()
    # debug mode
    spiderTool.setstate(state=state)
    spiderTool.set_spider_name(spider_name)
    spiderTool.addArgs(Args('page_index', 2))
    state.do_action(spiderTool)

    # shell mode
    # spiderTool.set_shellUrl('https://hjd.niao2048.biz/2048/read.php?tid-2127862.html')
    # spiderTool.setstate(shell)
    # shell.do_action(spiderTool)
