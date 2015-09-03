#include <vector>
#include <algorithm>
#include <iostream>
using namespace std;

void printBits(int x) {
	for(int i=31; i>=0; --i) 
		cout << ((x>>i)&0x1) << ends;
	cout << endl;
}

//naive solution
int count1s(int x) {
	int cnt=0;
	for(int i=31; i>=0; --i) 
		cnt+=((x>>i)&0x1);
	return cnt;
}

int naive_solution(int x) {
	const int cnt = count1s(x--);
	while(count1s(x)!=cnt) --x;
	return x;
}

//better one
int solution(int x) {
	int i=0, cnt=0;
	bool flag = false;
	while(i!=32) {
		auto tmp = (x>>i)&0x1;
		if(tmp==1) {
			++cnt;
			if(flag) break;
		}
		else flag = true;
		++i;
	}
	int mask = ~((0x1<<(i+1))-1);
	x &= mask;
	mask = ((0x1<<cnt)-1)<<(i-1);
	x |= mask;
	return x;
}

int main(){
	int test = 10;
	auto r1 = naive_solution(test);
	auto r2 = solution(test);
	cout << r1 << " " << r2 << endl;
}
