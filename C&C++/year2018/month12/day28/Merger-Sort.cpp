//归并排序
#include <iostream>
#define INF 1000000
#define MAX 100

using namespace::std;

void Merger(int A[], int p, int q, int r){
    int n1=q-p+1;
    int n2=r-q;
    int L[MAX]={0},R[MAX]={0};
    int i,j,k=1;
    for(i=1;i<=n1;i++)
        L[i]=A[p+i-1];
    for(j=1;j<=n2;j++)
        R[j]=A[q+i];
    L[n1+1]=INF;R[n2+1]=INF;//哨兵
    for(i=1, j=1, k=1;k<=r;k++){
        if(L[i]<=R[j]){
            A[k]=L[i++];
        }else if(R[j]<L[i]){
            A[k]=R[j++];
        }
    }
}

void Merger_Sort(int A[], int p, int r){
    if(p<r){
        int q=(p+r)/2;
        Merger_Sort(A, p, q);
        Merger_Sort(A, q+1,r);
        Merger(A, p, q, r);
    }
}

int main(){
    int const maxN=3;
    int A[maxN+1]={0};
    A[0]=INF;
    for(int i=1;i<=maxN;i++){
        A[i]=maxN-i+1;
    }
    Merger_Sort(A,1,maxN);
    return 0;
}