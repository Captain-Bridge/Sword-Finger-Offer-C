/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
#include <queue>
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
		vector<int> ans;
		if (!root) return ans;

		queue<TreeNode*> q;
		q.push(root);
		while(!q.empty()){
			TreeNode* curr = q.front();
			q.pop();
			
			ans.push_back(curr->val);

			if(curr->left) q.push(curr->left);
			if(curr->right) q.push(curr->right);
		}

		return ans;
    }
};
