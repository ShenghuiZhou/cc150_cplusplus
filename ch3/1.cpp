#include <iostream>
#include <vector>

using namespace std;

class ThreeStack {
	private:
		vector<int> data = {0,0,0}; // the only array
		
		vector<int> begs = {0,1,2};
		vector<int> size = {0,0,0};
		vector<int> caps = {1,1,1};

	public:
		void push(int val, int stk) {
			if(size[stk]==caps[stk]) {
				data.insert(next(data.begin(),begs[stk]+caps[stk]),caps[stk],0);
				caps[stk] += caps[stk];
				begs[1] = begs[0] + caps[0];
				begs[2] = begs[1] + caps[1];
			}
			data[begs[stk]+size[stk]] = val;
			++size[stk];
		}

		bool empty(int stk) const {
			return size[stk] == 0;
		}

		void pop(int stk) {
			if(!empty(stk)) {
				data[begs[stk]+size[stk]-1] = 0;
				--size[stk];
			}
		}

		int top(int stk) const {
			if(!empty(stk)) 
				return data[begs[stk]+size[stk]-1];
		}
};
