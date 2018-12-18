#include <bits/stdc++.h>
using namespace::std;
int main(){
    int T;
    cin >> T;
    while(T--){
        int m, n, result=0;
        cin >> m;
        for(int i=0;i<m;i++){
            cin >> n;
            result += n;
        }
        cout << result << endl;
    }
    return 0;
}