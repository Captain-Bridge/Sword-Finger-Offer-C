/*
struct ListNode {
    int val;
    struct ListNode *next;
    ListNode(int x) :
        val(x), next(NULL) {
    }
};
*/
class Solution {
public:
    ListNode* deleteDuplication(ListNode* pHead) {
        if (!pHead) return nullptr;

        ListNode dummy(0);
        dummy.next = pHead;
        ListNode* prev = &dummy;
        ListNode* curr = pHead;

        while (curr) {
            bool duplicated = false;
            // 找到一段重复区间
            while (curr->next && curr->val == curr->next->val) {
                duplicated = true;
                curr = curr->next;
            }

            if (duplicated) {
                // 跳过整段重复节点
                prev->next = curr->next;
            } else {
                // 保留当前节点，prev 往前走
                prev = curr;
            }
            curr = curr->next;
        }

        return dummy.next;
    }
};

