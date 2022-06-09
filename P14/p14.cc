#include <iostream>
#include <vector>
#include <map>

using namespace std;

vector<int> twoSum_1(vector<int>& numbers, int target) {
	// Time: O(n), n is the number of elements
	// Space: O(n), space for map
	map<int, int> numidx_map;
	int n = numbers.size();
	for(int i = 0; i < n; i++)
		numidx_map[numbers[i]] = i + 1;
	vector<int> result;
	for(auto map_item: numidx_map){
		if(numidx_map.count(target - map_item.first) == 1){
			result.push_back(map_item.second);
			result.push_back(numidx_map[target - map_item.first]);
			break;
		}
	}
	return result;
}

int binSearch(vector<int> &nums, int low, int high, int query){
	if(high >= low){
		int mid = low + (high - low) / 2;

		if(nums[mid] == query) return mid;

		if(nums[mid] > query) return binSearch(nums, low, mid - 1, query);

		return binSearch(nums, mid + 1, high, query);
	}

	return -1;
}
vector<int> twoSum_2(vector<int>& numbers, int target) {
	// Time: O(nlogn), n is the number of elements
	// Space : O(1)
	int n = numbers.size();
	vector<int> result;
	for(int i = 0; i < n; i++){
		int lookup_idx = binSearch(numbers, i + 1, n -1, target - numbers[i]);
		if(lookup_idx != -1){
			result.push_back(i + 1);
			result.push_back(lookup_idx + 1);
		}
	}
	return result;
}

vector<int> twoSum_2(vector<int>& numbers, int target){
	// Time: O(n), n is the number of elements
	// Space: O(1)
	int i = 0, j = numbers.size() - 1;
	vector<int> result;
	while(i  < j) {
		int sum = numbers[i] + numbers[j];
		if(sum > target) j--;
		else if(sum < target) i++;
		else{
			result.push_back(i + 1);
			result.push_back(j + 1);
			return result;
		}
	}
	return result;
}


void display(vector<int> &res){
	if(res.size() > 0)
		cout << res[0] << " " << res[1] << endl;
	else
		cout << "" << endl;
}

int main(int argc, char *argv[]){
	vector<int> c1 = {2, 7, 11, 15};
	int t1 = 9;
	vector<int> res1 = twoSum_1(c1, t1);
	display(res1);
	return 0;
}