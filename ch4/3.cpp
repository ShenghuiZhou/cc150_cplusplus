#include <cstdlib>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

TreeNode* solution(int beg, int end, const vector<int> &nums) {
	if(beg==end) return nullptr;
	auto mid = (beg+end)>>1;
	auto ret = new TreeNode (nums[mid]);
	ret->left = solution(beg,mid,nums);
	ret->right = solution(mid+1,end,nums);
	return ret;
}

TreeNode* sortedArrayToBST(vector<int>& nums) {
	return solution(0,nums.size(),nums);
}
