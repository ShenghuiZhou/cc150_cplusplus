struct ListNode {
	int val;
	ListNode *next;

	ListNode(int i=0)
		:val(i),next(nullptr) { }
};

ListNode *detectCycle(ListNode *head) {
	auto f=head, s=head, r=head;
	while(f&&f->next) {
		f = f->next->next;
		s = s->next;
		if(f==s) {
			while(r!=s) {
				r = r->next;
				s = s->next;
			}
			return r;
		}
	}
	return nullptr;
}
