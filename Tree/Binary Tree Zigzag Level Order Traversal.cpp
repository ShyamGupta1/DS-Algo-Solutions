class Solution
{
public:
    vector<vector<int>> zigzagLevelOrder(TreeNode *root)
    {
        if (!root)
            return {};
        vector<vector<int>> ans;
        queue<TreeNode *> que;
        que.push(root);
        int level = 0;
        while (!que.empty())
        {
            int n = que.size();
            vector<int> result;
            while (n--)
            {
                TreeNode *node = que.front();
                result.push_back(node->val);
                que.pop();
                if (node->left)
                    que.push(node->left);
                if (node->right)
                    que.push(node->right);
            }
            if (level % 2)
                reverse(result.begin(), result.end());
            level++;
            ans.push_back(result);
        }
        return ans;
    }
};