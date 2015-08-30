#include <vector>
using namespace std;

int uniquePaths(int i, int j, vector<vector<int>> &f) {
	if(i<0||j<0) return 0;
	if(f[i][j]!=0) return f[i][j];
	f[i][j] = uniquePaths(i-1,j,f) + uniquePaths(i,j-1,f);
	return f[i][j];
}

int uniquePaths(int m, int n) {
	vector<vector<int>> f(m,vector<int>(n,0));
	f[0][0] = 1;
	return uniquePaths(m-1,n-1,f);
}
