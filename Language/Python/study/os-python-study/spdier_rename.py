import os


IMAGES_STORE = 'C:/sources/hjd/img/'

src_img = 'full/5dd48d9798541d3f4eb51d140ae34f1835be8af6.jpg'

title = '大白乳秘書'

dir = IMAGES_STORE + title + '/'
if os.path.exists(dir) == False:
    os.mkdir(dir)
os.rename(IMAGES_STORE+src_img, dir+'1'+'.jpg')
