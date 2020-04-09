#include <iostream>
#include <string.h>
using namespace::std;
const int length = 100000;
int main(){
    int T;
    int n, m, t, L, R;
    cin >> T;
    int A[length]={0};
    while(T--){
        cin >> n >> m;
        memset(A,0,n);
        for(int i=0;i<n;i++)
            cin >> A[i];
        while(m--){
            cin >> t >> L >> R;
            if(t==1){
                
            }else{

            }
        }
    }
    return 0;
}