#include <vector>
#include <stack>

using namespace std;

class SetOfStacks {
	private:
		static constexpr size_t maxSize = 3;
		vector<stack<int>> stks;
	public:
		void push(int x) {
			if(stks.empty()||stks.back().size()==maxSize)
				stks.push_back(stack<int>());
			stks.back().push(x);
		}

		bool empty() const {
			return stks.empty();
		}

		int top() const {
			return stks.back().top();
		}

		void pop() {
			stks.back().pop();
			if(stks.back().empty()) 
				stks.pop_back();
		}

		void pop_at(int ind) {
			stks[ind].pop();
			if(stks[ind].empty()) 
				stks.erase(next(stks.begin(),ind));
		}
};
