#include <ctime>
#include <iostream>

using namespace std;

const int MAX = 1e6;
int N[MAX];
int main()
{
    // 取消cin于stdin同步
    ios::sync_with_stdio(false);
    int start = clock();
    for (int i = 0; i < MAX; i++)
    {
        cin >> N[i];
    }
    printf("%.3lf\n", double(clock() - start) / CLOCKS_PER_SEC);
}