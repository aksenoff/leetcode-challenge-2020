// https://leetcode.com/problems/count-complete-tree-nodes/

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
    int tracePath(TreeNode* root, int depth, int path)
    { // path is no of node in last complete level
        int result = 0;
        depth--; // decrementing to get value for shifting bit
        TreeNode* node = root;        
        for (int i = 0; i <= depth; ++i)
        { // path bits are instructions to go left/right
            if (path & (1 << depth)) node = node->right;
            else node = node->left;
            path <<= 1;
        }
        if (node->left) result++;
        if (node->right) result++;
        return result; // number of child nodes
    }
public:
    int countNodes(TreeNode* root) {
        if (!root) return 0;
        if (!root->right) return root->left ? 2 : 1;
        TreeNode* node = root;
        int depth = 0;
        while (node->right) 
        {
            node = node->right;
            depth++;
        }
        int a = 0, b = pow(2, depth) - 1, mid, res;
        while (a < b) // binary search through last complete row nodes
        {
            mid = a + (b - a) / 2;
            res = tracePath(root, depth, mid);
            if (res == 2) a = mid + 1; 
            else if (!res) b = mid - 1;
            else return pow(2, depth + 1) + 2 * mid;
        }
        return pow(2, depth + 1) - 1 + 2 * a + tracePath(root, depth, a);
    }
};