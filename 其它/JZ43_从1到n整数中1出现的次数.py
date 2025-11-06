# -*- coding:utf-8 -*-
class Solution:
    def NumberOf1Between1AndN_Solution(self, n):
        str_n = ''
        for i in range(1, n + 1):
            str_n += str(i)
        res = str_n.count('1')
        return res