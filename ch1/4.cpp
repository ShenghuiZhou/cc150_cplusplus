/*----------------------------------------------------
> File Name:    4.cpp
> Author:       Shenghui Zhou
> Mail:         shzhouus@gmail.com 
> Created Time: Wed 12 Aug 2015 09:31:54 AM CDT
----------------------------------------------------*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <utility>
#include <iterator>

using namespace std;

void replaceSpace (string &str) {
	auto str_rend = find_if(str.rbegin(),str.rend(),[](char c){
				return c!=' ';
			});
	auto str_end = str_rend.base();
	int cnt = count_if(str.begin(),str_end,[](char c) {
				return c==' ';
			});
	auto new_end = next(str_end,cnt*2);
	auto i = prev(str_end), j = prev(new_end);
	while(i>=str.begin()) {
		if(*i!=' ') *j--=*i--;
		else {
			*j--='0';
			*j--='2';
			*j--='%';
			--i;
		}
	}
}
