import json
import os
import codecs

ITEM_STORE = 'C:\sources\\bt7086/'

item = {'cur_time': '2020-03-07 11:26',
        'image_paths': 'C:\\sources\\bt7086\\img/2020-03-07/在家發情想讓大家看看我的騷穴[13P]/11.jpg',
        'image_urls': 'http://p8.urlpic.club/pic20190701/upload/image/20200307/30709254038.jpg',
        'index': 11,
        'title': '在家發情想讓大家看看我的騷穴[13P]'}

filename = ITEM_STORE + 'file/'
if os.path.exists(filename) is False:
    os.mkdir(filename)
    # 打开json文件，向里面以dumps的方式吸入数据
    # 注意需要有一个参数ensure_ascii=False ，不然数据会直接为utf编码的方式存入比如
    # :“/xe15”
filename = filename + item['cur_time'][0:10:] + '.json'
with codecs.open(filename, 'a+') as f:
    line = json.dumps(dict(item), ensure_ascii=False) + '\n'
    f.write(line)
    f.write(',')
