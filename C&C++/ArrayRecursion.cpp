#include <iostream>
#include <algorithm>
using namespace::std;

int addRe(int A[],int n){//recursion add
    if(n==0)
        return A[n];
    else
        return A[n]+addRe(A,n-1);
}
double averageRe(int A[],int index,double size){//recursion average
    if(index==0)
        return A[index]/size;
    else
        return A[index]/size+averageRe(A,index-1,size);
}
int maxRe(int A[],int index){//recursion max
    if(index==0)
        return A[index];
    else
        return max(A[index],maxRe(A,index-1));
}
int main(){
    int A[10];
    for(int i=0;i<10;i++)
        A[i]=i;
    int addResult=addRe(A,9);
    cout << "recursion add is: " << addResult << endl;
    double averageresult=averageRe(A,9,10);
    cout << "recursion average is: " << averageresult << endl;
    int maxResult = maxRe(A,9);
    cout << "recursion max is: " << maxResult << endl;
    for(int i=0;i<10;i++)
        cout << A[i] << " ";
    cout << endl;
    return 0;
}