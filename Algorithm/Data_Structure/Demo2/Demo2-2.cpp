#include <iostream>
using namespace::std;

/**
 * 将数组A向左移动n位
 * */
void move(int A[], int length, int n){
    for(int i=0;i<n%length;i++){
        for(int i=1;i<=length;++i){
            A[i-1]=A[i];
        }
        A[length]=A[0];
    }
}
/**
 * 遍历A[start, end)
 * */
void show(int A[], int start, int end){
    for(int i=start;i<end;++i){
        cout << A[i] << " ";
    }
    cout << endl;
}
int main(){
    int A[8+1]={-1, 1, 2, 3, 4, 5, 6, 7, 8};
    move(A, 8, 8);
    show(A, 1, 9);
    return 0;
}