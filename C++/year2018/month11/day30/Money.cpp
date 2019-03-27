#include<iostream>
#include <algorithm>
#include <math.h>
using namespace::std;
#define MAX 20
//返回区间A[p,r]内最大值的坐标
int MaxIndex(int A[], int p, int r){
    int maxVal=-1;
    int maxIndex=-1;
    while(p<=r){
        if(maxVal<A[p]){
            maxVal=A[p];
            maxIndex=p;
        }
        p++;
    }
    return maxIndex;
}
//返回区间A[p,r]内最小值的坐标
int MinIndex(int A[], int p, int r){
    int minVal=2147483647;
    int minIndex=-1;
    while(p<=r){
        if(minVal>A[p]){
            minVal=A[p];
            minIndex=p;
        }
        p++;
    }
    return minIndex;
}
int main(){
    //测试MaxIndex和MinIndex
    //int A[10]={1,2,3,4,5,6,7,8,9,0};
    //int n1=MaxIndex(A,0,9);
    //int n2=MinIndex(A,0,9);
    int T;
    cin >> T;
    while(T--){
        int n;
        cin >> n;
        int p[MAX+1]={0};
        int f[MAX+1]={0};       //标识数组
        int x[MAX+1]={0};       //stores的选择状态
        int P=0;                //手中的钱
        int S=0;                //交易次数
        for(int i=1;i<=n;i++)
            cin >> p[i];
        for(int i=1;i<=n;i++){
            int maxIndex,minIndex;
            maxIndex=MaxIndex(p,i,n);//找到p[i,n]的u最大值
            minIndex=MinIndex(p,i,maxIndex);//找到p[i,maxIndex]内的最小值
            cout << maxIndex << " " << minIndex << endl;
            if(f[i]){               //卖出
                x[i]=1;
                continue;
            }
            if(i<maxIndex<=n&&minIndex==i){      //买入
                x[i]=-1;
                f[maxIndex]=1;
                continue;
            }
 //           if(minIndex!=i){        //不买
 //               x[i]=0;
 //               f[maxIndex]=0;
 //               continue;
 //           }
        }
        for(int i=1;i<=n;i++){
            P+=p[i]*x[i];
            S+=abs(x[i]);
        }
        cout << P << " " << S << endl;
    }
    return 0;
}