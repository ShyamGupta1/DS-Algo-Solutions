// T.C : O(n)
// S.C : O(n)

class Solution
{
public:
    TreeNode *ans = NULL;
    TreeNode *dummy = NULL;
    void preorder(TreeNode *roti)
    {
        if (roti)
        {
            TreeNode *newNode = new TreeNode(roti->val);
            if (ans == NULL)
            {
                dummy = newNode;
                ans = dummy;
            }
            else
            {
                dummy->right = newNode;
                dummy = newNode;
            }
            preorder(roti->left);
            preorder(roti->right);
        }
    }
    void flatten(TreeNode *root)
    {

        preorder(root);
        if (root)
        {
            root->left = NULL;
            root->right = ans->right;
        }
    }
};