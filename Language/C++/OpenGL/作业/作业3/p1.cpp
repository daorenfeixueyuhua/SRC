#include <iostream>
using namespace std;

// 算法：
// 1、输入点(x,y)
// 2、交换x与y
// 3、输出(x,y)
void fun1(int &x, int &y)
{
    int tmp = x;
    x = y;
    y = tmp;
}
// 算法：
// 1、输入(x,y,altha)
// 2、计算新点的坐标：
//  x1 = x * cos(altha) + y * sin(altha)
//  y1 = x * sin(altha) + y * cos(altha)
// 3、输出新点坐标

void fun2(int x, int y, float altha, int &x1, int &y1)
{
    x1 = x * cos(altha) + y * sin(altha);
    y1 = x * sin(altha) + y * cos(altha);
}
// 算法：
// 1、输入点坐标(x, y, z)
// 2、令x、y坐标取反，z坐标不变
// 3、输出新点坐标
void fun3(int x, int y, int z, int x1, int y1, int z1)
{
    x1 = -x;
    y1 = -y;
    z1 = z;
}
int main()
{
    return 0;
}