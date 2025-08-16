class Solution {
public:
    ListNode* Merge(ListNode* pHead1, ListNode* pHead2) {
        //一个已经为空了，返回另一个
        if(pHead1 == NULL) 
            return pHead2;
        if(pHead2 == NULL)
            return pHead1;
        
        //先用较小的值的节点
        if(pHead1->val <= pHead2->val){ 
            //递归往下
            pHead1->next = Merge(pHead1->next, pHead2); 
            return pHead1; 
        }else{
            //递归往下
            pHead2->next = Merge(pHead1, pHead2->next); 
            return pHead2;
        }
    }
};
