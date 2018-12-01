#include <iostream>
#include <cstring>
#include <algorithm>
using namespace::std;
const int length=10000;
const int INF = 10009;
int main(){
    int T;
    cin >> T;
    int A[length+1]={0};
    int dp[length+1]={0};
    while(T--){
        int n;
        cin >> n;
        for(int i=0;i<=length;i++){
            A[i]=INF;
            dp[i]=1;
        }
        //memset(A, INF, sizeof(A));
        //memset(dp, 1, sizeof(dp));
        for(int i=1;i<=n;i++)
            cin >> A[i];
        for(int i=1;i<=n;i++){
           if(A[i]-1==A[i-1]){
               dp[i]=dp[i-1]+1;
            }
           //
        }
        for(int i=1;i<=n;i++)
            dp[i]=max(dp[i],dp[i-1]);
        cout << dp[n] << endl;
    }
    return 0;
}