/**
 * @file p3.cc
 * @author Nick
 * @brief Triplet sum with duplicates
 * @version 0.1
 * @date 2022-05-27
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>
#include <unordered_set>
#include <algorithm>

using namespace std;

void display_set(unordered_set<int> s) {
	for(auto const &elem : s) {
		cout << elem << " ";
	}
	cout << endl;
}

void display(vector<vector<int>> result) {
	int n_result = result.size();
	cout << "{";
	for(int i = 0; i < n_result; i++){
		int n_single_res = result[i].size();
		cout << "{";
		for(int j = 0; j < n_single_res; j++){
			cout << result[i][j];
			if(j != n_single_res - 1) cout << ", ";
		}
		cout << "}";
	}
	cout << "}" << endl;
}


vector<vector<int>> threeSum_Sol1(vector<int>& nums) { // Very large array fails - time limit exceeded
	vector<vector<int>> result;
	
	int n = nums.size();
	if(n < 3) return result;
	if(n == 3){
		if(nums[0] + nums[1] + nums[2] == 0){
			vector<int> res = nums;
			result.push_back(res);
		}
		return result;
	}

	sort(nums.begin(), nums.end());
	for(int i = 0; i < n; i++) {

		unordered_set<int> num_map;
		for(int  j = i + 1; j < n; j++) {
			int sum = nums[i] + nums[j];
			if(num_map.find(-sum) != num_map.end()){
				int min_val = min(min(nums[i], nums[j]), -sum);
				int max_val = max(max(nums[i], nums[j]), -sum);
				int mid_val = nums[i] + nums[j] + -sum - min_val - max_val;
				vector<int> single_sol = {min_val, mid_val, max_val};
				result.push_back(single_sol);
			} else {
				num_map.insert(nums[j]);
			}
		}
	}
	sort(result.begin(), result.end());
	result.erase(unique(result.begin(), result.end()), result.end());

	return result;
}

vector<vector<int>> threeSum_Sol2(vector<int>& nums) { // Skip duplicates from start and end after sorting for each pivot selected
	// Time: O(N^2), where N is the number of elements in the array
	// Space: O(1)
	vector<vector<int>> result;
	sort(nums.begin(), nums.end());

	int n = nums.size();
	for(int pivot = 0; pivot < n; pivot++){
		int start = pivot + 1;
		if(pivot > 0 && (nums[pivot] == nums[pivot - 1])) // Skip duplicates from pivot
			continue;

		int end = n - 1;
		int curval = -nums[pivot];
		while(start < end){
			if((end < n - 1) && (nums[end] == nums[end + 1])){ // Skip duplicates from end
				end--;
				continue;
			}
			int sum = nums[start] + nums[end];
			if(curval > sum){
				start++;
			} else if (curval < sum){
				end--;
			} else {
				int min_val = min(min(nums[start], nums[end]), -curval);
				int max_val = max(max(nums[start], nums[end]), -curval);
				int mid_val = nums[end] + nums[start] + -curval - min_val - max_val;
				vector<int> single_sol = {min_val, mid_val, max_val};
				result.push_back(single_sol);
				start++;
				end--;
			}
		}
	}
	return result;
}

int main() {

	vector<int> c1 = {1, 2, -3};
	display(threeSum_Sol1(c1));
	display(threeSum_Sol2(c1));

	vector<int> c2 = {1, 2, -3, 4, -1};
	display(threeSum_Sol1(c2));
	display(threeSum_Sol2(c2));

	vector<int> c3 = {-1,0,1,2,-1,-4};
	display(threeSum_Sol1(c3));
	display(threeSum_Sol2(c3));

	vector<int> c4 = {0,0,0,0};
	display(threeSum_Sol1(c4));
	display(threeSum_Sol2(c4));

	vector<int> c5 = {-1,1,0};
	display(threeSum_Sol1(c5));
	display(threeSum_Sol2(c5));

	vector<int> c6 = {1,2,-2,-1};
	display(threeSum_Sol1(c6));
	display(threeSum_Sol2(c6));

	vector<int> c7 = {-2,0,1,1,2};
	display(threeSum_Sol1(c7));
	display(threeSum_Sol2(c7));
	
	return 0;
}