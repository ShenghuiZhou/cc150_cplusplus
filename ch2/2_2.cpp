#include <vector>
#include <iostream>
using namespace std;
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

int main() {
	vector<int> nums = {1,2,3,4,5};
	auto head = new ListNode (nums[0]);
	auto pre = head;
	for(int i=1; i!=nums.size(); ++i) {
		auto new_node = new ListNode (nums[i]);
		pre->next = new_node;
		pre = pre->next;
	}
	cout << solution(head,2)->val << endl;
}

