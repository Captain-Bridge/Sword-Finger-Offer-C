#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param base double浮点型
# @param exponent int整型
# @return double浮点型
#


class Solution:
    # 快速幂
    def Pow(self, x: float, y: int) -> float:
        res = 1
        while y:
            # 判断是不是奇数，可以再往上乘一个
            if y & 1:  # y的最后1位是0，结果就是false，最后一位是1，结果为true
                res *= x
            # x叠加
            x *= x
            # 减少乘次数，如果是奇数右移，会在除2的基础上减一，偶数就是直接除2
            y = y >> 1
        return res

    def Power(self, base: float, exponent: int) -> float:
        # 处理负数次方
        a = 7  # 1111,右移两位，为11
        print(a >> 1)
        if exponent < 0:
            base = 1 / base
            exponent = -exponent
        res = 1.0
        return self.Pow(base, exponent)
