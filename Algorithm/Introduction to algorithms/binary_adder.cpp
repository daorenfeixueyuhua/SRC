#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
using namespace::std;
const int BIT=32;
const char initchar='0';
string add(string & s1, string & s2){
    string res(BIT,initchar);
    int carray=0;

    for(int i=BIT-1;i>0;i--){
        res[i]=(char)((s1[i]-'0')+(s2[i]-'0')%2+carray);
        carray=((s1[i]-'0')+(s2[i]-'0'))/2;    
    }
    return res;
}

int main(){
    string s1(BIT,initchar),s2(BIT,initchar),s3(BIT,initchar);
    cin >> s1 >> s2;
    s3=add(s1,s2);    
    
    return 0;
}