struct ListNode {
	int val;
	ListNode *next;

	ListNode(int i=0)
		:val(i),next(nullptr) { }
};

ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
	ListNode dummyH(-1);
	auto pre = &dummyH;
	int carry = 0;
	while(l1||l2) {
		int val1 = 0, val2 = 0;
		if(l1) {
			val1 = l1->val;
			l1 = l1->next;
		}
		if(l2) {
			val2 = l2->val;
			l2 = l2->next;
		}
		int tmp = val1+val2+carry;
		carry = tmp/10;
		tmp %= 10;

		auto new_node = new ListNode (tmp);
		pre->next = new_node;
		pre = pre->next;
	}

	if(carry) {
		auto new_node = new ListNode (1);
		pre->next = new_node;
	}
	return dummyH.next;
}
