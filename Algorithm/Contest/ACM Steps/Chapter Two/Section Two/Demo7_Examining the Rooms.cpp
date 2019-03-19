# include <iostream>
using namespace std;

int factorial(int n){
    if(n == 0)
        return 1;
    else return factorial(n-1);
}

int main(){
    int n;
    int* N = new int[n];
    cin >> n;

    N[1] = (n-1) * (n-2) * factorial(n-2);
    for(int i=2;i<n;++i)
        N[i] = (n-1)*N[n-2];
    for(int i=1;i<n;++i)
        cout << N[i] << " ";
    cout << endl;

    
    return 0;
}