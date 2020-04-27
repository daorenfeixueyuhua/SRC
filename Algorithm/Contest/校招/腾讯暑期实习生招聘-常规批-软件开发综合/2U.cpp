#include <bits/stdc++.h>
using namespace std;

typedef long long LL;
const LL maxn = 100002;

double length(pair<double, double> a, pair<double, double> b) {
  return sqrt(pow(a.first - b.first, 2) + pow(a.second - b.second, 2));
}

int main() {
  int t, n;
  cin >> t;
  while (t--) {
    double x, y;
    vector<pair<double, double>> A(maxn, {0, 0}), B(maxn, {0, 0});
    cin >> n;
    for (int i = 0; i < n; ++i) {
      cin >> x >> y;
      A[i] = {x, y};
    }
    for (int i = 0; i < n; ++i) {
      cin >> x >> y;
      B[i] = {x, y};
    }
    double ans = 1e9;
    for (int i = 0; i < n; i++) {
      for (int j = 0; j < n; ++j) {
        ans = min(ans, length(A[i], B[j]));
      }
    }

    cout.setf(ios_base::fixed);
    cout << setprecision(3) << ans << endl;
    // cout << int(ans) << ".";
    // int k = (ans - int(ans)) * 1000;
    // string s = to_string(k);
    // while (s.size() < 3) {
    //   s.push_back('0');
    // }
    // cout << s << endl;
  }

  return 0;
}