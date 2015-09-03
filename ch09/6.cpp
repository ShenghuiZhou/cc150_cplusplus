#include <vector>
#include <string>
using namespace std;
void DFS(int l, int r, int n, vector<string> &ret, string &p) {
	if(l<r||l>n) return;
	if(l==r&&l==n) {
		ret.push_back(p);
		return;
	}
	p.push_back('(');
	DFS(l+1,r,n,ret,p);
	p.pop_back();
	p.push_back(')');
	DFS(l,r+1,n,ret,p);
	p.pop_back();
}
vector<string> generateParenthesis(int n) {
	vector<string> ret;
	if(n==0) return ret;
	string path = "(";
	int l = 1, r=0;
	DFS(l,r,n,ret,path);
	return ret;
}
