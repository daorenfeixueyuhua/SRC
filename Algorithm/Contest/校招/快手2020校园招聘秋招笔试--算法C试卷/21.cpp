#include <bits/stdc++.h>
using namespace std;

class Time {
  public:
    // 任务到达时间分为
    int st, et;
    // 最少花费时间
    int ct;
    // 任务开始执行时间
    int stt;
    // 结束时间
    int ftt;
    Time(int _st, int _et) {
        st = _st;
        et = _et;
        ct = ceil((et - st) / 2);
        // cout << ct << " " << ct % 2 << endl;
        if (ct or ct % 2 == 0)
            ct++;
    }
    void setCt() {
        ct = ceil((et - st) / 2);
        // cout << ct << " " << ct % 2 << endl;
        if (ct or ct % 2 == 0)
            ct++;
    }
    void show() {
        cout << st << " " << et << " " << ct << " " << stt << " " << ftt
             << endl;
    }
};

bool cmp(const Time &t1, const Time &t2) {
    if (t1.st == t2.st)
        return t1.ct < t2.ct;
    return t1.st < t2.st;
}

int run(vector<Time> &times) {
    cout << "run:      " << endl;
    int falg = 1;
    stack<Time> S;
    times[0].stt = times[0].st;
    times[0].ftt = times[0].stt + times[0].ct;
    S.push(times[0]);
    // S.top().show();
    times.erase(times.begin());
    Time tmp(0, 0), cur(0, 0);
    while (!times.empty()) {
        tmp = S.top();
        tmp.stt = tmp.st;
        tmp.ftt = tmp.stt + tmp.ct;
        // 从剩下的任务中查询下一个任务
        for (int i = 0; i < times.size(); i++) {
            // 上一个的结束在该开始之前
            if (times[i].st <= tmp.ftt) {
                cur = times[i];
                times.erase(times.begin() + i);
                break;
            }
        }
        cur.stt = tmp.ftt;
        cur.ftt = cur.stt + cur.ct;
        S.push(cur);
        // S.top().show();
        if (!cur.st) {
            falg = -1;
            break;
        }
    }
    return falg;
}

// 内存超了
int main() {
    int n;
    cin >> n;
    vector<Time> times(n, Time(0, 0));
    for (int i = 0; i < n; ++i) {
        cin >> times[i].st >> times[i].et;
        times[i].setCt();
    }

    sort(times.begin(), times.end(), cmp);
    // for (int i = 0; i < n; ++i)
    //     times[i].show();
    cout << run(times) << endl;
    return 0;
}
/**
3
3 10
1 5
4 6
 * */

// 1 5 4 3
// 3 10 7 4
// 4 6 2 2
