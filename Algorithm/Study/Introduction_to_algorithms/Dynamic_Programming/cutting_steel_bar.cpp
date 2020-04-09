#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;
// 递归版
int cut_rod(const vector<int> &p, int n)
{
    if (n == 0)
        return 0;
    int q = -INT_MAX;
    for (int i = 1; i <= n; ++i)
        q = max(q, p[i] + cut_rod(p, n - i));
    return q;
}

int memoriezed_cut_ord_aux(const vector<int> &p, vector<int> &r, int n)
{
    if (r[n] >= 0)
        return r[n];
    int q;
    if (n == 0)
        q = 0;
    else
    {
        q = -INT_MAX;
        for (int i = 1; i <= n; ++i)
            q = max(q, p[i] + memoriezed_cut_ord_aux(p, r, n - i));
    }
    r[n] = q;
    return q;
}

// 自顶向下（带备忘）
int memoriezed_cut_rod(const vector<int> &p, int n)
{
    vector<int> r(n + 1, 0);
    fill(r.begin(), r.end(), -INT_MAX);
    return memoriezed_cut_ord_aux(p, r, n);
}

// 自低向上
int bottom_up_cut_rod(const vector<int> &p, int n)
{
    vector<int> r(n + 1, 0); // 记录长度为j的最优解
    for (int j = 1; j <= n; ++j)
    {
        int q = -INT_MAX;
        for (int i = 1; i <= j; ++i) // 求解长度为 i 和 j-i 的最优解
            q = max(q, p[i] + r[j - i]);
        r[j] = q;
    }
    return r[n];
}
// 记录切割方案
void extended_bottom_cut_rod(const vector<int> &p, int n, vector<int> &r, vector<int> &s)
{
    for (int j = 1; j < n; j++)
    {
        int q = -INT_MAX;
        for (int i = 1; i <= j; ++i)
        {
            if (q < p[i] + r[j - i])
            {
                q = p[i] + r[j - i];
                s[j] = i;
            }
        }
        r[j] = q;
    }
}

void print_cut_rod_solution(const vector<int> &p, int n)
{
    vector<int> r(n + 1, 0), s(n + 1, 0);
    extended_bottom_cut_rod(p, n, r, s);
    cout << r[n] << endl;
    while (n > 0) // error：死循环
    {
        cout << s[n] << " ";
        n = n - s[n];
    }
    cout << endl;
}

int main()
{
    int k = 10;
    vector<int> p(k + 1, 0);
    for (int i = 1; i <= k; ++i)
        cin >> p[i];
    int n;
    cin >> n;
    cout << bottom_up_cut_rod(p, n) << endl;
    // print_cut_rod_solution(p, n);
    return 0;
}