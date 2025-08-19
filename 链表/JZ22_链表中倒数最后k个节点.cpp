/**
 * struct ListNode {
 *	int val;
 *	struct ListNode *next;
 *	ListNode(int x) : val(x), next(nullptr) {}
 * };
 */
#include <cstddef>
class Solution {
public:
    /**
     * 代码中的类名、方法名、参数名已经指定，请勿修改，直接返回方法规定的值即可
     *
     * 
     * @param pHead ListNode类 
     * @param k int整型 
     * @return ListNode类
     */
    ListNode* FindKthToTail(ListNode* pHead, int k) {
        // write code here
        ListNode* head = pHead;
        int length = 0;
        while(head){
            head = head->next;
            length++;
        }
        if(length<k){
            return NULL;
        }
        head = pHead;
        for(int i = 0; i < (length - k); i++){
            head = head->next;
        }
        return head;
    }
};
