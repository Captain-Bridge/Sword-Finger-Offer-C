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
     * @param proot TreeNode类 
     * @param k int整型 
     * @return int整型
     */
    int KthNode(TreeNode* proot, int k) {
        stack<TreeNode*> st;
        TreeNode* curr = proot;
        while (curr||!st.empty()) {
            while (curr) {
                st.push(curr);
                curr = curr->left;
            }
            curr = st.top(); 
            st.pop();
            k--;
            if(k==0)
            return curr->val;
            curr = curr->right;        // 转向右子树
        }
        return -1;
    }
};