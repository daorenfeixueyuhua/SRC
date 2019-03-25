#include <stdio.h>
#include <time.h>

const int MAX = 1e6;
int N[MAX];
int main()
{
    int start = clock();
    for (int i = 0; i < MAX; i++)
    {
        scanf("%d", &N[i]);
    }
    printf("%.3lf\n", double(clock() - start) / CLOCKS_PER_SEC);
    return 0;
}