/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
class Solution {
public:
    bool HasSubtree(TreeNode* pRoot1, TreeNode* pRoot2) {
        if (!pRoot1 || !pRoot2) return false;

        // 当前节点匹配 或 左子树匹配 或 右子树匹配
        return isSubtree(pRoot1, pRoot2) 
            || HasSubtree(pRoot1->left, pRoot2) 
            || HasSubtree(pRoot1->right, pRoot2);
    }

    bool isSubtree(TreeNode* r1, TreeNode* r2) {
        if (!r2) return true;   // pRoot2 遍历完，说明匹配成功
        if (!r1) return false;  // pRoot1 先遍历完，失败
        if (r1->val != r2->val) return false;

        // 继续比较左右子树
        return isSubtree(r1->left, r2->left) && isSubtree(r1->right, r2->right);
    }
};

