#include <bits/stdc++.h>
int main(){
	char s[100] = "欢迎参加贵州师范大学第二届程序设计竞赛";
	int times;
	while(scanf("%d",&times)!=EOF&&(times>=1&&times<=10)){
		for(int i=0;i<times;i++){
			printf("%s\n",s);
		}
		printf("\n");
	}
	return 0;
}
