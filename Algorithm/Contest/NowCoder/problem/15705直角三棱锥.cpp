// 直角三棱锥
// https: // ac.nowcoder.com/acm/problem/15705
#include <bits/stdc++.h>
using namespace std;

int main() {
    long long t, k, m;
    cin >> t;
    while (t--) {
        cin >> k >> m;
        long long ans = 1LL * (k + 3) * (k + 2) % (m * 6);
        ans *= (k + 1) % (6 * m) / 6;
        cout << ans << endl;
    }
    return 0;
}