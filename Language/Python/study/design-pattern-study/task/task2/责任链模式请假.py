import random


class Handler(object):

    def __init__(self, successor=None):
        self._successor = successor

    def handle(self, request):
        res = self._handle(request)
        if not res:
            self._successor.handle(request)

    def _handle(self, request):
        raise NotImplementedError('Must provide implementation in subclass.')


class ConcreteHandler1(Handler):

    def _handle(self, request):
        if 0 < request <= 10:
            print("请求班主任批准！")
            print('你打算请假天数为？{0}'.format(request))
            return True


class ConcreteHandler2(Handler):

    def _handle(self, request):
        if 10 < request <= 20:
            print("请求系主任批准！")
            print('你打算请假天数为？{0}'.format(request))

            return True


class ConcreteHandler3(Handler):

    def _handle(self, request):
        if 20 < request <= 30:
            print("请求院长批准！")
            print('你打算请假天数为？{0}'.format(request))

            return True


class DefaultHandler(Handler):

    def _handle(self, request):
        print("教务申请休学")
        print('请假时间过长，你打算请假{0}天'.format(request))
        return True


class Client(object):

    def __init__(self):
        self.handler = ConcreteHandler1(
            ConcreteHandler3(ConcreteHandler2(DefaultHandler())))

    def delegate(self, requests):
        for request in requests:
            self.handler.handle(request)


if __name__ == "__main__":
    client1 = Client()

    requests = [random.randint(0, 45)for _ in [0]*10]
    client1.delegate(requests)
