// 最大子数组问题
#include <bits/stdc++.h>
const int INF = 65535;
using namespace::std;
typedef struct Tuple{
    int low, high, sum;
}Tuple;
// 返回下标元组划定跨越中点的最大子数组边界，并返回最大子数组中值的和
Tuple findMaxCorssingSubArray(int A[], int low, int mid, int high){
    int leftSum=-INF, rightSum=-INF, sum=0, maxLeft=-1, maxRight=-1;
    for(int i=mid;i>=low;--i){
        sum=sum+A[i];
        if(sum>leftSum){
            leftSum=sum;
            maxLeft=i;
        }
    }
    sum=0;
    for(int i=mid+1;i<=high;++i){
        sum=sum+A[i];
        if(sum>rightSum){
            rightSum=sum;
            maxRight=i;
        }
    }
    Tuple tuple;
    tuple.low=maxLeft;tuple.high=maxRight;tuple.sum=leftSum+rightSum;
    return tuple;
}

Tuple findMaxSumSubArray(int A[], int low, int high){
    if(low==high){
        Tuple tuple;
        tuple.low=low;tuple.high=high;tuple.sum=A[low];
        return tuple;
    }else{
        int mid=(low+high)/2;
        Tuple leftTuple, midTuple, rightTuple;
        leftTuple=findMaxSumSubArray(A, low, mid);
        midTuple=findMaxCorssingSubArray(A, low, mid, high);
        rightTuple=findMaxSumSubArray(A, mid+1, high);
        if(leftTuple.sum>=rightTuple.sum&&leftTuple.sum>=midTuple.sum)
            return leftTuple;
        else if(rightTuple.sum>=leftTuple.sum&&rightTuple.sum>=midTuple.sum)
            return rightTuple;
        else 
            return midTuple;
    }

}

int bf(int A[], int n){
    int left=1, right=1, max=A[1], curSum=0;
    for(int i=1;i<=n;++i){
        curSum=0;
        for(int j=i;j<=n;++j){
            curSum=curSum+A[j];
            if(curSum>max){
                max=curSum;
                left=i;
                right=j;
            }
        }
    }
    return max;
}

int main(){
    int A[17]={0, 13, -3, -25, -20, -3, -16, -23, 18, 20, -7, -12, -5, -22, 15, -4, -7};
    Tuple tuple = findMaxSumSubArray(A, 1, 16);
    int result=bf(A, 16);
    return 0;
}