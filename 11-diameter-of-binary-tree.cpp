// https://leetcode.com/problems/diameter-of-binary-tree/submissions/

// struct TreeNode {
//     int val;
//     TreeNode* left;
//     TreeNode* right;
//     TreeNode(int x) : val(x), left(0), right(0) {}
// };

struct AnnotatedTreeNode {
    int val;
    int maxlength;
    AnnotatedTreeNode* left;
    AnnotatedTreeNode* right;
    AnnotatedTreeNode(int x) : val(x), left(0), right(0), maxlength(0) {}
};

int fardfs(TreeNode* node, int currentlen, int& maxlen, char direction, string& path, string& maxpath, AnnotatedTreeNode*& parentAnnotatedNode)
{
    path.push_back(direction);
    AnnotatedTreeNode* annotatedNode = new AnnotatedTreeNode(node->val);
    if (parentAnnotatedNode)
    {
        if (direction == 'l') parentAnnotatedNode->left = annotatedNode;
        else parentAnnotatedNode->right = annotatedNode;
    }
    else parentAnnotatedNode = annotatedNode;
    if (currentlen > maxlen)
    {
        maxlen = currentlen;
        maxpath = path;
    }
    int leftlength = 0, rightlength = 0;
    if (node->left) leftlength = fardfs(node->left, currentlen + 1, maxlen, 'l', path, maxpath, annotatedNode);
    if (node->right) rightlength = fardfs(node->right, currentlen + 1, maxlen, 'r', path, maxpath, annotatedNode);
    int maxcurrentlength = 1 + (leftlength > rightlength ? leftlength : rightlength);
    annotatedNode->maxlength = maxcurrentlength - 1;
    path.pop_back();
    return maxcurrentlength;
}

void followThePath(string path, AnnotatedTreeNode* node, int& diameter)
{
    if (path.empty()) return;
    if (path.back() == 'l')
    {
        if (diameter < node->maxlength + (node->right ? node->right->maxlength + 1 : 0))
        {
            diameter = node->maxlength + (node->right ? node->right->maxlength + 1 : 0);
        }
        path.pop_back();
        followThePath(path, node->left, diameter);
    }
    else if (path.back() == 'r')
    {
        if (diameter < node->maxlength + (node->left ? node->left->maxlength + 1 : 0))
        {
            diameter = node->maxlength + (node->left ? node->left->maxlength + 1 : 0);
        }
        path.pop_back();
        followThePath(path, node->right, diameter);
    }
}

class Solution {
public:
    int diameterOfBinaryTree(TreeNode* root) {
        if (root == 0) return 0;
        int maxlen = 0;
        string path = "", maxpath = "";
        AnnotatedTreeNode* annotatedRoot = 0;
        fardfs(root, 0, maxlen, 'i', path, maxpath, annotatedRoot);
        if (maxpath == "") return 0;
        reverse(maxpath.begin(), maxpath.end());
        maxpath.pop_back();
        int diameter = 0;
        followThePath(maxpath, annotatedRoot, diameter);
        return diameter;
    }
};