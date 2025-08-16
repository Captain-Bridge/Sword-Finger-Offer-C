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
        int i = 0;
        vector<int> ans;
        if(head == NULL){
            return ans; 
        }
        while (head) {
            ans.push_back(head->val);
            i++;
            head = head->next;
        }
        int temp;
        for(int j = 0; j < i/2; j++){
            temp = ans[j] ;
            ans[j] = ans[i-j-1];
            ans[i-j-1] = temp;
        }
        return ans;
    }
};
