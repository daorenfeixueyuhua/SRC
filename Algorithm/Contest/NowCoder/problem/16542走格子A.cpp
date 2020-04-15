#include <algorithm>
#include <bitset>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#define MAXN 1010
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
const LL mod = 1e9 + 7;
// d=0 down
// d=1 rigth
// d=2 up
// d=3 left
int m, n, d = 0;
pair<int, int> dir = {1, 0};
// {x, y}表示下一步的方向: {1, 0} down; {0, 1} rigth
vector<int> V(MAXN, 1);
vector<vector<int>> G(MAXN, V);

pair<int, int> dfs(const int k, const int i, const int j) {
    if (k == m) {
        return {i, j};
    }
    G[i][j] = 1;
    // 边界和已经走i过的点为1 每一次变向都需要进行判断下一步是否可走
    while (G[i + dir.first][j + dir.second]) { // 不停变向
        d++;
        d %= 4;
        switch (d) {
        case 0:
            /* code */
            dir = {1, 0};
            break;
        case 1:
            dir = {0, 1};
            break;
        case 2:
            dir = {-1, 0};
            break;
        case 3:
            dir = {0, -1};
            break;
        }
    }
    return dfs(k + 1, i + dir.first, j + dir.second);
}

int main() {
    cin >> n >> m;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            G[i][j] = 0; // 标记为走过
    G[1][1] = 1;
    pair<int, int> ans = dfs(1, 1 + dir.first, 1 + dir.second);
    cout << ans.first << " " << ans.second << endl;

    return 0;
}
