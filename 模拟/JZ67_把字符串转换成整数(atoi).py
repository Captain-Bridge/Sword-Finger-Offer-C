#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
#
# @param s string字符串
# @return int整型
#
class Solution:
    def StrToInt(self, s: str) -> int:
        res = 0
        index = 0
        # 去掉前导空格
        s = s.strip()
        # 去掉空格就什么都没有了
        n = len(s)
        if s == "":
            return 0
        sign = 1
        # 处理第一个符号是正负号的情况
        if s[index] == "+":
            index += 1
        elif s[index] == "-":
            index += 1
            sign = -1
        # 去掉符号就什么都没有了
        if index == n:
            return 0
        while index < n:
            c = s[index]
            # 后续非法字符，截断
            if c < "0" or c > "9":
                break
            # 转数字
            res = res * 10 + sign * ((int)(c) - (int)("0"))
            index += 1
        # 输出处理越界
        return min(max(res, -(2 ** 31)), 2 ** 31 - 1)
