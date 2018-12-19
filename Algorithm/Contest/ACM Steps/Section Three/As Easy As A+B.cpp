#include <bits/stdc++.h>
using namespace::std;
const int length=1000;
int main(){
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        int A[n];
        for(int i=0;i<n;++i)
            cin >> A[i];

        sort(A, A+n);
        for(int i=0;i<n;i++){
            if(i==n-1)
                cout << A[i];
            else
                cout << A[i] << " ";
        }
        cout << endl;
    }
    return 0;
}