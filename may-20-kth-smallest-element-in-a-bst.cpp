// https://leetcode.com/problems/kth-smallest-element-in-a-bst/

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
void traverse(TreeNode* node, int& counter, int k, int& result)
{
    if (result) return;
    if (node->left) traverse(node->left, counter, k, result);
    if (++counter == k) result = node->val;
    if (node->right) traverse(node->right, counter, k, result);
}
 
class Solution {
public:
    int kthSmallest(TreeNode* root, int k) {
        int counter = 0, result = 0;
        traverse(root, counter, k, result);
        return result;
    }
};