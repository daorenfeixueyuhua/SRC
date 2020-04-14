#include <bits/stdc++.h>
using namespace std;

int isLeap(int &yy) { return !(yy % 400) or (!(yy % 4) and (yy % 100)); }

int getMonth(int y, int &m) {
    if (m == 1)
        return 31;
    if (m == 2)
        return 28 + isLeap(y);
    if (m <= 7)
        return 30 + m % 2;
    if (m >= 8)
        return 30 + (m + 1) % 2;
}

int main() {
    int y, m;
    while (cin >> y >> m and y) {
        cout << isLeap(y) << endl;
        cout << getMonth(y, m) << endl;
    }

    return 0;
}