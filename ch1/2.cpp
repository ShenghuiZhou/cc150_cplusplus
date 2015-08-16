#include <iostream>
#include <string.h>
using namespace std;

void swap(char &a, char &b) {
	a = a^b;
	b = a^b;
	a = a^b;
}

void reverse(char *str) {
	const int N = strlen(str);
	for(int i=0, j=N-1; i<j; ++i,--j) {
		swap(str[i],str[j]);
	}
}

int main() {
	char str[] = "shenghui zhou";
	reverse(str);
	cout << str << endl;
}
