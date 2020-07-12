# 用泰坦尼克数据中的pclass,sex,age作为决策属性，Survived作类别属性，
# 30%的数据作为测试集，70%作为训练集。用程序得到该数据集的决策树模型，
# 并给出测试数据的准确度。

# 算法思路：
# 1、导入库
# 2、读取数据文件
# 3、提取属性
# 4、缺失值处理
# 5、特征工程
# 6、划分训练集和测试集
# 7、开始训练
# 8、测试模式准确值
# 9、保存结果


# import
import matplotlib.pylab as plt
import pandas as pd
import numpy as np
from sklearn.feature_extraction import DictVectorizer
from sklearn.model_selection import train_test_split
from sklearn.tree import DecisionTreeClassifier
from sklearn.tree import export_graphviz


def print_line(message):
    print('=' * 20, message, '=' * 20)


filename = 'C:\\Users\Lenovo\OneDrive\Projects\SRC\Language\Python\study\Data_Mining\\recources\exper3\\titantic.xlsx'

# 导入数据
dateFrame = pd.read_excel(filename, encoding='gbk')

print_line('原始数据')
print(dateFrame)
# print()

# 提取属性
x = dateFrame[['Pclass', 'Sex', 'Age']]
y = dateFrame[['Survived']]

# 缺失值处理
x['Age'].fillna(x['Age'].mean(), inplace=True)

# 特征工程
vec = DictVectorizer(sparse=False)
x_train = vec.fit_transform(x.to_dict(orient='record'))
print(x_train)
print(vec.feature_names_)
x = x_train
print_line('特征工程后的数据')
print(x)
print(y)

# 划分数据集

x_train, x_test, y_train, y_test = train_test_split(x, y, test_size=0.3)

# 初始化分类其
dtc = DecisionTreeClassifier(criterion="entropy", max_depth=5)
# 训练
dtc.fit(x_train, y_train)
# 预测
print('预测的准确率为', dtc.score(x_test, y_test))

# from sklearn.externals.six import StringIO
savefile = 'C:\\Users\Lenovo\OneDrive\Projects\SRC\Language\Python\study\Data_Mining\\recources\exper3\\save.dot'
with open(savefile, "w") as file:
    export_graphviz(dtc, feature_names=vec.get_feature_names(), out_file=file)
