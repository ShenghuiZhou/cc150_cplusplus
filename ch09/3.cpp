#include <vector>
#include <iostream>
using namespace std;

int solution(vector<int> &nums) {
	int b = 0, e = nums.size();
	while(b!=e) {
		auto m = (b+e)>>1;
		if(nums[m]==m) return m;
		else if(nums[m]<m) b = m+1;
		else e = m;
	}
	return -1;
}

int solutionWithDup(int b, int e, vector<int> &nums) {
	if(b<0||e>nums.size()||b>=e) return -1;
	auto m = (b+e)>>1;
	if(nums[m]==m) return m;
	int tmp = solutionWithDup(b,min(m,nums[m]+1),nums);
	if(tmp!=-1) return tmp;
	return solutionWithDup(max(m+1,nums[m]),e,nums);
}

int solutionWithDup(vector<int> &nums) {
	int b = 0, e = nums.size();
	return solutionWithDup(b,e,nums);
}

int main() {
	vector<int> nums = {-10,-5,2,2,2,3,4,7,9,12,13};
	cout << boolalpha << solutionWithDup(nums) << endl;
}
