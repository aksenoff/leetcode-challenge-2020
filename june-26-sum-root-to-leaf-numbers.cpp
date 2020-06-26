// https://leetcode.com/problems/sum-root-to-leaf-numbers/

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
    int sum = 0;
    string number = "";
    void dfs(TreeNode* node)
    {
        number.push_back('0' + node->val);
        if (node->left) dfs(node->left);
        if (node->right) dfs(node->right);
        if (!node->left && !node->right) sum += stoi(number);
        number.pop_back();
    }
public:
    int sumNumbers(TreeNode* root) {
        if (!root) return 0;
        dfs(root);
        return sum;
    }
};