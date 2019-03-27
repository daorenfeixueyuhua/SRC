#include <iostream>
#include <cstdio>
using namespace std;
int main()
{
    // 枚举法
    int N;
    scanf("%d", &N);
    for (int a = 2; a <= N; ++a)
        for (int b = 2; b < a; ++b)
            for (int c = 2; c < b; ++c)
                for (int d = c; d < a; ++d)
                    if (a * a * a == b * a * a + c * c * c + d * d * d)
                        printf("Cube = %d, Tripe = (%d, %d, %d)\n", a, b, c, d);
    cin.get();
    cin.get();
    return 0;
}