#include <iostream>
#include <vector>

using namespace std;

vector<int> plusOne(vector<int>& digits) {
	// Time: O(n), n = digits.size()
	// Space: O(n + 1)
	int n_digits = digits.size();
	vector<int> res(n_digits + 1, 0);
	int carry = 0;
	int sum, val;
	for(int i = n_digits - 1, j = n_digits; i >= 0; i--, j--){
		if(i == n_digits - 1)
			sum = digits[i] + 1 + carry;
		else
			sum = digits[i] + carry;
		res[j] = sum % 10;
		carry = sum / 10;
	}
	if(carry != 0)
		res[0] = carry;
	if(res[0] == 0)
		res.erase(res.begin());
	return res;
}

int main(int argc, char *argv[]){
	// vector<int> input = {1, 2, 3};
	vector<int> input = {9};
	vector<int> res = plusOne(input);
	for(auto val : res)
		cout << val << " ";
	cout << endl;
	return 0;
}