#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
typedef long long ll;
const ll MAX = 1e5 + 1;

bool cmp(const int &x, const int &y) { return x > y; }

ll n, m, k, temp;
vector<ll> A(MAX, 0), B(MAX, 0);

ll check1(ll i, ll j, ll x) { return cmp(x, A[i] * B[j]); }

ll check(ll x) {
    int ans = 0;
    for (int i = 0; i < n; ++i) {
        ll l = 1, r = m, q;
        while (l <= r) {
            ll mid = (l + r) >> 1;
            // cout << l << " " << mid << " " << r << " " << x << endl;
            if (A[i] * B[mid - 1] < x) //  这里不是二分答案，而是二分查找
                l = mid + 1;
            else
                r = mid - 1;
        }
        // cout << A[i] << "*B[j]< " << x << " is " << r << endl;
        ans += r;
    }
    cout << ans << endl;
    return ans;
}

int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i)
        cin >> A[i];
    for (int i = 0; i < m; ++i)
        cin >> B[i];

    sort(&A[0], &A[n]);
    sort(&B[0], &B[m]);
    // output vector
    // copy(A.begin(), A.begin() + n, ostream_iterator<ll>(cout, " "));
    // cout << endl;
    // copy(B.begin(), B.begin() + m, ostream_iterator<ll>(cout, " "));
    // cout << endl;
    temp = A[n - 1] * B[m - 1];
    ll l = 1, r = temp, q;
    while (l <= r) {
        ll mid = (l + r) >> 1;
        q = check(mid); // 统计　满足　A[i][j] < mid ｊ的个数
        // cout << "A[i]*B[j]< " << mid << " is " << q << endl;
        q = n * m - q;
        if (q < k) // 二分答案
            r = mid - 1;
        else
            l = mid + 1;
    }
    cout << "max values: " << temp << endl;
    cout << r << endl;
    return 0;
}
// 1 2 2 3 4 6