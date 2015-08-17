#include <iostream>
#include <string>
#include <unordered_map>

using namespace std;

string solution_5(const string &str) {
	string ret;
	auto i = str.begin();
	while(i!=str.end()) {
		char c = *i;
		int cnt = 1;
		++i;
		while(i!=str.end()&&*i==*prev(i)) {
			++i;
			++cnt;
		}
		ret.push_back(c);
		ret+=to_string(cnt);
	}
	return ret.size()<=str.size() ? ret:str;
}

int main() {
	string test = "aabcccccaaa";
	cout << solution_5(test) << endl;
}
