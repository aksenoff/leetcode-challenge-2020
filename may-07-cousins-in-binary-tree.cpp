// https://leetcode.com/problems/cousins-in-binary-tree/

void dfs(TreeNode* node, unordered_map<int, pair<int, int>>& depths, int depth, int parent)
{
    depths[node->val] = make_pair(depth, parent);
    if (node->left) dfs(node->left, depths, depth + 1, node->val);
    if (node->right) dfs(node->right, depths, depth + 1, node->val);
}
 
class Solution {
public:
    bool isCousins(TreeNode* root, int x, int y) {
        unordered_map<int, pair<int, int>> depths;
        dfs(root, depths, 0, 0);
        return depths[x].first == depths[y].first && depths[x].second != depths[y].second;
    }
};