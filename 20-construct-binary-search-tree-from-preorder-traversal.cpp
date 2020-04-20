// https://leetcode.com/problems/construct-binary-search-tree-from-preorder-traversal/

/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
TreeNode* makeTree(vector<int>& preorder, int max = -30000, int lastrightparent = 30000)
{
    int current = preorder.back();
    if (current > max) max = current;
    TreeNode* node = new TreeNode(current);
    preorder.pop_back();
    if (preorder.size() && preorder.back() < current) node->left = makeTree(preorder, max, current);
    if (preorder.size() && preorder.back() > lastrightparent && current != max) return node;
    if (preorder.size() && preorder.back() > current) node->right = makeTree(preorder, max, lastrightparent);
    return node;
}
 
class Solution {
public:
    TreeNode* bstFromPreorder(vector<int>& preorder) {
        reverse(preorder.begin(), preorder.end());
        return makeTree(preorder);
    }
};