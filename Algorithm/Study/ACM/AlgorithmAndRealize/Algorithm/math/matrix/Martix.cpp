#include <bits/stdc++.h>

using namespace std;
const int MAXN = 1010;
const int MAXM = 1010;
struct Matrix
{
    int n, m;
    int a[MAXN][MAXM];
    void clear()
    {
        n = m = 0;
        memset(a, 0, sizeof(a));
    }
    Matrix operator+(const Matrix &b) const
    {
        Matrix temp;
        temp.n = n;
        temp.m = m;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                temp.a[i][j] = a[i][j] + b.a[i][j];
        return temp;
    }
    Matrix operator-(const Matrix &b) const
    {
        Matrix temp;
        temp.n = n;
        temp.m = m;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                temp.a[i][j] = a[i][j] - b.a[i][j];
        return temp;
    }
    Matrix operator*(const Matrix &b) const
    {
        Matrix temp;
        temp.n = n;
        temp.m = m;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                temp.a[i][j] = a[i][j] - b.a[i][j];
        return temp;
    }
};

int main()
{
    return 0;
}