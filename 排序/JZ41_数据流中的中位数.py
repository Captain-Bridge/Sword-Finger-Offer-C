# -*- coding:utf-8 -*-
class Solution:
    def __init__(self):
        self.val = []
    def Insert(self, num):
        # write code here
        if len(self.val) == 0:
            self.val.append(num)
        else:
            i = 0
            while(i<len(self.val)):
                if num <= self.val[i]:
                    break
                i = i+1
            self.val.insert(i,num)
    def GetMedian(self):
        # write code here
        n = len(self.val)
        if n % 2 == 1:
            return self.val[n//2]
        else:
            return (self.val[n//2]+self.val[n//2-1])/2.0
