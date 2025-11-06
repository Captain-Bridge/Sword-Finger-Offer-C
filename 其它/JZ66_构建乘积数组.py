#
# @param A int整型一维数组
# @return int整型一维数组
#
class Solution:
    def multiply(self, A: List[int]) -> List[int]:
        # 初始化数组B
        B = [1 for i in range(len(A))]
        # 先乘左边，从左到右
        for i in range(1, len(A)):
            # 每多一位由数组B左边的元素多乘一个前面A的元素
            B[i] = B[i - 1] * A[i - 1]
        temp = 1
        # 再乘右边，从右到左
        for i in reversed(range(len(A))):
            # temp为右边的累乘
            B[i] *= temp
            temp *= A[i]
        return B
