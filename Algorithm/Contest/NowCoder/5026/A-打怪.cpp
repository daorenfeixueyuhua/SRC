#include <bits/stdc++.h>
using namespace std;
int main() {
    int t = 0;
    cin >> t;
    while (t--) {
        int h, a, H, A;
        int ans = 0;
        cin >> h >> a >> H >> A;
        // 进行预先判断
        if (a >= H and A == 0) {
            cout << -1 << endl;
            continue;
        }
        if (a == 0) {
            cout << 0 << endl;
            continue;
        }
        while (h > 0) {
            int tmp = H;
            while (tmp) {
                if (h > 0)
                    tmp -= a;
                else
                    break;
                if (tmp > 0)
                    h -= A;
                else
                    break;
            }
            if (h > 0 and tmp <= 0)
                ans += 1;
        }
        cout << ans << endl;
    }
    return 0;
}