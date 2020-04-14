#include <bits/stdc++.h>
using namespace std;
int main()
{
    int n;
    while (scanf("%d", &n) != EOF)
    {
        int k = 2 * n + 1;
        string s(k, '0');
        vector<string> G(k, s);
        int v[k][k] = {0};
        int cnt = 0;
        int i = 0, j = 0;
        while (1)
        {
            if (k * k <= cnt)
                break;

            cout << cnt << endl;
            // 向右走
            while (j < G.size() && v[i][j] != 1)
            {
                G[i][j] = cnt % 26 + 'a';
                v[i][j] = 1;
                j++;
                cnt++;
                cout << "(" << i << "," << j << "), ";
            }
            j--;
            // 向下走
            while (i < G.size() && v[i][j] != 1)
            {
                G[i][j] = cnt % 26 + 'a';
                v[i][j] = 1;
                i++;
                cnt++;
                cout << "(" << i << "," << j << "), ";
            }
            i--;
            // 向左走
            while (0 <= j && v[i][j] != 1)
            {
                G[i][j] = cnt % 26 + 'a';
                v[i][j] = 1;
                j--;
                cnt++;
                cout << "(" << i << "," << j << "), ";
            }
            j++;
            // 向上走
            while (0 <= i && v[i][j] != 1)
            {
                G[i][j] = cnt % 26 + 'a';
                i--;
                cnt++;
                cout << "(" << i << "," << j << "), ";
            }
            i++;
        }
        for (int i = 0; i < G.size(); ++i)
        {
            cout << G[i] << endl;
        }
    }

    return 0;
}