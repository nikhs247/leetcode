#include <iostream>
#include <vector>
#include <map>

using namespace std;

bool isAnagram(string s, string t) {
	// Time: O(max(s.len, t.len))
	// Space: O(26), constant
	map<char, int> map_s;
	int s_len = s.length();
	for(int i = 0; i < s_len; i++){
		if(map_s.count(s[i]) == 0){
			map_s[s[i]] = 1;
		} else {
			map_s[s[i]]++;
		}
	}

	int t_len = t.length();
	for(int i = 0; i < t_len; i++){
		if(map_s.count(t[i]) == 0)
			return false;
		map_s[t[i]]--;
	}
	for(auto kv : map_s){
		if(kv.second > 0)
			return false;
	}
	return true;
}
int main(int argc, char *argv[]){

	cout << isAnagram("b", "b") << endl;
	return 0;
}