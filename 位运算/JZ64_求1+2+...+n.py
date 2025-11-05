# -*- coding:utf-8 -*-
class Solution:
    def Sum_Solution(self, n):
        ans = n
        temp = ans and self.Sum_Solution(n-1)
        ans += temp
        return ans