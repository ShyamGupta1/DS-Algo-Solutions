class Solution
{
public:
    vector<TreeNode *> totka;
    vector<int> noice;
    void inOrder(TreeNode *root)
    {
        if (!root)
            return;
        inOrder(root->left);
        noice.push_back(root->val);
        totka.push_back(root);
        inOrder(root->right);
    }
    void recoverTree(TreeNode *root)
    {
        inOrder(root);
        sort(noice.begin(), noice.end());
        for (int i = 0; i < totka.size(); i++)
            totka[i]->val = noice[i];
    }
};