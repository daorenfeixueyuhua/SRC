#include <stdio.h>
long long gcd(long long a, long long b)
{
    return a % b == 0 ? b : gcd(b, a % b);
}

void remove(long long &a, long long &b)
{
    long long tmp = a > b ? gcd(a, b) : gcd(b, a);
    a = a / tmp;
    b = b / tmp;
}

int main()
{
    long long n, a, b, c, d;
    scanf("%lld", &n);
    while (n--)
    {
        scanf("%lld/%lld %lld/%lld", &a, &b, &c, &d);
        remove(a, b);
        remove(c, d);
        long long fenzi = (a * c) / gcd(a, c);
        long long fenmu = gcd(b, d);
        if (fenzi % fenmu)
        {
            printf("%lld/%lld\n", fenzi, fenmu);
        }
        else
            printf("%lld\n", fenzi / fenmu);
    }
    return 0;
}