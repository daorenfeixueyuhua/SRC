#include <bits/stdc++.h>
using namespace::std;
const int MAX = 1001;
const int INF = 1e9+7;
void show(int A[], int p, int r){
    while(p<=r){
        cout << A[p++] << " ";
    }
    cout << endl;
}
void merger(int A[], int p, int q, int r){ // 合并
    int n1 = p-q+1;
    int n2 = r-q;
    int i, j, k;
    int L[n1], R[n2];
    for(i=0;i<n1;i++)
        L[i]=A[p+i];
    for(i=0;i<n2;i++)
        R[i]=A[q+i+1];
    i=0;j=0;k=p;
    while(i<n1&&j<n2){
        if(L[i]<=R[j]){
            A[k++]=L[i++];
        }else{
            A[k++]=R[j++];
        }
    }
    while(i<n1){
        A[k++]=L[i++];
    }
    while(j<n2){
        A[k++]=R[j++];
    }
    return ;
}
void merger_sort(int A[], int p, int r){
    if(p<r){
        int q = (p+r)/2;
        merger_sort(A, p, q);
        merger_sort(A, q+1, r);
        merger(A, p, q, r); // 合并
    }
    show(A,p,r);
}
int main(){
    int K[10]={9,8,7,6,5,4,3,2,1,0};
    merger_sort(K,0,9);

    int T;
    cin >> T;
    int A[MAX];
    while(T--){
        int N;
        memset(A, 0, sizeof(A));
        cin >> N;

    }
    return 0;
}