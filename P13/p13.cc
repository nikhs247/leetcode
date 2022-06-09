#include <iostream>
#include <string>

using namespace std;

int removePalindromeSub(string s) {
	// Time: O(n), n is the string length
	// Space: O(1)
    int i = 0, j = s.length() - 1;
	while(i <= j){
		if(s[i] != s[j]) return 2;
		i++;
		j--;
	}
	return 1;
}

int main(int argc, char *argv[]){
	string s(argv[1]);
	cout << removePalindromeSub(s) << endl;
	return 0;
}