// 小Y和小B睡觉觉
// 链接：https://ac.nowcoder.com/acm/problem/14944

// 假设当前的时间为yyyy - mm -dd hh : mm:
// ss，他们两个会一觉睡t秒，请问他们睡醒的时刻是几天以后（过了晚上12点就算一天）？

#include <bits/stdc++.h>
using namespace std;
int isLeap(int &yy) { return !(yy % 400) or (!(yy % 4) and (yy % 100)); }

int getMonth(int y, int &m) {
    if (m == 2)
        return 28 + isLeap(y);
    if (m <= 7)
        return 30 + m % 2;
    if (m >= 8)
        return 30 + (m + 1) % 2;
}

void getEndTime(int yyyy, int mm, int dd, int hh, int MM, int ss, int t) {
    for (int i = 0; i < t; ++i) {
        ss++;
        if (ss == 60) {
            MM++;
            ss = 0;
        }
        if (MM == 60) {
            hh++;
            MM = 0;
        }
        if (hh = 24) {
            dd++;
            hh = 0;
        }
        if (dd == getMonth(yyyy, mm)) {
            mm++;
            dd = 1;
        }
        if (mm == 12) {
            yyyy++;
            mm = 1;
        }
    }
    printf("%d-%d-%d %02d:%02d:%02d\n", yyyy, mm, dd, hh, MM, ss);
}
int main() {
    int yyyy, mm, dd, hh, MM, ss, t;
    scanf("%d-%d-%d %d:%d:%d", &yyyy, &mm, &dd, &hh, &MM, &ss);
    cin >> t;
    // getEndTime(yyyy, mm, dd, hh, MM, ss, t);
    ss += t;
    MM += ss / 60;
    ss %= 60;
    hh += MM / 60;
    MM %= 60;
    int ans = hh / 24;
    hh %= 24;
    dd += ans;
    cout << ans << endl;
    // printf("%d-%d-%d %02d:%02d:%02d\n", yyyy, mm, dd, hh, MM, ss);

    return 0;
}