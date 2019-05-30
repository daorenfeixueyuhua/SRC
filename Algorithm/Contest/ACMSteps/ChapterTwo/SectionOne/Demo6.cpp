// 七夕节

#include <iostream>
using namespace ::std;
const int length = 5e5 + 1;
int A[length] = {0};
void init()
{

    for (int i = 1; i < length; ++i)
    {
        for (int j = 2; i * j < length; ++j)
        {
            A[i * j] += i;
        }
    }
}
int main()
{
    init();
    int T;
    cin >> T;
    while (T--)
    {
        int n;
        cin>> n;
        cout << A[n] << endl;
    }
    return 0;
}