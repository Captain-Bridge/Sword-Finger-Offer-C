/**
 * struct TreeNode {
 *  int val;
 *  struct TreeNode *left;
 *  struct TreeNode *right;
 *  TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 * };
 */
#include <queue>
#include <vector>
class Solution {
  public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     *
     * @param preOrder int整型vector
     * @param vinOrder int整型vector
     * @return TreeNode类
     */
    TreeNode* reConstructBinaryTree(vector<int>& preOrder, vector<int>& vinOrder) {
        if (preOrder.size() == 0) return nullptr;

        TreeNode* pRoot = new TreeNode(preOrder[0]);

        vector<int> leftVinOrder;
        int root = 0;
        for (; root < vinOrder.size(); root++) {
            if (preOrder[0] == vinOrder[root]) {
                break;
            }
            leftVinOrder.push_back(vinOrder[root]);
        }

        vector<int> rightVinOrder;
        for (int i = root + 1; i < vinOrder.size(); i++) {
            rightVinOrder.push_back(vinOrder[i]);
        }

        vector<int> leftPreOrder;
        int Count = 0;
        for (int i = 0; i < preOrder.size(); i++) {
            if (find(leftVinOrder.begin(), leftVinOrder.end(),
                     preOrder[i]) != leftVinOrder.end()) {
                leftPreOrder.push_back(preOrder[i]);
                Count++;
            }
        }

        vector<int> rightPreOrder;
        Count = 0;
        for (int i = 0; i < preOrder.size(); i++) {
            if (find(rightVinOrder.begin(), rightVinOrder.end(),
                     preOrder[i]) != rightVinOrder.end()) {
                rightPreOrder.push_back(preOrder[i]);
                Count++;
            }
        }


        pRoot->left = reConstructBinaryTree(leftPreOrder, leftVinOrder);
        pRoot->right = reConstructBinaryTree(rightPreOrder, rightVinOrder);

        return pRoot;
    }
};