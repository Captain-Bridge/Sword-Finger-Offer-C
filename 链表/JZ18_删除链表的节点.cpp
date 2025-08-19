/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param head ListNode类 
     * @param val int整型 
     * @return ListNode类
     */
    ListNode* deleteNode(ListNode* head, int val) {
        ListNode* yump = new ListNode(-1);
        yump->next = head;
        ListNode* prev = yump;
        ListNode* curr = head;
        while(curr){
            if(curr->val == val){
                prev->next = curr->next;
                break;
            }
            curr = curr->next;
            prev = prev->next;
        }
        return yump->next;
    }
};
