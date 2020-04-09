#include <bits/stdc++.h>
const int mod = 1e9+7;
using namespace::std;
int main(){
	int T;
	cin >> T;
	while(T--){
		int n;
		cin >> n;
		long long ans = 1;
		for(int i=n;i>0;i--){
			ans = (ans*i) % mod;
		}
		cout << ans << endl;
	}
}
// 100000000 ��ʱ 
