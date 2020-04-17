#include <bits/stdc++.h>
using namespace std;
int find(vector<int> &A, int max, int v) {
    for (int i = 1; i <= max; ++i) {
        if (A[i] == v)
            return i;
    }
    return -1;
}
int main() {
    int n;
    cin >> n;
    vector<int> src = {0, 1};
    for (int i = 2; i <= n; ++i) {
        int op = -1;
        int ans = 0;
        int falg = 1;
        // 使用入栈的方式进行插入
        // 特殊点，src 中存在值 src[j]*2 - i，说明需要在j点之前插入
        for (int j = 1; j <= i - 1; ++j) {
          
            op = find(src, j, src[j] * 2 - i);
            ans = j;
            if (op != -1) {
                src.insert(src.begin() + ans, i);
                falg = 0;
                break;
            }
        }
        if (falg) {
            src.push_back(i);
        }
    }
    copy(src.begin() + 1, src.end(), ostream_iterator<int>(cout, " "));
    return 0;
}