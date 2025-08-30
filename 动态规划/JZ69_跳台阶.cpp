class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param number int整型
     * @return int整型
     */
    int jumpFloor(int number) {
        if (number == 1) return 1;
        if (number == 2) return 2;
        return jumpFloor(number - 2) + jumpFloor(number - 1);
    }
};