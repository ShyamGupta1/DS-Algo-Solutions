class Solution
{
public:
    int h = 1;
    int height(TreeNode *root)
    {
        if (!root)
            return 0;
        int left = height(root->left) + 1;
        int right = height(root->right) + 1;
        if (abs(left - right) > 1)
            h = 0;
        return max(right, left);
    }
    bool isBalanced(TreeNode *root)
    {
        if (root == NULL)
            return 1;
        height(root);
        if (h)
            return 1;
        return 0;
    }
};