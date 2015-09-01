#include <iostream>
#include <vector>
#include <string>
using namespace std;

int solution(const string &target, const vector<string> &words, int b, int e) {
	while(b!=e) {
		auto mid = (b+e)>>1;
		if(words[mid]=="") {
			int tmp = solution(target,words,b,mid);
			return tmp!=-1 ? tmp : solution(target,words,mid+1,e);
		}
		else {
			if(words[mid]==target) return mid;
			else if(words[mid]<target) b = mid+1;
			else e=mid;
		}
	}
	return -1;
}

int main()
{
	vector<string> words = {
		"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""
	};
	cout<<solution("ball",words,0,words.size())<<endl;
	return 0;
}
