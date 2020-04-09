#include <iostream>
#include <string>
#include <vector>
typedef long long ll;
using namespace ::std;
int main()
{
    ll n, result = 0;
    while (cin >> n)
    {
        result = n * (n + 1) / 2;
        cout << result << endl;
        cout << endl;
    }
    return 0;
}