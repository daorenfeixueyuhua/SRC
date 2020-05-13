import cv2 as cv
import sys
import matplotlib.pyplot as plt

img1 = cv.imread('resources\\00e719e3bab58dfc86a0f1e86dd75b3c41b876e7.jpg')
img2 = cv.imread('resources\\00e1302d503c6e55a755f96ea22db878b1cde981.jpg')

# show tow image
cv.imshow('img1', img1)
cv.waitKey(0)

cv.imshow('img2', img2)
cv.waitKey(0)
