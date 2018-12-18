#include <bits/stdc++.h>
using namespace::std;
const int modVal=10;
int main(){
    int T;
    cin >> T;
    while(T--){
        int n, d=1;
        int c=0;
        cin >> n;
        bitset<64> N(n);
        for(int i=32;i>=0;i--){
            c=2*c;
            d=(d*d)%modVal;
            if(N[i]==1){
                c=c+1;
                d=(d*n)%modVal;
            }
        }
        cout << d << endl;
    }
    return 0;
}
