#include <bits/stdc++.h>
using namespace::std;
int main(){
    int N, result, n;
    while(cin >> N && N){
        result = 0;
        for(int i=0;i<N;i++){
            cin >> n;
            result += n;
        }
        cout << result << endl;
    }
    return 0;
}