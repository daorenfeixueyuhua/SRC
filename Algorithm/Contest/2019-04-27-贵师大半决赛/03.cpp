#include <iostream>
#include <algorithm>
#include <vector>
using namespace std;
typedef long long ll;
const int maxn = 100000;

bool valid[maxn];

void getPrime(int n, int &tot, int ans[maxn])
{
    tot = 0;
    int i, j;
    for (i = 2; i <= n; i++)
        valid[i] = true;
    for (i = 2; i <= n; ++i)
        if (valid[i])
        {
            if (n / i < i)
                break;
            for (j = i * i; j <= n; j += i)
                valid[j] = false;
        }
    for (i = 2; i <= n; ++i)
        if (valid[i])
            ans[++tot] = i;
}

int pow1(int a, int b)
{
    int n = 1;
    for (int i = 1; i <= b; i++)
        n *= a;
    return n;
}

// 107 -> 701
int getInteger(int n)
{
    vector<int> V;
    while (n)
    {
        V.push_back(n % 10);
        n /= 10;
    }
    int N = 0;
    reverse(V.begin(), V.end());
    for (int i = 0; i < V.size(); i++)
    {
        N += V[i] * pow1(10, i);
    }

    return N;
}

int main()
{

    int m, n;
    cin >> m >> n;
    int ans[maxn];
    // int n = 1000;
    int tot;
    getPrime(maxn, tot, ans);
    // cout << "sum: " << tot << endl;
    // copy(ans, ans + n, ostream_iterator<int>(cout, " "));
    for (int i = m; i <= n; i++)
    {
        if (valid[i] && valid[getInteger(i)])
        {
            cout << i << endl;
        }
    }
    return 0;
}