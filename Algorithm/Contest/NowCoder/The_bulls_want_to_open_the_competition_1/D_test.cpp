#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;
const int MAXN = 5;

int main()
{
    int A[MAXN + 1][MAXN + 1] = {0};
    int XOR[MAXN + 1] = {0};
    int e = 2;
    for (int i = 1; i <= MAXN; ++i)
    {
        for (int j = 1; j <= MAXN; ++j)
        {
            cin >> A[i][j];
            A[i][j] ^= e;
        }
    }
    for (int i = 1; i <= MAXN; ++i)
    {
        for (int j = 1; j <= MAXN; ++j)
            cout << A[i][j] << " ";
        cout << endl;
    }
    int dp[MAXN + 1][MAXN + 1] = {0};
    for (int i = 1; i <= MAXN; ++i)
        for (int j = 1; j <= MAXN; ++j)
            dp[i][j] = max(dp[i - 1][j], dp[i][j - 1]) + A[i][j];

    cout << dp[MAXN][MAXN] << endl;
    // random_shuffle(A, A + MAXN);
    // int r = 0;
    // for (int i = 0; i < 5; ++i)
    // {
    //     XOR[i] = e ^ A[i];
    //     cout << A[i] << "^" << e << " = " << XOR[i] << endl;
    // }
    return 0;
}