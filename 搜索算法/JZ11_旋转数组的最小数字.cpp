class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param nums int整型vector 
     * @return int整型
     */
    int minNumberInRotateArray(vector<int>& nums) {
        int prev = -1;
        for(int i : nums){
            if (prev>i) {
                return i;
            }
            prev = i;
        }
        return nums[0];
    }
};