#include <iostream>
#include <string>
using namespace::std;

const int length=100;
const string success="WeRide.ai";
const string failed="Transform Mobility With Autonomous Driving";

// 判断是否连续大于0
bool fly(int A[], int n){
    for(int i=1;i<=n;i++)
        if(A[i]<=0)
            return false;
    return true;
}

int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        int S[length+1];
        cin >> n;
        for(int i=1;i<=n;i++)
            cin >> S[i];
        if(fly(S,n))
            cout << success << endl;
        else 
            cout << failed << endl;

    }
    return 0;
}