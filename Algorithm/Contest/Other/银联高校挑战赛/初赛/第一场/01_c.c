#include <stdio.h>
int main()
{
    int t;
    scanf("%d", &t);
    while (t--)
    {
        int n, k;
        long long m = 0L;
        scanf("%d %d %I64d", &n, &k, &m);
        // printf("%d %d %I64d\n", n, k, m);
        char s[102];
        scanf("%s", s);
        // printf("%s\n", s);
        int w = 0, f, F;
        long long r = 0L;
        for (int i = 0; i < n; i++)
            if (s[i] == '1')
                w++;
        f = (n - w) - k;
        if (f < 0)
            f = 0;
        r = m * (w - f);
        if (r < 0)
            r = 0;
        // printf("%d %d\n", w, f);
        printf("%I64d\n", r);
    }
    return 0;
}