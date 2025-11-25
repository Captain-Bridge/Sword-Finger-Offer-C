#
# 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
#
# 
# @param numbers int整型一维数组 
# @return string字符串
#
class Solution:
    def sortRule(self,number1:int,number2:int) -> bool:
        str1 = str(number1)
        str2 = str(number2)
        if(''.join([str1,str2]) > ''.join([str2,str1])):
            return True
        else:
            return False
    def PrintMinNumber(self , numbers: List[int]) -> str:
        for i in range(len(numbers)):
            for j in range(i,len(numbers)):
                if(self.sortRule(numbers[i],numbers[j])):
                    temp = numbers[i]
                    numbers[i] = numbers[j]
                    numbers[j] = temp
        result = ''.join(str(num) for num in numbers)
        return result

        