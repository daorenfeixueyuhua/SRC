#include <bits/stdc++.h>
using namespace::std;
const int mod = 1000000007;
const int bits = 62;
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
int getDecimal(string s, int radix){
    int ans = 0;
    for(int i=s.length()-1;i>=0;i--){
        ans += (s[i] - '0')*power1(radix, i, mod);
    }
    return ans;
}

string to_string(long long n){
    string s;
    while(n){
        s.push_back(n%10+'0');
        n /= 10;
    }
    return s;
}
int main(){
    int T;
    while(cin >> T && T){
        int ans = 0;
        int x, y;
        while(T--){
            scanf("%d(%d)", &x, &y);
            string s = to_string(x);
            int tmp = getDecimal(s, y);
            cout << tmp << " ";
            ans += tmp;
        }
        cout << ans << endl;
    }
    return 0;
}
/**
 * 
 * */