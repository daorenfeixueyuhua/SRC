#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
const int MAX = 4001;
typedef long long ll;
int main() {
    int n;
    vector<ll> A1(MAX, 0), A2(MAX, 0), A3(MAX, 0), A4(MAX, 0),
        Res(MAX * MAX, 0);
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> A1[i] >> A2[i] >> A3[i] >> A4[i];
    // 第一次遍历
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            Res.push_back(A1[i] + A2[j]);
    // 排序
    sort(Res.begin(), Res.end());
    // 第二次遍历
    int ans = 0;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j) {
            int temp_ans = -(A3[i] + A4[j]);
            ans += upper_bound(Res.begin(), Res.end(), temp_ans) -
                   lower_bound(Res.begin(), Res.end(), temp_ans);
        }
    cout << ans << endl;
    return 0;
}