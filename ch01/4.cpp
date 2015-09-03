#include <iostream>
#include <algorithm>
#include <string>

using namespace std;

void solution_4(string &str) {
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

int main() {
	string str = " sheng  hui zhou           ";
	solution_4(str);
	cout << str << endl;
}
