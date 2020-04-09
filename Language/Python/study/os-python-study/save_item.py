import json
import os
item = [{'image_paths': 'full/cc955f0d3aeb60d764d91347062140c9d8f9e45a.jpg',
         'image_urls': 'http://p8.urlpic.club/pic20190701/upload/image/20200303/30309140349.jpg',
         'index': 46,
         'title': '可愛正妹露臉自拍，如此嫩B一旦擁有，別無所求[50P]'},
        {'image_paths': 'full/0031f1462c5955566dffd32132199839166c31d9.jpg',
         'image_urls': 'http://p8.urlpic.club/pic20190701/upload/image/20200305/30508566192.jpg',
         'index': 41,
         'title': '网红美乳女神『丁丁』大尺度私拍流出：纯天然美女，圆润美乳、长腿细腰高清大合集（第二部）[48P]'}
        ]
item_json = open('save_item_data.json', mode='w', encoding='UTF-8')
item = json.dump(item, item_json, ensure_ascii=False)
print(item, type(item))

item_json.close()

item_json = open('save_item_data.json', mode='r', encoding='UTF-8')

item_temp = json.load(item_json)
print(item_temp)
