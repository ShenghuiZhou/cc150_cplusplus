/*----------------------------------------------------
> File Name:    8.cpp
> Author:       Shenghui Zhou
> Mail:         shzhouus@gmail.com 
> Created Time: Fri 17 Apr 2015 11:52:10 AM CDT
----------------------------------------------------*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <cstring>
#include <unordered_map>
#include <utility>
#include <iterator>

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
