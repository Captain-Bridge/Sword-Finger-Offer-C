#include <stack>
class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param pushV int整型vector
     * @param popV int整型vector
     * @return bool布尔型
     */
    bool IsPopOrder(vector<int>& pushV, vector<int>& popV) {
        int pushCount = 0;
        int popCount = 0;
        stack<int> st;
        while (pushCount < pushV.size()) {
            st.push(pushV[pushCount]);
            pushCount++;

            while (!st.empty() && popCount < popV.size() && st.top() == popV[popCount]) {
                st.pop();
                popCount++;
            }

        }

        if (popCount==popV.size()) return true;
        return false;
    }
};