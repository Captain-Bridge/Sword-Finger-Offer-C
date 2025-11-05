#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param nums int整型一维数组
# @return int整型一维数组
#
class Solution:
    def FindNumsAppearOnce(self, nums: List[int]) -> List[int]:
        xor_result = 0
        for num in nums:
            xor_result = xor_result ^ num
        diff_bit = xor_result & -xor_result
        a, b = 0, 0
        for num in nums:
            if num & diff_bit:
                a ^= num  # 该位为1的数字
            else:
                b ^= num  # 该位为0的数字
        return [a,b] if a < b else [b,a]