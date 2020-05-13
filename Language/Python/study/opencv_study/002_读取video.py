import cv2 as cv
import sys

video = cv.VideoCapture('resources\\video1.mp4')

# 检查是否打开正确
if video.isOpened():
    open, frame = video.read()
else:
    sys.exit('Open failed')

while open:
    ret, frame = video.read()
    if frame is None:
        print('Read Ended')
        break

    if ret == True:
        gray = cv.cvtColor(frame, cv.COLOR_BGR2GRAY)
        cv.imshow('result', gray)
        # wait
        if cv.waitKey(100) & 0xFF == 27:
            break
            
video.release()
cv.destroyWindow()