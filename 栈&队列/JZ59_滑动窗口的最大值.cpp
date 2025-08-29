#include <queue>
#include <vector>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param num int整型vector 
     * @param size int整型 
     * @return int整型vector
     */
    vector<int> maxInWindows(vector<int>& num, int size) {
        if(num.size()<size) return {};
        vector<int> ans;
        for(int & i : num){
            q.push(i);
            if(q.size()==size){
                ans.push_back(findMaxValInQueue(q));
                q.pop();
            }
        }

        return ans;
    }
private:
    queue<int> q;
    int findMaxValInQueue(queue<int> q){
        int maxVal = q.front();
        while (!q.empty()) {
            if(q.front()>maxVal) maxVal = q.front();
            q.pop();
        }
        return maxVal;
    }
};