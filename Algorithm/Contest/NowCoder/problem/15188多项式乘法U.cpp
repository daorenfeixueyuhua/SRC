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
#define MAXN 504
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

// 多项式的系数
vector<int> L1(MAXN, 0);
vector<int> L2(MAXN, 0);
vector<int> L3(MAXN * 2, 0);
LL n, m;

// 过96%
int main() {
    cin >> n >> m;
    for (int i = 0; i <= n; ++i)
        cin >> L1[i];
    for (int i = 0; i <= m; ++i)
        cin >> L2[i];
    for (int i = 0; i <= n; ++i) {
        for (int j = 0; j <= m; ++j) {
            L3[i + j] += L1[i] * L2[j];
        }
    }
    // 需要输出全部系数（包括0）
    for (int i = 0; i <= m + n; ++i) {
        cout << L3[i];
        if (i != m + n)
            cout << " ";
    }
    // cout << endl;
    return 0;
}
