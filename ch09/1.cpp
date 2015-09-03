#include <iostream>
#include <vector>

using namespace std;

int solution(int n) {
	if(n<=3) return n;
	vector<int> cache(n+1,0);
	cache[1]=1;
	cache[2]=2;
	cache[3]=3;

	for(int i=4; i!=n+1; ++i) 
		cache[i] = cache[i-1] + cache[i-2] + cache[i-3];

	return cache[n];
}
