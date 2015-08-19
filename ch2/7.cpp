struct ListNode {
	int val;
	ListNode *next;

	ListNode(int i=0)
		:val(i),next(nullptr) { }
};

ListNode *reverseList(ListNode *head) {
	ListNode dummyH(-1);
	auto prev = &dummyH;
	prev->next = head;
	while(head->next) {
		auto tmp = head->next;
		head->next = tmp->next;
		tmp->next = prev->next;
		prev->next = tmp;
	}
	return dummyH.next;
}

bool solution(ListNode *head) {
	if(!head||!head->next) return true;
	
	auto f=head, s=head, prev=head;
	while(f&&f->next) {
		f=f->next->next;
		prev = s;
		s=s->next;
	}
	prev->next = nullptr;
	
	auto l = head;
	auto r = reverseList(s);
	
	while(l) {
		if(l->val!=r->val) return false;
		l = l->next;
		r = r->next;
	}
	
	return true;
}
