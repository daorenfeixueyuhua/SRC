import redis


class RedisTool:
    __pool = None
    __client = None

    def __init__(self, host, port, auth):
        self.__pool = redis.ConnectionPool(host=host, port=port, decode_responses=True)
        self.__client = redis.Redis(connection_pool=self.__pool)

    def sadd(self, key, values):
        for i in values:
            self.__client.sadd(key, i)

    def smembers(self, key):
        values = []
        for i in self.__client.sscan_iter(key):
            values.append(i)
        return values

    def close(self):
        self.__client.close()
