#include <stdio.h>

int main(){
	int d;//distance
	float money;
	scanf("%d",&d);
	if(d>3){
		money=8+(d-3)*1.6;
	}else{
		money=8;
	}
	printf("money: %.2f\n",money);
	return 0;
}
