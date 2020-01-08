# 导入模块
import pandas
from sklearn.model_selection import train_test_split
from sklearn.feature_extraction import DictVectorizer
from sklearn.tree import DecisionTreeClassifier, export_graphviz
from sklearn.externals.six import StringIO
from graphviz import Digraph
import pydotplus
import os

# os.environ['PATH'] += os.pathsep + 'C:/Program Files (x86)/Graphviz2.38/bin/'

# 获取数据

# titan = pandas.read_csv("./titanic.csv")
titan = pandas.read_csv('./titanic.csv',
                        names=["row.names", "pclass", "survived", "name", "age", "embarked", "home.dest", "room",
                               "ticket", "boat", "sex"
                               ])
# 输出数据
print(titan)

# 处理数据，找出特征值和目标值
feature = titan[["pclass", "age", "sex", "room"]]
label = titan['survived']

print('特征值：')
print(feature)
print('目标值')
print(label)

#
# featu缺失值处理re['age'].fillna(feature['age'].mean(), inplace=True)

# 分割数据集到训练集和测试集
feature_train, feature_test, label_train, label_test = train_test_split(feature, label, test_size=0.25)

# 进行处理（特征工程） 特征->类别->one_hot编码
dict = DictVectorizer(sparse=False)

feature_train = dict.fit_transform(feature_train.to_dict(orient="records"))
print(dict.get_feature_names())
feature_test = dict.transform(feature_test.to_dict(orient="records"))

# 使用决策树进行预测
dec = DecisionTreeClassifier(criterion='entropy', max_depth=5)

dec.fit(feature_train, label_train)

# 预测准确率
print('预测的准确率: ', dec.score(feature_test, label_test))

# 导出决策树的结构
# export_graphviz(dec, out_file="./tree.dot",
#                 feature_names=['年龄', 'pclass=1st', 'pclass=2nd', 'pclass=3rd', 'sex=女', 'sex=男'])
dot_data = StringIO()
export_graphviz(dec,
                out_file=dot_data,
                feature_names=dict.get_feature_names())

graph = pydotplus.graph_from_dot_data(dot_data.getvalue())
graph.write_pdf("./tree.pdf")
# graph.create_png("./tree.png")
