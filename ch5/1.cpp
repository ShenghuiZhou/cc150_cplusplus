#include <iostream>

using namespace std;

void printBits(int x) {
	for(int i=31; i>=0; --i)
		cout << ((x>>i)&0x1) << ends;
	cout << endl;
}

int solution(int N, int M, int j, int i) {
	int mask_1 = (0x1<<(j+1))-1;
	int mask_2 = (0x1<<i)-1;
	int mask = ~(mask_1^mask_2);
	return (N&mask)|(M<<i);
}
int main() {
	int N = 1<<10, M = 19, j=6, i=2;
	auto ret = solution(N,M,j,i);
	printBits(N);
	printBits(M);
	printBits(ret);
}
