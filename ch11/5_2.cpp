/*----------------------------------------------------
> File Name:    5.cpp
> Author:       Shenghui Zhou
> Mail:         shzhouus@gmail.com 
> Created Time: Sun 15 Feb 2015 02:20:59 PM CST
----------------------------------------------------*/

#include <iostream>
#include <vector>
#include <algorithm>
#include <string>
#include <unordered_map>
#include <utility>
#include <iterator>

using namespace std;


int solution(const string &target, const vector<string> &words) 
{
	int b = 0;
	int e = words.size();
	while(b!=e) {
		auto mid = (b+e)>>1;
		auto orig_mid = mid;
		while(mid!=e&&words[mid]=="") ++mid;

		if(mid==e) e=orig_mid;
		else {
			if(words[mid]==target) return mid;
			else if(words[mid]<target)
				b = mid+1;
			else 
				e=orig_mid;
		}
	}
	return -1;
}

int main()
{
	vector<string> words = {
		"at", "", "", "", "ball", "", "", "car", "", "", "dad", "", ""
	};
	cout<<solution("ball",words)<<endl;
	return 0;
}
