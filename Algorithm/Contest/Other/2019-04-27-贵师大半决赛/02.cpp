#include <iostream>
#include <vector>
#include <algorithm>
using namespace std;
typedef long long ll;

int main()
{
    int n;

    while (cin >> n && n && n < 100)
    {
        int C = 0;
        vector<int> A(n, 0);
        for (int i = 0; i < n; i++)
            cin >> A[i];
        sort(A.begin(), A.end());
        for (int i = A.size() - 1; i >= 0; --i)
        {
            C += A[i] / 100;
            A[i] %= 100;
            C += A[i] / 50;
            A[i] %= 50;
            C += A[i] / 10;
            A[i] %= 10;
            C += A[i] / 5;
            A[i] %= 5;
            C += A[i] / 2;
            A[i] %= 2;
            C += A[i] / 1;
            A[i] %= 1;
        }
        cout << C << endl;
    }
    return 0;
}