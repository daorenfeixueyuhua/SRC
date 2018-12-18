#include <bits/stdc++.h>
const int length = 100000;
using namespace::std;
int main(){
	int T;
	int dp[27];
	string s;
	cin >> T;
	int result = 0;
	while(T--){
		result = 0;
		memset(dp,0,sizeof(dp));
		cin >> s;
		for(int i=0;i<s.length();i++){
			dp[s[i]-'A'+1]++;
		}
		for(int i=1;i<=26;i++){
			result += dp[i]*i;
		}
		cout << result << endl;
	}
	return 0;
}
