import urllib.parse

src = '%u5728%u7ebf%u64ad%u653e%24https%3A%2F%2Flbbf9.com%2F20200423%2F3Czu27sh%2Findex.m3u8'

src = urllib.parse.unquote(src, encoding='UTF-8')

src = src.split('$')[1]

print(src.decode('UTF-8'))