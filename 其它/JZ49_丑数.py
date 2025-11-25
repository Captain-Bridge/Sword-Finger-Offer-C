#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 
# @param index int整型 
# @return int整型
#
class Solution:
    def GetUglyNumber_Solution(self , index: int) -> int:
        if (index <= 6):
            return index
        res = []
        res.append(1)
        i2 = 0
        i3 = 0
        i5 = 0
        for i in range(index):
            res.append(min(res[i2]*2,min(res[i3]*3,res[i5]*5)))
            if(res[-1]==res[i2]*2):
                i2 += 1
            if(res[-1]==res[i3]*3):
                i3 += 1
            if(res[-1]==res[i5]*5):
                i5 += 1
        return res[index-1]
