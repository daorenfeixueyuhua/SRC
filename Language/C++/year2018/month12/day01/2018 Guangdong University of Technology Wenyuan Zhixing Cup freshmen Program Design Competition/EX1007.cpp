#include <iostream>
#include <stdio.h>
#include <cmath>
#include <string>
using namespace::std;

const string failed="Impossble";
// 3.1415926535897931
const double pi=acos(-1);

int main(){
    int T;
    int N;
    double r;
    cin >> T;
    while(T--){
        cin >> N;
        if(N<=0){
            cout << failed << endl;
            continue;
        }
        r=N*N/(2*pi);
        //cout << r << endl;
    }
    return 0;
}