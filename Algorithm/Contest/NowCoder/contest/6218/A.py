# https://ac.nowcoder.com/acm/contest/6218/A
#
#
# @param s string字符串
# @return string字符串
#


class Solution:
    def change(self, s):
        cnt = 0
        res = ''
        for c in s:
            if c is not 'a':
                res += c
            else:
                cnt += 1
        for _ in [0]*cnt:
            res += 'a'
        return res
        # write code here

if __name__ == "__main__":
    solu = Solution()
    print(solu.change('abcavv'))