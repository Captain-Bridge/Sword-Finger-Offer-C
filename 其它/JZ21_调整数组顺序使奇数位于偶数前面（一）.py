#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 
# @param array int整型一维数组 
# @return int整型一维数组
#
class Solution:
    def reOrderArray(self , array: List[int]) -> List[int]:
        odd = []
        even = []
        for num in array:
            if num % 2 == 0:
                even.append(num)
            else:
                odd.append(num)
        ans = odd
        for num in even:
            ans.append(num)
        return ans