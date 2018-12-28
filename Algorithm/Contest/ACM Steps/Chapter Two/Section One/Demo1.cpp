// 最小公倍数
#include <iostream>
using namespace ::std;
// 最大公因数公式
int gcd(int a, int b)
{
    if (b == 0)
        return a;
    else
        return gcd(b, a % b);
}
// 最小公倍数公式
int lcm(int a, int b)
{
    return a * b / gcd(a, b);
}
int main()
{
    int a, b;
    while (cin >> a >> b && (a || b))
    {
        cout << lcm(a, b) << endl;
    }
    return 0;
}