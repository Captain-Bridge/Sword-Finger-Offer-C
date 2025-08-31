class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param prices int整型vector 
     * @return int整型
     */
    int maxProfit(vector<int>& prices) {
        if(prices.size()<=1) return 0;
        int preMin = prices[0];
        int dp = 0;
        for(int i = 1; i<prices.size();i++){
            dp = max(dp,prices[i]-preMin);
            preMin = min(preMin,prices[i]);
        }
        return dp;
    }
};