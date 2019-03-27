#include <iostream>
#include <string>
#include <vector>
#include <ctype.h>
using namespace::std;

bool isalnum(char c){
    if(('0'<=c&&c<='9')||('A'<=c&&c<='Z')||('a'<=c&&c<='z')){
        return true;
    }else{
        return false;
    }
}

int main(){
    string s;
    vector<int> n(200,0);
    getline(cin, s);
    for(int i=0;i<s.length();i++){
        if(isalnum(s[i])){
            n[s[i]]++;
            for(int j=0;j<200;j++){
                if(n[j]==3){
                    cout << (char)j << endl;
                    return 0;
                }
            }
        }
    }
    return 0;
}