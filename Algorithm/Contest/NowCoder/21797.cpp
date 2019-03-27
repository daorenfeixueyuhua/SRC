#include <iostream>
#include <vector>
#include <string>

using namespace std;

int max(const int &a, const int &b, const int &c, const int &d)
{
    int max = a;
    if (max < b)
        max = b;
    if (max < c)
        max = c;
    if (max < d)
        return d;
}

int move(vector<string> vs, int k, int m, int n)
{
    cout << k << " " << m << " " << n << endl;
    if(k<=0)
        return k;
    else if (m < 0 || vs.size() <= m || n < 0 || vs[m].size() <= n || vs[m][n] == '#')
        return k - 1;
    else if (vs[m][n] == 'E')
        return -1;
    else if (vs[m][n] = '.')
    {
        return max(move(vs, k - 1, m - 1, n), move(vs, k - 1, m, n - 1), move(vs, k - 1, m + 1, n), move(vs, k - 1, m, n + 1));
    }
    else if (vs[m][n] == 'T')
    {
        return max(move(vs, k, m - 1, n), move(vs, k, m, n - 1), move(vs, k, m + 1, n), move(vs, k, m, n + 1));
    }
}

int main()
{
    int r, c, k;
    cin >> r >> c >> k;
    vector<string> vs;
    int m = 0, n = 0;
    for (int i = 0; i < r; i++)
    {
        string s;
        cin >> s;
        vs.push_back(s);
    }
    for (int i = 0; i < r; i++)
    {
        cout << vs[i] << endl;
    }
    for (int i = 0; i < r; i++)
        for (int j = 0; j < c; j++)
            if (vs[i][j] == 'T')
            {
                m = i;
                n = j;
            }
    cout << move(vs, k, m, n) << endl;
    cin.get();
    cin.get();
    return 0;
}