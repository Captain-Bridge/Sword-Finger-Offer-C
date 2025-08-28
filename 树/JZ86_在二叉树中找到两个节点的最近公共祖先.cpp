/**
 * struct TreeNode {
 *     int val;
 *     struct TreeNode *left;
 *     struct TreeNode *right;
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
#include <vector>
using namespace std;

class Solution {
public:
    int lowestCommonAncestor(TreeNode* root, int o1, int o2) {
        vector<int> path1, path2;
        findPath(root, o1, path1);
        findPath(root, o2, path2);

        int i = 0;
        while (i < path1.size() && i < path2.size() && path1[i] == path2[i]) {
            i++;
        }
        return path1[i - 1]; // 最近公共祖先
    }

private:
    bool findPath(TreeNode* root, int target, vector<int>& path) {
        if (!root) return false;
        path.push_back(root->val);

        if (root->val == target) return true;
        if (findPath(root->left, target, path) || findPath(root->right, target, path)) {
            return true;
        }

        path.pop_back(); // 回溯
        return false;
    }
};
