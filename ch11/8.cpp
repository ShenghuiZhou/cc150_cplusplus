#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	int cnt;
	TreeNode *left;
	TreeNode *right;
	
	TreeNode(int v=0, int c=0, TreeNode *l=nullptr, TreeNode *r=nullptr) 
		:val(v),cnt(c),left(l),right(r) { }
};

class BST {
	private:
		TreeNode *root;

		void insert(TreeNode *&cur, int x) {
			if(!cur) cur = new TreeNode (x,1,nullptr,nullptr);
			else if(cur->val<x) insert(cur->right,x);
			else if(cur->val>x) {
				cur->cnt += 1;
				insert(cur->left,x);
			}
			else cur->cnt += 1;
		}
		void clear (TreeNode *&cur) {
			if(!cur) return;
			clear(cur->left);
			clear(cur->right);
			delete cur;
			cur = nullptr;
		}
	public:
		BST()
			:root(nullptr) { }
		~BST() {
			clear(root);
		}

		void insert(int x) {
			insert(root,x);
		}

		int getRankOf(int x) const {
			int ret = 0;
			auto cur = root;
			while(cur) {
				if(cur->val==x) {
					ret += cur->cnt-1;
					return ret;
				}
				else if(cur->val>x) {
					cur = cur->left;
				}
				else {
					ret += cur->cnt;
					cur = cur->right;
				}
			}
			return ret;
		}
};

int main() {
	vector<int> test = {5,1,4,4,5,9,7,13,3};
	BST tree;
	for(auto i:test) tree.insert(i);
	
	cout << tree.getRankOf(1) << endl;
	cout << tree.getRankOf(3) << endl;
	cout << tree.getRankOf(4) << endl;
	cout << tree.getRankOf(14) << endl;
	cout << tree.getRankOf(8) << endl;
}
