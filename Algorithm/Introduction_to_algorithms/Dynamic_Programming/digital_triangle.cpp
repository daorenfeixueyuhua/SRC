#include <iostream>
#include <algorithm>

using namespace std;

const int MAXN = 1005;

int n;
int P[MAXN][MAXN] = {0};
int dp[MAXN][MAXN];
// 递归版
int MaxSum1(int i, int j)
{
    if (i == n)
        return P[i][j];
    else
        return max(MaxSum1(i + 1, j), MaxSum1(i + 1, j + 1)) + P[i][j];
}

// DP递归版
int MaxSum2(int i, int j)
{
    if (dp[i][j] != -1)
        return dp[i][j];
    if (i == n)
        return dp[i][j] = P[i][j];
    return max(MaxSum2(i + 1, j), MaxSum2(i + 1, j + 1)) + P[i][j];
}

int main()
{
    for (int i = 0; i < MAXN; i++)
        for (int j = 0; j < MAXN; j++)
            dp[i][j] = -1;
    cin >> n;
    for (int i = 0; i < n; i++)
        for (int j = 0; j <= i; j++)
            cin >> P[i][j];
    cout << MaxSum2(1, 1) << endl;
    cin.get();
    cin.get();
    return 0;
}