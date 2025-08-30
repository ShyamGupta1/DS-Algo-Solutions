class Solution
{
public:
    void dfs(TreeNode *root, int level, vector<vector<int>> &result)
    {
        if (!root)
            return;
        if (result.size() < level)
            result.push_back(vector<int>());
        result[level - 1].push_back(root->val);
        dfs(root->left, level + 1, result);
        dfs(root->right, level + 1, result);
    }
    vector<vector<int>> levelOrderBottom(TreeNode *root)
    {
        vector<vector<int>> result;
        dfs(root, 1, result);
        reverse(result.begin(), result.end());
        return result;
    }
};