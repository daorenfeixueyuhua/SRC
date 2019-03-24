#include <iostream>

using namespace std;

// sum(1, ..., n)

int main()
{
    long long n;
    cin >> n;
    long long result = 0;
    result = (n + 1) * n / 2;
    cout << result << endl;
    return 0;
}