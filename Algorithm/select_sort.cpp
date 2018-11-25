#include <iostream>
#include <algorithm>
using namespace::std;

// select sorted
void select_sort(int A[], int n){
    for(int i=0;i<n-1;i++){
        int min=A[i];
        int minIndex=i;
        for(int j=i+1;j<n;j++){
            if(A[j]<min){
                min=A[j];
                minIndex=j;
            }
            swap(A[i],A[minIndex]);
        }
    }
}

int main(){
    const int max=10;
    int A[max]={0};
    for(int i=0;i<max;i++)
        A[i]=max-i;
    select_sort(A, max);
    for(int i=0;i<max;i++)
        cout << A[i] << " ";
    cout << endl;
    return 0;
}