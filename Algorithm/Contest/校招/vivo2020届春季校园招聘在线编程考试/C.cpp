#include <bits/stdc++.h>
using namespace std;

class Solution {
  public:
    /**
     *
     * @param n int整型 第n天
     * @return int整型
     */
    int solution(int n) {
        // write code here
        int f0 = 0, f1 = 1;
        // Sn = na1 + n(n+1)/2
        // Sn = a1*(1-q^n)/(1-q)
        
    }
};
// 1 2 2 3 3 3 4 4 4 4 5 5 5 5 5 6 6 6 6 6 6

int main() {
    Solution s = Solution();
    int n;
    cin >> n;
    cout << s.solution(n) << endl;
    return 0;
}