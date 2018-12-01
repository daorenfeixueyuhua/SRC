#include <iostream>
using namespace::std;

const int modVal=1000000007;
const int length=100000;

int main(){
    int a[length+1],b[length+1];
    int n;
    cin >> n;
    int P=1;
    for(int i=1;i<=n;i++){
        cin >> a[i] >> b[i];
        a[i]=b[i]-a[i];
        a[i]*=a[i-1];
        b[i]*=b[i-1];
    }
    P=(a[n]/b[n])*modVal;
    return 0;
}