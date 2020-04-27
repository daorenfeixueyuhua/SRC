#include <algorithm>
#include <bitset>
#include <iostream>
#include <iterator>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#define MAXN 102
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

int n;
string tmp1(MAXN, '0');
vector<string> tmp2(MAXN, tmp1);
vector<vector<string>> G(MAXN, tmp2);
vector<int> tmp4(MAXN, 0);
vector<vector<int>> tmp5(MAXN, tmp4);

double interVal(int x, int y, int z, int i, int j, int k) {
    return sqrt(pow(x - i, 2) + pow(y - j, 2) + pow(z - k, 2));
}

// 深搜版，可能不行
int dfs(vector<vector<vector<int>>> Vaild, int x, int y, int z) {
    if (x == n && y == n && z == n) {
        // printf("-->(%d, %d, %d)\n", x, y, z);
        return 1;
    }
    if (Vaild[x][y][z] == 1 or G[x][y][x] == '*') {
        // printf("-->(%d, %d, %d)\n", x, y, z);

        cout << Vaild[x][y][z] << endl;
        cout << G[x][y][x] << endl;

        return INF;
    }
    Vaild[x][y][z] = 1;
    // printf("-->(%d, %d, %d)\n", x, y, z);
    int ans = INF;
    for (int i = 1; i <= n; ++i)

        for (int j = 1; j <= n; ++j)
            for (int k = 1; k <= n; ++k) {
                vector<vector<vector<int>>> tmp3 = Vaild;
                if (interVal(x, y, z, i, j, k) == 1 && !tmp3[i][j][k] &&
                    G[i][j][k] == '.') {
                    ans = min(ans, dfs(tmp3, i, j, k));
                }
            }
    return ans + 1;
}

int bfs(vector<vector<vector<int>>> Vaild, int x, int y, int z) {


    
}

int main() {
    string s;
    cin >> n;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; j++) {
            cin >> s;
            s.insert(s.begin(), '*');
            G[i][j] = s;
        }
    int ans = 0;
    vector<vector<vector<int>>> Vaild(MAXN, tmp5);
    ans = dfs(Vaild, 1, 1, 1);
    if (ans >= INF) {
        ans = -1;
    }
    cout << ans << endl;
    return 0;
}
