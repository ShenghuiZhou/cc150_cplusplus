#include <iostream>
#include <vector>
#include <unordered_map>

using namespace std;

bool solution_3(const string &str1, const string &str2) {
	if(str1.size()!=str2.size()) return false;
	unordered_map<char,int> check;
	for(auto c:str1) check[c]+=1;
	for(auto c:str2) {
		auto iter = check.find(c);
		if(iter==check.end()) return false;
		--iter->second;
		if(iter->second<0) return false;
	}
	return true;
}

int main() {
	string str1 = "hello world";
	string str2 = "world hello";
	cout << boolalpha << solution_3(str1,str2) << endl;
}
