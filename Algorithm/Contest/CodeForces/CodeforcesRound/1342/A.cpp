#include <bits/stdc++.h>
using namespace std;

int main() {
  int T;
  int x, y, a, b;
  cin >> T;
  while (T--) {
    cin >> x >> y;
    cin >> a >> b;
    if (!x and !y) {
      cout << 0 << endl;
      continue;
    }
    int cost = min(x, y) * b + (max(x, y) - min(x, y)) * a;
    cout << cost << endl;
  }

  return 0;
}