#include <iostream>
#include <string>
#include <vector>

using namespace std;

int strStr(string haystack, string needle) {
	// Time: O(haystack length)
	// Space: O(1)
	if(needle.length() == 0) return 0;
	int hlen = haystack.length(), nlen = needle.length();
	int i = 0, j = 0;
	int next_first_char_loc = -1;
	int start = 0;
	while(i < hlen && j < nlen) {
		if(haystack[i]!= needle[j]){
			if(haystack[i] == needle[0] && next_first_char_loc == -1){
				start = i;
			}
			else if(next_first_char_loc != -1){
				start = next_first_char_loc;
				i = start;
				next_first_char_loc = -1;
			} else{
				start = ++i;
			}
			j = 0;
			continue;
		}
		if(haystack[i] == needle[0] && j != 0 && next_first_char_loc == -1){
			next_first_char_loc = i;
		}
		i++;
		j++;
		if(j == nlen) return start;
	}
	return -1;
}

int main(int argc, char *argv[]){
	cout << strStr(string(argv[1]), string(argv[2])) << endl;
	return 0;
}