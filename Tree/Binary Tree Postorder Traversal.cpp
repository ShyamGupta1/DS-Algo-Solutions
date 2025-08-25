class Solution
{
public:
    vector<int> ans;
    void postorder(TreeNode *roti)
    {
        if (roti)
        {
            postorder(roti->left);
            postorder(roti->right);
            ans.push_back(roti->val);
        }
    }
    vector<int> postorderTraversal(TreeNode *root)
    {
        postorder(root);
        return ans;
    }
};