#include <iostream>
#include <vector>
#include <algorithm>

// #define mytest
// #ifdef mytest
// freopen("test.in", "r", stdin);
// freopen("test.out", "w", stdout);
// #endif

using namespace std;

/**
 * ACM题目分类：
 * 杂题
 * 穷举搜索（迭代/回溯）
 * 分治
 * 贪心
 * 动态规划
 * 图论
 * 数学
 * 字符串处理
 * 计算几何
 * 罕见题目
 * 
 * */
int main()
{
    int n;
    cin >> n;
    vector<int> N(n);
    for (int i = 0; i < n; i++)
    {
        cin >> N[i];
    }
    sort(N.begin(), N.end());
    for (int i = 0; i < n; i++)
    {
        cout << N[i] << " ";
    }
    return 0;
}