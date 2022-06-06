#include <iostream>
#include <vector>
#include <map>
#include <stack>

using namespace std;

bool isPosSafe(vector<vector<bool>> &board, int row, int col){
	int n = board[0].size();
	// check for column
	for(int i = row - 1; i >= 0; i--)
		if(board[i][col])
			return false;

	// check for left diagonal
	for(int i = row, j = col; i >= 0 && j >= 0; i--, j--)
		if(board[i][j])
			return false;

	// check for right diagonal
	for(int i = row, j = col; i >= 0 && j < n; i--, j++)
		if(board[i][j])
			return false;

	return true;
}

bool findNQSol(vector<vector<string>> &result, vector<vector<bool>> &board, int row){
	int n = board[0].size();
	if(row >= n){
		vector<string> sol;
		for(int i = 0; i < n; i++){
			string rowstr = "";
			for(int j = 0; j < n; j++){
				if(board[i][j])
					rowstr += "Q";
				else
					rowstr += ".";
			}
			sol.push_back(rowstr);
		}
		result.push_back(sol);
		return true;
	}
	bool res = false;
	for(int i = 0; i < n; i++){
		if(isPosSafe(board, row, i)){
			board[row][i] = true;
			res = findNQSol(result, board, row + 1) || res;
			board[row][i] = false;
		}
	}
	return res;
}

vector<vector<string>> nqueens(int n) {
	// Time: O(n*n), n queens
	// Space: O(n*n), size of board
	vector<vector<string>> result;
	vector<vector<bool>> board;
	for(int i = 0; i < n; i++){
		vector<bool> row;
		for(int j = 0; j < n; j++){
			row.push_back(false);
		}
		board.push_back(row);
	}

	findNQSol(result, board, 0);
	return result;
}

int main(int argc, char *argv[]){
	int n = stoi(argv[1]);
	vector<vector<string>> result = nqueens(n);
	for(int i = 0; i < result.size(); i++){
		for(int j = 0; j < result[i].size(); j++)
			cout << result[i][j] << " ";
		cout << endl;
	}
	return 0;
}