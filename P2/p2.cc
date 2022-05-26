/**
 * @file p2.cc
 * @author Nick
 * @brief Vertical scanning and divide-conquer method for longest common prefix
 * @version 0.1
 * @date 2022-05-26
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <string>
#include <vector>

/**
 * @brief Vertical scanning
 * 
 * @param strs 
 * @return std::string 
 */
std::string longestCommonPrefix_Sol1(std::vector<std::string>& strs) {
	// Time: O(Total number of characters in all strings)
	// Space: O(1)
	int n_strs = strs.size();
	for(int i = 0; i < strs[0].length(); i++){
		for(int j = 1; j < n_strs; j++){
			if(strs[j][i] != strs[0][i] || i == strs[j].length())
				return strs[0].substr(0, i);
		}
	}
	return "";
}


std::string common_prefix(std::string str1, std::string str2){
	int l1 = str1.length(), l2 = str2.length();
	std::string prefix = "";
	for(int i = 0, j = 0; (i < l1) && (j < l2); i++, j++){
		if(str1[i] != str2[j])
			break;
		prefix.push_back(str1[i]);
	}
	return prefix;
}

std::string lcpdc(std::vector<std::string>& strs, int low, int high) {
	if(low == high)
		return strs[low];
	if(low < high){
		int mid = low + (high - low) / 2;
		std::string str1 = lcpdc(strs, low, mid);
		std::string str2 = lcpdc(strs, mid + 1, high);

		return common_prefix(str1, str2); 
	}
	return "";
}

/**
 * @brief Divide and conquer
 * 
 * @param strs 
 * @return std::string 
 */
std::string longestCommonPrefix_Sol2(std::vector<std::string>& strs) {
	// Time: O(Total number of characters in all strings)
	// Space: O(M log N), log N recursize calls, with space M for storing strings
	int low = 0, high = strs.size() - 1;
	return lcpdc(strs, low, high);
}

int main(){
	std::vector<std::string> c1 = {"flower","flow","flight"};
	std::cout << "C1_Sol1: " << longestCommonPrefix_Sol1(c1) << std::endl;
	std::cout << "C1_Sol2: " << longestCommonPrefix_Sol2(c1) << std::endl;
	std::cout <<std::endl;

	std::vector<std::string> c2 = {"flower","water","soil"};
	std::cout << "C2_Sol1: " << longestCommonPrefix_Sol1(c2) << std::endl;
	std::cout << "C2_Sol2: " << longestCommonPrefix_Sol2(c2) << std::endl;
	std::cout <<std::endl;

	std::vector<std::string> c3 = {"flower","","soil"};
	std::cout << "C3_Sol1: " << longestCommonPrefix_Sol1(c3) << std::endl;
	std::cout << "C3_Sol2: " << longestCommonPrefix_Sol2(c3) << std::endl;
	std::cout <<std::endl;

	std::vector<std::string> c4 = {"","",""};
	std::cout << "C4_Sol1: " << longestCommonPrefix_Sol1(c4) << std::endl;
	std::cout << "C4_Sol2: " << longestCommonPrefix_Sol2(c4) << std::endl;
	std::cout <<std::endl;

	return 0;
}