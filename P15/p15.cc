#include <iostream>
#include <vector>

using namespace std;

int removeDuplicates(vector<int>& nums) {
	// Time = O(n), n is the numbr of elements
	// Space: O(1)
	int req_idx = 0;
	int n = nums.size();
	for(int i = 0; i < n; i++){
		if(nums[i] != nums[req_idx]){
			nums[req_idx + 1] = nums[i];
			req_idx++;
		}
	}
	return req_idx + 1;
}

int main(int argc, char *argv[]){
	vector<int> c1 = {1, 1, 2};
	cout << removeDuplicates(c1) << endl;
	c1 = {0,0,1,1,1,2,2,3,3,4};
	cout << removeDuplicates(c1) << endl;
	return 0;
}