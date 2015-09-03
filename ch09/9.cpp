#include <vector>
#include <string>
using namespace std;

void DFS(int i, int n, vector<vector<string>> &ret, vector<int> &rows, vector<bool> &cols, vector<bool> &diag, vector<bool> &anti) {
	if(i==n) {
		vector<string> tmp;
		for(auto c:rows) {
			string s (n,'.');
			s[c] = 'Q';
			tmp.push_back(s);
		}
		ret.push_back(tmp);
		return;
	}

	for(int j=0; j!=n; ++j) {
		if(!cols[j] && !diag[n-1-i+j] && !anti[i+j]) {
			cols[j] = diag[n-1-i+j] = anti[i+j] = true;
			rows[i] = j;
			DFS(i+1,n,ret,rows,cols,diag,anti);
			cols[j] = diag[n-1-i+j] = anti[i+j] = false;
			rows[i] = 0;
		}

	}
}
vector<vector<string>> solveNQueens(int n) {
	vector<vector<string>> ret;
	vector<int> rows(n,0);
	vector<bool> cols(n,false), diag(2*n-1,false), anti(2*n-1,false);
	DFS(0,n,ret,rows,cols,diag,anti);
	return ret;
}
