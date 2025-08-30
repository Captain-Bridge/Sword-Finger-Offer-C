#include <algorithm>
#include <vector>
using namespace std;
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param array int整型vector 
     * @return int整型
     */
    int FindGreatestSumOfSubArray(vector<int>& array) {
        vector<int> dp;
        dp.push_back(array[0]);
        for(int i =1;i<array.size();i++){
            dp.push_back(max(array[i],dp[i-1]+array[i]));
        }
        return *max_element(dp.begin(), dp.end());
    }
};