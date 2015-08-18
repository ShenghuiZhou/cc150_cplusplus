struct ListNode {
	int val;
	ListNode *next;

	ListNode(int i=0)
		:val(i),next(nullptr) { }
};

ListNode *solution(ListNode *head, int k) {
	auto f=head, s=head;
	while(k) {
		f = f->next;
		--k;
	}
	while(f) {
		f = f->next;
		s = s->next;
	}
	return s;
}

