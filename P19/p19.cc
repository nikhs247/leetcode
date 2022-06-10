#include <iostream>
#include <vector>

using namespace std;

int removeElement(vector<int>& nums, int val) {
	// Time = O(n), n is the number of elements
	// Space: O(1)
	int n_req = 0;
	int n = nums.size();
	for(int i = 0; i < n; i++){
		if(nums[i] != val)
			nums[n_req++] = nums[i];
	}
	return n_req;
}

int main(int argc, char *argv[]){
	vector<int> c1 = {0,1,2,2,3,0,4,2};
	int val = 2;
	cout << removeElement(c1, val) << endl;
	return 0;
}