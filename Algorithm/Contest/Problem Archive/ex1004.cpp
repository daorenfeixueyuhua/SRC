#include <iostream>
#include <string>
#include <vector>
using namespace ::std;
int main(){
    int N;
    while(scanf("%d",&N)!=EOF&&N){
        vector<string> A(N, "0");
        for (int i = 0; i < N;++i)
            cin >> A[i];
        
    }
    return 0;
}