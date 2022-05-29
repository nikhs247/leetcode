#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include <bitset>

#define ALPHBT 20

using namespace std;

bool haveSameAlpha(bitset<ALPHBT> b1, bitset<ALPHBT> b2){
	for(int i = 0; i < ALPHBT; i++){
		if((b1[i] && b2[i]) == 1) return true;
	}
	return false;
}
int maxProduct(vector<string>& words) { // Use bitset to reduce memory usage for comparison
	// Time: O(N * N), where N is the number of words
	// Space: O(N)
	vector<bitset<ALPHBT>> bitword(words.size());
	int maxpdt = 0;
	for(int i = 0; i < words.size(); i++){
		for(int j = 0; j < words[i].length(); j++){
			char ch = words[i][j];
			bitword[i][ch - 'a'] = 1;
		}
		for(int j = 0; j < i; j++){
			if(!haveSameAlpha(bitword[i], bitword[j])){
				maxpdt = max(maxpdt, (int)words[i].length() * (int)words[j].length());
			}
		}
	}

	return maxpdt;
}

int main() {
	vector<string> c1 = {"abcw","baz","foo","bar","xtfn","abcdef"};
	cout << "C1: " << maxProduct(c1) << endl;

	vector<string> c2 = {"a", "aa", "aaa"};
	cout << "C2: " << maxProduct(c2) << endl;

	return 0;
}