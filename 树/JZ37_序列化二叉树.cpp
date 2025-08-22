/*
struct TreeNode {
    int val;
    struct TreeNode *left;
    struct TreeNode *right;
    TreeNode(int x) :
            val(x), left(NULL), right(NULL) {
    }
};
*/
class Solution {
  public:
    char* Serialize(TreeNode* root) {
        if (!root) return nullptr;

        stringstream ss;
        serializeHelper(root, ss);
        string serializedStr = ss.str();

        // 将序列化的字符串转换为 C 风格字符串
        char* result = new char[serializedStr.size() + 1];
        strcpy(result, serializedStr.c_str());
        return result;
    }

    TreeNode* Deserialize(char* str) {
        if (!str) return nullptr;

        stringstream ss(str);
        return deserializeHelper(ss);
    }

  private:
    // 辅助函数：用于序列化，采用前序遍历
    void serializeHelper(TreeNode* root, stringstream& ss) {
        if (!root) {
            ss << "#" << " "; // 用 # 表示空节点
            return;
        }
        ss << root->val << " ";  // 序列化节点值
        serializeHelper(root->left, ss);  // 序列化左子树
        serializeHelper(root->right, ss); // 序列化右子树
    }

    // 辅助函数：用于反序列化，构建二叉树
    TreeNode* deserializeHelper(stringstream& ss) {
        string val;
        ss >> val;

        if (val == "#") return nullptr;  // 如果是空节点，返回 nullptr

        TreeNode* node = new TreeNode(stoi(val));  // 创建节点
        node->left = deserializeHelper(ss);  // 递归构建左子树
        node->right = deserializeHelper(ss); // 递归构建右子树

        return node;
    }
};