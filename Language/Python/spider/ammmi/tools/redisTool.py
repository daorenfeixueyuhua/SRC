import redis


class RedisTool:
    __pool = None
    __client = None
    __host = ''
    __port = 0
    __auth = ''

    @classmethod
    def setHost(self, host, port, auth=None):
        self.__host = host
        self.__pool = port
        self.__auth = auth

    def __init__(self):
        self.__pool = redis.ConnectionPool(host=self.__host, port=self.__pool)

    def __open(self):
        self.__client = redis.Redis(connection_pool=self.__pool)

    def __close(self):
        self.__client.close()

    def sadd(self, key, value):
        self.__open()
        if type(value) != list:
            value = [value]

        for i in value:
            self.__client.sadd(key, i)
        self.__close()

    def smembers(self, key) -> list:
        self.__open()

        values = []
        for i in self.__client.sscan_iter(key):
            values.append(i)
        self.__close()
        return values

    def del_key(self, key):
        self.__client.delete(key)


if __name__ == '__main__':
    host = 'localhost'
    port = 6379
    RedisTool.setHost(host=host, port=port)
    client = RedisTool()
    client.sadd('test', ['123'])
