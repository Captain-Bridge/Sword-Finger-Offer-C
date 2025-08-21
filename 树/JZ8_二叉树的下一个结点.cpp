/*
struct TreeLinkNode {
    int val;
    struct TreeLinkNode *left;
    struct TreeLinkNode *right;
    struct TreeLinkNode *next;
    TreeLinkNode(int x) :val(x), left(NULL), right(NULL), next(NULL) {
        
    }
};
*/
#include <stack>
class Solution {
public:
    TreeLinkNode* GetNext(TreeLinkNode* pNode) {
        TreeLinkNode* root = pNode;
        while (root->next) {
            root = root->next;
        }

        bool sameFlag = false;

        stack<TreeLinkNode*> st;
        TreeLinkNode* curr = root;
        while (curr||!st.empty()) {
            while (curr) {
                st.push(curr);
                curr = curr->left;
            }

            curr = st.top();
            st.pop();

            cout << curr->val << endl;
            if(sameFlag) return curr;
            if(curr->val == pNode->val) sameFlag = true;

            curr = curr->right;
        }

        return nullptr;
    }
};
