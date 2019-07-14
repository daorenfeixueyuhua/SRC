// Fibonacci
#include <iostream>
#include <vector>
#include <cmath>
using namespace ::std;
const int length = 100000001;
// 参考：https://www.cnblogs.com/shanyr/p/4671731.html

// 当n<21时，递归层次少，可直接调用
int ff(int n)
{
    if (n == 0)
        return 0;
    if (n == 1)
        return 1;
    return ff(n - 1) + ff(n - 2);
}

int main()
{
    int n;
    while (cin >> n)
    {
        if (n >= 21)
        {
            double s = (1 + sqrt(5.0)) / 2.0;
            double temp = -0.5 * log(5.0) / log(10.0) + ((double)n) * log(s) / log(10.0);
            temp = temp - floor(temp);
            temp = pow(10.0, temp);
            while (temp < 1000.0)
                temp *= 10.0;
            cout << int(temp) << endl;
        }
        else
            cout << ff(n) << endl;
    }
    return 0;
}