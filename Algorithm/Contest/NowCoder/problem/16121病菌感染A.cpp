#include <bits/stdc++.h>
#define MAXN 1002
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
int n, m;
int x, y;
vector<int> tmp(MAXN, 0);
vector<vector<int>> g(MAXN, tmp);

void bfs() {
  int flag = 1;
  int index = 1;
  while (flag) {
    flag = 0;
    // printf("%d 'st infect\n", index++);
    for (int i = 1; i <= n; ++i) {
      for (int j = 1; j <= n; ++j) {
        if (!g[i][j]) {
          g[i][j] =
              (g[i - 1][j] + g[i][j - 1] + g[i + 1][j] + g[i][j + 1]) >= 2;
          if (g[i][j]) {
            // printf("(%d, %d) is infected\n", i, j);
            flag = 1;
          }
        }
      }
    }
  }
  int ans = 0;
  for (int i = 1; i <= n; ++i) {
    // ans += sum(g[i].begin() + 1, g[i].begin() + n + 1);
    // copy(g[i].begin() + 1, g[i].begin() + n + 1, ostream_iterator<int>(cout,
    // " ")); cout << endl;
    ans += accumulate(g[i].begin() + 1, g[i].begin() + n + 1, 0);
  }
  // cout << ans << endl;
  if (ans >= n * n) {
    printf("YES\n");
  } else {
    printf("NO\n");
  }
}

int main() {
  cin >> n >> m;
  for (int i = 0; i < m; ++i) {
    cin >> x >> y;
    g[x][y] = 1;
  }
  bfs();
  return 0;
}
