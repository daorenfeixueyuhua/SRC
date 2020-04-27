#include <algorithm>
#include <bitset>
#include <iostream>
#include <iterator>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#define MAXN 3002
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

LL n, K;
vector<LL> N(MAXN, 0L);

int main() {
  cin >> n >> K;
  for (int i = 0; i < n; ++i)
    cin >> N[i];
  sort(N.begin(), N.end(), [](LL a, LL b) { return a < b; });
  // if (K <= N[0] or N[n - 1] < K / 3) {
    // cout << "wo yo wo yo~" << endl;
    // return 0;
  // }
  for (int i = 0; i < n; ++i)
    for (int j = i; j < n; ++j)
      for (int k = j; k < n; ++k)
        if (N[i] + N[j] + N[k] == K) {
          cout << "o hu~" << endl;
          return 0;
        }
  cout << "wo yo wo yo~" << endl;
  return 0;
}
