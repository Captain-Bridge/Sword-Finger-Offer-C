/**
 * struct TreeNode {
 *	int val;
 *	struct TreeNode *left;
 *	struct TreeNode *right;
 *	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
#include <stack>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pRoot TreeNode类 
     * @return TreeNode类
     */
    TreeNode* Mirror(TreeNode* pRoot) {
        if(!pRoot) return nullptr;

        stack<TreeNode*> st;
        st.push(pRoot);
        while (!st.empty()) {
            TreeNode* curr = st.top();
            st.pop();
            TreeNode* temp = curr->left;
            curr->left = curr->right;
            curr->right = temp;
            
            if(curr->left) st.push(curr->left);
            if(curr->right) st.push(curr->right);
        }

        return pRoot;
    }
};