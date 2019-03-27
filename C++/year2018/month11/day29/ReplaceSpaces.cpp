#include <iostream>
#include <malloc.h>

using namespace::std;
class Solution {
public:
    //再p的位置插入字符串"%20"
    int change(char *str,int p,int length){
        //扩容
        str=realloc(str,sizeof(char)*(length+3));
        for(int i=length-1;i>p;i--)
            str[i+3]=str[i];
        str[p+0]='%';str[p+1]='2';str[p+2]='0';
        length+=3;
        return length;
    }
	void replaceSpace(char *str,int length) {
        for(int i=0;i<length;i++){
            if(str[i]==' '){
                length=change(str,i,length);
            }
        }
	}
};

int main(){
    
    return 0;
}