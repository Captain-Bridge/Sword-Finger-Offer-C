/*
struct ListNode {
	int val;
	struct ListNode *next;
	ListNode(int x) :
			val(x), next(NULL) {
	}
};*/
class Solution {
public:
    ListNode* FindFirstCommonNode( ListNode* pHead1, ListNode* pHead2) {
		if (!pHead1||!pHead2) {
			return nullptr;
		}
		ListNode* head1 = pHead1;
		int size1=0;
		while(head1){
			head1 = head1->next;
			size1+=1;
		}
		ListNode* head2 = pHead2;
		int size2 = 0;
		while(head2){
			head2 = head2->next;
			size2+=1;
		}
		head1 = pHead1;
		head2 = pHead2;
		if(size1 > size2){
			for(int i=0;i<size1-size2;i++) 
				head1 = head1->next;
		}else{
			for(int i=0;i<size2-size1;i++) 
				head2 = head2->next;
		}

		while(head1 && head2){
			if(head1 == head2) 
				return head1;
			head1 = head1->next;
			head2 = head2->next;
		}
		return nullptr;
    }
};
