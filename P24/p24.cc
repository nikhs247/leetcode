#include <iostream>
#include <vector>

using namespace std;

struct TreeNode {
	int val;
	TreeNode *left;
	TreeNode *right;
	TreeNode() : val(0), left(nullptr), right(nullptr) {}
	TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
	TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
};
void inorderTraversal(TreeNode *root){
	if(root == nullptr) {
		cout << "null " ;
		return;
	}

	cout << root-> val  << " ";
	inorderTraversal(root->left);
	inorderTraversal(root->right);
}
TreeNode* constructTree(vector<int> &preorder, int &pindex, vector<int> &inorder, int instart, int inend){
	// Time: O(n), n is the number of elements in the tree
	// Space: O(1), other than tree construction
	if (instart > inend) return nullptr;

	TreeNode *new_node = new TreeNode(preorder[pindex++]);

	if(instart == inend) return new_node;

	int new_in_idx = 0;
	for(int i = instart; i <= inend; i++){
		if(inorder[i] == new_node ->val)
			new_in_idx = i;
	}

	new_node->left = constructTree(preorder, pindex, inorder, instart, new_in_idx - 1);
	new_node->right = constructTree(preorder, pindex, inorder, new_in_idx + 1, inend);

	return new_node;
}

TreeNode* buildTree(vector<int>& preorder, vector<int>& inorder) {
	int pindex = 0;
	int n = preorder.size();
	return constructTree(preorder, pindex, inorder, 0, n - 1);
}

int main(int argc, char *argv[]){
	// vector<int> preorder = {3,9,20,15,7};
	// vector<int> inorder = {9,3,15,20,7};
	vector<int> preorder = {1, 2};
	vector<int> inorder = {2, 1};
	inorderTraversal(buildTree(preorder, inorder));
	cout << endl;
	return 0;
}