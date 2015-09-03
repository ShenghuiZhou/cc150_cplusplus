#include <vector>
#include <algorithm>
using namespace std;
template<typename I>
void DFS(I b, I e, vector<int> &p, vector<vector<int>> &ret) {
	if(b==e) {
		ret.push_back(p);
		return;
	}
	p.push_back(*b);
	DFS(next(b),e,p,ret);
	p.pop_back();
	DFS(next(b),e,p,ret);
}

vector<vector<int>> subsets(vector<int>& nums) {
	vector<vector<int>> ret;
	if(nums.empty()) return ret;
	sort(nums.begin(),nums.end());
	vector<int> path;
	DFS(nums.begin(),nums.end(),path,ret);
	return ret;
}
