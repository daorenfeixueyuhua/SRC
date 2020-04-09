#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(ll a, ll b)
{
    return b == 0L ? a : gcd(b, a % b);
}
void print(int n, char c)
{
    for (int i = 0; i < n; ++i)
        cout << c;
}
int getLenght(ll n)
{
    int i = 0;
    while (n)
    {
        i++;
        n /= 10;
    }
    return i;
}
int main()
{
    int n;

    while (cin >> n && n)
    {
        // 余数, 分子, 分母
        ll re = 0, num = 1, den = 1, temp;
        if (n == 1)
        {
            cout << 1 << endl;
            continue;
        }
        for (int i = 2; i <= n; ++i)
        {
            // todo 待完成！
            // 最小公倍数
            temp = den * i / gcd(den, i);
            num = num * (temp / den) + temp / i;
            den = temp;
        }

        if (!num)
        {
            cout << re << endl;
        }
        else
        {
            int length = max(getLenght(num), getLenght(den));
            print(getLenght(re) + 1, ' ');
            cout << num << endl;

            cout << re << " ";
            print(length, '-');
            cout << endl;

            print(getLenght(re) + 1, ' ');
            cout << den << endl;
        }
    }
    return 0;
}