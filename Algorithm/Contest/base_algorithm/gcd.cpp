#include <bits/stdc++.h>
using namespace std;
typedef long long ll;
ll gcd(const ll &a, const ll &b) { return !b ? a : gcd(b, a % b); }
ll lcm(const ll &a, const ll &b) { return a / gcd(a, b) * a; }
int main() {
    int a, b;
    while (cin >> a >> b and (a and b)) {
        cout << gcd(a, b) << endl;
    }

    return 0;
}