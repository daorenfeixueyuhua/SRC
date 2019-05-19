#include <bits/stdc++.h>
const int mod = 9973;
using namespace std;

int g(int x, int y)
{
    return ((y - 1) * (int(pow(x, 5)) % mod) + int(pow(x, 3)) % mod - x * y + 3 * x + 7 * y) % mod;
}

int main()
{
    vector<int> N(100001, 0);
    N[0] = 0;
    for (int i = 1; i < 100001; ++i)
    {
        N[i] = g(i, N[i - 1]);
    }
    int n;
    cin >> n;
    
    copy(N.begin(), N.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}