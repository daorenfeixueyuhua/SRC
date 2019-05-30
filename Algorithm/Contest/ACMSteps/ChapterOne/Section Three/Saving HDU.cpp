#include <bits/stdc++.h>
using namespace::std;
struct T{
    int p, m;
};
bool cmp(const T a, const T b){
    return a.p>b.p;
}

int main(){
    int v, n;
    while(cin >> v && v){
        cin >> n;
        struct T t[n];
        for(int i=0;i<n;++i)
            cin >> t[i].p >> t[i].m;
        sort(t, t+n, cmp);
        int ans = 0, cnt = 0;
        for(int i=0;i<n;++i){
            for(int j=0;j<t[i].m;++j){
                if(cnt<v){
                    ans += t[i].p;
                    cnt ++;
                }else{}
            }
        }
        cout << ans << endl;
    }
    return 0;
}