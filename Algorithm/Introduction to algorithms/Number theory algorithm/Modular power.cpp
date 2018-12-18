// 模取幂算法
#include <bits/stdc++.h>
using namespace::std;
const int mod = 1000000007;
const int bits = 62;
long long MODULAR_EXPONENTIATION(long long a, long long b, long long n){
    long long c = 0;
    long long d = 1;
    int k = bits -1;
    bitset<bits> B(b);
    while(!B[k])k--;
    for(int i=k;i>=0;i--){
        c *= 2;
        d *= d;
        d %= n;
        if(B[i]){
            c++;
            d *= a;
            d %= n;
        }
    }
    return d;
} // fialed
int fun(int a, int b, int n){
    int d=1,t=a;
    while(b>0){
        if(b%2==1){
            d=(d*t)%n;
        }
        b/=2;
        t=(t*t)%n;
    }
    return d;
} //successful
/**
 * left to right
 * */
long long power1(long long a, long long b, long long n){
    long long ans = 1;
    bitset<bits> B(b);
    for(int i=bits-1;i>=0;i--){
        ans = (ans*ans)%n;
        if(B[i]){
            ans *= a;
            ans %= mod;
        }
    }
    return ans;
} //successful
/**
 * rigth to left
 * */
long long power2(long long a, long long b, long long n){
    long long ans = 1, p = a;
    bitset<bits> B(b);
    for(int i=0;i<bits;i++){
        if(B[i]){
            ans *= p;
            ans %= mod;
        }
        p *= p;
        p %= mod;
    }
    return ans;
} //successful
int main(){
    long long a, b;
    while(cin>>a>>b&&(a||b)){
        cout << MODULAR_EXPONENTIATION(a, b, mod) << endl;
    }
    return 0;
}