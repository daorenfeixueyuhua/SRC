#include <bits/stdc++.h>

using namespace std;

int main()
{
    double n, m, a;
    cin >> n >> m >> a;
    // 1000000000 1000000000 999999999
    // 本机计算为4
    // 但是系统计算为1
    long long reslut = ceil(n / a) * ceil(m / a);
    // cout.unsetf(ios::scientific);
    cout << reslut << endl;
    return 0;
}
