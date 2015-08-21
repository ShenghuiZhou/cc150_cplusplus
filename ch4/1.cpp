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

int getHeight(TreeNode* root) {
	if(!root) return 0;
	auto l = getHeight(root->left);
	auto r = getHeight(root->right);
	if(l==-1||r==-1||abs(l-r)>1) return -1;
	return max(l,r)+1;
}

bool isBalanced(TreeNode* root) {
	return getHeight(root)>=0;
}
