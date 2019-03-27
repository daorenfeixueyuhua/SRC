#include <iostream>
#include <vector>
#include <limits.h>
#include <algorithm>
using namespace std;
int cut_rod(vector<int> &p, int n)
{
    if (n == 0)
        return 0;
    int q = -INT_MAX;
    for (int i = 1; i <= n; ++i)
        q = max(q, p[i] + cut_rod(p, n - 1));
    return q;
}

int main()
{
    int k = 10;
    vector<int> p(k + 1, 0);
    for (int i = 1; i <= k; ++i)
        cin >> p[i];
    int n;
    cin >> n;
    cout << cut_rod(p, n) << endl;
    cin.get();
    cin.get();
    return 0;
}