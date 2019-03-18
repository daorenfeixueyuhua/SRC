#include <iostream>
#include <queue>
#include <algorithm>

using namespace std;

const int MAX = 50;

// 失败


// 求a与b的最大公约数
int gcd(int a, int b)
{
    if (b == 0)
    {
        return a;
    }
    return gcd(b, a % b);
}

// 求a1, a1, ..., an的最小公倍数
int lcm(vector<int> A)
{
    int x = A[0], g = A[0];
    for(int i = 0; i < A.size(); ++i)
    {
        x = x * A[i];
        g = gcd(g, A[i]);
    }
    return x / g;
}

int main()
{

    // cout << "hello" << endl;
    int n, A[MAX], x;
    int flag = 0;
    cin >> n;
    for (int i = 0; i < n; ++i)
        cin >> A[i];
    cin >> x;
    sort(A, A + n);
    int lcmVar = 1;
    for (int i = 0; i < n; i++)
    {
        int tmp = (lcmVar * A[i]) / gcd(lcmVar, A[i]);
        if (tmp < x)
        {
            lcmVar = tmp;
            cout << lcmVar << endl;
            continue;
        }
        else if (lcmVar == x)
        {
            flag = 1;
            break;
        }
        else
        {
            continue;
        }
    }

    if (flag == 1)
    {
        cout << "Possible" << endl;
    }
    else
    {
        cout << "Impossible" << endl;
    }
    cin.get();
    cin.get();
    return 0;
}