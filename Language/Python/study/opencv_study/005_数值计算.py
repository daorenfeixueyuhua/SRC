import cv2 as cv
import sys
import matplotlib.pyplot as plt

img1 = cv.imread('resources\\0a1eab755cca04ca01de9138f3c313e1ef277be4.jpg')
img2 = cv.imread('resources\\0a6e28b88e492f0998cd4688059a1b35fe6935b6.jpg')

print((img1 + 10)[5::])
print((img1 + img2)[5::])
print(cv.add(img1, img2))

