#include <vector>
using namespace std;
//no duplicate exists
int search(vector<int>& nums, int target) {
	int b=0, e=nums.size();
	while(b!=e) {
		int m = (b+e)>>1;
		if(nums[m]==target) return m;
		else if(nums[m]>nums[b]) {
			if(target>=nums[b]&&target<nums[m]) e=m;
			else b=m+1;
		}
		else if(nums[m]<nums[b]) {
			if(target<nums[b]&&target>nums[m]) b=m+1;
			else e=m;
		}
		else return -1;
	}
	return -1;
}

