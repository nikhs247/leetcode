#include <iostream>
#include <algorithm>
#include <vector>

using namespace std;

bool isValidSquare(vector<int> &matchsticks, vector<int> &buckets, int index, int maxSide){
	if(index == -1) return true;

	for(int i = 0; i < 4; i++){
		// second condition implies the index is already at max value possible with given elements
		if((buckets[i] + matchsticks[index] > maxSide) || (i > 0 && buckets[i] == buckets[i - 1]))
			continue;
		
		buckets[i] += matchsticks[index];

		if(isValidSquare(matchsticks, buckets, index - 1, maxSide)) return true;
		
		buckets[i] -= matchsticks[index];
	}
	return false;
}
bool makesquare(vector<int>& matchsticks) {
	if(matchsticks.size() < 4) return false;
	
	// sum should be multiple of 4
	int sum = 0;
	for(int i = 0; i < matchsticks.size(); i++)
		sum += matchsticks[i];
	if(sum % 4 != 0) return false;

	sort(matchsticks.begin(), matchsticks.end());
	
	std::vector<int> buckets(4, 0);
	int index = matchsticks.size();
	int maxSide = sum / 4;
	return isValidSquare(matchsticks, buckets, index - 1, maxSide);
}

int main(int argc, char *argv[]){
	// vector<int> matchsticks = {1,1,2,2,2};
	vector<int> matchsticks = {3, 3, 3, 3, 4};
	// vector<int> matchsticks = {1, 1, 2, 2, 2, 2, 3, 3, 4};
	cout << makesquare(matchsticks) << endl;
	return 0;
}