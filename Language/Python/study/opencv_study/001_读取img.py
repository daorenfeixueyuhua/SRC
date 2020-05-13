import cv2 as cv
import sys

img = cv.imread(cv.samples.findFile('./resources/0a1eab755cca04ca01de9138f3c313e1ef277be4.jpg'))

if img is None:
    sys.exit('Could not read img')

cv.imshow('Display img', img)
k = cv.waitKey(0)

if k == ord('s'):
    cv.imwrite('./resources/001.jpg', img)
