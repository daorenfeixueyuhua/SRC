#include <iostream>

using namespace::std;
// positive sequence sort
void insert_sort_positive(int A[], int n){
    for(int j=2; j<n; j++){
        int key = A[j];
        int i=j-1;
        while(i>0&&key<A[i]){
            A[i+1]=A[i];
            i--;
        }
        A[i+1]=key;
    }
}
// inverted sequence sort
void insert_sort_inverted(int A[], int n){
    for(int j=2;j<n;j++){
        int key=A[j];
        int i=j-1;
        while(i>0&&A[i]<key){
            A[i+1]=A[i];
            i--;
        }
        A[i+1]=key;
    }
}
int main(){
    const int n = 21;
    int A[n] = {0};
    for(int i = n-1; i>0; i--)
        A[i] = i;
    insert_sort_positive(A, n);
    for(int i=1;i<n;i++)
        cout << A[i] << " ";
    cout << endl;
    return 0;    
}