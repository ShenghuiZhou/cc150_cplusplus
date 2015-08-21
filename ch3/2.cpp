#include <stack>
using namespace std;

class MinStack {
	private:
		stack<int> data;
		int cur_min = 0;

	public:
		void push(int x) {
			if(data.empty()) cur_min = x;
			else if(cur_min>=x) {
				data.push(cur_min);
				cur_min = x;
			}
			data.push(x);
		}

		void pop() {
			int x = top();
			data.pop();
			if(x==cur_min && !data.empty()) {
				cur_min = data.top();
				data.pop();
			}
		}

		int top() const{
			return data.top();
		}

		int getMin() const{
			return cur_min;
		}
};
