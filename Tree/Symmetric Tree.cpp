class Solution
{
public:
    void lefttraverse(TreeNode *root, string &str)
    {
        if (!root)
        {
            str += ".";
            return;
        }
        str += to_string(root->val);
        lefttraverse(root->left, str);
        lefttraverse(root->right, str);
    }
    void righttraverse(TreeNode *root, string &str)
    {
        if (!root)
        {
            str += ".";
            return;
        }
        str += to_string(root->val);
        righttraverse(root->right, str);
        righttraverse(root->left, str);
    }
    bool isSymmetric(TreeNode *root)
    {
        if (!root)
            return false;
        if (!root->left and !root->right)
            return true;
        string s1 = " ", s2 = " ";
        lefttraverse(root->left, s1);
        righttraverse(root->right, s2);
        if (s1 == s2)
            return true;
        return false;
    }
};