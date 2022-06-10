#include <iostream>
#include <string>
#include <map>

using namespace std;

int romanToInt(string s) {
	// Time: O(n), n is the string length
	// Space: O(1)
    map<char, int> r2i = {
		{'I', 1},
		{'V', 5},
		{'X', 10},
		{'L', 50},
		{'C', 100},
		{'D', 500},
		{'M', 1000}
	};

	int len = s.length();
	int value = 0;
	for(int i = 0; i < len; i++){
		char ch = s[i];
		switch(ch){
			case 'I':	if(i + 1 < len){
							if(s[i+1] == 'V'){
								value += 4;
								i++;
							}else if(s[i+1] == 'X'){
								value += 9;
								i++;
							} else value++;
						} else value++;
						break;
			case 'X':	if(i + 1 < len){
							if(s[i+1] == 'L'){
								value += 40;
								i++;
							}else if(s[i+1] == 'C'){
								value += 90;
								i++;
							} else value += 10;
						} else value += 10;
						break;
			case 'C':	if(i + 1 < len){
							if(s[i+1] == 'D'){
								value += 400;
								i++;
							}else if(s[i+1] == 'M'){
								value += 900;
								i++;
							} else value += 100;
						} else value += 100;
						break;
			default: value += r2i[s[i]];
		}
	}
	return value;
}

int main(int argc, char *argv[]){
	cout << romanToInt("III") << endl;
	cout << romanToInt("LVIII") << endl;
	cout << romanToInt("MCMXCIV") << endl;
	return 0;
}