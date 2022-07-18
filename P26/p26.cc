#include <iostream>
#include <string>

using namespace std;

int lengthOfLastWord(string s) {
	// Time: O(s.length)
	// Space: O(1)
	int str_len = s.length();
	int max_str_len = 0;
	for (int i = str_len - 1; i >=0; i--){
		if(i == str_len - 1){
			while(i >= 0 && s[i] == ' ') i--;
			if(i < 0){
				return 0;
			}
		}
		if(s[i] == ' ') return max_str_len;
		max_str_len++;
	}
	return max_str_len;
}

int main(int argc, char *argv[]){
	string t1 = "Hello World";
	cout << t1 << ": " << lengthOfLastWord(t1) << endl;
	string t2 = "   fly me   to   the moon  ";
	cout << t2 << ": " << lengthOfLastWord(t2) << endl;
	string t3 = "luffy is still joyboy";
	cout << t3 << ": " << lengthOfLastWord(t3) << endl;
	string t4 = "s ";
	cout << t4 << ": " << lengthOfLastWord(t4) << endl;
	return 0;
}