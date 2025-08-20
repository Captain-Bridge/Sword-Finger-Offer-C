/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
public:
    bool hasPathSum(TreeNode* root, int sum) {
        if (!root) return false;  // 如果当前节点为空，返回 false

        // 检查是否到达叶子节点并且路径和是否等于 sum
        if (!root->left && !root->right) {
            return root->val == sum;  // 只有在叶子节点才与 sum 比较
        }

        // 递归到左右子树，减去当前节点的值
        int newSum = sum - root->val;
        return hasPathSum(root->left, newSum) || hasPathSum(root->right, newSum);
    }
};
