#include <iostream>
#include <map>
#include <vector>
#include <string>
#include <algorithm>

#define ALPHACNT 26
using namespace std;

int minDeletions_1(string s) {
	map<char, int> char_occur;
	int str_len = s.length();
	for(int i = 0; i < str_len; i++){
		if(char_occur.count(s[i]) > 0)
			char_occur[s[i]]++;
		else
			char_occur[s[i]] = 1;
	}
	
	map<int, bool> val_map;
	int n_del = 0;
	for(auto char_val: char_occur){
		int val = char_val.second;
		while(val > 0){
			if(val_map.count(val) > 0){
				val--;
				n_del++;
			} else {
				val_map[val] = true;
				break;
			}    
		}
	}
	return n_del;
}

int minDeletions_2(string s){
	vector<int> alpha(ALPHACNT, 0);

	int str_len = s.length();
	for(int i = 0; i < str_len; i++){
		alpha[s[i] - 'a']++;
	}

	sort(alpha.begin(), alpha.end());

	int n_del = 0;
	for(int i = ALPHACNT - 2; i >= 0; i--){
		if(alpha[i] == 0) break;

		if(alpha[i] >= alpha[i + 1]){
			int old_val = alpha[i];
			int new_val = alpha[i + 1] - 1;
			alpha[i] = max(0, new_val); // multiple letters may appear only once
			n_del += old_val - alpha[i];
		}
	}

	return n_del;
}

int main(int argc, char *argv[]){
	// cccbba
	// cccnnna
	// cccabd
	string s(argv[1]);
	cout << minDeletions_2(s) << endl;
	return 0;
}