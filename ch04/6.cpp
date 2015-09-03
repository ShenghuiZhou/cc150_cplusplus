#include <cstdlib>
#include <algorithm>
using namespace std;
//Definition for a binary tree node.
struct TreeNode {
	int val;
	TreeNode *parent;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), parent(NULL),left(NULL), right(NULL) {}
};

TreeNode *solution(TreeNode *cur) {
	if(cur->right) {
		auto ret = cur->right;
		while(ret->left) ret=ret->left;
		return ret;
	}
	else {
		auto p = cur->parent;
		while(p&&cur==p->right) {
			cur = p;
			p = cur->parent;
		}
		return p;
	}
}
