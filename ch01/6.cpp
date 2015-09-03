#include <iostream>
#include <vector>

using namespace std;

void rotate(vector<vector<int>> &matrix) {
	const int N = matrix.size();
	for(int i=0, j=N-1; i<j; ++i,--j) {
		for(int k=0; k!=N; ++k) {
			swap(matrix[i][k],matrix[j][k]);
		}
	}

	for(int i=0; i!=N; ++i) {
		for(int j=i+1; j!=N; ++j) {
			swap(matrix[i][j],matrix[j][i]);
		}
	}
}
