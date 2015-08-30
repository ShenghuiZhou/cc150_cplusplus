#include <vector>
#include <iostream>
using namespace std;

vector<int> solution(int b, int e, vector<vector<vector<int>>> &f, const string &str) {
	if(b==e-1) {
		if(str[b]=='0') return {1,0};
		else return {0,1};
	}
	
	if(f[b][e][0]!=-1 && f[b][e][1] !=-1) return f[b][e];
	
	vector<int> &cur = f[b][e];
	cur[0] = cur[1] = 0;
	for(int i=b; i!=e; ++i) {
		char c = str[i];
		if(c!='1' && c!='0') {
			auto left = solution(b,i,f,str);
			auto right = solution(i+1,e,f,str);

			if(c=='*') {
				cur[0] += left[0]*right[0] + left[0]*right[1] + left[1]*right[0];
				cur[1] += left[1]*right[1];
			}

			else if(c=='|') {
				cur[0] += left[0]*right[0];
				cur[1] += left[1]*right[1] + left[1]*right[0] + left[0]*right[1];
			}

			else {
				cur[0] += left[0]*right[0] + left[1]*right[1];
				cur[1] += left[0]*right[1] + left[1]*right[0];
			}
		}
	}
	return cur;
}

vector<int> solution(const string &str) {
	if(str.empty()) return {0,0};
	const int N = str.size();
	vector<vector<vector<int>>> f(N+1,vector<vector<int>>(N+1,{-1,-1}));
	return solution(0,N,f,str);
}

int main() {
	string test = "1^0|0|1";
	auto r = solution(test);
	cout << r[0] << " " << r[1] << endl;
}
