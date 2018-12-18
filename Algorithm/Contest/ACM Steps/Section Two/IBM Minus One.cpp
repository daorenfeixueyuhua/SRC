#include <bits/stdc++.h>
using namespace::std;
int A[128]; // alphabet
void init(){
    for(int i=0;i<128;i++){
        if(i=='a'||i=='A'){
            A[i]=i-32;
        }else{
            A[i]=i+1;
        }
    }
}
int main(){
    int T;
    int t=1;
    cin >> T;
    string s;
    while(T--){
        cin >> s;
        for(int i=0;i<s.length();i++){
            if(s[i]=='Z'){
                s[i]='A';
            }else{
                s[i]=s[i]+1;
            }
        }
        cout << "String #" << t++ << endl << s << endl;
        cout << endl;
    }
    return 0;
}