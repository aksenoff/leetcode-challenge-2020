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

bool dfs(TreeNode* node, vector<int>& arr, int i)
{
    bool result = false;
    if (i < arr.size())
    {
        if (node->right && arr[i] == node->right->val) result |= dfs(node->right, arr, i + 1);
        if (node->left && arr[i] == node->left->val) result |= dfs(node->left, arr, i + 1);
        return result;
    }
    else if (node->left || node->right) return false;
    else return true;
}

class Solution {
public:
    bool isValidSequence(TreeNode* root, vector<int>& arr) {
        if (arr[0] != root->val) return false;
        return dfs(root, arr, 1);
    }
};