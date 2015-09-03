#include <stack>
using namespace std;

class Queue {
	private:
		stack<int> s1;
		stack<int> s2;

		void s1_to_s2() {
			if(s2.empty()) {
				while(!s1.empty()) {
					s2.push(s1.top());
					s1.pop();
				}
			}
		}
	public:
		void push(int x) {
			s1.push(x);
		}

		void pop(void) {
			s1_to_s2();
			s2.pop();
		}

		int peek(void) {
			s1_to_s2();
			return s2.top();
		}

		bool empty(void) {
			return s1.empty() && s2.empty();
		}
};
