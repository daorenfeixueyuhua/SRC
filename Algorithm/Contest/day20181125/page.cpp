#include <iostream>
using namespace ::std;
int main()
{
    int n = 1, m = 10, c1 = 15, c2 = 28, c3 = 31;

    int a1, b1, a2, b2, a3, b3;
    a1 = (n - 1) * m + 1;
    if (c1 / m > n - 1)
    {
        b1 = m;
    }
    else
    {
        b1 = c1 % m;
    }

    a2 = m - c1 / m + m * n - c1;
    cout << a1 << " " << b1 << " " << a2 << " " << endl;
    return 0;
}