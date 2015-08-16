/*----------------------------------------------------
> File Name:    1.cpp
> Author:       Shenghui Zhou
> Mail:         shzhouus@gmail.com 
> Created Time: Wed 12 Aug 2015 09:24:02 AM CDT
----------------------------------------------------*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <utility>
#include <iterator>

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

