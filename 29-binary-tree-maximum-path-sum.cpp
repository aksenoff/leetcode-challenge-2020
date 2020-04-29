// https://leetcode.com/problems/binary-tree-maximum-path-sum/

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
int dfs(TreeNode* node, int& max)
{
    int leftsum = -30000, rightsum = -30000;
    if (node->left) leftsum = dfs(node->left, max);
    if (node->right) rightsum = dfs(node->right, max);
    leftsum = (leftsum > 0 ? leftsum : 0);
    rightsum = (rightsum > 0 ? rightsum : 0);    
    int sum = leftsum + rightsum + node->val;
    if (sum > max) max = sum;
    return (leftsum > rightsum ? leftsum : rightsum) + node->val;
}
 
class Solution {
public:
    int maxPathSum(TreeNode* root) {
        int max_sum = -30000;
        dfs(root, max_sum);
        return max_sum;
    }
};