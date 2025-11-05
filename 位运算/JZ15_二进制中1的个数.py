#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 
# @param n int整型 
# @return int整型
#
class Solution:
    def NumberOf1(self , n: int) -> int:
        n_unsigned = n & 0xFFFFFFFF
        count = 0
        for i in range(32):
            if n_unsigned & (1 << i):
                count += 1
        return count