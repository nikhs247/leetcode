#include <iostream>
#include <vector>
#include <queue>
#include <unistd.h>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};

void display(vector<vector<int>> &res){
	int n = res.size();
	for(auto level: res){
		for (auto elem: level)
			cout << elem << " ";
		cout << endl;
	}
}

void inorderTraversal(queue<vector<TreeNode*>> &levelorder_queue, vector<vector<int>> &result){
	if(levelorder_queue.size() == 0) return;
	vector<TreeNode*> level = levelorder_queue.front();
	vector<int> level_result;
	vector<TreeNode*> level_node;
	for(int i = 0; i < level.size(); i++){
		TreeNode *node = level.at(i);
		level_result.push_back(node->val);
		if(node ->left)
			level_node.push_back(node->left);
		if(node ->right)
			level_node.push_back(node->right);
	}
	result.push_back(level_result);
	levelorder_queue.pop();
	if(level_node.size() != 0)
		levelorder_queue.push(level_node);
	inorderTraversal(levelorder_queue, result);
}
vector<vector<int>> levelOrder(TreeNode* root) {
	// Time: O(n), n is the number of elements in the tree
	// Space: O(n), to store result
	queue<vector<TreeNode*>> levelorder_queue;
	vector<vector<int>> result;
	vector<TreeNode*> root_level;
	root_level.push_back(root);
	levelorder_queue.push(root_level);
	inorderTraversal(levelorder_queue, result);
	display(result);
	return result;
}

int main(int argc, char *argv[]){
	TreeNode *root = new TreeNode(3);
	root-> left = new TreeNode(9);
	root->right = new TreeNode(20, new TreeNode(15), new TreeNode(7));
	
	auto res = levelOrder(root);

	return 0;
}