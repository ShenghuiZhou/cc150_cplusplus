#include <iostream>
using namespace std;

int solution(int x) {
	return (((0x55555555)&x)<<1) | ((0xaaaaaaaa&x)>>1);
}
int main() {
	cout << solution(9) << endl;	
}
