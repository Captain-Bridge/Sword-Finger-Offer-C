#include <vector>
class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param matrix char字符型vector<vector<>>
     * @param word string字符串
     * @return bool布尔型
     */
    bool hasPath(vector<vector<char> >& matrix, string word) {
        if (matrix[0].empty()) return false;


        //确定起点
        for (int i = 0; i < matrix.size(); i++) {
            for (int j = 0; j < matrix[0].size(); j++) {
                if (word[0] == matrix[i][j]) {
                    if (findPath(matrix, i, j, word, 0)) return true;
                }
            }
        }
        return false;
    }

  private:
    bool findPath(vector<vector<char>>& matrix, int start_i, int start_j,
                  string word, int index) {
        if (matrix[start_i][start_j] != word[index]) return false; // 核心检查
        if (index == word.length() - 1) return true;

        char temp = matrix[start_i][start_j];
        matrix[start_i][start_j] = '#'; // 标记已访问

        bool found = false;
        if (start_i > 0) found = found ||
                                     findPath(matrix, start_i - 1, start_j, word, index + 1);
        if (start_i < matrix.size() - 1) found = found ||
                    findPath(matrix, start_i + 1, start_j, word, index + 1);
        if (start_j > 0) found = found ||
                                     findPath(matrix, start_i, start_j - 1, word, index + 1);
        if (start_j < matrix[0].size() - 1) found = found ||
                    findPath(matrix, start_i, start_j + 1, word, index + 1);

        matrix[start_i][start_j] = temp; // 回溯

        return found;
    }

};