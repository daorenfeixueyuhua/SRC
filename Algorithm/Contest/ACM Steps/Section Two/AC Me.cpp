#include <bits/stdc++.h>
using namespace::std;
const int length = 1e5+1;
int main(){
    char s[length];
    int ans[127];
    while(gets(s)){
        memset(ans, 0, sizeof(ans));
        for(int i=0;i<strlen(s);++i){
            ans[s[i]]++;
        }
        for(int i='a';i<='z';++i){
            cout << (char)i << ":" << ans[i] << endl;
        }
        cout << endl;
    }
    return 0;
}