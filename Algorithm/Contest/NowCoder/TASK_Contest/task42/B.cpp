#include <iostream>
using namespace std;
const int mod = 100000007;
int main()
{
    int n;
    long long val, ans = 0, sum = 0;
    cin >> n;
    for (int i = 0; i < n; i++)
    {
        cin >> val;
        ans ^= val;
        sum += val;
    }
    cout << (ans + sum) % mod << endl;


    return 0;
}