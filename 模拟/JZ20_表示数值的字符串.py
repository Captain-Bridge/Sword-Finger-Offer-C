class Solution:
    def isNumeric(self, str):
        # 定义状态转移表
        states = [
            {" ": 0, "s": 1, "d": 2, ".": 4},  # 0. 起始状态，处理前导空格
            {"d": 2, ".": 4},  # 1. 符号之后
            {"d": 2, ".": 3, "e": 5, " ": 8},  # 2. 小数点前的数字
            {"d": 3, "e": 5, " ": 8},  # 3. 小数点后的数字
            {"d": 3},  # 4. 只有小数点（前面没有数字）
            {"s": 6, "d": 7},  # 5. 指数e之后
            {"d": 7},  # 6. 指数符号之后
            {"d": 7, " ": 8},  # 7. 指数数字
            {" ": 8},  # 8. 后导空格
        ]

        p = 0  # 初始状态
        for c in str:
            if "0" <= c <= "9":
                t = "d"  # digit
            elif c in "+-":
                t = "s"  # sign
            elif c in "eE":
                t = "e"  # exponent
            elif c in ". ":
                t = c  # dot or space
            else:
                t = "?"  # unknown

            if t not in states[p]:
                return False
            p = states[p][t]

        # 可接受的结束状态：2(数字), 3(小数), 7(指数数字), 8(后导空格)
        return p in (2, 3, 7, 8)
