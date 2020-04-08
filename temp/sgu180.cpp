#include <algorithm>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <iostream>
#include <iterator>
#include <map>
#include <queue>
#include <set>
#include <stack>
#include <vector>

#define L(x) (x << 1)
#define R(x) (x << 1 | 1)
#define MID(x, y) ((x + y) >> 1)

#define eps 1e-8
typedef __int64 ll;

#define fre(i, a, b) for (i = a; i < b; i++)
#define free(i, b, a) for (i = b; i >= a; i--)
#define mem(t, v) memset((t), v, sizeof(t))
#define ssf(n) scanf("%s", n)
#define sf(n) scanf("%d", &n)
#define sff(a, b) scanf("%d %d", &a, &b)
#define sfff(a, b, c) scanf("%d %d %d", &a, &b, &c)
#define pf printf
#define bug pf("Hi\n")

using namespace std;

const int INF = 0x3f3f3f3f;

int cmp(const int x, const int y) { return x < y; }

int merge_sort(vector<int> &A, int left, int right){
  
}

int main() {
    vector<int> array(10, 0);
    for (int i = 0; i < 10; ++i)
        array[i] = 10 - i;

    copy(array.begin(), array.end(), ostream_iterator<int>(cout, " "));
    cout << endl;
    return 0;
}