#include <cstdlib>
#include <algorithm>
using namespace std;
//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};   

void DFS(TreeNode *root, vector<vector<int>> &ret, vector<int> &path, int target) {
	if(!root) return;
	path.push_back(root->val);
	int sum = 0;
	for(auto iter = path.rbegin(); iter!=path.rend();++iter) {
		sum += *iter;
		if(sum==target) 
			ret.push_back(vector<int>(prev(iter.base()),path.end()));
	}
	DFS(root->left,ret,path,target);
	DFS(root->right,ret,path,target);
	path.pop_back();
}

vector<vector<int>> solution(TreeNode *root, int target) {
	vector<vector<int>> ret;
	vector<int> path;
	DFS(root,ret,path,target);
	return ret;
}
