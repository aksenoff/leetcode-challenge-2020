// https://leetcode.com/problems/binary-tree-level-order-traversal-ii/

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
    vector<vector<int>> levelOrderBottom(TreeNode* root) {
        if (!root) return {};
        vector<vector<int>> result;
        queue<pair<TreeNode*, int>> q;
        q.push(make_pair(root, 0));
        while (!q.empty())
        {
            auto node = q.front();
            q.pop();
            if (node.second + 1 > result.size()) result.push_back(vector<int>());
            result[result.size() - 1].push_back(node.first->val);
            if (node.first->left) q.push(make_pair(node.first->left, node.second + 1));
            if (node.first->right) q.push(make_pair(node.first->right, node.second + 1));
        }
        reverse(result.begin(), result.end());
        return result;
    }
};
