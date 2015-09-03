#include <cstdlib>
#include <algorithm>
#include <limits>
using namespace std;
//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};    

bool isValidBST(TreeNode *root, long u, long l) {
	if(!root) return true;
	long cur = static_cast<long>(root->val);
	if(cur>=u||cur<=l) return false;
	return isValidBST(root->left,cur,l) && isValidBST(root->right,u,cur);
}
bool isValidBST(TreeNode* root) {
	long upper = static_cast<long>(numeric_limits<int>().max()) + 1;
	long lower = static_cast<long>(numeric_limits<int>().min()) - 1;
	return isValidBST(root,upper,lower);
}
