import os
IMAGES_STORE = 'C:\sources\\bt7086\img/'
filename = IMAGES_STORE + 'file/' + '2020-03-07' + '.json'
if os.path.exists(filename) is False:
    os.mkdir(filename)
