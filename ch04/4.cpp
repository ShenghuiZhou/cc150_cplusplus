#include <vector>
#include <list>
#include <cstdlib>
#include <queue>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

vector<list<TreeNode*>> solution(TreeNode *root) {
	vector<list<TreeNode*>> ret;
	if(!root) return ret;

	queue<pair<TreeNode*,int>> q;
	q.push({root,0});

	while(!q.empty()) {
		auto cur = q.front().first;
		auto cur_depth = q.front().second;
		q.pop();

		if(cur_depth==ret.size()) {
			ret.push_back(list<TreeNode*>());
		}

		ret.back().push_back(cur);

		if(cur->left) q.push({cur->left,cur_depth+1});
		if(cur->right) q.push({cur->right,cur_depth+1});
	}
	return ret;
}
