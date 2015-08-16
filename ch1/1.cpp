#include <iostream>
#include <string>

using namespace std;

bool isUniqueChars(const string &str) {
	int check = 0;
	for(auto c:str) {
		int tmp = tolower(c) - 'a';
		if((check>>tmp) & 0x1) return false;
		check |= 0x1<<tmp;
	}
	return true;
}

int main() {
	string test = "hello";
	cout << std::boolalpha << isUniqueChars(test) << endl;
}

