#include <deque>
#include <vector>
using namespace std;

class Solution {
public:
    vector<int> maxInWindows(vector<int>& num, int size) {
        vector<int> ans;
        if (num.empty() || size <= 0 || size > num.size()) return ans;

        deque<int> dq; // 存下标，保证单调递减

        for (int i = 0; i < num.size(); i++) {
            // 移除比当前元素小的
            while (!dq.empty() && num[dq.back()] <= num[i]) {
                dq.pop_back();
            }
            dq.push_back(i);

            // 移除滑出窗口的元素
            if (dq.front() <= i - size) {
                dq.pop_front();
            }

            // 窗口形成后加入答案
            if (i >= size - 1) {
                ans.push_back(num[dq.front()]);
            }
        }
        return ans;
    }
};
