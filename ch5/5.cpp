#include <iostream>

using namespace std;

int solution(int a, int b) {
	int ret = 0;
	const int N = sizeof(int)*8;
	for(int i=0; i!=N; ++i) 
		ret += ((a>>i)&0x1) ^ ((b>>i)&0x1);
	return ret;
}
int solution_2(int a, int b) {
	int ret = 0;
	auto tmp = a^b;
	const int N = sizeof(int)*8;
	for(int i=0; i!=N; ++i)
		ret += (tmp>>i)&0x1;
	return ret;
}
int main() {
	cout << solution(31,14) << endl;
	cout << solution_2(31,14) << endl;
}

