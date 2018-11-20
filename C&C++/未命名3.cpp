#include <stdio.h>
int main(){
	int f0=0,f1=1;
	int n=20,i=2;
	printf("%d,",f0);
	while(i<n){
		f1=f0+f1;
		f0=f1-f0;
		printf("%d,",f0);
		i++;
	}
	return 0;
}
