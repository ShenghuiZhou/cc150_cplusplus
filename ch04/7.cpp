#include <cstdlib>
#include <algorithm>
#include <vector>
using namespace std;
//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};    

bool findAncestors(TreeNode *root, TreeNode *target, vector<TreeNode*> &path) {
	if(!root) return false;
	path.push_back(root);
	if(root==target||findAncestors(root->left,target,path)||findAncestors(root->right,target,path)) 
		return true;
	path.pop_back();
	return false;
}
TreeNode* lowestCommonAncestor(TreeNode* root, TreeNode* p, TreeNode* q) {
	vector<TreeNode *> p_ancestors, q_ancestors;
	findAncestors(root,p,p_ancestors);
	findAncestors(root,q,q_ancestors);

	TreeNode *ret = nullptr;

	for(int i=0, j=0; i!=p_ancestors.size()&&j!=q_ancestors.size()&&p_ancestors[i]==q_ancestors[j]; ++i,++j)
		ret = p_ancestors[i];

	return ret;
}
