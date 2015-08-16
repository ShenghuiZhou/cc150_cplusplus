#include <iostream>
#include <string>
#include <cstring>

using namespace std;

bool solution(const string &str1, const string &str2) {
	if(str1.length()!=str2.length()) return false;
	auto str = str1+str1;
	return strstr(str.c_str(),str2.c_str()) != nullptr;
}

int main(){
	string str1 = "waterbottle";
	string str2 = "erbottlewat";
	cout << solution(str1,str2) << endl;
}
