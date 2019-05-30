// Fibonacci
#include <iostream>
#include <vector>
using namespace ::std;
const int length = 100000001;

int MAX = 10000;
vector<int> Fi(int n)
{
    vector<int> f0(MAX, 0), f1(MAX, 0), f2(MAX, 0);
    f0[MAX - 1] = f1[MAX - 1] = 1;
    if(n==0)
        f1 = f0;
    for (int i = 2; i <= n;i++){

    }
}

long long Fibonacci(long long n)
{
    long long f0 = 0, f1 = 1, f2;
    if (n == 0)
        f1 = f0;
    for (int i = 2; i <= n; ++i)
    {
        f2 = f0 + f1;
        f0 = f2 - f0;
        f1 = f2;
    }
    return f1;
}

int main()
{
    long long n;
    while (cin >> n)
    {
        cout << Fibonacci(n) << endl;
    }
    return 0;
}