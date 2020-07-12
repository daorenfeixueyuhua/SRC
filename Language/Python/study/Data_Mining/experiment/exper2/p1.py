from lib.apriori import *
import pandas as pd

filename = 'C:\\Users\Lenovo\OneDrive\Projects\SRC\Language\Python\study\Data_Mining\\recources\exper2\lesson_buy.xls'

dataframe = pd.read_excel(filename, header=None)
# 转化数据为0,1矩阵
change = lambda x: pd.Series(1, index=x[pd.notnull(x)])
mapok = map(change, dataframe.values)  # 传入的dataframe先转化为矩阵，然后通过change来转化
data = pd.DataFrame(list(mapok)).fillna(0)  # 把值为NA表示没有购买，则填充为0
# 设置支持度和置信度阈值
support = 0.1
confidence = 0.3

find_rule(data, confidence, confidence, '->')
