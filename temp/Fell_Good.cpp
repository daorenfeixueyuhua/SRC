#include <bits/stdc++.h>
#define L(x) (x << 1)
#define R(x) (x << 1 | 1)
#define MID(x, y) ((x + y) >> 1)

#define eps 1e-8
typedef __int64 ll;

#define fre(i, a, b) for (i = a; i < b; i++)
#define free(i, b, a) for (i = b; i >= a; i--)
#define mem(t, v) memset((t), v, sizeof(t))
#define ssf(n) scanf("%s", n)
#define sf(n) scanf("%d", &n)
#define sff(a, b) scanf("%d %d", &a, &b)
#define sfff(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define pf printf
#define bug pf("Hi\n")

using namespace std;

const int INF = 0x3f3f3f3f;

const int MAXN = 1e5 + 5;
const int MAX = 1e6 + 5;

int n;
vector<int> A(MAXN, 0), last(MAXN, 0), next1(MAXN, 0);
stack<int> S;

int cmp(const int x, const int y) { return x < y; }

// 未完成！
int main() {
    cin >> n;
    // srand(time(nullptr));

    for (int i = 0; i < n; ++i)
        A[i] = 1 + rand() / ((RAND_MAX + 1u) / 6);
    S.push(A[0]);
    for (int i = 1; i < n; ++i) {
        if (A[i] > S.top()) {
            S.push(A[i]);
            last[i] = i - 1;
        } else {
            while (A[i] < S.top() && !S.empty()) {
                S.push(A[i]);
            }
        }
    }
    copy(A.begin(), A.begin() + n, ostream_iterator<int>(cout, " "));
    cout << endl;
    copy(last.begin(), last.begin() + n, ostream_iterator<int>(cout, " "));
    cout << endl;
    copy(next1.begin(), next1.begin() + n, ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}