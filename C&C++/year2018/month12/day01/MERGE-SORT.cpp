#include <iostream>
using namespace::std;
const int INF = 65335;
const int length = 10;

/*
 说明：合并A[p, q], A[q+1, r]
 复杂度：O(n)
 参数：A[] 待合并区间，p 左端点，q 中心，r 右端点
 返回值：无
*/
void MERGE(int A[], int p, int q, int r){
    int n1 = q-p+1;
    int n2 = r-q;
    int R[length+1],L[length+1];
    //initial R and L
    for(int i=1;i<=length;i++){
        L[i]=0;
        R[i]=0;
    }
    int i, j, k;
    for(i=1;i<=n1;i++)
        L[i]=A[p+i-1];
    for(j=1;j<=n2;j++)
        R[j]=A[q+j];
    L[n1+1]=INF;R[n2+1]=INF;
    i=1;j=1;
    for(k=1;k<=r;k++){
        if(L[i]<=R[j])
            A[k]=L[i++];
        else
            A[k]=R[j++];
    }
}
/*
 说明：归并排序数组A[p, r]，递归基为 p = r，此时A[p, r]是绝对以排序
 复杂度：T(n)=O(1) if n<=c; aT(n/b)+D(n)+C(n) other;
 参数：
 返回值：
*/
void MERGE_SORT(int A[], int p, int r){
    if(p<r){
        int q = (p+r)/2;                //将A[p, r]分为左区间A[p, q], 右区间A[q+1, r]
        MERGE_SORT(A, p, q);
        MERGE_SORT(A, q+1, r);
        MERGE(A, p, q, r);
    }
}


int main(){
    /*
    测试Merg
    int T[length+1]={INF,1,3,5,7,9,2,4,6,8,10};
    MERGE(T,1,5,10);
    */
    int A[length+1]={0};
    for(int i=1;i<=length;i++)
        A[i]=length-i+1;
    MERGE_SORT(A, 1, 10);
    for(int i=1;i<=length;i++)
        cout << A[i] << " ";
    cout << endl;

    return 0;
}
/*
 测试失败，存在bug
*/