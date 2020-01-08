# 导入波士顿房价
from sklearn.datasets import load_boston
from sklearn.linear_model import LinearRegression
# 导入划分数据集和测试集api
from sklearn.model_selection import train_test_split
# 导入标准化api
from sklearn.preprocessing import StandardScaler


def mylinear():
    """"
    线性回归直接预测房子价格
    """
    # 1、获取数据集
    lb = load_boston()

    # 2、分割数据集到训练集和测试集
    x_train, x_test, y_train, y_test = train_test_split(lb.data, lb.target, test_size=0.25)

    print(x_train[0:20], '\n', x_test[0:20], '\n', y_train[0:20], '\n', y_test[0:20])

    # 3、进行标准化处理，此处目标值也必须进行处理
    std_x = StandardScaler()
    x_train = std_x.fit_transform(x_train)
    x_test = std_x.transform(x_test)

    std_y = StandardScaler()
    y_train = std_y.fit_transform(y_train.reshape(-1, 1))
    y_test = std_y.transform(y_test.reshape(-1, 1))

    # estimator预测
    # 线性回归方程进行预测
    lr = LinearRegression()
    lr.fit(x_train, y_train)
    print('回归方程的权值', lr.coef_)

    # 预测数据集的房子价格
    y_predict = std_y.inverse_transform(lr.predict(x_test))

    print('预测集里面每个房子的预测价格', y_predict)

    return None


if __name__ == '__main__':
    mylinear()
