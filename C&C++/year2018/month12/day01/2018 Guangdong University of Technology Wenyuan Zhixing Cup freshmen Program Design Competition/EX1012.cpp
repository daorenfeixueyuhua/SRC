#include <iostream>
#include <cstring>
using namespace::std;
const int length=100000;

int gcd(int a, int b){
    return b==0?a:gcd(b, a%b);
}
// 最小公倍数=两整数乘积+最大公约数

int A[length+1]={0};

int main(){
    //int k = gcd(9,12345);
    int T;
    int b;
    cin >> T;
    while(T--){
        int cnt=0;
        memset(A, 0, sizeof(A));        
        cin >> b;
        for(int i=1;i<=1000;i++){
            int k=(i*b)/gcd(b,i);
            //cout << i << " " << k << " " << k/i << endl;
            A[k/i]++;
        }
        for(int i=0;i<=length;i++)
            if(A[i])
                cnt++;
        cout << cnt << endl;
    }

    return 0;
}