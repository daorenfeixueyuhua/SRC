#include <time.h>
#include <stdio.h>
int main()
{
    int start = clock();
    for (int i = 0; i < 100000; i++)
        ;
    printf("%.3lf\n", double(clock() - start) / CLOCKS_PER_SEC);
    return 0;
}