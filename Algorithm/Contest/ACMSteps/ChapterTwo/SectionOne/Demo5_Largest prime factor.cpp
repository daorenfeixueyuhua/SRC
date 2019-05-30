#include <iostream>
#include <cstdio>
const int length = 1e6 + 2;
int table[length] = {0};
using namespace ::std;

/**
 * 唯一因子分解定理：
 *  a = p1&e1*...*pr^e2
 *  pi为素数，ei为正整数
 * */
void init()
{
    int position = 1;
    for (int i = 2; i < length; ++i)
    {
        if (table[i] == 0)
        {
            for (int j = 1; i * j < length; ++j)
            {
                table[i * j] = position;
            }
            position++;
        }
    }
}
int main()
{
    int n;
    init();
    while (scanf("%d", &n) != EOF)
    {
        cout << table[n] << endl;
    }
    return 0;
}