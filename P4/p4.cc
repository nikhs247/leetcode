/**
 * @file p4.cc
 * @author Nick
 * @brief Phone number letter combinations
 * @version 0.1
 * @date 2022-05-28
 * 
 * @copyright Copyright (c) 2022
 * 
 */
#include <iostream>
#include <vector>
#include <map>
#include <stack>
#include <string>

using namespace std;

vector<string> letterCombinations(string digits) {
	// Time:O(Product of number of letters per digit)
	// Space: O(Product of number of letters per digit) - used for stacks
	map<char, vector<char>> d2c = 	{
										{'2', {'a', 'b', 'c'}},
										{'3', {'d', 'e', 'f'}},
										{'4', {'g', 'h', 'i'}},
										{'5', {'j', 'k', 'l'}},
										{'6', {'m', 'n', 'o'}},
										{'7', {'p', 'q', 'r', 's'}},
										{'8', {'t', 'u', 'v'}},
										{'9', {'w', 'x', 'y', 'z'}}
									};
	stack<string> st1;
	stack<string> st2;
	vector<char> d1 = d2c[digits[0]];
	for(int i = 0; i < d1.size(); i++){
		string s;
		s = d1[i];
		st1.push(s);
	}

	stack<string> *first_stack;
	stack<string> *second_stack;
	for(int i = 1; i < digits.length(); i++){
		if(i % 2 == 0){
			first_stack = &st2;
			second_stack = &st1;
		} else {
			first_stack = &st1;
			second_stack = &st2;
		}
		while(!first_stack->empty()){
			vector<char> d = d2c[digits[i]];
			for(int j = 0; j < d.size(); j++){
				string s_pop = first_stack->top();
				string s;
				s = d[j];
				s_pop += s;
				second_stack->push(s_pop);
			}
			first_stack->pop();
		}
	}

	vector<string> result;
	stack<string> *end_stack;
	if(st1.empty())
		end_stack = &st2;
	else
		end_stack = &st1;
	while(!end_stack->empty()){
		result.push_back(end_stack->top());
		end_stack->pop();
	}

	return result;
}

void display(vector<string> res){
	for(auto comb : res){
		cout << "\'" << comb << "' ";
	}
	cout << endl;
}

int main(){

	string c1 = "23";
	vector<string> res = letterCombinations(c1);
	display(res);

	string c2 = "";
	res = letterCombinations(c2);
	display(res);

	return 0;
}