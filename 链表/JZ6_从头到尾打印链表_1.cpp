/**
*  struct ListNode {
*        int val;
*        struct ListNode *next;
*        ListNode(int x) :
*              val(x), next(NULL) {
*        }
*  };
*/
#include <cstddef>
#include <cstdio>
#include <vector>
class Solution {
  public:
    vector<int> printListFromTailToHead(ListNode* head) {
        ListNode* curr = head;
        ListNode* prev = NULL;
        while (head) {
            curr = head->next;
            head->next = prev;
            prev = head;
            head = curr;
        }
        vector<int> ans;
        while(prev){
            ans.push_back(prev->val);
            prev = prev->next;
        }
        return ans;
    }
};
