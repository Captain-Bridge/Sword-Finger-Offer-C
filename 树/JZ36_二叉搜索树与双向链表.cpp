/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};*/
#include <stack>
class Solution {
  public:
    TreeNode* Convert(TreeNode* pRootOfTree) {
        if (!pRootOfTree) return nullptr;

        stack<TreeNode*> st;
        TreeNode* curr = pRootOfTree;
        TreeNode* pre = nullptr;
        TreeNode* head = nullptr;

        while (curr != nullptr || !st.empty()) {
            // 将当前节点及其所有左子节点压入栈中
            while (curr != nullptr) {
                st.push(curr);
                curr = curr->left;
            }

            // 当前节点为空，栈顶元素就是左子树的最深节点
            curr = st.top();
            st.pop();

            // 处理当前节点
            if (pre == nullptr) {
                head = curr;  // 保存链表的头
            } else {
                pre->right = curr;  // 前一个节点的右指针指向当前节点
                curr->left = pre;   // 当前节点的左指针指向前一个节点
            }

            pre = curr;  // 更新前一个节点为当前节点

            // 处理当前节点的右子树
            curr = curr->right;
        }

        return head;
    }
};

