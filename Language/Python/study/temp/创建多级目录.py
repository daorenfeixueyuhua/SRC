import os


IMAGES_STORE = 'C:\\sources\\hjd\\img/'
first_title = '美图秀秀'
second_title = '网络正妹'
page = '1'
time = '2020-04-23'
title = '乳量惊人'

path = IMAGES_STORE + first_title + '/'
if first_title != '' and os.path.exists(path) == False:
    os.mkdir(path)
path = path + second_title + '/'
if second_title != '' and os.path.exists(path) == False:
    os.mkdir(path)
path = path + page + '/'
if page != '' and os.path.exists(path) == False:
    os.mkdir(path)
path = path + time + '/'
if time != '' and os.path.exists(path) == False:
    os.mkdir(path)
path = path + title + '/'
if title != '' and os.path.exists(path) == False:
    os.mkdir(path)


# path = ''
# path = IMAGES_STORE + first_title + '/' + second_title + '/' + title + '/'
# os.mkdir(path)
print(path)
