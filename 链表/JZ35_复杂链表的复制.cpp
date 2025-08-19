/*
struct RandomListNode {
    int label;
    struct RandomListNode *next, *random;
    RandomListNode(int x) :
            label(x), next(NULL), random(NULL) {
    }
};
*/
class Solution {
  public:
    RandomListNode* Clone(RandomListNode* pHead) {
        if(!pHead){
            return nullptr;
        }
        RandomListNode* head = pHead;
        while (head) {
            RandomListNode* copy = new RandomListNode(head->label);
            copy->next = head->next;
            head->next = copy;
            head = copy->next;
        }
        head = pHead;
        while (head) {
            if (head->random) {
                head->next->random = head->random->next;
            }
            head = head->next->next;
        }
        RandomListNode* newHead = pHead->next;
        RandomListNode* cur = pHead;

        while (cur) {
            RandomListNode* copy = cur->next;
            cur->next = copy->next;              // 恢复原链表
            if (copy->next) 
                copy->next = copy->next->next; // 连接新链表
            cur = cur->next;
        }

        return newHead;

    }
};
