import os
import json

print(os.getcwd())
# os.open('/tool/item.json')
with open(os.getcwd() + '\item.json') as f:
    f = json.load(f)
ts_urls = f[0]['ts_urls']
item = []
for i in range(len(ts_urls)):
    item.append({'index': i, 'url': ts_urls[i]})
print(item)
