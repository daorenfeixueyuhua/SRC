// Max Sum
#include <bits/stdc++.h>
using namespace::std;
const int INF=1e5+1;
// 超 时 O(n^2)
void fun(int A[], int n, int &start, int &end, int &max){
    max=A[0];
    int curSum=0;
    for(int i=0;i<n;i++){
        curSum=0;
        for(int j=i;j<n;++j){
            curSum+=A[j];
            if(max<curSum){
                max=curSum;
                start=i;
                end=j;
            }
        }
    }
}

void findMaxCorssingSubArray(int A[], int low, int mid, int high, int &start, int &end, int &max){
    int leftMax=-INF, rightMax=-INF, sum=0, maxLeft=-1, maxRight=-1;
    for(int i=mid;i>=low;--i){
        sum+=A[i];
        if(sum>leftMax){
            leftMax=sum;
            maxLeft=i;
        }
    }    
    sum=0;
    for(int i=mid+1;i<=high;++i){
        sum+=A[i];
        if(sum>rightMax){
            rightMax=sum;
            maxRight=i;
        }
    }
    start=maxLeft;
    end=maxRight;
    max=leftMax+rightMax;
}

void findMaxSumSubArray(int A[], int low, int high, int &start, int &end, int &max){
    if(low==high){
        start=low;end=high;max=A[low];
    }else{
        int mid=(low+high)/2;
        int lStart, lEnd, lMax;
        int mStart, mEnd, mMax;
        int rStart, rEnd, rMax;
        findMaxSumSubArray(A, low, mid, lStart, lEnd, lMax);
        findMaxCorssingSubArray(A, low, mid, high, mStart, mEnd, mMax);
        findMaxSumSubArray(A, mid+1, high, rStart, rEnd, rMax);
        if(lMax>=rMax&&lMax>=mMax){
            start=lStart;
            end=lEnd;
            max=lMax;
        }
        else if(rMax>=lMax&&rMax>=mMax){
            start=rStart;
            end=rEnd;
            max=rMax;
        }
        else{
            start=mStart;
            end=mEnd;
            max=mMax;
        }
    }
}

int main(){
    int T;
    int cnt=0;
    cin >> T;
    while(T--){
        ++cnt;
        int n;
        int start, end, max;
        cin >> n;
        int A[n];
        for(int i=0;i<n;++i)
            cin >> A[i];
        findMaxSumSubArray(A, 0, n-1, start, end, max);
        cout << "Case " << cnt << ":" << endl;
        cout << max << " " << start+1 << " " << end+1 << endl;
        if(T){
            cout << endl;
        }
    }
    return 0;
}