#include <iostream>

using namespace std;
int main()
{
    long long t, n, k, m;
    char s[101];
    // scanf("%d", &t);
    cin >> t;
    while (t--)
    {
        cin >> n >> k >> m;
        cin >> s;
        // scanf("%d %d %d", &n, &k, &m);
        // scanf("%s", s);
        long long w = 0, f = 0, F = 0, r = 0L;
        for (int i = 0; i < n; i++)
            if (s[i] == '1')
                w++;
        f = n - w;
        F = (f - k) < 0 ? 0 : (f - k);
        r = m * (w - F);
        r = r < 0 ? 0 : r;
        cout << "data: " << w << " " << f << " " << F << " " << r << endl;
        // printf("%s %d %d %d\n", s, w, f, F);
        cout << r << endl;
        // printf("%I64d\n", r);
    }
    return 0;
}