#include <bits/stdc++.h>
using namespace::std;
const int mods = 1000000007;
long long MODULAR_EXPONENTIATION(long long a, long long b, int n){
    long long c = 0;
    long long d = 1;
    bitset<32> B(b);
    for(int i=31;i>=0;i--){
        c = 2*c;
        d = (d*d)%n;
        if(B[i]==1){
            c = c+1;
            d = (d*a)%n;
        }
    }
    return d;
}
int main(){
	long long n;
	long long result = 0;
	while(scanf("%I64d",&n)!=EOF){
		result = 0;
		n %= mods;
		result = n%mods*(n+1)%mods*(2*n+1)%mods*MODULAR_EXPONENTIATION(6,mods-2,mods)%mods;
		printf("%I64d\n",result);
	}
	return 0;
}
