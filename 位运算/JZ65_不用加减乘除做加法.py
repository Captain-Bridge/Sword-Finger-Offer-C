#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 
# @param num1 int整型 
# @param num2 int整型 
# @return int整型
#
class Solution:
    def Add(self , num1: int, num2: int) -> int:
        # write code here
        add = num2
        sum = num1

        while add:
            temp = sum ^ add
            add = (sum & add) << 1
            sum = temp & 0xFFFFFFFF
        return sum if sum >> 31 == 0 else sum - 4294967296