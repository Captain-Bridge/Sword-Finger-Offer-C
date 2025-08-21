/**
 * struct TreeNode {
 *  int val;
 *  struct TreeNode *left;
 *  struct TreeNode *right;
 *  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param pRoot TreeNode类
     * @return bool布尔型
     */
    bool IsBalanced_Solution(TreeNode* pRoot) {
        return checkBalance(pRoot)!=-1;
    }

  private:
    // 计算树的高度并检查平衡性
    int checkBalance(TreeNode* root) {
        if (root == nullptr) return 0;  // 空树的高度是0

        // 递归计算左右子树的高度
        int leftHeight = checkBalance(root->left);
        int rightHeight = checkBalance(root->right);

        // 如果左子树或右子树不平衡，或者高度差超过1，返回-1
        if (leftHeight == -1 || rightHeight == -1 || abs(leftHeight - rightHeight) > 1)
            return -1;

        // 返回当前树的高度
        return std::max(leftHeight, rightHeight) + 1;
    }
};