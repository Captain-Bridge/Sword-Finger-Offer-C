#include <algorithm>
#include <vector>
class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param array int整型vector
     * @return int整型vector
     */
    vector<int> FindGreatestSumOfSubArray(vector<int>& array) {
        vector<int> dp;
        vector<int> indexDp;
        dp.push_back(array[0]);
        indexDp.push_back(0);
        for (int i = 1; i < array.size(); i++) {
            if (array[i] > dp[i - 1] + array[i]) {
                dp.push_back(array[i]);
                indexDp.push_back(i);
            } else {
                dp.push_back(dp[i - 1] + array[i]);
                indexDp.push_back(indexDp[i - 1]);
            }
        }
        int maxSum = -101;
        int maxLength = -1;
        int start = 0;
        int end = 0;
        for (int i = 0; i < dp.size(); i++) {
            cout << dp[i] << " " << maxSum << " " << indexDp[i] << " " << maxLength << endl;
            if (dp[i] > maxSum || (dp[i] == maxSum && (i - indexDp[i] + 1) > maxLength)) {
                maxSum = dp[i];
                maxLength = i - indexDp[i] + 1;
                start = indexDp[i];
                end = i;
            }
        }
        vector<int> ans;
        for (int i = start; i <= end; i++)
            ans.push_back(array[i]);


        return  ans;
    }
};