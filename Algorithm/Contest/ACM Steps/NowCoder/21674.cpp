#include <iostream>

using namespace std;

const int MAX = 50;

// 求a与b的最大公约数
int gcd(int a, int b){
    if (b==0) {
        return a;
    }
    return gcd(b, a % b);
}

// 求a1, a1, ..., an的最小公倍数
int lcm(int A[], int n){
    int x = A[0], g = A[0];
    for (int i = 1; i < n;++i){
        x = x * A[i];
        g = gcd(g, A[i]);
    }
    return x / g;
}

int main(){
    // cout << "hello" << endl;
    int n, A[MAX], x;
    cin >> n;
    for (int i = 0; i < n;++i)
        cin >> A[i];
    cin >> x;
    int lcmVar = lcm(A, n);
    cout << lcmVar << endl;
    cin.get();
    cin.get();
    return 0;
}