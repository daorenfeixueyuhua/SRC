/*
给定一张 n(n≤20)(n \leq 20)(n≤20) 个点的带权无向图，点从0∼n−10 \sim
n-10∼n−1标号，求起点 0 到终点 n-1 的最短Hamilton路径。 Hamilton路径的定义是从 0
到 n-1 不重不漏地经过每个点恰好一次。
第一行一个整数n。
接下来n行每行n个整数，其中第i行第j个整数表示点i到j的距离（一个不超过10710^7107的正整数，记为a[i,j]）。
对于任意的x,y,z，数据保证 a[x,x]=0，a[x,y]=a[y,x]
并且a[x,y]+a[y,z]≥a[x,z]a[x,y]+a[y,z] \geq a[x,z]a[x,y]+a[y,z]≥a[x,z]。

4
0 2 1 3
2 0 2 1
1 2 0 1
3 1 1 0

4

从0到3的Hamilton路径有两条，0-1-2-3和0-2-1-3。前者的长度为2+2+1=5，后者的长度为1+2+1=4

*/
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
            if ((i & (1 << (j - 1)))) // 去过j
                for (int k = 1; k <= n; ++k)
                    if (!(i & (1 << (k - 1)))) // 没有去过k
                        dp[k][i | (1 << (k - 1))] =
                            min(dp[k][i | (1 << (k - 1))], dp[i][j] + mp[i][j]);
    cout << dp[n][(1 << n) - 1] << endl;
    return 0;
}