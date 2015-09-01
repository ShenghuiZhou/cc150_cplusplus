#include <vector>
#include <string>
#include <unordered_map>
#include <set>
#include <algorithm>
using namespace std;
vector<vector<string>> groupAnagrams(vector<string>& strs) {
	unordered_map<string,multiset<string>> f;
	for(const auto &s:strs) {
		auto tmp = s;
		sort(tmp.begin(),tmp.end());
		f[tmp].insert(s);
	}
	vector<vector<string>> ret;
	for(auto p:f) {
		vector<string> tmp(p.second.begin(),p.second.end());
		ret.push_back(tmp);
	}
	return ret;
}
