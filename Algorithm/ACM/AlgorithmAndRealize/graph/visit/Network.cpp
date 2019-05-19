#include <algorithm>
#include <stdio.h>
#include <iterator>
#include <iostream>
using namespace std;

const int V = 1e4;

int edge[V][V];
int brideg[V][V], cut[V];

int low[V], dfn[V], vis[V];

// vertex 0 ~ n-1
void cut_bridge(int cur, int father, int dep, int n)
{
    vis[cur] = 1;
    dfn[cur] = low[cur] = dep;
    int children = 0;
    for (int i = 0; i < n; ++i)
        if (edge[cur][i])
        {
            if (i != father && 1 == vis[i])
            {
                if (dfn[i] < low[cur])
                    low[cur] = dfn[i];
            }
            if (0 == vis[i])
            {
                cut_bridge(i, cur, dep + 1, n);
                children++;
                if (low[i] < low[cur])
                    low[cur] = low[i];
                if ((father == -1 && children > 1) || (father != -1 && low[i] >= dfn[cur]))
                    cut[cur] = true;
                if (low[i] > dfn[cur])
                {
                    brideg[cur][i] = brideg[i][cur] = true;
                }
            }
        }
}

int main()
{
    int N;
    while (cin >> N && N)
    {
        int a;
        int b;
        while (cin >> a && a)
        {
            a--;
            while (getchar() != '\n')
            {
                cin >> b;
                b--;
                edge[a][b] = 1;
                edge[b][a] = 1;
            }
            cut_bridge(a, -1, 0, N);
        }
        int C = 0;
        // for (int i = 0; i < N;++i)
        //     for (int j = 0; j < N;j++)
        //         if(brideg[i][j])
        //             C++;
        for (int i = 0; i < N; ++i)
            if (cut[i])
                C++;
        for (int i = 0; i < N; ++i){
            copy(edge[i], edge[i]+N, ostream_iterator<int>(cout, " "));
            
        }

                copy(cut, cut + N, ostream_iterator<int>(cout, " "));
        cout << C << endl;
    }
    return 0;
}