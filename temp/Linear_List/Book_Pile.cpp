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

int cmp(const int x, const int y) { return x < y; }
ll n, m, k, temp = 0;

//需要翻转的部分
deque<char> q;
//不需要翻转的部分
vector<char> v;

string s;

bool front = 1;
// - a book is added to the top of the pile,
// - top K books are rotated.If there are less than K books on the table, the
// whole pile is rotated.
/**
 * B C A D
 * */
// 题目链接：http://www.voidcn.com/article/p-esstylmz-bga.html
// Splay解决方案：https://blog.csdn.net/niuox/article/details/8018280
/**
 * 此题的核心之处在于需要记录每一次队列翻转的方向。
 *
 * */
int main() {
    cin >> n >> m >> k;
    for (int i = 0; i < n; ++i) {
        cin >> s;
        // 自顶到下 B A
        q.push_front(s[0]);
    }
    temp = n;
    for (int i = 0; i < m; ++i) {
        cin >> s;
        if (temp > k) {
            if (front) { // 正向
                v.push_back(q.front());
                q.pop_front();
            } else { // 反向
                v.push_back(q.back());
                q.pop_back();
            }
        }
        if (s[0] != 'A') {
            front = !front;
            continue;
        }
        if (front) {
            q.push_back(s[4]);
            temp++;
        } else {
            q.push_front(s[4]);
            temp++;
        }
        // copy(v.begin(), v.end(), ostream_iterator<char>(cout, " "));
        // cout << "| ";
        // copy(q.begin(), q.end(), ostream_iterator<char>(cout, " "));
        // cout << "direction: " << front << endl;
    }
    // for (deque<char>::iterator it = q.begin(); it != q.end(); ++it)
    //     cout << *it << endl;
    // copy(v.begin(), v.end(), ostream_iterator<char>(cout, "\n"));
    // copy(q.begin(), q.end(), ostream_iterator<char>(cout, "\n"));
    if (front)
        copy(q.rbegin(), q.rend(), ostream_iterator<char>(cout, "\n"));
    else
        copy(q.begin(), q.end(), ostream_iterator<char>(cout, "\n"));
    copy(v.rend(), v.rbegin(), ostream_iterator<char>(cout, "\n"));
    copy(v.rbegin(), v.rend(), ostream_iterator<char>(cout, "\n"));

    return 0;
}