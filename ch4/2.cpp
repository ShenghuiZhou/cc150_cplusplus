#include <iostream>
#include <string>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

int ladderLength(string beginWord, string endWord, unordered_set<string>& wordDict) {
	unordered_set<string> set1 = {beginWord}, set2 = {endWord};
	unordered_set<string> *p1 = &set1, *p2 = &set2;
	int ret = 1;
	while(!set1.empty() && !set2.empty()) {
		++ret;
		if(p2->size()<p1->size()) swap(p1,p2);
		unordered_set<string> tmp;
		for(auto str:*p1) {
			for(int i=0; i!=str.size(); ++i) {
				for(int j=0; j!=26; ++j) {
					char c= 'a' + j;
					if(c!=str[i]) {
						swap(str[i],c);
						if(p2->find(str)!=p2->end()) return ret;
						auto iter = wordDict.find(str);
						if(iter!=wordDict.end()) {
							wordDict.erase(iter);
							tmp.insert(str);
						}
						swap(str[i],c);
					}
				}
			}
		}
		*p1 = tmp;
	}
	return 0;
}
