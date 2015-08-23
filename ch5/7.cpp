#include <iostream>
#include <vector>
using namespace std;

//O(1)
int fetch(const vector<int> &a, int i, int j) {	
	return (a[i]>>j)&0x1; 
} 

//O(1)
int get_num(const vector<int> &a, int i) {
	int ret = 0;
	for(int j=0; j!=sizeof(int)*8; ++j) 
		ret |= fetch(a,i,j)<<j;
	return ret;
}

//O(n)
int solution(const vector<int> &a, int n) {
	int ret = 0;
	for(int i=0; i<=n; ++i) ret ^= i;
	for(int i=0; i!=a.size(); ++i) ret ^= get_num(a,i);
	return ret;
}

int main() {
	vector<int> a = {0,1,2,3,4,5,6,7,9};
	cout << solution(a,9) << endl;
}
