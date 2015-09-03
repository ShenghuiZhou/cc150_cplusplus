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

bool isSameTree(TreeNode* p, TreeNode* q) {
	if(!p) return !q;
	if(!q) return !p;
	if(p->val!=q->val) return false;
	return isSameTree(p->left,q->left) && isSameTree(p->right,q->right);
}

bool subTree(TreeNode *T1, TreeNode *T2) {
	if(isSameTree(T1,T2)) return true;
	return isSameTree(T1->left,T2) || isSameTree(T1->right,T2);
}
