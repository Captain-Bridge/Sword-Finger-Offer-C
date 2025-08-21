/**
 * struct TreeNode {
 *  int val;
 *  struct TreeNode *left;
 *  struct TreeNode *right;
 *  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
#include <stack>
#include <vector>
class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param root TreeNode类
     * @param target int整型
     * @return int整型vector<vector<>>
     */
    vector<vector<int> > FindPath(TreeNode* root, int target) {
        vector<vector<int>> ans;
        if (!root) return ans;

        stack<TreeNode*> nodeSt;
        stack<vector<int>> pathSt;
        stack<int> targetSt;

        nodeSt.push(root);
        pathSt.push({root->val});
        targetSt.push(target);

        while (!nodeSt.empty()) {
            TreeNode* curr = nodeSt.top();
            nodeSt.pop();
            vector<int> currPath = pathSt.top();
            pathSt.pop();
            int currTarget = targetSt.top();
            targetSt.pop();

            if (!curr->left && !curr->right && (currTarget - curr->val) == 0) {
                ans.push_back(currPath);
            }

            if (curr->left) {
                nodeSt.push(curr->left);
                vector<int> leftPath = currPath;
                leftPath.push_back(curr->left->val);
                pathSt.push(leftPath);
                targetSt.push(currTarget - curr->val);
            }

            if (curr->right) {
                nodeSt.push(curr->right);
                vector<int> rightPath = currPath;
                rightPath.push_back(curr->right->val);
                pathSt.push(rightPath);
                targetSt.push(currTarget - curr->val);
            }
        }

        return ans;

    }
};