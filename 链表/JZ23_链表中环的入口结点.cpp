
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
    ListNode* EntryNodeOfLoop(ListNode* pHead) {
        ListNode* fast = pHead;
        ListNode* slow = pHead;
        while(fast && fast->next){
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)
                break;
        }

        if(fast == NULL || fast->next == NULL)
            return NULL;
        ListNode* meet = slow;
        ListNode* head = pHead;
        while(meet!=head){
            meet = meet->next;
            head = head->next;
        }
        return meet;
    }
};