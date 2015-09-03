#include <iostream>
#include <vector>
#include <cstdint>

using namespace std;

typedef uint8_t BYTE;

void printBits(BYTE x) {
	for(int i=7; i>=0; --i) 
		cout << ((x>>i)&0x1) << ends;
}

void printScreen(const vector<BYTE> &screen, const int width) {
	const int height = screen.size()/(width/8);
	cout << "	" << ends;
	for(int i=0; i!=width; ++i) cout << i%10 << ends;
	cout << endl;
	for(int i=0; i!=height; ++i) {
		cout << i <<"	" << ends;
		for(int j=0; j!=width/8; ++j) {
			BYTE tmp = screen[i*width/8+j];
			printBits(tmp);
		}
		cout << endl;
	}
}

void solution(vector<BYTE> &screen, const int width, int x1, int x2, int y) {
	const int height = screen.size()/(width/8); 
	int b = x1/8+1, e=x2/8;
	if(b<=e) {
		for(int i=b; i!=e; ++i) screen[y*(width/8)+i] = 0xff;
		BYTE mask = (1<<(8-x1%8))-1;
		screen[y*(width/8)+b-1] |= mask;
		mask = ~((1<<(8-x2%8-1))-1);
		screen[y*(width/8)+e] |= mask;
	}
	else {
		BYTE mask = ((1<<(x2%8-x1%8+1))-1)<<(8-x2%8-1);
		screen[y*(width/8)+b-1] |= mask;
	}
}

int main() {
	vector<BYTE> screen (1024,0);
	int width = 128;
	solution(screen,width,10,36,2);
	printScreen(screen, width);
}
