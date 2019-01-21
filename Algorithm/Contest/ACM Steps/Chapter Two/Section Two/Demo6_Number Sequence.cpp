#include <iostream>
using namespace ::std;
const int mod = 7;
int main(){
    int A, B, n;
    while(cin>>A>>B>>n&&A&&B&&n){
        int f1 = 1, f2 = 1;
        int f3;
        for (int i = 3; i <= n;i++){
            f3 = (A % mod * f1 + B % mod * f2) % mod;
            f1 = f2;
            f2 = f3;
        }
    }
    return 0;
}