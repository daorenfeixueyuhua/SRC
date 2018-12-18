#include <bits/stdc++.h>
using namespace::std;
const int mods=1000000007;
int main(){
	int T;
	cin >> T;
	int n,i,result;
	while(T--){
		i=1;result=1;
		cin >> n;
		while(i<=n){
			result = (result%mods)*i;
			result %= mods;
			if(result%mods==0){
				break;
			}
			i++;
		}
		cout << result << endl;
	}
	return 0;
}
