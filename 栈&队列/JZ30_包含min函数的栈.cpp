#include <stack>
class Solution {
  public:
    void push(int value) {
        if(!tail){
            tail = new ListNode(value);
            tail->prev = nullptr;
            tail->next = nullptr;
        }else {
            ListNode* newNode = new ListNode(value);
            newNode->prev = tail;
            newNode->next = nullptr;
            tail->next = newNode;
            tail = tail->next;
        }
    }
    void pop() {
        tail = tail->prev;
        ListNode* popNode = tail->next;
        tail->next = nullptr;
        delete popNode;
    }
    int top() {
        return tail->val;
    }
    int min() {
        ListNode* curr = tail;
        int minVal = curr->val;
        while (curr) {
            if (curr->val < minVal) minVal = curr->val;
            curr = curr->prev;
        }
        return minVal;
    }
  private:

    struct ListNode {
        int val;
        struct ListNode* next;
        struct ListNode* prev;
        ListNode(int x) : val(x), next(nullptr),prev(nullptr) {}
    };
    ListNode* tail;
};