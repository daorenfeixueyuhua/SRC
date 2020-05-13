from tools.redisTool import RedisTool

redis = RedisTool(host='localhost', port=6379)

key = 'hjd:complete:urls'
values = []

values = redis.smembers(key)

print(values[:1:])

for i in range(len(values)):
    if values[i].find('read') == 60:
        values[i] = values[i][30::]

redis.del_key(key)
redis.sadd('hjd:275:complete:urls', values)
