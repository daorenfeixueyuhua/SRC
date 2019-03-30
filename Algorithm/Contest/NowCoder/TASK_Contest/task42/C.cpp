#include <iostream>
#include <vector>
#include <cmath>
#include <algorithm>
#include <numeric>
using namespace std;

int main()
{
    int n, m;
    cin >> n >> m;

    vector<int> temp(n, 0);
    vector<vector<int>> S(m, temp);

    for (int i = 0; i < m; i++)
        for (int j = 0; j < n; j++)
            cin >> S[i][j];
    int sum = 0;
    // vector<int> t(m, 0);
    // vector<vector<int>> T(int(pow(n, m)), t);
    // for (int k = 0; k < int(pow(n, m)); k++)
    // {
    //     for (int i = 0; i < m; ++i)
    //     {
            
    //     }
    //     sort(t.begin(), t.end());
    //     unique(t.begin(), t.end());
    //     sum += accumulate(t.begin(), t.end(), 0);
    // }
    cout << sum << endl;
    return 0;
}