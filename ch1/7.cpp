#include <iostream>
#include <vector>

using namespace std;

void setZeroes(vector<vector<int>> &matrix) {
	const int M=matrix.size();
	const int N=matrix[0].size();
	vector<int> rows(M,1), cols(N,1);
	for(int i=0; i!=M; ++i) {
		for(int j=0; j!=N; ++j) {
			if(matrix[i][j]==0) {
				rows[i] = cols[j] = 0;
			}
		}
	}

	for(int i=0; i!=M; ++i) {
		for(int j=0; j!=N; ++j) {
			if(rows[i]==0||cols[j]==0) 
				matrix[i][j] = 0;
		}
	}
}
