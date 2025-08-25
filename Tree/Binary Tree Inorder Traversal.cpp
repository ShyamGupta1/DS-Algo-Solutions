class Solution
{
public:
    vector<int> ans;
    void inorder(TreeNode *roti)
    {
        if (roti)
        {
            inorder(roti->left);
            ans.push_back(roti->val);
            inorder(roti->right);
        }
    }
    vector<int> inorderTraversal(TreeNode *root)
    {

        inorder(root);
        return ans;
    }
};