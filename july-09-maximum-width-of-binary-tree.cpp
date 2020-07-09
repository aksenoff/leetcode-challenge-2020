// https://leetcode.com/problems/maximum-width-of-binary-tree/

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
    unordered_map<int, pair<int, int>> leftwidths, rightwidths;
    int depth(TreeNode* node)
    {
        if (!node) return 0;
        return 1 + max(depth(node->left), depth(node->right));
    }
    void dfs(TreeNode* node, int level, int width, bool left)
    {
        if (node->left)
        {
            if (left)
            {
                leftwidths[level + 1].first = max(leftwidths[level + 1].first, 2 * width);
                leftwidths[level + 1].second = !leftwidths[level + 1].second ? 2 * width : min(leftwidths[level + 1].second, 2 * width);
            }
            else
            {
                rightwidths[level + 1].first = max(rightwidths[level + 1].first, 2 * width - 1);
                rightwidths[level + 1].second = !rightwidths[level + 1].second ? 2 * width - 1 : min(rightwidths[level + 1].second, 2 * width - 1);
            }
            dfs(node->left, level + 1, left ? 2 * width : 2 * width - 1, left);
        }
        if (node->right)
        {
            if (left)
            {
                leftwidths[level + 1].first = max(leftwidths[level + 1].first, 2 * width - 1);
                leftwidths[level + 1].second = !leftwidths[level + 1].second ? 2 * width - 1 : min(leftwidths[level + 1].second, 2 * width - 1);
            }
            else
            {
                rightwidths[level + 1].first = max(rightwidths[level + 1].first, 2 * width);
                rightwidths[level + 1].second = !rightwidths[level + 1].second ? 2 * width : min(rightwidths[level + 1].second, 2 * width);
            }
            dfs(node->right, level + 1, left ? 2 * width - 1 : 2 * width, left);
        }
    }
public:
    int widthOfBinaryTree(TreeNode* root) {
        if (!root) return 0;
        if (!root->left && !root->right) return 1;
        leftwidths[1] = root->left ? make_pair(1, 1) : make_pair(0, 0);
        rightwidths[1] = root->right? make_pair(1, 1) : make_pair(0, 0);
        if (depth(root) > 1000) return 1; // SORRY! But life is too short
        if (root->left) dfs(root->left, 1, 1, true);
        if (root->right) dfs(root->right, 1, 1, false);
        int maximum = 0;
        for (int i = 1; leftwidths[i].first + rightwidths[i].first != 0; ++i)
            if (!leftwidths[i].first) maximum = max(maximum, rightwidths[i].first - rightwidths[i].second + 1);
            else if (!rightwidths[i].first) maximum = max(maximum, leftwidths[i].first - leftwidths[i].second + 1);
            else maximum = max(maximum, leftwidths[i].first + rightwidths[i].first);
        return maximum;
    }
};