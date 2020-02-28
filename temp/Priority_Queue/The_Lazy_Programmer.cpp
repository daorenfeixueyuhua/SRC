#include <bits/stdc++.h>
using namespace std;
typedef long long ll;

const ll MAXN = 100005;
ll N = 0L, T = 0L, ans = 0L;
typedef struct Task {
    int index;
    ll a, b, d;
    double momey;
} Task;

Task A[MAXN], cur;

priority_queue<Task> Q;

bool cmp(Task &x, Task &y) { return x.d > y.d; }
/*
2
20 50 100
10 100 50
*/
/**
 *
 * 解决方案：
 * https://www.cnblogs.com/zfyouxi/p/5356685.html
 */
int main() {
    cin >> N;
    for (int i = 0; i < N; ++i) {
        cin >> A[i].a >> A[i].b >> A[i].d;
        A[i].index = i + 1;
        A[i].momey = 0;
    }
    sort(A, A + N, cmp);
    while (!Q.empty())
        Q.pop();
    for (int i = 0; i < N; ++i) {
        Q.push(A[i]);
        T += A[i].d;
        while (T > A[i].d) {
            cur = Q.top();
            Q.pop();
            double temp = double(T - A[i].b) / cur.a;
            if (temp + cur.momey < double(cur.b) / cur.a) {
                T -= temp * cur.a;
                cur.momey += temp;
                ans += temp;
                Q.push(cur);
                break;
            } else {
                temp = double(cur.b) / cur.a - cur.momey;
                T -= temp + cur.a;
                ans += temp;
            }
        }
    }
    cout << setprecision(2) << ans << endl;
    return 0;
}