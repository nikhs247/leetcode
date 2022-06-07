#include <iostream>
#include <vector>

using namespace std;

void merge1(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	// Time: O( m + n), m+n total number of elements
	// Space: O(m + n), for temporary array
	vector<int> res;
	int i = 0, j = 0;
	while(i < m && j < n) {
		if(nums1[i] < nums2[j])
			res.push_back(nums1[i++]);
		else
			res.push_back(nums2[j++]);
	}
	while(i < m) res.push_back(nums1[i++]);
	while(j < n) res.push_back(nums2[j++]);
	
	for(int k = 0; k < m + n; k++)
		nums1[k] = res[k];
}

void merge2(vector<int>& nums1, int m, vector<int>& nums2, int n) {
	// Time: O( m + n), m+n total number of elements
	// Space: O(1)
	int i = m - 1, j = n - 1, k = m + n - 1;

	while(i >= 0 && j >= 0) {
		if(nums1[i] > nums2[j])
			nums1[k--] = nums1[i--];
		else
			nums1[k--] = nums2[j--];
	}
	while(i >= 0) nums1[k--] = nums1[i--];
	while(j >= 0) nums1[k--] = nums2[j--];
}


void display(vector<int> nums, int sz){
	for(int i = 0; i < sz; i++)
		cout << nums[i] << " ";
	cout << endl;
}

int main(){
	// vector<int> nums1 = {1,2,3,0,0,0}, nums2 = {2,5,6};
	// int m = 3, n = 3;
	vector<int> nums1 = {1}, nums2 = {};
	int m = 1, n = 0;
	merge2(nums1, m, nums2, n);
	display(nums1, m + n);
	return 0;
}