// Number Sequence
#include <bits/stdc++.h>
using namespace ::std;
const int mod = 7;
fstream fout("./out", ios::out);
// 超水版本
int f1(int A, int B, int n)
{
    vector<int> v(48, 0);
    v[1] = 1;
    v[2] = 1;
    for (int i = 3; i < 48; ++i)
        v[i] = (A * v[i - 1] + B * v[i - 2]) % mod;
    return v[n % 48];
}

int f1_print(int A, int B, int n)
{
    vector<int> v(n, 0);
    v[1] = 1;
    v[2] = 1;
    for (int i = 3; i < n; ++i)
        v[i] = (A * v[i - 1] + B * v[i - 2]) % mod;
    copy(v.begin(), v.end(), ostream_iterator<int>(fout, " "));
    fout << endl;
    return v[n % 48];
}
int f2(int A, int B, int n)
{
    int i;
    int F[60] = {0};
    F[0] = 1, F[1] = 1;
    // 存在循环节
    for (i = 2; i < n; ++i)
    {
        F[i] = (A * F[i - 1] + B * F[i - 2]) % mod;
        // 周期数判断有误
        if (F[i] == 1 && F[i - 1] == 1 || i == 50)
            break;
    }
    // i 为最小周期数
    cout << F[n % i] << endl;
    fout << "loop end is : " << i << " ";
    copy(F, F + 50, ostream_iterator<int>(fout, " "));
    fout << endl;
    fout.close();
    return F[n % i];
}
int main()
{

    int A = 0, B = 0, n = 0, i, flag = -1;
    while (cin >> A >> B >> n, A || B || n)
    {
        cout << f1_print(A, B, n) << endl;
    }
    fout.close();
    return 0;
}