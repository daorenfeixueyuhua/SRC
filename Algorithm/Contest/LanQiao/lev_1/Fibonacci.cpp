#include <iostream>

const int mod = 10007;
const int MAX = 1000000;
using namespace std;

int main()
{
    int A[MAX];
    A[0] = 1;
    A[1] = 1;
    int n;
    cin >> n;
    for (int i = 1; i < n; ++i)
    {
        A[i] = (A[i - 1] + A[i - 2]) % mod;
    }
    cout << A[n - 1] << endl;
    return 0;
}