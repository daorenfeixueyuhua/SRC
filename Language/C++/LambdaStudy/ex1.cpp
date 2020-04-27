#include <bits/stdc++.h>
using namespace std;

int cmp(int a, int b) { return a < b; }

int main() {
  vector<int> v1 = {9, 8, 6, 5, 4, 5};
  vector<int> v2(v1);
  sort(v1.begin(), v1.end(), cmp);
  for (int it : v1) {
    cout << it << " ";
  }
  cout << endl;
  sort(v2.begin(), v2.end(), [](int a, int b) -> bool { return a < b; });
  copy(v2.begin(), v2.end(), ostream_iterator<int>(cout, " "));
  cout << endl;
  return 0;
}