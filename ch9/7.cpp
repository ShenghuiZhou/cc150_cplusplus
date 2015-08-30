#include <vector>

using namespace std;

void DFS(vector<vector<int>> &screen, int i, int j, const int new_col, const int old_col) {
	if(i<0||j<0||i>=screen.size()||j>=screen[0].size()||screen[i][j]!=old_col) return;
	screen[i][j] = new_col;
	DFS(screen,i-1,j,new_col,old_col);
	DFS(screen,i+1,j,new_col,old_col);
	DFS(screen,i,j-1,new_col,old_col);
	DFS(screen,i,j+1,new_col,old_col);
}

void solution(vector<vector<int>> &screen, int i, int j, int new_col) {
	if(screen.empty()) return;
	if(i<0||j<0||i>=screen.size()||j>=screen[0].size()||screen[i][j]==new_col) return;
	DFS(screen,i,j,new_col,screen[i][j]);
}
