#include <vector>

using namespace std;

/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
Integers in each row are sorted from left to right.
The first integer of each row is greater than the last integer of the previous row.
*/
bool solution(const vector<vector<int>> nums, int tar) {
	const int M = nums.size();
	const int N = nums[0].size();
	int b=0, e=M*N;
	while(b!=e) {
		auto m = (b+e)>>1;
		auto i = m/N;
		auto j = m%N;
		if(nums[i][j]==tar) return true;
		if(nums[i][j]>tar) e = m;
		else b=m+1;
	}
	return false;
}

/*
Write an efficient algorithm that searches for a value in an m x n matrix. This matrix has the following properties:
Integers in each row are sorted in ascending from left to right.
Integers in each column are sorted in ascending from top to bottom.
*/
bool searchMatrix(vector<vector<int>>& matrix, int target) {
	const int M = matrix.size();
	if (M == 0) return false;
	const int N = matrix[0].size();
	int i = 0, j = N-1;
	while (i!=M && j>=0) {
		if (matrix[i][j] == target) return true;
		else if (matrix[i][j] > target) --j;
		else ++i;
	}
	return false;
}
