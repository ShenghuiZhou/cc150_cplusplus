struct ListNode {
	int val;
	ListNode *next;

	ListNode(int i=0)
		:val(i),next(nullptr) { }
};

void deleteNode(ListNode* node) {
	auto to_del = node->next;
	*node = *(node->next);
	delete to_del;
	to_del = nullptr;
}
