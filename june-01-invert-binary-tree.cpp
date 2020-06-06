// https://leetcode.com/problems/invert-binary-tree/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    TreeNode* invertTree(TreeNode* root) {
		if (!root) return root;
		if (!root->left && !root->right) return root;
		if (!root->left)
		{
			root->left = invertTree(root->right);
			root->right = nullptr;
		}			
		else if (!root->right)
		{
			root->right = invertTree(root->left);
			root->left = nullptr;
		}			
		else
		{
			TreeNode* temp = invertTree(root->left);
			root->left = invertTree(root->right);
			if (root->left) root->right = temp;
		}
		return root;
    }
};