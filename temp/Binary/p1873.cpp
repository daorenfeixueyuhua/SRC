#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAX = 1e5 + 1;
typedef long long ll;
bool cmp(const int &x, const int &y) { return x > y; }

ll N, M, H;
vector<ll> Tree(1000005, 0);
ll temp;

// 二分函数
ll check(ll &x) {
    ll ans = 0;
    for (int i = 0; i < N; ++i) {
        if (Tree[i] > x)
            ans = ans - x + Tree[i];
    }
    return ans;
}
// 解析：https://blog.csdn.net/rigeman__ZHN/article/details/81637623
int main() {
    cin >> N >> M;
    for (int i = 0; i < N; ++i) {
        cin >> Tree[i];
        temp = max(temp, Tree[i]);
    }
    // 二分模板
    ll l = 1, r = temp;
    while (l <= r) {
        ll mid = (l + r) >> 1, q = check(mid);
        if (q < M)
            r = mid - 1;
        else
            l = mid + 1;
    }
    cout << r << endl;
    return 0;
}