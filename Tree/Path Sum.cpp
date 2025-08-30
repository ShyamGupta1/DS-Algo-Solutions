class Solution
{
public:
    bool found = false;
    void dfs(TreeNode *root, int sum, int target)
    {
        if (!root)
            return;
        sum += root->val;
        cout << sum << " ";
        if (!root->left and !root->right and sum == target)
            found = true;
        dfs(root->left, sum, target);
        dfs(root->right, sum, target);
    }
    bool hasPathSum(TreeNode *root, int targetSum)
    {
        if (!root)
            return false;
        dfs(root->left, root->val, targetSum);
        dfs(root->right, root->val, targetSum);
        if (!root->left and !root->right and root->val == targetSum)
            return true;
        return found ? true : false;
    }
};