#include <cstring>
#include <iostream>
using namespace std;
int n;
int mp[21][21];
int dp[21][1 << 20];

int main() {
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> mp[i][j];
    memset(dp, 0x3f, sizeof(dp));
    dp[1][1] = 0;
    for (int i = 1; i < (1 << n); ++i)
        for (int j = 1; j <= n; ++j)
            if ((i & (1 << (j - 1))))
                for (int k = 1; k <= n; ++k)
                    if (!(i & (1 << (k - 1))))
                        dp[k][i | (1 << (k - 1))] =
                            min(dp[k][i | (1 << (k - 1))], dp[i][j] + mp[i][j]);
    cout << dp[n][(1 << n) - 1] << endl;
    return 0;
}