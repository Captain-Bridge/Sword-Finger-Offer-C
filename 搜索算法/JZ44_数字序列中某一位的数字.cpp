#include <string>
class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param n int整型
     * @return int整型
     */
    int findNthDigit(int n) {
        long long digitLen = 1;
        long long count = 9;
        long long start = 1;

        // 找到 n 所在的数字长度
        while (n > digitLen * count) {
            n -= digitLen * count;
            digitLen++;
            count *= 10;
            start *= 10;
        }

        // 找到具体的数字
        long long num = start + (n - 1) / digitLen;
        string s = to_string(num);

        return s[(n - 1) % digitLen] - '0';
    }

};