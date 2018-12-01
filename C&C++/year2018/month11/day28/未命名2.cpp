#include <stdio.h>
int main(){
	char ch='a';
	while(ch<='z'){
		printf("%c%c",ch-32,ch);
		ch++;
	}
	return 0;
}
