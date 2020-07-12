#include <iostream>
using namespace std;

void fun1(int x, int y, float altha, int &x1, int &y1)
{
    x1 = x * cos(altha) - y * sin(altha);
    y1 = x * sin(altha) + y * cos(altha);
}

void fun2(int x, int y, float fx, float fy, int &x1, int &y1)
{
    x1 = x * fx;
    y1 = y * fy;
}

void fun3(int x, int y, int &x1, int &y1)
{
    x1 = x;
    y1 = -y;
}
void fun4(int x, int y, int &x1, int &y1)
{
    x1 = -x;
    y1 = y;
}
void fun5(int x, int y, int z, int &x1, int &y1, int &z1)
{
    x1 = -x;
    y1 = -y;
    z1 = z;
}
int main()
{
}