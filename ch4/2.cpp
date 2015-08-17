#include <iostream>
#include <algorithm>
#include <unordered_map>
#include <unordered_set>

using namespace std;

bool solution_2(int start, int end, unordered_map<int,unordered_set<int>> &G) {
	unordered_map<int,bool> check;
	for(auto iter = G.begin(); iter!=G.end(); ++iter) check[iter->first] = false;
	check[start] = check[end] = true;
	unordered_set<int> set1 = {start}, set2 = {end};
	unordered_set<int> *p1 = &set1, *p2 = &set2;
	
	while(!set1.empty() && !set2.empty()) {
		if(set1.size()>set2.size()) swap(p1,p2);
		unordered_set<int> tmp;
		for(auto i:*p1) {
			for(auto j:G[i]) {
				if(p2->find(j)!=p2->end()) return true;
				if(check[j]==false) {
					check[j] = true;
					tmp.insert(j);
				}
			}
		}
		*p1 = tmp;
	}

	return false;
}
