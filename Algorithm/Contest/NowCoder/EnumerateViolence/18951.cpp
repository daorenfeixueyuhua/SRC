#include <iostream>
#include <cstdio>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 1000;

int main()
{
    int n;

    cin >> n;
    vector<int> x(MAX);
    vector<int> y(MAX);
    int max_count = -1;
    for (int i = 0; i < n; i++)
        cin >> x[i];
    for (int i = 0; i < n; i++)
        cin >> y[i];
    // 遍历 -MAX <= c1, c2 <= MAX
    for (int c1 = -MAX; c1 <= MAX; ++c1)
        for (int c2 = -MAX; c2 <= MAX; ++c2)
        {
                }
    cout << max_count << endl;
    cin.get();
    cin.get();
    return 0;
}