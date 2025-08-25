class Solution
{
public:
    vector<int> ans;
    void preorder(TreeNode *roti)
    {
        if (roti)
        {
            ans.push_back(roti->val);
            preorder(roti->left);
            preorder(roti->right);
        }
    }
    vector<int> preorderTraversal(TreeNode *root)
    {
        // if(!root) return ans;
        preorder(root);
        return ans;
    }
};