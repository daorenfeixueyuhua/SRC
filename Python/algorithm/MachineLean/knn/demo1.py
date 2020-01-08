from sklearn import neighbors
from sklearn import datasets
knn = neighbors.KNeighborsClassifier()
#得到分类器
iris = datasets.load_iris()
#得到数据集
print( iris.data)

knn.fit(iris.data, iris.target)
#训练模型
predictedLabel = knn.predict([[0.1, 0.2, 0.3, 0.4]])

print (predictedLabel)