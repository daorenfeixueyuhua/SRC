# include <iostream>

using namespace std;

template<class T>
int f(T A[], int n){
    for(int i=0;i<n-1;i++){
        for(int j=0;j<n-1;j++){
            if(A[j]<A]j+1){
                // exchange
                T t = A[j];
                A[j]=A[j+1];
                A[j+1]=t;
            }
        }
    }
}

int main(){
    //....
    return 0;
}