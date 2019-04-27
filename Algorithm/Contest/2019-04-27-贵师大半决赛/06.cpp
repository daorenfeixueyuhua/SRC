#include <iostream>
#include <stdio.h>
using namespace std;
typedef long long ll;

int ey, em, ed;
int yy, mm, dd;

bool isR(int y)
{
    if (y % 400 == 0 || (y % 4 == 0 && y % 100 != 0))
        return true;
    return false;
}

void yyadd()
{
    yy++;
}

void mmadd()
{
    mm++;
    if (mm == 13)
    {
        yyadd();
        mm = 1;
    }
}

void ddadd()
{
    dd++;
    switch (dd)
    {
    case 29:
        if (mm == 2 && !isR(yy))
        {
            mmadd();
            dd = 1;
        }
        break;
    case 30:
        if (mm == 2 && isR(yy))
        {
            mmadd();
            dd = 1;
        }
        break;
    case 31:
        if (mm == 4 || mm == 6 || mm == 9 || mm == 11)
        {
            mmadd();
            dd = 1;
        }
        break;
    case 32:
        if (mm == 1 || mm == 3 || mm == 5 || mm == 7 || mm == 8 || mm == 10 || mm == 12)
        {
            mmadd();
            dd = 1;
        }
        break;
    }
}
int main()
{

    yy = 2015;
    mm = 11;
    dd = 24;
    scanf("%d%d%d", &ey, &em, &ed);
    // cout << ey << " " << em << " " << ed << endl;
    // 统计strat到end之间的天数
    int C = 0;
    while (1)
    {
        C++;
        ddadd();
        if (yy == ey && mm == em && dd == ed)
            break;
    }
    C %= 5;
    if (C <= 2 && C != 0)
        cout << 1 << endl;
    else
        cout << 0 << endl;
    return 0;
}