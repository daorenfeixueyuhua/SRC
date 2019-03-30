#include <iostream>
#include <vector>
#include <climits>
using namespace std;

//
int Fibonacci_recursion(int n)
{
    if (n == 1 || n == 2)
        return 1;
    else
        return Fibonacci_recursion(n - 1) + Fibonacci_recursion(n - 2);
}

int Fibonacci_memoriezed_aux(vector<int> &f, int n)
{
    if (f[n] >= 0)
        return f[n];
    f[n] = Fibonacci_memoriezed_aux(f, n - 1) + Fibonacci_memoriezed_aux(f, n - 2);
    return f[n];
}
int Fibonacci_memoriezed(int n)
{
    vector<int> f(n + 1, -INT_MAX);
    f[1] = f[2] = 1;
    return Fibonacci_memoriezed_aux(f, n);
}

int Fibonacci_bottom_up(int n)
{
    vector<int> f(n + 1, -INT_MAX);
    f[1] = f[2] = 1;
    for (int i = 3; i <= n; ++i)
        f[i] = f[i - 1] + f[i - 2];
    return f[n];
}

int main()
{
    int n = 3;
    cin >> n;
    cout << Fibonacci_bottom_up(n) << endl;
    return 0;
}