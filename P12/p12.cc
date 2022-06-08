#include <iostream>
#include <string>
#include <vector>
#include <algorithm>

using namespace std;

int lps(string r, string s, int lr, int ls, vector<vector<int>> &dp) {

	if(lr == 0 || ls == 0) return 0;

	// already calculated lps
	if(dp[lr][ls] != -1) return dp[lr][ls];

	// shift by one character in both strings
	if(r[lr - 1] == s[ls - 1]) return dp[lr][ls] = lps(r, s, lr - 1, ls - 1, dp) + 1;

	// find lps in two branches
	return dp[lr][ls] = max(lps(r, s, lr - 1, ls, dp), lps(r, s, lr, ls - 1, dp));
}
int longestPalindromeSubseq(string s){
	int len = s.length();
	vector<vector<int>> dp(len + 1, vector<int>(len + 1, -1));
	string r = s;
	reverse(r.begin(), r.end());
	return lps(r, s, len, len, dp);
}
int main(){
	cout << longestPalindromeSubseq("bbbab") << endl;
	return 0;
}