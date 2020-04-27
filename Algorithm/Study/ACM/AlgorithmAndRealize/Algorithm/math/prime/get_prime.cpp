#include <algorithm>
#include <bitset>
#include <iostream>
#include <map>
#include <math.h>
#include <queue>
#include <set>
#include <stack>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <vector>
#include <iterator>
#define MAXN 1010100
#define LL long long
#define fi first
#define se second
#define mp make_pair
#define pb push_back
#define ll __int64
#define INF 0x7fffffff
#define cs(s) freopen(s, "r", stdin)
#define mem(x) memset(x, 0, sizeof(x))
#define PI acos(-1)
#define eps 1e-10
using namespace std;
int gcd(int a, int b) { return b ? gcd(b, a % b) : a; }
int lcm(int a, int b) { return a / gcd(a, b) * b; }
const LL mod = 1e9 + 7;

const int maxn = 1000000;

bool valid[maxn] = {0};

/**
 * n 所需素数范围
 * tot 素数个数
 * ans 素数表
 * */
void getPrime(int n, int &tot, int ans[maxn]) {
    tot = 0;
    int i, j;
    for (i = 2; i <= n; ++i)
        valid[1] = true;
    for (i = 2; i <= n; ++i) {
        if (valid[i]) {
            if (n / i < i)
                break;
            // 将所有能将i整除的数全部排除
            for (j = i * i; j <= n; j += i)
                valid[j] = false;
        }
    }

    // 记录素数表
    for (i = 2; i <= n; ++i)
        if (valid[i])
            ans[++tot] = i;
}

int main() {
    int ans[maxn] = {0};
    int n = 100;
    int tot = 0;
    cout << "I am you dady" << endl;
    getPrime(n, tot, ans);
    copy(ans, ans + tot, ostream_iterator<int>(cout, " "));
    cout << endl;


    return 0;
}