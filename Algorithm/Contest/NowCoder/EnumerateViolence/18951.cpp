#include <iostream>
#include <cstdio>
#include <time.h>
#include <vector>
#include <cstring>
using namespace std;

const int MAX = 1000;

int main()
{
    int n;
    cin >> n;
    vector<int> x(n);
    vector<int> y(n);
    int max_count = -1;
    int max_xy = -1;
    for (int i = 0; i < n; i++)
    {
        cin >> x[i];
        if (max_xy < x[i])
            max_xy = x[i];
    }
    for (int i = 0; i < n; i++)
    {
        cin >> y[i];
        if (max_xy < y[i])
            max_xy = y[i];
    }

    for (int c1 = -max_xy; c1 <= max_xy; ++c1)
        for (int c2 = -max_xy; c2 <= max_xy; ++c2)
        {
            int cnt = 0;
            vector<int> tmp(max_xy + 1, 0);
            vector<vector<int>> P(max_xy + 1, tmp);
            for (int i = 0; i < n; ++i)
            {
                if (y[i] == x[i] + c1 || y[i] == -x[i] + c2)
                {
                    if (P[x[i]][y[i]] == 0)
                    {
                        cnt++;
                        P[x[i]][y[i]] == 1;
                    }
                }
            }
            if (max_count < cnt)
                max_count = cnt;
        }
    cout << max_count << endl;
    cin.get();
    cin.get();
    return 0;
}
// 万通