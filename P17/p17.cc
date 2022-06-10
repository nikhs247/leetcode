#include <iostream>
#include <string>
#include <map>

using namespace std;

int lengthOfLongestSubstring(string s) {
	// Time: O(n), n is the string length
	// Space: O(n)
	int len = s.length();
	if(len <= 1) return len;
	int start = 0, end = 0;
	map<char, int> visited_char;
	int max_len = -1;
	int cur_substr_len;
	for(int i = 0; i < len; i++){
		if(visited_char.count(s[i])){
			cur_substr_len = end - start + 1;
			if(cur_substr_len > max_len)
				max_len = cur_substr_len;
			int prev_pos = visited_char[s[i]];
			for(int j = start; j < prev_pos; j++)
				visited_char.erase(s[j]);
			visited_char[s[i]] = i;
			start = prev_pos + 1;
		} else {
			visited_char[s[i]] = i;
		}
		end = i;
		cur_substr_len = end - start + 1;
	}
	if(cur_substr_len > max_len)
		max_len = cur_substr_len;

	return max_len;
}
int main(int argc, char *argv[]){
	cout << lengthOfLongestSubstring(string(argv[1])) << endl;
	return 0;
}