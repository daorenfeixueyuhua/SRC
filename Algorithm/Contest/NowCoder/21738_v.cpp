#include <set>
#include <map>
#include <queue>
#include <stack>
#include <math.h>
#include <bitset>
#include <vector>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <algorithm>
#define MAXN 1010100
#define LL long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll __int64
#define INF 0x7fffffff
#define cs(s) freopen(s, "r", stdin)
#define mem(x) memset(x, 0, sizeof(x))
#define PI acos(-1)
#define eps 1e-10
using namespace std;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
LL powmod(LL a, LL b, LL MOD)
{
    LL ans = 1;
    while (b)
    {
        if (b % 2)
            ans = ans * a % MOD;
        a = a * a % MOD;
        b /= 2;
    }
    return ans;
}
//head
const LL mod = 1e9 + 7;
LL dp[11][100003];
vector<LL> p[100001];
LL n, k;
void P()
{ //预处理倍数
    for (int i = 1; i <= k; i++)
    {
        for (int j = 2; 1ll * j * i <= k; j++)
        {
            p[i].pb(j * i);
        }
    }
}
LL a[111];
int main()
{
    ios::sync_with_stdio(false);
    cin >> n >> k;
    P();
    for (int i = 1; i <= k; i++)
        dp[1][i] = 1;
    for (int i = 1; i <= n; i++)
        dp[i][1] = 1;
    for (int i = 2; i <= n; i++)
    {
        LL pr = 0;
        for (int j = 1; j <= k; j++)
            pr = (0ll + pr + dp[i - 1][j]) % mod;
        LL sum = dp[i - 1][1];
        for (int j = 2; j <= k; j++)
        {
            LL mi = pr;
            dp[i][j] = (0ll + sum + dp[i - 1][j]) % mod;
            sum = (0ll + sum + dp[i - 1][j]) % mod; //为dp[i-1][1]到dp[i-1][j]的和
            mi -= sum;
            for (int x : p[j])
            {
                mi -= dp[i - 1][x]; //减去倍数
            }
            dp[i][j] += mi;
        }
    }
    LL ans = 0;
    for (int i = 1; i <= k; i++)
        ans = (ans + dp[n][i]) % mod;
    cout << ans;
    return 0;
}
