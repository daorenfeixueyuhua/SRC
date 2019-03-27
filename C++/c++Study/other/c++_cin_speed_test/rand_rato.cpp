#include <iostream>
#include <fstream>

using namespace std;
const int MAX = 1e5;

int N[MAX] = {0};
int main()
{
    int n;
    for (int i = 0; i < MAX; i++)
    {
        n = rand();
        N[n]++;
    }
    int cnt = 0;
    for (int i = 0; i < MAX; i++)
    {
        if (i % 1000 == 0 && i)
        {
            cout << i - 1000 << " ~ " << i << " : " << cnt << endl;
            cnt = 0;
        }
        cnt += N[i];
    }
    return 0;
}