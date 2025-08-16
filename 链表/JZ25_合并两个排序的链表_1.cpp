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
     * @param pHead1 ListNode类 
     * @param pHead2 ListNode类 
     * @return ListNode类
     */
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        ListNode* List1 = pHead1;
        ListNode* List2 = pHead2;
        
        //二者其中一个为空时返回另一个。
        if (List1==NULL) {
            return List2;
        }else if (List2==NULL) {
            return List1;
        }
        
        //初始化新链表头为两个链表中第一个元素较小的那一个头
        ListNode* ans_head;
        if(List1->val <= List2->val){
            ans_head = List1;
            List1 = List1->next;
        }else{
            ans_head = List2;
            List2 = List2->next;
        }
        ListNode* ans = ans_head;
        
        //头插法，双指针同时遍历两个链表，选择两个链表中较小的那一个插入到新的链表里面去
        while (true) {
            
            //如果某个链表已经插完了，则把另一个链表插入到当前处，跳出
            if (List1==NULL) {
                ans_head->next = List2;
                break;
            }
            if (List2==NULL) {
                ans_head->next = List1;
                break;
            }
            
            //判断+头插
            if (List1->val <= List2->val) {
                ans_head->next = List1;
                List1 = List1->next;
            }else {
                ans_head->next = List2;
                List2 = List2->next;    
            }
            ans_head = ans_head->next;
        }
        return ans;
    }
};