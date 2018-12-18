#include <bits/stdc++.h>
const int length = 1000;
int N[length+1];
int dp[length+1];
using namespace::std;
int main(){
	int maxLength;
	int a;
	int b;
	cin >> a; 
	while(a--){
		maxLength = -1;
		memset(N,0,sizeof(N));
		memset(dp,0,sizeof(dp));
		scanf("%d",&b);
		for(int i=1;i<=b;i++){
			cin >> N[i];
			dp[i]=N[i]==6?1:0;
			if(N[i]==6&&N[i-1]==6)
				dp[i]+=dp[i-1];
		}
		for(int i=1;i<=b;i++){
			if(dp[i]>maxLength)
				maxLength = dp[i];
			//cout << dp[i] << " ";
		}
		//cout << endl;
		cout << maxLength << endl;
	}
	return 0;
}
