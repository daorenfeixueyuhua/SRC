#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

int main()
{
    long long n, e;
    vector<long long> temp(n + 1, 0);
    vector<vector<long long>> p(n + 1, temp), dp(n + 1, temp);
    cin >> n >> e;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> p[i][j];
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            dp[i][j] = max(e ^ p[i - 1][j], e & p[i][j - 1]) + dp[i][j];
    cout << dp[n][n] << endl;
    return 0;
}