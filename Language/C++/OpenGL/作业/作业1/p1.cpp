#include <stdio.h>
#include <math.h>
using namespace std;

// dda算法
// (1)输入直线的两个点（x0, y0）, (x1, y1)
// (2)求出数（length） = max(△x /△y)
// (3) 求出长dx = (x1 - x0) / length Dy = (y1 - y0) / length
// (4) x = x0.y = y0, 显示（x, y）
// (5) 当i <= length, x += dx, y += dy;显示（int）(x + 0.5), (int)(y + 0.5)否则返回。
void LineDDA1(int x1, int y1, int x2, int y2, int color)
{
    int dm = 0;
    if (abs(x2 - x1) >= abs(y2 - y1))
        dm = abs(x2 - x1);
    else
        dm = abs(y2 - y1);
    float dx = (float)(x2 - x1) / dm;
    float dy = (float)(y2 - y1) / dm;
    float x = x1 + 0.5;
    float y = y1 + 0.5;
    for (int i = 0; i < dm; i++)
    {
        // glVertex3i((int)x, (int)y, color);
        printf("(%d, %d) ", (int)x, (int)y);
        x += dx;
        y += dx;
    }
    printf("\n");
}

// Bresenham算法
// 1、输入直线的两端点p0(x0,y0),p1(x1,y1)
// 2、计算△x，△y，e = -△x, x = x0, y = y0
// 3、绘制点（x, y）
// 4、e更新为e + 2△y, 判断e的符号。若e〉0, 则（x, y）更新为（x + 1, y + 1）
// 同时将e更新为e - 2△x；否则（x, y）更新为（x + 1, y）
// void Bresenham_Line(int x0, int y0, int x1, int y1, int color, DOC *PDC)
// {
//     int dx, dy, e, i, x, y;
//     dx = x1 - x0;
//     dy = y1 - y0, e = 2 * (dy - dx);
//     x = x0, y = y0;
//     for (i = 0; i <= dx; i++)
//     {
//         PDC->setpixel(x, y, color);
//         x++;
//         e = e + 2 * dy;
//         if (e >= 0)
//         {
//             y++;
//             e = e - 2 * dx;
//         }
//     }
// }

int main()
{
    LineDDA1(2, 3, 8, 5, 0);
    return 0;
}
