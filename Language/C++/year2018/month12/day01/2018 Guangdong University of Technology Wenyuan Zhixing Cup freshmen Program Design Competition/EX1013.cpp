#include <iostream>
using namespace::std;
int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        int r;
        cin >> n;
        while(n!=1){
            if(n%2){
                r=n*3+1;
                cout << n << "*3+1=" << r << endl; 
                n=r;
            }else{
                r=n/2;
                cout << n << "/2=" << r << endl;
                n=r;
            }
        }
        if(T!=0)
            cout << endl;
    } 
    return 0;
}