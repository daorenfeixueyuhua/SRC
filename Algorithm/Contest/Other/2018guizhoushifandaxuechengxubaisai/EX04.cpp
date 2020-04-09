#include <bits/stdc++.h>
int main(){
	long long begin, end ,time;
	long long h, m, s;
	while(scanf("%I64d %I64d", &begin, &end)!=EOF){
		time = end - begin;
		h = 0; m = 0; s = 0;
		h = time/3600;
		time %= 3600;
		m = time/60;
		s = time %= 60;
		printf("%02I64d:%02I64d:%02I64d\n",h,m,s);
	}
	return 0;
}
