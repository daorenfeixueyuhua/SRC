# 题1：请添加两个显示器类参与组装


class AbstractFactory(object):
    # 创建一个抽象工厂
    computer_name = ''  # 电脑名称

    def create_cpu(self):
        # 定义一个创建cpu方法具体实现由子类完成
        pass

    def create_mainboard(self):
        # 定义一个创建主板方法具体实现由子类完成
        pass

    def create_monitor(self):
        pass


class AbstractCpu(object):
    # 定义一个cpu产品抽象类
    series_name = ''
    instructions = ''
    arch = ''


class IntelCpu(AbstractCpu):
    # 定义一个Intel公司的cpu产品类，继承【cpu产品抽象类】
    def __init__(self, series):
        self.series_name = series  # 序列号名称


class AmdCpu(AbstractCpu):
    # 定义一个Amd公司的cpu产品类，继承【cpu产品抽象类】
    def __init__(self, series):
        self.series_name = series  # 序列号名称


class AbstractMainboard(object):
    # 定义一个mainboard(主板)产品抽象类
    series_name = ''


class IntelMainboard(AbstractMainboard):
    # 定义一个Intel公司的mainboard(主板)产品类，继承【mainboard(主板)抽象类】
    def __init__(self, series):
        self.series_name = series  # 序列号名称


class AmdMainboard(AbstractMainboard):
    # 定义一个Amd公司的mainboard(主板)产品类，继承【mainboard(主板)抽象类】
    def __init__(self, series):
        self.series_name = series  # 序列号名称


class AbstractMonitor():
    size = ''


class IntelMonitor(AbstractMonitor):
    def __init__(self, _size):
        self.size = _size


class AmdMonitor(AbstractMonitor):
    def __init__(self, _size):
        self.size = _size


class IntelFactory(AbstractFactory):
        # 创建一个生产Intel公司产品的工厂，继承抽象工厂类
    computer_name = 'Intel I7-series computer '

    def create_cpu(self):
        # 在工厂里定义一个创建cpu产品方法
        return IntelCpu('I7-6500')

    def create_mainboard(self):
        # 在工厂里定义一个创建mainboard(主板)产品方法
        return IntelCpu('Intel-6000')

    def create_monitor(self):
        return IntelMonitor('4K')


class AmdFactory(AbstractFactory):
    # 创建一个生产Amd公司产品的工厂，继承抽象工厂类
    computer_name = 'Amd 4 computer '

    def create_cpu(self):
        # 在工厂里定义一个创建cpu产品方法
        return AmdCpu('amd444')

    def create_mainboard(self):
        # 在工厂里定义一个创建mainboard(主板)产品方法
        return AmdMainboard('AMD-4000')

    def create_monitor(self):
        return AmdMonitor('14K')


class ComputerEnginee(object):
    # 定义一个装机工程师
    def make_computer(self, factory_obj):
        self.prepare_hardwares(factory_obj)

    def prepare_hardwares(self, factory_obj):
        # 定义一个硬件装机方法
        self.cpu = factory_obj.create_cpu()
        self.mainboard = factory_obj.create_mainboard()
        self.monitor = factory_obj.create_monitor()
        info = ''' -----------电脑【{}】信息-----------
            cpu: 【{}】
            mainboaed: 【{}】
            monitor: 【{}】
        '''.format(factory_obj.computer_name,
                   self.cpu.series_name,
                   self.mainboard.series_name,
                   self.monitor.size)
        print(info)


if __name__ == '__main__':
    engineer = ComputerEnginee()  # 装机工程师
    intel_factory = IntelFactory()  # Intel工厂
    engineer.make_computer(intel_factory)  # 工程师装Intel的电脑

    amd_factory = AmdFactory()  # Intel工厂
    engineer.make_computer(amd_factory)  # 工程师装Amd的电脑
