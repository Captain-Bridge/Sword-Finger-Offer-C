#include <map>
#include <string>
#include <algorithm>
using namespace std;

class Solution {
public:
    int lengthOfLongestSubstring(string s) {
        map<char, int> lastIndex;  // 记录每个字符上一次出现的位置
        int ans = 0;
        int left = 0;               // 当前无重复子串的起点

        for(int i = 0; i < s.size(); i++) {
            if(lastIndex.find(s[i]) != lastIndex.end() && lastIndex[s[i]] >= left) {
                // 当前字符重复，并且上一次出现的位置在窗口内
                left = lastIndex[s[i]] + 1;  // 移动窗口左端
            }
            lastIndex[s[i]] = i;      // 更新字符位置
            ans = max(ans, i - left + 1);
        }
        return ans;
    }
};
