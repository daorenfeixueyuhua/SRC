import redis


class RedisTool:
    __pool = None
    __cilent = None

    def __init__(self, host, port):
        """
        
        :param host: host
        :param port: post
        """
        self.__pool = redis.ConnectionPool(host=host, port=port, decode_responses=True)
        self.__cilent = redis.Redis(connection_pool=self.__pool)

    def save_urls(self, key, value):
        """
        
        :param key: key
        :param value: value
        :return: None
        """
        self.remov_all(key)
        for url in value:
            self.__cilent.rpush(key, url)

    def read_urls(self, key):
        """
        :param key: 
        :return: list_urls: value；list_cnt：value size
        """
        list_urls = []
        list_cnt = self.__cilent.llen(key)
        list_urls = self.__cilent.lrange(key, 0, list_cnt)
        return list_urls, list_cnt

    def push(self, key, value):
        for url in value:
            self.__cilent.lpush(key, url)

    def remov_all(self, key):
        self.__cilent.ltrim(key, 0, 0)

    def sadd(self, key, value):
        for i in value:
            self.__cilent.sadd(key, i)

    def smembers(self, key) -> list:
        values = []
        for i in self.__cilent.sscan_iter(key):
            values.append(i)
        return values

    def del_key(self, key):
        self.__cilent.delete(key)


# 教程： https://www.runoob.com/w3cnote/python-redis-intro.html

if __name__ == '__main__':
    img_base_url = 'https://hjd.niao2048.biz/2048/'
    complete_key = 'hjd:complete:urls'
    cilent = RedisTool(host='localhost', port=6379)
    urls, cnt = cilent.read_urls(complete_key)
    for i in range(len(urls)):
        if 'http' not in urls[i]:
            urls[i] = img_base_url + urls[i]
    cilent.sadd('test', urls)
    print(cilent.smembers('test')[:10:2])
