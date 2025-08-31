#include <string>
using namespace std;

class Solution {
public:
    int solve(string nums) {
        if(nums.empty()) return 1;          // 空串，解码方式为 1
        if(nums[0] == '0') return 0;        // 前导 0 不合法

        int res = solve(nums.substr(1));    // 第一位单独解码

        if(nums.length() >= 2) {
            int twoDigit = stoi(nums.substr(0,2));
            if(twoDigit >= 10 && twoDigit <= 26) {
                res += solve(nums.substr(2));  // 前两位组合解码
            }
        }
        return res;
    }
};
