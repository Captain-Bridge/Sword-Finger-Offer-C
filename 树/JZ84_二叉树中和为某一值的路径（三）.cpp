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
     * @param root TreeNode类 
     * @param sum int整型 
     * @return int整型
     */
    int FindPath(TreeNode* root, int sum) {
        int ans = 0;

        if(!root) return ans;

        stack<TreeNode*> nodeSt;
        stack<vector<int>> sumSt;
        
        nodeSt.push(root);
        sumSt.push({sum});
        while (!nodeSt.empty()) {
            TreeNode* curr = nodeSt.top();
            nodeSt.pop();

            vector<int> sums = sumSt.top();
            sumSt.pop();
            for(int& i : sums){
                if(i-curr->val==0) ans++;
                i = i - curr->val;
            }

            sums.push_back(sum);

            if(curr->left) {nodeSt.push(curr->left);sumSt.push(sums);}
            if(curr->right) {nodeSt.push(curr->right);sumSt.push(sums);}
        }
        return ans;
    }
};