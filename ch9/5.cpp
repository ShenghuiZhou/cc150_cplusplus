#include <string>
#include <algorithm>
#include <iostream>
using namespace std;

bool nextPermutation(string &str) {
	if(str.empty()) return false;
	auto i = next(str.rbegin());
	while(i!=str.rend() && *i>=*prev(i)) ++i;
	if(i==str.rend()) {
		reverse(str.begin(),str.end());
		return false;
	}
	auto j = str.rbegin();
	while(*j<=*i) ++j;
	swap(*i,*j);
	reverse(str.rbegin(),i);
	return true;
}

vector<string> allPermutations(string &str) {
	vector<string> ret;
	sort(str.begin(),str.end());
	do {
		ret.push_back(str);
	}while(nextPermutation(str));
	return ret;
}

int main() {
	string test = "abcd";
	auto r = allPermutations(test);
	for(auto s:r)
		cout << s << endl;
}
