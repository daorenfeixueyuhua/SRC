import pandas as pd
import matplotlib.pyplot as plt

# （1）	读取hexun.csv文件。
fileName = "C:\\Users\Lenovo\OneDrive\Projects\SRC\Language\Python\study\Data_Mining\\recources\exper1\hexun.csv"
dataFrame = pd.read_csv(fileName, header=None)

# （2）	取数据的values，分析一下第0行为什么没有了。
print(dataFrame)
print('因为第0行，被pandas认为是数据的head了，在取值时，没有取出来。')
# （3）	将数组转置。
print('转置后的数据')
print(pd.DataFrame(dataFrame.values.T, index=dataFrame.columns, columns=dataFrame.index))
# （4）	取出阅读数及评论数。
read = dataFrame.iloc[:, 3:4]
commet = dataFrame.iloc[:, 4:5]
print('阅读数:')
print(read)
print('评论数:')
print(commet)
# （5）	设阅读数为x轴，评论数为y轴，画出直线图。
plt.figure(1)
plt.plot(read, commet)
plt.xlabel('read')
plt.ylabel('commet')
plt.show()
# （6）	分析该图所反映的问题。
print('改数据中，阅读数10000以下，评论数在50以下的居多。其他数据较为稀少')
# （7）	设博客ID为x轴，阅读数为y轴，画出直线图。
plt.figure(2)
plt.plot(dataFrame.iloc[:, 0:1], read)
plt.xlabel('ID')
plt.ylabel('read')
plt.show()
# （8）	分析该图反应的问题。
print('反映出，阅读量在ID为1200左右达到顶峰，而ID在200到4600左右，阅读量基本为0')
# （9）   试试其他图形
print('以ID为x轴，以评论量为y轴，画直线图')
plt.figure(3)
plt.plot(dataFrame.iloc[:, 0:1], commet)
plt.xlabel('ID')
plt.ylabel('commet')
plt.show()
