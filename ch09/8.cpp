#include <iostream>
#include <vector>
using namespace std;
template<typename I>
void DFS(int n, vector<vector<int>> &ret, vector<int> &path, I b, I e) {
	if(n==0) {
		ret.push_back(path);
		return;
	}
	if(b==e) return;
	DFS(n,ret,path,next(b),e);
	int cur_coin = *b;
	int cur_cnt = n/cur_coin;
	for(int i=1; i<=cur_cnt; ++i) {
		path.push_back(cur_coin);
		DFS(n-i*cur_coin,ret,path,next(b),e);
	}
	for(int i=1; i<=cur_cnt; ++i)
		path.pop_back();

}

vector<vector<int>> solution(int n) {
	vector<vector<int>> ret;
	if(n<=0) return ret;
	const vector<int> coins = {25,10,5,1};
	vector<int> path;
	DFS(n,ret,path,coins.begin(),coins.end());
	return ret;
}


int main() {
	int test = 25;
	auto ret = solution(test);
	for(const auto &r:ret) {
		for(auto i:r) cout << i << " " << ends;
		cout << endl;
	}
}
