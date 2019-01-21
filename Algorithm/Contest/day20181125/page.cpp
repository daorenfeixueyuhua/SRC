#include <iostream>
using namespace ::std;
int main()
{
    float m = 10.0;
    int n, c1 = 2, c2 = 9, c3 = 31;
    while (cin >> n && n)
    {
        int a1 = 0, b1 = 0, a2 = 0, b2 = 0, a3 = 0, b3 = 0;
        if (c1 / m > n - 1)
        {
            a1 = (n - 1) * m;
            b1 = m;
        }
        if (c1 / (int)m == n - 1)
        {
            b1 = c1 % (int)m;
            a2 = 0;
            b2 = n * m - c1;
        }
        else if ((c1 + c2) / m > n - 1 && m * n > c1)
        {
            b2 = m;
            a2 = (n - 1) * m - c1;
        }
        if ((c1 + c2) / int(m) == n - 1)
        {
            b2 = m - n * m + c1 + c2;
            b3 = m - b2;
            a3 = 0;
        }
        else if ((c1 + c2 + c3) / m > n - 1 && m * n > (c1 + c2))
        {
            a3 = (n - 1) * m - c1 - c2;
            b3 = m;
        }
        if ((c1 + c2 + c3) / m == n - 1)
        {
            b3 = (n + 1) * m - c1 - c2 - c3;
        }
        cout << a1 << " " << b1 << " " << a2 << " " << b2 << " " << a3 << " " << b3 << endl;
    }
    return 0;
}