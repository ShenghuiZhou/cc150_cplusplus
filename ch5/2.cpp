#include <iostream>
#include <string>
#include <algorithm>

using namespace std;

string solution(double num) {
	int a = num;
	double b = num - a;
	string ret;
	int flag = false;
	for(int i=31;i>=0;--i) {
		int cur = (a>>i)&0x1;
		if(cur) flag=true;
		if(flag) ret.push_back('0'+cur);
	}
	ret.push_back('.');
	while(ret.size()<=32&&b!=0) {
		b*=2;
		a=b;
		ret.push_back('0'+a);
		b-=a;
	}
	return b==0?ret:"Error";
} 

int main() {
	string num = "11.875";
	cout << solution(stod(num)) << endl;
}
