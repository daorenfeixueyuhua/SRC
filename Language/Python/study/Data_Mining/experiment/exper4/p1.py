# 算法步骤：
# 1、随机选择k个点作为聚类中心
# 2、计算各个点到这k个点的距离
# 3、将对应的点聚到离它最近的聚类中心
# 4、重新计算聚类中心
# 5、比较当前聚类中心与前一次聚类中心，如果是同一个点，得到聚类结果，若为不同结果，则重复2-5

import pandas as pd
import numpy as np
import matplotlib.pyplot as plt
from sklearn.cluster import KMeans


def print_line(message):
    print('=' * 20, message, '=' * 20)


filename = 'C:\\Users\Lenovo\OneDrive\Projects\SRC\Language\Python\study\Data_Mining\\recources\exper4\\taob.xlsx'

dataf = pd.read_excel(filename)
print_line('原始数据')
print(dataf)
x = dataf.iloc[:, 2:4]
print_line('需要的属性列')
print(x)

kms = KMeans(n_clusters=4)
y = kms.fit_predict(x)
print_line('聚类结果')
print(y)

for i in range(len(y)):
    if (y[i] == 0):
        plt.plot(x.iloc[i:i + 1, 0:1], x.iloc[i:i + 1, 1:2], '*r')
    if (y[i] == 1):
        plt.plot(x.iloc[i:i + 1, 0:1], x.iloc[i:i + 1, 1:2], '*y')
    if (y[i] == 2):
        plt.plot(x.iloc[i:i + 1, 0:1], x.iloc[i:i + 1, 1:2], '*b')
    if (y[i] == 3):
        plt.plot(x.iloc[i:i + 1, 0:1], x.iloc[i:i + 1, 1:2], '*k')
plt.show()
