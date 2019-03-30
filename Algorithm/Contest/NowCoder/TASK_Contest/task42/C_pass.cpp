#include <bits/stdc++.h>
using namespace std;
#define mod 1000000007
#define maxn 2010
typedef long long ll;
struct node
{
    int x, y;
    bool operator<(const node z) const
    {
        return x == z.x ? y < z.y : x < z.x;
    }
} d[maxn * maxn];
ll f[maxn];
int n, m;
int main()
{
    int cnt = 0;
    ll ans = 0;
    scanf("%d %d", &n, &m);
    f[0] = 1;
    for (int i = 1; i <= m; i++)
        f[i] = f[i - 1] * n % mod;
    for (int i = 1; i <= m; i++)
    {
        for (int j = 1; j <= n; j++)
        {
            int x;
            scanf("%d", &x);
            d[++cnt] = node{x, i};
        }
    }
    sort(d + 1, d + cnt + 1);
    int fi = 1;
    for (int i = 1; i <= cnt; i++)
    {
        int t = 1;
        if (d[i].x != d[i + 1].x)
        {
            ll s = 1;
            int k = 0;
            for (int j = fi; j < i; j++)
            {
                if (d[j].y == d[j + 1].y)
                    t++;
                else
                {
                    k++;
                    ans = (ans + (1ll * d[j].x * t % mod * s % mod * f[m - k]) % mod) % mod;
                    s = (s % mod * (n - t) % mod);
                    t = 1;
                }
            }
            fi = i + 1;
            ans = (ans + (1ll * d[i].x * t % mod * s % mod * f[m - k - 1]) % mod) % mod;
        }
    }
    printf("%lld\n", ans);
    return 0;
}