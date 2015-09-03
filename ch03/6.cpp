#include <iostream>
#include <vector>
#include <stack>
using namespace std;

class AscendingStack {
	private:
		stack<int> data;
	public:
		void push(int x) {
			stack<int> cache;
			while(!data.empty() && data.top()>x) {
				cache.push(data.top());
				data.pop();
			}
			data.push(x);
			while(!cache.empty()) {
				data.push(cache.top());
				cache.pop();
			}
		}

		void pop() {
			data.pop();
		}

		bool empty() const {
			return data.empty();
		}

		int top() const {
			return data.top();
		}
};

int main() {
	vector<int> test = {2,4,3,1,5,7,2,0,10,-2};
	AscendingStack stk;
	for(auto i:test) stk.push(i);
	while(!stk.empty()) {
		cout << stk.top() << endl;
		stk.pop();
	}
}
