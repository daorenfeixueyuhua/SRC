#include <bits/stdc++.h>
using namespace std;
const int MAXN = 1e3 + 5;
int n, x[MAXN], y[MAXN];
vector<int> A[MAXN * 2], B[MAXN * 2];
int main()
{
    scanf("%d", &n);
    for (int i = 0; i < n; i++)
        scanf("%d", &x[i]);
    for (int i = 0; i < n; i++)
        scanf("%d", &y[i]);
    for (int i = 0; i < n; i++)
    {
        A[y[i] + x[i]].push_back(i);
        B[y[i] - x[i] + 1000].push_back(i);
    }
    int ans = 0;
    for (int i = 0; i < 2000; i++)
    {
        for (int j = 0; j < 2000; j++)
        {
            set<int> s;
            for (auto k : A[i])
                s.insert(k);
            for (auto k : B[j])
                s.insert(k);
            ans = max(ans, (int)s.size());
        }
    }
    printf("%d\n", ans);
    return 0;
}
/*
4
1 4 4 5
3 0 2 3
*/