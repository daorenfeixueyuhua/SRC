/**
 * vovel letters : A a E e I i O o U u
 * 
 * */
#include <bits/stdc++.h>
using namespace::std;
int A[128]; // ASCII
/**
 * 对ASCII表进行初始化
 * */
void init(){
    memset(A, 0, sizeof(A));
    // 元音为1，辅音为0
    A['A'] = A['a'] = 1;
    A['E'] = A['e'] = 1;
    A['I'] = A['i'] = 1;
    A['O'] = A['o'] = 1;
    A['U'] = A['u'] = 1;
}
int main(){
    init();
    int T;
    string buf;
    cin >> T;
    while(T--){
        cin >> buf;
        for(int i=0;i<buf.length();i++){
            if(A[buf[i]]){ // is vovewl
                buf[i] = toupper(buf[i]);
            }else{
                buf[i] = tolower(buf[i]);
            }
        }
        cout << buf << endl;
    }
    return 0;
}