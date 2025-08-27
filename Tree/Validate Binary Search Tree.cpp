class Solution
{
public:
    vector<int> temp;
    void inOrder(TreeNode *root)
    {
        if (!root)
            return;
        inOrder(root->left);
        temp.push_back(root->val);
        inOrder(root->right);
    }
    bool isValidBST(TreeNode *root)
    {
        if (!root)
            return false;
        inOrder(root);
        for (int i = 0; i < temp.size() - 1; i++)
            if (temp[i] >= temp[i + 1])
                return false;
        return true;
    }
};