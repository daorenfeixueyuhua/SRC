#include <bits/stdc++.h>
using namespace std;
const int maxn = 3;
int bfs(int k, int i, int j, int G[maxn][maxn]) {
    if (k == 0) {
        return 1;
    }
    if (G[i][j]) {
        return 0;
    }
    int ans = 0;
    G[i][j] = 1;
    for (int a = 0; a < maxn; ++a) {
        for (int b = 0; b < maxn; ++b) {
            if (!G[a][b]) {
                int falg = 1;
                // 需要进行判断该点是否可以访问
                double len = sqrt(pow(a - i, 2) + pow(b - j, 2));
                if (len == 2 or len == sqrt(8)) {
                    if (!G[(a + i) / 2][(b + j) / 2]) {
                        falg = 0;
                    }
                }
                if (falg) {
                    int tmp_G[maxn][maxn] = {0};
                    for (int p = 0; p < maxn; ++p)
                        for (int q = 0; q < maxn; ++q)
                            tmp_G[p][q] = G[p][q];
                    ans += bfs(k - 1, a, b, tmp_G);
                    // cout << i << " " << j << " into " << a << " " << b
                    //  << " result : " << ans << endl;
                }
            }
        }
    }
    return ans;
}
int main() {
    int m, n;
    cin >> m >> n;
    int ans = 0;
    for (int k = m; k <= n; ++k) {
        for (int i = 0; i < maxn; ++i) {
            for (int j = 0; j < maxn; ++j) {
                int tmp_G[maxn][maxn] = {0};
                ans += bfs(k - 1, i, j, tmp_G);
            }
        }
    }
    cout << ans << endl;
    return 0;
}
// # # #
// # # #
// # # #
