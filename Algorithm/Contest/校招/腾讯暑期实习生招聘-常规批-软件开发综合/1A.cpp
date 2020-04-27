#include <bits/stdc++.h>
using namespace std;
const int maxn = 100000;
int main() {
  int t;
  cin >> t;
  int op;
  while (t--) {
    queue<int> q;
    int cnt;
    cin >> cnt;
    for (int i = 0; i < cnt; ++i) {
      string s;
      int x;
      // scanf("%s %d", &s, &x);
      cin >> s;
      if (s == "PUSH") {
        cin >> x;
      }
      // cout << " OP " << s << " " << x << endl;
      if (s == "PUSH") {
        q.push(x);
      }
      if (s == "TOP") {
        if (q.empty()) {
          cout << "-1" << endl;
        } else {
          cout << q.front() << endl;
        }
      }
      if (s == "POP") {
        if (q.empty()) {
          cout << "-1" << endl;
        } else {
          q.pop();
        }
      }
      if (s == "SIZE") {
        cout << q.size() << endl;
      }
      if (s == "CLEAR") {
        while (!q.empty()) {
          q.pop();
        }
      }
    }
  }
  return 0;
}