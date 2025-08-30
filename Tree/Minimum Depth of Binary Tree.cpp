class Solution
{
public:
    int ans = INT_MAX;
    void depthi(TreeNode *root, int level)
    {
        if (!root)
            return;
        if (!root->left and !root->right)
            ans = min(ans, level);
        depthi(root->left, level + 1);
        depthi(root->right, level + 1);
    }
    int minDepth(TreeNode *root)
    {
        if (!root)
            return 0;
        depthi(root, 1);
        return ans;
    }
};