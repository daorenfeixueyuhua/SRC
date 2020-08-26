# https://ac.nowcoder.com/acm/contest/6218/B
#
# 返回最后要输出的答案
# @param n int整型 表示牛牛的数字
# @param m int整型 表示牛妹的数字
# @return int整型
#



# class Solution:
#     # 使用dfs
#     def solve(self, n, m):
#         # # 寻找距离m最近的完全平方数的方法来减小问题规模
#         # # 当 n > m: n -m
#         # # 当 n < m: min(m-n, m - k**2)(k = [n+1, sqrt(m)])
#         # if n > m:
#         #     return n - m
#         # k = 1
#         # while k**2 < m:
#         #     k += 1
#         # if k**2 - m > m - (k-1)**2:
#         #     k -= 1
#         # return min(m-n, self.solve(n, k) + 1 + abs(m-k**2))
#         # 使用bfs完成
#         if n > m:
#             return m-n
#         # 用于记录已经走过的节点
#         s = set()
#         s.add(n)
#         q = []
#         q.insert(0, n)
#         lv = 0
#         while q:
#             l = len(q)
#             for _ in range(l):
#                 num = q.pop()
#                 if num == m:
#                     return lv
#                 elif num + 1 <= 1000 and num + 1 not in s:
#                     s.add(num+1)
#                     q.insert(0, num + 1)
#                 elif num - 1 > 0 and num - 1 not in s:
#                     s.add(num-1)
#                     q.insert(0, num - 1)
#                 elif num ** 2 <= 2000 and num ** 2 not in s:
#                     s.add(num**2)
#                     q.insert(num**2)
#             lv += 1
#         pass

import collections
class Solution:
    def solve(self, n, m):
        # write code here
        if n > m:
            return n-m
        s = set()
        s.add(n)
        q = collections.deque([n])
        lv = 0
        while q:
            l = len(q)
            for _ in range(l):
                num = q.popleft()
                if num == m:
                    return lv
                else:
                    if num+1 <= 1000 and num+1 not in s:
                        s.add(num+1)
                        q.append(num+1)
                    if num-1 > 0 and num-1 not in s:
                        s.add(num-1)
                        q.append(num-1)
                    if num**2 <= 2000 and num**2 not in s:
                        s.add(num**2)
                        q.append(num**2)

            lv += 1
if __name__ == "__main__":
    sulo = Solution()
    print(sulo.solve(3, 7))
