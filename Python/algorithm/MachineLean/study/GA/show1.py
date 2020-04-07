# 画出图像如下
from mpl_toolkits.mplot3d import Axes3D
import numpy as np
from matplotlib import pyplot as plt

fig = plt.figure(figsize=(10, 6))
ax = Axes3D(fig)

x1 = np.arange(-5, 5, 0.1)
x2 = np.arange(-5, 5, 0.1)
x3 = np.arange(-5, 5, 0.1)
x4 = np.arange(-5, 5, 0.1)

X1, X2, X3, X4 = np.meshgrid(x1, x2, x3, x4)

Z = 1 / (X1 ^ 2 + X2 ^ 2 + X3 ^ 2 + X4 ^ 2 + 1)
# print(Z)
plt.xlabel('X1')
plt.ylabel('X2')
plt.xlabel('x')
plt.ylabel('y')
ax.set_zlim([-1, 5])
ax.plot_surface(X, Y, Z, rstride=1, cstride=1, cmap='rainbow')
plt.show()
