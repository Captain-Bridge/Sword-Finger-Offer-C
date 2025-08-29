#include <string>
#include <vector>
class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param str string字符串
     * @return string字符串vector
     */
    vector<string> Permutation(string str) {
        if (str == "") return {""};
        if (str.length() == 1) return vector<string> {str};
        vector<string> ans;
        char lastChar = str.back();
        str.pop_back();
        for (string back_str : Permutation(str)) {
            for (int i = 0; i <= str.length(); i++) {
                string curr = back_str;
                curr.insert(i, 1, lastChar);
                ans.push_back(curr);
            }
        }

        vector<string> res;
        unordered_set<string> seen;

        for (const auto& s : ans) {
            if (seen.count(s) == 0) {
                res.push_back(s);
                seen.insert(s);
            }
        }
        return res;
    }
};