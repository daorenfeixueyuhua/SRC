// 简单排序
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
const LL mod = 1e9 + 7;

LL n, q, kk;

int f1(int a, int b, int c) { return a + b > c and a + c > b and b + c > a; }

// O(N^4)
LL run(const vector<int> &src) {
    LL ans = -1;
    LL len = src.size();
    for (int i = len - 1; i > 2; --i) {       // 枚举C
        for (int j = i - 1; j > 1; --j) {     // 枚举B
            for (int k = j - 1; k > 0; --k) { // 枚举A
                if (f1(src[i], src[j], src[k])) {
                    // 三角形成立条件，任意a, b, c 满足 a+b>c and a-b<c
                    ans = src[i] + src[j] + src[k];
                    // printf("(%ld, %ld, %ld)\n", src[i], src[j], src[k]);
                    return ans;
                }
            }
        }
    }
    return ans;
}

LL run_maj(const vector<int> v) {
    LL ans = 0;
    int cnt = 0;
    for (int i = v.size() - 1; i > 0; --i) {
        ans += v[i];
        cnt++;
        if (cnt == 3) {
            if (v[i] + v[i + 1] > v[i] + 2) {
                return ans;
            } else {
                ans -= v[i];
                cnt--;
            }
        }
    }
    return -1;
}

int main() {
    cin >> n >> q;
    vector<int> src(n + 1, 0), temp;
    for (int i = 1; i <= n; ++i)
        cin >> src[i];
    while (q--) {
        cin >> kk;
        temp = src;
        temp.erase(temp.begin() + kk);
        sort(temp.begin(), temp.end());
        cout << run_maj(temp) << endl;
    }
    return 0;
}
