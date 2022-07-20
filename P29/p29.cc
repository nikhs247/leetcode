#include <iostream>
#include <string>

using namespace std;

void sumBin(char a, char b, char &res, char &carry){
	if(a == '1' && b == '1' && carry == '0'){
		res = '0';
		carry = '1';
	}else if(a == '1' && b == '1' && carry == '1'){
		res = '1';
		carry = '1';
	}else if((a == '1' && b == '0' && carry == '0') || (a == '0' && b == '1' && carry == '0')){
		res = '1';
		carry = '0';
	}else if((a == '1' && b == '0' && carry == '1') || (a == '0' && b == '1' && carry == '1')){
		res = '0';
		carry = '1';
	}else if(a == '0' && b == '0' && carry == '0'){
		res = '0';
		carry = '0';
	}else if(a == '0' && b == '0' && carry == '1'){
		res = '1';
		carry = '0';
	}
	
}
string addBinary(string a, string b) {
	// Time: O(max(len(a), len(b)))
	// Space: O(len(result))

	int len_a = a.length(), len_b = b.length();
	int i = len_a - 1, j = len_b - 1, k = max(len_a, len_b);
	char carry = '0', res;
	string result(max(len_a, len_b) + 1, '0');
	while(i >= 0 && j >= 0){
		sumBin(a[i], b[j], res, carry);
		result[k] = res;
		i--;
		j--;
		k--;
	}
	while(i>=0){
		sumBin(a[i], '0', res, carry);
		result[k] = res;
		i--;
		k--;
	}
	while(j>=0){
		sumBin('0', b[j], res, carry);
		result[k] = res;
		j--;
		k--;
	}
	result[0] = carry;
	if(result[0] == '0')
		result.erase(0, 1);
	return result;
}

int main(int argc, char *argv[]){
	string t1_a = "11", t1_b = "1";
	cout << addBinary(t1_a, t1_b) << endl;

	string t2_a = "1010", t2_b = "1011";
	cout << addBinary(t2_a, t2_b) << endl;

	return 0;
}