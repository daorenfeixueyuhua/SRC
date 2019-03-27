#include <iostream>
#include <stdio.h>
#include <string>
#include <cmath>
using namespace::std;

const float mods = 1024.0;

int getBits(char s){
    switch(s){
        case 'i': return 4;
        case 'b': return 1;
        case 'l': return 8;
        case 'd': return 8;
        case 'c': return 1;
        case 'f': return 4;
    }
}

int main(){
    //测试getKey()
    int T;
    cin >> T;
    while(T--){
        int n;
        int bits=0;       //字节数
        cin >> n;
        char s[30];
        //getchar();
        while(n--){
            //gets(s);
            bits += getBits(s[0]);
        }
        bits=ceil(bits/mods);
        cout << bits << endl;
    }
    return 0;
}