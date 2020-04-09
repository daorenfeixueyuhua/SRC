#include <bits/stdc++.h>

using namespace std;

bool comp(pair<double, double> p1, pair<double, double> p2)
{
    double d1 = p1.first * p1.first + p1.second * p1.second;
    double d2 = p2.first * p2.first + p2.second * p2.second;
    // cout << p1.first << " " << p2.first << endl;
    if (p1.first < 0)
        d1 = 0 - d1;
    if (p2.first < 0)
        d2 = 0 - d2;
    // cout << d1 << " " << d2 << endl;
    return d1 < d2 ? 1 : 0;
}
bool comp1(double d1, double d2)
{
    return d1 < d2 ? 1 : 0;
}

int main()
{
    int N;
    while (cin >> N && N)
    {
        double x, y;
        vector<pair<double, double>> v(N);
        // 两个点之间距离(1,2),(2,3)...(n-1, n)
        vector<double> d(N - 1, 0.0);
        for (int i = 0; i < N; i++)
        {
            cin >> x >> y;
            v[i].first = x;
            v[i].second = y;
        }
        sort(v.begin(), v.end(), comp);
        for (int i = 0; i < N - 1; ++i)
        {
            d[i] = sqrt(pow(v[i].first - v[i + 1].first, 2) + pow(v[i].second - v[i + 1].second, 2));
        }
        sort(d.begin(), d.end());
        // copy(d.begin(), d.end(), ostream_iterator<double>(cout, " "));
        // cout << endl;
        // double minVal = INT_MAX;

        // for (vector<double>::iterator it = d.begin(); it != d.end(); ++it)
        // {
        // if (minVal > *it)
        // minVal = *it;
        // }
        cout.precision(2);

        cout << d[0] / 2 << endl;
    }
    return 0;
}