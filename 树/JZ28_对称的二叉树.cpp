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
    bool isSymmetrical(TreeNode* pRoot) {
        if (!pRoot) return true;

        return isMirror(pRoot->left, pRoot->right);

    }
  private:

    bool isMirror(TreeNode* leftRoot, TreeNode* rightRoot) {
        if (!leftRoot && !rightRoot) return true;

        if (!leftRoot || !rightRoot) return false;

        return (leftRoot->val == rightRoot->val) &&
               isMirror(leftRoot->left, rightRoot->right) &&
               isMirror(leftRoot->right, rightRoot->left);
    }
};