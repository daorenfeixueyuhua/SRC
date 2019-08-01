#include <bits/stdc++.h>
using namespace std;
void print(int elem){
    cout << elem << ' ';
}
int main(){
    int T;
    cin >> T;
    while(T--){
        int n, v;
        cin >> n >> v;
        int B[n+1][v+1] = {0};
        vector<int> Va(n + 1, 0), Vo(n + 1, 0);
        for (int i = 1; i <= n;++i)
            cin >> Va[i];
        for (int i = 1; i <= n;++i)
            cin >> Vo[i];
        // for_each(Va.begin(), Va.end(), print);
        // for_each(Vo.begin(), Vo.end(), print);
        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= v; ++j)
            {
                if (j < Vo[i])
                {
                    B[i][j] = B[i - 1][j];
                }
                else
                {
                    B[i][j] = max(B[i - 1][j], B[i - 1][j - Vo[i]] + Va[i]);
                }
            }
        }
        // for (int i = 1; i <= n;++i){
        //     for_each(B[1], B[1] + v, print);
        //     cout << endl;
        // }
        cout << B[n][v] << endl;
    }
    return 0;
}