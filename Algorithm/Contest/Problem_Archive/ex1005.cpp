// Number Sequence
#include <iostream>
#include <cstdio>
using namespace ::std;
const int mod = 7;
int main(){
    int F1 = 1, F2 = 1, F3;
    int A, B, n;
    while(scanf("%d %d %d",&A,&B,&n)!=EOF&&(A&&B&&n)){
        for (int i = 3; i <= n;++i){
            F3 = (A * F1 + B * F2)%mod;
            F1 = F2;
            F2 = F3;
        }
        if(n==1)
            cout << F1 << endl;
        elseu
            cout << F2 << endl;
    }
    return 0;
}