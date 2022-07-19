#include <iostream>
#include <vector>

using namespace std;

vector<vector<int>> generate(int numRows) {
	// Time : O(n2), n = numRows 
	// Space: O(n2)
	vector<vector<int>> res;
	if(numRows == 1){
		vector<int> r = {1};
		res.push_back(r);
	} else if(numRows == 2){
		vector<int> r1 = {1};
		res.push_back(r1);
		vector<int> r2 = {1, 1};
		res.push_back(r2);
	} else{
		vector<int> r1 = {1};
		res.push_back(r1);
		vector<int> r2 = {1, 1};
		res.push_back(r2);
		
		for(int i = 2; i < numRows; i++){
			vector<int> r = {1};
			for(int j = 1; j < i; j++){
				int val = res[i - 1][j] + res[i - 1][j - 1];
				r.push_back(val);
			}
			r.push_back(1);
			res.push_back(r);
		}
	}
	return res;
}

void display(vector<vector<int>> &res){
	cout << "[ ";
	for(auto row: res){
		cout << "[ ";
		for(auto val: row)
			cout << val << " ";
		cout << " ]";
	}
	cout << " ]" << endl;;
}
int main(int argc, char *argv[]){
	int numRows = stoi(string(argv[1]));
	vector<vector<int>> res = generate(numRows);
	display(res);
	return 0;
}