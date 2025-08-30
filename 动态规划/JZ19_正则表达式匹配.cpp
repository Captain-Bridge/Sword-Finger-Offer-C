class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param str string字符串
     * @param pattern string字符串
     * @return bool布尔型
     */
    bool match(string str, string pattern) {
        return isMatch(str, pattern, 0, 0);
    }
  private:
    bool isMatch(const string& s, const string& p, int si, int pi) {
        // 如果模式已经遍历完，并且字符串也遍历完，则匹配成功
        if (si == s.length() && pi == p.length()) return true;

        // 如果模式遍历完，字符串没有遍历完，匹配失败
        if (pi == p.length()) return false;

        // 如果当前字符是'.'，或者字符相同，则可以继续匹配
        bool match = (si < s.length()) && (p[pi] == s[si] || p[pi] == '.');

        // 处理 '*'，有两种情况：
        if (pi + 1 < p.length() && p[pi + 1] == '*') {
            // 1. * 前面的字符匹配0次：跳过当前字符和 '*'，直接继续匹配
            if (isMatch(s, p, si, pi + 2)) return true;
            // 2. * 前面的字符匹配1次或多次：如果当前字符匹配，则继续匹配字符串
            if (match && isMatch(s, p, si + 1, pi)) return true;
        } else {
            // 如果没有 '*'，则普通字符匹配
            if (match && isMatch(s, p, si + 1, pi + 1)) return true;
        }

        return false;
    }

};