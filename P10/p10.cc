#include <iostream>
#include <string>
#include <stack>

using namespace std;

bool isValid(string s){
	stack<char> parstack;
	int len = s.length();
	for(int i = 0; i < len; i++){
		char ch = s[i];
		if(parstack.empty())
			parstack.push(ch);
		else{
			char top = parstack.top();
			bool popped = false;
			switch(top){
				case '(': 	if(ch == ')'){
								parstack.pop();
								popped = true;
							}
							break;
				case '{': 	if(ch == '}'){
								parstack.pop();
								popped = true;
							}
							break;
				case '[': 	if(ch == ']'){
								parstack.pop();
								popped = true;
							}
							break;
				default: 	parstack.push(ch);
			}
			if(!popped)
				parstack.push(ch);
		}
	}
	if(parstack.empty())
		return true;
	return false;
}

int main(){
	cout << isValid("()") << endl;
	cout << isValid("({[") << endl;
	cout << isValid("({[]})") << endl;
	return 0;
}