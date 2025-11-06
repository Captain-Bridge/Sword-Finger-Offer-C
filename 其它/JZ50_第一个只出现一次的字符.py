#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param str string字符串
# @return int整型
#
class Solution:
    def FirstNotRepeatingChar(self, s: str) -> int:
        # write code here
        if s==' ':
            return -1
        d=dict()
        #第一次遍历字符串，将每个字符的次数存入字典
        for i in s:    
            d[i]=d.get(i,0)+1
        #第二次遍历字符串，检查每个字符出现的次数
        for i in s:
            if d[i]==1:   #O(1)
                return s.index(i)
        return -1
