#include <bits/stdc++.h>
using namespace::std;
int main(){
    int n;
    while(cin >> n && n){
        int H[n], J[n];
        for(int i=0;i<n;i++)
            cin >> H[i];
        for(int i=0;i<n;i++)
            cin >> J[i];
        sort(H, H+n);
        sort(J, J+n);
        int scoreH=0, scoreJ=0;
        for(int i=0;i<n;i++){
            if(H[i]>J[i])
                scoreH += 2;
            else if(H[i]==J[i]){
                scoreH += 1;
                scoreJ += 1;
            }else
                scoreJ += 2;
        }
        cout << scoreH << " vs " << scoreJ << endl;
    }

    return 0;
}