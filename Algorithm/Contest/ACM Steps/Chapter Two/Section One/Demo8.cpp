// Leftmost Digit
#include <iostream>
#include <cmath>
using namespace ::std;
/**
 * 求N^N的第一位
 * k = 10^(N lg N - (int)N lg N)
 * */
int main()
{
    int T;
    double N, k, M;
    cin >> T;
    while(T--){
        cin >> N;
        M = N * log10(N);
        k = (long long)pow(10, M - (long long)M);
        cout << (int)k << endl;
    }
    return 0;
}