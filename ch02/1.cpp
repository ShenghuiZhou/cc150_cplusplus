#include <unordered_set>
using namespace std;

struct ListNode {
	int val;
	ListNode *next;

	ListNode(int i=0)
		:val(i),next(nullptr) { }
};

ListNode* solution(ListNode *head) {
	ListNode dummyH(-1);
	dummyH.next = head;
	auto pre = &dummyH, cur = head;
	unordered_set<int> check;
	while(cur) {
		if(check.find(cur->val)==check.end()) {
			check.insert(cur->val);
			pre = pre->next;
			cur = cur->next;
		}
		else {
			auto to_del = cur;
			cur = cur->next;
			pre->next = cur;
			delete to_del;
		}
	}
	return dummyH.next;
}

