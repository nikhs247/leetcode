#include <iostream>
#include <vector>

using namespace std;

int binSearch(vector<int> &nums, int low, int high, int query){
	// Time: O(log n), n is the number of elements
	// Space: O(1)
	if(high >= low){
		int mid = low + (high - low) / 2;

		if(nums[mid] == query) return mid;

		if(nums[mid] > query){
			if(mid == low) return low;
			if(nums[mid - 1] < query) return mid;
			return binSearch(nums, low , mid - 1, query);	
		}

		if(mid == high) return high + 1;
		if(nums[mid + 1] > query) return mid + 1;
		return binSearch(nums, mid + 1, high, query);
	}

	return -1;
}

int searchInsert(vector<int>& nums, int target) {
	int n = nums.size() - 1;
    return binSearch(nums, 0, n, target);
}

int main(int arc, char *argv[]) {
	vector<int> c = {1, 3, 5, 6};
	int target = 5;
	cout << searchInsert(c, target) << endl;
	target = 2;
	cout << searchInsert(c, target) << endl;
	target = 4;
	cout << searchInsert(c, target) << endl;
	target = 7;
	cout << searchInsert(c, target) << endl;
	c = {1};
	target = 0;
	cout << searchInsert(c, target) << endl;
	target = 2;
	cout << searchInsert(c, target) << endl;

	return 0;
}