#include <iostream>
#include <string>
#include <cmath>

using namespace std;

int myAtoi(string s) {
	// Time: O(s.len)
	// Space: constant
	long max_val = pow(2, 31) - 1;
	long min_val = -pow(2, 31);
	
	int s_len = s.length();
	long sum = 0;
	bool encountered_white_space = false;
	bool explicit_sign_assign = false;
	bool sum_change = false;
	int sign = 1;
	
	for(int i = 0; i < s_len; i++){
		if(explicit_sign_assign){
			if(s[i] < '0' || s[i] > '9')
				break;
		}
		if(s[i] == ' '){
			if(encountered_white_space || sum_change){
				sum = sign * sum;
				if(sum > max_val)
					sum = max_val;
				if(sum < min_val)
					sum = min_val;
				return sum;
			} else{
				while(s[i] == ' ' && i < s_len){
					i++;
				}
				i--;
				encountered_white_space = true;
			}
		} else if(s[i] == '+'){
			if(explicit_sign_assign || sum_change) break;
			sign = 1;
			explicit_sign_assign = true;
		} else if(s[i] == '-'){
			if(explicit_sign_assign || sum_change) break;
			sign = -1;
			explicit_sign_assign = true;
		}
		else{
			if(s[i] < '0' || s[i] > '9')
				break;
			sum = sum * 10 + (s[i] - '0');
			sum_change = true;
			if(sum * sign > max_val){
				return max_val;
			}
			if(sum * sign < min_val){
				return min_val;
			}
		}
	}
	return sum * sign;
}

int main(int argc, char *argv[]){
	/*
	"42"
"   -42"
	"4193 with words"
	"12."
	"+12"
	"+-12"
	"12+-"
	".12"
	"00000-42a1234"
	"0  123"
	*/
	cout << myAtoi("0  123") << endl;
	return 0;
}