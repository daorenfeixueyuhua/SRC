#include <iostream>
#include <string>
#include <cctype>
#include <cstring>
using namespace::std;

bool equals(char c1,char c2){
    if(c1+1==c2-1&&(c1!='z'||c2!='a')){
        return true;
    }else
        return false;
}
bool islower(char c){
    if('a' <= c && c <= 'z')
        return true;
    else
        return false;
}

bool f(string s,int n){
    int i,j;
    for(i=0,j=n-1;i<=j;i++,j--){
        if(s[i]==s[j]){
        }else{
            if(islower(s[i])&&islower(s[j])){
                if(equals(s[i],s[j])||equals(s[j],s[i]))
                    ;
                else
                    return false;
            }else
                return false;
        }
    }
    return true;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        string s;
        int n;
        cin >> n >> s;
        if(n%2!=0){
            cout << 0 << endl;
            break;
        }
        if(f(s,n)){
            cout << 1 << endl;
        }
        else{
            cout << 0 << endl;
        }
    }

    return 0;
}