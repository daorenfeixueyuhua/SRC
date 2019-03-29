#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
const int MAXN = 20;
int main()
{
    vector<int> v(MAXN, 0);
    for (int i = 0; i < MAXN; i++)
        v[i] = i + 1;

    for (int i = 0; i < MAXN; i++)
        cout << v[i] << " ";
    cout << endl;
    // 随机排序
    random_shuffle(v.begin(), v.end());
    for (int i = 0; i < MAXN; i++)
        cout << v[i] << " ";
    cout << endl;

    cin.get();
    cin.get();
    return 0;
}