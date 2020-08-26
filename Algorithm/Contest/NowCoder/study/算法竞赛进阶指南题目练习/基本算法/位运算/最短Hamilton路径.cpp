#include <iostream>
#include <algorithm>
#include <stdio.h>

using namespace std;
int n;
int map[21][21] = {0};
int dp[(1 << 20) + 1][21] = {0};
int main()
{
    cin >> n;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> map[i][j];
    cout << map[1][1] << endl;
    dp[1][0] = 0;
    for (int i = 1; i <= (1 << n) - 1; ++i)
        for (int j = 0; j < n; ++j)
            if ((i >> j) & 1)
                for (int k = 0; j < n; ++k)
                    if ((i >> k) & 1)
                        dp[i][j] = min(dp[i][j], dp[i ^ (1 << j)][k] + map[k][j]);
    cout << dp[(1 << n) - 1][n - 1] << endl;
    return 0;
}