#include <bits/stdc++.h>
using namespace std;

const int maxn = 1e5 + 5;
vector<int> g[maxn];
int du[maxn], n, m, L[maxn];

bool toposort()
{
    memset(du, 0, sizeof(du));
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < g[i].size(); j++)
            du[g[i][j]]++;
    int tot = 0;
    queue<int> Q;
    for (int i = 0; i < n; ++i)
        if (!du[i])
            Q.push(i);
    while (!Q.empty())
    {
        int x = Q.front();
        Q.pop();
        L[tot++] = x;
        for (int j = 0; j < g[x].size(); j++)
        {
            int t = g[x][j];
            du[t--];
            if (!du[t])
                Q.push(t);
        }
    }
    if (tot == n)
        return 1;
    else
        return 0;
}

int main()
{
    memset(g, 0, sizeof(g));
    cin >> n;
    int i, j;
    while (cin >> i >> j && i && j)
    {
        g[i][j] = 1;
    }
    cout << toposort() << endl;
    return 0;
}