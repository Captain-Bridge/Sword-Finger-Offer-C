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
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pRoot TreeNode类 
     * @return int整型vector<vector<>>
     */
    vector<vector<int>> Print(TreeNode* pRoot) {
        vector<vector<int>> res;
        if (!pRoot) return res;

        queue<TreeNode*> q;
        q.push(pRoot);
        bool leftToRight = true;  // 标记打印方向

        while (!q.empty()) {
            int size = q.size();
            vector<int> level(size);
            for (int i = 0; i < size; i++) {
                TreeNode* node = q.front();
                q.pop();

                // 根据方向决定存放位置
                int index = leftToRight ? i : size - 1 - i;
                level[index] = node->val;

                if (node->left) q.push(node->left);
                if (node->right) q.push(node->right);
            }
            res.push_back(level);
            leftToRight = !leftToRight; // 交替方向
        }

        return res;
    }
};