#include <bits/stdc++.h>
long long N[51]={0};
int init(){
	N[1]=0;N[2]=1;N[3]=1;
	for(int i=4;i<=50;i++){
		N[i]=N[i-1]+N[i-2]+N[i-3];
	}
//	for(int i=1;i<=50;i++){
//		printf("%I64d ",N[i]);
//	}
}
int main(){
	int n;
	init();
	while(scanf("%d",&n)!=EOF){
		printf("%I64d\n",N[n]);
	}
	return 0;
}
