#include <bits/stdc++.h>
typedef long long ll;
const int MAX = 11;
using namespace std;

ll dp[MAX][MAX] = {0};

int main()
{
    int N;
    cin >> N;
    for (int i = 1; i <= N; ++i)
        dp[i][1] = 1;
    for (int i = 2; i <= N; ++i)
        for (int j = 2; j <= i; ++j)
        {
            dp[i][j] = dp[i][j - 1] + dp[i - j][j];
        }
    // copy(dp, dp + MAX * MAX, ostream_iterator<ll>(cout, " "));
    for (int i = 1; i <= N; ++i)
    {
        for (int j = 1; j <= N; ++j)
            cout << dp[i][j] << " ";
        cout << endl;
    }
    return 0;
}