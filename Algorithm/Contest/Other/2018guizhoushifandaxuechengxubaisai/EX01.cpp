#include <bits/stdc++.h>
int main(){
	char s[100] = "��ӭ�μӹ���ʦ����ѧ�ڶ��������ƾ���";
	int times;
	while(scanf("%d",&times)!=EOF&&(times>=1&&times<=10)){
		for(int i=0;i<times;i++){
			printf("%s\n",s);
		}
		printf("\n");
	}
	return 0;
}
