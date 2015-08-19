struct ListNode {
	int val;
	ListNode *next;

	ListNode(int i=0)
		:val(i),next(nullptr) { }
};

ListNode* partition(ListNode* head, int x) {
	ListNode dummyL(-1), dummyR(-1);
	auto prevL = &dummyL, prevR = &dummyR;
	auto cur = head;
	while(cur) {
		if(cur->val<x) {
			prevL->next=cur;
			prevL = cur;
		}
		else {
			prevR->next=cur;
			prevR = cur;
		}
		cur = cur->next;
	}
	prevL->next = dummyR.next;
	prevR->next = nullptr;
	return dummyL.next;
}
