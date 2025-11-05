#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 
# @param numbers int整型一维数组 
# @return bool布尔型
#
class Solution:
    def IsContinuous(self , numbers: List[int]) -> bool:
        nOfZeros = numbers.count(0)
        numbers.sort()
        sumOfGap = 0
        for i in range(nOfZeros, len(numbers)-1):
            if(numbers[i]==numbers[i+1]):
                return False
            else:
                sumOfGap += (numbers[i+1]-numbers[i])-1
        if(sumOfGap > nOfZeros):
            return False
        return True