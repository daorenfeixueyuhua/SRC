class Solution {
  public:
    const int inf = 0xfffffff;
    int getV(int n) {
        int ans = 1;
        while (n) {
            ans *= n % 10;
            n /= 10;
        }
        return ans;
    }
    int P[10] = {0, 1, 1, 1, 0, 1, 0, 1, 0, 0};
    int isP(int n) {
        if (n < 10 and P[n]) // 10以内的素数不算
            return 0;
        for (int i = 2; i < sqrt(n); i++) {
            if (!(n % i))
                return 0;
        }
        return 1;
    }
    /**
     * 输入一个整形数值，返回一个整形值
     * @param n int整型 n>9
     * @return int整型
     */
    int solution(int n) {
        // write code here
        int ans = -1;
        // 素数问题
        for (int i = 10; i < inf; ++i) {
            if (isP(n)) {
                break;
            }
            if (getV(i) == n) {
                ans = i;
                break;
            }
        }
        return ans;
    }
};