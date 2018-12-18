#include <bits/stdc++.h>
using namespace::std;

/**
 * return aa..a(n个a
 * */
int getA(int n, int a){
    if(n==1)
        return a;
    else return a*pow(10, n)+getA(n-1, a);
}

int add(int n, int a){
    if(n==1)
        return getA(n, a);
    else getA(n, a)+add(n-1, a);
}
int main(){
    int n, a;
    while(cin >> n >> a && n){
        cout << add(n, a) << endl;
    }
    return 0;
}