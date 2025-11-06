#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 
# @param numbers int整型一维数组 
# @return int整型
#
class Solution:
    def MoreThanHalfNum_Solution(self , numbers: List[int]) -> int:
        times = {}
        for num in numbers:
            if num not in times:
                times[num] = 1
            else:
                times[num] += 1
            if times[num]>len(numbers)/2:
                return num