class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param target int整型 
     * @param array int整型vector<vector<>> 
     * @return bool布尔型
     */
    bool Find(int target, vector<vector<int>>& array) {
        if(array.empty() || array[0].empty()) return false;

        int row = 0, col = array[0].size() - 1;
        while(row < array.size() && col >= 0) {
            if(array[row][col] == target) return true;
            else if(array[row][col] > target) col--;
            else row++;
        }
        return false;
    }
};