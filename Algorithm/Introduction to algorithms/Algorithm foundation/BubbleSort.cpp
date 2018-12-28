// 冒泡算法
#include <bits/stdc++.h>
using namespace::std;
const int length = 20;
void swap(int &a, int &b){
    int tmp=a;
    a=b;b=tmp;
}

// 对区间 A[start, end) 进行冒泡排序
void bSort(int A[], int start, int end){
    for(int i=start;i<end-1;++i){
        for(int j=end-1;j>=i+1;--j){
            if(A[j]<A[j-1]){
                swap(A[j], A[j-1]);
            }
        }
    }
}
int main(){
    // test
    int A[length];
    for(int i=0;i<length;++i){
        A[i]=length-i-1;
    }    
    bSort(A, 1, 10);
    for(int i=0;i<length;++i){
        cout << A[i] << " ";
    }
    cout << endl;
    return 0;
}