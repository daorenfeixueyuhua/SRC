import cv2 as cv
import sys
import matplotlib.pyplot as plt

img = cv.imread(cv.samples.findFile('resources\\00e1302d503c6e55a755f96ea22db878b1cde981.jpg'))

if img is None:
    sys.exit('Read Img Fail')

top_size, bottom_size, left_size, rigth_size = (50, 50, 50, 50)
# 复制法
relicate = cv.copyMakeBorder(img,
                             top_size, bottom_size, left_size, rigth_size,
                             borderType=cv.BORDER_REPLICATE)
# 反射法
relfect = cv.copyMakeBorder(img,
                            top_size, bottom_size, left_size, rigth_size,
                            borderType=cv.BORDER_REFLECT)
# 反射法
reflect_101 = cv.copyMakeBorder(img,
                                top_size, bottom_size, left_size, rigth_size,
                                borderType=cv.BORDER_REFLECT_101)
# 外包装法
wrap = cv.copyMakeBorder(img,
                         top_size, bottom_size, left_size, rigth_size,
                         borderType=cv.BORDER_WRAP)
# 常量法
constant = cv.copyMakeBorder(img,
                             top_size, bottom_size, left_size, rigth_size,
                             borderType=cv.BORDER_CONSTANT, value=0)

# show image
plt.subplot(231), plt.imshow(img, 'gray'), plt.title('original')
plt.subplot(232), plt.imshow(relicate, 'gray'), plt.title('relicate')
plt.subplot(233), plt.imshow(relfect, 'gray'), plt.title('reflect')
plt.subplot(234), plt.imshow(reflect_101, 'gray'), plt.title('reflect_101')
plt.subplot(235), plt.imshow(wrap, 'gray'), plt.title('warp')
plt.subplot(236), plt.imshow(constant, 'gray'), plt.title('constant')

plt.show()
