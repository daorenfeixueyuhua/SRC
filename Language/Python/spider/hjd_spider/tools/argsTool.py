class Args:
    k = ''
    v = ''

    def __init__(self, k, v):
        self.k = k
        self.v = v

    def setK(self, k):
        self.k = k

    def getK(self):
        return self.k

    def setV(self, v):
        self.v = v

    def getV(self):
        return self.v

    def __str__(self):
        return '{0}={1}'.format(self.k, self.v)


if __name__ == '__main__':
    args_list = []
    args_list.append(Args('page_id', '277'))
    print(args_list[0])
