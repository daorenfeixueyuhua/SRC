// cake
#include <iostream>
using namespace ::std;
int gcd(int a, int b)
{
    return b == 0 ? a : gcd(b, a % b);
}
int main()
{
    int p, q;
    while (cin >> p >> q)
    {
        cout << p + q - gcd(p, q) << endl;
    }
    return 0;
}